/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "../../../include/sgd2mapi98/game_constant/d2_draw_effect.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../include/sgd2mapi98/game_version.h"

int D2_DrawEffect_ToGameValue(enum D2_DrawEffect api_value) {
  return D2_DrawEffect_ToGameValue_1_00(api_value);
}

enum D2_DrawEffect_1_00 D2_DrawEffect_ToGameValue_1_00(
    enum D2_DrawEffect api_value
) {
  switch (api_value) {
    case D2_DrawEffect_kOneFourthOpaque: {
      return D2_DrawEffect_1_00_kOneFourthOpaque;
    }

    case D2_DrawEffect_kHalfOpaque: {
      return D2_DrawEffect_1_00_kHalfOpaque;
    }

    case D2_DrawEffect_kThreeFourthsOpaque: {
      return D2_DrawEffect_1_00_kThreeFourthsOpaque;
    }

    case D2_DrawEffect_kUnknown03: {
      return D2_DrawEffect_1_00_kUnknown03;
    }

    case D2_DrawEffect_kUnknown04: {
      return D2_DrawEffect_1_00_kUnknown04;
    }

    case D2_DrawEffect_kNone: {
      return D2_DrawEffect_1_00_kNone;
    }

    case D2_DrawEffect_kUnknown06: {
      return D2_DrawEffect_1_00_kUnknown06;
    }

    case D2_DrawEffect_kUnknown07: {
      return D2_DrawEffect_1_00_kUnknown07;
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

enum D2_DrawEffect D2_DrawEffect_ToApiValue(int game_value) {
  return D2_DrawEffect_ToApiValue_1_00(game_value);
}

enum D2_DrawEffect D2_DrawEffect_ToApiValue_1_00(
    enum D2_DrawEffect_1_00 game_value
) {
  switch (game_value) {
    case D2_DrawEffect_1_00_kOneFourthOpaque: {
      return D2_DrawEffect_kOneFourthOpaque;
    }

    case D2_DrawEffect_1_00_kHalfOpaque: {
      return D2_DrawEffect_kHalfOpaque;
    }

    case D2_DrawEffect_1_00_kThreeFourthsOpaque: {
      return D2_DrawEffect_kThreeFourthsOpaque;
    }

    case D2_DrawEffect_1_00_kUnknown03: {
      return D2_DrawEffect_kUnknown03;
    }

    case D2_DrawEffect_1_00_kUnknown04: {
      return D2_DrawEffect_kUnknown04;
    }

    case D2_DrawEffect_1_00_kNone: {
      return D2_DrawEffect_kNone;
    }

    case D2_DrawEffect_1_00_kUnknown06: {
      return D2_DrawEffect_kUnknown06;
    }

    case D2_DrawEffect_1_00_kUnknown07: {
      return D2_DrawEffect_kUnknown07;
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
