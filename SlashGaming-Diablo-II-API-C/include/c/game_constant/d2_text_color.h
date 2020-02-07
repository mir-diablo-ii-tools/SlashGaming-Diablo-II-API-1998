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

#ifndef SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_
#define SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_

#include "../../dllexport_define.inc"

/**
 * Generic enum definitions
 */

enum D2_TextColor {
  TEXT_COLOR_WHITE,
  TEXT_COLOR_RED,
  TEXT_COLOR_GREEN,
  TEXT_COLOR_BLUE,
  TEXT_COLOR_GOLD,
  TEXT_COLOR_DARK_GREY,
  TEXT_COLOR_BLACK,
  TEXT_COLOR_TAN,
  TEXT_COLOR_ORANGE,
  TEXT_COLOR_YELLOW,
  TEXT_COLOR_DARKER_GREEN,
  TEXT_COLOR_PURPLE,
  TEXT_COLOR_DARK_GREEN,
  TEXT_COLOR_METALLIC,
  TEXT_COLOR_LIGHT_GREY,
  TEXT_COLOR_CORRUPT,
  TEXT_COLOR_BRIGHT_WHITE,
  TEXT_COLOR_DARK_RED,
  TEXT_COLOR_BROWN,
};

/**
 * Version-specific enum definitions
 */

enum D2_TextColor_1_00 {
  TEXT_COLOR_1_00_WHITE,
  TEXT_COLOR_1_00_RED,
  TEXT_COLOR_1_00_GREEN,
  TEXT_COLOR_1_00_BLUE,
  TEXT_COLOR_1_00_GOLD,
  TEXT_COLOR_1_00_DARK_GREY,
  TEXT_COLOR_1_00_BLACK,
  TEXT_COLOR_1_00_TAN,
  TEXT_COLOR_1_00_ORANGE,
  TEXT_COLOR_1_00_YELLOW,
  TEXT_COLOR_1_00_DARKER_GREEN,
  TEXT_COLOR_1_00_PURPLE,
  TEXT_COLOR_1_00_DARK_GREEN,

  // TEXT_COLOR_1_00_WHITE (same as 1) = 13,
  // TEXT_COLOR_1_00_BLACK (same as 6),

  TEXT_COLOR_1_00_METALLIC = 15,
  TEXT_COLOR_1_00_LIGHT_GREY,
  TEXT_COLOR_1_00_CORRUPT,
  TEXT_COLOR_1_00_BRIGHT_WHITE,
  TEXT_COLOR_1_00_DARK_RED,
  TEXT_COLOR_1_00_BROWN,
};

/**
 * Typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef enum D2_TextColor D2_TextColor;
typedef enum D2_TextColor_1_00 D2_TextColor_1_00;

#endif // SGD2MAPI_ENABLE_TYPEDEFS

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT int D2_TextColor_ToGameValue(enum D2_TextColor api_value);

DLLEXPORT enum D2_TextColor D2_TextColor_ToApiValue(int game_value);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_
