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

#include "../../../../include/c/game_function/d2client/d2client_draw_centered_unicode_text.h"

#include <pthread.h>
#include <stdint.h>

#include "../../../asm_x86_macro.h"
#include "../../backend/game_function/fastcall_function.h"
#include "../../backend/game_address_table.h"
#include "../../backend/error_handling.h"
#include "../../../wide_macro.h"

static pthread_once_t once_flag = PTHREAD_ONCE_INIT;
static const struct MAPI_GameAddress* game_address;

static void InitGameAddress(void) {
  game_address = GetGameAddress(
      "D2Client.dll",
      "DrawCenteredUnicodeText"
  );
}

void D2_D2Client_DrawCenteredUnicodeText(
    int left,
    int position_y,
    const struct D2_UnicodeChar* text,
    int right,
    enum D2_TextColor text_color
) {
  struct D2_UnicodeChar_1_00* actual_text =
      (struct D2_UnicodeChar_1_00*) text;

  enum D2_TextColor text_color_game_value =
      D2_TextColor_ToGameValue(text_color);

  D2_D2Client_DrawCenteredUnicodeText_1_00(
      left,
      position_y,
      actual_text,
      right,
      text_color_game_value
  );
}

void D2_D2Client_DrawCenteredUnicodeText_1_00(
    int32_t left,
    int32_t position_y,
    const struct D2_UnicodeChar_1_00* text,
    int32_t right,
    int32_t text_color
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  CallFastcallFunction(
      game_address->raw_address,
      5,
      left,
      position_y,
      text,
      right,
      text_color
  );
}
