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

#include <mdc/container/map.h>
#include <mdc/std/threads.h>

static struct Mdc_Map game_library_map = MDC_MAP_UNINIT;
static once_flag game_library_map_once_flag = ONCE_FLAG_INIT;

static struct Mdc_MapMetadata map_metadata;
static once_flag map_metadata_once_flag =
    ONCE_FLAG_INIT;

static struct Mdc_PairMetadata pair_metadata;
static once_flag pair_metadata_once_flag = ONCE_FLAG_INIT;

static void InitPairMetadata(void) {
  struct Mdc_PairSize* const size = &pair_metadata.size;

  struct Mdc_PairFunctions* const functions =
      &pair_metadata.functions;
  struct Mdc_PairFirstFunctions* const first_functions =
      &functions->first_functions;
  struct Mdc_PairSecondFunctions* const second_functions =
      &functions->second_functions;

  size->first_size = sizeof(struct Mdc_BasicString);
  size->second_size = sizeof(struct MAPI_GameLibrary);

  first_functions->init_copy = &Mdc_BasicString_InitCopy;
  first_functions->init_move = &Mdc_BasicString_InitMove;
  first_functions->deinit = &Mdc_BasicString_Deinit;
  first_functions->compare = &Mdc_BasicString_CompareStr;

  second_functions->init_move = &MAPI_GameLibrary_InitMove;
  second_functions->deinit = &MAPI_GameLibrary_Deinit;
  second_functions->compare = &MAPI_GameLibrary_Compare;
}

static void InitMapMetadata(void) {
  call_once(&pair_metadata_once_flag, &InitPairMetadata);

  map_metadata.pair_metadata = pair_metadata;
}

static void InitStatic(void) {
  call_once(&map_metadata_once_flag, &InitMapMetadata);
  call_once(&pair_metadata_once_flag, &InitPairMetadata);
}

struct Mdc_Map* Mapi_InitGameLibraryMap(
    struct Mdc_Map* game_library_map
) {
  InitStatic();

  Mdc_Map_Init(&game_library_map, &map_metadata);
}
