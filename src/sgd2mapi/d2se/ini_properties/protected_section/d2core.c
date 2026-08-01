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

#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <shlwapi.h>

#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"

#include "sgd2mapi/d2se/dllapi_c_define.inc"

enum {
  D2SED2CORE_STR_CAPACITY = 16
};

struct D2SeD2CoreString {
  const wchar_t* str;
  enum D2SeD2Core d2core;
};

static int D2SeD2CoreString_CompareStr(
    const struct D2SeD2CoreString* lhs, const struct D2SeD2CoreString* rhs) {
  return wcscmp(lhs->str, rhs->str);
}

static int D2SeD2CoreString_CompareStrAsVoid(
    const void* lhs, const void* rhs) {
  return D2SeD2CoreString_CompareStr(lhs, rhs);
}

static const struct D2SeD2CoreString D2SED2CORE_STRINGS[] = {
  { L"1.07", D2SED2CORE_1_07 },
  { L"1.08", D2SED2CORE_1_08 },
  { L"1.09b", D2SED2CORE_1_09B },
  { L"1.09d", D2SED2CORE_1_09D },
  { L"1.10f", D2SED2CORE_1_10F },
  { L"1.11b", D2SED2CORE_1_11B },
  { L"1.12a", D2SED2CORE_1_12A },
  { L"1.13c", D2SED2CORE_1_13C }
};

enum {
  D2SED2CORE_STRING_COUNT =
      sizeof(D2SED2CORE_STRINGS) / sizeof(D2SED2CORE_STRINGS[0])
};

/**
 * External
 */

enum D2SeD2Core D2SeD2Core_ReadFrom(
    const wchar_t* ini_path, struct SGD2Error* error) {
  struct D2SeD2CoreString search_key;
  const struct D2SeD2CoreString* search_result;

  enum {
    VALUE_STR_CAPACITY = 16
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
    return D2SED2CORE_UNSPECIFIED;
  }

  GetPrivateProfileStringW(
      L"Protected",
      L"D2Core",
      L"",
      value_str,
      VALUE_STR_CAPACITY,
      ini_path);

  search_key.str = value_str;

  search_result =
      bsearch(
          &search_key,
          D2SED2CORE_STRINGS,
          D2SED2CORE_STRING_COUNT,
          sizeof(D2SED2CORE_STRINGS[0]),
          &D2SeD2CoreString_CompareStrAsVoid);

  if (search_result == NULL) {
    if (error != NULL) {
      error->path = __FILEW__;
      error->line = __LINE__;
      error->function_name = L"D2SeD2Core_ReadFrom";
      error->type = SGD2ERROR_UNEXPECTED_ERROR;
      error->unexpected_error.code =
          SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
    }
    return D2SED2CORE_UNSPECIFIED;
  }

  if (error != NULL) {
    error->type = SGD2ERROR_GOOD;
  }
  return search_result->d2core;
}

const char* D2SeD2Core_GetDisplayName(
    enum D2SeD2Core d2core, size_t* length, struct SGD2Error* error) {
  switch (d2core) {
    case D2SED2CORE_1_07: {
      static const char DISPLAY_NAME[] = "1.07";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_08: {
      static const char DISPLAY_NAME[] = "1.08";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_09B: {
      static const char DISPLAY_NAME[] = "1.09b";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_09D: {
      static const char DISPLAY_NAME[] = "1.09d";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_10F: {
      static const char DISPLAY_NAME[] = "1.10f";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_11B: {
      static const char DISPLAY_NAME[] = "1.11b";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_12A: {
      static const char DISPLAY_NAME[] = "1.12a";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    case D2SED2CORE_1_13C: {
      static const char DISPLAY_NAME[] = "1.13c";
      if (length != NULL) {
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1;
      }
      return DISPLAY_NAME;
    }

    default: {
      if (error != NULL) {
        error->path = __FILEW__;
        error->line = __LINE__;
        error->function_name = L"D2SeD2Core_GetDisplayName";
        error->type = SGD2ERROR_UNEXPECTED_ERROR;
        error->unexpected_error.code =
            SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
      }

      return NULL;
    }
  }
}
