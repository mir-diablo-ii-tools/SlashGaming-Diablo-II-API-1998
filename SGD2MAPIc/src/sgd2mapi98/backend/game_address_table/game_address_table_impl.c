/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#include <string.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../../../include/sgd2mapi98/game_version.h"
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

int Mapi_GameAddressTableEntry_CompareKeys(
    const struct Mapi_GameAddressTableEntry* entry1,
    const struct Mapi_GameAddressTableEntry* entry2
) {
  int address_name_compare_result;

  if (entry1->library < entry2->library) {
    return -1;
  } else if (entry1->library > entry2->library) {
    return 1;
  }

  address_name_compare_result = strcmp(
      entry1->address_name,
      entry2->address_name
  );

  return address_name_compare_result;
}

const struct Mapi_GameAddressTableEntry*
Mapi_GameAddressTable_Get(void) {
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GameVersion_GetRunning();

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

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          running_game_version
      );

      goto return_bad;
    }
  }

return_bad:
  return NULL;
}

size_t Mapi_GameAddressTable_Size(void) {
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GameVersion_GetRunning();

  switch (running_game_version) {
    case D2_GameVersion_k1_00: {
      return sizeof(kGameAddressTable_1_00)
          / sizeof(kGameAddressTable_1_00[0]);
    }

    case D2_GameVersion_k1_01: {
      return sizeof(kGameAddressTable_1_01)
          / sizeof(kGameAddressTable_1_01[0]);;
    }

    case D2_GameVersion_k1_02: {
      return sizeof(kGameAddressTable_1_02)
          / sizeof(kGameAddressTable_1_02[0]);;
    }

    case D2_GameVersion_k1_03: {
      return sizeof(kGameAddressTable_1_03)
          / sizeof(kGameAddressTable_1_03[0]);;
    }

    case D2_GameVersion_k1_04B_C: {
      return sizeof(kGameAddressTable_1_04B_C)
          / sizeof(kGameAddressTable_1_04B_C[0]);
    }

    case D2_GameVersion_k1_05: {
      return sizeof(kGameAddressTable_1_05)
          / sizeof(kGameAddressTable_1_05[0]);
    }

    case D2_GameVersion_k1_05B: {
      return sizeof(kGameAddressTable_1_05B)
          / sizeof(kGameAddressTable_1_05B[0]);
    }

    case D2_GameVersion_k1_06: {
      return sizeof(kGameAddressTable_1_06)
          / sizeof(kGameAddressTable_1_06[0]);
    }

    case D2_GameVersion_k1_06B: {
      return sizeof(kGameAddressTable_1_06B)
          / sizeof(kGameAddressTable_1_06B[0]);
    }

    case D2_GameVersion_k1_07Beta: {
      return sizeof(kGameAddressTable_1_07Beta)
          / sizeof(kGameAddressTable_1_07Beta[0]);
    }

    case D2_GameVersion_k1_08: {
      return sizeof(kGameAddressTable_1_08)
          / sizeof(kGameAddressTable_1_08[0]);
    }

    case D2_GameVersion_k1_09: {
      return sizeof(kGameAddressTable_1_09)
          / sizeof(kGameAddressTable_1_09[0]);
    }

    case D2_GameVersion_k1_09B: {
      return sizeof(kGameAddressTable_1_09B)
          / sizeof(kGameAddressTable_1_09B[0]);
    }

    case D2_GameVersion_k1_09D: {
      return sizeof(kGameAddressTable_1_09D)
          / sizeof(kGameAddressTable_1_09D[0]);
    }

    case D2_GameVersion_k1_10Beta: {
      return sizeof(kGameAddressTable_1_10Beta)
          / sizeof(kGameAddressTable_1_10Beta[0]);
    }

    case D2_GameVersion_k1_10SBeta: {
      return sizeof(kGameAddressTable_1_10SBeta)
          / sizeof(kGameAddressTable_1_10SBeta[0]);
    }

    case D2_GameVersion_k1_10: {
      return sizeof(kGameAddressTable_1_10)
          / sizeof(kGameAddressTable_1_10[0]);
    }

    case D2_GameVersion_k1_11: {
      return sizeof(kGameAddressTable_1_11)
          / sizeof(kGameAddressTable_1_11[0]);
    }

    case D2_GameVersion_k1_11B: {
      return sizeof(kGameAddressTable_1_11B)
          / sizeof(kGameAddressTable_1_11B[0]);
    }

    case D2_GameVersion_k1_12A: {
      return sizeof(kGameAddressTable_1_12A)
          / sizeof(kGameAddressTable_1_12A[0]);
    }

    case D2_GameVersion_k1_13ABeta: {
      return sizeof(kGameAddressTable_1_13ABeta)
          / sizeof(kGameAddressTable_1_13ABeta[0]);
    }

    case D2_GameVersion_k1_13C: {
      return sizeof(kGameAddressTable_1_13C)
          / sizeof(kGameAddressTable_1_13C[0]);
    }

    case D2_GameVersion_k1_13D: {
      return sizeof(kGameAddressTable_1_13D)
          / sizeof(kGameAddressTable_1_13D[0]);
    }

    case D2_GameVersion_kClassic1_14A: {
      return sizeof(kGameAddressTable_Classic1_14A)
          / sizeof(kGameAddressTable_Classic1_14A[0]);
    }

    case D2_GameVersion_kLod1_14A: {
      return sizeof(kGameAddressTable_Lod1_14A)
          / sizeof(kGameAddressTable_Lod1_14A[0]);
    }

    case D2_GameVersion_kClassic1_14B: {
      return sizeof(kGameAddressTable_Classic1_14B)
          / sizeof(kGameAddressTable_Classic1_14B[0]);
    }

    case D2_GameVersion_kLod1_14B: {
      return sizeof(kGameAddressTable_Lod1_14B)
          / sizeof(kGameAddressTable_Lod1_14B[0]);
    }

    case D2_GameVersion_kClassic1_14C: {
      return sizeof(kGameAddressTable_Classic1_14C)
          / sizeof(kGameAddressTable_Classic1_14C[0]);
    }

    case D2_GameVersion_kLod1_14C: {
      return sizeof(kGameAddressTable_Lod1_14C)
          / sizeof(kGameAddressTable_Lod1_14C[0]);
    }

    case D2_GameVersion_kClassic1_14D: {
      return sizeof(kGameAddressTable_Classic1_14D)
          / sizeof(kGameAddressTable_Classic1_14D[0]);
    }

    case D2_GameVersion_kLod1_14D: {
      return sizeof(kGameAddressTable_Lod1_14D)
          / sizeof(kGameAddressTable_Lod1_14D[0]);
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          running_game_version
      );

      goto return_bad;
    }
  }

return_bad:
  return 0;
}
