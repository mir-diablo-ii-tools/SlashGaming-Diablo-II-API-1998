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

#include "../../../../include/c/game_function/d2gfx/d2gfx_draw_rectangle.h"

#include <mdc/std/threads.h>
#include "../../../../include/c/default_game_library.h"
#include "../../../../include/c/game_address.h"
#include "../../../../include/c/game_version.h"
#include "../../backend/game_address_table.h"
#include "../../backend/game_function/stdcall_function.h"

static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  game_address = Mapi_GameAddressTable_GetFromLibrary(
      D2_DefaultLibrary_kD2GFX,
      "DrawRectangle"
  );
}

static void InitStatic(void) {
  static once_flag game_address_init_flag = ONCE_FLAG_INIT;

  call_once(&game_address_init_flag, &InitGameAddress);
}

/**
 * External
 */

void D2_D2GFX_DrawRectangle(
    int left,
    int top,
    int right,
    int bottom,
    int primitive_color_id,
    enum D2_DrawEffect draw_effect
) {
  InitStatic();

  D2_D2GFX_DrawRectangle_1_00(
      left,
      top,
      right,
      bottom,
      primitive_color_id,
      D2_DrawEffect_ToGameValue(draw_effect)
  );
}

void D2_D2GFX_DrawRectangle_1_00(
    int32_t left,
    int32_t top,
    int32_t right,
    int32_t bottom,
    int32_t primitive_color_id,
    /* enum D2_DrawEffect_1_00 */ int32_t draw_effect
) {
  InitStatic();

  CallStdcallFunction(
      game_address.raw_address,
      6,
      left,
      top,
      right,
      bottom,
      primitive_color_id,
      draw_effect
  );
}
