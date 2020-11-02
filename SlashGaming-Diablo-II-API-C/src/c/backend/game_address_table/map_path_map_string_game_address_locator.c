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

#include "map_path_map_string_game_address_locator.h"

#include <mdc/std/threads.h>
#include "pair_path_map_string_game_address_locator.h"

/**
 * Static functions
 */

static struct Mdc_ObjectMetadata object_metadata;
static once_flag object_metadata_init_flag = ONCE_FLAG_INIT;

static struct Mdc_MapMetadata map_metadata;
static once_flag pair_metadata_init_flag = ONCE_FLAG_INIT;

static void* Mdc_MapPathMapStringGameAddressLocator_InitEmptyAsVoid(
    void* obj
) {
  return Mdc_MapPathMapStringGameAddressLocator_InitEmpty(obj);
}

static void
Mdc_MapPathMapStringGameAddressLocator_InitGlobalObjectMetadata(void) {
  object_metadata = *Mdc_Map_GetObjectMetadataTemplate();

  object_metadata.functions.init_default =
      &Mdc_MapPathMapStringGameAddressLocator_InitEmptyAsVoid;
}

static void
Mdc_MapPathMapStringGameAddressLocator_InitGlobalMapMetadata(void) {
  Mdc_MapMetadata_Init(
      &map_metadata,
      Mdc_PairPathMapStringGameAddressLocator_GetPairMetadata()
  );
}

static void InitStatic(void) {
  call_once(
      &pair_metadata_init_flag,
      &Mdc_MapPathMapStringGameAddressLocator_InitGlobalMapMetadata
  );

  call_once(
      &object_metadata_init_flag,
      &Mdc_MapPathMapStringGameAddressLocator_InitGlobalObjectMetadata
  );
}

/**
 * External functions
 */

struct Mdc_Map*
Mdc_MapPathMapStringGameAddressLocator_InitEmpty(
    struct Mdc_Map* map
) {
  InitStatic();

  return Mdc_Map_InitEmpty(
      map,
      Mdc_MapPathMapStringGameAddressLocator_GetMapMetadata()
  );
}

const struct Mdc_ObjectMetadata*
Mdc_MapPathMapStringGameAddressLocator_GetObjectMetadata(void) {
  InitStatic();

  return &object_metadata;
}

const struct Mdc_MapMetadata*
Mdc_MapPathMapStringGameAddressLocator_GetMapMetadata(void) {
  InitStatic();

  return &map_metadata;
}
