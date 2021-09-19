/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#ifndef SGMAPI_C_FILE_FILE_PE_SIGNATURE_H_
#define SGMAPI_C_FILE_FILE_PE_SIGNATURE_H_

#include <stddef.h>

#include <mdc/std/stdint.h>
#include <mdc/std/wchar.h>

#include "../../dllexport_define.inc"

enum {
  Mapi_FilePeSignature_kMinSignatureCount = 32,
  Mapi_FilePeSignature_kMaxSignatureCount = 64,
};

struct Mapi_FilePeSignature {
  size_t signature_count;
  uint8_t signature[Mapi_FilePeSignature_kMaxSignatureCount];
};

#define MAPI_FILE_PE_SIGNATURE_UNINIT { 0 }

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT extern const struct Mapi_FilePeSignature
Mapi_FilePeSignature_kUninit;

DLLEXPORT int Mapi_FilePeSignature_Compare(
    const struct Mapi_FilePeSignature* signature1,
    const struct Mapi_FilePeSignature* signature2
);

DLLEXPORT int Mapi_FilePeSignature_ReadFile(
    struct Mapi_FilePeSignature* signature,
    const wchar_t* path,
    size_t count
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGMAPI_C_FILE_FILE_PE_SIGNATURE_H_ */
