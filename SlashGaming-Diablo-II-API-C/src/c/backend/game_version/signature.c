/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "signature.h"

#include <stddef.h>
#include <wchar.h>
#include <windows.h>

#include "../error_handling.h"

struct Signature {
  const wchar_t* file_path;
  int offset;
  unsigned char signature[4];
  enum D2_GameVersion game_version;
};

const struct Signature kVersion1_00SignatureTable[] = {
    { L"storm.dll", 0xF0, { 0x25, 0x47, 0x52, 0x39 }, VERSION_1_01 },
    { L"storm.dll", 0xF0, { 0x79, 0xBD, 0x20, 0x39 }, VERSION_BETA_1_02 },
    {
        L"storm.dll",
        0xF0,
        { 0xB7, 0x70, 0xD0, 0x38 },
        VERSION_BETA_STRESS_TEST_1_02
    },
    { L"storm.dll", 0xF0, { 0xBC, 0xC7, 0x2E, 0x39 }, VERSION_1_00 }
};

enum FILE_SCOPE_CONSTANTS_03 {
  kVersion1_00SignatureTableCount = sizeof(kVersion1_00SignatureTable)
      / sizeof(kVersion1_00SignatureTable[0])
};

const struct Signature kVersion1_06Signature = {
    L"storm.dll", 0xF0, { 0x43, 0x0C, 0xD6, 0x3A }, VERSION_1_06
};

const struct Signature kVersion1_07Signature = {
    L"storm.dll", 0xF8, { 0x32, 0xA6, 0xDC, 0x3A }, VERSION_1_07_BETA
};

const struct Signature kVersion1_14ASignature = {
    NULL, 0x120, { 0x38, 0x81, 0xD4, 0x56 }, CLASSIC_1_14A
};

const struct Signature kVersion1_14BSignature = {
    NULL, 0x110, { 0xAE, 0x78, 0xFC, 0x56 }, CLASSIC_1_14B
};

const struct Signature kVersion1_14CSignature = {
    NULL, 0x110, { 0x52, 0xDF, 0x2C, 0x57 }, CLASSIC_1_14C
};

const struct Signature kVersion1_14DSignature = {
    NULL, 0x140, { 0x00, 0x50, 0x0A, 0x00 }, CLASSIC_1_14D
};

static int SignatureTableEntry_CompareKey(
    const struct Signature* signature1,
    const struct Signature* signature2
) {
  int file_path_diff;
  int offset_diff;
  int signature_diff;

  file_path_diff = wcscmp(signature1->file_path, signature2->file_path);

  if (file_path_diff != 0) {
    return file_path_diff;
  }

  offset_diff = signature1->offset - signature2->offset;

  if (offset_diff != 0) {
    return offset_diff;
  }

  signature_diff = memcmp(
      signature1->signature,
      signature2->signature,
      sizeof(signature1->signature)
  );

  return signature_diff;
}

static int SignatureTableEntry_CompareAsVoidKey(
    const void* signature1,
    const void* signature2
) {
  return SignatureTableEntry_CompareKey(
      (const struct Signature*) signature1,
      (const struct Signature*) signature2
  );
}

static enum D2_GameVersion CorrectVersionGuess1_00(void) {
  struct Signature search_signature;
  struct Signature* search_result;

  HMODULE library_base_address;

  search_signature.file_path = kVersion1_00SignatureTable[0].file_path;
  search_signature.offset = kVersion1_00SignatureTable[0].offset;

  /* Load the library info into memory. */
  library_base_address = GetModuleHandleW(search_signature.file_path);

  if (library_base_address != NULL) {
    library_base_address = LoadLibraryW(search_signature.file_path);
  }

  if (library_base_address == NULL) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  /* Copy the section of memory containing the signature. */
  intptr_t signature_address = (intptr_t) library_base_address
      + search_signature.offset;

  memcpy(
      search_signature.signature,
      (const void*) signature_address,
      sizeof(search_signature.signature)
  );

  search_result = bsearch(
      &search_signature,
      kVersion1_00SignatureTable,
      kVersion1_00SignatureTableCount,
      sizeof(kVersion1_00SignatureTable[0]),
      &SignatureTableEntry_CompareAsVoidKey
  );

  return search_result->game_version;
}

enum D2_GameVersion Signature_CorrectVersionGuess(
    enum D2_GameVersion guess_game_version
) {
  const struct Signature* source_signature;
  int memcmp_result;

  HMODULE library_base_address;

  switch (guess_game_version) {
    case VERSION_1_01: {
      /*
      * File version 1.0.0.1 is shared across prerelease and release
      * versions, so special case is needed.
      */
      return CorrectVersionGuess1_00();
    }

    case VERSION_1_06B: {
      source_signature = &kVersion1_06Signature;
      break;
    }

    case VERSION_1_07: {
      source_signature = &kVersion1_07Signature;
      break;
    }

    case LOD_1_14A: {
      source_signature = &kVersion1_14ASignature;
      break;
    }

    case LOD_1_14B: {
      source_signature = &kVersion1_14BSignature;
      break;
    }

    case LOD_1_14C: {
      source_signature = &kVersion1_14CSignature;
      break;
    }

    case LOD_1_14D: {
      source_signature = &kVersion1_14DSignature;
      break;
    }

    default: {
      return guess_game_version;
    }
  }

  /* Load the library info into memory. */
  library_base_address = GetModuleHandleW(source_signature->file_path);

  if (library_base_address != NULL) {
    library_base_address = LoadLibraryW(source_signature->file_path);
  }

  if (library_base_address == NULL) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  /* Copy the section of memory containing the signature. */
  memcmp_result = memcmp(
      source_signature->signature,
      (void*)((intptr_t)library_base_address + source_signature->offset),
      sizeof(source_signature->signature)
  );

  if (memcmp_result == 0) {
    return source_signature->game_version;
  }

  return guess_game_version;
}
