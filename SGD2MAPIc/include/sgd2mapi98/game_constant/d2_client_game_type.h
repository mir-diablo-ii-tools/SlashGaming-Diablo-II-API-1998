/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2022  Mir Drualga
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

#ifndef SGD2MAPI_C_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_H_
#define SGD2MAPI_C_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_H_

#include "../../d2api_version.h"

#include "../../dllexport_define.inc"

/**
 * Generic enum definitions
 */

enum D2_ClientGameType {
  D2_ClientGameType_kSinglePlayer,
  D2_ClientGameType_kBattleNetJoin,

#if D2API_VERSION == D2API_VERSION_ALL \
    || D2API_VERSION < D2API_VERSION_1_07
  D2_ClientGameType_kOpenBattleNetHostOrLanHost = 2,
  D2_ClientGameType_kOpenBattleNetJoinOrLanJoin,
#endif

#if D2API_VERSION == D2API_VERSION_ALL \
    || D2API_VERSION >= D2API_VERSION_1_07
  D2_ClientGameType_kOpenBattleNetHost = 4,
  D2_ClientGameType_kOpenBattleNetJoin,
  D2_ClientGameType_kLanHost,
  D2_ClientGameType_kLanJoin,
#endif
};

/**
 * Version-specific enum definitions
 */

enum D2_ClientGameType_1_00 {
  D2_ClientGameType_1_00_kSinglePlayer = 0,
  D2_ClientGameType_1_00_kBattleNetJoin = 3,
  D2_ClientGameType_1_00_kOpenBattleNetHostOrLanHost = 6,
  D2_ClientGameType_1_00_kOpenBattleNetJoinOrLanJoin,
};

enum D2_ClientGameType_1_07 {
  D2_ClientGameType_1_07_kSinglePlayer = 0,
  D2_ClientGameType_1_07_kBattleNetJoin = 3,
  D2_ClientGameType_1_07_kOpenBattleNetHost = 6,
  D2_ClientGameType_1_07_kOpenBattleNetJoin,
  D2_ClientGameType_1_07_kLanHost,
  D2_ClientGameType_1_07_kLanJoin,
};

/**
 * Typedefs
 */

#ifdef SGD2MAPI_ENABLE_TYPEDEFS

typedef enum D2_ClientGameType D2_ClientGameType;
typedef enum D2_ClientGameType_1_00 D2_ClientGameType_1_00;
typedef enum D2_ClientGameType_1_07 D2_ClientGameType_1_07;

#endif /* SGD2MAPI_ENABLE_TYPEDEFS */

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT int D2_ClientGameType_ToGameValue(
    enum D2_ClientGameType api_value
);

DLLEXPORT enum D2_ClientGameType_1_00 D2_ClientGameType_ToGameValue_1_00(
    enum D2_ClientGameType api_value
);

DLLEXPORT enum D2_ClientGameType_1_07 D2_ClientGameType_ToGameValue_1_07(
    enum D2_ClientGameType api_value
);

DLLEXPORT enum D2_ClientGameType D2_ClientGameType_ToApiValue(
    int game_value
);

DLLEXPORT enum D2_ClientGameType D2_ClientGameType_ToApiValue_1_00(
    enum D2_ClientGameType_1_00 game_value
);

DLLEXPORT enum D2_ClientGameType D2_ClientGameType_ToApiValue_1_07(
    enum D2_ClientGameType_1_07 game_value
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_CONSTANT_D2_CLIENT_GAME_TYPE_H_ */
