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

#ifndef SGD2MAPI_CPP98_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_HPP_
#define SGD2MAPI_CPP98_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_HPP_

#include <sgd2mapi98.h>

#include "../../dllexport_define.inc"

namespace d2 {
namespace client_game_type {

/*
* These internal enums is not intended for direct public use. It is
* stricly defined here to prevent enum leak to namespace. Use the
* typedefs in the upper-level namespace instead.
*/

namespace api {

enum ClientGameType {
  kSinglePlayer = D2_ClientGameType_kSinglePlayer,
  kBattleNetJoin = D2_ClientGameType_kSinglePlayer,

#if D2API_VERSION == D2API_VERSION_ALL \
    || D2API_VERSION < D2API_VERSION_1_07
  kOpenBattleNetHostOrLanHost =
      D2_ClientGameType_kOpenBattleNetHostOrLanHost,
  kOpenBattleNetJoinOrLanJoin =
      D2_ClientGameType_kOpenBattleNetJoinOrLanJoin,
#endif

#if D2API_VERSION == D2API_VERSION_ALL \
    || D2API_VERSION >= D2API_VERSION_1_07
  kOpenBattleNetHost = D2_ClientGameType_kOpenBattleNetHost,
  kOpenBattleNetJoin = D2_ClientGameType_kOpenBattleNetJoin,
  kLanHost = D2_ClientGameType_kLanHost,
  kLanJoin = D2_ClientGameType_kLanJoin,
#endif
};

} // namespace api

namespace v1_00 {

enum ClientGameType_1_00 {
  kSinglePlayer = D2_ClientGameType_1_00_kSinglePlayer,
  kBattleNetJoin = D2_ClientGameType_1_00_kBattleNetJoin,
  kOpenBattleNetHostOrLanHost =
      D2_ClientGameType_1_00_kOpenBattleNetHostOrLanHost,
  kOpenBattleNetJoinOrLanJoin =
      D2_ClientGameType_1_00_kOpenBattleNetJoinOrLanJoin,
};

} // namespace v1_00

namespace v1_07 {

enum ClientGameType_1_07 {
  kSinglePlayer = D2_ClientGameType_1_07_kSinglePlayer,
  kBattleNetJoin = D2_ClientGameType_1_07_kBattleNetJoin,
  kOpenBattleNetHost = D2_ClientGameType_1_07_kOpenBattleNetHost,
  kOpenBattleNetJoin = D2_ClientGameType_1_07_kOpenBattleNetJoin,
  kLanHost = D2_ClientGameType_1_07_kLanHost,
  kLanJoin = D2_ClientGameType_1_07_kLanJoin,
};

} // namespace v1_07

} // namespace client_game_type

/**
 * Generic enum definitions
 */

typedef client_game_type::api::ClientGameType ClientGameType;

/**
 * Version-specific enum definitions
 */

typedef client_game_type::v1_00::ClientGameType_1_00 ClientGameType_1_00;

typedef client_game_type::v1_07::ClientGameType_1_07 ClientGameType_1_07;

/**
 * Function declarations
 */

namespace client_game_type {

DLLEXPORT int ToGameValue(ClientGameType api_value);

DLLEXPORT ClientGameType_1_00 ToGameValue_1_00(ClientGameType api_value);

DLLEXPORT ClientGameType_1_07 ToGameValue_1_07(ClientGameType api_value);

DLLEXPORT ClientGameType ToApiValue(int game_value);

DLLEXPORT ClientGameType ToApiValue_1_00(ClientGameType_1_00 game_value);

DLLEXPORT ClientGameType ToApiValue_1_07(ClientGameType_1_07 game_value);

} // namespace client_game_type
} // namespace d2

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CPP98_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_HPP_ */
