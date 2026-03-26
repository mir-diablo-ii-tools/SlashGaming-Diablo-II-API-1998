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

#include "sgd2mapi/core/file_metadata/pe_timestamp_tests.h"

#include <stddef.h>
#include <stdio.h>
#include <windows.h>
#include <shlwapi.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/core/file_metadata/pe_timestamp.h"

#define SIMPLE_1_PATH L"../file_metadata/data/simple1.exe"
#define SIMPLE_2_PATH L"../file_metadata/data/simple2.exe"
#define TOO_SMALL_PATH L"../file_metadata/data/too_small.txt"

#define NON_EXISTENT_PATH L"this/pat/hdoesn/ote/xi/st"
#define INVALID_PATH L"this\1path\2does\3not\4exist"

static void Precondition_CheckFiles(void) {
  static wchar_t EXISTING_PATHS[][MAX_PATH] = {
    SIMPLE_1_PATH,
    SIMPLE_2_PATH,
    TOO_SMALL_PATH
  };
  enum {
    EXISTING_PATH_COUNT = sizeof(EXISTING_PATHS) / sizeof(EXISTING_PATHS[0])
  };

  size_t i;

  for (i = 0; i < EXISTING_PATH_COUNT; ++i) {
    if (!PathFileExistsW(EXISTING_PATHS[i])) {
      wprintf(L"File not found: %s\n", EXISTING_PATHS[i]);
    }
  }

  if (PathFileExistsW(NON_EXISTENT_PATH)) {
    wprintf(L"File should not exist: %s\n", NON_EXISTENT_PATH);
  }
}

static void ReadFile_Simple1_MatchesExpected(CuTest* tc) {
  struct PeTimestamp actual;
  struct PeTimestamp expected;
  struct SGD2Error error;
  struct PeTimestamp* result;

  expected.value = 0x69C3B61D;

  result = PeTimestamp_ReadFile(SIMPLE_1_PATH, &actual, &error);

  CuAssertPtrNotNull(tc, result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, 0, PeTimestamp_Compare(&actual, &expected));
}

static void ReadFile_Simple2_MatchesExpected(CuTest* tc) {
  struct PeTimestamp actual;
  struct PeTimestamp expected;
  struct SGD2Error error;
  struct PeTimestamp* result;

  expected.value = 0x69C48DB2;

  result = PeTimestamp_ReadFile(SIMPLE_2_PATH, &actual, &error);

  CuAssertPtrNotNull(tc, result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, 0, PeTimestamp_Compare(&actual, &expected));
}

static void ReadFile_PathNotExist_ReturnsNull(CuTest* tc) {
  struct PeTimestamp actual;
  struct SGD2Error error;
  struct PeTimestamp* result;

  result = PeTimestamp_ReadFile(NON_EXISTENT_PATH, &actual, &error);

  CuAssertPtrEquals(tc, NULL, result);
  CuAssertIntEquals(tc, SGD2ERROR_WINDOWS_ERROR, error.type);
  CuAssertIntEquals(tc, ERROR_PATH_NOT_FOUND, error.windows_error.code);
}

static void ReadFile_InvalidPath_ReturnsNull(CuTest* tc) {
  struct PeTimestamp actual;
  struct SGD2Error error;
  struct PeTimestamp* result;

  result = PeTimestamp_ReadFile(INVALID_PATH, &actual, &error);

  CuAssertPtrEquals(tc, NULL, result);
  CuAssertIntEquals(tc, SGD2ERROR_WINDOWS_ERROR, error.type);
  CuAssertIntEquals(tc, ERROR_INVALID_NAME, error.windows_error.code);
}

static void ReadFile_FileTooSmall_ReturnsNull(CuTest* tc) {
  struct PeTimestamp actual;
  struct SGD2Error error;
  struct PeTimestamp* result;

  result = PeTimestamp_ReadFile(TOO_SMALL_PATH, &actual, &error);

  CuAssertPtrEquals(tc, NULL, result);
  CuAssertIntEquals(tc, SGD2ERROR_WINDOWS_ERROR, error.type);
  CuAssertIntEquals(tc, ERROR_BAD_EXE_FORMAT, error.windows_error.code);
}

/**
 * External
 */

CuSuite* PeTimestamp_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  Precondition_CheckFiles();

  SUITE_ADD_TEST(suite, &ReadFile_Simple1_MatchesExpected);
  SUITE_ADD_TEST(suite, &ReadFile_Simple2_MatchesExpected);
  SUITE_ADD_TEST(suite, &ReadFile_PathNotExist_ReturnsNull);
  SUITE_ADD_TEST(suite, &ReadFile_InvalidPath_ReturnsNull);
  SUITE_ADD_TEST(suite, &ReadFile_FileTooSmall_ReturnsNull);

  return suite;
}
