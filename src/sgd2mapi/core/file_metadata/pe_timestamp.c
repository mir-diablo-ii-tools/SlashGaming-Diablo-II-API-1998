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

#include "sgd2mapi/core/file_metadata/pe_timestamp.h"

#include <stddef.h>
#include <windows.h>
#include <imagehlp.h>

#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>

#include "sgd2mapi/core/error/error.h"

/**
 * External
 */

struct PeTimestamp* PeTimestamp_ReadFile(
    const wchar_t* path,
    struct PeTimestamp* timestamp,
    struct SGD2Error* error) {
  HANDLE file;
  HANDLE file_mapping;
  LPVOID file_map_view;
  PIMAGE_NT_HEADERS nt_headers;

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
    if (error != NULL) {
      error->path = __FILEW__;
      error->line = __LINE__;
      error->function_name = L"CreateFile";
      error->type = SGD2ERROR_WINDOWS_ERROR;
      error->windows_error.code = GetLastError();
    }
    goto error;
  }

  file_mapping = CreateFileMappingW(file, NULL, PAGE_READONLY, 0, 0, NULL);
  if (file == INVALID_HANDLE_VALUE) {
    if (error != NULL) {
      error->path = __FILEW__;
      error->line = __LINE__;
      error->function_name = L"CreateFileMapping";
      error->type = SGD2ERROR_WINDOWS_ERROR;
      error->windows_error.code = GetLastError();
    }
    goto error_close_file;
  }

  file_map_view = MapViewOfFile(file_mapping, FILE_MAP_READ, 0, 0, 0);
  if (file == INVALID_HANDLE_VALUE) {
    if (error != NULL) {
      error->path = __FILEW__;
      error->line = __LINE__;
      error->function_name = L"MapViewOfFile";
      error->type = SGD2ERROR_WINDOWS_ERROR;
      error->windows_error.code = GetLastError();
    }
    goto error_close_file_mapping;
  }

  nt_headers = ImageNtHeader(file_map_view);
  if (nt_headers == NULL) {
    if (error != NULL) {
      error->path = __FILEW__;
      error->line = __LINE__;
      error->function_name = L"ImageNtHeader";
      error->type = SGD2ERROR_WINDOWS_ERROR;
      error->windows_error.code = GetLastError();
    }
    goto error_unmap_file_map_view;
  }

  timestamp->value = nt_headers->FileHeader.TimeDateStamp;
  error->type = SGD2ERROR_GOOD;

  UnmapViewOfFile(file_map_view);
  CloseHandle(file_mapping);
  CloseHandle(file);

  return timestamp;

error_unmap_file_map_view:
  UnmapViewOfFile(file_map_view);

error_close_file_mapping:
  CloseHandle(file_mapping);

error_close_file:
  CloseHandle(file);

error:
  return NULL;
}

int PeTimestamp_Compare(struct PeTimestamp* lhs, struct PeTimestamp* rhs) {
  return (lhs->value < rhs->value) ? -1 : (lhs->value > rhs->value);
}
