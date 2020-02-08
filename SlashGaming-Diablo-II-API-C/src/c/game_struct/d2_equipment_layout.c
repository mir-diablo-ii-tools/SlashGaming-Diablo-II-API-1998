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

#include "../../../include/c/game_struct/d2_equipment_layout.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "../backend/error_handling.h"
#include "../../wide_macro.h"

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

/**
 * Function definitions
 */

struct D2_EquipmentLayout* D2_EquipmentLayout_CreateWithLayout(
    const struct D2_PositionalRectangle* position,
    uint_least8_t width,
    uint_least8_t height
) {
  struct D2_EquipmentLayout_1_00* actual_equipment_layout =
      (struct D2_EquipmentLayout_1_00*) malloc(
          sizeof(*actual_equipment_layout)
      );

  if (actual_equipment_layout == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  actual_equipment_layout->position =
      *(struct D2_PositionalRectangle_1_00*) position;
  actual_equipment_layout->width = width;
  actual_equipment_layout->height = height;

  return (struct D2_EquipmentLayout*) actual_equipment_layout;
}

void D2_EquipmentLayout_Destroy(
    struct D2_EquipmentLayout* equipment_layout
) {
  free(equipment_layout);
}

struct D2_PositionalRectangle* D2_EquipmentLayout_GetPosition(
    struct D2_EquipmentLayout* equipment_layout
) {
  return (struct D2_PositionalRectangle*) D2_EquipmentLayout_GetConstPosition(
      equipment_layout
  );
}

const struct D2_PositionalRectangle* D2_EquipmentLayout_GetConstPosition(
    const struct D2_EquipmentLayout* equipment_layout
) {
  const struct D2_EquipmentLayout_1_00* actual_equipment_layout =
      (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return (const struct D2_PositionalRectangle*)
      &actual_equipment_layout->position;
}

uint_least8_t D2_EquipmentLayout_GetWidth(
    const struct D2_EquipmentLayout* equipment_layout
) {
  const struct D2_EquipmentLayout_1_00* actual_equipment_layout =
      (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return actual_equipment_layout->width;
}

void D2_EquipmentLayout_SetWidth(
    struct D2_EquipmentLayout* equipment_layout,
    uint_least8_t width
) {
  struct D2_EquipmentLayout_1_00* actual_equipment_layout =
      (struct D2_EquipmentLayout_1_00*) equipment_layout;

  actual_equipment_layout->width = width;
}

uint_least8_t D2_EquipmentLayout_GetHeight(
    const struct D2_EquipmentLayout* equipment_layout
) {
  const struct D2_EquipmentLayout_1_00* actual_equipment_layout =
      (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return actual_equipment_layout->height;
}

void D2_EquipmentLayout_SetHeight(
    struct D2_EquipmentLayout* equipment_layout,
    uint_least8_t height
) {
  struct D2_EquipmentLayout_1_00* actual_equipment_layout =
      (struct D2_EquipmentLayout_1_00*) equipment_layout;

  actual_equipment_layout->height = height;
}
