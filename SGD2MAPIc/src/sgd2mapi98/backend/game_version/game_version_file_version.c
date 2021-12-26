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

#include "game_version_file_version.h"

#include <windows.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../../include/sgd2mapi98/file/fixed_file_version.h"
#include "../../../../include/sgd2mapi98/game_executable.h"

static enum D2_GameVersion SearchTable(
    const struct Mapi_FixedFileVersion* fixed_file_version
) {
  switch (Mapi_FixedFileVersion_ToValue(fixed_file_version)) {
    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 0, 1): {
      return D2_GameVersion_k1_01;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 2, 0): {
      return D2_GameVersion_k1_02;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 3, 0): {
      return D2_GameVersion_k1_03;
    }

    /* 1.04B and 1.04C use the same DLLs. */
    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 4, 1): {
      return D2_GameVersion_k1_04B_C;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 4, 2): {
      return D2_GameVersion_k1_04B_C;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 5, 0): {
      return D2_GameVersion_k1_05;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 5, 1): {
      return D2_GameVersion_k1_05B;
    }

    /*
     * 1.06 & 1.06B have the same version #, but use completely
     * different DLLs.
     */
    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 6, 0): {
      return D2_GameVersion_k1_06B;
    }

    /*
     * 1.07 Beta & 1.07 have the same version #, but use completely
     * different DLLs.
     */
    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 7, 0): {
      return D2_GameVersion_k1_07;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 8, 28): {
      return D2_GameVersion_k1_08;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 9, 19): {
      return D2_GameVersion_k1_09;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 9, 20): {
      return D2_GameVersion_k1_09B;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 9, 22): {
      return D2_GameVersion_k1_09D;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 10, 9): {
      return D2_GameVersion_k1_10Beta;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 10, 10): {
      return D2_GameVersion_k1_10SBeta;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 10, 39): {
      return D2_GameVersion_k1_10;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 11, 45): {
      return D2_GameVersion_k1_11;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 11, 46): {
      return D2_GameVersion_k1_11B;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 12, 49): {
      return D2_GameVersion_k1_12A;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 13, 55): {
      return D2_GameVersion_k1_13ABeta;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 13, 60): {
      return D2_GameVersion_k1_13C;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 0, 13, 64): {
      return D2_GameVersion_k1_13D;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 14, 0, 64): {
      return D2_GameVersion_kLod1_14A;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 14, 1, 68): {
      return D2_GameVersion_kLod1_14B;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 14, 2, 70): {
      return D2_GameVersion_kLod1_14C;
    }

    case MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE(1, 14, 3, 71): {
      return D2_GameVersion_kLod1_14D;
    }

    default: {
      Mdc_Error_ExitOnGeneralError(
          L"Error",
          L"Could not map the file version %u.%u.%u.%u to a known "
              L"game version.",
          __FILEW__,
          __LINE__,
          fixed_file_version->major_high,
          fixed_file_version->major_low,
          fixed_file_version->minor_high,
          fixed_file_version->minor_low
      );

      return -1;
    }
  }
}

/**
 * External
 */

enum D2_GameVersion FileVersion_GuessGameVersion(void) {
  const VS_FIXEDFILEINFO* fixed_file_info;
  struct Mapi_FixedFileVersion fixed_file_version;

  fixed_file_info = Mapi_GameExecutable_QueryFixedFileInfo();

  fixed_file_version = Mapi_FixedFileVersion_InitFromVersion(
      HIWORD(fixed_file_info->dwFileVersionMS),
      LOWORD(fixed_file_info->dwFileVersionMS),
      HIWORD(fixed_file_info->dwFileVersionLS),
      LOWORD(fixed_file_info->dwFileVersionLS)
  );

  return SearchTable(&fixed_file_version);
}
