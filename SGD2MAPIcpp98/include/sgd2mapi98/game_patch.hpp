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

#ifndef SGMAPI_CPP98_GAME_PATCH_HPP_
#define SGMAPI_CPP98_GAME_PATCH_HPP_

#include <stddef.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include <sgd2mapi98.h>
#include "game_address.hpp"
#include "game_branch_type.hpp"

#include "../dllexport_define.inc"

namespace mapi {

class DLLEXPORT GamePatch {
public:
  GamePatch();

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  GamePatch(const GamePatch& game_patch) = delete;

  GamePatch(GamePatch&& game_patch);

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  /**
   * Destructs this game patch. Does not remove the effects of the
   * patch.
   */
  ~GamePatch();

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  GamePatch& operator=(const GamePatch& game_patch) = delete;

  GamePatch& operator=(GamePatch&& game_patch);

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  operator Mapi_GamePatch&();

  operator const Mapi_GamePatch&() const;

  /**
   * Makes an instance of a back branch patch. The patch is configured
   * to overwrite the game code with a branch to the specified
   * function. Space prior to the branch is filled with NOPs.
   */
  static GamePatch MakeGameBackBranchPatch(
      const GameAddress& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      size_t patch_size
  );

  /**
   * Makes an instance of a branch patch. The patch is configured to
   * overwrite the game code with a branch to the specified function.
   * Space after the branch is filled with NOPs.
   */
  static GamePatch MakeGameBranchPatch(
      const GameAddress& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      size_t patch_size
  );

  /**
   * Makes an instance of a buffer patch. The patch is configured to
   * overwrite the game code with values copied from an array of 8-bit
   * integrals.
   */
  static GamePatch MakeGameBufferPatch(
      const GameAddress& game_address,
      const uint8_t* buffer,
      size_t patch_size
  );

  /**
   * Makes an instance of a NOP patch. The patch is configured to
   * overwrite the game code with NOPs.
   */
  static GamePatch MakeGameNopPatch(
      const GameAddress& game_address,
      size_t patch_size
  );

  /**
   * Applies the game patch by replacing the bytes at its target
   * address with the bytes stored in its patch buffer.
   */
  void Apply();

  /**
   * Removes the game patch by restoring the original state of the
   * bytes at its target address.
   */
  void Remove();

  void Swap(GamePatch& game_patch);

  void swap(GamePatch& game_patch);

private:
  Mapi_GamePatch game_patch_;

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

  /*
  * These functions are intentionally unusable. They need to be
  * defined for DLL export, however. They should not be used
  * internally and cannot be used externally.
  */

  GamePatch(const GamePatch& game_patch);
  GamePatch& operator=(const GamePatch& game_patch);

#endif // __cplusplus < 201103L && _MSVC_LANG < 201103L
};

} // namespace mapi

#include "../dllexport_undefine.inc"
#endif /* SGMAPI_CPP98_GAME_PATCH_HPP_ */
