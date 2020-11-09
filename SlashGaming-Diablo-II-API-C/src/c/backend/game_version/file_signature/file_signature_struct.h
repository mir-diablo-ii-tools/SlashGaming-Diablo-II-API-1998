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

#ifndef SGMAPI_C_BACKEND_GAME_VERSION_FILE_SIGNATURE_FILE_SIGNATURE_STRUCT_H_
#define SGMAPI_C_BACKEND_GAME_VERSION_FILE_SIGNATURE_FILE_SIGNATURE_STRUCT_H_

#include <stddef.h>

#include <mdc/filesystem/filesystem.h>
#include <mdc/std/stdbool.h>
#include <mdc/std/stdint.h>
#include <mdc/std/wchar.h>
#include "../../../../../include/c/game_address.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum {
  Mapi_Impl_FileSignature_kSignatureByteCount = 4
};

struct Mapi_Impl_FileSignature {
  struct Mdc_Fs_Path file_path_;
  ptrdiff_t offset_;
  uint8_t signature_[Mapi_Impl_FileSignature_kSignatureByteCount];
};

struct Mapi_Impl_FileSignatureLiteral {
  const wchar_t* file_path_cstr;
  ptrdiff_t offset;
  uint8_t signature[Mapi_Impl_FileSignature_kSignatureByteCount];
};

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitFromLiteral(
    struct Mapi_Impl_FileSignature* file_signature,
    struct Mapi_Impl_FileSignatureLiteral* lit
);

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitCopy(
    struct Mapi_Impl_FileSignature* dest,
    const struct Mapi_Impl_FileSignature* src
);

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitMove(
    struct Mapi_Impl_FileSignature* dest,
    struct Mapi_Impl_FileSignature* src
);

void Mapi_Impl_FileSignature_Deinit(
    struct Mapi_Impl_FileSignature* file_signature
);

const struct Mdc_ObjectMetadata*
Mapi_Impl_FileSignature_GetObjectMetadata(void);

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_AssignCopy(
    struct Mapi_Impl_FileSignature* dest,
    const struct Mapi_Impl_FileSignature* src
);

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_AssignMove(
    struct Mapi_Impl_FileSignature* dest,
    struct Mapi_Impl_FileSignature* src
);

bool Mapi_Impl_FileSignature_Equal(
    const struct Mapi_Impl_FileSignature* file_signature1,
    const struct Mapi_Impl_FileSignature* file_signature2
);

bool Mapi_Impl_FileSignature_Compare(
    const struct Mapi_Impl_FileSignature* file_signature1,
    const struct Mapi_Impl_FileSignature* file_signature2
);

void Mapi_Impl_FileSignature_Swap(
    struct Mapi_Impl_FileSignature* file_signature1,
    struct Mapi_Impl_FileSignature* file_signature2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* SGMAPI_C_BACKEND_GAME_VERSION_FILE_SIGNATURE_FILE_SIGNATURE_STRUCT_H_ */
