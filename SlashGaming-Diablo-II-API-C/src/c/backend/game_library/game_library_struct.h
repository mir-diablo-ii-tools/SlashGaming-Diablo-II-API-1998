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

#ifndef SGMAPI_C_BACKEND_GAME_LIBRARY_GAME_LIBRARY_STRUCT_H_
#define SGMAPI_C_BACKEND_GAME_LIBRARY_GAME_LIBRARY_STRUCT_H_

#include <stdint.h>

#include <mdc/filesystem/filesystem.h>
#include <mdc/object_metadata/object_metadata.h>

struct Mapi_GameLibrary {
  struct Mdc_Fs_Path file_path_;
  intptr_t base_address_;
};

/**
 * Initializes a GameLibrary, value copying the specified file path,
 * loading the module, and storing the module handle.
 */
struct Mapi_GameLibrary* Mapi_GameLibrary_InitFromFilePath(
    struct Mapi_GameLibrary* game_library,
    struct Mdc_Fs_Path* file_path
);

/**
 * Initializes a GameLibrary, value copying the specified file path,
 * loading the module, and storing the module handle.
 */
struct Mapi_GameLibrary* Mapi_GameLibrary_InitFromFilePathCopy(
    struct Mapi_GameLibrary* game_library,
    const struct Mdc_Fs_Path* file_path
);

struct Mapi_GameLibrary* Mapi_GameLibrary_InitMove(
    struct Mapi_GameLibrary* dest,
    struct Mapi_GameLibrary* src
);

void Mapi_GameLibrary_Deinit(struct Mapi_GameLibrary* game_library);

const struct Mdc_ObjectMetadata*
Mapi_GameLibrary_GetGlobalObjectMetadata(void);

struct Mapi_GameLibrary* Mapi_GameLibrary_AssignMove(
    struct Mapi_GameLibrary* dest,
    struct Mapi_GameLibrary* src
);

bool Mapi_GameLibrary_Equal(
    const struct Mapi_GameLibrary* game_library1,
    const struct Mapi_GameLibrary* game_library2
);

int Mapi_GameLibrary_Compare(
    const struct Mapi_GameLibrary* game_library1,
    const struct Mapi_GameLibrary* game_library2
);

void Mapi_GameLibrary_Swap(
    struct Mapi_GameLibrary* game_library1,
    struct Mapi_GameLibrary* game_library2
);

intptr_t Mapi_GameLibrary_GetBaseAddress(
    const struct Mapi_GameLibrary* game_library
);

const struct Mdc_Fs_Path* Mapi_GameLibrary_GetFilePath(
    const struct Mapi_GameLibrary* game_library
);

#endif /* SGMAPI_C_BACKEND_GAME_LIBRARY_GAME_LIBRARY_STRUCT_H_ */
