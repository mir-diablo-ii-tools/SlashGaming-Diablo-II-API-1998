/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2021  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++98.
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

#include "../../../../include/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.hpp"

#include <sgd2mapi98.h>

namespace d2 {
namespace d2gfx {

bool DrawCelContext(
    CelContext* cel_context,
    int position_x,
    int position_y,
    unsigned int bgrt_color,
    DrawEffect draw_effect,
    ::mapi::Undefined* unknown_06__set_to_nullptr
) {
  return !!::D2_D2GFX_DrawCelContext(
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      static_cast< ::D2_DrawEffect>(draw_effect),
      unknown_06__set_to_nullptr
  );
}

::mapi::bool32 DrawCelContext_1_00(
    CelContext_1_00* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    DrawEffect_1_00 draw_effect,
    ::mapi::Undefined* unknown_06__set_to_nullptr
) {
  return ::D2_D2GFX_DrawCelContext_1_00(
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      draw_effect,
      unknown_06__set_to_nullptr
  );
}

::mapi::bool32 DrawCelContext_1_12A(
    CelContext_1_12A* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    DrawEffect_1_00 draw_effect,
    ::mapi::Undefined* unknown_06__set_to_nullptr
) {
  return ::D2_D2GFX_DrawCelContext_1_12A(
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      draw_effect,
      unknown_06__set_to_nullptr
  );
}

::mapi::bool32 DrawCelContext_1_13C(
    CelContext_1_13C* cel_context,
    int32_t position_x,
    int32_t position_y,
    uint32_t bgrt_color,
    DrawEffect_1_00 draw_effect,
    ::mapi::Undefined* unknown_06__set_to_nullptr
) {
  return ::D2_D2GFX_DrawCelContext_1_13C(
      cel_context,
      position_x,
      position_y,
      bgrt_color,
      draw_effect,
      unknown_06__set_to_nullptr
  );
}

} // namespace d2gfx
} // namespace d2
