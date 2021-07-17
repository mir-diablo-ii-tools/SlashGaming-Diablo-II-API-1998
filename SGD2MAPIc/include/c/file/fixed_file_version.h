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

#ifndef SGMAPI_C_FILE_FIXED_FILE_VERSION_H_
#define SGMAPI_C_FILE_FIXED_FILE_VERSION_H_

#include <limits.h>
#include <windows.h>

#include <mdc/std/stdint.h>

#include "../../dllexport_define.inc"

#define MAPI_FIXED_FILE_VERSION_MERGE_VERSION_TO_VALUE( \
    major_high, \
    major_low, \
    minor_high, \
    minor_low \
) \
    (((uint_least64_t)major_high & 0xFFFF) << (sizeof(WORD) * CHAR_BIT * 3)) \
        | (((uint_least64_t)major_low & 0xFFFF) \
            << (sizeof(WORD) * CHAR_BIT * 2)) \
        | (((uint_least64_t)minor_high & 0xFFFF) \
            << (sizeof(WORD) * CHAR_BIT)) \
        | ((uint_least64_t)minor_low & 0xFFFF)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mapi_FixedFileVersion {
  WORD major_high;
  WORD major_low;
  WORD minor_high;
  WORD minor_low;
};

DLLEXPORT struct Mapi_FixedFileVersion
Mapi_FixedFileVersion_InitFromVersion(
    WORD major_high,
    WORD major_low,
    WORD minor_high,
    WORD minor_low
);

DLLEXPORT void Mapi_FixedFileVersion_Deinit(
    struct Mapi_FixedFileVersion* fixed_file_version
);

DLLEXPORT uint_least64_t Mapi_FixedFileVersion_ToValue(
    const struct Mapi_FixedFileVersion* fixed_file_version
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGMAPI_C_FILE_FIXED_FILE_VERSION_H_ */
