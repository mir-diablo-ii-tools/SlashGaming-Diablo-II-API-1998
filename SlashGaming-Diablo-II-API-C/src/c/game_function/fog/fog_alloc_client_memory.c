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

#include "../../../../include/c/game_function/fog/fog_alloc_client_memory.h"

#include <mdc/std/threads.h>
#include "../../../../include/c/game_version.h"
#include "../../../asm_x86_macro.h"
#include "../../../wide_macro.h"
#include "../../backend/game_address_table.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_function/fastcall_function.h"

static struct Mapi_GameAddress game_address;
static once_flag game_address_init_flag = ONCE_FLAG_INIT;

static void InitGameAddress(void) {
  struct Mapi_GameAddress* init_game_address;

  init_game_address = Mapi_Impl_LoadGameAddressByLibraryId(
      &game_address,
      LIBRARY_FOG,
      "AllocClientMemory"
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

void* D2_Fog_AllocClientMemory(
    int size,
    const char* source_file,
    int line,
    int unused__set_to_0
) {
  InitStatic();

  return D2_Fog_AllocClientMemory_1_00(
      size,
      source_file,
      line,
      unused__set_to_0
  );
}

void* D2_Fog_AllocClientMemory_1_00(
    int32_t size,
    const char* source_file,
    int32_t line,
    int32_t unused__set_to_0
) {
  InitStatic();

  return (void*) CallFastcallFunction(
      game_address.raw_address,
      4,
      size,
      source_file,
      line,
      unused__set_to_0
  );
}
