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

#ifndef SGD2MAPI_CXX98_GAME_CONSTANT_D2_VIDEO_MODE_HPP_
#define SGD2MAPI_CXX98_GAME_CONSTANT_D2_VIDEO_MODE_HPP_

#include <sgd2mapi.h>

namespace d2 {

/**
 * Generic enum definitions
 */

enum VideoMode {
  VideoMode_kGdi = D2_VideoMode_kGdi,
  VideoMode_kSoftware = D2_VideoMode_kSoftware,
  VideoMode_kDirectDraw = D2_VideoMode_kDirectDraw,
  VideoMode_kGlide = D2_VideoMode_kGlide,
  VideoMode_kOpenGl = D2_VideoMode_kOpenGl,
  VideoMode_kDirect3D = D2_VideoMode_kDirect3D,
  VideoMode_kRave = D2_VideoMode_kRave,
};

/**
 * Version-specific enum definitions
 */

enum VideoMode_1_00 {
  VideoMode_1_00_kGdi = D2_VideoMode_1_00_kGdi,
  VideoMode_1_00_kSoftware = D2_VideoMode_1_00_kSoftware,
  VideoMode_1_00_kDirectDraw = D2_VideoMode_1_00_kDirectDraw,
  VideoMode_1_00_kGlide = D2_VideoMode_1_00_kGlide,
  VideoMode_1_00_kOpenGl = D2_VideoMode_1_00_kOpenGl,
  VideoMode_1_00_kDirect3D = D2_VideoMode_1_00_kDirect3D,
  VideoMode_1_00_kRave = D2_VideoMode_1_00_kRave,
};

/**
 * Function declarations
 */

int VideoMode_ToGameValue(VideoMode api_value) {
  return D2_VideoMode_ToGameValue(static_cast<D2_VideoMode>(api_value));
}

VideoMode_1_00 VideoMode_ToGameValue_1_00(
    VideoMode api_value
) {
  D2_VideoMode_1_00 actual_game_value = D2_VideoMode_ToGameValue_1_00(
      static_cast<D2_VideoMode>(api_value)
  );

  return static_cast<VideoMode_1_00>(actual_game_value);
}

VideoMode VideoMode_ToApiValue(int game_value) {
  return static_cast<VideoMode>(D2_VideoMode_ToApiValue(game_value));
}

VideoMode VideoMode_ToApiValue_1_00(
    VideoMode_1_00 game_value
) {
  D2_VideoMode actual_api_value = D2_VideoMode_ToApiValue_1_00(
      static_cast<D2_VideoMode_1_00>(game_value)
  );

  return static_cast<VideoMode>(actual_api_value);
}

} // namespace d2

#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_VIDEO_MODE_HPP_ */
