/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2022  Mir Drualga
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

#ifndef SGD2MAPI_CPP98_GAME_CONSTANT_D2_TEXT_COLOR_HPP_
#define SGD2MAPI_CPP98_GAME_CONSTANT_D2_TEXT_COLOR_HPP_

#include <sgd2mapi98.h>

#include "../../dllexport_define.inc"

namespace d2 {
namespace text_color {

/*
* These internal enums is not intended for direct public use. It is
* stricly defined here to prevent enum leak to namespace. Use the
* typedefs in the upper-level namespace instead.
*/

namespace api {

enum TextColor {
  kWhite = D2_TextColor_kWhite,
  kRed = D2_TextColor_kRed,
  kGreen = D2_TextColor_kGreen,
  kBlue = D2_TextColor_kBlue,
  kGold = D2_TextColor_kGold,
  kDarkGrey = D2_TextColor_kDarkGrey,
  kBlack = D2_TextColor_kBlack,
  kTan = D2_TextColor_kTan,
  kOrange = D2_TextColor_kOrange,
  kYellow = D2_TextColor_kYellow,
  kDarkerGreen = D2_TextColor_kDarkerGreen,
  kPurple = D2_TextColor_kPurple,
  kDarkGreen = D2_TextColor_kDarkGreen,
  kMetallic = D2_TextColor_kMetallic,
  kLightGrey = D2_TextColor_kLightGrey,
  kCorrupt = D2_TextColor_kCorrupt,
  kBrightWhite = D2_TextColor_kBrightWhite,
  kDarkRed = D2_TextColor_kDarkRed,
  kBrown = D2_TextColor_kBrown,
};

} // namespace api

namespace v1_00 {

enum TextColor_1_00 {
  kWhite = D2_TextColor_1_00_kWhite,
  kRed = D2_TextColor_1_00_kRed,
  kGreen = D2_TextColor_1_00_kGreen,
  kBlue = D2_TextColor_1_00_kBlue,
  kGold = D2_TextColor_1_00_kGold,
  kDarkGrey = D2_TextColor_1_00_kDarkGrey,
  kBlack = D2_TextColor_1_00_kBlack,
  kTan = D2_TextColor_1_00_kTan,
  kOrange = D2_TextColor_1_00_kOrange,
  kYellow = D2_TextColor_1_00_kYellow,
  kDarkerGreen = D2_TextColor_1_00_kDarkerGreen,
  kPurple = D2_TextColor_1_00_kPurple,
  kDarkGreen = D2_TextColor_1_00_kDarkGreen,
  kMetallic = D2_TextColor_1_00_kMetallic,
  kLightGrey = D2_TextColor_1_00_kLightGrey,
  kCorrupt = D2_TextColor_1_00_kCorrupt,
  kBrightWhite = D2_TextColor_1_00_kBrightWhite,
  kDarkRed = D2_TextColor_1_00_kDarkRed,
  kBrown = D2_TextColor_1_00_kBrown,
};

} // namespace v1_00

} // namespace text_color

/**
 * Generic enum definitions
 */

typedef text_color::api::TextColor TextColor;

/**
 * Version-specific enum definitions
 */

typedef text_color::v1_00::TextColor_1_00 TextColor_1_00;

/**
 * Function declarations
 */

namespace text_color {

DLLEXPORT int ToGameValue(TextColor api_value);

DLLEXPORT TextColor_1_00 ToGameValue_1_00(TextColor api_value);

DLLEXPORT TextColor ToApiValue(int game_value);

DLLEXPORT TextColor ToApiValue_1_00(TextColor_1_00 game_value);

} // namespace text_color
} // namespace d2

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CPP98_GAME_CONSTANT_D2_TEXT_COLOR_HPP_ */
