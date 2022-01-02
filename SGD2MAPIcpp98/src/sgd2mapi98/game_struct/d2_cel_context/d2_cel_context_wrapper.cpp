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

#include "../../../../include/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_wrapper.hpp"

#include "../../../../include/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.hpp"
#include "../../../../include/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.hpp"
#include "../../../../include/sgd2mapi98/game_version.hpp"

namespace d2 {

CelContext_Wrapper::CelContext_Wrapper(CelContext* cel_context) {
  GameVersion running_game_version = game_version::GetRunning();

  if (running_game_version >= game_version::k1_00
      && running_game_version <= game_version::k1_10) {
    this->cel_context_.v1_00 = reinterpret_cast<CelContext_1_00*>(
        cel_context
    );
  } else if (running_game_version == game_version::k1_12A) {
    this->cel_context_.v1_12a = reinterpret_cast<CelContext_1_12A*>(
        cel_context
    );
  } else /* if (running_game_version >= game_version::k1_13ABeta
      && running_game_version <= game_version::kLod1_14D) */ {
    this->cel_context_.v1_13c = reinterpret_cast<CelContext_1_13C*>(
        cel_context
    );
  }
}

CelContext_Wrapper::CelContext_Wrapper(CelContext_1_00* cel_context) {
  this->cel_context_.v1_00 = cel_context;
}

CelContext_Wrapper::CelContext_Wrapper(CelContext_1_12A* cel_context) {
  this->cel_context_.v1_12a = cel_context;
}

CelContext_Wrapper::CelContext_Wrapper(CelContext_1_13C* cel_context) {
  this->cel_context_.v1_13c = cel_context;
}

CelContext_View CelContext_Wrapper::operator[](size_t index) const {
  CelContext_View view(*this);

  return view[index];
}

CelContext_Wrapper CelContext_Wrapper::operator[](size_t index) {
  return ::D2_CelContext_Access(this->Get(), index);
}

CelContext_Wrapper::operator CelContext_View() const {
  return CelContext_View(this->Get());
}

CelContext* CelContext_Wrapper::Get() {
  const CelContext_Wrapper* const_this = this;

  return const_cast<CelContext*>(const_this->Get());
}

const CelContext* CelContext_Wrapper::Get() const {
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

void CelContext_Wrapper::AssignMembers(CelContext_View src) {
  ::D2_CelContext_AssignMembers(this->Get(), src.Get());
}

bool CelContext_Wrapper::DrawFrame(int position_x, int position_y) {
  return d2gfx::DrawCelContext(
      this->Get(),
      position_x,
      position_y,
      0xFFFFFFFFUL,
      draw_effect::api::kNone,
      NULL
  );
}

Cel_Wrapper CelContext_Wrapper::GetCel() {
  return d2cmp::GetCelFromCelContext(this->Get());
}

CelFile_View CelContext_Wrapper::GetCelFile() const {
  CelContext_View view(*this);

  return view.GetCelFile();
}

CelFile_Wrapper CelContext_Wrapper::GetCelFile() {
  return ::D2_CelContext_GetCelFile(this->Get());
}

void CelContext_Wrapper::SetCelFile(CelFile_Wrapper cel_file) {
  ::D2_CelContext_SetCelFile(this->Get(), cel_file.Get());
}

unsigned int CelContext_Wrapper::GetDirectionIndex() const {
  CelContext_View view(*this);

  return view.GetDirectionIndex();
}

void CelContext_Wrapper::SetDirectionIndex(unsigned int direction_index) {
  ::D2_CelContext_SetDirectionIndex(this->Get(), direction_index);
}

unsigned int CelContext_Wrapper::GetFrameIndex() const {
  CelContext_View view(*this);

  return view.GetFrameIndex();
}

void CelContext_Wrapper::SetFrameIndex(unsigned int frame_index) {
  ::D2_CelContext_SetFrameIndex(this->Get(), frame_index);
}

} // namespace d2
