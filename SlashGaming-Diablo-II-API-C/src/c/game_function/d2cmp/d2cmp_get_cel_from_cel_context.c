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

#include "../../../../include/c/game_function/d2cmp/d2cmp_get_cel_from_cel_context.h"

#include <pthread.h>
#include <stdint.h>

#include "../../../asm_x86_macro.h"
#include "../../backend/error_handling.h"
#include "../../backend/game_address_table.h"
#include "../../../../include/c/game_version.h"
#include "../../backend/game_function/stdcall_function.h"
#include "../../../wide_macro.h"

static pthread_once_t once_flag = PTHREAD_ONCE_INIT;
static struct MAPI_GameAddress* game_address;

static void InitGameAddress(void) {
  game_address = GetGameAddress(
      "D2CMP.dll",
      "GetCelFromCelContext"
  );
}

struct D2_Cel* D2_D2CMP_GetCelFromCelContext(
    struct D2_CelContext* cel_context
) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version < VERSION_1_11) {
    struct D2_CelContext_1_00* actual_cel_context =
        (struct D2_CelContext_1_00*) cel_context;

    return (struct D2_Cel*) D2_D2CMP_GetCelFromCelContext_1_00(
        actual_cel_context
    );
  } else if (running_game_version == VERSION_1_12A) {
    struct D2_CelContext_1_12A* actual_cel_context =
        (struct D2_CelContext_1_12A*) cel_context;

    return (struct D2_Cel*) D2_D2CMP_GetCelFromCelContext_1_12A(
        actual_cel_context
    );
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    struct D2_CelContext_1_13C* actual_cel_context =
        (struct D2_CelContext_1_13C*) cel_context;

    return (struct D2_Cel*) D2_D2CMP_GetCelFromCelContext_1_13C(
        actual_cel_context
    );
  }
}

struct D2_Cel_1_00* D2_D2CMP_GetCelFromCelContext_1_00(
    struct D2_CelContext_1_00* cel_context
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (struct D2_Cel_1_00*) CallStdcallFunction(
      game_address->raw_address,
      1,
      cel_context
  );
}

struct D2_Cel_1_00* D2_D2CMP_GetCelFromCelContext_1_12A(
    struct D2_CelContext_1_12A* cel_context
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (struct D2_Cel_1_00*) CallStdcallFunction(
      game_address->raw_address,
      1,
      cel_context
  );
}

struct D2_Cel_1_00* D2_D2CMP_GetCelFromCelContext_1_13C(
    struct D2_CelContext_1_13C* cel_context
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  return (struct D2_Cel_1_00*) CallStdcallFunction(
      game_address->raw_address,
      1,
      cel_context
  );
}
