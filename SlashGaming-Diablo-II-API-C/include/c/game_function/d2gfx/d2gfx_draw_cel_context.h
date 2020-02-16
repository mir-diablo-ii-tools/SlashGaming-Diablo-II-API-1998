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

#ifndef SGD2MAPI_C_GAME_FUNC_D2GFX_D2GFX_DRAW_CEL_CONTEXT_H_
#define SGD2MAPI_C_GAME_FUNC_D2GFX_D2GFX_DRAW_CEL_CONTEXT_H_

#include <stdbool.h>
#include <stdint.h>

#include "../../game_bool.h"
#include "../../game_struct/d2_cel_context.h"
#include "../../game_constant/d2_draw_effect.h"
#include "../../game_undefined.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT bool D2_D2GFX_DrawCelContext(
    struct D2_CelContext* cel_context,
    int position_x,
    int position_y,
    unsigned int bgrt_color,
    enum D2_DrawEffect draw_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
);

DLLEXPORT mapi_bool32 D2_D2GFX_DrawCelContext_1_00(
    struct D2_CelContext_1_00* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    int32_t draw_cel_context_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
);

DLLEXPORT mapi_bool32 D2_D2GFX_DrawCelContext_1_12A(
    struct D2_CelContext_1_12A* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    int32_t draw_cel_context_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
);

DLLEXPORT mapi_bool32 D2_D2GFX_DrawCelContext_1_13C(
    struct D2_CelContext_1_13C* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    int32_t draw_cel_context_effect,
    struct MAPI_Undefined* unknown_06__set_to_nullptr
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_FUNC_D2GFX_D2GFX_DRAW_CEL_CONTEXT_H_
