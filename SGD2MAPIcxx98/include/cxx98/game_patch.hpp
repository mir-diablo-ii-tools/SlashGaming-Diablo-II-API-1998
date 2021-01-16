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

#ifndef SGMAPI_CXX98_GAME_PATCH_HPP_
#define SGMAPI_CXX98_GAME_PATCH_HPP_

#include <stddef.h>

#include <sgd2mapi.h>
#include "game_address.hpp"
#include "game_branch_type.hpp"

namespace mapi {

class GamePatch {
public:

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

  /**
   * Deinitializes the game patch.
   */
  ~GamePatch() throw() {
    Mapi_GamePatch_Deinit(&this->game_patch_);
  }

#else

  /*
  * The following move functions are declared to enable move in C++98
  * code.
  */

  static GamePatch InitMove(GamePatch& game_patch) {
    return GamePatch(
        Mapi_GamePatch_InitMove(&game_patch.game_patch_)
    );
  }

  GamePatch& AssignMove(
      GamePatch& game_patch
  ) {
    if (this == &game_patch) {
      return *this;
    }

    Mapi_GamePatch_AssignMove(
        &this->game_patch_,
        &game_patch.game_patch_
    );

    return *this;
  }

  GamePatch(GamePatch&& game_patch) noexcept
      : game_patch_(Mapi_GamePatch_InitMove(&game_patch.game_patch_)) {
  }

  /**
   * Deinitializes the game patch.
   */
  ~GamePatch() noexcept {
    Mapi_GamePatch_Deinit(&this->game_patch_);
  }

  GamePatch& operator=(GamePatch&& game_patch) noexcept {
    if (this == &game_patch) {
      return *this;
    }

    Mapi_GamePatch_AssignMove(
        &this->game_patch_,
        &game_patch.game_patch_
    );

    return *this;
  }

#endif

  /**
   * Initializes a patch. The patch is configured to overwrite the game
   * code with a branch to the specified function. Space prior to the
   * branch is filled with NOPs.
   */
  static GamePatch MakeGameBackBranchPatch(
      const GameAddress& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      size_t patch_size
  ) {
    return GamePatch(
        Mapi_GamePatch_InitGameBackBranchPatch(
            &game_address.GetRefC(),
            static_cast<Mapi_BranchType>(branch_type),
            func_ptr,
            patch_size
        )
    );
  }

  /**
   * Initializes a patch. The patch is configured to overwrite the game
   * code with a branch to the specified function. Space after the
   * branch is filled with NOPs.
   */
  static GamePatch MakeGameBranchPatch(
      const GameAddress& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      size_t patch_size
  ) {
    return GamePatch(
        Mapi_GamePatch_InitGameBranchPatch(
            &game_address.GetRefC(),
            static_cast<Mapi_BranchType>(branch_type),
            func_ptr,
            patch_size
        )
    );
  }

  /**
   * Initializes a patch. The patch is configured to overwrite the game
   * code with values copied from an array of 8-bit integrals.
   */
  static GamePatch MakeGameBufferPatch(
      const GameAddress& game_address,
      const uint8_t* buffer,
      size_t patch_size
  ) {
    return GamePatch(
        Mapi_GamePatch_InitGameBufferPatch(
            &game_address.GetRefC(),
            buffer,
            patch_size
        )
    );
  }

  /**
   * Initializes a patch. The patch is configured to overwrite the game
   * code with NOPs.
   */
  static GamePatch MakeGameNopPatch(
      const GameAddress& game_address,
      size_t patch_size
  ) {
    return GamePatch(
        Mapi_GamePatch_InitGameNopPatch(
            &game_address.GetRefC(),
            patch_size
        )
    );
  }

  /**
   * Applies the game patch by replacing the bytes at its target
   * address with the bytes stored in its patch buffer.
   */
  void Apply() {
    Mapi_GamePatch_Apply(&this->game_patch_);
  }

  /**
   * Removes the game patch by restoring the original state of the
   * bytes at its target address.
   */
  void Remove() {
    Mapi_GamePatch_Remove(&this->game_patch_);
  }

  void swap(GamePatch& game_patch) {
    Mapi_GamePatch_Swap(&this->game_patch_, &game_patch.game_patch_);
  }

  Mapi_GamePatch& GetRefC() throw() {
    const auto* const_this = this;

    return const_cast<Mapi_GamePatch&>(const_this->GetRefC());
  }

  const Mapi_GamePatch& GetRefC() const throw() {
    return this->game_patch_;
  }

private:
  Mapi_GamePatch game_patch_;

  explicit GamePatch(Mapi_GamePatch game_patch) throw()
      : game_patch_(game_patch) {
  }

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

  /*
  * These functions are intentionally left unimplemented.
  */

  GamePatch(GamePatch&);
  GamePatch& operator=(GamePatch&);

#endif
};

} // namespace mapi

#endif /* SGMAPI_CXX98_GAME_PATCH_HPP_ */
