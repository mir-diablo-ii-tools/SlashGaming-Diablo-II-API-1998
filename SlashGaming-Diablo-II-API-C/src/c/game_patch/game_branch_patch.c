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

#include "../../../include/c/game_patch/game_branch_patch.h"

#include <mdc/std/stdint.h>
#include "../../../include/c/game_patch/game_nop_patch.h"
#include "../../wide_macro.h"
#include "../backend/architecture_opcode.h"
#include "../backend/error_handling.h"

struct Mapi_GamePatch* Mapi_GamePatch_InitGameBranchPatch(
    struct Mapi_GamePatch* game_patch,
    const struct Mapi_GameAddress* game_address,
    enum Mapi_BranchType branch_type,
    void (*func_ptr)(void),
    size_t patch_size
) {
  /* Fill the buffer with NOPs. */
  Mapi_GamePatch_InitGameNopPatch(
      game_patch,
      game_address,
      patch_size
  );

  /* Set the first byte in the buffer to the branch operation opcode byte. */
  enum Mapi_OpCode opcode_value = Mapi_ToOpcode(branch_type);

  game_patch->patch_buffer[0] = (uint8_t) (0xFF & opcode_value);

  /* Set the next bytes to the address of the inserted function. */
  intptr_t func_buffer = ((intptr_t) func_ptr)
      - (game_address->raw_address)
      - sizeof(game_patch->patch_buffer[0])
      - sizeof(func_ptr);

  for (size_t i = 0; i < sizeof(func_buffer); i += 1) {
    size_t shift_amount = i * (sizeof(game_patch->patch_buffer[0]) * 8);

    game_patch->patch_buffer[i + 1] = (func_buffer >> shift_amount) & 0xFF;
  }
}
