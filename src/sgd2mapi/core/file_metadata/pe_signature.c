/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#include "sgd2mapi/core/file_metadata/pe_signature.h"

#include <stddef.h>
#include <windows.h>

#include <mdc/std/wchar.h>

enum {
  PE_SIGNATURE_START_OFFSET = 0x3C
};

static int IsFileSizeSufficient(HANDLE file) {
  DWORD file_size_low;
  DWORD file_size_high;

  file_size_low = GetFileSize(file, &file_size_high);
  return file_size_high > 0 || file_size_low >= PE_SIGNATURE_START_OFFSET + PE_SIGNATURE_SIZE;
}

/**
 * External
 */

struct PeSignature* PeSignature_ReadFile(
    struct PeSignature* signature, const wchar_t* path) {
  HANDLE file;
  BOOL read_file_succeeded;
  DWORD set_file_pointer_result;

  file =
      CreateFileW(
          path,
          GENERIC_READ,
          FILE_SHARE_READ,
          NULL,
          OPEN_EXISTING,
          FILE_ATTRIBUTE_NORMAL,
          NULL);
  if (file == INVALID_HANDLE_VALUE) {
    goto error;
  }

  if (!IsFileSizeSufficient(file)) {
    goto error_close_file;
  }

  set_file_pointer_result =
      SetFilePointer(file, PE_SIGNATURE_START_OFFSET, NULL, FILE_BEGIN);
  if (set_file_pointer_result == INVALID_SET_FILE_POINTER) {
    DWORD last_error;

    last_error = GetLastError();
    if (last_error != NO_ERROR) {
      goto error_close_file;
    }
  }

  read_file_succeeded =
      ReadFile(file, signature->data, PE_SIGNATURE_SIZE, NULL, NULL);
  if (!read_file_succeeded) {
    goto error_close_file;
  }

  return signature;

error_close_file:
  CloseHandle(file);

error:
  return NULL;
}

int PeSignature_Compare(
    const struct PeSignature* lhs, const struct PeSignature* rhs) {
  return memcmp(lhs->data, rhs->data, sizeof(lhs->data));
}
