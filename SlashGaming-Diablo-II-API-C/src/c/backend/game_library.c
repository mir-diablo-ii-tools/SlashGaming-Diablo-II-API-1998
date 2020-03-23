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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "encoding.h"
#include "error_handling.h"
#include "../../wide_macro.h"

struct MAPI_GameLibraryTable {
  struct MAPI_GameLibrary** entries;
  size_t num_elements;
  size_t capacity;
};

static struct MAPI_GameLibraryTable game_library_table = {
  .entries = NULL,
  .num_elements = 0,
  .capacity = 0,
};

static int CompareGameLibraryByFilePath(
    const struct MAPI_GameLibrary* first,
    const struct MAPI_GameLibrary* second
) {
  return strcmp(first->file_path, second->file_path);
}

/**
 * Doubles the size of the game libraries collection.
 */
static void ResizeGameLibraries(void) {
  game_library_table.capacity = (game_library_table.capacity == 0)
          ? 1
          : game_library_table.capacity * 2;
  struct MAPI_GameLibrary** realloc_entries = (struct MAPI_GameLibrary**) realloc(
      game_library_table.entries,
      game_library_table.capacity * sizeof(game_library_table.entries[0])
  );

  if (realloc_entries == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  game_library_table.entries = realloc_entries;
}

static struct MAPI_GameLibrary* AddGameLibrary(
    const char* file_path
) {
  if (game_library_table.num_elements == game_library_table.capacity) {
    ResizeGameLibraries();
  }

  wchar_t* wide_file_path = ConvertUtf8ToWide(NULL, file_path, __FILEW__, __LINE__);

  // Insert the new game library to the correct position.
  struct MAPI_GameLibrary* new_game_library =
      (struct MAPI_GameLibrary*) malloc(sizeof(*new_game_library));

  if (new_game_library == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  new_game_library->base_address = (intptr_t) LoadLibraryW(wide_file_path);
  new_game_library->file_path = (char*) malloc(
      (strlen(file_path) + 1) * sizeof(new_game_library->file_path[0])
  );

  if (new_game_library->file_path == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  strcpy(new_game_library->file_path, file_path);

  game_library_table.num_elements += 1;

  // Insert the element into the sorted part of the array.
  size_t insertion_index = game_library_table.num_elements;
  for (insertion_index = game_library_table.num_elements;
      insertion_index > 0;
      insertion_index -= 1) {
    if (CompareGameLibraryByFilePath(
            new_game_library,
            game_library_table.entries[insertion_index - 1]
        ) >= 0) {
      break;
    }

    game_library_table.entries[insertion_index] =
        game_library_table.entries[insertion_index - 1];
  }

  game_library_table.entries[insertion_index] = new_game_library;

clean_wide_file_path:
  free(wide_file_path);

  return new_game_library;
}

static void ClearGameLibraries(void) {
  if (game_library_table.entries == NULL) {
    return;
  }

  for (size_t i = 0; i < game_library_table.num_elements; i += 1) {
    FreeLibrary((HMODULE) game_library_table.entries[i]->base_address);
    free(game_library_table.entries[i]->file_path);
    free(game_library_table.entries[i]);
  }

  free(game_library_table.entries);

  game_library_table.entries = NULL;
  game_library_table.num_elements = 0;
  game_library_table.capacity = 0;
}

const struct MAPI_GameLibrary* GetGameLibrary(
    const char* file_path
) {
  const struct MAPI_GameLibrary key = {
      .file_path = (char*) file_path
  };

  struct MAPI_GameLibrary* search_result = NULL;

  if (game_library_table.entries != NULL) {
    search_result = (struct MAPI_GameLibrary*) bsearch(
        &key,
        game_library_table.entries,
        game_library_table.num_elements,
        sizeof(game_library_table.entries[0]),
        (int (*)(const void*, const void*)) &CompareGameLibraryByFilePath
    );
  }

  // If not found, then add the game library.
  if (search_result == NULL) {
    return AddGameLibrary(file_path);
  }

  return search_result;
}
