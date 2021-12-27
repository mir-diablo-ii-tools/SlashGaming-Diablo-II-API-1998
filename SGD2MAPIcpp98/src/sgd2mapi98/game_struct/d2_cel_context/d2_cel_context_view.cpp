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

#include "../../../../include/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_view.hpp"

#include "../../../../include/sgd2mapi98/game_version.hpp"

namespace d2 {

CelContext_View::CelContext_View(const CelContext* cel_context) {
  GameVersion running_game_version = game_version::GetRunning();

  if (running_game_version >= game_version::k1_00
      && running_game_version <= game_version::k1_10) {
    this->cel_context_.v1_00 = reinterpret_cast<const CelContext_1_00*>(
        cel_context
    );
  } else if (running_game_version == game_version::k1_12A) {
    this->cel_context_.v1_12a = reinterpret_cast<const CelContext_1_12A*>(
        cel_context
    );
  } else /* if (running_game_version >= game_version::k1_13ABeta
      && running_game_version <= game_version::kLod1_14D) */ {
    this->cel_context_.v1_13c = reinterpret_cast<const CelContext_1_13C*>(
        cel_context
    );
  }
}

CelContext_View::CelContext_View(const CelContext_1_00* cel_context) {
  this->cel_context_.v1_00 = cel_context;
}

CelContext_View::CelContext_View(const CelContext_1_12A* cel_context) {
  this->cel_context_.v1_12a = cel_context;
}

CelContext_View::CelContext_View(const CelContext_1_13C* cel_context) {
  this->cel_context_.v1_13c = cel_context;
}

CelContext_View CelContext_View::operator[](size_t index) const {
  return ::D2_CelContext_AccessConst(this->Get(), index);
}

const CelContext* CelContext_View::Get() const {
  GameVersion running_game_version = game_version::GetRunning();

  if (running_game_version >= game_version::k1_00
      && running_game_version <= game_version::k1_10) {
    return reinterpret_cast<const CelContext*>(this->cel_context_.v1_00);
  } else if (running_game_version == game_version::k1_12A) {
    return reinterpret_cast<const CelContext*>(this->cel_context_.v1_12a);
  } else /* if (running_game_version >= game_version::k1_13ABeta
      && running_game_version <= game_version::kLod1_14D) */ {
    return reinterpret_cast<const CelContext*>(this->cel_context_.v1_13c);
  }
}

CelFile_View CelContext_View::GetCelFile() const {
  return ::D2_CelContext_GetCelFileConst(this->Get());
}

unsigned int CelContext_View::GetDirectionIndex() const {
  return ::D2_CelContext_GetDirectionIndex(this->Get());
}

unsigned int CelContext_View::GetFrameIndex() const {
  return ::D2_CelContext_GetFrameIndex(this->Get());
}

} // namespace d2
