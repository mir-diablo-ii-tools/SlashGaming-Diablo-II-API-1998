/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2021  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++98.
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

#ifndef SGD2MAPI_CXX98_DEFAULT_GAME_LIBRARY_HPP_
#define SGD2MAPI_CXX98_DEFAULT_GAME_LIBRARY_HPP_

#include <mdc/std/wchar.h>

#include "../dllexport_define.inc"

namespace d2 {

/**
 * The default libraries that are used by Diablo II.
 */
enum DefaultLibrary {
  DefaultLibrary_kBNClient, DefaultLibrary_kD2Client,
  DefaultLibrary_kD2CMP, DefaultLibrary_kD2Common,
  DefaultLibrary_kD2DDraw, DefaultLibrary_kD2Direct3D,
  DefaultLibrary_kD2Game, DefaultLibrary_kD2GDI,
  DefaultLibrary_kD2GFX, DefaultLibrary_kD2Glide,
  DefaultLibrary_kD2Lang,  DefaultLibrary_kD2Launch,
  DefaultLibrary_kD2MCPClient, DefaultLibrary_kD2Multi,
  DefaultLibrary_kD2Net, DefaultLibrary_kD2Server,
  DefaultLibrary_kD2Sound, DefaultLibrary_kD2Win,
  DefaultLibrary_kFog, DefaultLibrary_kStorm,
};

DLLEXPORT const wchar_t* DefaultLibrary_GetPathWithRedirect(
    DefaultLibrary library
);

DLLEXPORT const wchar_t* DefaultLibrary_GetPathWithoutRedirect(
    DefaultLibrary library
);

} // namespace d2

#include "../dllexport_undefine.inc"
#endif /* SGD2MAPI_CXX98_DEFAULT_GAME_LIBRARY_HPP_ */
