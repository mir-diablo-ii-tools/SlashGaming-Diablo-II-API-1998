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

#ifndef SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_IMPL_H_
#define SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_IMPL_H_

#include <stddef.h>
#include <stdint.h>

#include "../../../include/c/game_address/game_address_struct.h"

enum LocatorType {
  LOCATOR_TYPE_OFFSET,
  LOCATOR_TYPE_ORDINAL,
  LOCATOR_TYPE_DECORATED_NAME
};

union LocatorValue {
  ptrdiff_t offset;
  int16_t ordinal;
  const char* decorated_name;
};

struct MAPI_GameAddressTableEntry {
  const char* library_path;
  const char* address_name;
  union LocatorValue locator_value;
  enum LocatorType locator_type;
};

struct MAPI_GameAddressTable {
  struct MAPI_GameAddressTableEntry** entries;
  size_t num_elements;
  size_t capacity;
};

struct MAPI_GameAddressTable* LoadGameAddressTable(void);

#endif // SGMAPI_C_BACKEND_GAME_ADDRESS_TABLE_IMPL_H_
