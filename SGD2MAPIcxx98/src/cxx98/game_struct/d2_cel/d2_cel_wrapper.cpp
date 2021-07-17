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

#include "../../../../include/cxx98/game_struct/d2_cel/d2_cel_wrapper.hpp"

namespace d2 {

Cel_Wrapper::Cel_Wrapper(Cel* cel) {
  this->cel_.v1_00 = reinterpret_cast<Cel_1_00*>(cel);
}

Cel_Wrapper::Cel_Wrapper(Cel_1_00* cel) {
  this->cel_.v1_00 = cel;
}

Cel_Wrapper::operator Cel_View() const {
  return Cel_View(this->Get());
}

Cel* Cel_Wrapper::Get() {
  const Cel_Wrapper* const_this = this;

  return const_cast<Cel*>(const_this->Get());
}

const Cel* Cel_Wrapper::Get() const {
  Cel_View view(*this);

  return view.Get();
}

int Cel_Wrapper::GetHeight() const {
  Cel_View view(*this);

  return view.GetHeight();
}

void Cel_Wrapper::SetHeight(int height) {
  ::D2_Cel_SetHeight(this->Get(), height);
}

int Cel_Wrapper::GetOffsetX() const {
  Cel_View view(*this);

  return view.GetOffsetX();
}

void Cel_Wrapper::SetOffsetX(int offset_x) {
  ::D2_Cel_SetOffsetX(this->Get(), offset_x);
}

int Cel_Wrapper::GetOffsetY() const {
  Cel_View view(*this);

  return view.GetOffsetY();
}

void Cel_Wrapper::SetOffsetY(int offset_y) {
  ::D2_Cel_SetOffsetY(this->Get(), offset_y);
}

int Cel_Wrapper::GetWidth() const {
  Cel_View view(*this);

  return view.GetWidth();
}

void Cel_Wrapper::SetWidth(int width) {
  ::D2_Cel_SetWidth(this->Get(), width);
}

} // namespace d2
