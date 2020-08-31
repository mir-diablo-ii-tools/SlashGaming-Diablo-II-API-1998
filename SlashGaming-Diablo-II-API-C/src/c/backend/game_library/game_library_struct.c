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

#include "game_library_struct.h"

#include <string.h>
#include <windows.h>

#include <mdc/std/threads.h>
#include "../encoding.h"
#include "../error_handling.h"

const struct MAPI_GameLibrary Mapi_GameLibrary_kUninit =
    MAPI_GAME_LIBRARY_UNINIT;

struct MAPI_GameLibrary* MAPI_GameLibrary_Init(
    struct MAPI_GameLibrary* game_library,
    const char* file_path
) {
  struct Mdc_BasicStringMetadata string_metadata;

  size_t file_path_len;
  size_t file_path_size;

  wchar_t* wide_file_path;

  /* Copy the file path. */
  Mdc_StringMetadata_InitMetadata(&string_metadata);
  Mdc_BasicString_InitFromCStr(
      &game_library->file_path,
      &string_metadata,
      file_path
  );

  /* Load the library. */
  wide_file_path = ConvertUtf8ToWide(
      NULL,
      file_path,
      __FILEW__,
      __LINE__
  );

  game_library->base_address = (intptr_t) LoadLibraryW(wide_file_path);

  if (game_library->base_address == NULL) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

free_wide_file_path:
  free(wide_file_path);

  return game_library;

return_bad:
  *game_library = Mapi_GameLibrary_kUninit;

  return NULL;
}

struct MAPI_GameLibrary* MAPI_GameLibrary_InitMove(
    struct MAPI_GameLibrary* dest,
    struct MAPI_GameLibrary* src
) {
  *dest = *src;
}

void MAPI_GameLibrary_Deinit(struct MAPI_GameLibrary* game_library) {
  BOOL is_free_library_success;

  is_free_library_success = FreeLibrary((HMODULE) game_library->base_address);
  if (!is_free_library_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"FreeLibrary",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  Mdc_BasicString_Deinit(&game_library->file_path);
}

int MAPI_GameLibrary_Compare(
    const struct MAPI_GameLibrary* game_library1,
    const struct MAPI_GameLibrary* game_library2
) {
  return Mdc_BasicString_CompareStr(
      &game_library1->file_path,
      &game_library2->file_path
  );
}
