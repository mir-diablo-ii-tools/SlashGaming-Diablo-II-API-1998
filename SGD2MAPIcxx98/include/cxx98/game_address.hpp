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

#ifndef SGMAPI_CXX98_GAME_ADDRESS_HPP_
#define SGMAPI_CXX98_GAME_ADDRESS_HPP_

#include <stddef.h>

#include <mdc/std/stdint.h>
#include <sgd2mapi.h>
#include "default_game_library.hpp"

namespace mapi {

class GameAddress {
 public:

  /*
  * Copiers, movers, and destructors are not declared on purpose.
  */

  /*
  * The following move functions are declared to enable move in C++98
  * code.
  */

  static GameAddress InitMove(GameAddress& game_address) {
    return GameAddress(
        Mapi_GameAddress_InitMove(&game_address.game_address_)
    );
  }

  GameAddress& AssignMove(
      GameAddress& game_address
  ) {
    if (this == &game_address) {
      return *this;
    }

    Mapi_GameAddress_AssignMove(
        &this->game_address_,
        &game_address.game_address_
    );

    return *this;
  }

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as a string encoded in 7-bit ASCII, which represents the address's
   * exported name.
   */
  static GameAddress FromExportedName(
      d2::DefaultLibrary default_library,
      const char* exported_name
  ) {
    return GameAddress(
        Mapi_GameAddress_InitFromLibraryAndExportedName(
            static_cast<D2_DefaultLibrary>(default_library),
            exported_name
        )
    );
  }

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as a null-terminated string encoded in 7-bit ASCII, which
   * represents the address's exported name.
   */
  static GameAddress FromExportedName(
      const wchar_t* path,
      const char* exported_name
  ) {
    return GameAddress(
        Mapi_GameAddress_InitFromPathAndExportedName(
            path,
            exported_name
        )
    );
  }

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the offset from the module base address to the target address.
   */
  static GameAddress FromOffset(
      d2::DefaultLibrary library,
      ptrdiff_t offset
  ) {
    return GameAddress(
        Mapi_GameAddress_InitFromLibraryAndOffset(
            static_cast<D2_DefaultLibrary>(library),
            offset
        )
    );
  }

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the offset from the module base address to the target address.
   */
  static GameAddress FromOffset(
      const wchar_t* path,
      ptrdiff_t offset
  ) {
    return GameAddress(
        Mapi_GameAddress_InitFromPathAndOffset(
            path,
            offset
        )
    );
  }

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the address's ordinal value.
   */
  static GameAddress FromOrdinal(
      d2::DefaultLibrary library,
      int16_t ordinal
  ) {
    return GameAddress(
        Mapi_GameAddress_InitFromLibraryAndOrdinal(
            static_cast<D2_DefaultLibrary>(library),
            ordinal
        )
    );
  }

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the address's ordinal value.
   */
  static GameAddress FromOrdinal(
      const wchar_t* path,
      int16_t ordinal
  ) {
    return GameAddress(
        Mapi_GameAddress_InitFromPathAndOrdinal(
            path,
            ordinal
        )
    );
  }

  void swap(GameAddress& game_address) {
    Mapi_GameAddress_Swap(&this->game_address_, &game_address.game_address_);
  }

  Mapi_GameAddress& GetRefC() throw() {
    const GameAddress* const_this = this;

    return const_cast<Mapi_GameAddress&>(const_this->GetRefC());
  }

  const Mapi_GameAddress& GetRefC() const throw() {
    return this->game_address_;
  }

  intptr_t raw_address() const throw() {
    return this->game_address_.raw_address;
  }

 private:
  Mapi_GameAddress game_address_;

  explicit GameAddress(Mapi_GameAddress game_address)
      : game_address_(game_address) {
  }
};

} // namespace mapi

#endif /* SGMAPI_CXX98_GAME_ADDRESS_HPP_ */
