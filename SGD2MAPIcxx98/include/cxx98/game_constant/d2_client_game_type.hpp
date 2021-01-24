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

#ifndef SGD2MAPI_CXX98_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_HPP_
#define SGD2MAPI_CXX98_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_HPP_

#include <sgd2mapi.h>

namespace d2 {

/**
 * Generic enum definitions
 */

enum ClientGameType {
  ClientGameType_kSinglePlayer = D2_ClientGameType_kSinglePlayer,
  ClientGameType_kBattleNetJoin = D2_ClientGameType_kSinglePlayer,

#if D2API_VERSION == D2API_VERSION_ALL \
    || D2API_VERSION < D2API_VERSION_1_07
  ClientGameType_kOpenBattleNetHostOrLanHost =
      D2_ClientGameType_kOpenBattleNetHostOrLanHost,
  ClientGameType_kOpenBattleNetJoinOrLanJoin =
      D2_ClientGameType_kOpenBattleNetJoinOrLanJoin,
#endif

#if D2API_VERSION == D2API_VERSION_ALL \
    || D2API_VERSION >= D2API_VERSION_1_07
  ClientGameType_kOpenBattleNetHost = D2_ClientGameType_kOpenBattleNetHost,
  ClientGameType_kOpenBattleNetJoin = D2_ClientGameType_kOpenBattleNetJoin,
  ClientGameType_kLanHost = D2_ClientGameType_kLanHost,
  ClientGameType_kLanJoin = D2_ClientGameType_kLanJoin,
#endif
};

/**
 * Version-specific enum definitions
 */

enum ClientGameType_1_00 {
  ClientGameType_1_00_kSinglePlayer = D2_ClientGameType_1_00_kSinglePlayer,
  ClientGameType_1_00_kBattleNetJoin = D2_ClientGameType_1_00_kBattleNetJoin,
  ClientGameType_1_00_kOpenBattleNetHostOrLanHost =
      D2_ClientGameType_1_00_kOpenBattleNetHostOrLanHost,
  ClientGameType_1_00_kOpenBattleNetJoinOrLanJoin =
      D2_ClientGameType_1_00_kOpenBattleNetJoinOrLanJoin,
};

enum ClientGameType_1_07 {
  ClientGameType_1_07_kSinglePlayer = D2_ClientGameType_1_07_kSinglePlayer,
  ClientGameType_1_07_kBattleNetJoin = D2_ClientGameType_1_07_kBattleNetJoin,
  ClientGameType_1_07_kOpenBattleNetHost =
      D2_ClientGameType_1_07_kOpenBattleNetHost,
  ClientGameType_1_07_kOpenBattleNetJoin =
      D2_ClientGameType_1_07_kOpenBattleNetJoin,
  ClientGameType_1_07_kLanHost = D2_ClientGameType_1_07_kLanHost,
  ClientGameType_1_07_kLanJoin = D2_ClientGameType_1_07_kLanJoin,
};

/**
 * Function declarations
 */

int ClientGameType_ToGameValue(
    ClientGameType api_value
) {
  return D2_ClientGameType_ToGameValue(
      static_cast<D2_ClientGameType>(api_value)
  );
}

ClientGameType_1_00 ClientGameType_ToGameValue_1_00(
    ClientGameType api_value
) {
  D2_ClientGameType_1_00 actual_game_value =
      D2_ClientGameType_ToGameValue_1_00(
          static_cast<D2_ClientGameType>(api_value)
      );

  return static_cast<ClientGameType_1_00>(actual_game_value);
}

ClientGameType_1_07 ClientGameType_ToGameValue_1_07(
    ClientGameType api_value
) {
  D2_ClientGameType_1_07 actual_game_value =
      D2_ClientGameType_ToGameValue_1_07(
          static_cast<D2_ClientGameType>(api_value)
      );

  return static_cast<ClientGameType_1_07>(actual_game_value);
}

ClientGameType ClientGameType_ToApiValue(
    int game_value
) {
  return static_cast<ClientGameType>(
      D2_ClientGameType_ToApiValue(game_value)
  );
}

ClientGameType ClientGameType_ToApiValue_1_00(
    ClientGameType_1_00 game_value
) {
  D2_ClientGameType actual_api_value =
      D2_ClientGameType_ToApiValue_1_00(
          static_cast<D2_ClientGameType_1_00>(game_value)
      );

  return static_cast<ClientGameType>(actual_api_value);
}

ClientGameType ClientGameType_ToApiValue_1_07(
    ClientGameType_1_07 game_value
) {
  D2_ClientGameType actual_api_value =
      D2_ClientGameType_ToApiValue_1_07(
          static_cast<D2_ClientGameType_1_07>(game_value)
      );

  return static_cast<ClientGameType>(actual_api_value);
}

} // namespace d2

#endif /* SGD2MAPI_CXX98_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_HPP_ */