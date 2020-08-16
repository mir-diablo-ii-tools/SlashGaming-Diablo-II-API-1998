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

#include "game_library_table.h"

#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include"../../../wide_macro.h"
#include "../error_handling.h"

static int MAPI_GameLibraryTable_CompareKeys(
    const struct MAPI_GameLibrary** game_library1,
    const struct MAPI_GameLibrary** game_library2
) {
  return strcmp((*game_library1)->file_path, (*game_library2)->file_path);
}

static int MAPI_GameLibraryTable_CompareAsVoidKeys(
    const void* game_library1,
    const void* game_library2
) {
  return MAPI_GameLibraryTable_CompareKeys(
      (const struct MAPI_GameLibrary**) game_library1,
      (const struct MAPI_GameLibrary**) game_library2
  );
}

static void MAPI_GameLibraryTable_Resize(
    struct MAPI_GameLibraryTable* game_library_table,
    size_t new_capacity
) {
  void* realloc_result;
  size_t realloc_size;

  size_t i;

  /* Do nothing if the new capacity is the same. */
  if (game_library_table->capacity == new_capacity) {
    return;
  }

  /*
  * Shrink away elements if new size is smaller than number of
  * elements.
  */
  if (new_capacity < game_library_table->num_elements) {
    for (i = new_capacity; i < game_library_table->num_elements; i += 1) {
      MAPI_GameLibrary_Deinit(game_library_table->entries[i]);
      free(game_library_table->entries[i]);
    }

    game_library_table->num_elements = new_capacity;
  }

  realloc_size = new_capacity * sizeof(game_library_table->entries[0]);

  realloc_result = realloc(
      game_library_table->entries,
      realloc_size
  );

  if (realloc_result == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  game_library_table->entries = (struct MAPI_GameLibrary**) realloc_result;
  game_library_table->capacity = new_capacity;
}

static void MAPI_GameLibraryTable_DoubleCapacity(
    struct MAPI_GameLibraryTable* game_library_table
) {
  MAPI_GameLibraryTable_Resize(
      game_library_table,
      game_library_table->capacity * 2
  );
}

struct MAPI_GameLibraryTable* MAPI_GameLibraryTable_Init(
    struct MAPI_GameLibraryTable* game_library_table
) {
  game_library_table->num_elements = 0;
  game_library_table->capacity = 4;
  game_library_table->entries = malloc(
      game_library_table->capacity * sizeof(game_library_table->entries[0])
  );

  if (game_library_table->entries == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  return game_library_table;
}

void MAPI_GameLibraryTable_Deinit(
    struct MAPI_GameLibraryTable* game_library_table
) {
  MAPI_GameLibraryTable_Clear(game_library_table);

  free(game_library_table->entries);

  game_library_table->entries = NULL;
  game_library_table->num_elements = 0;
  game_library_table->capacity = 0;
}

const struct MAPI_GameLibrary* MAPI_GameLibraryTable_AtConst(
    const struct MAPI_GameLibraryTable* game_library_table,
    const char* file_path
) {
  struct MAPI_GameLibrary search_game_library;
  struct MAPI_GameLibrary* search_game_library_ptr;
  struct MAPI_GameLibrary** game_library_search_result;

  search_game_library_ptr = &search_game_library;

  search_game_library.file_path = file_path;

  game_library_search_result = bsearch(
      &search_game_library_ptr,
      game_library_table->entries,
      game_library_table->num_elements,
      sizeof(game_library_table->entries[0]),
      &MAPI_GameLibraryTable_CompareAsVoidKeys
  );

  if (game_library_search_result == NULL) {
    return NULL;
  }

  return *game_library_search_result;
}

struct MAPI_GameLibrary* MAPI_GameLibraryTable_Emplace(
    struct MAPI_GameLibraryTable* game_library_table,
    const char* file_path
) {
  while (game_library_table->num_elements >= game_library_table->capacity) {
    MAPI_GameLibraryTable_DoubleCapacity(game_library_table);
  }

  game_library_table->entries[game_library_table->num_elements] = malloc(
      sizeof(*game_library_table->entries[0])
  );

  MAPI_GameLibrary_Init(
      game_library_table->entries[game_library_table->num_elements],
      file_path
  );

  game_library_table->num_elements += 1;

  qsort(
      game_library_table->entries,
      game_library_table->num_elements,
      sizeof(game_library_table->entries[0]),
      &MAPI_GameLibraryTable_CompareAsVoidKeys
  );

  return game_library_table->entries[game_library_table->num_elements - 1];
}

void MAPI_GameLibraryTable_Clear(
    struct MAPI_GameLibraryTable* game_library_table
) {
  if (game_library_table->entries == NULL) {
    return;
  }

  for (size_t i = 0; i < game_library_table->num_elements; i += 1) {
    MAPI_GameLibrary_Deinit(game_library_table->entries[i]);
  }

  game_library_table->num_elements = 0;
}
