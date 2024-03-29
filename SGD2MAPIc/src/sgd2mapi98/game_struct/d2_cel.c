/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../../include/sgd2mapi98/game_struct/d2_cel.h"

/**
 * View and wrapper declarations
 */

struct D2_Cel_View {
  union {
    const struct D2_Cel_1_00* v1_00;
  } ptr;
};

struct D2_Cel_Wrapper {
  union {
    struct D2_Cel_1_00* v1_00;
  } ptr;
};

/**
 * Function definitions
 */

int D2_Cel_GetHeight(const struct D2_Cel* cel) {
  struct D2_Cel_View view;

  view.ptr.v1_00 = (const struct D2_Cel_1_00*) cel;

  return view.ptr.v1_00->height;
}

void D2_Cel_SetHeight(struct D2_Cel* cel, int height) {
  struct D2_Cel_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_Cel_1_00*) cel;

  wrapper.ptr.v1_00->height = height;
}

int D2_Cel_GetOffsetX(const struct D2_Cel* cel) {
  struct D2_Cel_View view;

  view.ptr.v1_00 = (const struct D2_Cel_1_00*) cel;

  return view.ptr.v1_00->offset_x;
}

void D2_Cel_SetOffsetX(struct D2_Cel* cel, int offset_x) {
  struct D2_Cel_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_Cel_1_00*) cel;

  wrapper.ptr.v1_00->offset_x = offset_x;
}

int D2_Cel_GetOffsetY(const struct D2_Cel* cel) {
  struct D2_Cel_View view;

  view.ptr.v1_00 = (const struct D2_Cel_1_00*) cel;

  return view.ptr.v1_00->offset_y;
}

void D2_Cel_SetOffsetY(struct D2_Cel* cel, int offset_y) {
  struct D2_Cel_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_Cel_1_00*) cel;

  wrapper.ptr.v1_00->offset_y = offset_y;
}

int D2_Cel_GetWidth(const struct D2_Cel* cel) {
  struct D2_Cel_View view;

  view.ptr.v1_00 = (const struct D2_Cel_1_00*) cel;

  return view.ptr.v1_00->width;
}

void D2_Cel_SetWidth(struct D2_Cel* cel, int width) {
  struct D2_Cel_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_Cel_1_00*) cel;

  wrapper.ptr.v1_00->width = width;
}
