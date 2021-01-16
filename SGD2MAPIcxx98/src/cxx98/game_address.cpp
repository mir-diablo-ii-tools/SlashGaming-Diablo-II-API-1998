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

#include "../../include/cxx98/game_address.hpp"

namespace mapi {

GameAddress::GameAddress(Mapi_GameAddress game_address)
    : game_address_(game_address) {
}

GameAddress GameAddress::FromExportedName(
    d2::DefaultLibrary default_library,
    const char* exported_name
) throw() {
  return GameAddress(
      Mapi_GameAddress_InitFromLibraryAndExportedName(
          static_cast<D2_DefaultLibrary>(default_library),
          exported_name
      )
  );
}

GameAddress GameAddress::FromExportedName(
    const wchar_t* path,
    const char* exported_name
) throw() {
  return GameAddress(
      Mapi_GameAddress_InitFromPathAndExportedName(
          path,
          exported_name
      )
  );
}

GameAddress GameAddress::FromOffset(
    d2::DefaultLibrary library,
    ptrdiff_t offset
) throw() {
  return GameAddress(
      Mapi_GameAddress_InitFromLibraryAndOffset(
          static_cast<D2_DefaultLibrary>(library),
          offset
      )
  );
}

GameAddress GameAddress::FromOffset(
    const wchar_t* path,
    ptrdiff_t offset
) throw() {
  return GameAddress(
      Mapi_GameAddress_InitFromPathAndOffset(
          path,
          offset
      )
  );
}

GameAddress GameAddress::FromOrdinal(
    d2::DefaultLibrary library,
    int16_t ordinal
) throw() {
  return GameAddress(
      Mapi_GameAddress_InitFromLibraryAndOrdinal(
          static_cast<D2_DefaultLibrary>(library),
          ordinal
      )
  );
}

GameAddress GameAddress::FromOrdinal(
    const wchar_t* path,
    int16_t ordinal
) throw() {
  return GameAddress(
      Mapi_GameAddress_InitFromPathAndOrdinal(
          path,
          ordinal
      )
  );
}

void GameAddress::swap(GameAddress& game_address) {
  Mapi_GameAddress_Swap(&this->game_address_, &game_address.game_address_);
}

intptr_t GameAddress::raw_address() const throw() {
  return this->game_address_.raw_address;
}

} // namespace mapi
