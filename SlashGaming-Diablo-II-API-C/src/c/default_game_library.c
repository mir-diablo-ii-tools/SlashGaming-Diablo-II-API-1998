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

#include "../../include/c/default_game_library.h"

#include <wchar.h>

#include <mdc/container/map.h>
#include <mdc/filesystem/filesystem.h>
#include <mdc/malloc/malloc.h>
#include <mdc/object/integer_object.h>
#include <mdc/std/threads.h>
#include "../../include/c/game_version.h"
#include "../wide_macro.h"
#include "backend/error_handling.h"
#include "backend/default_game_library/map_default_game_library_path.h"

static struct Mdc_Map paths_by_default_libraries;
static once_flag paths_by_default_libraries_init_flag;

static struct Mdc_Fs_Path game_executable_path;
static once_flag game_executable_path_init_flag;

static void InitPathsByDefaultLibraries(void) {
  struct Mdc_Map* init_paths_by_default_libraries;

  init_paths_by_default_libraries = Mdc_Map_InitEmpty(
      &paths_by_default_libraries,
      Mapi_MapDefaultGameLibraryPath_GetGlobalMapMetadata()
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_BNCLIENT,
      L"BNClient.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2CLIENT,
      L"D2Client.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2CMP,
      L"D2CMP.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2COMMON,
      L"D2Common.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2DDRAW,
      L"D2DDraw.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2DIRECT3D,
      L"D2Direct3D.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2GAME,
      L"D2Game.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2GDI,
      L"D2GDI.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2GFX,
      L"D2GFX.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2GLIDE,
      L"D2Glide.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2LANG,
      L"D2Lang.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2LAUNCH,
      L"D2Launch.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2MCPCLIENT,
      L"D2MCPClient.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2MULTI,
      L"D2Multi.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2NET,
      L"D2Net.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2SERVER,
      L"D2Server.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2SOUND,
      L"D2Sound.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_D2WIN,
      L"D2Win.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_FOG,
      L"Fog.dll"
  );

  Mapi_MapDefaultGameLibraryPath_EmplaceKeyValue(
      &paths_by_default_libraries,
      LIBRARY_STORM,
      L"Storm.dll"
  );
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
      goto free_game_executable_path_cstr;
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
    goto free_game_executable_path_cstr;
  }

  Mdc_free(game_executable_path_cstr);

  return;

free_game_executable_path_cstr:
  free(game_executable_path_cstr);

  return;
}

static void InitStatic(void) {
  call_once(
      &paths_by_default_libraries_init_flag,
      &InitPathsByDefaultLibraries
  );
}

const wchar_t* Mapi_GetGameExecutablePath(void) {
  InitStatic();

  return Mdc_Fs_Path_CStr(&game_executable_path);
}

const wchar_t* Mapi_GetDefaultLibraryPathWithRedirect(
    enum D2_DefaultLibrary library_id
) {
  enum {
    kErrorMessageCapacity = 128
  };

  wchar_t error_message[kErrorMessageCapacity];

  struct Mdc_Integer default_library;
  struct Mdc_Integer* init_default_library;

  const struct Mdc_Fs_Path* mapped_path;

  InitStatic();

  // Redirect if the game version is 1.14 or higher.
  if (D2_IsRunningGameVersionAtLeast1_14()) {
    return Mapi_GetGameExecutablePath();
  }

  init_default_library = Mdc_Integer_InitFromValue(
      &default_library,
      library_id
  );

  if (!Mdc_Map_Contains(&paths_by_default_libraries, &default_library)) {
    swprintf(
        error_message,
        kErrorMessageCapacity,
        L"Could not determine the game library path from the library ID: %d",
        library_id
    );

    ExitOnGeneralFailure(
        error_message,
        L"Failed to Determine Game Library Path",
        __FILEW__,
        __LINE__
    );
  }

  mapped_path = Mdc_Map_AtConst(
      &paths_by_default_libraries,
      &default_library
  );

  Mdc_Integer_Deinit(&default_library);

  return Mdc_Fs_Path_CStr(mapped_path);
}
