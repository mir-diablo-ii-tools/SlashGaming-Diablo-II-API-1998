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

#include "../../../include/c/game_constant/d2_text_color.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../include/c/game_version.h"

int D2_TextColor_ToGameValue(enum D2_TextColor api_value) {
  return D2_TextColor_ToGameValue_1_00(api_value);
}

enum D2_TextColor_1_00 D2_TextColor_ToGameValue_1_00(
    enum D2_TextColor api_value
) {
  switch (api_value) {
    case D2_TextColor_kWhite: {
      return D2_TextColor_1_00_kWhite;
    }

    case D2_TextColor_kRed: {
      return D2_TextColor_1_00_kRed;
    }

    case D2_TextColor_kGreen: {
      return D2_TextColor_1_00_kGreen;
    }

    case D2_TextColor_kBlue: {
      return D2_TextColor_1_00_kBlue;
    }

    case D2_TextColor_kGold: {
      return D2_TextColor_1_00_kGold;
    }

    case D2_TextColor_kDarkGrey: {
      return D2_TextColor_1_00_kDarkGrey;
    }

    case D2_TextColor_kBlack: {
      return D2_TextColor_1_00_kBlack;
    }

    case D2_TextColor_kTan: {
      return D2_TextColor_1_00_kTan;
    }

    case D2_TextColor_kOrange: {
      return D2_TextColor_1_00_kOrange;
    }

    case D2_TextColor_kYellow: {
      return D2_TextColor_1_00_kYellow;
    }

    case D2_TextColor_kDarkerGreen: {
      return D2_TextColor_1_00_kDarkerGreen;
    }

    case D2_TextColor_kPurple: {
      return D2_TextColor_1_00_kPurple;
    }

    case D2_TextColor_kDarkGreen: {
      return D2_TextColor_1_00_kDarkGreen;
    }

    case D2_TextColor_kMetallic: {
      return D2_TextColor_1_00_kMetallic;
    }

    case D2_TextColor_kLightGrey: {
      return D2_TextColor_1_00_kLightGrey;
    }

    case D2_TextColor_kCorrupt: {
      return D2_TextColor_1_00_kCorrupt;
    }

    case D2_TextColor_kBrightWhite: {
      return D2_TextColor_1_00_kBrightWhite;
    }

    case D2_TextColor_kDarkRed: {
      return D2_TextColor_1_00_kDarkRed;
    }

    case D2_TextColor_kBrown: {
      return D2_TextColor_1_00_kBrown;
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

enum D2_TextColor D2_TextColor_ToApiValue(int game_value) {
  return D2_TextColor_ToApiValue_1_00(game_value);
}

enum D2_TextColor D2_TextColor_ToApiValue_1_00(
    enum D2_TextColor_1_00 game_value
) {
  switch (game_value) {
    case D2_TextColor_1_00_kWhite: {
      return D2_TextColor_kWhite;
    }

    case D2_TextColor_1_00_kRed: {
      return D2_TextColor_kRed;
    }

    case D2_TextColor_1_00_kGreen: {
      return D2_TextColor_kGreen;
    }

    case D2_TextColor_1_00_kBlue: {
      return D2_TextColor_kBlue;
    }

    case D2_TextColor_1_00_kGold: {
      return D2_TextColor_kGold;
    }

    case D2_TextColor_1_00_kDarkGrey: {
      return D2_TextColor_kDarkGrey;
    }

    case D2_TextColor_1_00_kBlack: {
      return D2_TextColor_kBlack;
    }

    case D2_TextColor_1_00_kTan: {
      return D2_TextColor_kTan;
    }

    case D2_TextColor_1_00_kOrange: {
      return D2_TextColor_kOrange;
    }

    case D2_TextColor_1_00_kYellow: {
      return D2_TextColor_kYellow;
    }

    case D2_TextColor_1_00_kDarkerGreen: {
      return D2_TextColor_kDarkerGreen;
    }

    case D2_TextColor_1_00_kPurple: {
      return D2_TextColor_kPurple;
    }

    case D2_TextColor_1_00_kDarkGreen: {
      return D2_TextColor_kDarkGreen;
    }

    case 13: {
      return D2_TextColor_kWhite;
    }

    case 14: {
      return D2_TextColor_kBlack;
    }

    case D2_TextColor_1_00_kMetallic: {
      return D2_TextColor_kMetallic;
    }

    case D2_TextColor_1_00_kLightGrey: {
      return D2_TextColor_kLightGrey;
    }

    case D2_TextColor_1_00_kCorrupt: {
      return D2_TextColor_kCorrupt;
    }

    case D2_TextColor_1_00_kBrightWhite: {
      return D2_TextColor_kBrightWhite;
    }

    case D2_TextColor_1_00_kDarkRed: {
      return D2_TextColor_kDarkRed;
    }

    case D2_TextColor_1_00_kBrown: {
      return D2_TextColor_kBrown;
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
