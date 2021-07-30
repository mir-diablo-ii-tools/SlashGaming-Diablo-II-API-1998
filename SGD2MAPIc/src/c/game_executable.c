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

#include "../../include/c/game_executable.h"

#include <windows.h>

#include <mdc/malloc/malloc.h>
#include <mdc/std/threads.h>

#include "../../include/c/file/file_version_info.h"
#include "backend/d2se/d2se_file_pe_signature.h"

static wchar_t game_executable_path[MAX_PATH + 1];
static size_t game_executable_path_len = 0;

static wchar_t* long_game_executable_path = NULL;

static int is_d2se = 0;

static struct Mapi_FileVersionInfo file_version_info;

enum {
  kInitialCapacity = 512
};

static wchar_t* GetMemoryAllocGameExecutable(
    size_t* path_len
) {
  void* realloc_result;

  wchar_t* path;
  size_t path_capacity;
  size_t path_new_capacity;

  path = NULL;
  path_new_capacity = kInitialCapacity;

  do {
    realloc_result = Mdc_realloc(path, path_new_capacity * sizeof(path[0]));
    if (realloc_result == NULL) {
      goto free_path;
    }

    path = realloc_result;
    path_capacity = path_new_capacity;

    *path_len = GetModuleFileNameW(NULL, path, path_capacity);

    path_new_capacity *= 2;
  } while (*path_len >= path_capacity);

  /* Shrink to fit. */
  realloc_result = Mdc_realloc(path, (*path_len + 1) * sizeof(path[0]));
  if (realloc_result == NULL) {
    goto free_path;
  }

  path = realloc_result;

  return path;

free_path:
  Mdc_free(path);

  return NULL;
}

static void InitGameExecutable(void) {
  static int is_init = 0;

  if (is_init) {
    return;
  }

  /* Simple case: Paths within the MAX_PATH limit. */
  game_executable_path_len = GetModuleFileNameW(
      NULL,
      game_executable_path,
      MAX_PATH + 1
  );

  if (game_executable_path_len < MAX_PATH) {
    is_init = 1;
    return;
  }

  /* Complex case: Paths beyond the MAX_PATH limit. */
  long_game_executable_path = GetMemoryAllocGameExecutable(
      &game_executable_path_len
  );

  is_init = 1;
}

static void InitIsD2se(void) {
  static is_init = 0;

  if (is_init) {
    return;
  }

  is_d2se = FilePeSignature_IsD2se();

  is_init = 1;
}

static void InitFileVersionInfo(void) {
  static is_init = 0;

  if (is_init) {
    return;
  }

  file_version_info = Mapi_FileVersionInfo_InitFromPath(
      Mapi_GameExecutable_GetPath()
  );

  is_init = 1;
}

/**
 * External functions
 */

const wchar_t* Mapi_GameExecutable_GetPath(void) {
  InitGameExecutable();

  if (game_executable_path_len < MAX_PATH) {
    return game_executable_path;
  }

  return long_game_executable_path;
}

int Mapi_GameExecutable_IsD2se(void) {
  InitIsD2se();

  return is_d2se;
}

const wchar_t* Mapi_GameExecutable_QueryFileVersionInfoString(
    const wchar_t* sub_block
) {
  InitFileVersionInfo();

  return Mapi_FileVersionInfo_QueryString(
      &file_version_info,
      sub_block
  );
}

const DWORD* Mapi_GameExecutable_QueryFileVersionInfoVar(
    const wchar_t* sub_block,
    size_t* count
) {
  InitFileVersionInfo();

  return Mapi_FileVersionInfo_QueryVar(&file_version_info, sub_block, count);
}

const VS_FIXEDFILEINFO* Mapi_GameExecutable_QueryFixedFileInfo(void) {
  InitFileVersionInfo();

  return Mapi_FileVersionInfo_QueryFixedFileInfo(&file_version_info);
}
