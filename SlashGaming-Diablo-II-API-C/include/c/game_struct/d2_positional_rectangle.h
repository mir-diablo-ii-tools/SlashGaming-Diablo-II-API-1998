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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_H_

#include <stdint.h>

#include "../../dllexport_define.inc"

/**
 * Generic struct definition
 */

struct D2_PositionalRectangle;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

struct D2_PositionalRectangle_1_00 {
  int32_t left;
  int32_t right;
  int32_t top;
  int32_t bottom;
};

#pragma pack(pop)

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a generic PositionalRectangle initialized with the specified
 * positions.
 */
DLLEXPORT struct D2_PositionalRectangle*
D2_PositionalRectangle_CreateWithPositions(
    int left,
    int right,
    int top,
    int bottom
);

/**
 * Destroy the PositionalRectangle, freeing up resources.
 */
DLLEXPORT void D2_PositionalRectangle_Destroy(
    struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Returns the value of the PositionalRectangle's left member.
 */
DLLEXPORT int D2_PositionalRectangle_GetLeft(
    const struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Sets the value of the PositionalRectangle's left member.
 */
DLLEXPORT void D2_PositionalRectangle_SetLeft(
    struct D2_PositionalRectangle* positional_rectangle,
    int value
);

/**
 * Returns the value of the PositionalRectangle's right member.
 */
DLLEXPORT int D2_PositionalRectangle_GetRight(
    const struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Sets the value of the PositionalRectangle's right member.
 */
DLLEXPORT void D2_PositionalRectangle_SetRight(
    struct D2_PositionalRectangle* positional_rectangle,
    int value
);

/**
 * Returns the value of the PositionalRectangle's top member value.
 */
DLLEXPORT int D2_PositionalRectangle_GetTop(
    const struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Sets the value of the PositionalRectangle's top member.
 */
DLLEXPORT void D2_PositionalRectangle_SetTop(
    struct D2_PositionalRectangle* positional_rectangle,
    int value
);

/**
 * Returns the value of the PositionalRectangle's bottom member value.
 */
DLLEXPORT int D2_PositionalRectangle_GetBottom(
    const struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Sets the value of the PositionalRectangle's bottom member.
 */
DLLEXPORT void D2_PositionalRectangle_SetBottom(
    struct D2_PositionalRectangle* positional_rectangle,
    int value
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_UNICODE_CHAR_H_
