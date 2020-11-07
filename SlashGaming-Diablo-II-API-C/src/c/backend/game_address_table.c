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

#include "game_address_table.h"

#include <stdlib.h>
#include <string.h>

#include <mdc/std/threads.h>
#include <mdc/std/wchar.h>
#include "../../../include/c/game_version.h"
#include "../../wide_macro.h"
#include "error_handling.h"
#include "game_address_table/game_address_table_impl.h"
#include "game_address_table/game_address_locator.h"

/**
 * Table of game address entries containing game addresses.
 */
static struct Mdc_Map* game_address_table;
static once_flag game_address_table_init_flag = ONCE_FLAG_INIT;

/**
 * Initializes the game address table.
 */
static void InitGameAddressTable(void) {
  game_address_table = Mapi_Impl_GetGameAddressTable();
}

static void InitStatic(void) {
  call_once(&game_address_table_init_flag, &InitGameAddressTable);
}

struct Mapi_GameAddress* Mapi_Impl_LoadGameAddress(
    struct Mapi_GameAddress* game_address,
    const struct Mdc_Fs_Path* library_path,
    const char* address_name
) {
  struct Mapi_GameAddress* init_game_address;

  struct Mdc_BasicString address_name_str;
  struct Mdc_BasicString* init_address_name_str;

  struct Mapi_Impl_GameAddressLocator* game_address_locator;

  InitStatic();

  init_address_name_str = Mdc_BasicString_InitFromCStr(
      &address_name_str,
      Mdc_CharTraitsChar_GetCharTraits(),
      address_name
  );

  if (init_address_name_str != &address_name_str) {
    ExitOnMdcFunctionFailure(
        L"Mdc_BasicString_InitFromCStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  game_address_locator = Mdc_Map_At(
      Mdc_Map_At(
          game_address_table,
          library_path
      ),
      &address_name_str
  );

  if (game_address_locator == NULL) {
    ExitOnMdcFunctionFailure(L"Mdc_Map_At", __FILEW__, __LINE__);
    goto return_bad;
  }

  init_game_address = Mapi_Impl_GameAddressLocator_LocateGameAddress(
      game_address,
      game_address_locator
  );

  if (init_game_address != game_address) {
    goto return_bad;
  }

  return game_address;

return_bad:
  return NULL;
}
