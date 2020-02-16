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

#include "../../../../include/c/game_function/d2gfx/d2gfx_draw_cel_context.h"

#include <pthread.h>
#include <stdint.h>

#include "../../../asm_x86_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_address_table.h"
#include "../../../../include/c/game_version.h"
#include "../../backend/game_function/stdcall_function.h"
#include "../../../wide_macro.h"

static pthread_once_t once_flag = PTHREAD_ONCE_INIT;
static struct MAPI_GameAddress* game_address;

static void InitGameAddress(void) {
  game_address = GetGameAddress(
      "D2GFX.dll",
      "DrawCelContext"
  );
}

bool D2_D2GFX_DrawCelContext(
    struct D2_CelContext* cel_context,
    int position_x,
    int position_y,
    unsigned int bgrt_color,
    enum D2_DrawEffect draw_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    return (bool) D2_D2GFX_DrawCelContext_1_00(
        (struct D2_CelContext_1_00*) cel_context,
        position_x,
        position_y,
        bgrt_color,
        D2_DrawEffect_ToGameValue(draw_effect),
        unknown_06__set_to_nullptr
    );
  } else if (running_game_version == VERSION_1_12A) {
    return (bool) D2_D2GFX_DrawCelContext_1_12A(
        (struct D2_CelContext_1_12A*) cel_context,
        position_x,
        position_y,
        bgrt_color,
        D2_DrawEffect_ToGameValue(draw_effect),
        unknown_06__set_to_nullptr
    );
  } else /* if (running_game_version > VERSION_1_13A_BETA) */ {
    return (bool) D2_D2GFX_DrawCelContext_1_13C(
        (struct D2_CelContext_1_13C*) cel_context,
        position_x,
        position_y,
        bgrt_color,
        D2_DrawEffect_ToGameValue(draw_effect),
        unknown_06__set_to_nullptr
    );
  }
}

mapi_bool32 D2_D2GFX_DrawCelContext_1_00(
    struct D2_CelContext_1_00* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    int32_t draw_cel_context_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (mapi_bool32) CallStdcallFunction(
      game_address->raw_address,
      6,
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      draw_cel_context_effect,
      unknown_06__set_to_nullptr
  );
}

mapi_bool32 D2_D2GFX_DrawCelContext_1_12A(
    struct D2_CelContext_1_12A* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    int32_t draw_cel_context_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (mapi_bool32) CallStdcallFunction(
      game_address->raw_address,
      6,
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      draw_cel_context_effect,
      unknown_06__set_to_nullptr
  );
}

mapi_bool32 D2_D2GFX_DrawCelContext_1_13C(
    struct D2_CelContext_1_13C* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    int32_t draw_cel_context_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (mapi_bool32) CallStdcallFunction(
      game_address->raw_address,
      6,
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      draw_cel_context_effect,
      unknown_06__set_to_nullptr
  );
}
