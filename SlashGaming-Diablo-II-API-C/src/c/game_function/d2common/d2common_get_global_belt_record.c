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

#include "../../../../include/c/game_function/d2common/d2common_get_global_belt_record.h"

#include <stdint.h>

#include <mdc/std/threads.h>
#include "../../../../include/c/game_version.h"
#include "../../../asm_x86_macro.h"
#include "../../../wide_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_address_table.h"
#include "../../backend/game_function/stdcall_function.h"

static once_flag init_flag = ONCE_FLAG_INIT;
static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  LoadGameAddress(
      &game_address,
      "D2Common.dll",
      "GetGlobalBeltRecord"
  );
}

void D2_D2Common_GetGlobalBeltRecord(
    unsigned int belt_record_index,
    unsigned int inventory_arrange_mode,
    struct D2_BeltRecord* out_belt_record
) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  struct D2_BeltRecord_1_00* actual_out_belt_record =
      (struct D2_BeltRecord_1_00*) out_belt_record;

  if (running_game_version <= VERSION_1_06B) {
    D2_D2Common_GetGlobalBeltRecord_1_00(
        belt_record_index,
        actual_out_belt_record
    );
  } else /* if (running_game_version >= VERSION_1_07_BETA) */ {
    D2_D2Common_GetGlobalBeltRecord_1_07(
        belt_record_index,
        inventory_arrange_mode,
        actual_out_belt_record
    );
  }
}

void D2_D2Common_GetGlobalBeltRecord_1_00(
    uint32_t belt_record_index,
    struct D2_BeltRecord_1_00* out_belt_record
) {
  call_once(&init_flag, &InitGameAddress);

  CallStdcallFunction(
      game_address.raw_address,
      2,
      belt_record_index,
      out_belt_record
  );
}

void D2_D2Common_GetGlobalBeltRecord_1_07(
    uint32_t belt_record_index,
    uint32_t inventory_arrange_mode,
    struct D2_BeltRecord_1_00* out_belt_record
) {
  call_once(&init_flag, &InitGameAddress);

  CallStdcallFunction(
      game_address.raw_address,
      3,
      belt_record_index,
      inventory_arrange_mode,
      out_belt_record
  );
}
