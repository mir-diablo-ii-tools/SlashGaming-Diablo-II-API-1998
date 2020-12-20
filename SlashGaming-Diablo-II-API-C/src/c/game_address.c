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

#include "../../include/c/game_address.h"

#include <windows.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include <mdc/wchar_t/wide_decoding.h>
#include "backend/game_library.h"

#define MAPI_GAME_ADDRESS_UNINIT { 0 }

static const struct Mapi_GameAddress Mapi_GameAddress_kUninit =
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
  return Mapi_GameAddress_InitFromPathAndExportedName(
      D2_DefaultLibrary_GetPathWithoutRedirect(library),
      decorated_name
  );
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromPathAndExportedName(
    const wchar_t* path,
    const char* exported_name
) {
  struct Mapi_GameAddress game_address;

  wchar_t* exported_name_wide_ptr;
  size_t exported_name_wide_length;

  const struct Mapi_GameLibrary* game_library;
  FARPROC get_proc_address_result;

  game_library = Mapi_GameLibrary_GetFromPath(path);

  get_proc_address_result = GetProcAddress(
      (HMODULE) game_library->base_address,
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
  return Mapi_GameAddress_InitFromPathAndOffset(
      D2_DefaultLibrary_GetPathWithRedirect(library),
      offset
  );
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromPathAndOffset(
    const wchar_t* path,
    ptrdiff_t offset
) {
  struct Mapi_GameAddress game_address;
  const struct Mapi_GameLibrary* game_library;

  game_library = Mapi_GameLibrary_GetFromPath(path);
  game_address.raw_address = game_library->base_address + offset;

  return game_address;
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromLibraryAndOrdinal(
    enum D2_DefaultLibrary library,
    int16_t ordinal
) {
  return Mapi_GameAddress_InitFromPathAndOrdinal(
      D2_DefaultLibrary_GetPathWithRedirect(library),
      ordinal
  );
}

struct Mapi_GameAddress
Mapi_GameAddress_InitFromPathAndOrdinal(
    const wchar_t* path,
    int16_t ordinal
) {
  struct Mapi_GameAddress game_address;
  const struct Mapi_GameLibrary* game_library;

  FARPROC get_proc_address_result;

  game_library = Mapi_GameLibrary_GetFromPath(path);

  get_proc_address_result = GetProcAddress(
      (HMODULE) game_library->base_address,
      (LPCSTR) ordinal
  );

  if (get_proc_address_result == NULL) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%s failed with error code 0x%X. Could not locate exported "
            L"ordinal: %hd",
        __FILEW__,
        __LINE__,
        L"GetProcAddress",
        GetLastError(),
        ordinal
    );

    goto return_bad;
  }

  game_address.raw_address = (intptr_t) get_proc_address_result;

  return game_address;

return_bad:
  return Mapi_GameAddress_kUninit;
}

void Mapi_GameAddress_Deinit(
    struct Mapi_GameAddress* game_address
) {
  /* Do nothing, as there is nothing to free. */
}
