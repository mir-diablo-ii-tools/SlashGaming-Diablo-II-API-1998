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

#include "sgd2mapi/types/d2/cel_context_test.h"

#include <stddef.h>

#include <CuTest.h>

#include "sgd2mapi/types/d2/cel_context.h"

#define SIZEOF_TEST(version_d2) SizeOf_##version_d2
#define OFFSETOF_TEST(version_d2) OffsetOf_##version_d2

#define DEFINE_SIZEOF_TEST_1_00(version_d2) \
  static void SIZEOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals(tc, 0x48, sizeof(struct D2CelContext_##version_d2)); \
  }

#define DEFINE_OFFSETOF_TEST_1_00(version_d2) \
  static void OFFSETOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals( \
        tc, 0x04, offsetof(struct D2CelContext_##version_d2, cel_file)); \
    CuAssertIntEquals( \
        tc, 0x08, offsetof(struct D2CelContext_##version_d2, frame_index)); \
    CuAssertIntEquals( \
        tc, \
        0x0C, \
        offsetof(struct D2CelContext_##version_d2, direction_index)); \
  }

DEFINE_SIZEOF_TEST_1_00(1_00);
DEFINE_OFFSETOF_TEST_1_00(1_00);
DEFINE_SIZEOF_TEST_1_00(1_01);
DEFINE_OFFSETOF_TEST_1_00(1_01);
DEFINE_SIZEOF_TEST_1_00(1_02);
DEFINE_OFFSETOF_TEST_1_00(1_02);
DEFINE_SIZEOF_TEST_1_00(1_03);
DEFINE_OFFSETOF_TEST_1_00(1_03);
DEFINE_SIZEOF_TEST_1_00(1_04);
DEFINE_OFFSETOF_TEST_1_00(1_04);
DEFINE_SIZEOF_TEST_1_00(1_04b);
DEFINE_OFFSETOF_TEST_1_00(1_04b);
DEFINE_SIZEOF_TEST_1_00(1_04c);
DEFINE_OFFSETOF_TEST_1_00(1_04c);
DEFINE_SIZEOF_TEST_1_00(1_05);
DEFINE_OFFSETOF_TEST_1_00(1_05);
DEFINE_SIZEOF_TEST_1_00(1_05b);
DEFINE_OFFSETOF_TEST_1_00(1_05b);
DEFINE_SIZEOF_TEST_1_00(1_06);
DEFINE_OFFSETOF_TEST_1_00(1_06);
DEFINE_SIZEOF_TEST_1_00(1_06b);
DEFINE_OFFSETOF_TEST_1_00(1_06b);
DEFINE_SIZEOF_TEST_1_00(1_07Beta);
DEFINE_OFFSETOF_TEST_1_00(1_07Beta);
DEFINE_SIZEOF_TEST_1_00(1_07);
DEFINE_OFFSETOF_TEST_1_00(1_07);
DEFINE_SIZEOF_TEST_1_00(1_08);
DEFINE_OFFSETOF_TEST_1_00(1_08);
DEFINE_SIZEOF_TEST_1_00(1_09);
DEFINE_OFFSETOF_TEST_1_00(1_09);
DEFINE_SIZEOF_TEST_1_00(1_09b);
DEFINE_OFFSETOF_TEST_1_00(1_09b);
DEFINE_SIZEOF_TEST_1_00(1_09c);
DEFINE_OFFSETOF_TEST_1_00(1_09c);
DEFINE_SIZEOF_TEST_1_00(1_09d);
DEFINE_OFFSETOF_TEST_1_00(1_09d);
DEFINE_SIZEOF_TEST_1_00(1_10Beta);
DEFINE_OFFSETOF_TEST_1_00(1_10Beta);
DEFINE_SIZEOF_TEST_1_00(1_10sBeta);
DEFINE_OFFSETOF_TEST_1_00(1_10sBeta);

#define DEFINE_SIZEOF_TEST_1_11(version_d2) \
  static void SIZEOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals(tc, 0x48, sizeof(struct D2CelContext_##version_d2)); \
  }

#define DEFINE_OFFSETOF_TEST_1_11(version_d2) \
  static void OFFSETOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals( \
        tc, \
        0x00, \
        offsetof(struct D2CelContext_##version_d2, direction_index)); \
    CuAssertIntEquals( \
        tc, 0x08, offsetof(struct D2CelContext_##version_d2, cel_file)); \
    CuAssertIntEquals( \
        tc, 0x44, offsetof(struct D2CelContext_##version_d2, frame_index)); \
  }

DEFINE_SIZEOF_TEST_1_11(1_11);
DEFINE_OFFSETOF_TEST_1_11(1_11);
DEFINE_SIZEOF_TEST_1_11(1_11b);
DEFINE_OFFSETOF_TEST_1_11(1_11b);

#define DEFINE_SIZEOF_TEST_1_12(version_d2) \
  static void SIZEOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals(tc, 0x48, sizeof(struct D2CelContext_##version_d2)); \
  }

#define DEFINE_OFFSETOF_TEST_1_12(version_d2) \
  static void OFFSETOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals( \
        tc, \
        0x38, \
        offsetof(struct D2CelContext_##version_d2, direction_index)); \
    CuAssertIntEquals( \
        tc, 0x3C, offsetof(struct D2CelContext_##version_d2, cel_file)); \
    CuAssertIntEquals( \
        tc, 0x40, offsetof(struct D2CelContext_##version_d2, frame_index)); \
  }

DEFINE_SIZEOF_TEST_1_12(1_12);
DEFINE_OFFSETOF_TEST_1_12(1_12);

#define DEFINE_SIZEOF_TEST_1_13A(version_d2) \
  static void SIZEOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals(tc, 0x48, sizeof(struct D2CelContext_##version_d2)); \
  }

#define DEFINE_OFFSETOF_TEST_1_13A(version_d2) \
  static void OFFSETOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals( \
        tc, \
        0x00, \
        offsetof(struct D2CelContext_##version_d2, direction_index)); \
    CuAssertIntEquals( \
        tc, 0x08, offsetof(struct D2CelContext_##version_d2, frame_index)); \
    CuAssertIntEquals( \
        tc, 0x44, offsetof(struct D2CelContext_##version_d2, cel_file)); \
  }

DEFINE_SIZEOF_TEST_1_13A(1_13a);
DEFINE_OFFSETOF_TEST_1_13A(1_13a);
DEFINE_SIZEOF_TEST_1_13A(1_13b);
DEFINE_OFFSETOF_TEST_1_13A(1_13b);

#define DEFINE_SIZEOF_TEST_1_13C(version_d2) \
  static void SIZEOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals(tc, 0x48, sizeof(struct D2CelContext_##version_d2)); \
  }

#define DEFINE_OFFSETOF_TEST_1_13C(version_d2) \
  static void OFFSETOF_TEST(version_d2)(CuTest* tc) { \
    CuAssertIntEquals( \
        tc, 0x00, offsetof(struct D2CelContext_##version_d2, frame_index)); \
    CuAssertIntEquals( \
        tc, 0x34, offsetof(struct D2CelContext_##version_d2, cel_file)); \
    CuAssertIntEquals( \
        tc, \
        0x40, \
        offsetof(struct D2CelContext_##version_d2, direction_index)); \
  }

DEFINE_SIZEOF_TEST_1_13C(1_13c);
DEFINE_OFFSETOF_TEST_1_13C(1_13c);
DEFINE_SIZEOF_TEST_1_13C(1_14a);
DEFINE_OFFSETOF_TEST_1_13C(1_14a);
DEFINE_SIZEOF_TEST_1_13C(1_14b);
DEFINE_OFFSETOF_TEST_1_13C(1_14b);
DEFINE_SIZEOF_TEST_1_13C(1_14c);
DEFINE_OFFSETOF_TEST_1_13C(1_14c);
DEFINE_SIZEOF_TEST_1_13C(1_14d);
DEFINE_OFFSETOF_TEST_1_13C(1_14d);

/**
 * External
 */

CuSuite* D2CelContext_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_00));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_00));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_01));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_01));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_02));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_02));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_03));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_03));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_04));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_04));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_04b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_04b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_04c));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_04c));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_05));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_05));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_05b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_05b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_06));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_06));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_06b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_06b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_07Beta));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_07Beta));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_07));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_07));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_08));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_08));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_09));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_09));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_09b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_09b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_09c));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_09c));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_09d));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_09d));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_10Beta));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_10Beta));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_10sBeta));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_10sBeta));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_11));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_11));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_11b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_11b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_12));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_12));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_13a));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_13a));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_13b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_13b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_13c));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_13c));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_14a));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_14a));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_14b));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_14b));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_14c));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_14c));
  SUITE_ADD_TEST(suite, &SIZEOF_TEST(1_14d));
  SUITE_ADD_TEST(suite, &OFFSETOF_TEST(1_14d));

  return suite;
}
