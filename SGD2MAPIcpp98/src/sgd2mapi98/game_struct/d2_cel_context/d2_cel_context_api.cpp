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

#include "../../../../include/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_api.hpp"

#include "../../../../include/sgd2mapi98/game_version.hpp"

namespace d2 {

CelContext_Api::CelContext_Api(
    CelFile_Wrapper cel_file,
    unsigned int direction_index,
    unsigned int frame_index
) {
  this->cel_context_ = ::D2_CelContext_Api_Init(
      cel_file.Get(),
      direction_index,
      frame_index
  );
}

CelContext_Api::~CelContext_Api() {
  ::D2_CelContext_Api_Deinit(&this->cel_context_);
}

CelContext_Api::operator CelContext_View() const {
  return CelContext_View(this->Get());
}

CelContext_Api::operator CelContext_Wrapper() {
  return CelContext_Wrapper(this->Get());
}

CelContext* CelContext_Api::Get() {
  const CelContext_Api* const_this = this;

  return const_cast<CelContext*>(const_this->Get());
}

const CelContext* CelContext_Api::Get() const {
  return ::D2_CelContext_Api_GetConst(&this->cel_context_);
}

void CelContext_Api::AssignMembers(CelContext_View src) {
  CelContext_Wrapper wrapper(*this);

  wrapper.AssignMembers(src);
}

bool CelContext_Api::DrawFrame(int position_x, int position_y) {
  CelContext_Wrapper wrapper(*this);

  return wrapper.DrawFrame(position_x, position_y);
}

Cel_Wrapper CelContext_Api::GetCel() {
  CelContext_Wrapper wrapper(*this);

  return wrapper.GetCel();
}

CelFile_View CelContext_Api::GetCelFile() const {
  CelContext_View view(*this);

  return view.GetCelFile();
}

CelFile_Wrapper CelContext_Api::GetCelFile() {
  CelContext_Wrapper wrapper(*this);

  return wrapper.GetCelFile();
}

void CelContext_Api::SetCelFile(CelFile_Wrapper cel_file) {
  CelContext_Wrapper wrapper(*this);

  wrapper.SetCelFile(cel_file);
}

unsigned int CelContext_Api::GetDirectionIndex() const {
  CelContext_View view(*this);

  return view.GetDirectionIndex();
}

void CelContext_Api::SetDirectionIndex(unsigned int direction_index) {
  CelContext_Wrapper wrapper(*this);

  wrapper.SetDirectionIndex(direction_index);
}

unsigned int CelContext_Api::GetFrameIndex() const {
  CelContext_View view(*this);

  return view.GetFrameIndex();
}

void CelContext_Api::SetFrameIndex(unsigned int frame_index) {
  CelContext_Wrapper wrapper(*this);

  wrapper.SetFrameIndex(frame_index);
}

} // namespace d2
