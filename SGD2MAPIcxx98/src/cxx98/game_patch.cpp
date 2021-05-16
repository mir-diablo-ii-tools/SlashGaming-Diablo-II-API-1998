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

#include "../../include/cxx98/game_patch.hpp"

#include <mdc/std/assert.h>

namespace mapi {

GamePatch::GamePatch()
    : game_patch_(::Mapi_GamePatch_kUninit) {
}

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

GamePatch::GamePatch(GamePatch&& game_patch)
    : game_patch_(::Mapi_GamePatch_InitMove(&game_patch.game_patch_)) {
}

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L


GamePatch::~GamePatch() {
  ::Mapi_GamePatch_Deinit(&this->game_patch_);
}

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

GamePatch& GamePatch::operator=(GamePatch&& game_patch) {
  if (this == &game_patch) {
    return *this;
  }

  ::Mapi_GamePatch_AssignMove(&this->game_patch_, &game_patch.game_patch_);

  return *this;
}

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

GamePatch::operator Mapi_GamePatch&() {
  return this->game_patch_;
}

GamePatch::operator const Mapi_GamePatch&() const {
  return this->game_patch_;
}

GamePatch GamePatch::MakeGameBackBranchPatch(
    const GameAddress& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    size_t patch_size
) {
  GamePatch game_patch;

  game_patch.game_patch_ = ::Mapi_GamePatch_InitGameBackBranchPatch(
      &static_cast<const ::Mapi_GameAddress&>(game_address),
      static_cast<::Mapi_BranchType>(branch_type),
      func_ptr,
      patch_size
  );

  return game_patch;
}

GamePatch GamePatch::MakeGameBranchPatch(
    const GameAddress& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    size_t patch_size
) {
  GamePatch game_patch;

  game_patch.game_patch_ = ::Mapi_GamePatch_InitGameBranchPatch(
      &static_cast<const ::Mapi_GameAddress&>(game_address),
      static_cast<::Mapi_BranchType>(branch_type),
      func_ptr,
      patch_size
  );

  return game_patch;
}

GamePatch GamePatch::MakeGameBufferPatch(
    const GameAddress& game_address,
    const uint8_t* buffer,
    size_t patch_size
) {
  GamePatch game_patch;
  
  game_patch.game_patch_ = ::Mapi_GamePatch_InitGameBufferPatch(
      &static_cast<const ::Mapi_GameAddress&>(game_address),
      buffer,
      patch_size
  );

  return game_patch;
}

GamePatch GamePatch::MakeGameNopPatch(
    const GameAddress& game_address,
    size_t patch_size
) {
  GamePatch game_patch;
  
  game_patch.game_patch_ = ::Mapi_GamePatch_InitGameNopPatch(
      &static_cast<const ::Mapi_GameAddress&>(game_address),
      patch_size
  );

  return game_patch;
}

void GamePatch::Apply() {
  ::Mapi_GamePatch_Apply(&this->game_patch_);
}

void GamePatch::Remove() {
  ::Mapi_GamePatch_Remove(&this->game_patch_);
}

void GamePatch::Swap(GamePatch& game_patch) {
  ::Mapi_GamePatch_Swap(&this->game_patch_, &game_patch.game_patch_);
}

void GamePatch::swap(GamePatch& game_patch) {
  this->Swap(game_patch);
}

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

/*
* These functions are intentionally unusable. They need to be
* defined for DLL export, however. They should not be used
* internally and cannot be used externally.
*/

GamePatch::GamePatch(const GamePatch& game_patch) {
  assert(false);
}

GamePatch& GamePatch::operator=(const GamePatch& game_patch) {
  assert(false);

  return *this;
}

#endif // __cplusplus < 201103L && _MSVC_LANG < 201103L

} // namespace mapi
