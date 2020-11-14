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

#include "file_signature_struct.h"

#include <mdc/std/threads.h>

static void* Mapi_Impl_FileSignature_InitCopyAsVoid(
    void* dest,
    const void* src
) {
  return Mapi_Impl_FileSignature_InitCopy(dest, src);
}

static void* Mapi_Impl_FileSignature_InitMoveAsVoid(
    void* dest,
    void* src
) {
  return Mapi_Impl_FileSignature_InitMove(dest, src);
}

void Mapi_Impl_FileSignature_DeinitAsVoid(void* obj) {
  Mapi_Impl_FileSignature_Deinit(obj);
}

void* Mapi_Impl_FileSignature_AssignCopyAsVoid(
    void* dest,
    const void* src
) {
  return Mapi_Impl_FileSignature_AssignCopy(dest, src);
}

void* Mapi_Impl_FileSignature_AssignMoveAsVoid(
    void* dest,
    void* src
) {
  return Mapi_Impl_FileSignature_AssignMove(dest, src);
}

bool Mapi_Impl_FileSignature_EqualAsVoid(
    const void* obj1,
    const void* obj2
) {
  return Mapi_Impl_FileSignature_Equal(obj1, obj2);
}

int Mapi_Impl_FileSignature_CompareAsVoid(
    const void* obj1,
    const void* obj2
) {
  return Mapi_Impl_FileSignature_Compare(obj1, obj2);
}

void Mapi_Impl_FileSignature_SwapAsVoid(
    void* obj1,
    void* obj2
) {
  Mapi_Impl_FileSignature_Swap(obj1, obj2);
}

static struct Mdc_ObjectMetadata object_metadata;
static once_flag object_metadata_init_flag;

static void Mapi_Impl_FileSignature_InitObjectMetadata(void) {
  object_metadata.size = sizeof(struct Mapi_Impl_FileSignature);

  object_metadata.functions.init_copy =
      &Mapi_Impl_FileSignature_InitCopyAsVoid;
  object_metadata.functions.init_move =
      &Mapi_Impl_FileSignature_InitMoveAsVoid;

  object_metadata.functions.deinit =
      &Mapi_Impl_FileSignature_DeinitAsVoid;

  object_metadata.functions.assign_copy =
      &Mapi_Impl_FileSignature_AssignCopyAsVoid;
  object_metadata.functions.assign_move =
      &Mapi_Impl_FileSignature_AssignMoveAsVoid;

  object_metadata.functions.equal =
      &Mapi_Impl_FileSignature_EqualAsVoid;
  object_metadata.functions.compare =
      &Mapi_Impl_FileSignature_CompareAsVoid;

  object_metadata.functions.swap =
      &Mapi_Impl_FileSignature_SwapAsVoid;
}

static void InitStatic(void) {
  call_once(
      &object_metadata_init_flag,
      &Mapi_Impl_FileSignature_InitObjectMetadata
  );
}

const struct Mdc_ObjectMetadata*
Mapi_Impl_FileSignature_GetObjectMetadata(void) {
  InitStatic();

  return &object_metadata;
}
