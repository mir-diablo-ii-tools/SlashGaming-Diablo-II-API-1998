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

#ifndef SGD2MAPI_CXX98_GAME_CONSTANT_D2_SCREEN_OPEN_MODE_HPP_
#define SGD2MAPI_CXX98_GAME_CONSTANT_D2_SCREEN_OPEN_MODE_HPP_

#include <sgd2mapi.h>

namespace d2 {

/**
 * Generic enum definitions
 */

enum ScreenOpenMode {
  ScreenOpenMode_kNone = D2_ScreenOpenMode_kNone,
  ScreenOpenMode_kRight = D2_ScreenOpenMode_kRight,
  ScreenOpenMode_kLeft = D2_ScreenOpenMode_kLeft,
  ScreenOpenMode_kBoth = D2_ScreenOpenMode_kBoth,
};

/**
 * Version-specific enum definitions
 */

enum ScreenOpenMode_1_07 {
  ScreenOpenMode_1_07_kNone = D2_ScreenOpenMode_1_07_kNone,
  ScreenOpenMode_1_07_kRight = D2_ScreenOpenMode_1_07_kRight,
  ScreenOpenMode_1_07_kLeft = D2_ScreenOpenMode_1_07_kLeft,
  ScreenOpenMode_1_07_kBoth = D2_ScreenOpenMode_1_07_kBoth,
};

/**
 * Function declarations
 */

int ScreenOpenMode_ToGameValue(
    ScreenOpenMode api_value
) {
  return D2_ScreenOpenMode_ToGameValue(
      static_cast<D2_ScreenOpenMode>(api_value)
  );
}

ScreenOpenMode_1_07 ScreenOpenMode_ToGameValue_1_07(
    ScreenOpenMode api_value
) {
  D2_ScreenOpenMode_1_07 actual_game_value =
      D2_ScreenOpenMode_ToGameValue_1_07(
          static_cast<D2_ScreenOpenMode>(api_value)
      );

  return static_cast<ScreenOpenMode_1_07>(actual_game_value);
}

ScreenOpenMode ScreenOpenMode_ToApiValue(
    int game_value
) {
  return static_cast<ScreenOpenMode>(
      D2_ScreenOpenMode_ToApiValue(game_value)
  );
}

ScreenOpenMode ScreenOpenMode_ToApiValue_1_07(
    ScreenOpenMode_1_07 game_value
) {
  D2_ScreenOpenMode actual_api_value =
      D2_ScreenOpenMode_ToApiValue_1_07(
          static_cast<D2_ScreenOpenMode_1_07>(game_value)
      );

  return static_cast<ScreenOpenMode>(actual_api_value);
}

} // namespace d2

#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_SCREEN_OPEN_MODE_HPP_ */
