/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#ifndef SGD2MAPI_C_TYPES_D2_CEL_CONTEXT_H_
#define SGD2MAPI_C_TYPES_D2_CEL_CONTEXT_H_

#include <mdc/std/stdint.h>

#include "sgd2mapi/types/d2/cel_file.h"
#include "sgd2mapi/types/undefined.h"

/* sizeof: 0x48 */ struct D2CelContext_1_00 {
  /* offsetof: 0x00 */ SGD2Undefined unknown_0x00[0x04 - 0x00];
  /* offsetof: 0x04 */ struct D2_CelFile_1_00* cel_file;
  /* offsetof: 0x08 */ uint32_t frame_index;
  /* offsetof: 0x0C */ uint32_t direction_index;
  /* offsetof: 0x10 */ SGD2Undefined unknown_0x10[0x48 - 0x10];
};

#define D2CelContext_1_01 D2CelContext_1_00
#define D2CelContext_1_02 D2CelContext_1_01
#define D2CelContext_1_03 D2CelContext_1_02
#define D2CelContext_1_04 D2CelContext_1_03
#define D2CelContext_1_04b D2CelContext_1_04
#define D2CelContext_1_04c D2CelContext_1_04b
#define D2CelContext_1_05 D2CelContext_1_04c
#define D2CelContext_1_05b D2CelContext_1_05
#define D2CelContext_1_06 D2CelContext_1_05b
#define D2CelContext_1_06b D2CelContext_1_06
#define D2CelContext_1_07Beta D2CelContext_1_06b
#define D2CelContext_1_07 D2CelContext_1_07Beta
#define D2CelContext_1_08 D2CelContext_1_07
#define D2CelContext_1_09 D2CelContext_1_08
#define D2CelContext_1_09b D2CelContext_1_09
#define D2CelContext_1_09c D2CelContext_1_09b
#define D2CelContext_1_09d D2CelContext_1_09c
#define D2CelContext_1_10Beta D2CelContext_1_09d
#define D2CelContext_1_10sBeta D2CelContext_1_10Beta
#define D2CelContext_1_10 D2CelContext_1_10sBeta

/* sizeof: 0x48 */ struct D2CelContext_1_11 {
  /* offsetof: 0x00 */ uint32_t direction_index;
  /* offsetof: 0x04 */ SGD2Undefined unknown_0x04[0x08 - 0x04];
  /* offsetof: 0x08 */ struct D2CelFile_1_11* cel_file;
  /* offsetof: 0x0C */ SGD2Undefined unknown_0x0C[0x44 - 0x0C];
  /* offsetof: 0x44 */ uint32_t frame_index;
};

#define D2CelContext_1_11b D2CelContext_1_11

/* sizeof: 0x48 */ struct D2CelContext_1_12 {
  /* offsetof: 0x00 */ SGD2Undefined unknown_0x00[0x38 - 0x00];
  /* offsetof: 0x38 */ uint32_t direction_index;
  /* offsetof: 0x3C */ struct D2CelFile_1_12* cel_file;
  /* offsetof: 0x40 */ uint32_t frame_index;
  /* offsetof: 0x44 */ SGD2Undefined unknown_0x44[0x48 - 0x44];
};

/* sizeof: 0x48 */ struct D2CelContext_1_13a {
  /* offsetof: 0x00 */ uint32_t direction_index;
  /* offsetof: 0x04 */ SGD2Undefined unknown_0x04[0x08 - 0x04];
  /* offsetof: 0x08 */ uint32_t frame_index;
  /* offsetof: 0x0C */ SGD2Undefined unknown_0x0C[0x44 - 0x0C];
  /* offsetof: 0x44 */ struct D2CelFile_1_13a* cel_file;
};

#define D2CelContext_1_13b D2CelContext_1_13a

/* sizeof: 0x48 */ struct D2CelContext_1_13c {
  /* offsetof: 0x00 */ uint32_t frame_index;
  /* offsetof: 0x04 */ SGD2Undefined unknown_0x04[0x34 - 0x04];
  /* offsetof: 0x34 */ struct D2CelFile_1_13c* cel_file;
  /* offsetof: 0x38 */ SGD2Undefined unknown_0x38[0x40 - 0x38];
  /* offsetof: 0x40 */ uint32_t direction_index;
  /* offsetof: 0x44 */ SGD2Undefined unknown_0x44[0x48 - 0x44];
};

#define D2CelContext_1_13d D2CelContext_1_13c
#define D2CelContext_1_14a D2CelContext_1_13d
#define D2CelContext_1_14b D2CelContext_1_14a
#define D2CelContext_1_14c D2CelContext_1_14b
#define D2CelContext_1_14d D2CelContext_1_14c

#endif /* SGD2MAPI_C_TYPES_D2_CEL_CONTEXT_H_ */
