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

#include "../../../include/c/game_struct/d2_positional_rectangle.h"

#include <stdlib.h>

#include "../../wide_macro.h"
#include "../backend/error_handling.h"

/**
 * Function definitions
 */

struct D2_PositionalRectangle*
D2_PositionalRectangle_CreateWithPositions(
    int left,
    int right,
    int top,
    int bottom
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) malloc(
          sizeof(*actual_positional_rectangle)
      );

  if (actual_positional_rectangle == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  actual_positional_rectangle->left = left;
  actual_positional_rectangle->right = right;
  actual_positional_rectangle->top = top;
  actual_positional_rectangle->bottom = bottom;

  return (struct D2_PositionalRectangle*) actual_positional_rectangle;
}

void D2_PositionalRectangle_Destroy(
    struct D2_PositionalRectangle* positional_rectangle
) {
  free(positional_rectangle);
}

int D2_PositionalRectangle_GetLeft(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  return actual_positional_rectangle->left;
}

void D2_PositionalRectangle_SetLeft(
    struct D2_PositionalRectangle* positional_rectangle,
    int left
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  actual_positional_rectangle->left = left;
}

int D2_PositionalRectangle_GetRight(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  return actual_positional_rectangle->right;
}

void D2_PositionalRectangle_SetRight(
    struct D2_PositionalRectangle* positional_rectangle,
    int right
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  actual_positional_rectangle->right = right;
}

int D2_PositionalRectangle_GetTop(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  return actual_positional_rectangle->top;
}

void D2_PositionalRectangle_SetTop(
    struct D2_PositionalRectangle* positional_rectangle,
    int top
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  actual_positional_rectangle->top = top;
}

int D2_PositionalRectangle_GetBottom(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  return actual_positional_rectangle->bottom;
}

void D2_PositionalRectangle_SetBottom(
    struct D2_PositionalRectangle* positional_rectangle,
    int bottom
) {
  struct D2_PositionalRectangle_1_00* actual_positional_rectangle =
      (struct D2_PositionalRectangle_1_00*) positional_rectangle;

  actual_positional_rectangle->bottom = bottom;
}
