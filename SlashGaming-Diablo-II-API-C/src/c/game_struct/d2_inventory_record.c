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

#include "../../../include/c/game_struct/d2_inventory_record.h"

#include <stdlib.h>
#include <string.h>

#include <mdc/malloc/malloc.h>
#include "../../wide_macro.h"
#include "../backend/error_handling.h"

/**
 * Function definitions
 */

struct D2_InventoryRecord* D2_InventoryRecord_CreateWithRecord(
    const struct D2_PositionalRectangle* position,
    const struct D2_GridLayout* grid_layout,
    const struct D2_EquipmentLayout* equipment_slots
) {
  struct D2_InventoryRecord_1_00* actual_inventory_record =
      (struct D2_InventoryRecord_1_00*) Mdc_malloc(
          sizeof(*actual_inventory_record)
      );

  if (actual_inventory_record == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
    goto return_bad;
  }

  actual_inventory_record->position =
      *(const struct D2_PositionalRectangle_1_00*) position;
  actual_inventory_record->grid_layout =
      *(const struct D2_GridLayout_1_00*) grid_layout;

  memcpy(
      actual_inventory_record->equipment_slots,
      equipment_slots,
      sizeof(actual_inventory_record->equipment_slots)
  );

  return (struct D2_InventoryRecord*) actual_inventory_record;

return_bad:
  return NULL;
}

void D2_InventoryRecord_Destroy(
    struct D2_InventoryRecord* inventory_record
) {
  Mdc_free(inventory_record);
}

struct D2_InventoryRecord* D2_InventoryRecord_GetAt(
    struct D2_InventoryRecord* inventory_record,
    size_t index
) {
  return (struct D2_InventoryRecord*) D2_InventoryRecord_GetConstAt(
      inventory_record,
      index
  );
}

const struct D2_InventoryRecord* D2_InventoryRecord_GetConstAt(
    const struct D2_InventoryRecord* inventory_record,
    size_t index
) {
  const struct D2_InventoryRecord_1_00* actual_inventory_record =
      (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_InventoryRecord*) &actual_inventory_record[index];
}

void D2_InventoryRecord_Copy(
    struct D2_InventoryRecord* dest,
    const struct D2_InventoryRecord* src
) {
  struct D2_InventoryRecord_1_00* actual_dest =
      (struct D2_InventoryRecord_1_00*) dest;
  const struct D2_InventoryRecord_1_00* actual_src =
      (const struct D2_InventoryRecord_1_00*) src;

  *actual_dest = *actual_src;
}

struct D2_PositionalRectangle* D2_InventoryRecord_GetPosition(
    struct D2_InventoryRecord* inventory_record
) {
  return (struct D2_PositionalRectangle*) D2_InventoryRecord_GetConstPosition(
      inventory_record
  );
}

const struct D2_PositionalRectangle*
D2_InventoryRecord_GetConstPosition(
    const struct D2_InventoryRecord* inventory_record
) {
  const struct D2_InventoryRecord_1_00* actual_inventory_record =
      (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_PositionalRectangle*)
      &actual_inventory_record->position;
}

struct D2_GridLayout* D2_InventoryRecord_GetGridLayout(
    struct D2_InventoryRecord* inventory_record
) {
  return (struct D2_GridLayout*) D2_InventoryRecord_GetConstGridLayout(
      inventory_record
  );
}

const struct D2_GridLayout* D2_InventoryRecord_GetConstGridLayout(
    const struct D2_InventoryRecord* inventory_record
) {
  const struct D2_InventoryRecord_1_00* actual_inventory_record =
      (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_GridLayout*)
      &actual_inventory_record->grid_layout;
}

struct D2_EquipmentLayout* D2_InventoryRecord_GetEquipmentSlots(
    struct D2_InventoryRecord* inventory_record
) {
  return (struct D2_EquipmentLayout*)
      D2_InventoryRecord_GetConstEquipmentSlots(
          inventory_record
      );
}

const struct D2_EquipmentLayout*
D2_InventoryRecord_GetConstEquipmentSlots(
    const struct D2_InventoryRecord* inventory_record
) {
  const struct D2_InventoryRecord_1_00* actual_inventory_record =
      (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_EquipmentLayout*)
      actual_inventory_record->equipment_slots;
}
