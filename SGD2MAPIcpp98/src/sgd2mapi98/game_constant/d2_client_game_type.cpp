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

#include "../../../include/sgd2mapi98/game_constant/d2_client_game_type.hpp"

namespace d2 {
namespace client_game_type {

int ToGameValue(ClientGameType api_value) {
  return ::D2_ClientGameType_ToGameValue(
      static_cast<D2_ClientGameType>(api_value)
  );
}

ClientGameType_1_00 ToGameValue_1_00(ClientGameType api_value) {
  ::D2_ClientGameType_1_00 c_game_value =
      ::D2_ClientGameType_ToGameValue_1_00(
          static_cast< ::D2_ClientGameType>(api_value)
      );

  return static_cast<ClientGameType_1_00>(c_game_value);
}

ClientGameType_1_07 ToGameValue_1_07(ClientGameType api_value) {
  ::D2_ClientGameType_1_07 c_game_value =
      ::D2_ClientGameType_ToGameValue_1_07(
          static_cast< ::D2_ClientGameType>(api_value)
      );

  return static_cast<ClientGameType_1_07>(c_game_value);
}

ClientGameType ToApiValue(int game_value) {
  ::D2_ClientGameType c_api_value = ::D2_ClientGameType_ToApiValue(
      game_value
  );

  return static_cast<ClientGameType>(c_api_value);
}

ClientGameType ToApiValue_1_00(ClientGameType_1_00 game_value) {
  ::D2_ClientGameType c_api_value = ::D2_ClientGameType_ToApiValue_1_00(
      static_cast< ::D2_ClientGameType_1_00>(game_value)
  );

  return static_cast<ClientGameType>(c_api_value);
}

ClientGameType ToApiValue_1_07(ClientGameType_1_07 game_value) {
  ::D2_ClientGameType c_api_value = ::D2_ClientGameType_ToApiValue_1_07(
      static_cast< ::D2_ClientGameType_1_07>(game_value)
  );

  return static_cast<ClientGameType>(c_api_value);
}

} // namespace client_game_type
} // namespace d2
