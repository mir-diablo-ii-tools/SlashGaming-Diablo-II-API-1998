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

#include "version_name.h"

#include "file_version.h"

const char* D2_SearchGameVersionName(enum D2_GameVersion game_version) {
  switch (game_version) {
    case VERSION_BETA_1_02: {
      return "Beta 1.02";
    }

    case VERSION_BETA_STRESS_TEST_1_02: {
      return "Beta Stress Test 1.02";
    }

    case VERSION_1_00: {
      return "1.00";
    }

    case VERSION_1_01: {
      return "1.01";
    }

    case VERSION_1_02: {
      return "1.02";
    }

    case VERSION_1_03: {
      return "1.03";
    }

    // 1.04B and 1.04C use the same DLLs.
    case VERSION_1_04B_C: {
      return "1.04B/C";
    }

    case VERSION_1_05: {
      return "1.05";
    }

    case VERSION_1_05B: {
      return "1.05B";
    }

    case VERSION_1_06: {
      return "1.06";
    }

    case VERSION_1_06B: {
      return "1.06B";
    }

    case VERSION_1_07_BETA: {
      return "1.07 Beta";
    }

    case VERSION_1_07: {
      return "1.07";
    }

    case VERSION_1_08: {
      return "1.08";
    }

    case VERSION_1_09: {
      return "1.09";
    }

    case VERSION_1_09B: {
      return "1.09B";
    }

    case VERSION_1_09D: {
      return "1.09D";
    }

    case VERSION_1_10_BETA: {
      return "1.10 Beta";
    }

    case VERSION_1_10S_BETA: {
      return "1.10S Beta";
    }

    case VERSION_1_10: {
      return "1.10";
    }

    case VERSION_1_11: {
      return "1.11";
    }

    case VERSION_1_11B: {
      return "1.11B";
    }

    case VERSION_1_12A: {
      return "1.12A";
    }

    case VERSION_1_13A_PTR: {
      return "1.13A PTR";
    }

    case VERSION_1_13C: {
      return "1.13C";
    }

    case VERSION_1_13D: {
      return "1.13D";
    }

    case CLASSIC_1_14A: {
      return "Classic 1.14A";
    }

    case LOD_1_14A: {
      return "LoD 1.14A";
    }

    case CLASSIC_1_14B: {
      return "Classic 1.14B";
    }

    case LOD_1_14B: {
      return "LoD 1.14B";
    }

    case CLASSIC_1_14C: {
      return "Classic 1.14C";
    }

    case LOD_1_14C: {
      return "LoD 1.14C";
    }

    case CLASSIC_1_14D: {
      return "Classic 1.14D";
    }

    case LOD_1_14D: {
      return "LoD 1.14D";
    }
  }
}
