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

#include "../../../../include/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"

namespace d2 {

EquipmentLayout_Wrapper::EquipmentLayout_Wrapper(
    EquipmentLayout* equipment_layout
) {
  this->equipment_layout_.v1_00 =
      reinterpret_cast<EquipmentLayout_1_00*>(
          equipment_layout
      );
}

EquipmentLayout_Wrapper::EquipmentLayout_Wrapper(
    EquipmentLayout_1_00* equipment_layout
) {
  this->equipment_layout_.v1_00 = equipment_layout;
}

EquipmentLayout_View EquipmentLayout_Wrapper::operator[](size_t index) const {
  EquipmentLayout_View view(*this);

  return view[index];
}

EquipmentLayout_Wrapper EquipmentLayout_Wrapper::operator[](size_t index) {
  return ::D2_EquipmentLayout_Access(this->Get(), index);
}

EquipmentLayout_Wrapper::operator EquipmentLayout_View() const {
  return EquipmentLayout_View(this->Get());
}

EquipmentLayout* EquipmentLayout_Wrapper::Get() {
  const EquipmentLayout_Wrapper* const_this = this;

  return const_cast<EquipmentLayout*>(const_this->Get());
}

const EquipmentLayout* EquipmentLayout_Wrapper::Get() const {
  return reinterpret_cast<const EquipmentLayout*>(
      this->equipment_layout_.v1_00
  );
}

void EquipmentLayout_Wrapper::AssignMembers(EquipmentLayout_View src) {
  ::D2_EquipmentLayout_AssignMembers(this->Get(), src.Get());
}

PositionalRectangle_View EquipmentLayout_Wrapper::GetPosition() const {
  EquipmentLayout_View view(*this);

  return view.GetPosition();
}

PositionalRectangle_Wrapper EquipmentLayout_Wrapper::GetPosition() {
  return PositionalRectangle_Wrapper(
      ::D2_EquipmentLayout_GetPosition(this->Get())
  );
}

unsigned char EquipmentLayout_Wrapper::GetWidth() const {
  EquipmentLayout_View view(*this);

  return view.GetWidth();
}

void EquipmentLayout_Wrapper::SetWidth(unsigned char width) {
  ::D2_EquipmentLayout_SetWidth(this->Get(), width);
}

unsigned char EquipmentLayout_Wrapper::GetHeight() const {
  EquipmentLayout_View view(*this);

  return view.GetHeight();
}

void EquipmentLayout_Wrapper::SetHeight(unsigned char height) {
  ::D2_EquipmentLayout_SetHeight(this->Get(), height);
}

} // namespace d2
