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

#include "../../../../include/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_view.hpp"

namespace d2 {

EquipmentLayout_View::EquipmentLayout_View(
    const EquipmentLayout* equipment_layout
) {
  this->equipment_layout_.v1_00 =
      reinterpret_cast<const EquipmentLayout_1_00*>(
          equipment_layout
      );
}

EquipmentLayout_View::EquipmentLayout_View(
    const EquipmentLayout_1_00* equipment_layout
) {
  this->equipment_layout_.v1_00 = equipment_layout;
}

EquipmentLayout_View EquipmentLayout_View::operator[](size_t index) const {
  return ::D2_EquipmentLayout_AccessConst(this->Get(), index);
}

const EquipmentLayout* EquipmentLayout_View::Get() const {
  return reinterpret_cast<const EquipmentLayout*>(
      this->equipment_layout_.v1_00
  );
}

PositionalRectangle_View EquipmentLayout_View::GetPosition() const {
  return PositionalRectangle_View(
      ::D2_EquipmentLayout_GetPositionConst(this->Get())
  );
}

unsigned char EquipmentLayout_View::GetWidth() const {
  return ::D2_EquipmentLayout_GetWidth(this->Get());
}

unsigned char EquipmentLayout_View::GetHeight() const {
  return ::D2_EquipmentLayout_GetHeight(this->Get());
}

} // namespace d2
