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

#include "../../../include/c/game_constant/d2_text_font.h"

#include "../../../include/c/game_version.h"
#include "../../wide_macro.h"
#include "../backend/encoding.h"
#include "../backend/error_handling.h"

enum D2_TextFont_1_00 D2_TextFont_ToGameValue_1_00(
    enum D2_TextFont api_value
) {
  switch (api_value) {
    case TEXT_FONT_DIABLO_MENU_24: {
      return TEXT_FONT_1_00_DIABLO_MENU_24;
    }

    case TEXT_FONT_DIABLO_MENU_30: {
      return TEXT_FONT_1_00_DIABLO_MENU_30;
    }

    case TEXT_FONT_DIABLO_MENU_42: {
      return TEXT_FONT_1_00_DIABLO_MENU_42;
    }

    case TEXT_FONT_EXOCET_8: {
      return TEXT_FONT_1_00_EXOCET_8;
    }

    case TEXT_FONT_EXOCET_16: {
      return TEXT_FONT_1_00_EXOCET_16;
    }

    case TEXT_FONT_EXOCET_BLACK_9: {
      return TEXT_FONT_1_00_EXOCET_BLACK_9;
    }

    case TEXT_FONT_EXOCET_BLACK_10: {
      return TEXT_FONT_1_00_EXOCET_BLACK_10;
    }

    case TEXT_FONT_FORMAL_6: {
      return TEXT_FONT_1_00_FORMAL_6;
    }

    case TEXT_FONT_FORMAL_8: {
      return TEXT_FONT_1_00_FORMAL_8;
    }

    case TEXT_FONT_FORMAL_10: {
      return TEXT_FONT_1_00_FORMAL_10;
    }

    case TEXT_FONT_FORMAL_11: {
      return TEXT_FONT_1_00_FORMAL_11;
    }

    case TEXT_FONT_FORMAL_12: {
      return TEXT_FONT_1_00_FORMAL_12;
    }

    case TEXT_FONT_FORMAL_WIDE_11: {
      return TEXT_FONT_1_00_FORMAL_WIDE_11;
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

enum D2_TextFont D2_TextFont_ToApiValue_1_00(
    enum D2_TextFont_1_00 game_value
) {
  switch (game_value) {
    case TEXT_FONT_1_00_FORMAL_8: {
      return TEXT_FONT_FORMAL_8;
    }

    case TEXT_FONT_1_00_EXOCET_16: {
      return TEXT_FONT_EXOCET_16;
    }

    case TEXT_FONT_1_00_DIABLO_MENU_30: {
      return TEXT_FONT_DIABLO_MENU_30;
    }

    case TEXT_FONT_1_00_DIABLO_MENU_42: {
      return TEXT_FONT_DIABLO_MENU_42;
    }

    case TEXT_FONT_1_00_FORMAL_10: {
      return TEXT_FONT_FORMAL_10;
    }

    case TEXT_FONT_1_00_FORMAL_12: {
      return TEXT_FONT_FORMAL_12;
    }

    case TEXT_FONT_1_00_FORMAL_6: {
      return TEXT_FONT_FORMAL_6;
    }

    case TEXT_FONT_1_00_DIABLO_MENU_24: {
      return TEXT_FONT_DIABLO_MENU_24;
    }

    case TEXT_FONT_1_00_FORMAL_WIDE_11: {
      return TEXT_FONT_FORMAL_WIDE_11;
    }

    case TEXT_FONT_1_00_EXOCET_BLACK_10: {
      return TEXT_FONT_EXOCET_BLACK_10;
    }

    case TEXT_FONT_1_00_EXOCET_BLACK_9: {
      return TEXT_FONT_EXOCET_BLACK_9;
    }

    case TEXT_FONT_1_00_EXOCET_8: {
      return TEXT_FONT_EXOCET_8;
    }

    case 12: {
      return TEXT_FONT_FORMAL_6;
    }

    case TEXT_FONT_1_00_FORMAL_11: {
      return TEXT_FONT_FORMAL_11;
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

int D2_TextFont_ToGameValue(enum D2_TextFont api_value) {
  return D2_TextFont_ToGameValue_1_00(api_value);
}

enum D2_TextFont D2_TextFont_ToApiValue(int game_value) {
  return D2_TextFont_ToApiValue_1_00(game_value);
}
