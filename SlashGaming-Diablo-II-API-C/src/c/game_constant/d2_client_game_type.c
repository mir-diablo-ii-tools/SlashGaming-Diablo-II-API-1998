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

#include "../backend/encoding.h"
#include "../backend/error_handling.h"
#include "../../wide_macro.h"

enum D2_ClientGameType_1_00 ToGameValue_1_00(
    enum D2_ClientGameType api_value
) {
  switch (api_value) {
    case CLIENT_GAME_TYPE_SINGLE_PLAYER: {
      return CLIENT_GAME_TYPE_1_00_SINGLE_PLAYER;
    }

    case CLIENT_GAME_TYPE_BATTLE_NET_JOIN: {
      return CLIENT_GAME_TYPE_1_00_BATTLE_NET_JOIN;
    }

    case CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST_OR_LAN_HOST: {
      return CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_HOST_OR_LAN_HOST;
    }

    case CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN: {
      return CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN;
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

enum D2_ClientGameType ToApiValue_1_00(
    enum D2_ClientGameType_1_00 game_value
) {
  switch (game_value) {
    case CLIENT_GAME_TYPE_1_00_SINGLE_PLAYER: {
      return CLIENT_GAME_TYPE_SINGLE_PLAYER;
    }

    case CLIENT_GAME_TYPE_1_00_BATTLE_NET_JOIN: {
      return CLIENT_GAME_TYPE_BATTLE_NET_JOIN;
    }

    case CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_HOST_OR_LAN_HOST: {
      return CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST_OR_LAN_HOST;
    }

    case CLIENT_GAME_TYPE_1_00_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN: {
      return CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN_OR_LAN_JOIN;
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

enum D2_ClientGameType_1_09D ToGameValue_1_09D(
    enum D2_ClientGameType api_value
) {
  switch (api_value) {
    case CLIENT_GAME_TYPE_SINGLE_PLAYER: {
      return CLIENT_GAME_TYPE_1_09D_SINGLE_PLAYER;
    }

    case CLIENT_GAME_TYPE_BATTLE_NET_JOIN: {
      return CLIENT_GAME_TYPE_1_09D_BATTLE_NET_JOIN;
    }

    case CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST: {
      return CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_HOST;
    }

    case CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN: {
      return CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_JOIN;
    }

    case CLIENT_GAME_TYPE_LAN_HOST: {
      return CLIENT_GAME_TYPE_1_09D_LAN_HOST;
    }

    case CLIENT_GAME_TYPE_LAN_JOIN: {
      return CLIENT_GAME_TYPE_1_09D_LAN_JOIN;
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

enum D2_ClientGameType ToApiValue_1_09D(
    enum D2_ClientGameType_1_09D game_value
) {
  switch (game_value) {
    case CLIENT_GAME_TYPE_1_09D_SINGLE_PLAYER: {
      return CLIENT_GAME_TYPE_SINGLE_PLAYER;
    }

    case CLIENT_GAME_TYPE_1_09D_BATTLE_NET_JOIN: {
      return CLIENT_GAME_TYPE_BATTLE_NET_JOIN;
    }

    case CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_HOST: {
      return CLIENT_GAME_TYPE_OPEN_BATTLE_NET_HOST;
    }

    case CLIENT_GAME_TYPE_1_09D_OPEN_BATTLE_NET_JOIN: {
      return CLIENT_GAME_TYPE_OPEN_BATTLE_NET_JOIN;
    }

    case CLIENT_GAME_TYPE_1_09D_LAN_HOST: {
      return CLIENT_GAME_TYPE_LAN_HOST;
    }

    case CLIENT_GAME_TYPE_1_09D_LAN_JOIN: {
      return CLIENT_GAME_TYPE_LAN_JOIN;
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

int D2_ClientGameType_ToGameValue(enum D2_ClientGameType api_value) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version < VERSION_1_07) {
    return ToGameValue_1_00(api_value);
  } else {
    return ToGameValue_1_09D(api_value);
  }
}

enum D2_ClientGameType D2_ClientGameType_ToApiValue(int game_value) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version < VERSION_1_07) {
    return ToApiValue_1_00(game_value);
  } else {
    return ToApiValue_1_09D(game_value);
  }
}
