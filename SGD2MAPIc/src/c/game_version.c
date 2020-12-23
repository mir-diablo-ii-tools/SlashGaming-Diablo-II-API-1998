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

#include "../../include/c/game_version.h"

#include <windows.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/std/threads.h>
#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>
#include "../../include/c/game_executable.h"
#include "backend/game_version/file_signature.h"
#include "backend/game_version/file_version.h"

static enum D2_GameVersion running_game_version;

static enum D2_GameVersion DetermineRunningGameVersion(void) {
  const wchar_t* game_executable_path;
  VS_FIXEDFILEINFO fixed_file_info;
  enum D2_GameVersion game_version;

  /*
  * Perform first stage game version detection using the executable
  * file name.
  */
  game_executable_path = Mapi_GetGameExecutablePath();
  fixed_file_info = Mapi_GetFixedFileInfo(game_executable_path);
  game_version = Mapi_GetGameVersionFromFileVersion(&fixed_file_info);

  /*
  * Perform second stage game version detection by checking the bytes
  * of game file(s).
  */
  game_version = Mapi_GetGameVersionFromFileSignature(game_version);

  return game_version;
}

static void InitRunningGameVersion(void) {
  running_game_version = DetermineRunningGameVersion();
}

static void InitStatic(void) {
  static once_flag running_game_version_init_flag = ONCE_FLAG_INIT;
  call_once(&running_game_version_init_flag, &InitRunningGameVersion);
}

/**
 * External functions
 */

const char* D2_GetGameVersionName(
    enum D2_GameVersion game_version
) {
  switch (game_version) {
    case D2_GameVersion_k1_00: {
      return "1.00";
    }

    case D2_GameVersion_k1_01: {
      return "1.01";
    }

    case D2_GameVersion_k1_02: {
      return "1.02";
    }

    case D2_GameVersion_k1_03: {
      return "1.03";
    }
    /* 1.04B and 1.04C use the same DLLs. */
    case D2_GameVersion_k1_04B_C: {
      return "1.04B/C";
    }

    case D2_GameVersion_k1_05: {
      return "1.05";
    }

    case D2_GameVersion_k1_05B: {
      return "1.05B";
    }

    case D2_GameVersion_k1_06: {
      return "1.06";
    }

    case D2_GameVersion_k1_06B: {
      return "1.06B";
    }

    case D2_GameVersion_k1_07Beta: {
      return "1.07 Beta";
    }

    case D2_GameVersion_k1_07: {
      return "1.07";
    }

    case D2_GameVersion_k1_08: {
      return "1.08";
    }

    case D2_GameVersion_k1_09: {
      return "1.09";
    }

    case D2_GameVersion_k1_09B: {
      return "1.09B";
    }

    case D2_GameVersion_k1_09D: {
      return "1.09D";
    }

    case D2_GameVersion_k1_10Beta: {
      return "1.10 Beta";
    }

    case D2_GameVersion_k1_10SBeta: {
      return "1.10S Beta";
    }

    case D2_GameVersion_k1_10: {
      return "1.10";
    }

    case D2_GameVersion_k1_11: {
      return "1.11";
    }

    case D2_GameVersion_k1_11B: {
      return "1.11B";
    }

    case D2_GameVersion_k1_12A: {
      return "1.12A";
    }

    case D2_GameVersion_k1_13ABeta: {
      return "1.13A Beta";
    }

    case D2_GameVersion_k1_13C: {
      return "1.13C";
    }

    case D2_GameVersion_k1_13D: {
      return "1.13D";
    }

    case D2_GameVersion_kClassic1_14A: {
      return "Classic 1.14A";
    }

    case D2_GameVersion_kLod1_14A: {
      return "LoD 1.14A";
    }

    case D2_GameVersion_kClassic1_14B: {
      return "Classic 1.14B";
    }

    case D2_GameVersion_kLod1_14B: {
      return "LoD 1.14B";
    }

    case D2_GameVersion_kClassic1_14C: {
      return "Classic 1.14C";
    }

    case D2_GameVersion_kLod1_14C: {
      return "LoD 1.14C";
    }

    case D2_GameVersion_kClassic1_14D: {
      return "Classic 1.14D";
    }

    case D2_GameVersion_kLod1_14D: {
      return "LoD 1.14D";
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          game_version
      );

      return NULL;
    }
  }
}

enum D2_GameVersion D2_GetRunningGameVersion(void) {
  InitStatic();

  return running_game_version;
}

const char* D2_GetRunningGameVersionName(void) {
  InitStatic();

  return D2_GetGameVersionName(D2_GetRunningGameVersion());
}

bool D2_IsGameVersionAtLeast1_14(
    enum D2_GameVersion game_version_id
) {
  InitStatic();

  return game_version_id > D2_GameVersion_k1_13D;
}

bool D2_IsRunningGameVersionAtLeast1_14(void) {
  InitStatic();

  return D2_IsGameVersionAtLeast1_14(
      D2_GetRunningGameVersion()
  );
}
