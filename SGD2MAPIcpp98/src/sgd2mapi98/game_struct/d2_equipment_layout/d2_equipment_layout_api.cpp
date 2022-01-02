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

#include "../../../../include/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_api.hpp"

namespace d2 {

EquipmentLayout_Api::EquipmentLayout_Api() {
}

EquipmentLayout_Api::EquipmentLayout_Api(
    const PositionalRectangle* position,
    unsigned char width,
    unsigned char height
)
    : equipment_layout_(
          ::D2_EquipmentLayout_Api_InitFromLayout(
              position,
              width,
              height
          )
      ) {
}

EquipmentLayout_Api::~EquipmentLayout_Api() {
  ::D2_EquipmentLayout_Api_Deinit(&this->equipment_layout_);
}

EquipmentLayout_Api::operator EquipmentLayout_View() const {
  return EquipmentLayout_View(this->Get());
}

EquipmentLayout_Api::operator EquipmentLayout_Wrapper() {
  return EquipmentLayout_Wrapper(this->Get());
}

EquipmentLayout* EquipmentLayout_Api::Get() {
  const EquipmentLayout_Api* const_this = this;

  return const_cast<EquipmentLayout*>(const_this->Get());
}

const EquipmentLayout* EquipmentLayout_Api::Get() const {
  return ::D2_EquipmentLayout_Api_GetConst(&this->equipment_layout_);
}

void EquipmentLayout_Api::AssignMembers(EquipmentLayout_View src) {
  EquipmentLayout_Wrapper wrapper(*this);

  wrapper.AssignMembers(src);
}

PositionalRectangle_View EquipmentLayout_Api::GetPosition() const {
  EquipmentLayout_View view(*this);

  return view.GetPosition();
}

PositionalRectangle_Wrapper EquipmentLayout_Api::GetPosition() {
  EquipmentLayout_Wrapper wrapper(*this);

  return wrapper.GetPosition();
}

unsigned char EquipmentLayout_Api::GetWidth() const {
  EquipmentLayout_View view(*this);

  return view.GetWidth();
}

void EquipmentLayout_Api::SetWidth(unsigned char width) {
  EquipmentLayout_Wrapper wrapper(*this);

  wrapper.SetWidth(width);
}

unsigned char EquipmentLayout_Api::GetHeight() const {
  EquipmentLayout_View view(*this);

  return view.GetHeight();
}

void EquipmentLayout_Api::SetHeight(unsigned char height) {
  EquipmentLayout_Wrapper wrapper(*this);

  wrapper.SetHeight(height);
}

} // namespace d2
