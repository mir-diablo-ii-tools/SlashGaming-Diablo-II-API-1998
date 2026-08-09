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

#include "sgd2mapi/version/d2/d2converter_test.h"

#include <stddef.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"
#include "sgd2mapi/version/d2/d2converter.h"
#include "sgd2mapi/version/d2/d2types.h"

static void FromD2SeD2Core_D2SeD2Core1_07_VersionD21_07(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_07, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_07, version);
}

static void FromD2SeD2Core_D2SeD2Core1_08_VersionD21_08(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_08, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_08, version);
}

static void FromD2SeD2Core_D2SeD2Core1_09b_VersionD21_09b(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_09B, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_09B, version);
}

static void FromD2SeD2Core_D2SeD2Core1_09d_VersionD21_09d(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_09D, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_09D, version);
}

static void FromD2SeD2Core_D2SeD2Core1_10_VersionD21_10(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_10F, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_10, version);
}

static void FromD2SeD2Core_D2SeD2Core1_11b_VersionD21_11b(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_11B, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_11B, version);
}

static void FromD2SeD2Core_D2SeD2Core1_12a_VersionD21_12a(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_12A, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_12, version);
}

static void FromD2SeD2Core_D2SeD2Core1_13c_VersionD21_13c(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(D2SED2CORE_1_13C, &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, VERSIOND2_1_13C, version);
}

static void FromD2SeD2Core_Invalid_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_FromD2SeD2Core(-42, &error);

  CuAssertIntEquals(tc, SGD2ERROR_UNEXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING,
      error.unexpected_error.code);
  CuAssertIntEquals(tc, VERSIOND2_UNSPECIFIED, version);
}

/**
 * External
 */

CuSuite* D2Converter_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_07_VersionD21_07);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_08_VersionD21_08);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_09b_VersionD21_09b);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_09d_VersionD21_09d);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_10_VersionD21_10);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_11b_VersionD21_11b);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_12a_VersionD21_12a);
  SUITE_ADD_TEST(suite, &FromD2SeD2Core_D2SeD2Core1_13c_VersionD21_13c);

  SUITE_ADD_TEST(suite, &FromD2SeD2Core_Invalid_NoConstantMappingError);

  return suite;
}
