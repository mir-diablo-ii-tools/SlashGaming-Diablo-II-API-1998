/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#ifndef SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_
#define SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_

#include "../../dllexport_define.inc"

/**
 * Generic enum definitions
 */

enum D2_TextColor {
  D2_TextColor_kWhite,
  D2_TextColor_kRed,
  D2_TextColor_kGreen,
  D2_TextColor_kBlue,
  D2_TextColor_kGold,
  D2_TextColor_kDarkGrey,
  D2_TextColor_kBlack,
  D2_TextColor_kTan,
  D2_TextColor_kOrange,
  D2_TextColor_kYellow,
  D2_TextColor_kDarkerGreen,
  D2_TextColor_kPurple,
  D2_TextColor_kDarkGreen,
  D2_TextColor_kMetallic,
  D2_TextColor_kLightGrey,
  D2_TextColor_kCorrupt,
  D2_TextColor_kBrightWhite,
  D2_TextColor_kDarkRed,
  D2_TextColor_kBrown,
};

/**
 * Version-specific enum definitions
 */

enum D2_TextColor_1_00 {
  D2_TextColor_1_00_kWhite,
  D2_TextColor_1_00_kRed,
  D2_TextColor_1_00_kGreen,
  D2_TextColor_1_00_kBlue,
  D2_TextColor_1_00_kGold,
  D2_TextColor_1_00_kDarkGrey,
  D2_TextColor_1_00_kBlack,
  D2_TextColor_1_00_kTan,
  D2_TextColor_1_00_kOrange,
  D2_TextColor_1_00_kYellow,
  D2_TextColor_1_00_kDarkerGreen,
  D2_TextColor_1_00_kPurple,
  D2_TextColor_1_00_kDarkGreen,

  /*
  * D2_TextColor_1_00_kWhite (same as 1) = 13,
  * D2_TextColor_1_00_kBlack (same as 6),
  */

  D2_TextColor_1_00_kMetallic = 15,
  D2_TextColor_1_00_kLightGrey,
  D2_TextColor_1_00_kCorrupt,
  D2_TextColor_1_00_kBrightWhite,
  D2_TextColor_1_00_kDarkRed,
  D2_TextColor_1_00_kBrown,
};

/**
 * Typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef enum D2_TextColor D2_TextColor;
typedef enum D2_TextColor_1_00 D2_TextColor_1_00;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT int D2_TextColor_ToGameValue(enum D2_TextColor api_value);

DLLEXPORT enum D2_TextColor_1_00 D2_TextColor_ToGameValue_1_00(
    enum D2_TextColor api_value
);

DLLEXPORT enum D2_TextColor D2_TextColor_ToApiValue(int game_value);

DLLEXPORT enum D2_TextColor D2_TextColor_ToApiValue_1_00(
    enum D2_TextColor_1_00 game_value
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_ */
