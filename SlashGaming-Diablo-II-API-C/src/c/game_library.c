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

#include "game_library.h"

#include <windows.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/c/default_game_library.h"
#include "encoding.h"
#include "error_handling.h"
#include "../wide_macro.h"

static struct MAPI_GameLibrary** game_libraries = NULL;
static size_t game_libraries_count = 0;
static size_t game_libraries_capacity = 0;

static int CompareGameLibraryByFilePath(
    const struct MAPI_GameLibrary* first,
    const struct MAPI_GameLibrary* second
) {
  return strcmp(first->file_path, second->file_path);
}

/**
 * Doubles the size of the game libraries if capacity is maxed.
 */
static void ResizeGameLibraries(void) {
  game_libraries_capacity *= 2;
  game_libraries = (struct MAPI_GameLibrary**) realloc(
      game_libraries,
      game_libraries_capacity * sizeof(game_libraries[0])
  );

  if (game_libraries == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }
}

static struct MAPI_GameLibrary* AddGameLibrary(
    const char* file_path
) {
  if (game_libraries_count == game_libraries_capacity) {
    ResizeGameLibraries();
  }

  wchar_t* wide_file_path = ConvertUtf8ToWide(NULL, file_path, __FILEW__, __LINE__);

  // Append the new game library to the end.
  game_libraries[game_libraries_count] = (struct MAPI_GameLibrary*) malloc(
      sizeof(*game_libraries[0])
  );
  game_libraries[game_libraries_count]->base_address = LoadLibraryW(
      wide_file_path
  );
  game_libraries[game_libraries_count]->file_path = (char*) malloc(
      (strlen(file_path) + 1) * sizeof(*game_libraries[0]->file_path)
  );
  if (game_libraries[game_libraries_count]->file_path == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }
  strcpy(game_libraries[game_libraries_count]->file_path, file_path);

  game_libraries_count += 1;

  struct MAPI_GameLibrary* inserted_game_library =
      game_libraries[game_libraries_count];

  // Sort the element in the array.
  for (size_t i = game_libraries_count - 1; i > 0; i -= 1) {
    if (CompareGameLibraryByFilePath(
            game_libraries[i],
            game_libraries[i - 1]
        ) <= 0) {
      break;
    }

    struct MAPI_GameLibrary* temp = game_libraries[i];
    game_libraries[i] = game_libraries[i - 1];
    game_libraries[i - 1] = temp;
  }

clean_wide_file_path:
  free(wide_file_path);

  return inserted_game_library;
}

static void ClearGameLibraries(void) {
  if (game_libraries == NULL) {
    return;
  }

  for (size_t i = 0; i < game_libraries_count; i += 1) {
    FreeLibrary((HMODULE) game_libraries[i]->base_address);
    free(game_libraries[i]->file_path);
    free(game_libraries[i]);
  }

  free(game_libraries);

  game_libraries = NULL;
  game_libraries_capacity = 0;
  game_libraries_count = 0;
}

const struct MAPI_GameLibrary* GetGameLibrary(
    const char* file_path
) {
  struct MAPI_GameLibrary key;
  key.file_path = file_path;

  struct MAPI_GameLibrary* search_result = NULL;
  
  if (game_libraries != NULL) {
    search_result = (struct MAPI_GameLibrary*) bsearch(
        &key,
        game_libraries,
        game_libraries_count,
        sizeof(game_libraries[0]),
        &CompareGameLibraryByFilePath
    );
  }

  // If not found, then add the game library.
  if (search_result == NULL) {
    return AddGameLibrary(file_path);
  }

  return search_result;
}
