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

#include "../../../include/c/game_constant/d2_text_color.h"

#include "../../../include/c/game_version.h"

#include "../backend/encoding.h"
#include "../backend/error_handling.h"
#include "../../wide_macro.h"

static enum D2_TextColor_1_00 ToGameValue_1_00(
    enum D2_TextColor api_value
) {
  switch (api_value) {
    case TEXT_COLOR_WHITE: {
      return TEXT_COLOR_1_00_WHITE;
    }

    case TEXT_COLOR_RED: {
      return TEXT_COLOR_1_00_RED;
    }

    case TEXT_COLOR_GREEN: {
      return TEXT_COLOR_1_00_GREEN;
    }

    case TEXT_COLOR_BLUE: {
      return TEXT_COLOR_1_00_BLUE;
    }

    case TEXT_COLOR_GOLD: {
      return TEXT_COLOR_1_00_GOLD;
    }

    case TEXT_COLOR_DARK_GREY: {
      return TEXT_COLOR_1_00_DARK_GREY;
    }

    case TEXT_COLOR_BLACK: {
      return TEXT_COLOR_1_00_BLACK;
    }

    case TEXT_COLOR_TAN: {
      return TEXT_COLOR_1_00_TAN;
    }

    case TEXT_COLOR_ORANGE: {
      return TEXT_COLOR_1_00_ORANGE;
    }

    case TEXT_COLOR_YELLOW: {
      return TEXT_COLOR_1_00_YELLOW;
    }

    case TEXT_COLOR_DARKER_GREEN: {
      return TEXT_COLOR_1_00_DARKER_GREEN;
    }

    case TEXT_COLOR_PURPLE: {
      return TEXT_COLOR_1_00_PURPLE;
    }

    case TEXT_COLOR_DARK_GREEN: {
      return TEXT_COLOR_1_00_DARK_GREEN;
    }

    case TEXT_COLOR_METALLIC: {
      return TEXT_COLOR_1_00_METALLIC;
    }

    case TEXT_COLOR_LIGHT_GREY: {
      return TEXT_COLOR_1_00_LIGHT_GREY;
    }

    case TEXT_COLOR_CORRUPT: {
      return TEXT_COLOR_1_00_CORRUPT;
    }

    case TEXT_COLOR_BRIGHT_WHITE: {
      return TEXT_COLOR_1_00_BRIGHT_WHITE;
    }

    case TEXT_COLOR_DARK_RED: {
      return TEXT_COLOR_1_00_DARK_RED;
    }

    case TEXT_COLOR_BROWN: {
      return TEXT_COLOR_1_00_BROWN;
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

static enum D2_TextColor ToApiValue_1_00(
    enum D2_TextColor_1_00 game_value
) {
  switch (game_value) {
    case TEXT_COLOR_1_00_WHITE: {
      return TEXT_COLOR_WHITE;
    }

    case TEXT_COLOR_1_00_RED: {
      return TEXT_COLOR_RED;
    }

    case TEXT_COLOR_1_00_GREEN: {
      return TEXT_COLOR_GREEN;
    }

    case TEXT_COLOR_1_00_BLUE: {
      return TEXT_COLOR_BLUE;
    }

    case TEXT_COLOR_1_00_GOLD: {
      return TEXT_COLOR_GOLD;
    }

    case TEXT_COLOR_1_00_DARK_GREY: {
      return TEXT_COLOR_DARK_GREY;
    }

    case TEXT_COLOR_1_00_BLACK: {
      return TEXT_COLOR_BLACK;
    }

    case TEXT_COLOR_1_00_TAN: {
      return TEXT_COLOR_TAN;
    }

    case TEXT_COLOR_1_00_ORANGE: {
      return TEXT_COLOR_ORANGE;
    }

    case TEXT_COLOR_1_00_YELLOW: {
      return TEXT_COLOR_YELLOW;
    }

    case TEXT_COLOR_1_00_DARKER_GREEN: {
      return TEXT_COLOR_DARKER_GREEN;
    }

    case TEXT_COLOR_1_00_PURPLE: {
      return TEXT_COLOR_PURPLE;
    }

    case TEXT_COLOR_1_00_DARK_GREEN: {
      return TEXT_COLOR_DARK_GREEN;
    }

    case 13: {
      return TEXT_COLOR_WHITE;
    }

    case 14: {
      return TEXT_COLOR_BLACK;
    }

    case TEXT_COLOR_1_00_METALLIC: {
      return TEXT_COLOR_METALLIC;
    }

    case TEXT_COLOR_1_00_LIGHT_GREY: {
      return TEXT_COLOR_LIGHT_GREY;
    }

    case TEXT_COLOR_1_00_CORRUPT: {
      return TEXT_COLOR_CORRUPT;
    }

    case TEXT_COLOR_1_00_BRIGHT_WHITE: {
      return TEXT_COLOR_BRIGHT_WHITE;
    }

    case TEXT_COLOR_1_00_DARK_RED: {
      return TEXT_COLOR_DARK_RED;
    }

    case TEXT_COLOR_1_00_BROWN: {
      return TEXT_COLOR_BROWN;
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

int D2_TextColor_ToGameValue(enum D2_TextColor api_value) {
  return ToGameValue_1_00(api_value);
}

enum D2_TextColor D2_TextColor_ToApiValue(int game_value) {
  return ToApiValue_1_00(game_value);
}
