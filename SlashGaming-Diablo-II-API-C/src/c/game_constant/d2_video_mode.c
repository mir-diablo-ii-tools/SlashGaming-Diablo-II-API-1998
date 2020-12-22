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

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../include/c/game_version.h"

int D2_VideoMode_ToGameValue(enum D2_VideoMode api_value) {
  return D2_VideoMode_ToGameValue_1_00(api_value);
}

enum D2_VideoMode_1_00 D2_VideoMode_ToGameValue_1_00(
    enum D2_VideoMode api_value
) {
  switch (api_value) {
    case D2_VideoMode_kGdi: {
      return D2_VideoMode_1_00_kGdi;
    }

    case D2_VideoMode_kSoftware: {
      return D2_VideoMode_1_00_kSoftware;
    }

    case D2_VideoMode_kDirectDraw: {
      return D2_VideoMode_1_00_kDirectDraw;
    }

    case D2_VideoMode_kGlide: {
      return D2_VideoMode_1_00_kGlide;
    }

    case D2_VideoMode_kOpenGl: {
      return D2_VideoMode_1_00_kOpenGl;
    }

    case D2_VideoMode_kDirect3D: {
      return D2_VideoMode_1_00_kDirect3D;
    }

    case D2_VideoMode_kRave: {
      return D2_VideoMode_1_00_kRave;
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          api_value
      );

      goto return_bad;
    }
  }

return_bad:
  return -1;
}

enum D2_VideoMode D2_VideoMode_ToApiValue(int game_value) {
  return D2_VideoMode_ToApiValue_1_00(game_value);
}

enum D2_VideoMode D2_VideoMode_ToApiValue_1_00(
    enum D2_VideoMode_1_00 game_value
) {
  switch (game_value) {
    case D2_VideoMode_1_00_kGdi: {
      return D2_VideoMode_kGdi;
    }

    case D2_VideoMode_1_00_kSoftware: {
      return D2_VideoMode_kSoftware;
    }

    case D2_VideoMode_1_00_kDirectDraw: {
      return D2_VideoMode_kDirectDraw;
    }

    case D2_VideoMode_1_00_kGlide: {
      return D2_VideoMode_kGlide;
    }

    case D2_VideoMode_1_00_kOpenGl: {
      return D2_VideoMode_kOpenGl;
    }

    case D2_VideoMode_1_00_kDirect3D: {
      return D2_VideoMode_kDirect3D;
    }

    case D2_VideoMode_1_00_kRave: {
      return D2_VideoMode_kRave;
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          game_value
      );

      goto return_bad;
    }
  }

return_bad:
  return -1;
}
