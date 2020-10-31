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

#include <mdc/std/threads.h>

static void* Mapi_GameLibrary_InitMoveAsVoid(void* dest, void* src) {
  return Mapi_GameLibrary_InitMove(dest, src);
}

static void Mapi_GameLibrary_DeinitAsVoid(void* game_library) {
  Mapi_GameLibrary_Deinit(game_library);
}

static void* Mapi_GameLibrary_AssignMoveAsVoid(void* dest, void* src) {
  return Mapi_GameLibrary_AssignMove(dest, src);
}

static bool Mapi_GameLibrary_EqualAsVoid(
    const void* game_library1,
    const void* game_library2
) {
  return Mapi_GameLibrary_Equal(game_library1, game_library2);
}

static int Mapi_GameLibrary_CompareAsVoid(
    const void* game_library1,
    const void* game_library2
) {
  return Mapi_GameLibrary_Compare(game_library1, game_library2);
}

static void Mapi_GameLibrary_SwapAsVoid(
    void* game_library1,
    void* game_library2
) {
  Mapi_GameLibrary_Swap(game_library1, game_library2);
}

static struct Mdc_ObjectMetadata* Mapi_GameLibrary_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mapi_GameLibrary);

  metadata->functions.init_move = &Mapi_GameLibrary_InitMoveAsVoid;
  metadata->functions.deinit = &Mapi_GameLibrary_DeinitAsVoid;

  metadata->functions.assign_move = &Mapi_GameLibrary_AssignMoveAsVoid;

  metadata->functions.equal = &Mapi_GameLibrary_EqualAsVoid;
  metadata->functions.compare = &Mapi_GameLibrary_CompareAsVoid;

  metadata->functions.swap = &Mapi_GameLibrary_SwapAsVoid;

  return metadata;
}

static struct Mdc_ObjectMetadata object_metadata;
static once_flag object_metadata_init_flag = ONCE_FLAG_INIT;

static void Mapi_GameLibrary_InitGlobalObjectMetadata(void) {
  Mapi_GameLibrary_InitObjectMetadata(&object_metadata);
}

const struct Mdc_ObjectMetadata*
Mapi_GameLibrary_GetObjectMetadata(void) {
  call_once(
      &object_metadata_init_flag,
      &Mapi_GameLibrary_InitGlobalObjectMetadata
  );

  return &object_metadata;
}
