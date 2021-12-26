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

#include "../../../../include/sgd2mapi98/game_variable/d2client/d2client_difficulty_level.hpp"

#include <sgd2mapi.h>

namespace d2 {
namespace d2client {

DifficultyLevel GetDifficultyLevel() {
  return static_cast<DifficultyLevel>(::D2_D2Client_GetDifficultyLevel());
}

DifficultyLevel_1_00 GetDifficultyLevel_1_00() {
  return static_cast<DifficultyLevel_1_00>(
      ::D2_D2Client_GetDifficultyLevel_1_00()
  );
}

void SetDifficultyLevel(
    DifficultyLevel difficulty_level
) {
  ::D2_D2Client_SetDifficultyLevel(
      static_cast< ::D2_DifficultyLevel>(difficulty_level)
  );
}

void SetDifficultyLevel_1_00(
    DifficultyLevel_1_00 difficulty_level
) {
  ::D2_D2Client_SetDifficultyLevel_1_00(difficulty_level);
}

} // namespace d2client
} // namespace d2
