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

#include "../../../include/c/game_patch/game_buffer_patch.h"

#include "../error_handling.h"

void MAPI_GamePatch_InitGameBufferPatch(
    struct MAPI_GamePatch* game_patch,
    const struct MAPI_GameAddress* game_address,
    const uint8_t* buffer,
    size_t patch_size
) {
  // Init all simple members.
  game_patch->is_patch_applied = false;
  game_patch->patch_size = patch_size;

  // Init game address member.
  game_patch->game_address = (struct MAPI_GameAddress*) malloc(
      sizeof(game_patch->game_address)
  );
  if (game_patch->game_address == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  *game_patch->game_address = *game_address;

  // Init patch buffer member.
  game_patch->patch_buffer = (uint8_t*) malloc(
      patch_size * sizeof(game_patch->patch_buffer[0])
  );
  if (game_patch->patch_buffer == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  memcpy(game_patch->patch_buffer, buffer, patch_size);

  // Init old buffer member.
  game_patch->old_buffer = (uint8_t*) malloc(
      patch_size * sizeof(game_patch->old_buffer[0])
  );
  if (game_patch->old_buffer == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  memcpy(
      game_patch->old_buffer,
      game_patch->game_address->raw_address,
      patch_size
  );
}
