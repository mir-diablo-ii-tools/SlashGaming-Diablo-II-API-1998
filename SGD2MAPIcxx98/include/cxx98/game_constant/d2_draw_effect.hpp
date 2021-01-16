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

#ifndef SGD2MAPI_CXX98_GAME_CONSTANT_D2_DRAW_EFFECT_HPP_
#define SGD2MAPI_CXX98_GAME_CONSTANT_D2_DRAW_EFFECT_HPP_

#include <sgd2mapi.h>

namespace d2 {

/**
 * Generic enum definitions
 */

enum DrawEffect {
  DrawEffect_kOneFourthOpaque = D2_DrawEffect_kOneFourthOpaque,
  DrawEffect_kHalfOpaque = D2_DrawEffect_kHalfOpaque,
  DrawEffect_kThreeFourthsOpaque = D2_DrawEffect_kThreeFourthsOpaque,
  DrawEffect_kUnknown03 = D2_DrawEffect_kUnknown03,
  DrawEffect_kUnknown04 = D2_DrawEffect_kUnknown04,
  DrawEffect_kNone = D2_DrawEffect_kNone,
  DrawEffect_kUnknown06 = D2_DrawEffect_kUnknown06,
  DrawEffect_kUnknown07 = D2_DrawEffect_kUnknown07
};

/**
 * Version-specific enum definitions
 */

enum DrawEffect_1_00 {
  DrawEffect_1_00_kOneFourthOpaque = D2_DrawEffect_1_00_kOneFourthOpaque,
  DrawEffect_1_00_kHalfOpaque = D2_DrawEffect_1_00_kHalfOpaque,
  DrawEffect_1_00_kThreeFourthsOpaque =
      D2_DrawEffect_1_00_kThreeFourthsOpaque,
  DrawEffect_1_00_kUnknown03 = D2_DrawEffect_1_00_kUnknown03,
  DrawEffect_1_00_kUnknown04 = D2_DrawEffect_1_00_kUnknown04,
  DrawEffect_1_00_kUnknown04 = D2_DrawEffect_1_00_kNone,
  DrawEffect_1_00_kUnknown06 = D2_DrawEffect_1_00_kUnknown06,
  DrawEffect_1_00_kUnknown07 = D2_DrawEffect_1_00_kUnknown07
};

/**
 * Function declarations
 */

int DrawEffect_ToGameValue(DrawEffect api_value) {
  return D2_DrawEffect_ToGameValue(static_cast<D2_DrawEffect>(api_value));
}

DrawEffect_1_00 DrawEffect_ToGameValue_1_00(
    DrawEffect api_value
) {
  D2_DrawEffect_1_00 actual_game_value  = D2_DrawEffect_ToGameValue_1_00(
      static_cast<D2_DrawEffect>(api_value)
  );

  return static_cast<DrawEffect_1_00>(actual_game_value);
}

DrawEffect DrawEffect_ToApiValue(int game_value) {
  return static_cast<DrawEffect>(D2_DrawEffect_ToApiValue(game_value));
}

DrawEffect DrawEffect_ToApiValue_1_00(
    DrawEffect_1_00 game_value
) {
  D2_DrawEffect actual_api_value = D2_DrawEffect_ToApiValue_1_00(
      static_cast<D2_DrawEffect_1_00>(game_value)
  );

  return static_cast<DrawEffect>(actual_api_value);
}

} // namespace d2

#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_DRAW_EFFECT_HPP_ */
