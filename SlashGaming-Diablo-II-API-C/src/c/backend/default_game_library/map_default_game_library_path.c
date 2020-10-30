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

#include "map_default_game_library_path.h"

#include <mdc/std/threads.h>
#include <mdc/filesystem/filesystem.h>
#include <mdc/object/integer_object.h>

#include "pair_default_game_library_path.h"

/**
 * Static functions
 */

static struct Mdc_MapMetadata global_map_metadata;
static once_flag global_map_metadata_init_flag = ONCE_FLAG_INIT;

static void Mapi_MapDefaultGameLibraryPath_InitGlobalMapMetadata(void) {
  Mdc_MapMetadata_Init(
      &global_map_metadata,
      Mapi_PairDefaultGameLibraryPath_GetGlobalPairMetadata()
  );
}

/**
 * External functions
 */

const struct Mdc_MapMetadata*
Mapi_MapDefaultGameLibraryPath_GetGlobalMapMetadata(void) {
  call_once(
      &global_map_metadata_init_flag,
      &Mapi_MapDefaultGameLibraryPath_InitGlobalMapMetadata
  );

  return &global_map_metadata;
}

void Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
    struct Mdc_Map* map,
    enum D2_DefaultLibrary default_library_id,
    const wchar_t* path_cstr
) {
  struct Mdc_Integer default_library;
  struct Mdc_Integer* init_default_library;

  init_default_library = Mdc_Integer_InitFromValue(
      &default_library,
      default_library_id
  );

  Mdc_Map_Emplace(
      map,
      &default_library,
      &Mdc_Fs_Path_InitFromCWStr,
      path_cstr
  );

  Mdc_Integer_Deinit(&default_library);
}
