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

#ifndef SGD2MAPI_CXX98_GAME_CONSTANT_D2_DIFFICULTY_LEVEL_HPP_
#define SGD2MAPI_CXX98_GAME_CONSTANT_D2_DIFFICULTY_LEVEL_HPP_

#include <sgd2mapi.h>

namespace d2 {

/**
 * Generic enum definitions
 */

enum DifficultyLevel {
  DifficultyLevel_kNormal = D2_DifficultyLevel_kNormal,
  DifficultyLevel_kNightmare = D2_DifficultyLevel_kNightmare,
  DifficultyLevel_kHell = D2_DifficultyLevel_kHell,
};

/**
 * Version-specific enum definitions
 */

enum DifficultyLevel_1_00 {
  DifficultyLevel_1_00_kNormal = D2_DifficultyLevel_1_00_kNormal,
  DifficultyLevel_1_00_kNightmare = D2_DifficultyLevel_1_00_kNightmare,
  DifficultyLevel_1_00_kHell = D2_DifficultyLevel_1_00_kHell,
};

/**
 * Function declarations
 */

int DifficultyLevel_ToGameValue(
    DifficultyLevel api_value
) {
  return D2_DifficultyLevel_ToGameValue(
      static_cast<D2_DifficultyLevel>(api_value)
  );
}

DifficultyLevel_1_00 DifficultyLevel_ToGameValue_1_00(
    DifficultyLevel api_value
) {
  D2_DifficultyLevel_1_00 actual_game_value =
      D2_DifficultyLevel_ToGameValue_1_00(
          static_cast<D2_DifficultyLevel>(api_value)
      );

  return static_cast<DifficultyLevel_1_00>(actual_game_value);
}

DifficultyLevel DifficultyLevel_ToApiValue(
    int game_value
) {
  return static_cast<DifficultyLevel>(
      D2_DifficultyLevel_ToApiValue(game_value)
  );
}

DifficultyLevel DifficultyLevel_ToApiValue_1_00(
    DifficultyLevel_1_00 game_value
) {
  D2_DifficultyLevel actual_api_value =
      D2_DifficultyLevel_ToApiValue_1_00(
          static_cast<D2_DifficultyLevel_1_00>(game_value)
      );

  return static_cast<DifficultyLevel>(actual_api_value);
}

} // namespace d2

#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_DIFFICULTY_LEVEL_HPP_ */
