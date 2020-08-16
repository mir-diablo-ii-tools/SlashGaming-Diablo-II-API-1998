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

#include "game_library_struct.h"

#include <string.h>
#include <windows.h>

#include "../encoding.h"
#include "../error_handling.h"

struct MAPI_GameLibrary* MAPI_GameLibrary_Init(
    struct MAPI_GameLibrary* game_library,
    const char* file_path
) {
  size_t file_path_len;
  size_t file_path_size;

  wchar_t* wide_file_path;

  /* Copy the file path. */
  file_path_len = strlen(file_path);
  file_path_size = (file_path_len + 1) * sizeof(game_library->file_path[0]);

  game_library->file_path = malloc(file_path_size);
  strcpy(game_library->file_path, file_path);

  /* Load the library. */
  wide_file_path = ConvertUtf8ToWide(
      NULL,
      file_path,
      __FILEW__,
      __LINE__
  );

  game_library->base_address = LoadLibraryW(wide_file_path);

  if (game_library->base_address == NULL) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

free_wide_file_path:
  free(wide_file_path);

  return game_library;
}

void MAPI_GameLibrary_Deinit(struct MAPI_GameLibrary* game_library) {
  BOOL is_free_library_success;

  is_free_library_success = FreeLibrary(game_library->base_address);
  if (!is_free_library_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"FreeLibrary",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  free(game_library->file_path);
}
