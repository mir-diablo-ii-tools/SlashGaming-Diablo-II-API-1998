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

#ifndef SGD2MAPI_CPP98_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_VIEW_HPP_
#define SGD2MAPI_CPP98_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_VIEW_HPP_

#include <stddef.h>

#include <sgd2mapi98.h>
#include "../d2_positional_rectangle/d2_positional_rectangle_view.hpp"
#include "d2_grid_layout_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT GridLayout_View {
 public:
  union ViewType {
    const GridLayout_1_00* v1_00;
  };

  GridLayout_View(const GridLayout* grid_layout);

  explicit GridLayout_View(const GridLayout_1_00* grid_layout);

  GridLayout_View operator[](size_t index) const;

  const GridLayout* Get() const;

  unsigned char GetNumColumns() const;

  unsigned char GetNumRows() const;

  PositionalRectangle_View GetPosition() const;

  unsigned char GetWidth() const;

  unsigned char GetHeight() const;

 private:
  ViewType grid_layout_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CPP98_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_VIEW_HPP_ */
