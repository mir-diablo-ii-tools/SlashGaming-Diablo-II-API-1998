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

#include "../../include/c/game_version.h"
#include "../wide_macro.h"
#include "backend/error_handling.h"

static const char* GetLibraryName(enum D2_DefaultLibrary library) {
  switch (library) {
    case LIBRARY_BNCLIENT: {
      return "BNClient.dll";
    }

    case LIBRARY_D2CLIENT: {
      return "D2Client.dll";
    }

    case LIBRARY_D2CMP: {
      return "D2CMP.dll";
    }

    case LIBRARY_D2COMMON: {
      return "D2Common.dll";
    }

    case LIBRARY_D2DDRAW: {
      return "D2DDraw.dll";
    }

    case LIBRARY_D2DIRECT3D: {
      return "D2Direct3D.dll";
    }

    case LIBRARY_D2GAME: {
      return "D2Game.dll";
    }

    case LIBRARY_D2GDI: {
      return "D2GDI.dll";
    }

    case LIBRARY_D2GFX: {
      return "D2GFX.dll";
    }

    case LIBRARY_D2GLIDE: {
      return "D2Glide.dll";
    }

    case LIBRARY_D2LANG: {
      return "D2Lang.dll";
    }

    case LIBRARY_D2LAUNCH: {
      return "D2Launch.dll";
    }

    case LIBRARY_D2MCPCLIENT: {
      return "D2MCPClient.dll";
    }

    case LIBRARY_D2MULTI: {
      return "D2Multi.dll";
    }

    case LIBRARY_D2NET: {
      return "D2Net.dll";
    }

    case LIBRARY_D2SERVER: {
      return "D2Server.dll";
    }

    case LIBRARY_D2SOUND: {
      return "D2Sound.dll";
    }

    case LIBRARY_D2WIN: {
      return "D2Win.dll";
    }

    case LIBRARY_FOG: {
      return "Fog.dll";
    }

    case LIBRARY_STORM: {
      return "Storm.dll";
    }
  }

  return NULL;
}

const char* Mapi_GetGameExecutablePath(void) {
  return "Game.exe";
}

const char* Mapi_GetDefaultLibraryPathWithRedirect(
    enum D2_DefaultLibrary library_id
) {
  // Redirect if the game version is 1.14 or higher.
  if (D2_IsRunningGameVersionAtLeast1_14()) {
    return Mapi_GetGameExecutablePath();
  }

  if (library_id < 0 || library_id > LIBRARY_STORM) {
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

  return GetLibraryName(library_id);
}
