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

#include "../../../../include/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"

namespace d2 {

PositionalRectangle_Wrapper::PositionalRectangle_Wrapper(
    PositionalRectangle* positional_rectangle
) {
  this->positional_rectangle_.v1_00 =
      reinterpret_cast<PositionalRectangle_1_00*>(
          positional_rectangle
      );
}

PositionalRectangle_Wrapper::PositionalRectangle_Wrapper(
    PositionalRectangle_1_00* positional_rectangle
) {
  this->positional_rectangle_.v1_00 = positional_rectangle;
}

PositionalRectangle_Wrapper PositionalRectangle_Wrapper::operator[](
    size_t index
) {
  return ::D2_PositionalRectangle_Access(this->Get(), index);
}

PositionalRectangle_View PositionalRectangle_Wrapper::operator[](
    size_t index
) const {
  PositionalRectangle_View view(*this);

  return view[index];
}

PositionalRectangle_Wrapper::operator PositionalRectangle_View() const {
  return PositionalRectangle_View(this->positional_rectangle_.v1_00);
}

PositionalRectangle* PositionalRectangle_Wrapper::Get() {
  const PositionalRectangle_Wrapper* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->Get());
}

const PositionalRectangle* PositionalRectangle_Wrapper::Get() const {
  return reinterpret_cast<const PositionalRectangle*>(
      this->positional_rectangle_.v1_00
  );
}

void PositionalRectangle_Wrapper::AssignMembers(
    PositionalRectangle_View src
) {
  ::D2_PositionalRectangle_AssignMembers(this->Get(), src.Get());
}

int PositionalRectangle_Wrapper::GetLeft() const {
  PositionalRectangle_View view(*this);

  return view.GetLeft();
}

void PositionalRectangle_Wrapper::SetLeft(int left) {
  ::D2_PositionalRectangle_SetLeft(this->Get(), left);
}

int PositionalRectangle_Wrapper::GetRight() const {
  PositionalRectangle_View view(*this);

  return view.GetRight();
}

void PositionalRectangle_Wrapper::SetRight(int right) {
  ::D2_PositionalRectangle_SetRight(this->Get(), right);
}

int PositionalRectangle_Wrapper::GetTop() const {
  PositionalRectangle_View view(*this);

  return view.GetTop();
}

void PositionalRectangle_Wrapper::SetTop(int top) {
  ::D2_PositionalRectangle_SetTop(this->Get(), top);
}

int PositionalRectangle_Wrapper::GetBottom() const {
  PositionalRectangle_View view(*this);

  return view.GetBottom();
}

void PositionalRectangle_Wrapper::SetBottom(int bottom) {
  ::D2_PositionalRectangle_SetBottom(this->Get(), bottom);
}

} // namespace d2
