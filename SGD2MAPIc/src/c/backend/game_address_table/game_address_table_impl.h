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

#ifndef SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_IMPL_H_
#define SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_IMPL_H_

#include <stddef.h>

#include <mdc/std/stdint.h>
#include <mdc/std/wchar.h>
#include "../../../include/c/game_address.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum Mapi_GameAddressLocatorType {
  Mapi_GameAddressLocatorType_kOffset,
  Mapi_GameAddressLocatorType_kOrdinal,
  Mapi_GameAddressLocatorType_kExportedName
};

union Mapi_GameAddressLocator {
  ptrdiff_t offset;
  int16_t ordinal;
  const char* exported_name;
};

struct Mapi_GameAddressTableEntry {
  enum D2_DefaultLibrary library;
  const char* address_name;
  enum Mapi_GameAddressLocatorType address_locator_type;
  union Mapi_GameAddressLocator address_locator_value;
};

const struct Mapi_GameAddressTableEntry*
Mapi_GameAddressTable_Get(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_IMPL_H_ */
