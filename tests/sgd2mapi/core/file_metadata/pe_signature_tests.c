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

#include "sgd2mapi/core/file_metadata/pe_signature_tests.h"

#include <stddef.h>
#include <stdio.h>
#include <windows.h>
#include <shlwapi.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/file_metadata/pe_signature.h"

#define SIMPLE_PATH L"../file_metadata/data/simple.txt"
#define TOO_SMALL_PATH L"../file_metadata/data/too_small.txt"

#define NON_EXISTENT_PATH L"this\1path\2does\3not\4exist"

static void Precondition_CheckFiles(void) {
  static wchar_t EXISTING_PATHS[][MAX_PATH] = {
    SIMPLE_PATH,
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
    wprintf(L"File should no exist: %s\n", NON_EXISTENT_PATH);
  }
}

static void ReadFile_Simple_MatchesExpected(CuTest* tc) {
  struct PeSignature actual;
  struct PeSignature expected;
  struct PeSignature* result;

  memcpy(
      expected.data,
      "The quick brown fox jumped over the lazy dog. 0 1 2 3 4 5 6 7 8 ",
      PE_SIGNATURE_SIZE);

  result = PeSignature_ReadFile(&actual, SIMPLE_PATH);

  CuAssertPtrNotNull(tc, result);
  CuAssertIntEquals(tc, 0, PeSignature_Compare(&actual, &expected));
}

static void ReadFile_PathNotExist_ReturnsNull(CuTest* tc) {
  struct PeSignature signature;
  struct PeSignature* result;

  result = PeSignature_ReadFile(&signature, NON_EXISTENT_PATH);

  CuAssertPtrEquals(tc, NULL, result);
}

static void ReadFile_FileTooSmall_ReturnsNull(CuTest* tc) {
  struct PeSignature signature;
  struct PeSignature* result;

  result = PeSignature_ReadFile(&signature, TOO_SMALL_PATH);

  CuAssertPtrEquals(tc, NULL, result);
}

/**
 * External
 */

CuSuite* PeSignature_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  Precondition_CheckFiles();

  SUITE_ADD_TEST(suite, &ReadFile_Simple_MatchesExpected);
  SUITE_ADD_TEST(suite, &ReadFile_PathNotExist_ReturnsNull);
  SUITE_ADD_TEST(suite, &ReadFile_FileTooSmall_ReturnsNull);

  return suite;
}
