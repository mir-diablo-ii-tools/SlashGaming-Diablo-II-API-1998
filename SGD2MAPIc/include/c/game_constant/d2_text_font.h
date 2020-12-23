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

#ifndef SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_FONT_H_
#define SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_FONT_H_

#include "../../dllexport_define.inc"

/**
 * Generic enum definitions
 */

enum D2_TextFont {
  D2_TextFont_kDiabloMenu_24,
  D2_TextFont_kDiabloMenu_30,
  D2_TextFont_kDiabloMenu_42,

  D2_TextFont_kExocet_8,
  D2_TextFont_kExocet_16,

  D2_TextFont_kExocetBlack_9,
  D2_TextFont_kExocetBlack_10,

  D2_TextFont_kFormal_6,
  D2_TextFont_kFormal_8,
  D2_TextFont_kFormal_10,
  D2_TextFont_kFormal_11,
  D2_TextFont_kFormal_12,

  D2_TextFont_kFormalWide_11,
};

/**
 * Version-specific enum definitions
 */

enum D2_TextFont_1_00 {
  D2_TextFont_1_00_kFormal_8,
  D2_TextFont_1_00_kExocet_16,
  D2_TextFont_1_00_kDiabloMenu_30,
  D2_TextFont_1_00_kDiabloMenu_42,
  D2_TextFont_1_00_kFormal_10,
  D2_TextFont_1_00_kFormal_12,
  D2_TextFont_1_00_kFormal_6,
  D2_TextFont_1_00_kDiabloMenu_24,
  D2_TextFont_1_00_kFormalWide_11,
  D2_TextFont_1_00_kExocetBlack_10,
  D2_TextFont_1_00_kExocetBlack_9,
  D2_TextFont_1_00_kExocet_8,

  /* D2_TextFont_1_00_kFormal_6 (same as 6) = 12 */

  D2_TextFont_1_00_kFormal_11 = 13
};

/**
 * Typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef enum D2_TextFont D2_TextFont;
typedef enum D2_TextFont_1_00 D2_TextFont_1_00;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT int D2_TextFont_ToGameValue(enum D2_TextFont api_value);

DLLEXPORT enum D2_TextFont_1_00 D2_TextFont_ToGameValue_1_00(
    enum D2_TextFont api_value
);

DLLEXPORT enum D2_TextFont D2_TextFont_ToApiValue(int game_value);

DLLEXPORT enum D2_TextFont D2_TextFont_ToApiValue_1_00(
    enum D2_TextFont_1_00 game_value
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_FONT_H_ */
