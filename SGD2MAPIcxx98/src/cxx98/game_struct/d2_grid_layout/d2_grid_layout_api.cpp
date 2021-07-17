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

#include "../../../../include/cxx98/game_struct/d2_grid_layout/d2_grid_layout_api.hpp"

namespace d2 {

GridLayout_Api::GridLayout_Api(
    unsigned char num_columns,
    unsigned char num_rows,
    const PositionalRectangle* position,
    unsigned char width,
    unsigned char height
)
    : grid_layout_(
          ::D2_GridLayout_Api_InitFromLayout(
              num_columns,
              num_rows,
              position,
              width,
              height
          )
      ) {
}

GridLayout_Api::~GridLayout_Api() {
  ::D2_GridLayout_Api_Deinit(&this->grid_layout_);
}

GridLayout_Api::operator GridLayout_View() const {
  return GridLayout_View(this->Get());
}

GridLayout_Api::operator GridLayout_Wrapper() {
  return GridLayout_Wrapper(this->Get());
}

GridLayout* GridLayout_Api::Get() {
  const GridLayout_Api* const_this = this;

  return const_cast<GridLayout*>(const_this->Get());
}

const GridLayout* GridLayout_Api::Get() const {
  return ::D2_GridLayout_Api_GetConst(&this->grid_layout_);
}

void GridLayout_Api::AssignMembers(GridLayout_View src) {
  GridLayout_Wrapper wrapper(*this);

  wrapper.AssignMembers(src);
}

unsigned char GridLayout_Api::GetNumColumns() const {
  GridLayout_View view(*this);

  return view.GetNumColumns();
}

void GridLayout_Api::SetNumColumns(unsigned char num_columns) {
  GridLayout_Wrapper wrapper(*this);

  wrapper.SetNumColumns(num_columns);
}

unsigned char GridLayout_Api::GetNumRows() const {
  GridLayout_View view(*this);

  return view.GetNumRows();
}

void GridLayout_Api::SetNumRows(unsigned char num_rows) {
  GridLayout_Wrapper wrapper(*this);

  wrapper.SetNumRows(num_rows);
}

PositionalRectangle_View GridLayout_Api::GetPosition() const {
  GridLayout_View view(*this);

  return view.GetPosition();
}

PositionalRectangle_Wrapper GridLayout_Api::GetPosition() {
  GridLayout_Wrapper wrapper(*this);

  return wrapper.GetPosition();
}

unsigned char GridLayout_Api::GetWidth() const {
  GridLayout_View view(*this);

  return view.GetWidth();
}

void GridLayout_Api::SetWidth(unsigned char width) {
  GridLayout_Wrapper wrapper(*this);

  wrapper.SetWidth(width);
}

unsigned char GridLayout_Api::GetHeight() const {
  GridLayout_View view(*this);

  return view.GetHeight();
}

void GridLayout_Api::SetHeight(unsigned char height) {
  GridLayout_Wrapper wrapper(*this);

  wrapper.SetHeight(height);
}

} // namespace d2
