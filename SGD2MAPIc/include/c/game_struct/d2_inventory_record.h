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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_INVENTORY_RECORD_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_INVENTORY_RECORD_H_

#include <stddef.h>
#include <stdint.h>

#include "d2_equipment_layout.h"
#include "d2_grid_layout.h"
#include "d2_positional_rectangle.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_InventoryRecord;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0xF0 */ struct D2_InventoryRecord_1_00 {
  /* 0x00 */ struct D2_PositionalRectangle_1_00 position;
  /* 0x10 */ struct D2_GridLayout_1_00 grid_layout;
  /* 0x28 */ struct D2_EquipmentLayout_1_00 equipment_slots[10];
};

#pragma pack(pop)

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_InventoryRecord D2_InventoryRecord;
typedef struct D2_InventoryRecord_1_00 D2_InventoryRecord_1_00;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Creates a generic InventoryRecord with the specified record.
 */
DLLEXPORT struct D2_InventoryRecord* D2_InventoryRecord_CreateWithRecord(
    const struct D2_PositionalRectangle* position,
    const struct D2_GridLayout* grid_layout,
    const struct D2_EquipmentLayout* equipment_slots
);

/**
 * Destroys the InventoryRecord, freeing up resources.
 */
DLLEXPORT void D2_InventoryRecord_Destroy(
    struct D2_InventoryRecord* inventory_record
);

/**
 * Returns the element of the InventoryRecord array at the specified index.
 */
DLLEXPORT struct D2_InventoryRecord* D2_InventoryRecord_GetAt(
    struct D2_InventoryRecord* inventory_record,
    size_t index
);

/**
 * Returns the element of the InventoryRecord array at the specified index.
 */
DLLEXPORT const struct D2_InventoryRecord* D2_InventoryRecord_GetConstAt(
    const struct D2_InventoryRecord* inventory_record,
    size_t index
);

/**
 * Copies the values of each member of a InventoryRecord into a specified
 * destination.
 */
DLLEXPORT void D2_InventoryRecord_Copy(
    struct D2_InventoryRecord* dest,
    const struct D2_InventoryRecord* src
);

/**
 * Returns a pointer to the InventoryRecord's position member.
 */
DLLEXPORT struct D2_PositionalRectangle* D2_InventoryRecord_GetPosition(
    struct D2_InventoryRecord* inventory_record
);

/**
 * Returns a pointer to the InventoryRecord's position member.
 */
DLLEXPORT const struct D2_PositionalRectangle*
D2_InventoryRecord_GetConstPosition(
    const struct D2_InventoryRecord* inventory_record
);

/**
 * Returns a pointer to the InventoryRecord's grid layout member.
 */
DLLEXPORT struct D2_GridLayout* D2_InventoryRecord_GetGridLayout(
    struct D2_InventoryRecord* inventory_record
);

/**
 * Returns a pointer to the InventoryRecord's grid layout member.
 */
DLLEXPORT const struct D2_GridLayout* D2_InventoryRecord_GetConstGridLayout(
    const struct D2_InventoryRecord* inventory_record
);

/**
 * Returns a pointer to the InventoryRecord's equipment slots array member.
 */
DLLEXPORT struct D2_EquipmentLayout* D2_InventoryRecord_GetEquipmentSlots(
    struct D2_InventoryRecord* inventory_record
);

/**
 * Returns a pointer to the InventoryRecord's equipment slots array member.
 */
DLLEXPORT const struct D2_EquipmentLayout*
D2_InventoryRecord_GetConstEquipmentSlots(
    const struct D2_InventoryRecord* inventory_record
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_STRUCT_D2_INVENTORY_RECORD_H_ */
