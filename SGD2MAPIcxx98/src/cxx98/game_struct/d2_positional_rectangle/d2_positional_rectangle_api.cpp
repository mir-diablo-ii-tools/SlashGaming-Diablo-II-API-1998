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

#include "../../../../include/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.hpp"

namespace d2 {

PositionalRectangle_Api::PositionalRectangle_Api() {
}

PositionalRectangle_Api::PositionalRectangle_Api(
    int left,
    int right,
    int top,
    int bottom
)
    : positional_rectangle_(
          ::D2_PositionalRectangle_Api_InitFromPositions(
              left,
              right,
              top,
              bottom
          )
      ) {
}

PositionalRectangle_Api::operator PositionalRectangle_View() const {
  return PositionalRectangle_View(this->Get());
}

PositionalRectangle_Api::operator PositionalRectangle_Wrapper() {
  return PositionalRectangle_Wrapper(this->Get());
}

PositionalRectangle* PositionalRectangle_Api::Get() {
  const PositionalRectangle_Api* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->Get());
}

const PositionalRectangle* PositionalRectangle_Api::Get() const {
  return ::D2_PositionalRectangle_Api_GetConst(&this->positional_rectangle_);
}

void PositionalRectangle_Api::AssignMembers(
    PositionalRectangle_View src
) {
  PositionalRectangle_Wrapper wrapper(*this);

  wrapper.AssignMembers(src);
}

int PositionalRectangle_Api::GetLeft() const {
  PositionalRectangle_View view(*this);

  return view.GetLeft();
}

void PositionalRectangle_Api::SetLeft(int left) {
  PositionalRectangle_Wrapper wrapper(*this);

  wrapper.SetLeft(left);
}

int PositionalRectangle_Api::GetRight() const {
  PositionalRectangle_View view(*this);

  return view.GetRight();
}

void PositionalRectangle_Api::SetRight(int right) {
  PositionalRectangle_Wrapper wrapper(*this);

  wrapper.SetRight(right);
}

int PositionalRectangle_Api::GetTop() const {
  PositionalRectangle_View view(*this);

  return view.GetTop();
}

void PositionalRectangle_Api::SetTop(int top) {
  PositionalRectangle_Wrapper wrapper(*this);

  wrapper.SetTop(top);
}

int PositionalRectangle_Api::GetBottom() const {
  PositionalRectangle_View view(*this);

  return view.GetBottom();
}

void PositionalRectangle_Api::SetBottom(int bottom) {
  PositionalRectangle_Wrapper wrapper(*this);

  wrapper.SetBottom(bottom);
}

} // namespace d2
