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

#ifndef SGD2MAPI_CXX98_GAME_CONSTANT_D2_TEXT_COLOR_HPP_
#define SGD2MAPI_CXX98_GAME_CONSTANT_D2_TEXT_COLOR_HPP_

#include <sgd2mapi.h>

namespace d2 {

/**
 * Generic enum definitions
 */

enum TextColor {
  TextColor_kWhite = D2_TextColor_kWhite,
  TextColor_kRed = D2_TextColor_kRed,
  TextColor_kGreen = D2_TextColor_kGreen,
  TextColor_kBlue = D2_TextColor_kBlue,
  TextColor_kGold = D2_TextColor_kGold,
  TextColor_kDarkGrey = D2_TextColor_kDarkGrey,
  TextColor_kBlack = D2_TextColor_kBlack,
  TextColor_kTan = D2_TextColor_kTan,
  TextColor_kOrange = D2_TextColor_kOrange,
  TextColor_kYellow = D2_TextColor_kYellow,
  TextColor_kDarkerGreen = D2_TextColor_kDarkerGreen,
  TextColor_kPurple = D2_TextColor_kPurple,
  TextColor_kDarkGreen = D2_TextColor_kDarkGreen,
  TextColor_kMetallic = D2_TextColor_kMetallic,
  TextColor_kLightGrey = D2_TextColor_kLightGrey,
  TextColor_kCorrupt = D2_TextColor_kCorrupt,
  TextColor_kBrightWhite = D2_TextColor_kBrightWhite,
  TextColor_kDarkRed = D2_TextColor_kDarkRed,
  TextColor_kBrown = D2_TextColor_kBrown,
};

/**
 * Version-specific enum definitions
 */

enum TextColor_1_00 {
  TextColor_1_00_kWhite = D2_TextColor_1_00_kWhite,
  TextColor_1_00_kRed = D2_TextColor_1_00_kRed,
  TextColor_1_00_kGreen = D2_TextColor_1_00_kGreen,
  TextColor_1_00_kBlue = D2_TextColor_1_00_kBlue,
  TextColor_1_00_kGold = D2_TextColor_1_00_kGold,
  TextColor_1_00_kDarkGrey = D2_TextColor_1_00_kDarkGrey,
  TextColor_1_00_kBlack = D2_TextColor_1_00_kBlack,
  TextColor_1_00_kTan = D2_TextColor_1_00_kTan,
  TextColor_1_00_kOrange = D2_TextColor_1_00_kOrange,
  TextColor_1_00_kYellow = D2_TextColor_1_00_kYellow,
  TextColor_1_00_kDarkerGreen = D2_TextColor_1_00_kDarkerGreen,
  TextColor_1_00_kPurple = D2_TextColor_1_00_kPurple,
  TextColor_1_00_kDarkGreen = D2_TextColor_1_00_kDarkGreen,
  TextColor_1_00_kMetallic = D2_TextColor_1_00_kMetallic,
  TextColor_1_00_kLightGrey = D2_TextColor_1_00_kLightGrey,
  TextColor_1_00_kCorrupt = D2_TextColor_1_00_kCorrupt,
  TextColor_1_00_kBrightWhite = D2_TextColor_1_00_kBrightWhite,
  TextColor_1_00_kDarkRed = D2_TextColor_1_00_kDarkRed,
  TextColor_1_00_kBrown = D2_TextColor_1_00_kBrown,
};

/**
 * Function declarations
 */

int TextColor_ToGameValue(TextColor api_value) {
  return D2_TextColor_ToGameValue(static_cast<D2_TextColor>(api_value));
}

TextColor_1_00 TextColor_ToGameValue_1_00(
    TextColor api_value
) {
  D2_TextColor_1_00 actual_game_value = D2_TextColor_ToGameValue_1_00(
      static_cast<D2_TextColor>(api_value)
  );

  return static_cast<TextColor_1_00>(actual_game_value);
}

TextColor TextColor_ToApiValue(int game_value) {
  return static_cast<TextColor>(D2_TextColor_ToApiValue(game_value));
}

TextColor TextColor_ToApiValue_1_00(
    TextColor_1_00 game_value
) {
  D2_TextColor actual_api_value =
      D2_TextColor_ToApiValue_1_00(
          static_cast<D2_TextColor_1_00>(game_value)
      );

  return static_cast<TextColor>(actual_api_value);
}

} // namespace d2

#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_TEXT_COLOR_HPP_ */
