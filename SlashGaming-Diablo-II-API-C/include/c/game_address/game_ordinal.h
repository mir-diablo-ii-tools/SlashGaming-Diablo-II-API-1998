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

#ifndef SGMAPI_C_GAME_ADDRESS_GAME_ORDINAL_H_
#define SGMAPI_C_GAME_ADDRESS_GAME_ORDINAL_H_

#include <stdint.h>
#include <wchar.h>

#include "../default_game_library.h"
#include "game_address_struct.h"

#include "../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Initializes a GameAddress. The base library is specified using its ID. The
 * game address locator is specified as the address's ordinal value.
 */
DLLEXPORT struct Mapi_GameAddress*
Mapi_GameAddress_InitFromLibraryIdAndOrdinal(
    struct Mapi_GameAddress* game_address,
    enum D2_DefaultLibrary library_id,
    int16_t ordinal
);

/**
 * Initializes a GameAddress. The base library is specified using its path,
 * a UTF-8 encoded null-terminated string. The game address locator is
 * specified as the address's ordinal value.
 */
DLLEXPORT struct Mapi_GameAddress*
Mapi_GameAddress_InitFromLibraryPathAndOrdinal(
    struct Mapi_GameAddress* game_address,
    const wchar_t* library_path_cstr,
    int16_t ordinal
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGMAPI_C_GAME_ADDRESS_GAME_ORDINAL_H_
