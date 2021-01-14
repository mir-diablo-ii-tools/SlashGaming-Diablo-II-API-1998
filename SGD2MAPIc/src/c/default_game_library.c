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

#include "../../include/c/default_game_library.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>
#include "../../include/c/game_executable.h"
#include "../../include/c/game_version.h"

const wchar_t* D2_DefaultLibrary_GetPathWithRedirect(
    enum D2_DefaultLibrary library
) {
  /* Redirect if the game version is 1.14 or higher. */
  if (D2_IsRunningGameVersionAtLeast1_14()) {
    return Mapi_GetGameExecutablePath();
  }

  return D2_DefaultLibrary_GetPathWithoutRedirect(library);
}

const wchar_t* D2_DefaultLibrary_GetPathWithoutRedirect(
    enum D2_DefaultLibrary library
) {
  switch (library) {
    case D2_DefaultLibrary_kBNClient: {
      return L"BNClient.dll";
    }

    case D2_DefaultLibrary_kD2Client: {
      return L"D2Client.dll";
    }

    case D2_DefaultLibrary_kD2CMP: {
      return L"D2CMP.dll";
    }

    case D2_DefaultLibrary_kD2Common: {
      return L"D2Common.dll";
    }

    case D2_DefaultLibrary_kD2DDraw: {
      return L"D2DDraw.dll";
    }

    case D2_DefaultLibrary_kD2Direct3D: {
      return L"D2Direct3D.dll";
    }

    case D2_DefaultLibrary_kD2Game: {
      return L"D2Game.dll";
    }

    case D2_DefaultLibrary_kD2GDI: {
      return L"D2GDI.dll";
    }

    case D2_DefaultLibrary_kD2GFX: {
      return L"D2GFX.dll";
    }

    case D2_DefaultLibrary_kD2Glide: {
      return L"D2Glide.dll";
    }

    case D2_DefaultLibrary_kD2Lang: {
      return L"D2Lang.dll";
    }

    case D2_DefaultLibrary_kD2Launch: {
      return L"D2Launch.dll";
    }

    case D2_DefaultLibrary_kD2MCPClient: {
      return L"D2MCPClient.dll";
    }

    case D2_DefaultLibrary_kD2Multi: {
      return L"D2Multi.dll";
    }

    case D2_DefaultLibrary_kD2Net: {
      return L"D2Net.dll";
    }

    case D2_DefaultLibrary_kD2Server: {
      return L"D2Server.dll";
    }

    case D2_DefaultLibrary_kD2Sound: {
      return L"D2Sound.dll";
    }

    case D2_DefaultLibrary_kD2Win: {
      return L"D2Win.dll";
    }

    case D2_DefaultLibrary_kFog: {
      return L"Fog.dll";
    }

    case D2_DefaultLibrary_kStorm: {
      return L"Storm.dll";
    }

    default: {
      Mdc_Error_ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          library
      );

      return NULL;
    }
  }
}
