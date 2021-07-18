/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "../../../include/c/file/file_pe_signature.h"

#include <stdio.h>
#include <string.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>

/**
 * External
 */

const struct Mapi_FilePeSignature Mapi_FilePeSignature_kUninit =
    MAPI_FILE_PE_SIGNATURE_UNINIT;

int Mapi_FilePeSignature_Compare(
    const struct Mapi_FilePeSignature* signature1,
    const struct Mapi_FilePeSignature* signature2
) {
  int memcmp_result;
  size_t lesser_count;

  /*
   * The comparison does not need size to be the same. There just
   * needs to be enough similarities for a valid determination to
   * be made.
   */
  lesser_count = (signature1->signature_count < signature2->signature_count)
      ? signature1->signature_count
      : signature2->signature_count;

  memcmp_result = memcmp(
      signature1->signature,
      signature2->signature,
      lesser_count
  );

  return memcmp_result;
}

int Mapi_FilePeSignature_ReadFile(
    struct Mapi_FilePeSignature* signature,
    const wchar_t* path,
    size_t count
) {
  FILE* file;

  int fseek_result;
  size_t fread_count;

  intptr_t pe_header_pointer;

  if (count < Mapi_FilePeSignature_kMinSignatureCount) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"Signature is of insufficient size: %u / %u",
        __FILEW__,
        __LINE__,
        count,
        Mapi_FilePeSignature_kMinSignatureCount
    );

    return 0;
  } else if (count > Mapi_FilePeSignature_kMaxSignatureCount) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"Signature is of too large size: %u / %u",
        __FILEW__,
        __LINE__,
        count,
        Mapi_FilePeSignature_kMaxSignatureCount
    );

    return 0;
  }

  file = _wfopen(path, L"rb");

  /* Grab the pointer to the PE header. */
  fseek_result = fseek(file, 0x3C, SEEK_SET);
  if (fseek_result != 0) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%s failed.",
        __FILEW__,
        __LINE__,
        L"fseek"
    );

    goto close_file;
  }

  fread_count = fread(
      &pe_header_pointer,
      sizeof(pe_header_pointer),
      1,
      file
  );

  if (fread_count < 1) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%s failed.",
        __FILEW__,
        __LINE__,
        L"fread"
    );

    goto close_file;
  }

  /* Read the PE header. */
  fseek_result = fseek(file, pe_header_pointer, SEEK_SET);
  if (fseek_result != 0) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%s failed.",
        __FILEW__,
        __LINE__,
        L"fseek"
    );

    goto close_file;
  }

  fread_count = fread(
      signature,
      sizeof(signature[0]),
      count,
      file
  );

  if (fread_count < count) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%s failed.",
        __FILEW__,
        __LINE__,
        L"fread"
    );

    goto close_file;
  }

  fclose(file);

  return 1;

close_file:
  fclose(file);

  return 0;
}
