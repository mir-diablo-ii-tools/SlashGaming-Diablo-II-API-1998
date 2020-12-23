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

#include "../../include/c/game_patch.h"

#include <string.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>
#include "backend/architecture_opcode.h"

#define MAPI_GAME_PATCH_UNINIT { 0 }

static const struct Mapi_GamePatch Mapi_GamePatch_kUninit =
    MAPI_GAME_PATCH_UNINIT;

enum {
  kBranchPatchMinSize = sizeof(void (*)(void)) + 1
};

static struct Mapi_GamePatch Mapi_GamePatch_InitFromBufferMove(
    const struct Mapi_GameAddress* game_address,
    uint8_t* buffer,
    size_t patch_size
) {
  struct Mapi_GamePatch game_patch;
  int mtx_init_result;

  game_patch.is_patch_applied = false;
  game_patch.patch_size = patch_size;

  game_patch.game_address = Mapi_GameAddress_InitCopy(game_address);

  game_patch.patch_buffer = buffer;

  game_patch.unpatched_buffer = Mdc_malloc(patch_size);
  if (game_patch.unpatched_buffer == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  memcpy(
      game_patch.unpatched_buffer,
      (const void*) game_address->raw_address,
      patch_size
  );

  mtx_init_result = mtx_init(&game_patch.patch_mutex, mtx_plain);
  if (mtx_init_result != thrd_success) {
    goto free_unpatched_buffer;
  }

  return game_patch;

free_unpatched_buffer:
  Mdc_free(game_patch.unpatched_buffer);

return_bad:
  return Mapi_GamePatch_kUninit;
}

static void Mapi_GamePatch_WriteBytes(
    const struct Mapi_GameAddress* game_address,
    const uint8_t* buffer,
    size_t patch_size
) {
  BOOL is_write_process_memory_success;

  is_write_process_memory_success = WriteProcessMemory(
      GetCurrentProcess(),
      game_address->raw_address,
      buffer,
      patch_size,
      NULL
  );

  if (!is_write_process_memory_success) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetCurrentProcess",
        GetLastError()
    );

    goto return_bad;
  }

  return;

return_bad:
  return;
}

/**
 * External functions
 */

struct Mapi_GamePatch Mapi_GamePatch_InitGameBackBranchPatch(
    const struct Mapi_GameAddress* game_address,
    enum Mapi_BranchType branch_type,
    void (*func_ptr)(void),
    size_t patch_size
) {
  struct Mapi_GamePatch game_patch;
  size_t func_patch_pos;
  ptrdiff_t func_ptr_offset;

  if (patch_size < kBranchPatchMinSize) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"The specified back branch patch at 0x%X requires a minimum "
            L"size of %u. The size specified is %u.",
        __FILEW__,
        __LINE__,
        game_address->raw_address,
        kBranchPatchMinSize,
        patch_size
    );

    goto return_bad;
  }

  game_patch = Mapi_GamePatch_InitGameNopPatch(game_address, patch_size);

  func_patch_pos = patch_size - sizeof(func_ptr);
  func_ptr_offset = ((intptr_t) func_ptr)
      - (game_address->raw_address + patch_size);

  game_patch.patch_buffer[func_patch_pos - 1] = Mapi_ToOpcode(branch_type);
  *((ptrdiff_t*) &game_patch.patch_buffer[func_patch_pos]) = func_ptr_offset;

  return game_patch;

return_bad:
  return Mapi_GamePatch_kUninit;
}

struct Mapi_GamePatch Mapi_GamePatch_InitGameBranchPatch(
    const struct Mapi_GameAddress* game_address,
    enum Mapi_BranchType branch_type,
    void (*func_ptr)(void),
    size_t patch_size
) {
  struct Mapi_GamePatch game_patch;
  ptrdiff_t func_ptr_offset;

  if (patch_size < kBranchPatchMinSize) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"The specified branch patch at 0x%X requires a minimum size "
            L"of %u. The size specified is %u.",
        __FILEW__,
        __LINE__,
        game_address->raw_address,
        kBranchPatchMinSize,
        patch_size
    );

    goto return_bad;
  }

  game_patch = Mapi_GamePatch_InitGameNopPatch(game_address, patch_size);

  func_ptr_offset = (intptr_t) func_ptr -
      (game_address->raw_address + kBranchPatchMinSize);

  game_patch.patch_buffer[0] = Mapi_ToOpcode(branch_type);
  *((ptrdiff_t*) &game_patch.patch_buffer[1]) = func_ptr_offset;

  return game_patch;

return_bad:
  return Mapi_GamePatch_kUninit;
}

struct Mapi_GamePatch Mapi_GamePatch_InitGameBufferPatch(
    const struct Mapi_GameAddress* game_address,
    const uint8_t* buffer,
    size_t patch_size
) {
  uint8_t* patch_buffer;

  patch_buffer = Mdc_malloc(patch_size);
  if (patch_buffer == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  memcpy(patch_buffer, buffer, patch_size);

  return Mapi_GamePatch_InitFromBufferMove(
      game_address,
      patch_buffer,
      patch_size
  );

return_bad:
  return Mapi_GamePatch_kUninit;
}

struct Mapi_GamePatch Mapi_GamePatch_InitGameNopPatch(
    const struct Mapi_GameAddress* game_address,
    size_t patch_size
) {
  uint8_t* patch_buffer;

  patch_buffer = Mdc_malloc(patch_size);
  if (patch_buffer == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  memset(patch_buffer, Mapi_OpCode_kNop, patch_size);

  return Mapi_GamePatch_InitFromBufferMove(
      game_address,
      patch_buffer,
      patch_size
  );

return_bad:
  return Mapi_GamePatch_kUninit;
}

struct Mapi_GamePatch Mapi_GamePatch_InitMove(
    struct Mapi_GamePatch* src
) {
  struct Mapi_GamePatch game_patch;

  game_patch = *src;
  *src = Mapi_GamePatch_kUninit;

  return game_patch;
}

void Mapi_GamePatch_Deinit(struct Mapi_GamePatch* game_patch) {
  mtx_destroy(&game_patch->patch_mutex);

  Mdc_free(game_patch->unpatched_buffer);
  game_patch->unpatched_buffer = NULL;

  Mdc_free(game_patch->patch_buffer);
  game_patch->patch_buffer = NULL;

  Mapi_GameAddress_Deinit(&game_patch->game_address);
}

struct Mapi_GamePatch* Mapi_GamePatch_AssignMove(
    struct Mapi_GamePatch* dest,
    struct Mapi_GamePatch* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;
  *src = Mapi_GamePatch_kUninit;

  return dest;
}

void Mapi_GamePatch_Apply(
    struct Mapi_GamePatch* game_patch
) {
  mtx_lock(&game_patch->patch_mutex);

  if (game_patch->is_patch_applied) {
    return;
  }

  Mapi_GamePatch_WriteBytes(
      &game_patch->game_address,
      game_patch->patch_buffer,
      game_patch->patch_size
  );

  game_patch->is_patch_applied = true;

  mtx_unlock(&game_patch->patch_mutex);
}

void Mapi_GamePatch_Remove(
    struct Mapi_GamePatch* game_patch
) {
  mtx_lock(&game_patch->patch_mutex);

  if (!game_patch->is_patch_applied) {
    return;
  }

  Mapi_GamePatch_WriteBytes(
      &game_patch->game_address,
      game_patch->unpatched_buffer,
      game_patch->patch_size
  );

  game_patch->is_patch_applied = false;

  mtx_unlock(&game_patch->patch_mutex);
}

void Mapi_GamePatch_Swap(
    struct Mapi_GamePatch* game_patch1,
    struct Mapi_GamePatch* game_patch2
) {
  struct Mapi_GamePatch temp_game_patch;

  temp_game_patch = *game_patch1;
  *game_patch1 = *game_patch2;
  *game_patch2 = temp_game_patch;
}
