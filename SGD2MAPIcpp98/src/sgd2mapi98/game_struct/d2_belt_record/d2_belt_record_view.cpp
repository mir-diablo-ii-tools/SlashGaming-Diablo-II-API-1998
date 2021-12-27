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

#include "../../../../include/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_view.hpp"

namespace d2 {

BeltRecord_View::BeltRecord_View(
    const BeltRecord* belt_record
) {
  this->belt_record_.v1_00 =
      reinterpret_cast<const BeltRecord_1_00*>(
          belt_record
      );
}

BeltRecord_View::BeltRecord_View(
    const BeltRecord_1_00* belt_record
) {
  this->belt_record_.v1_00 = belt_record;
}

BeltRecord_View BeltRecord_View::operator[](
    size_t index
) const {
  return ::D2_BeltRecord_AccessConst(this->Get(), index);
}

const BeltRecord* BeltRecord_View::Get() const {
  return reinterpret_cast<const BeltRecord*>(
      this->belt_record_.v1_00
  );
}

unsigned char BeltRecord_View::GetNumSlots() const {
  return this->belt_record_.v1_00->num_slots;
}

PositionalRectangle_View BeltRecord_View::GetSlotPositions() const {
  return PositionalRectangle_View(this->belt_record_.v1_00->slot_positions);
}

} // namespace d2