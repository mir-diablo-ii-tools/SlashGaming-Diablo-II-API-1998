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

#include "../../../include/sgd2mapi98/helper/d2_determine_video_mode.h"

#include <stddef.h>
#include <windows.h>
#include <shlwapi.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../include/sgd2mapi98/game_executable.h"
#include "../backend/d2se/d2se_ini.h"

static enum D2_VideoMode_1_00 GetVideoModeFromRegValue_1_00(DWORD reg_value) {
  switch (reg_value) {
    case 0: {
      return D2_VideoMode_1_00_kDirectDraw;
    }

    case 1: {
      return D2_VideoMode_1_00_kDirect3D;
    }

    case 3: {
      return D2_VideoMode_1_00_kGlide;
    }

    case 4: {
      return D2_VideoMode_1_00_kGdi;
    }

    default: {
      return D2_VideoMode_1_00_kDirectDraw;
    }
  }
}

static enum D2_VideoMode GetVideoModeFromRegValue(DWORD reg_value) {
  return D2_VideoMode_ToApiValue_1_00(
      GetVideoModeFromRegValue_1_00(reg_value)
  );
}

static enum D2_VideoMode GetCommandLineVideoMode() {
  size_t i;

  enum D2_VideoMode video_mode;

  const wchar_t* command_line;
  const wchar_t* command_line_args;
  size_t command_line_args_len;

  video_mode = D2_VideoMode_kDirectDraw;
  command_line = GetCommandLineW();
  command_line_args = PathGetArgsW(command_line);
  command_line_args_len = wcslen(command_line_args);

  /*
  * The D2 command line parsing code is not very complex. It just
  * checks (case insensitive) if the arg strings are contained in the
  * command line. For example:
  *
  * Game.exe -W42-3DfX"GNU Linux"
  *
  * This is windowed Glide mode.
  */

  for (i = 0; i < command_line_args_len; i += 1) {
    if (_wcsnicmp(&command_line_args[i], L"-3dfx", 5) == 0) {

      video_mode = D2_VideoMode_kGlide;

    } else if (video_mode != D2_VideoMode_kGlide
        && _wcsnicmp(&command_line_args[i], L"-w", 2) == 0) {

      video_mode = D2_VideoMode_kGdi;

    } else if (video_mode != D2_VideoMode_kGdi
        && _wcsnicmp(&command_line_args[i], L"-d3d", 4) == 0) {

      video_mode = D2_VideoMode_kDirect3D;

    }
  }

  return video_mode;
}

static enum D2_VideoMode GetRegistryVideoMode() {
  HKEY query_key_result;
  LONG reg_open_key_status;

  DWORD render_value;
  DWORD render_value_size;

  LONG reg_query_value_status;

  reg_open_key_status = RegOpenKeyExW(
      HKEY_CURRENT_USER,
      L"SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig",
      0,
      KEY_QUERY_VALUE,
      &query_key_result
  );

  if (reg_open_key_status != ERROR_SUCCESS) {
    reg_open_key_status = RegOpenKeyExW(
        HKEY_LOCAL_MACHINE,
        L"SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig",
        0,
        KEY_QUERY_VALUE,
        &query_key_result
    );

    if (reg_open_key_status != ERROR_SUCCESS) {
      return D2_VideoMode_kDirectDraw;
    }
  }

  render_value_size = sizeof(render_value);

  reg_query_value_status = RegQueryValueExW(
      query_key_result,
      L"Render",
      NULL,
      NULL,
      (LPBYTE) &render_value,
      &render_value_size
  );

  RegCloseKey(query_key_result);

  return GetVideoModeFromRegValue(render_value);
}

/**
 * External
 */

enum D2_VideoMode D2_Helper_DetermineVideoMode(void) {
  enum D2_VideoMode command_line_video_mode;
  enum D2_VideoMode reg_video_mode;

  if (Mapi_GameExecutable_IsD2se()) {
    return D2seIni_GetVideoMode();
  }

  command_line_video_mode = GetCommandLineVideoMode();

  if (command_line_video_mode != D2_VideoMode_kDirectDraw) {
    return command_line_video_mode;
  }

  reg_video_mode = GetRegistryVideoMode();
  return reg_video_mode;
}

enum D2_VideoMode_1_00 D2_Helper_DetermineVideoMode_1_00(void) {
  return D2_VideoMode_ToGameValue_1_00(D2_Helper_DetermineVideoMode());
}
