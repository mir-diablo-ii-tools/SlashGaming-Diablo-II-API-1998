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

#include <pthread.h>
#include <stdint.h>

#include "../../../asm_x86_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_function/fastcall_function.h"
#include "../../backend/game_address_table.h"
#include "../../../../include/c/game_version.h"
#include "../../../wide_macro.h"

static pthread_once_t once_flag = PTHREAD_ONCE_INIT;
static const struct MAPI_GameAddress* game_address;

static void InitGameAddress(void) {
  game_address = GetGameAddress(
      "Fog.dll",
      "AllocClientMemory"
  );
}

void* D2_Fog_AllocClientMemory(
    int size,
    const char* source_file,
    int line,
    int unused__set_to_0
) {
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
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (void*) CallFastcallFunction(
      game_address->raw_address,
      4,
      size,
      source_file,
      line,
      unused__set_to_0
  );
}
