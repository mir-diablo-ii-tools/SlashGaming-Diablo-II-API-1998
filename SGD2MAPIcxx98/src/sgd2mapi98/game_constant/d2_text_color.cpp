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

#include "../../../include/sgd2mapi98/game_constant/d2_text_color.hpp"

namespace d2 {
namespace text_color {

int ToGameValue(TextColor api_value) {
  return ::D2_TextColor_ToGameValue(
      static_cast<D2_TextColor>(api_value)
  );
}

TextColor_1_00 ToGameValue_1_00(TextColor api_value) {
  ::D2_TextColor_1_00 c_game_value =
      ::D2_TextColor_ToGameValue_1_00(
          static_cast< ::D2_TextColor>(api_value)
      );

  return static_cast<TextColor_1_00>(c_game_value);
}

TextColor ToApiValue(int game_value) {
  ::D2_TextColor c_api_value = ::D2_TextColor_ToApiValue(
      game_value
  );

  return static_cast<TextColor>(c_api_value);
}

TextColor ToApiValue_1_00(TextColor_1_00 game_value) {
  ::D2_TextColor c_api_value = ::D2_TextColor_ToApiValue_1_00(
      static_cast< ::D2_TextColor_1_00>(game_value)
  );

  return static_cast<TextColor>(c_api_value);
}

} // namespace text_color
} // namespace d2
