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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_CEL_CONTEXT_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_CEL_CONTEXT_H_

#include <stdint.h>

#include "d2_cel_file.h"
#include "../game_undefined.h"

#include "../../dllexport_define.inc"

struct D2_CelContext;

#pragma pack(push, 1)

/* sizeof: 0x48 */ struct D2_CelContext_1_00 {
  /* 0x00 */ MAPI_UndefinedByte unknown_0x00[0x04 - 0x00];
  /* 0x04 */ struct D2_CelFile_1_00* cel_file;
  /* 0x08 */ uint32_t frame;
  /* 0x0C */ uint32_t direction;
  /* 0x10 */ MAPI_UndefinedByte unknown_0x10[0x48 - 0x10];
};

/* sizeof: 0x48 */ struct D2_CelContext_1_12A {
  /* 0x00 */ MAPI_UndefinedByte unknown_0x00[0x38 - 0x00];
  /* 0x38 */ uint32_t direction;
  /* 0x3C */ struct D2_CelFile_1_00* cel_file;
  /* 0x40 */ uint32_t frame;
  /* 0x44 */ MAPI_UndefinedByte unknown_0x44[0x48 - 0x44];
};

/* sizeof: 0x48 */ struct D2_CelContext_1_13C {
  /* 0x00 */ uint32_t frame;
  /* 0x04 */ MAPI_UndefinedByte unknown_0x04[0x34 - 0x04];
  /* 0x34 */ struct D2_CelFile_1_00* cel_file;
  /* 0x38 */ MAPI_UndefinedByte unknown_0x38[0x40 - 0x38];
  /* 0x40 */ uint32_t direction;
  /* 0x44 */ MAPI_UndefinedByte unknown_0x44[0x48 - 0x44];
};

#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT struct D2_CelContext* D2_CelContext_Create(
    struct D2_CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
);

DLLEXPORT void D2_CelContext_Destroy(struct D2_CelContext* cel_context);

DLLEXPORT struct D2_CelFile* D2_CelContext_GetCelFile(
    struct D2_CelContext* cel_context
);

DLLEXPORT const struct D2_CelFile* D2_CelContext_GetConstCelFile(
    const struct D2_CelContext* cel_context
);

DLLEXPORT void D2_CelContext_SetCelFile(
    struct D2_CelContext* cel_context,
    struct D2_CelFile* cel_file
);

DLLEXPORT unsigned int D2_CelContext_GetDirection(
    const struct D2_CelContext* cel_context
);

DLLEXPORT void D2_CelContext_SetDirection(
    struct D2_CelContext* cel_context,
    unsigned int direction
);

DLLEXPORT unsigned int D2_CelContext_GetFrame(
    const struct D2_CelContext* cel_context
);

DLLEXPORT void D2_CelContext_SetFrame(
    struct D2_CelContext* cel_context,
    unsigned int frame
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_CEL_CONTEXT_H_
