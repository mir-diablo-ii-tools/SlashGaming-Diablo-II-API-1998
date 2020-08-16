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

#include <stdint.h>

#include <mdc/std/threads.h>
#include "../../../../include/c/game_version.h"
#include "../../../asm_x86_macro.h"
#include "../../../wide_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_address_table.h"

static once_flag init_flag = ONCE_FLAG_INIT;
static struct MAPI_GameAddress game_address;

static void InitGameAddress(void) {
  LoadGameAddress(
      &game_address,
      "D2Client.dll",
      "GameType"
  );
}

enum D2_ClientGameType D2_D2Client_GetGameType(void) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_06B) {
    return D2_ClientGameType_ToApiValue_1_00(D2_D2Client_GetGameType_1_00());
  } else /* if (running_game_version >= VERSION_1_07_BETA) */ {
    return D2_ClientGameType_ToApiValue_1_07(D2_D2Client_GetGameType_1_07());
  }
}

enum D2_ClientGameType_1_00 D2_D2Client_GetGameType_1_00(void) {
  call_once(&init_flag, &InitGameAddress);

  return *(int32_t*) game_address.raw_address;
}

enum D2_ClientGameType_1_07 D2_D2Client_GetGameType_1_07(void) {
  call_once(&init_flag, &InitGameAddress);

  return *(int32_t*) game_address.raw_address;
}

void D2_D2Client_SetGameType(
    enum D2_ClientGameType game_type
) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_06B) {
    D2_D2Client_SetGameType_1_00(
        D2_ClientGameType_ToGameValue_1_00(game_type)
    );
  } else /* if (running_game_version >= VERSION_1_07_BETA) */ {
    D2_D2Client_SetGameType_1_07(
        D2_ClientGameType_ToGameValue_1_07(game_type)
    );
  }
}

void D2_D2Client_SetGameType_1_00(
    enum D2_ClientGameType_1_00 game_type
) {
  call_once(&init_flag, &InitGameAddress);

  *(int32_t*) game_address.raw_address = game_type;
}

void D2_D2Client_SetGameType_1_07(
    enum D2_ClientGameType_1_07 game_type
) {
  call_once(&init_flag, &InitGameAddress);

  *(int32_t*) game_address.raw_address = game_type;
}
