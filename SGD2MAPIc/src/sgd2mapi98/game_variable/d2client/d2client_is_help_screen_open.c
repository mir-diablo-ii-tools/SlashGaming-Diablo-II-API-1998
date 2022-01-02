/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../../../include/sgd2mapi98/game_variable/d2client/d2client_is_help_screen_open.h"

#include "../../../../include/sgd2mapi98/default_game_library.h"
#include "../../../../include/sgd2mapi98/game_address.h"
#include "../../../../include/sgd2mapi98/game_version.h"
#include "../../backend/game_address_table.h"

static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  game_address = Mapi_GameAddressTable_GetFromLibrary(
      D2_DefaultLibrary_kD2Client,
      "IsHelpScreenOpen"
  );
}

static void InitStatic(void) {
  static int is_game_address_init = 0;

  if (!is_game_address_init) {
    InitGameAddress();

    is_game_address_init = 1;
  }
}

/**
 * External
 */

int D2_D2Client_GetIsHelpScreenOpen(void) {
  InitStatic();

  return D2_D2Client_GetIsHelpScreenOpen_1_00();
}

mapi_bool32 D2_D2Client_GetIsHelpScreenOpen_1_00(void) {
  InitStatic();

  return *(mapi_bool32*) game_address.raw_address;
}

void D2_D2Client_SetIsHelpScreenOpen(
    int is_help_screen_open
) {
  InitStatic();

  D2_D2Client_SetIsHelpScreenOpen_1_00(is_help_screen_open);
}

void D2_D2Client_SetIsHelpScreenOpen_1_00(
    mapi_bool32 is_help_screen_open
) {
  InitStatic();

  *(mapi_bool32*) game_address.raw_address = is_help_screen_open;
}
