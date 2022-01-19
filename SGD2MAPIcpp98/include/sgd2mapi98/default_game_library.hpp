/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2022  Mir Drualga
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

#ifndef SGD2MAPI_CPP98_DEFAULT_GAME_LIBRARY_HPP_
#define SGD2MAPI_CPP98_DEFAULT_GAME_LIBRARY_HPP_

#include <windows.h>

#include <mdc/std/wchar.h>

#include "../dllexport_define.inc"

namespace d2 {
namespace default_library {

/*
* This internal enum is not intended for direct public use. It is
* stricly defined here to prevent enum leak to namespace. Use the
* typedefs in the upper-level namespace instead.
*/

enum DefaultLibrary {
  kBNClient, kD2CMP, kD2Client, kD2Common, kD2DDraw, kD2Direct3D, kD2GDI,
  kD2GFX, kD2Game, kD2Glide, kD2Lang, kD2Launch, kD2MCPClient, kD2Multi,
  kD2Net, kD2Server, kD2Sound, kD2Win, kFog, kStorm,
};

} // namespace default_library

/**
 * The default libraries that are used by Diablo II.
 */
typedef default_library::DefaultLibrary DefaultLibrary;

namespace default_library {

DLLEXPORT HMODULE GetHandle(
    DefaultLibrary library,
    bool is_allow_redirect_to_game_exe);

DLLEXPORT const wchar_t* GetPathWithRedirect(DefaultLibrary library);

DLLEXPORT const wchar_t* GetPathWithoutRedirect(DefaultLibrary library);

} // namespace default_library

} // namespace d2

#include "../dllexport_undefine.inc"
#endif /* SGD2MAPI_CPP98_DEFAULT_GAME_LIBRARY_HPP_ */
