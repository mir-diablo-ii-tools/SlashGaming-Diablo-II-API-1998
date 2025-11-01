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

#ifndef SGD2MAPI_C_GAME_VERSION_H_
#define SGD2MAPI_C_GAME_VERSION_H_

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * The Diablo II game versions supported and recognized.
 */
enum D2_GameVersion {
  D2_GameVersion_kBeta1_02, D2_GameVersion_kBeta1_02StressTest,

  D2_GameVersion_k1_00, D2_GameVersion_k1_01, D2_GameVersion_k1_02,
  D2_GameVersion_k1_03, D2_GameVersion_k1_04B_C, D2_GameVersion_k1_05,
  D2_GameVersion_k1_05B, D2_GameVersion_k1_06, D2_GameVersion_k1_06B,

  D2_GameVersion_k1_07Beta, D2_GameVersion_k1_07, D2_GameVersion_k1_08,
  D2_GameVersion_k1_09, D2_GameVersion_k1_09B, D2_GameVersion_k1_09D,
  D2_GameVersion_k1_10Beta, D2_GameVersion_k1_10SBeta, D2_GameVersion_k1_10,
  D2_GameVersion_k1_11, D2_GameVersion_k1_11B, D2_GameVersion_k1_12A,
  D2_GameVersion_k1_13ABeta, D2_GameVersion_k1_13C, D2_GameVersion_k1_13D,

  D2_GameVersion_kClassic1_14A, D2_GameVersion_kLod1_14A,
  D2_GameVersion_kClassic1_14B, D2_GameVersion_kLod1_14B,
  D2_GameVersion_kClassic1_14C, D2_GameVersion_kLod1_14C,
  D2_GameVersion_kClassic1_14D, D2_GameVersion_kLod1_14D,
};

/**
 * Returns the UTF-8 encoded null-terminated string associated with the
 * specified game version.
 */
DLLEXPORT const char* D2_GameVersion_GetName(
    enum D2_GameVersion game_version
);

/**
 * Returns the identifier of the running game version.
 */
DLLEXPORT enum D2_GameVersion D2_GameVersion_GetRunning(void);

/**
 * Returns the UTF-8 encoded null-terminated string associated with the
 * running game version.
 */
DLLEXPORT const char* D2_GameVersion_GetRunningName(void);

/**
 * Returns whether the Diablo II game version is at least 1.14.
 */
DLLEXPORT int D2_GameVersion_IsAtLeast1_14(
    enum D2_GameVersion game_version_id
);

/**
 * Returns whether the running game version is at least 1.14.
 */
DLLEXPORT int D2_GameVersion_IsRunningAtLeast1_14(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../dllexport_undefine.inc"
#endif /* SGD2MAPI_C_GAME_VERSION_H_ */
