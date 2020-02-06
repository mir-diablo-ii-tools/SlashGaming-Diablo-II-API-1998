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

#include "../../../include/c/game_constant/d2_client_game_type.h"

#include "../../../include/c/game_version.h"

static const enum D2_ClientGameType_1_00 to_1_00_mapping[] = {
    [CLIENT_GAME_TYPE_SINGLE_PLAYER] = CLIENT_GAME_TYPE_1_00_SINGLE_PLAYER,
    [CLIENT_GAME_TYPE_BATTLE_NET_JOIN] = CLIENT_GAME_TYPE_1_00_BATTLE_NET_JOIN,
    [CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST_OR_LAN_HOST] =
        CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_HOST_OR_LAN_HOST,
    [CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN] =
        CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN,
};

static const enum D2_ClientGameType from_1_00_mapping[] = {
    [CLIENT_GAME_TYPE_1_00_SINGLE_PLAYER] = CLIENT_GAME_TYPE_SINGLE_PLAYER,
    [CLIENT_GAME_TYPE_1_00_BATTLE_NET_JOIN] =
        CLIENT_GAME_TYPE_BATTLE_NET_JOIN,
    [CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_HOST_OR_LAN_HOST] =
        CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST_OR_LAN_HOST,
    [CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN] =
        CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN,
};

static const enum D2_ClientGameType_1_09D to_1_09d_mapping[] = {
    [CLIENT_GAME_TYPE_SINGLE_PLAYER] = CLIENT_GAME_TYPE_1_09D_SINGLE_PLAYER,
    [CLIENT_GAME_TYPE_BATTLE_NET_JOIN] =
        CLIENT_GAME_TYPE_1_09D_BATTLE_NET_JOIN,
    [CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST] =
        CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_HOST,
    [CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN] =
        CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_JOIN,
    [CLIENT_GAME_TYPE_LAN_HOST] = CLIENT_GAME_TYPE_1_09D_LAN_HOST,
    [CLIENT_GAME_TYPE_LAN_JOIN] = CLIENT_GAME_TYPE_1_09D_LAN_JOIN
};

static const enum D2_ClientGameType from_1_09d_mapping[] = {
    [CLIENT_GAME_TYPE_1_09D_SINGLE_PLAYER] = CLIENT_GAME_TYPE_SINGLE_PLAYER,
    [CLIENT_GAME_TYPE_1_09D_BATTLE_NET_JOIN] =
        CLIENT_GAME_TYPE_BATTLE_NET_JOIN,
    [CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_HOST] =
        CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST,
    [CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_JOIN] =
        CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN,
    [CLIENT_GAME_TYPE_1_09D_LAN_HOST] = CLIENT_GAME_TYPE_LAN_HOST,
    [CLIENT_GAME_TYPE_1_09D_LAN_JOIN] = CLIENT_GAME_TYPE_LAN_JOIN,
};

int D2_ClientGameType_ToGameValue(enum D2_ClientGameType api_value) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version < VERSION_1_07) {
    return to_1_00_mapping[api_value];
  } else {
    return to_1_09d_mapping[api_value];
  }
}

enum D2_ClientGameType D2_ClientGameType_ToApiValue(int game_value) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version < VERSION_1_07) {
    return from_1_00_mapping[game_value];
  } else {
    return from_1_09d_mapping[game_value];
  }
}
