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

#include "../../../include/c/game_struct/d2_equipment_layout.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>

/**
 * Function definitions
 */

struct D2_EquipmentLayout* D2_EquipmentLayout_CreateFromLayout(
    const struct D2_PositionalRectangle* position,
    unsigned char width,
    unsigned char height
) {
  union D2_EquipmentLayout_Wrapper wrapper;
  union D2_PositionalRectangle_View position_view;

  wrapper.ptr_1_00 = Mdc_malloc(sizeof(*wrapper.ptr_1_00));
  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  position_view.ptr_1_00 = (struct D2_PositionalRectangle_1_00*) position;

  wrapper.ptr_1_00->position = *position_view.ptr_1_00;
  wrapper.ptr_1_00->width = width;
  wrapper.ptr_1_00->height = height;

  return (struct D2_EquipmentLayout*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

void D2_EquipmentLayout_Destroy(
    struct D2_EquipmentLayout* equipment_layout
) {
  Mdc_free(equipment_layout);
}

struct D2_EquipmentLayout* D2_EquipmentLayout_AssignMembers(
    struct D2_EquipmentLayout* dest,
    const struct D2_EquipmentLayout* src
) {
  union D2_EquipmentLayout_Wrapper dest_wrapper;
  union D2_EquipmentLayout_View src_view;

  dest_wrapper.ptr_1_00 = (struct D2_EquipmentLayout_1_00*) dest;
  src_view.ptr_1_00 = (const struct D2_EquipmentLayout_1_00*) src;

  *dest_wrapper.ptr_1_00 = *src_view.ptr_1_00;

  return dest;
}

struct D2_EquipmentLayout* D2_EquipmentLayout_Access(
    struct D2_EquipmentLayout* equipment_layout,
    size_t index
) {
  return (struct D2_EquipmentLayout*) D2_EquipmentLayout_AccessConst(
      equipment_layout,
      index
  );
}

const struct D2_EquipmentLayout* D2_EquipmentLayout_AccessConst(
    const struct D2_EquipmentLayout* equipment_layout,
    size_t index
) {
  union D2_EquipmentLayout_View view;

  view.ptr_1_00 = (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return (const struct D2_EquipmentLayout*) &view.ptr_1_00[index];
}

struct D2_PositionalRectangle* D2_EquipmentLayout_GetPosition(
    struct D2_EquipmentLayout* equipment_layout
) {
  return (struct D2_PositionalRectangle*)
      D2_EquipmentLayout_GetPositionConst(equipment_layout);
}

const struct D2_PositionalRectangle* D2_EquipmentLayout_GetPositionConst(
    const struct D2_EquipmentLayout* equipment_layout
) {
  union D2_EquipmentLayout_View view;

  view.ptr_1_00 = (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return (const struct D2_PositionalRectangle*) &view.ptr_1_00->position;
}

unsigned char D2_EquipmentLayout_GetWidth(
    const struct D2_EquipmentLayout* equipment_layout
) {
  union D2_EquipmentLayout_View view;

  view.ptr_1_00 = (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return view.ptr_1_00->width;
}

void D2_EquipmentLayout_SetWidth(
    struct D2_EquipmentLayout* equipment_layout,
    unsigned char width
) {
  union D2_EquipmentLayout_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_EquipmentLayout_1_00*) equipment_layout;

  wrapper.ptr_1_00->width = width;
}

unsigned char D2_EquipmentLayout_GetHeight(
    const struct D2_EquipmentLayout* equipment_layout
) {
  union D2_EquipmentLayout_View view;

  view.ptr_1_00 = (const struct D2_EquipmentLayout_1_00*) equipment_layout;

  return view.ptr_1_00->height;
}

void D2_EquipmentLayout_SetHeight(
    struct D2_EquipmentLayout* equipment_layout,
    unsigned char height
) {
  union D2_EquipmentLayout_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_EquipmentLayout_1_00*) equipment_layout;

  wrapper.ptr_1_00->height = height;
}
