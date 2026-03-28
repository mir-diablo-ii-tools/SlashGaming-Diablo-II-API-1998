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

#include "sgd2mapi/d2se/exe_detect_tests.h"

#include <windows.h>
#include <shlwapi.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/core/file_metadata/pe_timestamp.h"
#include "sgd2mapi/d2se/exe_detect.h"

static const struct PeTimestamp D2SE_TIMESTAMP = { 0x4DB5DC5F };
static const struct PeTimestamp NOT_D2SE_TIMESTAMP = { 0x0 };

static void MatchTimestamp_IsD2Se_ReturnsTrue(CuTest* tc) {
  struct SGD2Error error;
  int is_d2se;

  is_d2se = D2Se_MatchTimestamp(&D2SE_TIMESTAMP, &error);

  CuAssertIntEquals(tc, 1, is_d2se);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
}

static void MatchTimestamp_NotD2Se_ReturnsFalse(CuTest* tc) {
  struct SGD2Error error;
  int is_d2se;

  is_d2se = D2Se_MatchTimestamp(&NOT_D2SE_TIMESTAMP, &error);

  CuAssertIntEquals(tc, 0, is_d2se);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
}

/**
 * External
 */

CuSuite* ExeDetect_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &MatchTimestamp_IsD2Se_ReturnsTrue);
  SUITE_ADD_TEST(suite, &MatchTimestamp_NotD2Se_ReturnsFalse);

  return suite;
}
