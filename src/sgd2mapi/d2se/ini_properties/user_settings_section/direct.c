/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#include "sgd2mapi/d2se/ini_properties/user_settings_section/direct.h"

#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <shlwapi.h>

#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"

#include "sgd2mapi/d2se/dllapi_c_define.inc"

/**
 * External
 */

enum D2SeDirect D2SeDirect_ReadFrom(
    const wchar_t* ini_path, struct SGD2Error* error) {
  enum {
    VALUE_STR_CAPACITY = 8
  };

  wchar_t value_str[VALUE_STR_CAPACITY];

  if (!PathFileExistsW(ini_path)) {
    if (error != NULL) {
      error->path = __FILEW__;
      error->line = __LINE__;
      error->function_name = L"D2SeD2Core_ReadFrom";
      error->type = SGD2ERROR_EXPECTED_ERROR;
      error->expected_error.code = SGD2EXPECTEDERRORCODE_NOT_FOUND;
    }
    return D2SEDIRECT_UNSPECIFIED;
  }

  GetPrivateProfileStringW(
      L"USERSETTINGS",
      L"Direct",
      L"",
      value_str,
      VALUE_STR_CAPACITY,
      ini_path);

  if (error != NULL) {
    error->type = SGD2ERROR_GOOD;
  }

  if (wcscmp(value_str, L"0") == 0) {
    return D2SEDIRECT_DISABLED;
  } else if (wcscmp(value_str, L"1") == 0) {
    return D2SEDIRECT_ENABLED;
  } else {
    return D2SeDirect_GetDefault();
  }
}

enum D2SeDirect D2SeDirect_GetDefault(void) {
  return D2SEDIRECT_DISABLED;
}

const char* D2SeDirect_GetDisplayName(
    enum D2SeDirect direct, size_t* length, struct SGD2Error* error) {
  switch (direct) {
    case D2SEDIRECT_DISABLED: {
      static const char DISPLAY_NAME[] = "Direct Disabled";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SEDIRECT_ENABLED: {
      static const char DISPLAY_NAME[] = "Direct Enabled";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    default: {
      if (error != NULL) {
        error->path = __FILEW__;
        error->line = __LINE__;
        error->function_name = L"D2SeDirect_GetDisplayName";
        error->type = SGD2ERROR_UNEXPECTED_ERROR;
        error->unexpected_error.code =
            SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
      }

      return NULL;
    }
  }
}
