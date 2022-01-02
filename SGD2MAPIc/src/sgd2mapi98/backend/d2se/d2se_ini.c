/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "d2se_ini.h"

#include <windows.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>
#include "d2se_game_version.h"

#define D2SE_INI_PATH L"D2SE_SETUP.ini"

static const wchar_t* const kD2seIniPath = D2SE_INI_PATH;

enum D2_GameVersion D2seIni_GetGameVersion(void) {
  DWORD get_private_profile_string_result;

  wchar_t version_str[10];

  get_private_profile_string_result = GetPrivateProfileStringW(
      L"Protected",
      L"D2Core",
      L"",
      version_str,
      10,
      kD2seIniPath
  );

  return D2seIni_GuessGameVersion(version_str);
}

enum D2_VideoMode D2seIni_GetVideoMode(void) {
  int renderer_value;
  int window_mode_value;

  renderer_value = GetPrivateProfileIntW(
      L"USERSETTINGS",
      L"Renderer",
      -1,
      kD2seIniPath
  );

  switch (renderer_value) {
    case 0: {
      window_mode_value = GetPrivateProfileIntW(
          L"USERSETTINGS",
          L"WindowMode",
          -1,
          kD2seIniPath
      );

      return (window_mode_value == 1)
          ? D2_VideoMode_kGdi
          : D2_VideoMode_kDirectDraw;
    }

    case 1: {
      return D2_VideoMode_kDirect3D;
    }

    case 3: {
      return D2_VideoMode_kGlide;
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          renderer_value
      );

      return -1;
    }
  }
}
