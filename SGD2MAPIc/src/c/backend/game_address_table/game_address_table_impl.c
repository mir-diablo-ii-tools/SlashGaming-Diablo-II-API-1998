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

#include "game_address_table_impl.h"

#include "../../../include/c/game_version.h"
#include "game_address_table_define.h"

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_00[] =
    MAPI_GAME_ADDRESS_TABLE_1_00;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_01[] =
    MAPI_GAME_ADDRESS_TABLE_1_01;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_02[] =
    MAPI_GAME_ADDRESS_TABLE_1_02;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_03[] =
    MAPI_GAME_ADDRESS_TABLE_1_03;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_1_04B_C[] = MAPI_GAME_ADDRESS_TABLE_1_04B_AND_C;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_05[] =
    MAPI_GAME_ADDRESS_TABLE_1_05;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_05B[] =
    MAPI_GAME_ADDRESS_TABLE_1_05B;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_06[] =
    MAPI_GAME_ADDRESS_TABLE_1_06;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_06B[] =
    MAPI_GAME_ADDRESS_TABLE_1_06B;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_1_07Beta[] = MAPI_GAME_ADDRESS_TABLE_1_07_BETA;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_07[] =
    MAPI_GAME_ADDRESS_TABLE_1_07;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_08[] =
    MAPI_GAME_ADDRESS_TABLE_1_08;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_09[] =
    MAPI_GAME_ADDRESS_TABLE_1_09;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_09B[] =
    MAPI_GAME_ADDRESS_TABLE_1_09B;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_09D[] =
    MAPI_GAME_ADDRESS_TABLE_1_09D;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_1_10Beta[] = MAPI_GAME_ADDRESS_TABLE_1_10_BETA;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_1_10SBeta[] = MAPI_GAME_ADDRESS_TABLE_1_10S_BETA;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_10[] =
  MAPI_GAME_ADDRESS_TABLE_1_10;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_11[] =
    MAPI_GAME_ADDRESS_TABLE_1_11;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_11B[] =
    MAPI_GAME_ADDRESS_TABLE_1_11B;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_12A[] =
    MAPI_GAME_ADDRESS_TABLE_1_12A;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_1_13ABeta[] = MAPI_GAME_ADDRESS_TABLE_1_13A_BETA;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_13C[] =
    MAPI_GAME_ADDRESS_TABLE_1_13C;

static const struct Mapi_GameAddressTableEntry kGameAddressTable_1_13D[] =
    MAPI_GAME_ADDRESS_TABLE_1_13D;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Classic1_14A[] = MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14A;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Lod1_14A[] = MAPI_GAME_ADDRESS_TABLE_LOD_1_14A;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Classic1_14B[] = MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14B;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Lod1_14B[] = MAPI_GAME_ADDRESS_TABLE_LOD_1_14B;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Classic1_14C[] = MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14C;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Lod1_14C[] = MAPI_GAME_ADDRESS_TABLE_LOD_1_14C;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Classic1_14D[] = MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14D;

static const struct Mapi_GameAddressTableEntry
kGameAddressTable_Lod1_14D[] = MAPI_GAME_ADDRESS_TABLE_LOD_1_14D;

/**
 * External
 */

const struct Mapi_GameAddressTableEntry*
Mapi_GameAddressTable_Get(void) {
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  switch (running_game_version) {
    case D2_GameVersion_k1_00: {
      return kGameAddressTable_1_00;
    }

    case D2_GameVersion_k1_01: {
      return kGameAddressTable_1_01;
    }

    case D2_GameVersion_k1_02: {
      return kGameAddressTable_1_02;
    }

    case D2_GameVersion_k1_03: {
      return kGameAddressTable_1_03;
    }

    case D2_GameVersion_k1_04B_C: {
      return kGameAddressTable_1_04B_C;
    }

    case D2_GameVersion_k1_05: {
      return kGameAddressTable_1_05;
    }

    case D2_GameVersion_k1_05B: {
      return kGameAddressTable_1_05B;
    }

    case D2_GameVersion_k1_06: {
      return kGameAddressTable_1_06;
    }

    case D2_GameVersion_k1_06B: {
      return kGameAddressTable_1_06B;
    }

    case D2_GameVersion_k1_07Beta: {
      return kGameAddressTable_1_07Beta;
    }

    case D2_GameVersion_k1_08: {
      return kGameAddressTable_1_08;
    }

    case D2_GameVersion_k1_09: {
      return kGameAddressTable_1_09;
    }

    case D2_GameVersion_k1_09B: {
      return kGameAddressTable_1_09B;
    }

    case D2_GameVersion_k1_09D: {
      return kGameAddressTable_1_09D;
    }

    case D2_GameVersion_k1_10Beta: {
      return kGameAddressTable_1_10Beta;
    }

    case D2_GameVersion_k1_10SBeta: {
      return kGameAddressTable_1_10SBeta;
    }

    case D2_GameVersion_k1_10: {
      return kGameAddressTable_1_10;
    }

    case D2_GameVersion_k1_11: {
      return kGameAddressTable_1_11;
    }

    case D2_GameVersion_k1_11B: {
      return kGameAddressTable_1_11B;
    }

    case D2_GameVersion_k1_12A: {
      return kGameAddressTable_1_12A;
    }

    case D2_GameVersion_k1_13ABeta: {
      return kGameAddressTable_1_13ABeta;
    }

    case D2_GameVersion_k1_13C: {
      return kGameAddressTable_1_13C;
    }

    case D2_GameVersion_k1_13D: {
      return kGameAddressTable_1_13D;
    }

    case D2_GameVersion_kClassic1_14A: {
      return kGameAddressTable_Classic1_14A;
    }

    case D2_GameVersion_kLod1_14A: {
      return kGameAddressTable_Lod1_14A;
    }

    case D2_GameVersion_kClassic1_14B: {
      return kGameAddressTable_Classic1_14B;
    }

    case D2_GameVersion_kLod1_14B: {
      return kGameAddressTable_Lod1_14B;
    }

    case D2_GameVersion_kClassic1_14C: {
      return kGameAddressTable_Classic1_14C;
    }

    case D2_GameVersion_kLod1_14C: {
      return kGameAddressTable_Lod1_14C;
    }

    case D2_GameVersion_kClassic1_14D: {
      return kGameAddressTable_Classic1_14D;
    }

    case D2_GameVersion_kLod1_14D: {
      return kGameAddressTable_Lod1_14D;
    }
  }
}
