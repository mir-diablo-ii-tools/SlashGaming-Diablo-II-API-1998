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

#include <mdc/container/map.h>
#include <mdc/std/threads.h>
#include "../../wide_macro.h"
#include "encoding.h"
#include "error_handling.h"
#include "game_library/game_library_table.h"

static struct Mdc_Map game_library_map = MDC_MAP_UNINIT;
static once_flag game_library_map_once_flag = ONCE_FLAG_INIT;

static struct Mdc_BasicStringMetadata string_metadata;
static once_flag string_metadata_once_flag = ONCE_FLAG_INIT;

static void InitGameLibraryMap(void) {
  Mapi_InitGameLibraryMap(&game_library_map);
}

static void InitStringMetadata(void) {
  Mdc_StringMetadata_InitMetadata(&string_metadata);
}

static void InitStatic(void) {
  call_once(&game_library_map_once_flag, &InitGameLibraryMap);
  call_once(&string_metadata_once_flag, &InitStringMetadata);
}

const struct MAPI_GameLibrary* GetGameLibrary(const char* file_path) {
  struct Mdc_BasicString file_path_str = MDC_BASIC_STRING_UNINIT;
  const struct MAPI_GameLibrary* game_library;

  struct Mdc_BasicString* init_file_path_str;

  InitStatic();

  init_file_path_str = Mdc_BasicString_InitFromCStr(
      &file_path_str,
      &string_metadata,
      file_path
  );

  game_library = Mdc_Map_Contains(
      &game_library_map,
      file_path
  );

  /* If not found, then add the game library. */
  if (!Mdc_Map_Contains(&game_library_map, &file_path_str)) {
    Mdc_Map_EmplaceKeyCopy(
        &game_library_map,
        &file_path_str,
        &MAPI_GameLibrary_Init,
        Mdc_BasicString_Data(&file_path_str)
    );
  }

  game_library = Mdc_Map_AtConst(&game_library_map, &file_path_str);

deinit_file_path_str:
  Mdc_BasicString_Deinit(&file_path_str);

  return game_library;
}
