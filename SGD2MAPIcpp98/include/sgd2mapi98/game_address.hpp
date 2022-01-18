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

#ifndef SGMAPI_CPP98_GAME_ADDRESS_HPP_
#define SGMAPI_CPP98_GAME_ADDRESS_HPP_

#include <stddef.h>
#include <windows.h>

#include <mdc/std/stdint.h>
#include <sgd2mapi98.h>
#include "default_game_library.hpp"

#include "../dllexport_define.inc"

namespace mapi {

class DLLEXPORT GameAddress {
 public:

  /*
  * Copiers, movers, and destructors are not declared on purpose.
  */

  operator Mapi_GameAddress&();

  operator const Mapi_GameAddress&() const;

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as a null-terminated string encoded in 7-bit ASCII, which
   * represents the address's exported name.
   */
  static GameAddress FromExportedName(
      ::d2::DefaultLibrary default_library,
      const char* exported_name
  );

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as a null-terminated string encoded in 7-bit ASCII, which
   * represents the address's exported name.
   */
  static GameAddress FromExportedName(
      HMODULE library,
      const char* exported_name
  );

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the offset from the module base address to the target address.
   */
  static GameAddress FromOffset(
      ::d2::DefaultLibrary library,
      ptrdiff_t offset
  );

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the offset from the module base address to the target address.
   */
  static GameAddress FromOffset(
      HMODULE library,
      ptrdiff_t offset
  );

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the address's ordinal value.
   */
  static GameAddress FromOrdinal(
      ::d2::DefaultLibrary library,
      int16_t ordinal
  );

  /**
   * Initializes a GameAddress. The game address locator is specified
   * as the address's ordinal value.
   */
  static GameAddress FromOrdinal(
      HMODULE library,
      int16_t ordinal
  );

  void Swap(GameAddress& game_address);

  void swap(GameAddress& game_address);

  intptr_t raw_address() const throw();

 private:
  Mapi_GameAddress game_address_;
};

} // namespace mapi

#include "../dllexport_undefine.inc"
#endif /* SGMAPI_CPP98_GAME_ADDRESS_HPP_ */
