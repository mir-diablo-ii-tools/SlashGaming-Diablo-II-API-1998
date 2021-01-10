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

#include "../../../../include/c/game_variable/d2client/d2client_game_type.h"

#include "../../../../include/c/default_game_library.h"
#include "../../../../include/c/game_address.h"
#include "../../../../include/c/game_version.h"
#include "../../backend/game_address_table.h"

static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  game_address = Mapi_GameAddressTable_GetFromLibrary(
      D2_DefaultLibrary_kD2Client,
      "GameType"
  );
}

static void InitStatic(void) {
  static int is_game_address_init = 0;

  if (is_game_address_init) {
    InitGameAddress();

    is_game_address_init = 1;
  }
}

/**
 * External
 */

enum D2_ClientGameType D2_D2Client_GetGameType(void) {
  InitStatic();

  return D2_D2Client_GetGameType_1_00();
}

/* enum D2_ClientGameType_1_00 */ int32_t
D2_D2Client_GetGameType_1_00(void) {
  InitStatic();

  return *(int32_t*) game_address.raw_address;
}

void D2_D2Client_SetGameType(
    enum D2_ClientGameType game_type
) {
  InitStatic();

  D2_D2Client_SetGameType_1_00(game_type);
}

void D2_D2Client_SetGameType_1_00(
    /* enum D2_ClientGameType_1_00 */ int32_t game_type
) {
  InitStatic();

  *(int32_t*) game_address.raw_address = game_type;
}
