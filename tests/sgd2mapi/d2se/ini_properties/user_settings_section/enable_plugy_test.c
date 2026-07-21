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

#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_plugy_test.h"

#include <shlwapi.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_plugy.h"

static void ReadFrom_DisablePlugYIni_Disabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/plugy_disable.ini",
          &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_DISABLED, enable_plugy);
}

static void ReadFrom_EnablePlugYIni_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/plugy_enable.ini",
          &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

static void ReadFrom_EmptyKeyIni_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/empty_key.ini",
          &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

static void ReadFrom_EmptyValueIni_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/empty_value.ini",
          &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

static void ReadFrom_InvalidStringIni_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/invalid_string.ini",
          &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

static void ReadFrom_NegativeIni_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/negative.ini",
          &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

static void ReadFrom_OverIni_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"../ini_properties/user_settings_section/data/over.ini", &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

static void ReadFrom_NotExist_Enabled(CuTest* tc) {
  struct SGD2Error error;
  enum D2SeEnablePlugY enable_plugy;

  /* Precondition */
  CuAssertIntEquals(tc, 0, PathFileExistsW(L"./file/that/doesnt/exist.iniw"));

  enable_plugy =
      D2SeEnablePlugY_ReadFrom(
          L"./file/that/doesnt/exist.iniw", &error);

  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SEENABLEPLUGY_ENABLED, enable_plugy);
}

/**
 * External
 */

CuSuite* D2SeEnablePlugY_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &ReadFrom_EnablePlugYIni_Enabled);
  SUITE_ADD_TEST(suite, &ReadFrom_DisablePlugYIni_Disabled);

  SUITE_ADD_TEST(suite, &ReadFrom_EmptyKeyIni_Enabled);
  SUITE_ADD_TEST(suite, &ReadFrom_EmptyValueIni_Enabled);
  SUITE_ADD_TEST(suite, &ReadFrom_InvalidStringIni_Enabled);
  SUITE_ADD_TEST(suite, &ReadFrom_NegativeIni_Enabled);
  SUITE_ADD_TEST(suite, &ReadFrom_OverIni_Enabled);
  SUITE_ADD_TEST(suite, &ReadFrom_NotExist_Enabled);

  return suite;
}
