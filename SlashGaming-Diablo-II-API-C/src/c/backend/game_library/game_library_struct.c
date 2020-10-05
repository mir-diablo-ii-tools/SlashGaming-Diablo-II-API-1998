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
#include <mdc/wchar_t/wide_decoding.h>
#include "../error_handling.h"

#define MAPI_GAME_LIBRARY_UNINIT { 0 }

static const struct Mapi_GameLibrary Mapi_GameLibrary_kUninit =
    MAPI_GAME_LIBRARY_UNINIT;

struct Mapi_GameLibrary* Mapi_GameLibrary_InitFromFilePath(
    struct Mapi_GameLibrary* game_library,
    const char* file_path
) {
  struct Mdc_BasicString* init_file_path;

  struct Mdc_BasicString wide_file_path;
  struct Mdc_BasicString* init_wide_file_path;

  size_t file_path_len;
  size_t file_path_size;

  /* Copy the file path. */
  init_file_path = Mdc_BasicString_InitFromCStr(
      &game_library->file_path,
      Mdc_CharTraitsChar_GetCharTraits(),
      file_path
  );
  if (init_file_path != &game_library->file_path) {
    goto return_bad;
  }

  /* Load the library. */
  init_wide_file_path = Mdc_Wide_DecodeUtf8(&wide_file_path, file_path);
  if (init_wide_file_path != &wide_file_path) {
    goto deinit_file_path;
  }

  game_library->base_address = (intptr_t) LoadLibraryW(
      Mdc_BasicString_Data(&wide_file_path)
  );

  if (game_library->base_address == NULL) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  Mdc_BasicString_Deinit(&wide_file_path);

  return game_library;

deinit_file_path:
  Mdc_BasicString_Deinit(&game_library->file_path);

return_bad:
  *game_library = Mapi_GameLibrary_kUninit;

  return NULL;
}

struct Mapi_GameLibrary* Mapi_GameLibrary_InitMove(
    struct Mapi_GameLibrary* dest,
    struct Mapi_GameLibrary* src
) {
  const struct Mdc_BasicString* init_file_path_move;

  init_file_path_move = Mdc_BasicString_InitMove(
      &dest->file_path,
      &src->file_path
  );

  if (init_file_path_move != &dest->file_path) {
    goto return_bad;
  }

  src->file_path = Mdc_BasicString_kUninit;

  dest->base_address = src->base_address;
  src->base_address = 0;

  return dest;

return_bad:
  *dest = Mapi_GameLibrary_kUninit;

  return NULL;
}

void Mapi_GameLibrary_Deinit(struct Mapi_GameLibrary* game_library) {
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

  *game_library = Mapi_GameLibrary_kUninit;
}

struct Mapi_GameLibrary* Mapi_GameLibrary_AssignMove(
    struct Mapi_GameLibrary* dest,
    struct Mapi_GameLibrary* src
) {
  Mdc_BasicString_AssignMove(&dest->file_path, &src->file_path);

  dest->base_address = src->base_address;
  src->base_address = 0;
}

bool Mapi_GameLibrary_Equal(
    const struct Mapi_GameLibrary* game_library1,
    const struct Mapi_GameLibrary* game_library2
) {
  return Mdc_BasicString_EqualStr(
      &game_library1->file_path,
      &game_library2->file_path
  );
}

int Mapi_GameLibrary_Compare(
    const struct Mapi_GameLibrary* game_library1,
    const struct Mapi_GameLibrary* game_library2
) {
  return Mdc_BasicString_CompareStr(
      &game_library1->file_path,
      &game_library2->file_path
  );
}

void Mapi_GameLibrary_Swap(
    struct Mapi_GameLibrary* game_library1,
    struct Mapi_GameLibrary* game_library2
) {
  struct Mapi_GameLibrary temp_game_library;
  struct Mapi_GameLibrary* init_temp_game_library;

  struct Mapi_GameLibrary* assign_game_library1;
  struct Mapi_GameLibrary* assign_game_library2;

  /* Init-move temp. */
  init_temp_game_library = Mapi_GameLibrary_InitMove(
      &temp_game_library,
      game_library1
  );

  if (init_temp_game_library != &temp_game_library) {
    goto return_bad;
  }

  /* Assign-move first game library. */
  assign_game_library1 = Mapi_GameLibrary_AssignMove(
      game_library1,
      game_library2
  );

  if (assign_game_library1 != game_library1) {
    goto deinit_temp_game_library;
  }

  /* Assign-move second game library. */
  assign_game_library2 = Mapi_GameLibrary_AssignMove(
      game_library2,
      &temp_game_library
  );

  if (assign_game_library2 != game_library2) {
    goto deassign_game_library1;
  }

  Mapi_GameLibrary_Deinit(&temp_game_library);

  return;

deassign_game_library1:
  Mapi_GameLibrary_AssignMove(game_library2, game_library1);

deinit_temp_game_library:
  Mapi_GameLibrary_AssignMove(game_library1, &temp_game_library);
  Mapi_GameLibrary_Deinit(&temp_game_library);

return_bad:
  return;
}
