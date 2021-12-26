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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_H_

#include <stddef.h>

#include <mdc/std/assert.h>
#include <mdc/std/stdint.h>

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_PositionalRectangle;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x10 */ struct D2_PositionalRectangle_1_00 {
  /* 0x00 */ int32_t left;
  /* 0x04 */ int32_t right;
  /* 0x08 */ int32_t top;
  /* 0x0C */ int32_t bottom;
};

#pragma pack(pop)

/**
 * API struct declarations
 */

struct D2_PositionalRectangle_Api {
  union {
    struct D2_PositionalRectangle_1_00 v1_00;
  } value;
};

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_PositionalRectangle D2_PositionalRectangle;
typedef struct D2_PositionalRectangle_1_00 D2_PositionalRectangle_1_00;

typedef struct D2_PositionalRectangle_Api D2_PositionalRectangle_Api;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Returns the element of the PositionalRectangle array at the specified
 * index.
 */
DLLEXPORT struct D2_PositionalRectangle* D2_PositionalRectangle_Access(
    struct D2_PositionalRectangle* positional_rectangle,
    size_t index
);

/**
 * Returns the element of the PositionalRectangle array at the specified
 * index.
 */
DLLEXPORT const struct D2_PositionalRectangle*
D2_PositionalRectangle_AccessConst(
    const struct D2_PositionalRectangle* positional_rectangle,
    size_t index
);

/**
 * Assigns each PositionalRectangle member the values of the source
 * PositionalRectangle. This is a shallow copy operation.
 */
DLLEXPORT struct D2_PositionalRectangle* D2_PositionalRectangle_AssignMembers(
    struct D2_PositionalRectangle* dest,
    const struct D2_PositionalRectangle* src
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
    int left
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
    int right
);

/**
 * Returns the value of the PositionalRectangle's top member.
 */
DLLEXPORT int D2_PositionalRectangle_GetTop(
    const struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Sets the value of the PositionalRectangle's top member.
 */
DLLEXPORT void D2_PositionalRectangle_SetTop(
    struct D2_PositionalRectangle* positional_rectangle,
    int top
);

/**
 * Returns the value of the PositionalRectangle's bottom member.
 */
DLLEXPORT int D2_PositionalRectangle_GetBottom(
    const struct D2_PositionalRectangle* positional_rectangle
);

/**
 * Sets the value of the PositionalRectangle's bottom member.
 */
DLLEXPORT void D2_PositionalRectangle_SetBottom(
    struct D2_PositionalRectangle* positional_rectangle,
    int bottom
);

/**
 * API functions
 */

/**
 * Initializes a PositionalRectangle with the specified position.
 */
DLLEXPORT struct D2_PositionalRectangle_Api
D2_PositionalRectangle_Api_InitFromPositions(
    int left,
    int right,
    int top,
    int bottom
);

/**
 * Deinitialize the PositionalRectangle.
 */
DLLEXPORT void D2_PositionalRectangle_Api_Deinit(
    struct D2_PositionalRectangle_Api* positional_rectangle
);

DLLEXPORT struct D2_PositionalRectangle* D2_PositionalRectangle_Api_Get(
    struct D2_PositionalRectangle_Api* positional_rectangle
);

DLLEXPORT const struct D2_PositionalRectangle*
D2_PositionalRectangle_Api_GetConst(
    const struct D2_PositionalRectangle_Api* positional_rectangle
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/**
 * Static assertions (1.00)
 */

static_assert(
    offsetof(struct D2_PositionalRectangle_1_00, left) == 0x00,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_PositionalRectangle_1_00, right) == 0x04,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_PositionalRectangle_1_00, top) == 0x08,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_PositionalRectangle_1_00, bottom) == 0x0C,
    "Incorrect member alignment."
);

static_assert(
    sizeof(struct D2_PositionalRectangle_1_00) == 0x10,
    "Incorrect size."
);

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_H_ */
