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

#include "sgd2mapi/version/d2/d2detector_test.h"

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/core/file_metadata/pe_timestamp.h"
#include "sgd2mapi/version/d2/d2detector.h"
#include "sgd2mapi/version/d2/d2types.h"

static void DetectFromGameExeTimestamp_ClassicBeta1_02Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x38D09D1F };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_BETA_1_02, version);
}

static void DetectFromGameExeTimestamp_ClassicBeta1_02StressTestTimestamp(
    CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3921FB6C };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_BETA_1_02_STRESS_TEST, version);
}

static void DetectFromGameExeTimestamp_Classic1_00Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x392ECD67 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_00, version);
}

static void DetectFromGameExeTimestamp_Classic1_02Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x396659E0 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_02, version);
}

static void DetectFromGameExeTimestamp_Classic1_03Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x398615BF };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_03, version);
}

static void DetectFromGameExeTimestamp_Classic1_04bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3A439611 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_04B, version);
}

static void DetectFromGameExeTimestamp_Classic1_04cTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3A443C3C };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_04C, version);
}

static void DetectFromGameExeTimestamp_Classic1_05Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3A7210C7 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_05, version);
}

static void DetectFromGameExeTimestamp_Classic1_05bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3A79CBA9 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_05B, version);
}

static void DetectFromGameExeTimestamp_Classic1_06Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3ADE4782 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_06, version);
}

static void DetectFromGameExeTimestamp_Classic1_08Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3B2EB481 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_08, version);
}

static void DetectFromGameExeTimestamp_Classic1_09Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3B7C514A };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_09, version);
}

static void DetectFromGameExeTimestamp_Classic1_09bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3B901118 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_09B, version);
}

static void DetectFromGameExeTimestamp_Classic1_09dTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3C070176 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_09D, version);
}

static void DetectFromGameExeTimestamp_Classic1_10Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3F8A5F81 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_10, version);
}

static void DetectFromGameExeTimestamp_Classic1_11Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x42E6C446 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_11, version);
}

static void DetectFromGameExeTimestamp_Classic1_11bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x43028CAA };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_11B, version);
}

static void DetectFromGameExeTimestamp_Classic1_12Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x483CB8E4 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_12, version);
}

static void DetectFromGameExeTimestamp_Classic1_13cTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x4B95CA54 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_13C, version);
}

static void DetectFromGameExeTimestamp_Classic1_13dTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x4E9DE613 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_13D, version);
}

static void DetectFromGameExeTimestamp_Classic1_14aTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x56D48138 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14A, version);
}

static void DetectFromGameExeTimestamp_Classic1_14bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x56FC78AE };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14B, version);
}

static void DetectFromGameExeTimestamp_Classic1_14cTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x572CDF52 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14C, version);
}

static void DetectFromGameExeTimestamp_Classic1_14dTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x574DDFC4 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14D, version);
}

static void DetectFromGameExeTimestamp_Lod1_07BetaTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3AE0FBC9 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_07_BETA, version);
}

static void DetectFromGameExeTimestamp_Lod1_07Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3AF87A29 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_07, version);
}

static void DetectFromGameExeTimestamp_Lod1_08Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3B2EB47E };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_08, version);
}

static void DetectFromGameExeTimestamp_Lod1_09Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3B7C50BF };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_09, version);
}

static void DetectFromGameExeTimestamp_Lod1_09bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3B901114 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_09B, version);
}

static void DetectFromGameExeTimestamp_Lod1_09dTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3C07016A };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_09D, version);
}

static void DetectFromGameExeTimestamp_Lod1_10BetaTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3F04743F };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_10_BETA, version);
}

static void DetectFromGameExeTimestamp_Lod1_10sBetaTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3F24B4E7 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_10S_BETA, version);
}

static void DetectFromGameExeTimestamp_Lod1_10Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x3F8A5F7D };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_10, version);
}

static void DetectFromGameExeTimestamp_Lod1_11Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x42E6C444 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_11, version);
}

static void DetectFromGameExeTimestamp_Lod1_11bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x43028CA8 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_11B, version);
}

static void DetectFromGameExeTimestamp_Lod1_12Timestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x483CB8E2 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_12, version);
}

static void DetectFromGameExeTimestamp_Lod1_13aTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x4AE0A138 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_13A, version);
}

static void DetectFromGameExeTimestamp_Lod1_13cTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x4B95CA4B };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_13C, version);
}

static void DetectFromGameExeTimestamp_Lod1_13dTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x4E9DE60E };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_13D, version);
}

static void DetectFromGameExeTimestamp_Lod1_14aTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x56D48134 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14A, version);
}

static void DetectFromGameExeTimestamp_Lod1_14bTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x56FC78A8 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14B, version);
}

static void DetectFromGameExeTimestamp_Lod1_14cTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x572CDF4D };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14C, version);
}

static void DetectFromGameExeTimestamp_Lod1_14dTimestamp(CuTest* tc) {
  const struct PeTimestamp timestamp = { 0x574DDFBC };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_GOOD);
  CuAssertIntEquals(tc, VERSIOND2_1_14D, version);
}

static void DetectFromGameExeTimestamp_Invalid_NoConstantMappingError(
    CuTest* tc) {
  const struct PeTimestamp timestamp = { 42 };
  struct SGD2Error error;
  enum VersionD2 version;

  version = VersionD2_DetectFromGameExeTimestamp(&timestamp, &error);

  CuAssertIntEquals(tc, error.type, SGD2ERROR_UNEXPECTED_ERROR);
  CuAssertIntEquals(
      tc,
      error.unexpected_error.code,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING);
  CuAssertIntEquals(tc, VERSIOND2_UNSPECIFIED, version);
}

/**
 * External
 */

CuSuite* D2Detector_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_ClassicBeta1_02Timestamp);
  SUITE_ADD_TEST(
      suite, &DetectFromGameExeTimestamp_ClassicBeta1_02StressTestTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_00Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_02Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_03Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_04bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_04cTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_05Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_05bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_06Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_08Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_09Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_09bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_09dTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_10Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_11Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_11bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_12Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_13cTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_13dTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_14aTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_14bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_14cTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Classic1_14dTimestamp);

  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_07BetaTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_07Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_08Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_09Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_09bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_09dTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_10BetaTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_10sBetaTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_10Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_11Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_11bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_12Timestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_13aTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_13cTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_13dTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_14aTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_14bTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_14cTimestamp);
  SUITE_ADD_TEST(suite, &DetectFromGameExeTimestamp_Lod1_14dTimestamp);

  SUITE_ADD_TEST(
      suite, &DetectFromGameExeTimestamp_Invalid_NoConstantMappingError);

  return suite;
}
