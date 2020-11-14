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

#include "../../../../include/c/game_function/storm/storm_s_file_open_archive.h"

#include <mdc/std/threads.h>
#include "../../../../include/c/game_version.h"
#include "../../../asm_x86_macro.h"
#include "../../../wide_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_address_table.h"
#include "../../backend/game_function/stdcall_function.h"

static struct Mapi_GameAddress game_address;
static once_flag game_address_init_flag = ONCE_FLAG_INIT;

static void InitGameAddress(void) {
  struct Mapi_GameAddress* init_game_address;

  init_game_address = Mapi_Impl_LoadGameAddressByLibraryId(
      &game_address,
      LIBRARY_STORM,
      "SFileOpenArchive"
  );

  if (init_game_address != &game_address) {
    ExitOnMapiFunctionFailure(
        L"Mapi_Impl_LoadGameAddressByLibraryId",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  return;

return_bad:
  return;
}

static void InitStatic(void) {
  call_once(&game_address_init_flag, &InitGameAddress);
}

bool D2_Storm_SFileOpenArchive(
    const char* mpq_archive_path,
    int priority,
    unsigned int flags,
    struct D2_MpqArchive** mpq_archive_ptr_out
) {
  InitStatic();

  return (bool) D2_Storm_SFileOpenArchive_1_00(
      mpq_archive_path,
      priority,
      flags,
      (struct D2_MpqArchive_1_00**) mpq_archive_ptr_out
  );
}

mapi_bool32 D2_Storm_SFileOpenArchive_1_00(
    const char* mpq_archive_path,
    int32_t priority,
    uint32_t flags,
    struct D2_MpqArchive_1_00** mpq_archive_ptr_out
) {
  InitStatic();

  return (mapi_bool32) CallStdcallFunction(
      game_address.raw_address,
      4,
      mpq_archive_path,
      priority,
      flags,
      mpq_archive_ptr_out
  );
}
