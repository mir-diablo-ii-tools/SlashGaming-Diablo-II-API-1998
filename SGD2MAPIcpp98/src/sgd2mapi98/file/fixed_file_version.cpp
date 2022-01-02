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

#include "../../../include/sgd2mapi98/file/fixed_file_version.hpp"

namespace mapi {

FixedFileVersion::FixedFileVersion()
    : fixed_file_version_(::Mapi_FixedFileVersion_kUninit) {
}

FixedFileVersion::FixedFileVersion(
    WORD major_high,
    WORD major_low,
    WORD minor_high,
    WORD minor_low
)
    : fixed_file_version_(
          Mapi_FixedFileVersion_InitFromVersion(
              major_high,
              major_low,
              minor_high,
              minor_low
          )
      ) {
}

FixedFileVersion::~FixedFileVersion() {
  ::Mapi_FixedFileVersion_Deinit(&this->fixed_file_version_);
}

bool operator==(const FixedFileVersion& lhs, const FixedFileVersion& rhs) {
  const ::Mapi_FixedFileVersion& actual_lhs = lhs.fixed_file_version_;
  const ::Mapi_FixedFileVersion& actual_rhs = rhs.fixed_file_version_;

  return (actual_lhs.major_high == actual_rhs.major_high)
      && (actual_lhs.major_low == actual_rhs.major_low)
      && (actual_lhs.minor_high == actual_rhs.minor_high)
      && (actual_lhs.minor_low == actual_rhs.minor_low);
}

bool operator<(const FixedFileVersion& lhs, const FixedFileVersion& rhs) {
  const ::Mapi_FixedFileVersion& actual_lhs = lhs.fixed_file_version_;
  const ::Mapi_FixedFileVersion& actual_rhs = rhs.fixed_file_version_;

  return (actual_lhs.major_high < actual_rhs.major_high)
      && (actual_lhs.major_low < actual_rhs.major_low)
      && (actual_lhs.minor_high < actual_rhs.minor_high)
      && (actual_lhs.minor_low < actual_rhs.minor_low);
}

uint_least64_t FixedFileVersion::ToValue() const {
  return ::Mapi_FixedFileVersion_ToValue(&this->fixed_file_version_);
}

} // namespace mapi
