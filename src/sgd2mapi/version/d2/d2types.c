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

#include "sgd2mapi/version/d2/d2types.h"

#include <stddef.h>

#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>

#include "sgd2mapi/core/error/error.h"

#define RETURN_DISPLAY_NAME(type, text) \
    do { \
      static const type DISPLAY_NAME[] = text; \
      if (length != NULL) { \
        *length = sizeof(DISPLAY_NAME) / sizeof(DISPLAY_NAME[0]) - 1; \
      } \
    \
      return DISPLAY_NAME; \
    } while (0)

/**
 * External
 */

const char* VersionD2_ToDisplayName(
    enum VersionD2 version, size_t* length, struct SGD2Error* error) {
  if (error != NULL) {
    error->type = SGD2ERROR_GOOD;
  }

  switch (version) {
    case VERSIOND2_BETA_1_02:
      RETURN_DISPLAY_NAME(char, "Beta 1.02");
    case VERSIOND2_BETA_1_02_STRESS_TEST:
      RETURN_DISPLAY_NAME(char, "Beta 1.02 Stress Test");
    case VERSIOND2_1_00:
      RETURN_DISPLAY_NAME(char, "1.00");
    case VERSIOND2_1_01:
      RETURN_DISPLAY_NAME(char, "1.01");
    case VERSIOND2_1_02:
      RETURN_DISPLAY_NAME(char, "1.02");
    case VERSIOND2_1_03:
      RETURN_DISPLAY_NAME(char, "1.03");
    case VERSIOND2_1_04:
      RETURN_DISPLAY_NAME(char, "1.04");
    case VERSIOND2_1_04B:
      RETURN_DISPLAY_NAME(char, "1.04b");
    case VERSIOND2_1_04C:
      RETURN_DISPLAY_NAME(char, "1.04c");
    case VERSIOND2_1_05:
      RETURN_DISPLAY_NAME(char, "1.05");
    case VERSIOND2_1_05B:
      RETURN_DISPLAY_NAME(char, "1.05b");
    case VERSIOND2_1_06:
      RETURN_DISPLAY_NAME(char, "1.06");
    case VERSIOND2_1_06B:
      RETURN_DISPLAY_NAME(char, "1.06b");
    case VERSIOND2_1_07_BETA:
      RETURN_DISPLAY_NAME(char, "1.07 Beta");
    case VERSIOND2_1_07:
      RETURN_DISPLAY_NAME(char, "1.07");
    case VERSIOND2_1_08:
      RETURN_DISPLAY_NAME(char, "1.08");
    case VERSIOND2_1_09:
      RETURN_DISPLAY_NAME(char, "1.09");
    case VERSIOND2_1_09B:
      RETURN_DISPLAY_NAME(char, "1.09b");
    case VERSIOND2_1_09C:
      RETURN_DISPLAY_NAME(char, "1.09c");
    case VERSIOND2_1_09D:
      RETURN_DISPLAY_NAME(char, "1.09d");
    case VERSIOND2_1_10_BETA:
      RETURN_DISPLAY_NAME(char, "1.10 Beta");
    case VERSIOND2_1_10S_BETA:
      RETURN_DISPLAY_NAME(char, "1.10s Beta");
    case VERSIOND2_1_10:
      RETURN_DISPLAY_NAME(char, "1.10");
    case VERSIOND2_1_11:
      RETURN_DISPLAY_NAME(char, "1.11");
    case VERSIOND2_1_11B:
      RETURN_DISPLAY_NAME(char, "1.11b");
    case VERSIOND2_1_12:
      RETURN_DISPLAY_NAME(char, "1.12");
    case VERSIOND2_1_13A:
      RETURN_DISPLAY_NAME(char, "1.13a");
    case VERSIOND2_1_13B:
      RETURN_DISPLAY_NAME(char, "1.13b");
    case VERSIOND2_1_13C:
      RETURN_DISPLAY_NAME(char, "1.13c");
    case VERSIOND2_1_13D:
      RETURN_DISPLAY_NAME(char, "1.13d");
    case VERSIOND2_1_14A:
      RETURN_DISPLAY_NAME(char, "1.14a");
    case VERSIOND2_1_14B:
      RETURN_DISPLAY_NAME(char, "1.14b");
    case VERSIOND2_1_14C:
      RETURN_DISPLAY_NAME(char, "1.14c");
    case VERSIOND2_1_14D:
      RETURN_DISPLAY_NAME(char, "1.14d");
    default: {
      if (error != NULL) {
        error->path = __FILEW__;
        error->line = __LINE__;
        error->function_name = L"VersionD2_ToDisplayName";
        error->type = SGD2ERROR_UNEXPECTED_ERROR;
        error->unexpected_error.code =
            SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
      }
      goto error;
    }
  }

error:
  return NULL;
}

const wchar_t* VersionD2_ToDisplayNameW(
    enum VersionD2 version, size_t* length, struct SGD2Error* error) {
  if (error != NULL) {
    error->type = SGD2ERROR_GOOD;
  }

  switch (version) {
    case VERSIOND2_BETA_1_02:
      RETURN_DISPLAY_NAME(wchar_t, L"Beta 1.02");
    case VERSIOND2_BETA_1_02_STRESS_TEST:
      RETURN_DISPLAY_NAME(wchar_t, L"Beta 1.02 Stress Test");
    case VERSIOND2_1_00:
      RETURN_DISPLAY_NAME(wchar_t, L"1.00");
    case VERSIOND2_1_01:
      RETURN_DISPLAY_NAME(wchar_t, L"1.01");
    case VERSIOND2_1_02:
      RETURN_DISPLAY_NAME(wchar_t, L"1.02");
    case VERSIOND2_1_03:
      RETURN_DISPLAY_NAME(wchar_t, L"1.03");
    case VERSIOND2_1_04:
      RETURN_DISPLAY_NAME(wchar_t, L"1.04");
    case VERSIOND2_1_04B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.04b");
    case VERSIOND2_1_04C:
      RETURN_DISPLAY_NAME(wchar_t, L"1.04c");
    case VERSIOND2_1_05:
      RETURN_DISPLAY_NAME(wchar_t, L"1.05");
    case VERSIOND2_1_05B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.05b");
    case VERSIOND2_1_06:
      RETURN_DISPLAY_NAME(wchar_t, L"1.06");
    case VERSIOND2_1_06B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.06b");
    case VERSIOND2_1_07_BETA:
      RETURN_DISPLAY_NAME(wchar_t, L"1.07 Beta");
    case VERSIOND2_1_07:
      RETURN_DISPLAY_NAME(wchar_t, L"1.07");
    case VERSIOND2_1_08:
      RETURN_DISPLAY_NAME(wchar_t, L"1.08");
    case VERSIOND2_1_09:
      RETURN_DISPLAY_NAME(wchar_t, L"1.09");
    case VERSIOND2_1_09B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.09b");
    case VERSIOND2_1_09C:
      RETURN_DISPLAY_NAME(wchar_t, L"1.09c");
    case VERSIOND2_1_09D:
      RETURN_DISPLAY_NAME(wchar_t, L"1.09d");
    case VERSIOND2_1_10_BETA:
      RETURN_DISPLAY_NAME(wchar_t, L"1.10 Beta");
    case VERSIOND2_1_10S_BETA:
      RETURN_DISPLAY_NAME(wchar_t, L"1.10s Beta");
    case VERSIOND2_1_10:
      RETURN_DISPLAY_NAME(wchar_t, L"1.10");
    case VERSIOND2_1_11:
      RETURN_DISPLAY_NAME(wchar_t, L"1.11");
    case VERSIOND2_1_11B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.11b");
    case VERSIOND2_1_12:
      RETURN_DISPLAY_NAME(wchar_t, L"1.12");
    case VERSIOND2_1_13A:
      RETURN_DISPLAY_NAME(wchar_t, L"1.13a");
    case VERSIOND2_1_13B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.13b");
    case VERSIOND2_1_13C:
      RETURN_DISPLAY_NAME(wchar_t, L"1.13c");
    case VERSIOND2_1_13D:
      RETURN_DISPLAY_NAME(wchar_t, L"1.13d");
    case VERSIOND2_1_14A:
      RETURN_DISPLAY_NAME(wchar_t, L"1.14a");
    case VERSIOND2_1_14B:
      RETURN_DISPLAY_NAME(wchar_t, L"1.14b");
    case VERSIOND2_1_14C:
      RETURN_DISPLAY_NAME(wchar_t, L"1.14c");
    case VERSIOND2_1_14D:
      RETURN_DISPLAY_NAME(wchar_t, L"1.14d");
    default: {
      if (error != NULL) {
        error->path = __FILEW__;
        error->line = __LINE__;
        error->function_name = L"VersionD2_ToDisplayNameW";
        error->type = SGD2ERROR_UNEXPECTED_ERROR;
        error->unexpected_error.code =
            SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
      }
      goto error;
    }
  }

error:
  return NULL;
}
