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

#include "../../../include/c/game_struct/d2_positional_rectangle.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>

/**
 * Function definitions
 */

struct D2_PositionalRectangle*
D2_PositionalRectangle_CreateFromPositions(
    int left,
    int right,
    int top,
    int bottom
) {
  union D2_PositionalRectangle_Wrapper wrapper;

  wrapper.ptr_1_00 = Mdc_malloc(sizeof(*wrapper.ptr_1_00));

  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  wrapper.ptr_1_00->left = left;
  wrapper.ptr_1_00->right = right;
  wrapper.ptr_1_00->top = top;
  wrapper.ptr_1_00->bottom = bottom;

  return (struct D2_PositionalRectangle*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

void D2_PositionalRectangle_Destroy(
    struct D2_PositionalRectangle* positional_rectangle
) {
  Mdc_free(positional_rectangle);
}

struct D2_PositionalRectangle* D2_PositionalRectangle_AssignMembers(
    struct D2_PositionalRectangle* dest,
    const struct D2_PositionalRectangle* src
) {
  union D2_PositionalRectangle_Wrapper dest_wrapper;
  union D2_PositionalRectangle_View src_view;

  dest_wrapper.ptr_1_00 = (struct D2_PositionalRectangle_1_00*) dest;
  src_view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*) src;

  *dest_wrapper.ptr_1_00 = *src_view.ptr_1_00;

  return dest;
}

struct D2_PositionalRectangle* D2_PositionalRectangle_Access(
    struct D2_PositionalRectangle* positional_rectangle,
    size_t index
) {
  return (struct D2_PositionalRectangle*)
      D2_PositionalRectangle_AccessConst(positional_rectangle, index);
}

const struct D2_PositionalRectangle* D2_PositionalRectangle_AccessConst(
    const struct D2_PositionalRectangle* positional_rectangle,
    size_t index
) {
  union D2_PositionalRectangle_View view;

  view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  return (const struct D2_PositionalRectangle*) &view.ptr_1_00[index];
}

int D2_PositionalRectangle_GetLeft(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  union D2_PositionalRectangle_View view;

  view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  return view.ptr_1_00->left;
}

void D2_PositionalRectangle_SetLeft(
    struct D2_PositionalRectangle* positional_rectangle,
    int left
) {
  union D2_PositionalRectangle_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  wrapper.ptr_1_00->left = left;
}

int D2_PositionalRectangle_GetRight(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  union D2_PositionalRectangle_View view;

  view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  return view.ptr_1_00->right;
}

void D2_PositionalRectangle_SetRight(
    struct D2_PositionalRectangle* positional_rectangle,
    int right
) {
  union D2_PositionalRectangle_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  wrapper.ptr_1_00->right = right;
}

int D2_PositionalRectangle_GetTop(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  union D2_PositionalRectangle_View view;

  view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  return view.ptr_1_00->top;
}

void D2_PositionalRectangle_SetTop(
    struct D2_PositionalRectangle* positional_rectangle,
    int top
) {
  union D2_PositionalRectangle_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  wrapper.ptr_1_00->top = top;
}

int D2_PositionalRectangle_GetBottom(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  union D2_PositionalRectangle_View view;

  view.ptr_1_00 = (const struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  return view.ptr_1_00->bottom;
}

void D2_PositionalRectangle_SetBottom(
    struct D2_PositionalRectangle* positional_rectangle,
    int bottom
) {
  union D2_PositionalRectangle_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_PositionalRectangle_1_00*)
      positional_rectangle;

  wrapper.ptr_1_00->bottom = bottom;
}
