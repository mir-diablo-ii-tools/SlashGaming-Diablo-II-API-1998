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

#include "../../../include/c/game_struct/d2_cel_file.h"

/**
 * Function definitions
 */

unsigned int D2_CelFile_GetVersion(const struct D2_CelFile* cel_file) {
  union D2_CelFile_View view;

  view.ptr_1_00 = (const struct D2_CelFile_1_00*) cel_file;

  return view.ptr_1_00->version;
}

void D2_CelFile_SetVersion(
    struct D2_CelFile* cel_file,
    unsigned int version
) {
  union D2_CelFile_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

  wrapper.ptr_1_00->version = version;
}

unsigned int D2_CelFile_GetNumDirections(const struct D2_CelFile* cel_file) {
  union D2_CelFile_View view;

  view.ptr_1_00 = (const struct D2_CelFile_1_00*) cel_file;

  return view.ptr_1_00->num_directions;
}

void D2_CelFile_SetNumDirections(
    struct D2_CelFile* cel_file,
    unsigned int num_directions
) {
  union D2_CelFile_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

  wrapper.ptr_1_00->num_directions = num_directions;
}

unsigned int D2_CelFile_GetNumFrames(const struct D2_CelFile* cel_file) {
  union D2_CelFile_View view;

  view.ptr_1_00 = (const struct D2_CelFile_1_00*) cel_file;

  return view.ptr_1_00->num_frames;
}

void D2_CelFile_SetNumFrames(
    struct D2_CelFile* cel_file,
    unsigned int num_frames
) {
  union D2_CelFile_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

  wrapper.ptr_1_00->num_frames = num_frames;
}
