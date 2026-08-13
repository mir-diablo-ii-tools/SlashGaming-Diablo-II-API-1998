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

#include "sgd2mapi/version/d2/d2types_test.h"

#include <stddef.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/version/d2/d2types.h"

static void ToDisplayname_VersionBeta1_02_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "Beta 1.02";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name =
      VersionD2_ToDisplayName(VERSIOND2_BETA_1_02, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_VersionBeta1_02StressTest_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "Beta 1.02 Stress Test";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name =
      VersionD2_ToDisplayName(
          VERSIOND2_BETA_1_02_STRESS_TEST, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_00_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.00";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_00, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_01_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.01";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_01, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_02_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.02";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_02, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_03_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.03";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_03, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_04_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.04";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_04, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_04b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.04b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_04B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_04c_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.04c";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_04C, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_05_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.05";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_05, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_05b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.05b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_05B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_06_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.06";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_06, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_06b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.06b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_06B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_07Beta_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.07 Beta";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_07_BETA, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_07_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.07";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_07, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_08_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.08";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_08, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_09_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.09";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_09, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_09b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.09b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_09B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_09c_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.09c";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_09C, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_09d_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.09d";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_09D, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_10Beta_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.10 Beta";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_10_BETA, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_10sBeta_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.10s Beta";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_10S_BETA, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_11_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.11";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_11, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_11b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.11b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_11B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_12_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.12";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_12, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_13a_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.13a";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_13A, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_13b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.13b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_13B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_13c_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.13c";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_13C, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_13d_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.13d";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_13D, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_14a_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.14a";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_14A, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_14b_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.14b";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_14B, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_14c_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.14c";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_14C, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayname_Version1_14d_MatchesExpected(CuTest* tc) {
  const char* expected_display_name = "1.14d";
  size_t length;
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(VERSIOND2_1_14D, &length, &error);

  CuAssertStrEquals(tc, expected_display_name, display_name);
  CuAssertIntEquals(tc, strlen(expected_display_name), length);
}

static void ToDisplayName_Invalid_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  const char* display_name;

  display_name = VersionD2_ToDisplayName(-42, NULL, &error);

  CuAssertIntEquals(tc, SGD2ERROR_UNEXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING,
      error.unexpected_error.code);
  CuAssertPtrEquals(tc, NULL, display_name);
}

static void ToDisplaynameW_VersionBeta1_02_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"Beta 1.02";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name =
      VersionD2_ToDisplayNameW(VERSIOND2_BETA_1_02, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_VersionBeta1_02StressTest_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"Beta 1.02 Stress Test";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name =
      VersionD2_ToDisplayNameW(
          VERSIOND2_BETA_1_02_STRESS_TEST, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_00_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.00";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_00, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_01_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.01";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_01, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_02_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.02";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_02, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_03_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.03";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_03, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_04_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.04";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_04, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_04b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.04b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_04B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_04c_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.04c";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_04C, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_05_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.05";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_05, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_05b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.05b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_05B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_06_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.06";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_06, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_06b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.06b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_06B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_07Beta_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.07 Beta";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_07_BETA, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_07_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.07";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_07, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_08_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.08";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_08, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_09_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.09";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_09, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_09b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.09b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_09B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_09c_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.09c";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_09C, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_09d_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.09d";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_09D, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_10Beta_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.10 Beta";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_10_BETA, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_10sBeta_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.10s Beta";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_10S_BETA, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_11_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.11";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_11, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_11b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.11b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_11B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_12_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.12";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_12, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_13a_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.13a";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_13A, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_13b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.13b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_13B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_13c_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.13c";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_13C, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_13d_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.13d";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_13D, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_14a_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.14a";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_14A, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_14b_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.14b";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_14B, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_14c_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.14c";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_14C, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplaynameW_Version1_14d_MatchesExpected(CuTest* tc) {
  const wchar_t* expected_display_name = L"1.14d";
  size_t length;
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(VERSIOND2_1_14D, &length, &error);

  CuAssertIntEquals(tc, 0, wcscmp(display_name, expected_display_name));
  CuAssertIntEquals(tc, wcslen(expected_display_name), length);
}

static void ToDisplayNameW_Invalid_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  const wchar_t* display_name;

  display_name = VersionD2_ToDisplayNameW(-42, NULL, &error);

  CuAssertIntEquals(tc, SGD2ERROR_UNEXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING,
      error.unexpected_error.code);
  CuAssertPtrEquals(tc, NULL, display_name);
}

/**
 * External
 */

CuSuite* D2Types_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &ToDisplayname_VersionBeta1_02_MatchesExpected);
  SUITE_ADD_TEST(
      suite, &ToDisplayname_VersionBeta1_02StressTest_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_00_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_01_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_02_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_03_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_04_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_04b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_04c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_05_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_05b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_06_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_06b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_07Beta_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_07_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_08_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_09_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_09b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_09c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_09d_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_10Beta_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_10sBeta_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_11_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_11b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_12_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_13a_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_13b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_13c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_13d_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_14a_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_14b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_14c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayname_Version1_14d_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayName_Invalid_NoConstantMappingError);

  SUITE_ADD_TEST(suite, &ToDisplaynameW_VersionBeta1_02_MatchesExpected);
  SUITE_ADD_TEST(
      suite, &ToDisplaynameW_VersionBeta1_02StressTest_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_00_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_01_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_02_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_03_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_04_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_04b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_04c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_05_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_05b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_06_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_06b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_07Beta_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_07_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_08_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_09_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_09b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_09c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_09d_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_10Beta_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_10sBeta_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_11_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_11b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_12_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_13a_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_13b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_13c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_13d_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_14a_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_14b_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_14c_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplaynameW_Version1_14d_MatchesExpected);
  SUITE_ADD_TEST(suite, &ToDisplayNameW_Invalid_NoConstantMappingError);

  return suite;
}
