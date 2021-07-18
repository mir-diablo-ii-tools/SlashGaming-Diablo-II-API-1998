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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_CEL_CONTEXT_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_CEL_CONTEXT_H_

#include <mdc/std/assert.h>
#include <mdc/std/stdint.h>
#include "d2_cel_file.h"
#include "../game_undefined.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_CelContext;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x48 */ struct D2_CelContext_1_00 {
  /* 0x00 */ Mapi_UndefinedByte unknown_0x00[0x04 - 0x00];
  /* 0x04 */ struct D2_CelFile_1_00* cel_file;
  /* 0x08 */ uint32_t frame_index;
  /* 0x0C */ uint32_t direction_index;
  /* 0x10 */ Mapi_UndefinedByte unknown_0x10[0x48 - 0x10];
};

/* sizeof: 0x48 */ struct D2_CelContext_1_12A {
  /* 0x00 */ Mapi_UndefinedByte unknown_0x00[0x38 - 0x00];
  /* 0x38 */ uint32_t direction_index;
  /* 0x3C */ struct D2_CelFile_1_00* cel_file;
  /* 0x40 */ uint32_t frame_index;
  /* 0x44 */ Mapi_UndefinedByte unknown_0x44[0x48 - 0x44];
};

/* sizeof: 0x48 */ struct D2_CelContext_1_13C {
  /* 0x00 */ uint32_t frame_index;
  /* 0x04 */ Mapi_UndefinedByte unknown_0x04[0x34 - 0x04];
  /* 0x34 */ struct D2_CelFile_1_00* cel_file;
  /* 0x38 */ Mapi_UndefinedByte unknown_0x38[0x40 - 0x38];
  /* 0x40 */ uint32_t direction_index;
  /* 0x44 */ Mapi_UndefinedByte unknown_0x44[0x48 - 0x44];
};

#pragma pack(pop)

/**
 * API struct declarations
 */

struct D2_CelContext_Api {
  union {
    struct D2_CelContext_1_00 v1_00;
    struct D2_CelContext_1_12A v1_12a;
    struct D2_CelContext_1_13C v1_13c;
  } value;
};

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_CelContext D2_CelContext;
typedef struct D2_CelContext_1_00 D2_CelContext_1_00;

typedef struct D2_UnicodeChar_Api D2_UnicodeChar_Api;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Returns the element of the CelContext array at the specified
 * index.
 */
DLLEXPORT struct D2_CelContext* D2_CelContext_Access(
    struct D2_CelContext* cel_context,
    size_t index
);

/**
 * Returns the element of the CelContext array at the specified
 * index.
 */
DLLEXPORT const struct D2_CelContext* D2_CelContext_AccessConst(
    const struct D2_CelContext* cel_context,
    size_t index
);

/**
 * Assigns each CelContext member the values of the source
 * CelContext. This is a shallow copy operation.
 */
DLLEXPORT void D2_CelContext_AssignMembers(
    struct D2_CelContext* dest,
    const struct D2_CelContext* src
);

/**
 * Returns the value of the CelContext's cel file pointer member.
 */
DLLEXPORT struct D2_CelFile* D2_CelContext_GetCelFile(
    struct D2_CelContext* cel_context
);

/**
 * Returns the value of the CelContext's cel file pointer member.
 */
DLLEXPORT const struct D2_CelFile* D2_CelContext_GetCelFileConst(
    const struct D2_CelContext* cel_context
);

/**
 * Sets the value of the CelContext's cel file pointer member.
 */
DLLEXPORT void D2_CelContext_SetCelFile(
    struct D2_CelContext* cel_context,
    struct D2_CelFile* cel_file
);

/**
 * Returns the value of the CelContext's direction member.
 */
DLLEXPORT unsigned int D2_CelContext_GetDirectionIndex(
    const struct D2_CelContext* cel_context
);

/**
 * Sets the value of the CelContext's direction member.
 */
DLLEXPORT void D2_CelContext_SetDirectionIndex(
    struct D2_CelContext* cel_context,
    unsigned int direction_index
);

/**
 * Returns the value of the CelContext's frame index member.
 */
DLLEXPORT unsigned int D2_CelContext_GetFrameIndex(
    const struct D2_CelContext* cel_context
);

/**
 * Sets the value of the CelContext's frame index member.
 */
DLLEXPORT void D2_CelContext_SetFrameIndex(
    struct D2_CelContext* cel_context,
    unsigned int frame_index
);

/**
 * API functions
 */

/**
 * Initializes a CelContext with the specified cel file, direction,
 * and frame.
 */
DLLEXPORT struct D2_CelContext_Api D2_CelContext_Api_Init(
    struct D2_CelFile* cel_file,
    unsigned int direction_index,
    unsigned int frame_index
);

/**
 * Deinitializes the CelContext.
 */
DLLEXPORT void D2_CelContext_Api_Deinit(
    struct D2_CelContext_Api* cel_context
);

DLLEXPORT struct D2_CelContext* D2_CelContext_Api_Get(
    struct D2_CelContext_Api* cel_context
);

DLLEXPORT const struct D2_CelContext* D2_CelContext_Api_GetConst(
    const struct D2_CelContext_Api* cel_context
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/**
 * Static assertions (1.00)
 */

static_assert(
    sizeof(struct D2_CelContext_1_00) == 0x48,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_CelContext_1_00, cel_file) == 0x04,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_00, frame_index) == 0x08,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_00, direction_index) == 0x0C,
    "Incorrect member alignment."
);

/**
 * Static assertions (1.12A)
 */

static_assert(
    sizeof(struct D2_CelContext_1_12A) == 0x48,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_CelContext_1_12A, cel_file) == 0x3C,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_12A, frame_index) == 0x40,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_12A, direction_index) == 0x38,
    "Incorrect member alignment."
);

/**
 * Static assertions (1.13C)
 */

static_assert(
    sizeof(struct D2_CelContext_1_13C) == 0x48,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_CelContext_1_13C, cel_file) == 0x34,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_13C, frame_index) == 0x00,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_13C, direction_index) == 0x40,
    "Incorrect member alignment."
);

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_STRUCT_D2_CEL_CONTEXT_H_ */
