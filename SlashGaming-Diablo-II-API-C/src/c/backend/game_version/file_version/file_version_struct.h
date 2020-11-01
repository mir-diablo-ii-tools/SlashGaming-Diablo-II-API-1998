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

#ifndef SGMAPI_C_BACKEND_GAME_VERSION_FILE_VERSION_FILE_VERSION_STRUCT_H_
#define SGMAPI_C_BACKEND_GAME_VERSION_FILE_VERSION_FILE_VERSION_STRUCT_H_

#include <windows.h>

#include <mdc/object_metadata/object_metadata.h>
#include <mdc/std/stdbool.h>

struct Mapi_FileVersion {
  DWORD major_left;
  DWORD major_right;
  DWORD minor_left;
  DWORD minor_right;
};

struct Mapi_FileVersion* Mapi_FileVersion_InitDefault(
    struct Mapi_FileVersion* file_version
);

struct Mapi_FileVersion* Mapi_FileVersion_InitCopy(
    struct Mapi_FileVersion* dest,
    const struct Mapi_FileVersion* src
);

struct Mapi_FileVersion* Mapi_FileVersion_InitMove(
    struct Mapi_FileVersion* dest,
    struct Mapi_FileVersion* src
);

void Mapi_FileVersion_Deinit(
    struct Mapi_FileVersion* file_version
);

const struct Mdc_ObjectMetadata* Mapi_FileVersion_GetObjectMetadata(void);

struct Mapi_FileVersion* Mapi_FileVersion_AssignCopy(
    struct Mapi_FileVersion* dest,
    const struct Mapi_FileVersion* src
);

struct Mapi_FileVersion* Mapi_FileVersion_AssignMove(
    struct Mapi_FileVersion* dest,
    struct Mapi_FileVersion* src
);

bool Mapi_FileVersion_Equal(
    const struct Mapi_FileVersion* file_version1,
    const struct Mapi_FileVersion* file_version2
);

int Mapi_FileVersion_Compare(
    const struct Mapi_FileVersion* file_version1,
    const struct Mapi_FileVersion* file_version2
);

void Mapi_FileVersion_Swap(
    struct Mapi_FileVersion* file_version1,
    struct Mapi_FileVersion* file_version2
);

#endif /* SGMAPI_C_BACKEND_GAME_VERSION_FILE_VERSION_FILE_VERSION_STRUCT_H_ */
