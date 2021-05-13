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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_CEL_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_CEL_H_

#include <stddef.h>

#include <mdc/std/assert.h>
#include <mdc/std/stdint.h>
#include "../game_undefined.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_Cel;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x?? */ struct D2_Cel_1_00 {
  /* 0x00 */ Mapi_UndefinedByte unknown_0x00[0x04 - 0x00];
  /* 0x04 */ int32_t width;
  /* 0x08 */ int32_t height;
  /* 0x0C */ int32_t offset_x;
  /* 0x10 */ int32_t offset_y;
};

#pragma pack(pop)

/**
 * View and wrapper declarations
 */

struct D2_Cel_View {
  union {
    const struct D2_Cel_1_00* v1_00;
  } ptr;
};

struct D2_Cel_Wrapper {
  union {
    struct D2_Cel_1_00* v1_00;
  } ptr;
};

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_Cel D2_Cel;
typedef struct D2_Cel_1_00 D2_Cel_1_00;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Returns the value of the Cel's height member.
 */
DLLEXPORT int D2_Cel_GetHeight(const struct D2_Cel* cel);

/**
 * Sets the value of the Cel's height member.
 */
DLLEXPORT void D2_Cel_SetHeight(struct D2_Cel* cel, int height);

/**
 * Returns the value of the Cel's offset-x member.
 */
DLLEXPORT int D2_Cel_GetOffsetX(const struct D2_Cel* cel);

/**
 * Sets the value of the Cel's offset-x member.
 */
DLLEXPORT void D2_Cel_SetOffsetX(struct D2_Cel* cel, int offset_x);

/**
 * Returns the value of the Cel's offset-y member.
 */
DLLEXPORT int D2_Cel_GetOffsetY(const struct D2_Cel* cel);

/**
 * Sets the value of the Cel's offset-y member.
 */
DLLEXPORT void D2_Cel_SetOffsetY(struct D2_Cel* cel, int offset_y);

/**
 * Returns the value of the Cel's width member.
 */
DLLEXPORT int D2_Cel_GetWidth(const struct D2_Cel* cel);

/**
 * Sets the value of the Cel's width member.
 */
DLLEXPORT void D2_Cel_SetWidth(struct D2_Cel* cel, int width);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/**
 * Static assertions (1.00)
 */

static_assert(
    sizeof(struct D2_Cel_1_00) >= 20,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_Cel_1_00, width) == 4,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_Cel_1_00, height) == 8,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_Cel_1_00, offset_x) == 12,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_Cel_1_00, offset_y) == 16,
    "Incorrect member alignment."
);

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_STRUCT_D2_CEL_H_ */
