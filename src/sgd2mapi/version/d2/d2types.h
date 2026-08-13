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

#ifndef SGD2MAPI_C_VERSION_TYPES_D2_D2TYPES_H_
#define SGD2MAPI_C_VERSION_TYPES_D2_D2TYPES_H_

#include <mdc/std/wchar.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"

#include "sgd2mapi/version/dllapi_c_define.inc"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/**
 * The various versions of Diablo II. Values are the release date
 * with the format YYYYMMDDRR. YYYY = Year, MM = Month, DD = Day, and
 * RR = Revision. Versions with unknown release dates are given the
 * closest approximate.
 *
 * Dates retrieved from
 * https://www.theamazonbasin.com/wiki/index.php/Patch.
 */
enum VersionD2 {
  VERSIOND2_UNSPECIFIED = 0,

  /* Unknown (set to 2000, March 20) */
  VERSIOND2_BETA_1_02 = 2000032000L,
  /* Unknown (set to 2000, March 20) */
  VERSIOND2_BETA_1_02_STRESS_TEST = 2000032001L,
  /* 2000, June 27 */
  VERSIOND2_1_00 = 2000062700L,
  /* Unknown (uses Patch 1.00 date) */
  VERSIOND2_1_01 = 2000062701L,
  /* Unknown (uses Patch 1.00 date) */
  VERSIOND2_1_02 = 2000062702L,
  /* 2000, August 4 */
  VERSIOND2_1_03 = 2000080400L,
  /* Unknown (uses Patch 1.04B date) */
  VERSIOND2_1_04 = 2000122300L,
  /* 2000, December 23 */
  VERSIOND2_1_04B = 2000122301L,
  /* Unknown (uses Patch 1.04B date) */
  VERSIOND2_1_04C = 2000122302L,
  /* 2001, January 31 */
  VERSIOND2_1_05 = 2001013100L,
  /* 2001, February 2 */
  VERSIOND2_1_05B = 2001020200L,
  /* 2001, April 19 */
  VERSIOND2_1_06 = 2001041900L,
  /* 2001, May 17 */
  VERSIOND2_1_06B = 2001051700L,
  /*
   * 2001, April 25 (https://tcrf.net/Proto:Diablo_II)
   * (Set to July to put it after 1.06B)
   */
  VERSIOND2_1_07_BETA = 2001072500L,
  /* 2001, June 29 */
  VERSIOND2_1_07 = 2001072700L,
  /* 2001, June 29 */
  VERSIOND2_1_08 = 2001072901L,
  /* 2001, August 20 */
  VERSIOND2_1_09 = 2001082000L,
  /* 2001, September 5 */
  VERSIOND2_1_09B = 2001090500L,
  /* 2001, November 14 */
  VERSIOND2_1_09C = 2001111400L,
  /* 2001, December 5 */
  VERSIOND2_1_09D = 2001120500L,
  /* 2003, July 3 */
  VERSIOND2_1_10_BETA = 2003070300L,
  /* 2003, August 4 */
  VERSIOND2_1_10S_BETA = 2003080400L,
  /* 2003, October 28 */
  VERSIOND2_1_10 = 2003102800L,
  /* 2005, August 1 */
  VERSIOND2_1_11 = 2005080100L,
  /* 2005, September 13 */
  VERSIOND2_1_11B = 2005091300L,
  /* 2008, June 17 */
  VERSIOND2_1_12 = 2008061700L,
  /* 2009, December 10 */
  VERSIOND2_1_13A = 2009121000L,
  /* 2010, February 23 */
  VERSIOND2_1_13B = 2010022300L,
  /* 2010, March 23 */
  VERSIOND2_1_13C = 2010032300L,
  /* 2011, October 27 */
  VERSIOND2_1_13D = 2011102700L,
  /* 2016, March 10 */
  VERSIOND2_1_14A = 2016031000L,
  /* 2016, April 7 */
  VERSIOND2_1_14B = 2016040700L,
  /* 2016, May 17 */
  VERSIOND2_1_14C = 2016051700L,
  /* 2016, June 7 */
  VERSIOND2_1_14D = 2016060700L,
};

DLLAPI const char* VersionD2_ToDisplayName(
    enum VersionD2 version, size_t* length, struct SGD2Error* error);

DLLAPI const wchar_t* VersionD2_ToDisplayNameW(
    enum VersionD2 version, size_t* length, struct SGD2Error* error);

#ifdef __cplusplus
}  // extern "C"
#endif  /* __cplusplus */

#include "sgd2mapi/version/dllapi_c_undef.inc"
#endif  /* SGD2MAPI_C_VERSION_TYPES_D2_D2TYPES_H_ */
