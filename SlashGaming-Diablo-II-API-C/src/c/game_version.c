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
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <wchar.h>

#include "encoding.h"
#include "error_handling.h"
#include "game_library.h"
#include "../wide_macro.h"

struct GameVersionInfo {
  const char* file_version;
  enum D2_GameVersion game_version;
};

struct GameDataInfo {
  ptrdiff_t offset_value;
  const char* library_path;
  enum D2_GameVersion matching_version;
  enum D2_GameVersion non_matching_version;
  uint8_t expected_values;
};

enum {
  MAX_FILE_VERSION_LEN = 128
};

static const char* kVersionIdToName[] = {
    [VERSION_1_00] = "1.00",
    [VERSION_1_01] = "1.01",
    [VERSION_1_02] = "1.02",
    [VERSION_1_03] = "1.03",
    // 1.04B and 1.04C use the same DLLs.
    [VERSION_1_04B_C] = "1.04B/C",
    [VERSION_1_05] = "1.05",
    [VERSION_1_05B] = "1.05B",
    [VERSION_1_06] = "1.06",
    [VERSION_1_06B] = "1.06B",
    [VERSION_1_07_BETA] = "1.07 Beta",
    [VERSION_1_07] = "1.07",
    [VERSION_1_08] = "1.08",
    [VERSION_1_09] = "1.09",
    [VERSION_1_09B] = "1.09B",
    [VERSION_1_09D] = "1.09D",
    [VERSION_1_10_BETA] = "1.10 Beta",
    [VERSION_1_10S_BETA] = "1.10S Beta",
    [VERSION_1_10] = "1.10",
    [VERSION_1_11] = "1.11",
    [VERSION_1_11B] = "1.11B",
    [VERSION_1_12A] = "1.12A",
    [VERSION_1_13A_BETA] = "1.13A Beta",
    [VERSION_1_13C] = "1.13C",
    [VERSION_1_13D] = "1.13D",
    [CLASSIC_1_14A] = "Classic 1.14A",
    [LOD_1_14A] = "LoD 1.14A",
    [CLASSIC_1_14B] = "Classic 1.14B",
    [LOD_1_14B] = "LoD 1.14B",
    [CLASSIC_1_14C] = "Classic 1.14C",
    [LOD_1_14C] = "LoD 1.14C",
    [CLASSIC_1_14D] = "Classic 1.14D",
    [LOD_1_14D] = "LoD 1.14D",
};

static const struct GameDataInfo kVersionIdToGameDataInfo[] = {
    [VERSION_1_01] = {
        .offset_value = 0xF0,
        .library_path = "D2Client.dll",
        .matching_version = VERSION_1_00,
        .non_matching_version = VERSION_1_01,
        .expected_values = 0xF0
    },
    [VERSION_1_06] = {
        .offset_value = 0xE8,
        .library_path = "D2Client.dll",
        .matching_version = VERSION_1_06,
        .non_matching_version = VERSION_1_06B,
        .expected_values = 0x3F
    },
    [VERSION_1_07] = {
        .offset_value = 0x3C,
        .library_path = "D2Client.dll",
        .matching_version = VERSION_1_07_BETA,
        .non_matching_version = VERSION_1_07,
        .expected_values = 0xF0
    },
    [LOD_1_14A] = {
        .offset_value = 0x120,
        .library_path = "Game.exe",
        .matching_version = CLASSIC_1_14A,
        .non_matching_version = LOD_1_14A,
        .expected_values = 0x38
    },
    [LOD_1_14B] = {
        .offset_value = 0x110,
        .library_path = "Game.exe",
        .matching_version = CLASSIC_1_14B,
        .non_matching_version = LOD_1_14B,
        .expected_values = 0xAE
    },
    [LOD_1_14C] = {
        .offset_value = 0x110,
        .library_path = "Game.exe",
        .matching_version = CLASSIC_1_14C,
        .non_matching_version = LOD_1_14C,
        .expected_values = 0x52
    },
    [LOD_1_14D] = {
        .offset_value = 0x128,
        .library_path = "Game.exe",
        .matching_version = CLASSIC_1_14D,
        .non_matching_version = LOD_1_14D,
        .expected_values = 0xC4
    },
};

static struct GameVersionInfo sorted_name_game_version_infos[] = {
    // 1.00 & 1.01 have the same version #, but use completely different
    // DLLs.
    { "1.0.0.1", VERSION_1_01 },
    { "1.0.2.0", VERSION_1_02 },
    { "1.0.3.0", VERSION_1_03 },
    // 1.04B and 1.04C use the same DLLs.
    { "1.0.4.1", VERSION_1_04B_C },
    { "1.0.4.2", VERSION_1_04B_C },
    { "1.0.5.0", VERSION_1_05 },
    { "1.0.5.1", VERSION_1_05B },
    // 1.06 & 1.06B have the same version #, but use completely different
    // DLLs.
    { "1.0.6.0", VERSION_1_06 },
    // 1.07 Beta & 1.07 have the same version #, but use completely
    // different DLLs.
    { "1.0.7.0", VERSION_1_07 },
    { "1.0.8.28", VERSION_1_08 },
    { "1.0.9.19", VERSION_1_09 },
    { "1.0.9.20", VERSION_1_09B },
    { "1.0.9.22", VERSION_1_09D },
    { "1.0.10.9", VERSION_1_10_BETA },
    { "1.0.10.10", VERSION_1_10S_BETA },
    { "1.0.10.39", VERSION_1_10 },
    { "1.0.11.45", VERSION_1_11 },
    { "1.0.11.46", VERSION_1_11B },
    { "1.0.12.49", VERSION_1_12A },
    { "1.0.13.55", VERSION_1_13A_BETA },
    { "1.0.13.60", VERSION_1_13C },
    { "1.0.13.64", VERSION_1_13D },
    { "1.14.0.64", LOD_1_14A },
    { "1.14.1.68", LOD_1_14B },
    { "1.14.2.70", LOD_1_14C },
    { "1.14.3.71", LOD_1_14D },
};

static int CompareGameVersionInfo(
    const struct GameVersionInfo* info1,
    const struct GameVersionInfo* info2
) {
  return strcmp(info1->file_version, info2->file_version);
}

static void ExtractFileVersionString(
    char* file_version,
    const char* file_path
) {
  // All the code for this function originated from StackOverflow user
  // crashmstr. Some parts were refactored and altered for clarity and
  // correctness.

  wchar_t* file_path_text_wide = ConvertUtf8ToWide(
      NULL,
      file_path,
      __FILEW__,
      __LINE__
  );

  // Check version size.
  DWORD ignored;
  DWORD file_version_info_size = GetFileVersionInfoSizeW(
      file_path_text_wide,
      &ignored
  );

  if (file_version_info_size == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoSizeW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  // Get the file version info.
  void* file_version_info = (void*) malloc(file_version_info_size);

  if (file_version_info == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  BOOL is_get_file_version_info_success = GetFileVersionInfoW(
      file_path_text_wide,
      ignored,
      file_version_info_size,
      file_version_info
  );

  if (!is_get_file_version_info_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  // Gather all of the information into the specified buffer, then check
  // version info signature.
  UINT version_info_size;
  VS_FIXEDFILEINFO* version_info;

  BOOL is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      L"\\",
      &version_info,
      &version_info_size
  );

  if (!is_ver_query_value_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"VerQueryValueW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  // Doesn't matter if you are on 32 bit or 64 bit,
  // DWORD is always 32 bits, so first two revision numbers
  // come from dwFileVersionMS, last two come from dwFileVersionLS
  snprintf(
      file_version,
      MAX_FILE_VERSION_LEN,
      "%u.%u.%u.%u",
      (version_info->dwFileVersionMS >> 16) & 0xFFFF,
      (version_info->dwFileVersionMS >> 0) & 0xFFFF,
      (version_info->dwFileVersionLS >> 16) & 0xFFFF,
      (version_info->dwFileVersionLS >> 0) & 0xFFFF
  );

free_file_version_info:
  free(file_version_info);

free_file_path_text_wide:
  free(file_path_text_wide);
}

static void SortGameVesionInfoByName(void) {
  qsort(
      sorted_name_game_version_infos,
      sizeof(sorted_name_game_version_infos) / sizeof(sorted_name_game_version_infos[0]),
      sizeof(sorted_name_game_version_infos[0]),
      &CompareGameVersionInfo
  );
}

static enum D2_GameVersion DetermineGameVersionByGameData(
    enum D2_GameVersion guess_game_version
) {
  const struct GameDataInfo* game_data_info =
      &kVersionIdToGameDataInfo[guess_game_version];

  // The guessed game version is the sufficient in determining the running
  // game version, so return the guess.
  if (game_data_info->library_path == NULL) {
    return guess_game_version;
  }

  // Determine if values at the specified offset match with the expected
  // values.
  const struct MAPI_GameLibrary* game_library = GetGameLibrary(
      game_data_info->library_path
  );

  int compare_result = memcmp(
      game_library->base_address + game_data_info->offset_value,
      game_data_info->expected_values,
      sizeof(game_data_info->expected_values)
  );

  return (compare_result == 0)
      ? game_data_info->matching_version
      : game_data_info->non_matching_version;
}

const char* D2_GetGameVersionName(
    enum D2_GameVersion game_version_id
) {
  return kVersionIdToName[game_version_id];
}

int D2_GetRunningGameVersionId(void) {
  static pthread_once_t once_flag = PTHREAD_ONCE_INIT;

  // Perform first stage game version detection using the executable file
  // name.
  char file_version[MAX_FILE_VERSION_LEN];
  ExtractFileVersionString(file_version, "Game.exe");

  // Sort the game version info so that a bsearch can be done correctly.
  // Multithread safe.
  pthread_once(&once_flag, &SortGameVesionInfoByName);

  const struct GameVersionInfo* search_result = bsearch(
      file_version,
      sorted_name_game_version_infos,
      sizeof(sorted_name_game_version_infos)
          / sizeof(sorted_name_game_version_infos[0]),
      sizeof(sorted_name_game_version_infos[0]),
      &CompareGameVersionInfo
  );

  enum D2_GameVersion first_stage_game_version = search_result->game_version;

  // Perform second stage game version detection by checking the bytes of game
  // libraries.

}

const char* D2_GetRunningGameVersionName(void) {
  return D2_GetGameVersionName(D2_GetRunningGameVersionId());
}

bool D2_IsGameVersionAtLeast1_14(
    enum D2_GameVersion game_version_id
) {
  return game_version_id > VERSION_1_13D;
}

bool D2_IsRunningGameVersionAtLeast1_14(void) {
  return D2_IsGameVersionAtLeast1_14(
      D2_GetRunningGameVersionId()
  );
}
