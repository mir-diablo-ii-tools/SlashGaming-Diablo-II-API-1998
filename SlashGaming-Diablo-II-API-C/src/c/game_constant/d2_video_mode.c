/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C.
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

#include "../../../include/c/game_constant/d2_video_mode.h"

#include "../../../include/c/game_version.h"
#include "../../wide_macro.h"
#include "../backend/error_handling.h"

enum D2_VideoMode_1_00 D2_VideoMode_ToGameValue_1_00(
    enum D2_VideoMode api_value
) {
  switch (api_value) {
    case VIDEO_MODE_GDI: {
      return VIDEO_MODE_1_00_GDI;
    }

    case VIDEO_MODE_SOFTWARE: {
      return VIDEO_MODE_1_00_SOFTWARE;
    }

    case VIDEO_MODE_DIRECT_DRAW: {
      return VIDEO_MODE_1_00_DIRECT_DRAW;
    }

    case VIDEO_MODE_GLIDE: {
      return VIDEO_MODE_1_00_GLIDE;
    }

    case VIDEO_MODE_OPENGL: {
      return VIDEO_MODE_1_00_OPENGL;
    }

    case VIDEO_MODE_DIRECT3D: {
      return VIDEO_MODE_1_00_DIRECT3D;
    }

    case VIDEO_MODE_RAVE: {
      return VIDEO_MODE_1_00_RAVE;
    }

    default: {
      ExitOnConstantMappingMissing(
          api_value,
          __FILEW__,
          __LINE__
      );

      return 0;
    }
  }
}

enum D2_VideoMode D2_VideoMode_ToApiValue_1_00(
    enum D2_VideoMode_1_00 game_value
) {
  switch (game_value) {
    case VIDEO_MODE_1_00_GDI: {
      return VIDEO_MODE_GDI;
    }

    case VIDEO_MODE_1_00_SOFTWARE: {
      return VIDEO_MODE_SOFTWARE;
    }

    case VIDEO_MODE_1_00_DIRECT_DRAW: {
      return VIDEO_MODE_DIRECT_DRAW;
    }

    case VIDEO_MODE_1_00_GLIDE: {
      return VIDEO_MODE_GLIDE;
    }

    case VIDEO_MODE_1_00_OPENGL: {
      return VIDEO_MODE_OPENGL;
    }

    case VIDEO_MODE_1_00_DIRECT3D: {
      return VIDEO_MODE_DIRECT3D;
    }

    case VIDEO_MODE_1_00_RAVE: {
      return VIDEO_MODE_RAVE;
    }

    default: {
      ExitOnConstantMappingMissing(
          game_value,
          __FILEW__,
          __LINE__
      );

      return 0;
    }
  }
}

int D2_VideoMode_ToGameValue(enum D2_VideoMode api_value) {
  return D2_VideoMode_ToGameValue_1_00(api_value);
}

enum D2_VideoMode D2_VideoMode_ToApiValue(int game_value) {
  return D2_VideoMode_ToApiValue_1_00(game_value);
}
