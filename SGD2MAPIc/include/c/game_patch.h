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

#ifndef SGMAPI_C_GAME_PATCH_H_
#define SGMAPI_C_GAME_PATCH_H_

#include <stddef.h>

#include <mdc/std/stdint.h>
#include <mdc/std/threads.h>
#include "game_address.h"
#include "game_branch_type.h"

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mapi_GamePatch {
  struct Mapi_GameAddress game_address;
  int is_patch_applied;
  uint8_t* patch_buffer;
  uint8_t* unpatched_buffer;
  size_t patch_size;

  mtx_t patch_mutex;
};

#define MAPI_GAME_PATCH_UNINIT { 0 }

DLLEXPORT extern const struct Mapi_GamePatch Mapi_GamePatch_kUninit;

/**
 * Initializes a patch. The patch is configured to overwrite the game
 * code with a branch to the specified function. Space prior to the
 * branch is filled with NOPs.
 */
DLLEXPORT struct Mapi_GamePatch Mapi_GamePatch_InitGameBackBranchPatch(
    const struct Mapi_GameAddress* game_address,
    enum Mapi_BranchType branch_type,
    void (*func_ptr)(void),
    size_t patch_size
);

/**
 * Initializes a patch. The patch is configured to overwrite the game
 * code with a branch to the specified function. Space after the
 * branch is filled with NOPs.
 */
DLLEXPORT struct Mapi_GamePatch Mapi_GamePatch_InitGameBranchPatch(
    const struct Mapi_GameAddress* game_address,
    enum Mapi_BranchType branch_type,
    void (*func_ptr)(void),
    size_t patch_size
);

/**
 * Initializes a patch. The patch is configured to overwrite the game
 * code with values copied from an array of 8-bit integrals.
 */
DLLEXPORT struct Mapi_GamePatch Mapi_GamePatch_InitGameBufferPatch(
    const struct Mapi_GameAddress* game_address,
    const uint8_t* buffer,
    size_t patch_size
);

/**
 * Initializes a patch. The patch is configured to overwrite the game
 * code with NOPs.
 */
DLLEXPORT struct Mapi_GamePatch Mapi_GamePatch_InitGameNopPatch(
    const struct Mapi_GameAddress* game_address,
    size_t patch_size
);

DLLEXPORT struct Mapi_GamePatch Mapi_GamePatch_InitMove(
    struct Mapi_GamePatch* src
);

/**
 * Deinitializes the game patch.
 */
DLLEXPORT void Mapi_GamePatch_Deinit(struct Mapi_GamePatch* game_patch);

DLLEXPORT struct Mapi_GamePatch* Mapi_GamePatch_AssignMove(
    struct Mapi_GamePatch* dest,
    struct Mapi_GamePatch* src
);

/**
 * Applies the game patch by replacing the bytes at its target
 * address with the bytes stored in its patch buffer.
 */
DLLEXPORT void Mapi_GamePatch_Apply(
    struct Mapi_GamePatch* game_patch
);

/**
 * Removes the game patch by restoring the original state of the
 * bytes at its target address.
 */
DLLEXPORT void Mapi_GamePatch_Remove(
    struct Mapi_GamePatch* game_patch
);

DLLEXPORT void Mapi_GamePatch_Swap(
    struct Mapi_GamePatch* game_patch1,
    struct Mapi_GamePatch* game_patch2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../dllexport_undefine.inc"
#endif /* SGMAPI_C_GAME_PATCH_H_ */
