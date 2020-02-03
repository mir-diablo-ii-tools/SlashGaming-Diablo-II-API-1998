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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_CEL_FILE_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_CEL_FILE_H_

#include <stdint.h>

#include "../game_undefined.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_CelFile;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x18 + sizeof(cels) */ struct D2_CelFile_1_00 {
  /* 0x00 */ uint32_t version;
  /* 0x04 */ MAPI_UndefinedByte unknown_0x04[0x10 - 0x04];
  /* 0x10 */ uint32_t num_directions;
  /* 0x14 */ uint32_t num_frames;

  // This field gives the struct variable length.
  /* 0x18 */ MAPI_UndefinedByte cels[];
};

#pragma pack(pop)

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_CelFile D2_CelFile;
typedef struct D2_CelFile_1_00 D2_CelFile_1_00;

#endif // SGD2MAPI_ENABLE_TYPEDEFS

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Returns the value of the CelFile's file format version member.
 */
DLLEXPORT unsigned int D2_CelFile_GetVersion(
    const struct D2_CelFile* cel_file
);

/**
 * Sets the value of the CelFile's file format version member.
 */
DLLEXPORT void D2_CelFile_SetVersion(
    struct D2_CelFile* cel_file,
    unsigned int version
);

/**
 * Returns the value of the CelFile's number of directions member.
 */
DLLEXPORT unsigned int D2_CelFile_GetNumDirections(
    const struct D2_CelFile* cel_file
);

/**
 * Sets the value of the CelFile's number of directions member.
 */
DLLEXPORT void D2_CelFile_SetNumDirections(
    struct D2_CelFile* cel_file,
    unsigned int num_directions
);

/**
 * Returns the value of the CelFile's number of frames member.
 */
DLLEXPORT unsigned int D2_CelFile_GetNumFrames(
    const struct D2_CelFile* cel_file
);

/**
 * Sets the value of the CelFile's number of frames member.
 */
DLLEXPORT void D2_CelFile_SetNumFrames(
    struct D2_CelFile* cel_file,
    unsigned int num_frames
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_CEL_FILE_H_
