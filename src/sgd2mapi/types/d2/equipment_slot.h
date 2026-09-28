/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#ifndef SGD2MAPI_C_TYPES_D2_EQUIPMENT_SLOT_H_
#define SGD2MAPI_C_TYPES_D2_EQUIPMENT_SLOT_H_

#include <mdc/std/stdint.h>

#include "sgd2mapi/types/d2/inventory_rect.h"

/**
 * Diablo II Manual:
 * "If you pick up an item that can be equipped, and you have the appropriate
 *  **equipment slot** free on your character, the item is auto-equipped. For
 *  example, if your character does not have a helmet, and you pick one up,
 *  your character automatically wears the helmet."
 *
 * "The Barbarian character may also equip a secondary weapon in the Left Arm
 *  **slot**."
 *
 * "...equip the potion in an Arm **slot** in your character’s Inventory."
 */

/* Confirmed members and size from 1.00 to 1.14d. */

/* sizeof: 0x14 */ struct D2EquipmentSlot_1_00 {
  /**
   * The bounding area of the equipemnt slot.
   */
  /* offsetof: 0x00 */ struct D2InventoryRect_1_00 position;

  /*
   * The width of the equipment slot, which should be equal to
   * `position.right - position.left`.
   */
  /* offsetof: 0x10 */ uint8_t width;

  /*
   * The height of the equipment slot, which should be equal to
   * `position.bottom - position.top`.
   */
  /* offsetof: 0x11 */ uint8_t height;
};

#define D2EquipmentSlot_1_01 D2EquipmentSlot_1_00
#define D2EquipmentSlot_1_02 D2EquipmentSlot_1_01
#define D2EquipmentSlot_1_03 D2EquipmentSlot_1_02
#define D2EquipmentSlot_1_04 D2EquipmentSlot_1_03
#define D2EquipmentSlot_1_04b D2EquipmentSlot_1_04
#define D2EquipmentSlot_1_04c D2EquipmentSlot_1_04b
#define D2EquipmentSlot_1_05 D2EquipmentSlot_1_04c
#define D2EquipmentSlot_1_05b D2EquipmentSlot_1_05
#define D2EquipmentSlot_1_06 D2EquipmentSlot_1_05b
#define D2EquipmentSlot_1_06b D2EquipmentSlot_1_06
#define D2EquipmentSlot_1_07Beta D2EquipmentSlot_1_06b
#define D2EquipmentSlot_1_07 D2EquipmentSlot_1_07Beta
#define D2EquipmentSlot_1_08 D2EquipmentSlot_1_07
#define D2EquipmentSlot_1_09 D2EquipmentSlot_1_08
#define D2EquipmentSlot_1_09b D2EquipmentSlot_1_09
#define D2EquipmentSlot_1_09c D2EquipmentSlot_1_09b
#define D2EquipmentSlot_1_09d D2EquipmentSlot_1_09c
#define D2EquipmentSlot_1_10Beta D2EquipmentSlot_1_09d
#define D2EquipmentSlot_1_10sBeta D2EquipmentSlot_1_10Beta
#define D2EquipmentSlot_1_10 D2EquipmentSlot_1_10sBeta
#define D2EquipmentSlot_1_11 D2EquipmentSlot_1_10
#define D2EquipmentSlot_1_11b D2EquipmentSlot_1_11
#define D2EquipmentSlot_1_12 D2EquipmentSlot_1_11b
#define D2EquipmentSlot_1_13a D2EquipmentSlot_1_12
#define D2EquipmentSlot_1_13b D2EquipmentSlot_1_13a
#define D2EquipmentSlot_1_13c D2EquipmentSlot_1_13b
#define D2EquipmentSlot_1_13d D2EquipmentSlot_1_13c
#define D2EquipmentSlot_1_14a D2EquipmentSlot_1_13d
#define D2EquipmentSlot_1_14b D2EquipmentSlot_1_14a
#define D2EquipmentSlot_1_14c D2EquipmentSlot_1_14b
#define D2EquipmentSlot_1_14d D2EquipmentSlot_1_14c

#endif /* SGD2MAPI_C_TYPES_D2_EQUIPMENT_SLOT_H_ */
