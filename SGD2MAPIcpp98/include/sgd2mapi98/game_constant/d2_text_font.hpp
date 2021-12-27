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

#ifndef SGD2MAPI_CPP98_GAME_CONSTANT_D2_TEXT_FONT_HPP_
#define SGD2MAPI_CPP98_GAME_CONSTANT_D2_TEXT_FONT_HPP_

#include <sgd2mapi98.h>

#include "../../dllexport_define.inc"

namespace d2 {
namespace text_font {

/*
* These internal enums is not intended for direct public use. It is
* stricly defined here to prevent enum leak to namespace. Use the
* typedefs in the upper-level namespace instead.
*/

namespace api {

enum TextFont {
  kDiabloMenu_24 = D2_TextFont_kDiabloMenu_24,
  kDiabloMenu_30 = D2_TextFont_kDiabloMenu_30,
  kDiabloMenu_42 = D2_TextFont_kDiabloMenu_42,

  kExocet_8 = D2_TextFont_kExocet_8,
  kExocet_16 = D2_TextFont_kExocet_16,

  kExocetBlack_9 = D2_TextFont_kExocetBlack_9,
  kExocetBlack_10 = D2_TextFont_kExocetBlack_10,

  kFormal_6 = D2_TextFont_kFormal_6,
  kFormal_8 = D2_TextFont_kFormal_8,
  kFormal_10 = D2_TextFont_kFormal_10,
  kFormal_11 = D2_TextFont_kFormal_11,
  kFormal_12 = D2_TextFont_kFormal_12,

  kFormalWide_11 = D2_TextFont_kFormalWide_11,
};

} // namespace api

namespace v1_00 {

enum TextFont_1_00 {
  kFormal_8 = D2_TextFont_1_00_kFormal_8,
  kExocet_16 = D2_TextFont_1_00_kExocet_16,
  kDiabloMenu_30 = D2_TextFont_1_00_kDiabloMenu_30,
  kDiabloMenu_42 = D2_TextFont_1_00_kDiabloMenu_42,
  kFormal_10 = D2_TextFont_1_00_kFormal_10,
  kFormal_12 = D2_TextFont_1_00_kFormal_12,
  kFormal_6 = D2_TextFont_1_00_kFormal_6,
  kDiabloMenu_24 = D2_TextFont_1_00_kDiabloMenu_24,
  kFormalWide_11 = D2_TextFont_1_00_kFormalWide_11,
  kExocetBlack_10 = D2_TextFont_1_00_kExocetBlack_10,
  kExocetBlack_9 = D2_TextFont_1_00_kExocetBlack_9,
  kExocet_8 = D2_TextFont_1_00_kExocet_8,
  kFormal_11 = D2_TextFont_1_00_kFormal_11,
};

} // namespace v1_00

} // namespace text_font

/**
 * Generic enum definitions
 */

typedef text_font::api::TextFont TextFont;

/**
 * Version-specific enum definitions
 */

typedef text_font::v1_00::TextFont_1_00 TextFont_1_00;

/**
 * Function declarations
 */

namespace text_font {

DLLEXPORT int ToGameValue(TextFont api_value);

DLLEXPORT TextFont_1_00 ToGameValue_1_00(TextFont api_value);

DLLEXPORT TextFont ToApiValue(int game_value);

DLLEXPORT TextFont ToApiValue_1_00(TextFont_1_00 game_value);

} // namespace text_font
} // namespace d2

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CPP98_GAME_CONSTANT_D2_TEXT_FONT_HPP_ */
