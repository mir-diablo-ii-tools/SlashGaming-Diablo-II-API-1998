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

#include "sgd2mapi/core/main_exe/main_exe_properties.h"

#include <stddef.h>
#include <windows.h>

#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/core/file_metadata/pe_timestamp.h"

static struct MainExeProperties* MainExeProperties_Init(
    struct MainExeProperties* properties, struct SGD2Error* error) {
  DWORD path_chars_count;
  struct PeTimestamp* timestamp_read_file_result;

  path_chars_count = GetModuleFileNameW(NULL, properties->path, MAX_PATH);
  if (path_chars_count == 0) {
    error->path = __FILEW__;
    error->line = __LINE__;
    error->function_name = L"GetModuleFileName";
    error->type = SGD2ERROR_WINDOWS_ERROR;
    error->windows_error.code = GetLastError();
    goto error_return;
  }

  properties->path_length = path_chars_count;

  timestamp_read_file_result =
      PeTimestamp_ReadFile(properties->path, &properties->timestamp, error);
  if (timestamp_read_file_result == NULL) {
    goto error_return;
  }

  return properties;

error_return:
  return NULL;
}

/**
 * External
 */

const struct MainExeProperties* MainExe_GetProperties(struct SGD2Error* error) {
  static struct MainExeProperties g_main_exe_properties;
  static int inited = 0;

  if (!inited) {
    MainExeProperties_Init(&g_main_exe_properties, error);
    inited = 1;
  }

  return &g_main_exe_properties;
}
