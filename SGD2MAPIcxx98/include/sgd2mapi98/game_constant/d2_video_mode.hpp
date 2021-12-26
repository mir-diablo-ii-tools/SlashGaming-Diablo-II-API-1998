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

#include <sgd2mapi98.h>

#include "../../dllexport_define.inc"

namespace d2 {
namespace video_mode {

/*
* These internal enums is not intended for direct public use. It is
* stricly defined here to prevent enum leak to namespace. Use the
* typedefs in the upper-level namespace instead.
*/

namespace api {

enum VideoMode {
  kGdi = D2_VideoMode_kGdi,
  kSoftware = D2_VideoMode_kSoftware,
  kDirectDraw = D2_VideoMode_kDirectDraw,
  kGlide = D2_VideoMode_kGlide,
  kOpenGl = D2_VideoMode_kOpenGl,
  kDirect3D = D2_VideoMode_kDirect3D,
  kRave = D2_VideoMode_kRave,
};

} // namespace api

namespace v1_00 {

enum VideoMode_1_00 {
  kGdi = D2_VideoMode_1_00_kGdi,
  kSoftware = D2_VideoMode_1_00_kSoftware,
  kDirectDraw = D2_VideoMode_1_00_kDirectDraw,
  kGlide = D2_VideoMode_1_00_kGlide,
  kOpenGl = D2_VideoMode_1_00_kOpenGl,
  kDirect3D = D2_VideoMode_1_00_kDirect3D,
  kRave = D2_VideoMode_1_00_kRave,
};

} // namespace v1_00

} // namespace video_mode

/**
 * Generic enum definitions
 */

typedef video_mode::api::VideoMode VideoMode;

/**
 * Version-specific enum definitions
 */

typedef video_mode::v1_00::VideoMode_1_00 VideoMode_1_00;

/**
 * Function declarations
 */

namespace video_mode {

DLLEXPORT int ToGameValue(VideoMode api_value);

DLLEXPORT VideoMode_1_00 ToGameValue_1_00(VideoMode api_value);

DLLEXPORT VideoMode ToApiValue(int game_value);

DLLEXPORT VideoMode ToApiValue_1_00(VideoMode_1_00 game_value);

} // namespace video_mode
} // namespace d2

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_VIDEO_MODE_HPP_ */
