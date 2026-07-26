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

#include <stdio.h>

#include <CuTest.h>

#include "sgd2mapi/d2se/exe_detect_tests.h"
#include "sgd2mapi/d2se/ini_properties/protected_section_test.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/direct_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_hc_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_plugy_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/no_sound_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/renderer_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/skip_to_bnet_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/txt_test.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/window_mode_test.h"

static void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, D2SeD2Core_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeProtectedSection_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeDirect_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeEnableHc_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeEnablePlugY_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeNoSound_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeRenderer_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeSkipToBNet_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeTxt_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeWindowMode_GetTestSuite());
  CuSuiteAddSuite(suite, D2SeUserSettingsSection_GetTestSuite());
  CuSuiteAddSuite(suite, ExeDetect_GetTestSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main() {
  RunAllTests();
  return 0;
}
