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

#include "../../../include/c/game_struct/d2_belt_record.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>

/**
 * Function definitions
 */

struct D2_BeltRecord* D2_BeltRecord_CreateFromRecord(
    struct Mapi_Undefined* reserved_00__set_to_nullptr,
    unsigned char num_slots,
    const struct D2_PositionalRectangle* slot_positions
) {
  struct D2_BeltRecord_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_BeltRecord_1_00*) Mdc_malloc(
      sizeof(*wrapper.ptr.v1_00)
  );

  if (wrapper.ptr.v1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  wrapper.ptr.v1_00->unknown_0x00 = reserved_00__set_to_nullptr;
  wrapper.ptr.v1_00->num_slots = num_slots;

  memcpy(
      wrapper.ptr.v1_00->slot_positions,
      slot_positions,
      sizeof(wrapper.ptr.v1_00->slot_positions)
  );

  return (struct D2_BeltRecord*) wrapper.ptr.v1_00;

return_bad:
  return NULL;
}

void D2_BeltRecord_Destroy(
    struct D2_BeltRecord* belt_record
) {
  Mdc_free(belt_record);
}

struct D2_BeltRecord* D2_BeltRecord_Access(
    struct D2_BeltRecord* belt_record,
    size_t index
) {
  return (struct D2_BeltRecord*) D2_BeltRecord_AccessConst(
      belt_record,
      index
  );
}

const struct D2_BeltRecord* D2_BeltRecord_AccessConst(
    const struct D2_BeltRecord* belt_record,
    size_t index
) {
  struct D2_BeltRecord_View view;

  view.ptr.v1_00 = (const struct D2_BeltRecord_1_00*) belt_record;

  return (const struct D2_BeltRecord*) &view.ptr.v1_00[index];
}

void D2_BeltRecord_AssignMembers(
    struct D2_BeltRecord* dest,
    const struct D2_BeltRecord* src
) {
  struct D2_BeltRecord_Wrapper dest_wrapper;
  struct D2_BeltRecord_View src_view;

  dest_wrapper.ptr.v1_00 = (struct D2_BeltRecord_1_00*) dest;
  src_view.ptr.v1_00 = (const struct D2_BeltRecord_1_00*) src;

  *dest_wrapper.ptr.v1_00 = *src_view.ptr.v1_00;
}

unsigned char D2_BeltRecord_GetNumSlots(
    const struct D2_BeltRecord* belt_record
) {
  struct D2_BeltRecord_View view;

  view.ptr.v1_00 = (const struct D2_BeltRecord_1_00*) belt_record;

  return view.ptr.v1_00->num_slots;
}

void D2_BeltRecord_SetNumSlots(
    struct D2_BeltRecord* belt_record,
    unsigned char num_slots
) {
  struct D2_BeltRecord_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_BeltRecord_1_00*) belt_record;

  wrapper.ptr.v1_00->num_slots = num_slots;
}

struct D2_PositionalRectangle* D2_BeltRecord_GetSlotPositions(
    struct D2_BeltRecord* belt_record
) {
  return (struct D2_PositionalRectangle*)
      D2_BeltRecord_GetSlotPositionsConst(belt_record);
}

const struct D2_PositionalRectangle*
D2_BeltRecord_GetSlotPositionsConst(
    const struct D2_BeltRecord* belt_record
) {
  struct D2_BeltRecord_View view;

  view.ptr.v1_00 = (const struct D2_BeltRecord_1_00*) belt_record;

  return (const struct D2_PositionalRectangle*)
      view.ptr.v1_00->slot_positions;
}
