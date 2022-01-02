/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "game_address_table.h"

#include <stdlib.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/std/threads.h>
#include <mdc/wchar_t/filew.h>
#include <mdc/wchar_t/wide_decoding.h>
#include "game_address_table/game_address_table_impl.h"
#include "game_library.h"

enum {
  kAddressNameWideCapacity = 512
};

static const struct Mapi_GameAddressTableEntry* game_address_table;

static wchar_t address_name_wide[kAddressNameWideCapacity];

static int Mapi_GameAddressTableEntry_CompareKeysAsVoid(
    const void* entry1,
    const void* entry2
) {
  return Mapi_GameAddressTableEntry_CompareKeys(entry1, entry2);
}

static struct Mapi_GameAddress ResolveAddress(
    const struct Mapi_GameAddressTableEntry* locator
) {
  struct Mapi_GameAddress game_address = { 0 };

  switch (locator->address_locator_type) {
    case Mapi_GameAddressLocatorType_kOffset: {
      game_address = Mapi_GameAddress_InitFromLibraryAndOffset(
          locator->library,
          locator->address_locator_value.offset
      );

      break;
    }

    case Mapi_GameAddressLocatorType_kOrdinal: {
      game_address = Mapi_GameAddress_InitFromLibraryAndOrdinal(
          locator->library,
          locator->address_locator_value.ordinal
      );

      break;
    }

    case Mapi_GameAddressLocatorType_kExportedName: {
      game_address = Mapi_GameAddress_InitFromLibraryAndExportedName(
          locator->library,
          locator->address_locator_value.exported_name
      );

      break;
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          locator->address_locator_type
      );

      goto return_bad;
    }
  }

  return game_address;

return_bad:
  return game_address;
}

static void InitGameAddressTable(void) {
  game_address_table = Mapi_GameAddressTable_Get();
}

static void InitStatic(void) {
  static once_flag game_address_table_init_flag = ONCE_FLAG_INIT;

  call_once(&game_address_table_init_flag, &InitGameAddressTable);
}

/**
 * External
 */

const struct Mapi_GameAddress Mapi_GameAddressTable_GetFromLibrary(
    enum D2_DefaultLibrary library,
    const char* address_name
) {
  struct Mapi_GameAddressTableEntry search_entry;
  const struct Mapi_GameAddressTableEntry* search_result;

  wchar_t* address_name_wide_ptr;
  size_t address_name_wide_length;

  InitStatic();

  search_entry.library = library;
  search_entry.address_name = address_name;

  search_result = bsearch(
      &search_entry,
      game_address_table,
      Mapi_GameAddressTable_Size(),
      sizeof(game_address_table[0]),
      &Mapi_GameAddressTableEntry_CompareKeysAsVoid
  );

  if (search_result == NULL) {
    address_name_wide_length = Mdc_Wide_DecodeAsciiLength(address_name);

    if (address_name_wide_length >= kAddressNameWideCapacity) {
      address_name_wide_ptr = L"**Name is longer than character limit**";
    } else {
      address_name_wide_ptr = Mdc_Wide_DecodeAscii(
          address_name_wide,
          address_name
      );
    }

    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"Could not locate address named \"%ls\" for library with value %d.",
        __FILEW__,
        __LINE__,
        address_name_wide,
        library
    );

    goto return_bad;
  }

  return ResolveAddress(search_result);

return_bad:
  return Mapi_GameAddress_kUninit;
}
