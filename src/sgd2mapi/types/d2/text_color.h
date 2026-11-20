/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#ifndef SGD2MAPI_C_TYPES_D2_TEXT_COLOR_H_
#define SGD2MAPI_C_TYPES_D2_TEXT_COLOR_H_

#define ENUMERATOR(version, identifier) \
    D2TEXTCOLOR_##version##_##identifier

#define ENUMERATOR_LIST(version) \
    ENUMERATOR(version, WHITE) = 0, \
    ENUMERATOR(version, LIGHT_RED) = 1, \
    ENUMERATOR(version, LIGHT_GREEN) = 2, \
    ENUMERATOR(version, BLUE) = 3, \
    ENUMERATOR(version, GOLD) = 4, \
    ENUMERATOR(version, DARK_GREY) = 5, \
    ENUMERATOR(version, BLACK) = 6, \
    ENUMERATOR(version, TAN) = 7, \
    ENUMERATOR(version, ORANGE) = 8, \
    ENUMERATOR(version, YELLOW) = 9, \
    ENUMERATOR(version, DARK_GREEN) = 10, \
    ENUMERATOR(version, PURPLE) = 11, \
    ENUMERATOR(version, GREEN) = 12

enum D2TextColor_1_00 {
  ENUMERATOR_LIST(1_00),
  ENUMERATOR_LIST(1_01),
  ENUMERATOR_LIST(1_02),
  ENUMERATOR_LIST(1_03),
  ENUMERATOR_LIST(1_04),
  ENUMERATOR_LIST(1_04B),
  ENUMERATOR_LIST(1_04C),
  ENUMERATOR_LIST(1_05),
  ENUMERATOR_LIST(1_05B),
  ENUMERATOR_LIST(1_06),
  ENUMERATOR_LIST(1_06B),
  ENUMERATOR_LIST(1_07_BETA),
  ENUMERATOR_LIST(1_07),
  ENUMERATOR_LIST(1_08),
  ENUMERATOR_LIST(1_09),
  ENUMERATOR_LIST(1_09B),
  ENUMERATOR_LIST(1_09C),
  ENUMERATOR_LIST(1_09D),
  ENUMERATOR_LIST(1_10_BETA),
  ENUMERATOR_LIST(1_10S_BETA),
  ENUMERATOR_LIST(1_10),
  ENUMERATOR_LIST(1_11),
  ENUMERATOR_LIST(1_11B),
  ENUMERATOR_LIST(1_12),
  ENUMERATOR_LIST(1_13A),
  ENUMERATOR_LIST(1_13B),
  ENUMERATOR_LIST(1_13C),
  ENUMERATOR_LIST(1_13D),
  ENUMERATOR_LIST(1_14A),
  ENUMERATOR_LIST(1_14B),
  ENUMERATOR_LIST(1_14C),
  ENUMERATOR_LIST(1_14D)
};

#undef ENUMERATOR_LIST

#define D2TextColor_1_01 D2TextColor_1_00
#define D2TextColor_1_02 D2TextColor_1_01
#define D2TextColor_1_03 D2TextColor_1_02
#define D2TextColor_1_04 D2TextColor_1_03
#define D2TextColor_1_04b D2TextColor_1_04
#define D2TextColor_1_04c D2TextColor_1_04b
#define D2TextColor_1_05 D2TextColor_1_04c
#define D2TextColor_1_05b D2TextColor_1_05
#define D2TextColor_1_06 D2TextColor_1_05b
#define D2TextColor_1_06b D2TextColor_1_06
#define D2TextColor_1_07Beta D2TextColor_1_06b
#define D2TextColor_1_07 D2TextColor_1_07Beta
#define D2TextColor_1_08 D2TextColor_1_07
#define D2TextColor_1_09 D2TextColor_1_08
#define D2TextColor_1_09b D2TextColor_1_09
#define D2TextColor_1_09c D2TextColor_1_09b
#define D2TextColor_1_09d D2TextColor_1_09c
#define D2TextColor_1_10Beta D2TextColor_1_09d
#define D2TextColor_1_10sBeta D2TextColor_1_10Beta
#define D2TextColor_1_10 D2TextColor_1_10sBeta
#define D2TextColor_1_11 D2TextColor_1_10
#define D2TextColor_1_11b D2TextColor_1_11
#define D2TextColor_1_12 D2TextColor_1_11b
#define D2TextColor_1_13a D2TextColor_1_12
#define D2TextColor_1_13b D2TextColor_1_13a
#define D2TextColor_1_13c D2TextColor_1_13b
#define D2TextColor_1_13d D2TextColor_1_13c
#define D2TextColor_1_14a D2TextColor_1_13d
#define D2TextColor_1_14b D2TextColor_1_14a
#define D2TextColor_1_14c D2TextColor_1_14b
#define D2TextColor_1_14d D2TextColor_1_14c

#undef ENUMERATOR

#endif /* SGD2MAPI_C_TYPES_D2_TEXT_COLOR_H_ */
