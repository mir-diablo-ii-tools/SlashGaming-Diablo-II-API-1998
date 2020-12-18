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

#include "backend/error_handling.h"
#include "../../include/c/game_version.h"
#include "../wide_macro.h"

static const char* kLibraryIdToName[] = {
    [LIBRARY_BNCLIENT] = "BNClient.dll",
    [LIBRARY_D2CLIENT] = "D2Client.dll",
    [LIBRARY_D2CMP] = "D2CMP.dll",
    [LIBRARY_D2COMMON] = "D2Common.dll",
    [LIBRARY_D2DDRAW] = "D2DDraw.dll",
    [LIBRARY_D2DIRECT3D] = "D2Direct3D.dll",
    [LIBRARY_D2GAME] = "D2Game.dll",
    [LIBRARY_D2GDI] = "D2GDI.dll",
    [LIBRARY_D2GFX] = "D2GFX.dll",
    [LIBRARY_D2GLIDE] = "D2Glide.dll",
    [LIBRARY_D2LANG] = "D2Lang.dll",
    [LIBRARY_D2LAUNCH] = "D2Launch.dll",
    [LIBRARY_D2MCPCLIENT] = "D2MCPClient.dll",
    [LIBRARY_D2MULTI] = "D2Multi.dll",
    [LIBRARY_D2NET] = "D2Net.dll",
    [LIBRARY_D2SERVER] = "D2Server.dll",
    [LIBRARY_D2SOUND] = "D2Sound.dll",
    [LIBRARY_D2WIN] = "D2Win.dll",
    [LIBRARY_FOG] = "Fog.dll",
    [LIBRARY_STORM] = "Storm.dll",
};

const char* MAPI_GetGameExecutablePath(void) {
  return "Game.exe";
}

const char* MAPI_GetDefaultLibraryPathWithRedirect(
    enum D2_DefaultLibrary library_id
) {
  /* Redirect if the game version is 1.14 or higher. */
  if (D2_IsRunningGameVersionAtLeast1_14()) {
    return MAPI_GetGameExecutablePath();
  }

  if (library_id < 0
      || library_id > (sizeof(kLibraryIdToName) / sizeof(kLibraryIdToName[0]))) {
    wchar_t error_message[128];
    swprintf(
        error_message,
        sizeof(error_message) / sizeof(error_message[0]),
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

  return kLibraryIdToName[library_id];
}
