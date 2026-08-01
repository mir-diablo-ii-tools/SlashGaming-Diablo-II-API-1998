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

#include "sgd2mapi/d2se/ini_properties_test.h"

#include <windows.h>
#include <shlwapi.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/direct.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_hc.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_plugy.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/no_sound.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/renderer.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/skip_to_bnet.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/txt.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/window_mode.h"

static struct D2SeIniProperties default_ini_properties;

static struct D2SeIniProperties non_default_ini_properties = {
  {
    D2SERENDERER_DIRECT3D,
    D2SEWINDOWMODE_WINDOWED,
    D2SENOSOUND_SOUNDDISABLED,
    D2SEENABLEHC_DISABLED,
    D2SEENABLEPLUGY_DISABLED,
    D2SEDIRECT_ENABLED,
    D2SETXT_ENABLED,
    D2SESKIPTOBNET_ENABLED
  }, {
    D2SED2CORE_1_13C
  }
};

static void BeforeTestSuite(void) {
  default_ini_properties.protected_section.d2core = D2SED2CORE_1_07;
  D2SeUserSettingsSection_GetDefault(&default_ini_properties.user_settings);
}

static void ReadFrom_DefaultIni_DefaultValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeIniProperties ini_properties;
  struct D2SeIniProperties* read_from_result;
  int equals_expected;

  read_from_result =
      D2SeIniProperties_ReadFrom(
          &ini_properties,
          L"../data/default.ini",
          &error);

  CuAssertPtrEquals(tc, &ini_properties, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  equals_expected =
      D2SeIniProperties_Equals(&ini_properties, &default_ini_properties);
  CuAssertTrue(tc, equals_expected);
}

static void ReadFrom_NonDefaultIni_NonDefaultValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeIniProperties ini_properties;
  struct D2SeIniProperties* read_from_result;
  int equals_expected;

  read_from_result =
      D2SeIniProperties_ReadFrom(
          &ini_properties,
          L"../data/non_default.ini",
          &error);

  CuAssertPtrEquals(tc, &ini_properties, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  equals_expected =
      D2SeIniProperties_Equals(&ini_properties, &non_default_ini_properties);
  CuAssertTrue(tc, equals_expected);
}

static void ReadFrom_EmptyKeyIni_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeIniProperties ini_properties;
  struct D2SeIniProperties* read_from_result;

  read_from_result =
      D2SeIniProperties_ReadFrom(
          &ini_properties,
          L"../data/empty_key.ini",
          &error);

  CuAssertPtrEquals(tc, NULL, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_UNEXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING,
      error.unexpected_error.code);
}

static void ReadFrom_EmptyValueIni_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeIniProperties ini_properties;
  struct D2SeIniProperties* read_from_result;

  read_from_result =
      D2SeIniProperties_ReadFrom(
          &ini_properties,
          L"../data/empty_value.ini",
          &error);

  CuAssertPtrEquals(tc, NULL, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_UNEXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING,
      error.unexpected_error.code);
}

static void ReadFrom_InvalidStringIni_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeIniProperties ini_properties;
  struct D2SeIniProperties* read_from_result;

  read_from_result =
      D2SeIniProperties_ReadFrom(
          &ini_properties,
          L"../data/invalid_string.ini",
          &error);

  CuAssertPtrEquals(tc, NULL, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_UNEXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc,
      SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING,
      error.unexpected_error.code);
}

static void ReadFrom_FileNotExist_NotFoundError(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeIniProperties ini_properties;
  struct D2SeIniProperties* read_from_result;

  /* Precondition */
  CuAssertIntEquals(tc, 0, PathFileExistsW(L"./file/that/doesnt/exist.iniw"));

  read_from_result =
      D2SeIniProperties_ReadFrom(
          &ini_properties,
          L"./file/that/doesnt/exist.iniw",
          &error);

  CuAssertPtrEquals(tc, NULL, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_EXPECTED_ERROR, error.type);
  CuAssertIntEquals(
      tc, SGD2EXPECTEDERRORCODE_NOT_FOUND, error.expected_error.code);
}

/**
 * External
 */

CuSuite* D2SeIniProperties_GetTestSuite(void) {
  CuSuite* suite;

  BeforeTestSuite();

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &ReadFrom_DefaultIni_DefaultValues);
  SUITE_ADD_TEST(suite, &ReadFrom_NonDefaultIni_NonDefaultValues);

  SUITE_ADD_TEST(suite, &ReadFrom_EmptyKeyIni_NoConstantMappingError);
  SUITE_ADD_TEST(suite, &ReadFrom_EmptyValueIni_NoConstantMappingError);
  SUITE_ADD_TEST(suite, &ReadFrom_InvalidStringIni_NoConstantMappingError);

  SUITE_ADD_TEST(suite, &ReadFrom_FileNotExist_NotFoundError);

  return suite;
}
