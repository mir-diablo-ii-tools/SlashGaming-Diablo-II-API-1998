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

#ifndef SGD2MAPI_CXX98_GAME_VERSION_HPP_
#define SGD2MAPI_CXX98_GAME_VERSION_HPP_

#include "../dllexport_define.inc"

namespace d2 {

/**
 * The Diablo II game versions supported and recognized.
 */
enum GameVersion {
  GameVersion_kBeta1_02, GameVersion_kBeta1_02StressTest,

  GameVersion_k1_00, GameVersion_k1_01, GameVersion_k1_02,
  GameVersion_k1_03, GameVersion_k1_04B_C, GameVersion_k1_05,
  GameVersion_k1_05B, GameVersion_k1_06, GameVersion_k1_06B,

  GameVersion_k1_07Beta, GameVersion_k1_07, GameVersion_k1_08,
  GameVersion_k1_09, GameVersion_k1_09B, GameVersion_k1_09D,
  GameVersion_k1_10Beta, GameVersion_k1_10SBeta, GameVersion_k1_10,
  GameVersion_k1_11, GameVersion_k1_11B, GameVersion_k1_12A,
  GameVersion_k1_13ABeta, GameVersion_k1_13C, GameVersion_k1_13D,

  GameVersion_kClassic1_14A, GameVersion_kLod1_14A,
  GameVersion_kClassic1_14B, GameVersion_kLod1_14B,
  GameVersion_kClassic1_14C, GameVersion_kLod1_14C,
  GameVersion_kClassic1_14D, GameVersion_kLod1_14D,
};

/**
 * Returns the UTF-8 encoded null-terminated string associated with the
 * specified game version.
 */
DLLEXPORT const char* GameVersion_GetName(
    GameVersion game_version
);

/**
 * Returns the identifier of the running game version.
 */
DLLEXPORT GameVersion GameVersion_GetRunning();

/**
 * Returns the UTF-8 encoded null-terminated string associated with the
 * running game version.
 */
DLLEXPORT const char* GameVersion_GetRunningName();

/**
 * Returns whether the Diablo II game version is at least 1.14.
 */
DLLEXPORT bool GameVersion_IsAtLeast1_14(GameVersion game_version);

/**
 * Returns whether the running game version is at least 1.14.
 */
DLLEXPORT bool GameVersion_IsRunningAtLeast1_14();

} // namespace d2

#include "../dllexport_undefine.inc"
#endif /* SGD2MAPI_CXX98_GAME_VERSION_HPP_ */
