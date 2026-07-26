/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#ifndef SGD2MAPI_C_D2SE_INI_PROPERTIES_PROTECTED_SECTION_H_
#define SGD2MAPI_C_D2SE_INI_PROPERTIES_PROTECTED_SECTION_H_

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"

#include "sgd2mapi/d2se/dllapi_c_define.inc"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

struct D2SeProtectedSection {
  enum D2SeD2Core d2core;
};

DLLAPI struct D2SeProtectedSection* D2SeProtectedSection_ReadFrom(
    struct D2SeProtectedSection* protected_section,
    const wchar_t* path,
    struct SGD2Error* error);

DLLAPI int D2SeProtectedSection_Equals(
    const struct D2SeProtectedSection* lhs,
    const struct D2SeProtectedSection* rhs);

#ifdef __cplusplus
}  // extern "C"
#endif  /* __cplusplus */

#include "sgd2mapi/d2se/dllapi_c_undef.inc"
#endif  /* SGD2MAPI_C_D2SE_INI_PROPERTIES_PROTECTED_SECTION_H_ */
