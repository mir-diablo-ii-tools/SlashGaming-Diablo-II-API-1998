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

#include "game_address_locator.h"

#include <mdc/std/threads.h>

static void* Mapi_GameAddressLocator_InitCopyAsVoid(
    void* dest,
    const void* src
) {
  return Mapi_GameAddressLocator_InitCopy(dest, src);
}

static void* Mapi_GameAddressLocator_InitMoveAsVoid(
    void* dest,
    void* src
) {
  return Mapi_GameAddressLocator_InitMove(dest, src);
}

static void Mapi_GameAddressLocator_DeinitAsVoid(void* obj) {
  Mapi_GameAddressLocator_Deinit(obj);
}

static void* Mapi_GameAddressLocator_AssignCopyAsVoid(
    void* dest,
    const void* src
) {
  return Mapi_GameAddressLocator_AssignCopy(dest, src);
}

static void* Mapi_GameAddressLocator_AssignMoveAsVoid(
    void* dest,
    void* src
) {
  return Mapi_GameAddressLocator_AssignMove(dest, src);
}

static bool Mapi_GameAddressLocator_EqualAsVoid(
    const void* obj1,
    const void* obj2
) {
  return Mapi_GameAddressLocator_Equal(obj1, obj2);
}

static int Mapi_GameAddressLocator_CompareAsVoid(
    const void* obj1,
    const void* obj2
) {
  return Mapi_GameAddressLocator_Compare(obj1, obj2);
}

static void Mapi_GameAddressLocator_SwapAsVoid(
    void* game_library1,
    void* game_library2
) {
  Mapi_GameAddressLocator_Swap(game_library1, game_library2);
}

static struct Mdc_ObjectMetadata*
Mapi_GameAddressLocator_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mapi_GameAddressLocator);

  metadata->functions.init_copy = &Mapi_GameAddressLocator_InitCopyAsVoid;
  metadata->functions.init_move = &Mapi_GameAddressLocator_InitMoveAsVoid;
  metadata->functions.deinit = &Mapi_GameAddressLocator_DeinitAsVoid;

  metadata->functions.assign_copy = &Mapi_GameAddressLocator_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mapi_GameAddressLocator_AssignMoveAsVoid;

  metadata->functions.equal = &Mapi_GameAddressLocator_EqualAsVoid;
  metadata->functions.compare = &Mapi_GameAddressLocator_CompareAsVoid;

  metadata->functions.swap = &Mapi_GameAddressLocator_SwapAsVoid;

  return metadata;
}

static struct Mdc_ObjectMetadata object_metadata;
static once_flag object_metadata_init_flag = ONCE_FLAG_INIT;

static void Mapi_GameAddressLocator_InitGlobalObjectMetadata(void) {
  Mapi_GameAddressLocator_InitObjectMetadata(&object_metadata);
}

static void InitStatic(void) {
  call_once(
      &object_metadata_init_flag,
      &Mapi_GameAddressLocator_InitGlobalObjectMetadata
  );
}

const struct Mdc_ObjectMetadata*
Mapi_GameAddressLocator_GetObjectMetadata(void) {
  InitStatic();

  return &object_metadata;
}
