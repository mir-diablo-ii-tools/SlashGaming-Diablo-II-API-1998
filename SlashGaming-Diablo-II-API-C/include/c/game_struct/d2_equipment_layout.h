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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_EQUIPMENT_LAYOUT_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_EQUIPMENT_LAYOUT_H_

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "d2_positional_rectangle.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_EquipmentLayout;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x14 */ struct D2_EquipmentLayout_1_00 {
  /* 0x00 */ struct D2_PositionalRectangle_1_00 position;
  /* 0x10 */ uint8_t width;
  /* 0x11 */ uint8_t height;
  /* 0x12 */ uint8_t unused__to_align_0x12[2];
};

/**
 * Static assertions (1.00)
 */

static_assert(
    sizeof(struct D2_EquipmentLayout_1_00) == 0x14,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_EquipmentLayout_1_00, position) == 0x00,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_EquipmentLayout_1_00, width) == 0x10,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_EquipmentLayout_1_00, height) == 0x11,
    "Incorrect member alignment."
);

#pragma pack(pop)

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_EquipmentLayout D2_EquipmentLayout;
typedef struct D2_EquipmentLayout_1_00 D2_EquipmentLayout_1_00;

#endif // SGD2MAPI_ENABLE_TYPEDEFS

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a generic EquipmentLayout with the specified position, width, and
 * height.
 */
DLLEXPORT struct D2_EquipmentLayout* D2_EquipmentLayout_CreateWithLayout(
    const struct D2_PositionalRectangle* position,
    uint_least8_t width,
    uint_least8_t height
);

/**
 * Destroys the EquipmentLayout, freeing up resources.
 */
DLLEXPORT void D2_EquipmentLayout_Destroy(
    struct D2_EquipmentLayout* equipment_layout
);

/**
 * Returns a pointer to the EquipmentLayout's position member.
 */
DLLEXPORT struct D2_PositionalRectangle* D2_EquipmentLayout_GetPosition(
    struct D2_EquipmentLayout* equipment_layout
);

/**
 * Returns a pointer to the EquipmentLayout's position member.
 */
DLLEXPORT const struct D2_PositionalRectangle*
D2_EquipmentLayout_GetConstPosition(
    const struct D2_EquipmentLayout* equipment_layout
);

/**
 * Returns the value of the EquipmentLayout's width member.
 */
DLLEXPORT uint_least8_t D2_EquipmentLayout_GetWidth(
    const struct D2_EquipmentLayout* equipment_layout
);

/**
 * Sets the value of the EquipmentLayout's width member.
 */
DLLEXPORT void D2_EquipmentLayout_SetWidth(
    struct D2_EquipmentLayout* equipment_layout,
    uint_least8_t width
);

/**
 * Returns the value of the EquipmentLayout's height member.
 */
DLLEXPORT uint_least8_t D2_EquipmentLayout_GetHeight(
    const struct D2_EquipmentLayout* equipment_layout
);

/**
 * Sets the value of the EquipmentLayout's height member.
 */
DLLEXPORT void D2_EquipmentLayout_SetHeight(
    struct D2_EquipmentLayout* equipment_layout,
    uint_least8_t height
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_EQUIPMENT_LAYOUT_H_
