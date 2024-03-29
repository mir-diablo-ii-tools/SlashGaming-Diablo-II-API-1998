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

#include "../../include/sgd2mapi98/game_address.h"

#include <windows.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include <mdc/wchar_t/wide_decoding.h>

/**
 * External
 */

const struct Mapi_GameAddress Mapi_GameAddress_kUninit =
    MAPI_GAME_ADDRESS_UNINIT;

enum {
  kExportedNameWideCapacity = 512
};

static wchar_t exported_name_wide[kExportedNameWideCapacity] = L"";

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndExportedName(
    enum D2_DefaultLibrary library,
    const char* decorated_name
) {
  return Mapi_GameAddress_InitFromLibraryHandleAndExportedName(
      D2_DefaultLibrary_GetHandle(library, 1),
      decorated_name
  );
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryHandleAndExportedName(
    HMODULE library,
    const char* exported_name
) {
  struct Mapi_GameAddress game_address;

  wchar_t* exported_name_wide_ptr;
  size_t exported_name_wide_length;

  FARPROC get_proc_address_result;

  get_proc_address_result = GetProcAddress(
      library,
      exported_name
  );

  if (get_proc_address_result == NULL) {
    exported_name_wide_length = Mdc_Wide_DecodeAsciiLength(exported_name);

    if (exported_name_wide_length >= kExportedNameWideCapacity) {
      exported_name_wide_ptr = L"**Name is longer than character limit**";
    } else {
      exported_name_wide_ptr = Mdc_Wide_DecodeAscii(
          exported_name_wide,
          exported_name
      );
    }

    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%ls failed with error code 0x%X. Could not locate exported "
            L"name: %ls",
        __FILEW__,
        __LINE__,
        L"GetProcAddress",
        GetLastError(),
        exported_name_wide_ptr
    );

    goto return_bad;
  }

  game_address.raw_address = (intptr_t) get_proc_address_result;

  return game_address;

return_bad:
  return Mapi_GameAddress_kUninit;
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndOffset(
    enum D2_DefaultLibrary library,
    ptrdiff_t offset
) {
  return Mapi_GameAddress_InitFromLibraryHandleAndOffset(
      D2_DefaultLibrary_GetHandle(library, 1),
      offset
  );
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryHandleAndOffset(
    HMODULE library,
    ptrdiff_t offset
) {
  struct Mapi_GameAddress game_address;

  game_address.raw_address = (intptr_t)library + offset;

  return game_address;
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndOrdinal(
    enum D2_DefaultLibrary library,
    int16_t ordinal
) {
  return Mapi_GameAddress_InitFromLibraryHandleAndOrdinal(
      D2_DefaultLibrary_GetHandle(library, 1),
      ordinal
  );
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryHandleAndOrdinal(
    HMODULE library,
    int16_t ordinal
) {
  struct Mapi_GameAddress game_address;

  FARPROC get_proc_address_result;

  get_proc_address_result = GetProcAddress(
      library,
      (LPCSTR) ordinal
  );

  if (get_proc_address_result == NULL) {
    static wchar_t path[MAX_PATH];

    GetModuleFileNameW(library, path, sizeof(path));
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%ls failed with error code 0x%X. Could not locate "
            L"exported ordinal %hd from the path %ls.",
        __FILEW__,
        __LINE__,
        L"GetProcAddress",
        GetLastError(),
        ordinal,
        path
    );

    goto return_bad;
  }

  game_address.raw_address = (intptr_t) get_proc_address_result;

  return game_address;

return_bad:
  return Mapi_GameAddress_kUninit;
}

struct Mapi_GameAddress Mapi_GameAddress_InitCopy(
    const struct Mapi_GameAddress* src
) {
  struct Mapi_GameAddress game_address;

  game_address.raw_address = src->raw_address;

  return game_address;
}

struct Mapi_GameAddress Mapi_GameAddress_InitMove(
    struct Mapi_GameAddress* src
) {
  return Mapi_GameAddress_InitCopy(src);
}

void Mapi_GameAddress_Deinit(
    struct Mapi_GameAddress* game_address
) {
  /* Do nothing, as there is nothing to free. */
}

struct Mapi_GameAddress* Mapi_GameAddress_AssignCopy(
    struct Mapi_GameAddress* dest,
    const struct Mapi_GameAddress* src
) {
  if (dest == src) {
    return dest;
  }

  dest->raw_address = src->raw_address;

  return dest;
}

struct Mapi_GameAddress* Mapi_GameAddress_AssignMove(
    struct Mapi_GameAddress* dest,
    struct Mapi_GameAddress* src
) {
  if (dest == src) {
    return dest;
  }

  return Mapi_GameAddress_AssignCopy(dest, src);
}

int Mapi_GameAddress_Equal(
    const struct Mapi_GameAddress* game_address1,
    const struct Mapi_GameAddress* game_address2
) {
  if (game_address1 == game_address2) {
    return 1;
  }

  return (game_address1->raw_address == game_address2->raw_address);
}

int Mapi_GameAddress_Compare(
    const struct Mapi_GameAddress* game_address1,
    const struct Mapi_GameAddress* game_address2
) {
  if (game_address1 == game_address2) {
    return 0;
  }

  if (game_address1->raw_address < game_address2->raw_address) {
    return -1;
  } else if (game_address1->raw_address > game_address2->raw_address) {
    return 1;
  }

  return 1;
}

void Mapi_GameAddress_Swap(
    struct Mapi_GameAddress* game_address1,
    struct Mapi_GameAddress* game_address2
) {
  struct Mapi_GameAddress temp_game_address;

  if (game_address1 == game_address2) {
    return;
  }

  temp_game_address = *game_address1;
  *game_address1 = *game_address2;
  *game_address2 = temp_game_address;
}
