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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_BELT_RECORD_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_BELT_RECORD_H_

#include <stddef.h>

#include <mdc/std/assert.h>
#include <mdc/std/stdint.h>
#include "../game_undefined.h"
#include "d2_positional_rectangle.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_BeltRecord;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x108 */ struct D2_BeltRecord_1_00 {
  /* 0x00 */ struct Mapi_Undefined* unknown_0x00;
  /* 0x04 */ uint8_t num_slots;
  /* 0x05 */ uint8_t unused__to_align_0x05[3];
  /* 0x08 */ struct D2_PositionalRectangle_1_00 slot_positions[16];
};

#pragma pack(pop)

/**
 * View and wrapper declarations
 */

union D2_BeltRecord_View {
  const struct D2_BeltRecord_1_00* ptr_1_00;
};

union D2_BeltRecord_Wrapper {
  struct D2_BeltRecord_1_00* ptr_1_00;
};

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_BeltRecord D2_BeltRecord;
typedef struct D2_BeltRecord_1_00 D2_BeltRecord_1_00;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Creates a generic BeltRecord with the specified number of slots and slot
 * positions.
 */
DLLEXPORT struct D2_BeltRecord* D2_BeltRecord_CreateFromRecord(
    struct Mapi_Undefined* reserved_00__set_to_nullptr,
    unsigned char num_slots,
    const struct D2_PositionalRectangle* slot_positions
);

/**
 * Destroys the BeltRecord, freeing up resources.
 */
DLLEXPORT void D2_BeltRecord_Destroy(
    struct D2_BeltRecord* belt_record
);

/**
 * Assigns each BeltRecord member the values of the source BeltRecord.
 * This is a shallow copy operation.
 */
DLLEXPORT void D2_BeltRecord_AssignMembers(
    struct D2_BeltRecord* dest,
    const struct D2_BeltRecord* src
);

/**
 * Returns the element of the BeltRecord array at the specified
 * index.
 */
DLLEXPORT struct D2_BeltRecord* D2_BeltRecord_Access(
    struct D2_BeltRecord* belt_record,
    size_t index
);

/**
 * Returns the element of the BeltRecord array at the specified
 * index.
 */
DLLEXPORT const struct D2_BeltRecord* D2_BeltRecord_AccessConst(
    const struct D2_BeltRecord* belt_record,
    size_t index
);

/**
 * Returns the value of the BeltRecord's number of slot positions member.
 */
DLLEXPORT unsigned char D2_BeltRecord_GetNumSlots(
    const struct D2_BeltRecord* belt_record
);

/**
 * Sets the value of the BeltRecord's number of slot positions member.
 */
DLLEXPORT void D2_BeltRecord_SetNumSlots(
    struct D2_BeltRecord* belt_record,
    unsigned char num_slots
);

/**
 * Returns a pointer to the BeltRecord's slot positions array member.
 */
DLLEXPORT struct D2_PositionalRectangle* D2_BeltRecord_GetSlotPositions(
    struct D2_BeltRecord* belt_record
);

/**
 * Returns a pointer to the BeltRecord's slot positions array member.
 */
DLLEXPORT const struct D2_PositionalRectangle*
D2_BeltRecord_GetSlotPositionsConst(
    const struct D2_BeltRecord* belt_record
);

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

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_STRUCT_D2_BELT_RECORD_H_ */
