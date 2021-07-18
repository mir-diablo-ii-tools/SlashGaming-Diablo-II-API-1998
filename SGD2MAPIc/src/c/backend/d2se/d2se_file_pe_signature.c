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

#include "d2se_file_pe_signature.h"

#include <stddef.h>
#include <stdlib.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>
#include "../../../../include/c/file/file_pe_signature.h"
#include "../../../../include/c/game_executable.h"

enum {
  kSignatureCount = 64,
};

static const struct Mapi_FilePeSignature kD2seSignatureSortedSet[] = {
    {
        kSignatureCount,
        {
            0x50, 0x45, 0x00, 0x00, 0x4C, 0x01, 0x05, 0x00,
            0x5F, 0xDC, 0xB5, 0x4D, 0x00, 0x00, 0x00, 0x00,

            0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x0F, 0x01,
            0x0B, 0x01, 0x02, 0x32, 0x00, 0x08, 0x01, 0x00,

            0x00, 0x8A, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x40, 0x3C, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,

            0x00, 0x20, 0x01, 0x00, 0x00, 0x00, 0x40, 0x00,
            0x00, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        }
    },
};

enum {
  kD2seSignatureSortedSetCount = sizeof(kD2seSignatureSortedSet)
      / sizeof(kD2seSignatureSortedSet[0])
};

static int Mapi_FilePeSignature_CompareAsVoid(
    const void* signature1,
    const void* signature2
) {
  return Mapi_FilePeSignature_Compare(signature1, signature2);
}

static int ContainsSignature(const struct Mapi_FilePeSignature* signature) {
  const struct Mapi_FilePeSignature* search_result;

  search_result = bsearch(
      signature,
      kD2seSignatureSortedSet,
      kD2seSignatureSortedSetCount,
      sizeof(kD2seSignatureSortedSet[0]),
      &Mapi_FilePeSignature_CompareAsVoid
  );

  return (search_result != NULL);
}

/**
 * External
 */

int FilePeSignature_IsD2se(void) {
  const wchar_t* game_executable_path;
  struct Mapi_FilePeSignature signature;

  game_executable_path = Mapi_GameExecutable_GetPath();

  Mapi_FilePeSignature_ReadFile(
      &signature,
      game_executable_path,
      kSignatureCount
  );

  return ContainsSignature(&signature);
}
