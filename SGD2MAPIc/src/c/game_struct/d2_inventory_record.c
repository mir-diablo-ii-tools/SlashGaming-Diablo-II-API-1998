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
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>

/**
 * Function definitions
 */

struct D2_InventoryRecord* D2_InventoryRecord_CreateFromRecord(
    const struct D2_PositionalRectangle* position,
    const struct D2_GridLayout* grid_layout,
    const struct D2_EquipmentLayout* equipment_slots
) {
  union D2_InventoryRecord_Wrapper wrapper;

  union D2_PositionalRectangle_View position_view;
  union D2_GridLayout_View grid_layout_view;
  union D2_EquipmentLayout_View equipment_slots_view;

  wrapper.ptr_1_00 = Mdc_malloc(sizeof(*wrapper.ptr_1_00));
  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
  }

  position_view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*)
      position;
  grid_layout_view.ptr_1_00 = (const struct D2_GridLayout_1_00*) grid_layout;
  equipment_slots_view.ptr_1_00 = (const struct D2_EquipmentLayout_1_00*)
      equipment_slots;

  wrapper.ptr_1_00->position = *position_view.ptr_1_00;
  wrapper.ptr_1_00->grid_layout = *grid_layout_view.ptr_1_00;

  memcpy(
      wrapper.ptr_1_00->equipment_slots,
      equipment_slots_view.ptr_1_00,
      sizeof(wrapper.ptr_1_00->equipment_slots)
  );

  return (struct D2_InventoryRecord*) wrapper.ptr_1_00;
}

void D2_InventoryRecord_Destroy(
    struct D2_InventoryRecord* inventory_record
) {
  Mdc_free(inventory_record);
}

struct D2_InventoryRecord* D2_InventoryRecord_AssignMembers(
    struct D2_InventoryRecord* dest,
    const struct D2_InventoryRecord* src
) {
  union D2_InventoryRecord_Wrapper dest_wrapper;
  union D2_InventoryRecord_View src_view;

  dest_wrapper.ptr_1_00 = (struct D2_InventoryRecord_1_00*) dest;
  src_view.ptr_1_00 = (const struct D2_InventoryRecord_1_00*) src;

  *dest_wrapper.ptr_1_00 = *src_view.ptr_1_00;

  return dest;
}

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
  union D2_InventoryRecord_View view;

  view.ptr_1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_InventoryRecord*) &view.ptr_1_00[index];
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
  union D2_InventoryRecord_View view;

  view.ptr_1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_PositionalRectangle*) &view.ptr_1_00->position;
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
  union D2_InventoryRecord_View view;

  view.ptr_1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_GridLayout*) &view.ptr_1_00->grid_layout;
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
  union D2_InventoryRecord_View view;

  view.ptr_1_00 = (const struct D2_InventoryRecord_1_00*) inventory_record;

  return (const struct D2_EquipmentLayout*) &view.ptr_1_00->equipment_slots;
}
