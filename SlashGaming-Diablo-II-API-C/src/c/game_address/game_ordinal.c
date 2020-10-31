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

#include "../../../include/c/game_address/game_ordinal.h"

#include <windows.h>
#include <stdlib.h>

#include "../../wide_macro.h"
#include "../backend/error_handling.h"
#include "../backend/game_library.h"

static const wchar_t* const kErrorMessageFormat =
    L"The data or function with the ordinal %hd from %ls could not be "
    L"found.";

struct Mapi_GameAddress* Mapi_GameAddress_InitFromLibraryIdAndOrdinal(
    struct Mapi_GameAddress* game_address,
    enum D2_DefaultLibrary library_id,
    int16_t ordinal
) {
  return Mapi_GameAddress_InitFromLibraryPathAndOrdinal(
      game_address,
      Mapi_GetDefaultLibraryPathWithRedirect(library_id),
      ordinal
  );
}

struct Mapi_GameAddress* Mapi_GameAddress_InitFromLibraryPathAndOrdinal(
    struct Mapi_GameAddress* game_address,
    const wchar_t* library_path_cstr,
    int16_t ordinal
) {
  struct Mdc_Fs_Path library_path;
  struct Mdc_Fs_Path* init_library_path;

  const struct Mapi_GameLibrary* game_library;
  FARPROC ordinal_address;

  init_library_path = Mdc_Fs_Path_InitFromCWStr(
      &library_path,
      library_path_cstr
  );

  if (init_library_path != &library_path) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_InitFromCWStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  game_library = GetGameLibrary(&library_path);
  ordinal_address = GetProcAddress(
      (HMODULE) game_library->base_address_,
      (const char*) (0xFFFF & ordinal)
  );

  if (ordinal_address == NULL) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        kErrorMessageFormat,
        ordinal,
        library_path_cstr
    );

    goto return_bad;
  }

  game_address->raw_address = (intptr_t) ordinal_address;

  return game_address;

return_bad:
  return NULL;
}
