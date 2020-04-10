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

#ifndef SGD2MAPI_C_GAME_FUNCTION_STORM_STORM_S_FILE_OPEN_ARCHIVE_H_
#define SGD2MAPI_C_GAME_FUNCTION_STORM_STORM_S_FILE_OPEN_ARCHIVE_H_

#include <stdbool.h>
#include <stdint.h>

#include "../../game_struct/d2_mpq_archive.h"
#include "../../game_bool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT bool D2_Storm_SFileOpenArchive(
    const char* mpq_archive_path,
    int priority,
    unsigned int flags,
    struct D2_MpqArchive** mpq_archive_ptr_out
);

DLLEXPORT mapi_bool32 D2_Storm_SFileOpenArchive_1_00(
    const char* mpq_archive_path,
    int32_t priority,
    uint32_t flags,
    struct D2_MpqArchive_1_00** mpq_archive_ptr_out
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_FUNCTION_STORM_STORM_S_FILE_OPEN_ARCHIVE_H_
