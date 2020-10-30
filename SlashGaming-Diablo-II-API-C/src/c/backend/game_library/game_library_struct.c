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

static intptr_t Mapi_GameLibrary_LoadBaseAddress(
    const struct Mdc_Fs_Path* file_path
) {
  HMODULE base_address;

  base_address = LoadLibraryW(Mdc_Fs_Path_CStr(file_path));

  if (base_address == NULL) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  return (intptr_t) base_address;
}

struct Mapi_GameLibrary* Mapi_GameLibrary_InitFromFilePath(
    struct Mapi_GameLibrary* game_library,
    struct Mdc_Fs_Path* file_path
) {
  struct Mdc_Fs_Path* init_file_path;

  /* Move the file path. */
  init_file_path = Mdc_Fs_Path_InitMove(
      &game_library->file_path_,
      file_path
  );

  if (init_file_path != &game_library->file_path_) {
    goto return_bad;
  }

  /* Load the library. */
  game_library->base_address_ = Mapi_GameLibrary_LoadBaseAddress(
      &game_library->file_path_
  );

  return game_library;

return_bad:
  *game_library = Mapi_GameLibrary_kUninit;

  return NULL;
}

struct Mapi_GameLibrary* Mapi_GameLibrary_InitFromFilePathCopy(
    struct Mapi_GameLibrary* game_library,
    const struct Mdc_Fs_Path* file_path
) {
  struct Mdc_Fs_Path* init_file_path;

  /* Copy the file path. */
  init_file_path = Mdc_Fs_Path_InitCopy(
      &game_library->file_path_,
      file_path
  );

  if (init_file_path != &game_library->file_path_) {
    goto return_bad;
  }

  /* Load the library. */
  game_library->base_address_ = Mapi_GameLibrary_LoadBaseAddress(
      &game_library->file_path_
  );

  return game_library;

return_bad:
  *game_library = Mapi_GameLibrary_kUninit;

  return NULL;
}

struct Mapi_GameLibrary* Mapi_GameLibrary_InitMove(
    struct Mapi_GameLibrary* dest,
    struct Mapi_GameLibrary* src
) {
  const struct Mdc_Fs_Path* init_file_path;

  init_file_path = Mdc_Fs_Path_InitMove(
      &dest->file_path_,
      &src->file_path_
  );

  if (init_file_path != &dest->file_path_) {
    goto return_bad;
  }

  dest->base_address_ = src->base_address_;
  src->base_address_ = (intptr_t) NULL;

  return dest;

return_bad:
  *dest = Mapi_GameLibrary_kUninit;

  return NULL;
}

void Mapi_GameLibrary_Deinit(struct Mapi_GameLibrary* game_library) {
  BOOL is_free_library_success;

  is_free_library_success = FreeLibrary(
      (HMODULE) game_library->base_address_
  );

  if (!is_free_library_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"FreeLibrary",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  Mdc_Fs_Path_Deinit(&game_library->file_path_);

  *game_library = Mapi_GameLibrary_kUninit;
}

struct Mapi_GameLibrary* Mapi_GameLibrary_AssignMove(
    struct Mapi_GameLibrary* dest,
    struct Mapi_GameLibrary* src
) {
  if (dest == src) {
    return dest;
  }

  Mdc_Fs_Path_AssignMove(&dest->file_path_, &src->file_path_);

  dest->base_address_ = src->base_address_;
  src->base_address_ = (intptr_t) NULL;

  return dest;
}

bool Mapi_GameLibrary_Equal(
    const struct Mapi_GameLibrary* game_library1,
    const struct Mapi_GameLibrary* game_library2
) {
  bool path_equal;
  bool module_equal;

  module_equal = Mapi_GameLibrary_GetBaseAddress(game_library1)
      == Mapi_GameLibrary_GetBaseAddress(game_library2);

  if (module_equal) {
    return true;
  }

  path_equal = Mdc_Fs_Path_EqualPath(
      Mapi_GameLibrary_GetFilePath(game_library1),
      Mapi_GameLibrary_GetFilePath(game_library2)
  );

  return path_equal;
}

int Mapi_GameLibrary_Compare(
    const struct Mapi_GameLibrary* game_library1,
    const struct Mapi_GameLibrary* game_library2
) {
  int path_compare_result;
  intptr_t module_compare_result;

  module_compare_result = Mapi_GameLibrary_GetBaseAddress(game_library1)
      - Mapi_GameLibrary_GetBaseAddress(game_library2);

  if (module_compare_result == 0) {
    return 0;
  }

  path_compare_result = Mdc_Fs_Path_ComparePath(
      Mapi_GameLibrary_GetFilePath(game_library1),
      Mapi_GameLibrary_GetFilePath(game_library2)
  );

  return path_compare_result;
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

intptr_t Mapi_GameLibrary_GetBaseAddress(
    const struct Mapi_GameLibrary* game_library
) {
  return game_library->base_address_;
}

const struct Mdc_Fs_Path* Mapi_GameLibrary_GetFilePath(
    const struct Mapi_GameLibrary* game_library
) {
  return &game_library->file_path_;
}
