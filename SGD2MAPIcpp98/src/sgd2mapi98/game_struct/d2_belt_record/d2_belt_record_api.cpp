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

#include "../../../../include/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_api.hpp"

namespace d2 {

BeltRecord_Api::BeltRecord_Api() {
}

BeltRecord_Api::BeltRecord_Api(
    ::mapi::Undefined* reserved_00__set_to_NULL,
    unsigned char num_slots,
    const PositionalRectangle* slot_positions
)
    : belt_record_(
          ::D2_BeltRecord_Api_InitFromRecord(
              reserved_00__set_to_NULL,
              num_slots,
              slot_positions
          )
      ) {
}

BeltRecord_Api::~BeltRecord_Api() {
  ::D2_BeltRecord_Api_Deinit(&this->belt_record_);
}

BeltRecord_Api::operator BeltRecord_View() const {
  return BeltRecord_View(this->Get());
}

BeltRecord_Api::operator BeltRecord_Wrapper() {
  return BeltRecord_Wrapper(this->Get());
}

BeltRecord* BeltRecord_Api::Get() {
  const BeltRecord_Api* const_this = this;

  return const_cast<BeltRecord*>(const_this->Get());
}

const BeltRecord* BeltRecord_Api::Get() const {
  return ::D2_BeltRecord_Api_GetConst(&this->belt_record_);
}

void BeltRecord_Api::AssignMembers(
    BeltRecord_View src
) {
  BeltRecord_Wrapper wrapper(*this);

  wrapper.AssignMembers(src);
}

unsigned char BeltRecord_Api::GetNumSlots() const {
  BeltRecord_View view(*this);

  return view.GetNumSlots();
}

void BeltRecord_Api::SetNumSlots(unsigned char num_slots) {
  BeltRecord_Wrapper wrapper(*this);

  wrapper.SetNumSlots(num_slots);
}

PositionalRectangle_View BeltRecord_Api::GetSlotPositions() const {
  BeltRecord_View view(*this);

  return view.GetSlotPositions();
}

PositionalRectangle_Wrapper BeltRecord_Api::GetSlotPositions() {
  BeltRecord_Wrapper wrapper(*this);

  return wrapper.GetSlotPositions();
}

} // namespace d2
