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

#include "../../../include/c/game_struct/d2_belt_record.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "../backend/error_handling.h"
#include "../../wide_macro.h"

/**
 * Static assertions (1.00)
 */

static_assert(
    sizeof(struct D2_BeltRecord_1_00) == 0x108,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_BeltRecord_1_00, num_slots) == 0x04,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_BeltRecord_1_00, slot_positions) == 0x08,
    "Incorrect member alignment."
);

/**
 * Function definitions
 */

struct D2_BeltRecord* D2_BeltRecord_CreateWithRecord(
    struct MAPI_Undefined* reserved_00__set_to_nullptr,
    uint_least8_t num_slots,
    const struct D2_PositionalRectangle* slot_positions
) {
  struct D2_BeltRecord_1_00* actual_belt_record =
      (struct D2_BeltRecord_1_00*) malloc(
          sizeof(*actual_belt_record)
      );

  actual_belt_record->unknown_0x00 = reserved_00__set_to_nullptr;
  actual_belt_record->num_slots = num_slots;

  memcpy(
      actual_belt_record->slot_positions,
      slot_positions,
      sizeof(actual_belt_record->slot_positions)
  );

  return (struct D2_BeltRecord*) actual_belt_record;
}

void D2_BeltRecord_Destroy(
    struct D2_BeltRecord* belt_record
) {
  free(belt_record);
}

struct D2_BeltRecord* D2_BeltRecord_GetAt(
    struct D2_BeltRecord* belt_record,
    size_t index
) {
  return (struct D2_BeltRecord*) D2_BeltRecord_GetConstAt(
      belt_record,
      index
  );
}

const struct D2_BeltRecord* D2_BeltRecord_GetConstAt(
    const struct D2_BeltRecord* belt_record,
    size_t index
) {
  const struct D2_BeltRecord_1_00* actual_belt_record =
      (const struct D2_BeltRecord_1_00*) belt_record;

  return (const struct D2_BeltRecord*) &actual_belt_record[index];
}

void D2_BeltRecord_Copy(
    struct D2_BeltRecord* dest,
    const struct D2_BeltRecord* src
) {
  struct D2_BeltRecord_1_00* actual_dest =
      (struct D2_BeltRecord_1_00*) dest;
  const struct D2_BeltRecord_1_00* actual_src =
      (const struct D2_BeltRecord_1_00*) src;

  *actual_dest = *actual_src;
}

uint_least8_t D2_BeltRecord_GetNumSlots(
    const struct D2_BeltRecord* belt_record
) {
  const struct D2_BeltRecord_1_00* actual_belt_record =
      (const struct D2_BeltRecord_1_00*) belt_record;

  return actual_belt_record->num_slots;
}

struct D2_PositionalRectangle* D2_BeltRecord_GetSlotPositions(
    struct D2_BeltRecord* belt_record
) {
  return (struct D2_PositionalRectangle*)
      D2_BeltRecord_GetConstSlotPositions(belt_record);
}

const struct D2_PositionalRectangle*
D2_BeltRecord_GetConstSlotPositions(
    const struct D2_BeltRecord* belt_record
) {
  const struct D2_BeltRecord_1_00* actual_belt_record =
      (const struct D2_BeltRecord_1_00*) belt_record;

  return (const struct D2_PositionalRectangle*)
      actual_belt_record->slot_positions;
}
