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

#include "../../../include/c/game_struct/d2_grid_layout.h"

#include <stdlib.h>

#include "../../wide_macro.h"
#include "../backend/error_handling.h"

/**
 * Function definitions
 */

struct D2_GridLayout* D2_GridLayout_CreateWithLayout(
    uint_least8_t num_columns,
    uint_least8_t num_rows,
    const struct D2_PositionalRectangle* position,
    uint_least8_t width,
    uint_least8_t height
) {
  struct D2_GridLayout_1_00* actual_grid_layout =
      (struct D2_GridLayout_1_00*) malloc(sizeof(*actual_grid_layout));

  if (actual_grid_layout == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  actual_grid_layout->num_columns = num_columns;
  actual_grid_layout->num_rows = num_rows;
  actual_grid_layout->position =
      *(struct D2_PositionalRectangle_1_00*) position;
  actual_grid_layout->width = width;
  actual_grid_layout->height = height;

  return (struct D2_GridLayout*) actual_grid_layout;
}

void D2_GridLayout_Destroy(
    struct D2_GridLayout* grid_layout
) {
  free(grid_layout);
}

uint_least8_t D2_GridLayout_GetNumColumns(
    const struct D2_GridLayout* grid_layout
) {
  const struct D2_GridLayout_1_00* actual_grid_layout =
      (const struct D2_GridLayout_1_00*) grid_layout;

  return actual_grid_layout->num_columns;
}

void D2_GridLayout_SetNumColumns(
    struct D2_GridLayout* grid_layout,
    uint_least8_t num_columns
) {
  struct D2_GridLayout_1_00* actual_grid_layout =
      (struct D2_GridLayout_1_00*) grid_layout;

  actual_grid_layout->num_columns = num_columns;
}

uint_least8_t D2_GridLayout_GetNumRows(
    const struct D2_GridLayout* grid_layout
) {
  const struct D2_GridLayout_1_00* actual_grid_layout =
      (const struct D2_GridLayout_1_00*) grid_layout;

  return actual_grid_layout->num_rows;
}

void D2_GridLayout_SetNumRows(
    struct D2_GridLayout* grid_layout,
    uint_least8_t num_rows
) {
  struct D2_GridLayout_1_00* actual_grid_layout =
      (struct D2_GridLayout_1_00*) grid_layout;

  actual_grid_layout->num_rows = num_rows;
}

struct D2_PositionalRectangle* D2_GridLayout_GetPosition(
    struct D2_GridLayout* grid_layout
) {
  return (struct D2_PositionalRectangle*) D2_GridLayout_GetConstPosition(
      grid_layout
  );
}

const struct D2_PositionalRectangle* D2_GridLayout_GetConstPosition(
    const struct D2_GridLayout* grid_layout
) {
  const struct D2_GridLayout_1_00* actual_grid_layout =
      (const struct D2_GridLayout_1_00*) grid_layout;

  return (const struct D2_PositionalRectangle*) &actual_grid_layout->position;
}

uint_least8_t D2_GridLayout_GetWidth(
    const struct D2_GridLayout* grid_layout
) {
  const struct D2_GridLayout_1_00* actual_grid_layout =
      (const struct D2_GridLayout_1_00*) grid_layout;

  return actual_grid_layout->width;
}

void D2_GridLayout_SetWidth(
    struct D2_GridLayout* grid_layout,
    uint_least8_t width
) {
  struct D2_GridLayout_1_00* actual_grid_layout =
      (struct D2_GridLayout_1_00*) grid_layout;

  actual_grid_layout->width = width;
}

uint_least8_t D2_GridLayout_GetHeight(
    const struct D2_GridLayout* grid_layout
) {
  const struct D2_GridLayout_1_00* actual_grid_layout =
      (const struct D2_GridLayout_1_00*) grid_layout;

  return actual_grid_layout->height;
}

void D2_GridLayout_SetHeight(
    struct D2_GridLayout* grid_layout,
    uint_least8_t height
) {
  struct D2_GridLayout_1_00* actual_grid_layout =
      (struct D2_GridLayout_1_00*) grid_layout;

  actual_grid_layout->height = height;
}
