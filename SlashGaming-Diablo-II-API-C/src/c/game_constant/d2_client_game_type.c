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

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../include/c/game_version.h"

int D2_ClientGameType_ToGameValue(enum D2_ClientGameType api_value) {
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version < D2_GameVersion_k1_07) {
    return D2_ClientGameType_ToGameValue_1_00(api_value);
  } else {
    return D2_ClientGameType_ToGameValue_1_07(api_value);
  }
}

enum D2_ClientGameType_1_00 D2_ClientGameType_ToGameValue_1_00(
    enum D2_ClientGameType api_value
) {
  switch (api_value) {
    case D2_ClientGameType_kSinglePlayer: {
      return D2_ClientGameType_1_00_kSinglePlayer;
    }

    case D2_ClientGameType_kBattleNetJoin: {
      return D2_ClientGameType_1_00_kBattleNetJoin;
    }

    case D2_ClientGameType_kOpenBattleNetHostOrLanHost: {
      return D2_ClientGameType_1_00_kOpenBattleNetHostOrLanHost;
    }

    case D2_ClientGameType_kOpenBattleNetJoinOrLanJoin: {
      return D2_ClientGameType_1_00_kOpenBattleNetJoinOrLanJoin;
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

enum D2_ClientGameType_1_07 D2_ClientGameType_ToGameValue_1_07(
    enum D2_ClientGameType api_value
) {
  switch (api_value) {
    case D2_ClientGameType_kSinglePlayer: {
      return D2_ClientGameType_1_07_kSinglePlayer;
    }

    case D2_ClientGameType_kBattleNetJoin: {
      return D2_ClientGameType_1_07_kBattleNetJoin;
    }

    case D2_ClientGameType_kOpenBattleNetHost: {
      return D2_ClientGameType_1_07_kOpenBattleNetHost;
    }

    case D2_ClientGameType_kOpenBattleNetJoin: {
      return D2_ClientGameType_1_07_kOpenBattleNetJoin;
    }

    case D2_ClientGameType_kLanHost: {
      return D2_ClientGameType_1_07_kLanHost;
    }

    case D2_ClientGameType_kLanJoin: {
      return D2_ClientGameType_1_07_kLanJoin;
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

enum D2_ClientGameType D2_ClientGameType_ToApiValue(int game_value) {
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version < D2_GameVersion_k1_07) {
    return D2_ClientGameType_ToApiValue_1_00(game_value);
  } else {
    return D2_ClientGameType_ToApiValue_1_07(game_value);
  }
}

enum D2_ClientGameType D2_ClientGameType_ToApiValue_1_00(
    enum D2_ClientGameType_1_00 game_value
) {
  switch (game_value) {
    case D2_ClientGameType_1_00_kSinglePlayer: {
      return D2_ClientGameType_kSinglePlayer;
    }

    case D2_ClientGameType_1_00_kBattleNetJoin: {
      return D2_ClientGameType_kBattleNetJoin;
    }

    case D2_ClientGameType_1_00_kOpenBattleNetHostOrLanHost: {
      return D2_ClientGameType_kOpenBattleNetHostOrLanHost;
    }

    case D2_ClientGameType_1_00_kOpenBattleNetJoinOrLanJoin: {
      return D2_ClientGameType_kOpenBattleNetJoinOrLanJoin;
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

enum D2_ClientGameType D2_ClientGameType_ToApiValue_1_07(
    enum D2_ClientGameType_1_07 game_value
) {
  switch (game_value) {
    case D2_ClientGameType_1_07_kSinglePlayer: {
      return D2_ClientGameType_kSinglePlayer;
    }

    case D2_ClientGameType_1_07_kBattleNetJoin: {
      return D2_ClientGameType_kBattleNetJoin;
    }

    case D2_ClientGameType_1_07_kOpenBattleNetHost: {
      return D2_ClientGameType_kOpenBattleNetHost;
    }

    case D2_ClientGameType_1_07_kOpenBattleNetJoin: {
      return D2_ClientGameType_kOpenBattleNetJoin;
    }

    case D2_ClientGameType_1_07_kLanHost: {
      return D2_ClientGameType_kLanHost;
    }

    case D2_ClientGameType_1_07_kLanJoin: {
      return D2_ClientGameType_kLanJoin;
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
