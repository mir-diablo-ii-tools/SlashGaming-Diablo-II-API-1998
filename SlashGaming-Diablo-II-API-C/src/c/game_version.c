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
#include <wchar.h>

#include <mdc/std/threads.h>
#include "../wide_macro.h"
#include "backend/error_handling.h"
#include "backend/game_library.h"
#include "backend/game_version/file_info.h"
#include "backend/game_version/file_version.h"
#include "backend/game_version/signature.h"
#include "backend/game_version/version_name.h"

static enum D2_GameVersion running_game_version;
static once_flag running_game_version_once_flag = ONCE_FLAG_INIT;

static wchar_t* GetCurrentProcessFilePath(void) {
  wchar_t* realloc_file_path;
  wchar_t* realloc_file_path_size;
  wchar_t* current_process_file_path;
  size_t current_process_file_path_capacity;

  DWORD get_module_file_name_result;

  current_process_file_path = NULL;
  current_process_file_path_capacity = 1;

  do {
    current_process_file_path_capacity *= 2;

    realloc_file_path_size = current_process_file_path_capacity
        * sizeof(current_process_file_path[0]);

    realloc_file_path = realloc(
        current_process_file_path,
        realloc_file_path_size
    );

    if (realloc_file_path == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
    }

    current_process_file_path = realloc_file_path;

    get_module_file_name_result = GetModuleFileNameW(
        NULL,
        current_process_file_path,
        current_process_file_path_capacity
    );

    if (get_module_file_name_result == 0) {
      ExitOnWindowsFunctionFailureWithLastError(
          L"GetModuleFileNameW",
          GetLastError(),
          __FILEW__,
          __LINE__
      );
    }
  } while (get_module_file_name_result == current_process_file_path_capacity);

  return current_process_file_path;
}

static enum GameVersion SearchGameFileInfoTable(
    const VS_FIXEDFILEINFO* game_file_info
) {
  struct FileVersion file_version;
  file_version.major_left = (game_file_info->dwFileVersionMS >> 16) & 0xFFFF;
  file_version.major_right = (game_file_info->dwFileVersionMS >> 0) & 0xFFFF;
  file_version.minor_left = (game_file_info->dwFileVersionLS >> 16) & 0xFFFF;
  file_version.minor_right = (game_file_info->dwFileVersionLS >> 0) & 0xFFFF;

  return FileVersion_SearchGameVersionTable(&file_version);
}

static void InitRunningGameVersion(void) {
  VS_FIXEDFILEINFO game_file_info;
  wchar_t* current_process_file_path;

  /* Extract the file info from the game executable. */
  current_process_file_path = GetCurrentProcessFilePath();
  ExtractFileInfo(&game_file_info, current_process_file_path);

  /*
  * Perform a search of the game version in the table. This will not
  * cover all cases, as some versions share file versions.
  */
  running_game_version = SearchGameFileInfoTable(&game_file_info);

  /*
  * Correct the initial guess using the a predetermined signature.
  */
  running_game_version = Signature_CorrectVersionGuess(running_game_version);

free_current_process_file_path:
  free(current_process_file_path);
}

const char* D2_GetGameVersionName(
    enum D2_GameVersion game_version_id
) {
  return D2_SearchGameVersionName(game_version_id);
}

int D2_GetRunningGameVersionId(void) {
  call_once(&running_game_version_once_flag, &InitRunningGameVersion);

  return running_game_version;
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
