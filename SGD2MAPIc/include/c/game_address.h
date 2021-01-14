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

#ifndef SGMAPI_C_GAME_ADDRESS_H_
#define SGMAPI_C_GAME_ADDRESS_H_

#include <stddef.h>

#include <mdc/std/stdint.h>
#include "default_game_library.h"

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mapi_GameAddress {
  intptr_t raw_address;
};

/**
 * Initializes a GameAddress. The game address locator is specified
 * as a string encoded in 7-bit ASCII, which represents the address's
 * exported name.
 */
DLLEXPORT struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndExportedName(
    enum D2_DefaultLibrary library,
    const char* decorated_name
);

/**
 * Initializes a GameAddress. The game address locator is specified
 * as a null-terminated string encoded in 7-bit ASCII, which
 * represents the address's exported name.
 */
DLLEXPORT struct Mapi_GameAddress
Mapi_GameAddress_InitFromPathAndExportedName(
    const wchar_t* path,
    const char* decorated_name
);

/**
 * Initializes a GameAddress. The game address locator is specified
 * as the offset from the module base address to the target address.
 */
DLLEXPORT struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndOffset(
    enum D2_DefaultLibrary library,
    ptrdiff_t offset
);

/**
 * Initializes a GameAddress. The game address locator is specified
 * as the offset from the module base address to the target address.
 */
DLLEXPORT struct Mapi_GameAddress
Mapi_GameAddress_InitFromPathAndOffset(
    const wchar_t* path,
    ptrdiff_t offset
);

/**
 * Initializes a GameAddress. The game address locator is specified
 * as the address's ordinal value.
 */
DLLEXPORT struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndOrdinal(
    enum D2_DefaultLibrary library,
    int16_t ordinal
);

/**
 * Initializes a GameAddress. The game address locator is specified
 * as the address's ordinal value.
 */
DLLEXPORT struct Mapi_GameAddress
Mapi_GameAddress_InitFromPathAndOrdinal(
    const wchar_t* path,
    int16_t ordinal
);

DLLEXPORT struct Mapi_GameAddress Mapi_GameAddress_InitCopy(
    const struct Mapi_GameAddress* src
);

DLLEXPORT struct Mapi_GameAddress Mapi_GameAddress_InitMove(
    struct Mapi_GameAddress* src
);

DLLEXPORT void Mapi_GameAddress_Deinit(
    struct Mapi_GameAddress* game_address
);

DLLEXPORT struct Mapi_GameAddress* Mapi_GameAddress_AssignCopy(
    struct Mapi_GameAddress* dest,
    const struct Mapi_GameAddress* src
);

DLLEXPORT struct Mapi_GameAddress* Mapi_GameAddress_AssignMove(
    struct Mapi_GameAddress* dest,
    struct Mapi_GameAddress* src
);

DLLEXPORT void Mapi_GameAddress_Swap(
    struct Mapi_GameAddress* game_address1,
    struct Mapi_GameAddress* game_address2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../dllexport_undefine.inc"
#endif /* SGMAPI_C_GAME_ADDRESS_H_ */
