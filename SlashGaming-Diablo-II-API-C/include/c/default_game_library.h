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

#ifndef SGD2MAPI_C_DEFAULT_GAME_LIBRARY_H_
#define SGD2MAPI_C_DEFAULT_GAME_LIBRARY_H_

#include <mdc/std/wchar.h>

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * The default libraries that are used by Diablo II.
 */
enum D2_DefaultLibrary {
  D2_DefaultLibrary_kBNClient, D2_DefaultLibrary_kD2Client,
  D2_DefaultLibrary_kD2CMP, D2_DefaultLibrary_kD2Common,
  D2_DefaultLibrary_kD2DDraw, D2_DefaultLibrary_kD2Direct3D,
  D2_DefaultLibrary_kD2Game, D2_DefaultLibrary_kD2GDI,
  D2_DefaultLibrary_kD2GFX, D2_DefaultLibrary_kD2Glide,
  D2_DefaultLibrary_kD2Lang,  D2_DefaultLibrary_kD2Launch,
  D2_DefaultLibrary_kD2MCPClient, D2_DefaultLibrary_kD2Multi,
  D2_DefaultLibrary_kD2Net, D2_DefaultLibrary_kD2Server,
  D2_DefaultLibrary_kD2Sound, D2_DefaultLibrary_kD2Win,
  D2_DefaultLibrary_kFog, D2_DefaultLibrary_kStorm,
};

DLLEXPORT const wchar_t* Mapi_GetDefaultLibraryPathWithRedirect(
    enum D2_DefaultLibrary library
);

DLLEXPORT const wchar_t* Mapi_GetDefaultLibraryPathWithoutRedirect(
    enum D2_DefaultLibrary library
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_DEFAULT_GAME_LIBRARY_H_ */
