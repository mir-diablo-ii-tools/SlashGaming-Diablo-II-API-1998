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

#include "../../../../include/cxx98/game_struct/d2_inventory_record/d2_inventory_record_wrapper.hpp"

namespace d2 {

InventoryRecord_Wrapper::InventoryRecord_Wrapper(
    InventoryRecord* inventory_record
) {
  this->inventory_record_.v1_00 = reinterpret_cast<InventoryRecord_1_00*>(
      inventory_record
  );
}

InventoryRecord_Wrapper::InventoryRecord_Wrapper(
    InventoryRecord_1_00* inventory_record
) {
  this->inventory_record_.v1_00 = inventory_record;
}

InventoryRecord_View InventoryRecord_Wrapper::operator[](
    size_t index
) const {
  InventoryRecord_View view(*this);

  return view[index];
}

InventoryRecord_Wrapper InventoryRecord_Wrapper::operator[](
    size_t index
) {
  return ::D2_InventoryRecord_Access(this->Get(), index);
}

InventoryRecord_Wrapper::operator InventoryRecord_View() const {
  return InventoryRecord_View(this->Get());
}

InventoryRecord* InventoryRecord_Wrapper::Get() {
  const InventoryRecord_Wrapper* const_this = this;

  return const_cast<InventoryRecord*>(const_this->Get());
}

const InventoryRecord* InventoryRecord_Wrapper::Get() const {
  return reinterpret_cast<const InventoryRecord*>(
      this->inventory_record_.v1_00
  );
}

void InventoryRecord_Wrapper::AssignMembers(InventoryRecord_View src) {
  ::D2_InventoryRecord_AssignMembers(this->Get(), src.Get());
}

PositionalRectangle_View InventoryRecord_Wrapper::GetPosition() const {
  InventoryRecord_View view(*this);

  return view.GetPosition();
}

PositionalRectangle_Wrapper InventoryRecord_Wrapper::GetPosition() {
  return PositionalRectangle_Wrapper(
      ::D2_InventoryRecord_GetPosition(this->Get())
  );
}

GridLayout_View InventoryRecord_Wrapper::GetGridLayout() const {
  InventoryRecord_View view(*this);

  return view.GetGridLayout();
}

GridLayout_Wrapper InventoryRecord_Wrapper::GetGridLayout() {
  return GridLayout_Wrapper(
      ::D2_InventoryRecord_GetGridLayout(this->Get())
  );
}

EquipmentLayout_View InventoryRecord_Wrapper::GetEquipmentSlots() const {
  InventoryRecord_View view(*this);

  return view.GetEquipmentSlots();
}

EquipmentLayout_Wrapper InventoryRecord_Wrapper::GetEquipmentSlots() {
  return EquipmentLayout_Wrapper(
      ::D2_InventoryRecord_GetEquipmentSlots(this->Get())
  );
}

} // namespace d2
