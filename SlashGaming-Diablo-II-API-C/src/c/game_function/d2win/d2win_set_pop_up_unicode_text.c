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

#include "../../../../include/c/game_function/d2win/d2win_set_pop_up_unicode_text.h"

#include <stdint.h>

#include <mdc/std/threads.h>
#include "../../../../include/c/game_version.h"
#include "../../../asm_x86_macro.h"
#include "../../../wide_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_address_table.h"
#include "../../backend/game_function/fastcall_function.h"

static once_flag init_flag = ONCE_FLAG_INIT;
static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  LoadGameAddress(
      &game_address,
      "D2Win.dll",
      "SetPopUpUnicodeText"
  );
}

void D2_D2Win_SetPopUpUnicodeText(
    const struct D2_UnicodeChar* text,
    int position_x,
    int position_y,
    enum D2_TextColor text_color,
    bool is_text_box_centered
) {
  const struct D2_UnicodeChar_1_00* actual_text =
      (const struct D2_UnicodeChar_1_00*) text;

  D2_D2Win_SetPopUpUnicodeText_1_00(
      actual_text,
      position_x,
      position_y,
      D2_TextColor_ToGameValue(text_color),
      is_text_box_centered
  );
}

void D2_D2Win_SetPopUpUnicodeText_1_00(
    const struct D2_UnicodeChar_1_00* text,
    int32_t position_x,
    int32_t position_y,
    int32_t text_color,
    mapi_bool32 is_text_box_centered
) {
  call_once(&init_flag, &InitGameAddress);

  CallFastcallFunction(
      game_address.raw_address,
      5,
      text,
      position_x,
      position_y,
      text_color,
      is_text_box_centered
  );
}
