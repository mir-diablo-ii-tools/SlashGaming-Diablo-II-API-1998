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

#include "../../../include/c/game_struct/d2_grid_layout.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>

/**
 * Function definitions
 */

struct D2_GridLayout* D2_GridLayout_CreateFromLayout(
    unsigned char num_columns,
    unsigned char num_rows,
    const struct D2_PositionalRectangle* position,
    unsigned char width,
    unsigned char height
) {
  union D2_GridLayout_Wrapper wrapper;
  union D2_PositionalRectangle_View positional_rectangle_view;

  wrapper.ptr_1_00 = (struct D2_GridLayout_1_00*)
      Mdc_malloc(sizeof(*wrapper.ptr_1_00));

  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  positional_rectangle_view.ptr_1_00 =
      (const struct D2_PositionalRectangle_1_00*) position;

  wrapper.ptr_1_00->num_columns = num_columns;
  wrapper.ptr_1_00->num_rows = num_rows;
  wrapper.ptr_1_00->position = *positional_rectangle_view.ptr_1_00;
  wrapper.ptr_1_00->width = width;
  wrapper.ptr_1_00->height = height;

  return (struct D2_GridLayout*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

void D2_GridLayout_Destroy(
    struct D2_GridLayout* grid_layout
) {
  Mdc_free(grid_layout);
}

struct D2_GridLayout* D2_GridLayout_AssignMembers(
    struct D2_GridLayout* dest,
    const struct D2_GridLayout* src
) {
  union D2_GridLayout_Wrapper dest_wrapper;
  union D2_GridLayout_View src_view;

  dest_wrapper.ptr_1_00 = (struct D2_GridLayout_1_00*) dest;
  src_view.ptr_1_00 = (const struct D2_GridLayout_1_00*) src;

  *dest_wrapper.ptr_1_00 = *src_view.ptr_1_00;

  return dest;
}

struct D2_GridLayout* D2_GridLayout_Access(
    struct D2_GridLayout* grid_layout,
    size_t index
) {
  return (struct D2_GridLayout*) D2_GridLayout_AccessConst(
      grid_layout,
      index
  );
}

const struct D2_GridLayout* D2_GridLayout_AccessConst(
    const struct D2_GridLayout* grid_layout,
    size_t index
) {
  union D2_GridLayout_View view;

  view.ptr_1_00 = (struct D2_GridLayout_1_00*) grid_layout;

  return (const struct D2_GridLayout*) &view.ptr_1_00[index];
}

unsigned char D2_GridLayout_GetNumColumns(
    const struct D2_GridLayout* grid_layout
) {
  union D2_GridLayout_View view;

  view.ptr_1_00 = (const struct D2_GridLayout_1_00*) grid_layout;

  return view.ptr_1_00->num_columns;
}

void D2_GridLayout_SetNumColumns(
    struct D2_GridLayout* grid_layout,
    unsigned char num_columns
) {
  union D2_GridLayout_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_GridLayout_1_00*) grid_layout;

  wrapper.ptr_1_00->num_columns = num_columns;
}

unsigned char D2_GridLayout_GetNumRows(
    const struct D2_GridLayout* grid_layout
) {
  union D2_GridLayout_View view;

  view.ptr_1_00 = (const struct D2_GridLayout_1_00*) grid_layout;

  return view.ptr_1_00->num_rows;
}

void D2_GridLayout_SetNumRows(
    struct D2_GridLayout* grid_layout,
    unsigned char num_rows
) {
  union D2_GridLayout_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_GridLayout_1_00*) grid_layout;

  wrapper.ptr_1_00->num_rows = num_rows;
}

struct D2_PositionalRectangle* D2_GridLayout_GetPosition(
    struct D2_GridLayout* grid_layout
) {
  return (struct D2_PositionalRectangle*) D2_GridLayout_GetPositionConst(
      grid_layout
  );
}

const struct D2_PositionalRectangle* D2_GridLayout_GetPositionConst(
    const struct D2_GridLayout* grid_layout
) {
  union D2_GridLayout_View view;

  view.ptr_1_00 = (const struct D2_GridLayout_1_00*) grid_layout;

  return (const struct D2_PositionalRectangle*) &view.ptr_1_00->position;
}

unsigned char D2_GridLayout_GetWidth(
    const struct D2_GridLayout* grid_layout
) {
  union D2_GridLayout_View view;

  view.ptr_1_00 = (const struct D2_GridLayout_1_00*) grid_layout;

  return view.ptr_1_00->width;
}

void D2_GridLayout_SetWidth(
    struct D2_GridLayout* grid_layout,
    unsigned char width
) {
  union D2_GridLayout_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_GridLayout_1_00*) grid_layout;

  wrapper.ptr_1_00->width = width;
}

unsigned char D2_GridLayout_GetHeight(
    const struct D2_GridLayout* grid_layout
) {
  union D2_GridLayout_View view;

  view.ptr_1_00 = (const struct D2_GridLayout_1_00*) grid_layout;

  return view.ptr_1_00->height;
}

void D2_GridLayout_SetHeight(
    struct D2_GridLayout* grid_layout,
    unsigned char height
) {
  union D2_GridLayout_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_GridLayout_1_00*) grid_layout;

  wrapper.ptr_1_00->height = height;
}
