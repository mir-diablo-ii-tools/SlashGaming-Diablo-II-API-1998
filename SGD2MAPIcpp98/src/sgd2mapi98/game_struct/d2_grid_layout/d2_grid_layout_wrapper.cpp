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

#include "../../../../include/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"

namespace d2 {

GridLayout_Wrapper::GridLayout_Wrapper(GridLayout* grid_layout) {
  this->grid_layout_.v1_00 = reinterpret_cast<GridLayout_1_00*>(
      grid_layout
  );
}

GridLayout_Wrapper::GridLayout_Wrapper(GridLayout_1_00* grid_layout) {
  this->grid_layout_.v1_00 = grid_layout;
}

GridLayout_View GridLayout_Wrapper::operator[](size_t index) const {
  GridLayout_View view(*this);

  return view[index];
}

GridLayout_Wrapper GridLayout_Wrapper::operator[](size_t index) {
  return ::D2_GridLayout_Access(this->Get(), index);
}

GridLayout_Wrapper::operator GridLayout_View() const {
  return GridLayout_View(this->Get());
}

GridLayout* GridLayout_Wrapper::Get() {
  const GridLayout_Wrapper* const_this = this;

  return const_cast<GridLayout*>(const_this->Get());
}

const GridLayout* GridLayout_Wrapper::Get() const {
  return reinterpret_cast<const GridLayout*>(
      this->grid_layout_.v1_00
  );
}

void GridLayout_Wrapper::AssignMembers(GridLayout_View src) {
  ::D2_GridLayout_AssignMembers(this->Get(), src.Get());
}

unsigned char GridLayout_Wrapper::GetNumColumns() const {
  GridLayout_View view(*this);

  return view.GetNumColumns();
}

void GridLayout_Wrapper::SetNumColumns(unsigned char num_columns) {
  ::D2_GridLayout_SetNumColumns(this->Get(), num_columns);
}

unsigned char GridLayout_Wrapper::GetNumRows() const {
  GridLayout_View view(*this);

  return view.GetNumRows();
}

void GridLayout_Wrapper::SetNumRows(unsigned char num_rows) {
  ::D2_GridLayout_SetNumRows(this->Get(), num_rows);
}

PositionalRectangle_View GridLayout_Wrapper::GetPosition() const {
  GridLayout_View view(*this);

  return view.GetPosition();
}

PositionalRectangle_Wrapper GridLayout_Wrapper::GetPosition() {
  return ::D2_GridLayout_GetPosition(this->Get());
}

unsigned char GridLayout_Wrapper::GetWidth() const {
  GridLayout_View view(*this);

  return view.GetWidth();
}

void GridLayout_Wrapper::SetWidth(unsigned char width) {
  ::D2_GridLayout_SetWidth(this->Get(), width);
}

unsigned char GridLayout_Wrapper::GetHeight() const {
  GridLayout_View view(*this);

  return view.GetHeight();
}

void GridLayout_Wrapper::SetHeight(unsigned char height) {
  ::D2_GridLayout_SetHeight(this->Get(), height);
}

} // namespace d2
