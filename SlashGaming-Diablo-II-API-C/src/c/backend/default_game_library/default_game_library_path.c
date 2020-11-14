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

#include "default_game_library_path.h"

#include <windows.h>

#include <mdc/container/map.h>
#include <mdc/malloc/malloc.h>
#include <mdc/object/integer_object.h>
#include <mdc/std/threads.h>
#include "../../../../include/c/default_game_library.h"
#include "../../../../include/c/game_version.h"
#include "../../../wide_macro.h"
#include "../error_handling.h"
#include "map_default_game_library_path.h"

static struct Mdc_Map paths_by_default_libraries;
static once_flag paths_by_default_libraries_init_flag;

static struct Mdc_Fs_Path game_executable_path;
static once_flag game_executable_path_init_flag;

static const struct {
  enum D2_DefaultLibrary default_library_id;
  const wchar_t* library_path_cstr;
} kPathsByDefaultLibrariesSrc[] = {
    { LIBRARY_BNCLIENT, L"BNClient.dll" },
    { LIBRARY_D2CLIENT, L"D2Client.dll" },
    { LIBRARY_D2CMP, L"D2CMP.dll" },
    { LIBRARY_D2COMMON, L"D2Common.dll" },
    { LIBRARY_D2DDRAW, L"D2DDraw.dll" },
    { LIBRARY_D2DIRECT3D, L"D2Direct3D.dll" },
    { LIBRARY_D2GAME, L"D2Game.dll" },
    { LIBRARY_D2GDI, L"D2GDI.dll" },
    { LIBRARY_D2GFX, L"D2GFX.dll" },
    { LIBRARY_D2GLIDE, L"D2Glide.dll"},
    { LIBRARY_D2LANG, L"D2Lang.dll"},
    { LIBRARY_D2LAUNCH, L"D2Launch.dll"},
    { LIBRARY_D2MCPCLIENT, L"D2MCPClient.dll"},
    { LIBRARY_D2MULTI, L"D2Multi.dll" },
    { LIBRARY_D2NET, L"D2Net.dll" },
    { LIBRARY_D2SERVER, L"D2Server.dll" },
    { LIBRARY_D2SOUND, L"D2Sound.dll" },
    { LIBRARY_D2WIN, L"D2Win.dll" },
    { LIBRARY_FOG, L"Fog.dll"},
    { LIBRARY_STORM, L"Storm.dll" }
};

enum {
  kPathsByDefaultLibrariesCount = sizeof(kPathsByDefaultLibrariesSrc) /
      sizeof(kPathsByDefaultLibrariesSrc[0]),
};

static void InitPathsByDefaultLibraries(void) {
  size_t i;

  struct Mdc_Map* init_paths_by_default_libraries;

  init_paths_by_default_libraries = Mdc_MapDefaultGameLibraryPath_InitEmpty(
      &paths_by_default_libraries
  );

  if (init_paths_by_default_libraries != &paths_by_default_libraries) {
    ExitOnMdcFunctionFailure(
        L"Mdc_MapDefaultGameLibraryPath_InitEmpty",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  for (i = 0; i < kPathsByDefaultLibrariesCount; i += 1) {
    Mdc_Map_EmplaceKeyCopy(
        &paths_by_default_libraries,
        &kPathsByDefaultLibrariesSrc[i].default_library_id,
        &Mdc_Fs_Path_InitFromCWStr,
        kPathsByDefaultLibrariesSrc[i].library_path_cstr
    );
  }

  return;

return_bad:
  return;
}

static void InitGameExecutablePath(void) {
  enum {
    kGameExecutablePathInitialCapacity = 8
  };

  void* realloc_result;

  struct Mdc_Fs_Path* init_game_executable_path;
  wchar_t* game_executable_path_cstr;
  size_t game_executable_path_cap;
  size_t game_executable_path_new_cap;

  /* Copy the game executable path into the C string. */
  game_executable_path_cstr = NULL;
  game_executable_path_new_cap = kGameExecutablePathInitialCapacity;

  do {
    game_executable_path_cap = game_executable_path_new_cap;

    realloc_result = Mdc_realloc(
        game_executable_path_cstr,
        game_executable_path_cap * sizeof(game_executable_path_cstr[0])
    );

    if (realloc_result == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
      goto return_bad;
    }

    game_executable_path_cstr = realloc_result;
    game_executable_path_cstr[game_executable_path_cap - 2] = L'\0';

    GetModuleFileNameW(
        NULL,
        game_executable_path_cstr,
        game_executable_path_cap
    );

    game_executable_path_new_cap *= 2;
  } while (game_executable_path_cstr[game_executable_path_cap - 2] != L'\0');

  /* The C string now contains the exectuable path. Init the path. */
  init_game_executable_path = Mdc_Fs_Path_InitFromCWStr(
      &game_executable_path,
      game_executable_path_cstr
  );

  if (init_game_executable_path != &game_executable_path) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_InitFromCWStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  Mdc_free(game_executable_path_cstr);

  return;

return_bad:
  return;
}

static void InitStatic(void) {
  call_once(
      &paths_by_default_libraries_init_flag,
      &InitPathsByDefaultLibraries
  );

  call_once(
      &game_executable_path_init_flag,
      &InitGameExecutablePath
  );
}

const struct Mdc_Fs_Path* Mapi_Impl_GetGameExecutablePath(void) {
  InitStatic();

  return &game_executable_path;
}

const struct Mdc_Fs_Path* Mapi_Impl_GetDefaultLibraryPathWithoutRedirect(
    enum D2_DefaultLibrary library_id
) {
  const struct Mdc_Fs_Path* mapped_path;

  InitStatic();

  if (!Mdc_Map_Contains(&paths_by_default_libraries, &library_id)) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"Failed to determine game library path from the library ID: %d",
        library_id
    );

    goto return_bad;
  }

  mapped_path = Mdc_Map_AtConst(
      &paths_by_default_libraries,
      &library_id
  );

  return mapped_path;

return_bad:
  return NULL;
}

const struct Mdc_Fs_Path* Mapi_Impl_GetDefaultLibraryPathWithRedirect(
    enum D2_DefaultLibrary library_id
) {
  InitStatic();

  if (D2_IsRunningGameVersionAtLeast1_14()) {
    return Mapi_Impl_GetGameExecutablePath();
  }

  return Mapi_Impl_GetDefaultLibraryPathWithoutRedirect(library_id);
}
