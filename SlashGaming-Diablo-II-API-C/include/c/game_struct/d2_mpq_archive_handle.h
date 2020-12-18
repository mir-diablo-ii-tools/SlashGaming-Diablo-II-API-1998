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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_H_

#include "d2_mpq_archive.h"

#include "../../dllexport_define.inc"

/**
 * Generic struct declaration
 */

struct D2_MpqArchiveHandle;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x108 */ struct D2_MpqArchiveHandle_1_00 {
  /* 0x0 */ struct D2_MpqArchive_1_00* mpq_archive;
  /* 0x4 */ char mpq_archive_path[260];
};

#pragma pack(pop)

/**
 * Struct typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef struct D2_MpqArchiveHandle D2_MpqArchiveHandle;
typedef struct D2_MpqArchiveHandle_1_00 D2_MpqArchiveHandle_1_00;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Returns the value of the MPQArchiveHandle's MPQ archive pointer member.
 */
DLLEXPORT struct D2_MpqArchive* D2_MpqArchiveHandle_GetMPQArchive(
    struct D2_MpqArchiveHandle* mpq_archive_handle
);

/**
 * Returns the value of the MPQArchiveHandle's MPQ archive pointer member.
 */
DLLEXPORT const struct D2_MpqArchive* D2_MpqArchiveHandle_GetConstMPQArchive(
    const struct D2_MpqArchiveHandle* mpq_archive_handle
);

/**
 * Sets the value of the MPQArchiveHandle's MPQ archive pointer member.
 */
DLLEXPORT void D2_MpqArchiveHandle_SetConstMPQArchive(
    struct D2_MpqArchiveHandle* mpq_archive_handle,
    struct D2_MpqArchive* mpq_archive
);

/**
 * Returns a pointer to the MPQArchiveHandle's MPQ archive file path member.
 */
DLLEXPORT char* D2_MpqArchiveHandle_GetMPQArchivePath(
    struct D2_MpqArchiveHandle* mpq_archive_handle
);

/**
 * Returns a pointer to the MPQArchiveHandle's MPQ archive file path member.
 */
DLLEXPORT const char* D2_MpqArchiveHandle_GetConstMPQArchivePath(
    const struct D2_MpqArchiveHandle* mpq_archive_handle
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_H_ */
