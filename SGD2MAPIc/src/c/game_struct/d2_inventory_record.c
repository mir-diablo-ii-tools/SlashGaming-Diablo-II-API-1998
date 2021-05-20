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

#include "../../../include/c/game_struct/d2_inventory_record.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>

/**
 * View and wrapper declarations
 */

struct D2_InventoryRecord_View {
  union {
    const struct D2_InventoryRecord_1_00* v1_00;
  } ptr;
};

struct D2_InventoryRecord_Wrapper {
  union {
    struct D2_InventoryRecord_1_00* v1_00;
  } ptr;
};

/**
 * Function definitions
 */

struct D2_InventoryRecord* D2_InventoryRecord_Access(
    struct D2_InventoryRecord* inventory_record,
    size_t index
) {
  return (struct D2_InventoryRecord*) D2_InventoryRecord_AccessConst(
      inventory_record,
      index
  );
}

const struct D2_InventoryRecord* D2_InventoryRecord_AccessConst(
    const struct D2_InventoryRecord* inventory_record,
    size_t index
) {
  struct D2_InventoryRecord_View view;

  view.ptr.v1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_InventoryRecord*) &view.ptr.v1_00[index];
}

void D2_InventoryRecord_AssignMembers(
    struct D2_InventoryRecord* dest,
    const struct D2_InventoryRecord* src
) {
  struct D2_InventoryRecord_Wrapper dest_wrapper;
  struct D2_InventoryRecord_View src_view;

  dest_wrapper.ptr.v1_00 = (struct D2_InventoryRecord_1_00*) dest;
  src_view.ptr.v1_00 = (const struct D2_InventoryRecord_1_00*) src;

  *dest_wrapper.ptr.v1_00 = *src_view.ptr.v1_00;
}

struct D2_PositionalRectangle* D2_InventoryRecord_GetPosition(
    struct D2_InventoryRecord* inventory_record
) {
  return (struct D2_PositionalRectangle*)
      D2_InventoryRecord_GetPositionConst(inventory_record);
}

const struct D2_PositionalRectangle*
D2_InventoryRecord_GetPositionConst(
    const struct D2_InventoryRecord* inventory_record
) {
  struct D2_InventoryRecord_View view;

  view.ptr.v1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_PositionalRectangle*) &view.ptr.v1_00->position;
}

struct D2_GridLayout* D2_InventoryRecord_GetGridLayout(
    struct D2_InventoryRecord* inventory_record
) {
  return (struct D2_GridLayout*) D2_InventoryRecord_GetGridLayoutConst(
      inventory_record
  );
}

const struct D2_GridLayout* D2_InventoryRecord_GetGridLayoutConst(
    const struct D2_InventoryRecord* inventory_record
) {
  struct D2_InventoryRecord_View view;

  view.ptr.v1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_GridLayout*) &view.ptr.v1_00->grid_layout;
}

struct D2_EquipmentLayout* D2_InventoryRecord_GetEquipmentSlots(
    struct D2_InventoryRecord* inventory_record
) {
  return (struct D2_EquipmentLayout*)
      D2_InventoryRecord_GetEquipmentSlotsConst(inventory_record);
}

const struct D2_EquipmentLayout*
D2_InventoryRecord_GetEquipmentSlotsConst(
    const struct D2_InventoryRecord* inventory_record
) {
  struct D2_InventoryRecord_View view;

  view.ptr.v1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_EquipmentLayout*) &view.ptr.v1_00->equipment_slots;
}

/**
 * API functions
 */

struct D2_InventoryRecord_Api D2_InventoryRecord_Api_InitFromRecord(
    const struct D2_PositionalRectangle* position,
    const struct D2_GridLayout* grid_layout,
    const struct D2_EquipmentLayout* equipment_slots
) {
  struct D2_InventoryRecord_Api inventory_record;

  D2_PositionalRectangle_AssignMembers(
      (struct D2_PositionalRectangle*) &inventory_record.value.v1_00.position,
      position
  );
  D2_GridLayout_AssignMembers(
      (struct D2_GridLayout*) &inventory_record.value.v1_00.grid_layout,
      grid_layout
  );

  memcpy(
      &inventory_record.value.v1_00.equipment_slots,
      equipment_slots,
      sizeof(inventory_record.value.v1_00.equipment_slots)
  );

  return inventory_record;
}

void D2_InventoryRecord_Api_Deinit(
    struct D2_InventoryRecord_Api* inventory_record
) {
}

struct D2_InventoryRecord* D2_InventoryRecord_Api_Get(
    struct D2_InventoryRecord_Api* inventory_record
) {
  return (struct D2_InventoryRecord*) &inventory_record->value.v1_00;
}

const struct D2_InventoryRecord*
D2_InventoryRecord_Api_GetConst(
    const struct D2_InventoryRecord_Api* inventory_record
) {
  return (const struct D2_InventoryRecord*) &inventory_record->value.v1_00;
}
