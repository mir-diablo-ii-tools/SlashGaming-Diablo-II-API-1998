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

#ifndef SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_LOCATOR_H_
#define SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_LOCATOR_H_

#include <stddef.h>

#include <mdc/filesystem/filesystem.h>
#include <mdc/object_metadata/object_metadata.h>
#include <mdc/std/stdint.h>
#include <mdc/string/basic_string.h>
#include "../../../../include/c/game_address.h"

enum Mapi_Impl_LocatorType {
  Mapi_Impl_LocatorType_kOffset,
  Mapi_Impl_LocatorType_kOrdinal,
  Mapi_Impl_LocatorType_kDecoratedName,
};

union Mapi_Impl_LocatorValue {
  ptrdiff_t offset;
  int16_t ordinal;
  struct Mdc_BasicString decorated_name;
};

union Mapi_Impl_LocatorValueLiteral {
  ptrdiff_t offset;
  int16_t ordinal;
  const char* decorated_name;
};

union Mapi_Impl_LocatorValue* Mapi_Impl_LocatorValue_InitFromLiteral(
    union Mapi_Impl_LocatorValue* locator_value,
    enum Mapi_Impl_LocatorType locator_type,
    union Mapi_Impl_LocatorValueLiteral* literal_locator_value
);

struct Mapi_Impl_GameAddressLocator {
  struct Mdc_Fs_Path library_path;
  enum Mapi_Impl_LocatorType locator_type;
  union Mapi_Impl_LocatorValue locator_value;
};

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitFromLocatorType(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    enum Mapi_Impl_LocatorType locator_type,
    union Mapi_Impl_LocatorValue locator_value
);

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitDecoratedNameLocator(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    const char* decorated_name_cstr
);

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitOffsetLocator(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    ptrdiff_t offset
);

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitOrdinalLocator(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    int16_t ordinal
);

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_InitCopy(
    struct Mapi_Impl_GameAddressLocator* dest,
    const struct Mapi_Impl_GameAddressLocator* src
);

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_InitMove(
    struct Mapi_Impl_GameAddressLocator* dest,
    struct Mapi_Impl_GameAddressLocator* src
);

void Mapi_Impl_GameAddressLocator_Deinit(
    struct Mapi_Impl_GameAddressLocator* game_address_locator
);

const struct Mdc_ObjectMetadata*
Mapi_Impl_GameAddressLocator_GetObjectMetadata(void);

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_AssignCopy(
    struct Mapi_Impl_GameAddressLocator* dest,
    const struct Mapi_Impl_GameAddressLocator* src
);

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_AssignMove(
    struct Mapi_Impl_GameAddressLocator* dest,
    struct Mapi_Impl_GameAddressLocator* src
);

bool Mapi_Impl_GameAddressLocator_Equal(
    const struct Mapi_Impl_GameAddressLocator* game_address_locator1,
    const struct Mapi_Impl_GameAddressLocator* game_address_locator2
);

int Mapi_Impl_GameAddressLocator_Compare(
    const struct Mapi_Impl_GameAddressLocator* game_address_locator1,
    const struct Mapi_Impl_GameAddressLocator* game_address_locator2
);

struct Mapi_GameAddress* Mapi_Impl_GameAddressLocator_LocateGameAddress(
    struct Mapi_GameAddress* game_address,
    const struct Mapi_Impl_GameAddressLocator* game_address_locator
);

void Mapi_Impl_GameAddressLocator_Swap(
    struct Mapi_Impl_GameAddressLocator* game_address_locator1,
    struct Mapi_Impl_GameAddressLocator* game_address_locator2
);

#endif /* SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_LOCATOR_H_ */
