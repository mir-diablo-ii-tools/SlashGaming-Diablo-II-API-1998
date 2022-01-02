/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../../include/sgd2mapi98/game_constant/d2_text_font.hpp"

namespace d2 {
namespace text_font {

int ToGameValue(TextFont api_value) {
  return ::D2_TextFont_ToGameValue(
      static_cast<D2_TextFont>(api_value)
  );
}

TextFont_1_00 ToGameValue_1_00(TextFont api_value) {
  ::D2_TextFont_1_00 c_game_value =
      ::D2_TextFont_ToGameValue_1_00(
          static_cast< ::D2_TextFont>(api_value)
      );

  return static_cast<TextFont_1_00>(c_game_value);
}

TextFont ToApiValue(int game_value) {
  ::D2_TextFont c_api_value = ::D2_TextFont_ToApiValue(
      game_value
  );

  return static_cast<TextFont>(c_api_value);
}

TextFont ToApiValue_1_00(TextFont_1_00 game_value) {
  ::D2_TextFont c_api_value = ::D2_TextFont_ToApiValue_1_00(
      static_cast< ::D2_TextFont_1_00>(game_value)
  );

  return static_cast<TextFont>(c_api_value);
}

} // namespace text_font
} // namespace d2
