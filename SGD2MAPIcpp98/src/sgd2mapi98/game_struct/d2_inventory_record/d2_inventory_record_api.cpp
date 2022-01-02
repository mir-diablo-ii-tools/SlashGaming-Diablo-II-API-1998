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

#include "../../../../include/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_api.hpp"

namespace d2 {

InventoryRecord_Api::InventoryRecord_Api() {
}

InventoryRecord_Api::InventoryRecord_Api(
      const PositionalRectangle* position,
      const GridLayout* grid_layout,
      const EquipmentLayout* equipment_slots
)
    : inventory_record_(
          ::D2_InventoryRecord_Api_InitFromRecord(
              position,
              grid_layout,
              equipment_slots
          )
      ) {
}

InventoryRecord_Api::~InventoryRecord_Api() {
  ::D2_InventoryRecord_Api_Deinit(&this->inventory_record_);
}

InventoryRecord_Api::operator InventoryRecord_View() const {
  return InventoryRecord_View(this->Get());
}

InventoryRecord_Api::operator InventoryRecord_Wrapper() {
  return InventoryRecord_Wrapper(this->Get());
}

InventoryRecord* InventoryRecord_Api::Get() {
  const InventoryRecord_Api* const_this = this;

  return const_cast<InventoryRecord*>(const_this->Get());
}

const InventoryRecord* InventoryRecord_Api::Get() const {
  return ::D2_InventoryRecord_Api_GetConst(&this->inventory_record_);
}

void InventoryRecord_Api::AssignMembers(InventoryRecord_View src) {
  InventoryRecord_Wrapper wrapper(*this);

  wrapper.AssignMembers(src.Get());
}

PositionalRectangle_View InventoryRecord_Api::GetPosition() const {
  InventoryRecord_View view(*this);

  return view.GetPosition();
}

PositionalRectangle_Wrapper InventoryRecord_Api::GetPosition() {
  InventoryRecord_Wrapper wrapper(*this);

  return wrapper.GetPosition();
}

GridLayout_View InventoryRecord_Api::GetGridLayout() const {
  InventoryRecord_View view(*this);

  return view.GetGridLayout();
}

GridLayout_Wrapper InventoryRecord_Api::GetGridLayout() {
  InventoryRecord_Wrapper wrapper(*this);

  return wrapper.GetGridLayout();
}

EquipmentLayout_View InventoryRecord_Api::GetEquipmentSlots() const {
  InventoryRecord_View view(*this);

  return view.GetEquipmentSlots();
}

EquipmentLayout_Wrapper InventoryRecord_Api::GetEquipmentSlots() {
  InventoryRecord_Wrapper wrapper(*this);

  return wrapper.GetEquipmentSlots();
}

} // namespace d2
