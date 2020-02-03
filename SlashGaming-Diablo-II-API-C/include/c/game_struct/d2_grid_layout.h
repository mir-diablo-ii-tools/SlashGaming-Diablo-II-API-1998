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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_GRID_LAYOUT_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_GRID_LAYOUT_H_

#include <stddef.h>
#include <stdint.h>

#include "d2_positional_rectangle.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_GridLayout;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x18 */ struct D2_GridLayout_1_00 {
  /* 0x00 */ uint8_t num_columns;
  /* 0x01 */ uint8_t num_rows;
  /* 0x02 */ uint8_t unused__to_align_0x02[2];
  /* 0x04 */ struct D2_PositionalRectangle_1_00 position;
  /* 0x14 */ uint8_t width;
  /* 0x15 */ uint8_t height;
  /* 0x16 */ uint8_t unused__to_align_0x22[2];
};

#pragma pack(pop)

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_GridLayout D2_GridLayout;
typedef struct D2_GridLayout_1_00 D2_GridLayout_1_00;

#endif // SGD2MAPI_ENABLE_TYPEDEFS

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a generic GridLayout with the specified layout.
 */
DLLEXPORT struct D2_GridLayout* D2_GridLayout_CreateWithLayout(
    uint_least8_t num_columns,
    uint_least8_t num_rows,
    const struct D2_PositionalRectangle* position,
    uint_least8_t width,
    uint_least8_t height
);

/**
 * Destroys the GridLayout, freeing up resources.
 */
DLLEXPORT void D2_GridLayout_Destroy(
    struct D2_GridLayout* grid_layout
);

/**
 * Returns the value of the GridLayout's number of columns member.
 */
DLLEXPORT uint_least8_t D2_GridLayout_GetNumColumns(
    const struct D2_GridLayout* grid_layout
);

/**
 * Sets the value of the GridLayout's number of columns member.
 */
DLLEXPORT void D2_GridLayout_SetNumColumns(
    struct D2_GridLayout* grid_layout,
    uint_least8_t num_columns
);

/**
 * Returns the value of the GridLayout's number of rows member.
 */
DLLEXPORT uint_least8_t D2_GridLayout_GetNumRows(
    const struct D2_GridLayout* grid_layout
);

/**
 * Sets the value of the GridLayout's number of rows member.
 */
DLLEXPORT void D2_GridLayout_SetNumRows(
    struct D2_GridLayout* grid_layout,
    uint_least8_t num_rows
);

/**
 * Returns a pointer to the GridLayout's position member.
 */
DLLEXPORT struct D2_PositionalRectangle* D2_GridLayout_GetPosition(
    struct D2_GridLayout* grid_layout
);

/**
 * Returns a pointer to the GridLayout's position member.
 */
DLLEXPORT const struct D2_PositionalRectangle* D2_GridLayout_GetConstPosition(
    const struct D2_GridLayout* grid_layout
);

/**
 * Returns the value of the GridLayout's width member.
 */
DLLEXPORT uint_least8_t D2_GridLayout_GetWidth(
    const struct D2_GridLayout* grid_layout
);

/**
 * Sets the value of the GridLayout's width member.
 */
DLLEXPORT void D2_GridLayout_SetWidth(
    struct D2_GridLayout* grid_layout,
    uint_least8_t width
);

/**
 * Returns the value of the GridLayout's height member.
 */
DLLEXPORT uint_least8_t D2_GridLayout_GetHeight(
    const struct D2_GridLayout* grid_layout
);

/**
 * Sets the value of the GridLayout's height member.
 */
DLLEXPORT void D2_GridLayout_SetHeight(
    struct D2_GridLayout* grid_layout,
    uint_least8_t height
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_GRID_LAYOUT_H_
