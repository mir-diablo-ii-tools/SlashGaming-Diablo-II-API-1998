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

#include "sgd2mapi/d2se/ini_properties/protected_section_test.h"

#include <shlwapi.h>

#include <CuTest.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/protected_section.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"

static void ReadFrom_107Ini_107Values(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.07.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_07, protected_section.d2core);
}

static void ReadFrom_108Ini_108Values(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.08.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_08, protected_section.d2core);
}

static void ReadFrom_109bIni_109bValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.09b.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_09B, protected_section.d2core);
}

static void ReadFrom_109dIni_109dValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.09d.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_09D, protected_section.d2core);
}

static void ReadFrom_110fIni_110fValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.10f.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_10F, protected_section.d2core);
}

static void ReadFrom_111bIni_111bValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.11b.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_11B, protected_section.d2core);
}

static void ReadFrom_112aIni_112aValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.12a.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_12A, protected_section.d2core);
}

static void ReadFrom_113cIni_113cValues(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/1.13c.ini",
          &error);

  CuAssertPtrEquals(tc, &protected_section, read_from_result);
  CuAssertIntEquals(tc, SGD2ERROR_GOOD, error.type);
  CuAssertIntEquals(tc, D2SED2CORE_1_13C, protected_section.d2core);
}

static void ReadFrom_EmptyKeyIni_NoConstantMappingError(CuTest* tc) {
  struct SGD2Error error;
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/empty_key.ini",
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
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/empty_value.ini",
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
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
          L"../ini_properties/data/invalid_string.ini",
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
  struct D2SeProtectedSection protected_section;
  struct D2SeProtectedSection* read_from_result;

  /* Precondition */
  CuAssertIntEquals(tc, 0, PathFileExistsW(L"./file/that/doesnt/exist.iniw"));

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &protected_section,
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

CuSuite* D2SeProtectedSection_GetTestSuite(void) {
  CuSuite* suite;

  suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, &ReadFrom_107Ini_107Values);
  SUITE_ADD_TEST(suite, &ReadFrom_108Ini_108Values);
  SUITE_ADD_TEST(suite, &ReadFrom_109bIni_109bValues);
  SUITE_ADD_TEST(suite, &ReadFrom_109dIni_109dValues);
  SUITE_ADD_TEST(suite, &ReadFrom_110fIni_110fValues);
  SUITE_ADD_TEST(suite, &ReadFrom_111bIni_111bValues);
  SUITE_ADD_TEST(suite, &ReadFrom_112aIni_112aValues);
  SUITE_ADD_TEST(suite, &ReadFrom_113cIni_113cValues);

  SUITE_ADD_TEST(suite, &ReadFrom_EmptyKeyIni_NoConstantMappingError);
  SUITE_ADD_TEST(suite, &ReadFrom_EmptyValueIni_NoConstantMappingError);
  SUITE_ADD_TEST(suite, &ReadFrom_InvalidStringIni_NoConstantMappingError);

  SUITE_ADD_TEST(suite, &ReadFrom_FileNotExist_NotFoundError);

  return suite;
}
