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

#include "sgd2mapi/version/d2/d2detector.h"

#include <stddef.h>
#include <stdlib.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/core/file_metadata/pe_timestamp.h"
#include "sgd2mapi/version/d2/d2types.h"

#include "sgd2mapi/version/dllapi_c_define.inc"

struct TimestampAndD2Version {
  struct PeTimestamp timestamp;
  enum VersionD2 version;
};

static int TimestampAndD2Version_CompareTimestamp(
    const struct TimestampAndD2Version* lhs,
    const struct TimestampAndD2Version* rhs) {
  return PeTimestamp_Compare(&lhs->timestamp, &rhs->timestamp);
}

static int TimestampAndD2Version_CompareTimestampAsVoid(
    const void* lhs, const void* rhs) {
  return TimestampAndD2Version_CompareTimestamp(lhs, rhs);
}

static const struct TimestampAndD2Version
GAME_EXE_TIMESTAMP_AND_D2_VERSIONS[] = {
  { { 0x38D09D1F }, VERSIOND2_BETA_1_02 },
  { { 0x3921FB6C }, VERSIOND2_BETA_1_02_STRESS_TEST },
  { { 0x392ECD67 }, VERSIOND2_1_00 },
  { { 0x396659E0 }, VERSIOND2_1_02 },
  { { 0x398615BF }, VERSIOND2_1_03 },
  { { 0x3A439611 }, VERSIOND2_1_04B },
  { { 0x3A443C3C }, VERSIOND2_1_04C },
  { { 0x3A7210C7 }, VERSIOND2_1_05 },
  { { 0x3A79CBA9 }, VERSIOND2_1_05B },
  { { 0x3ADE4782 }, VERSIOND2_1_06 },
  { { 0x3AE0FBC9 }, VERSIOND2_1_07_BETA },
  { { 0x3AF87A29 }, VERSIOND2_1_07 },
  { { 0x3B02CB14 }, VERSIOND2_1_06B },
  { { 0x3B2EB47E }, VERSIOND2_1_08 },
  { { 0x3B2EB481 }, VERSIOND2_1_08 },
  { { 0x3B7C50BF }, VERSIOND2_1_09 },
  { { 0x3B7C514A }, VERSIOND2_1_09 },
  { { 0x3B901114 }, VERSIOND2_1_09B },
  { { 0x3B901118 }, VERSIOND2_1_09B },
  { { 0x3C07016A }, VERSIOND2_1_09D },
  { { 0x3C070176 }, VERSIOND2_1_09D },
  { { 0x3F04743F }, VERSIOND2_1_10_BETA },
  { { 0x3F24B4E7 }, VERSIOND2_1_10S_BETA },
  { { 0x3F8A5F7D }, VERSIOND2_1_10 },
  { { 0x3F8A5F81 }, VERSIOND2_1_10 },
  { { 0x42E6C444 }, VERSIOND2_1_11 },
  { { 0x42E6C446 }, VERSIOND2_1_11 },
  { { 0x43028CA8 }, VERSIOND2_1_11B },
  { { 0x43028CAA }, VERSIOND2_1_11B },
  { { 0x483CB8E2 }, VERSIOND2_1_12 },
  { { 0x483CB8E4 }, VERSIOND2_1_12 },
  { { 0x4AE0A138 }, VERSIOND2_1_13A },
  { { 0x4B95CA4B }, VERSIOND2_1_13C },
  { { 0x4B95CA54 }, VERSIOND2_1_13C },
  { { 0x4E9DE60E }, VERSIOND2_1_13D },
  { { 0x4E9DE613 }, VERSIOND2_1_13D },
  { { 0x56D48134 }, VERSIOND2_1_14A },
  { { 0x56D48138 }, VERSIOND2_1_14A },
  { { 0x56FC78A8 }, VERSIOND2_1_14B },
  { { 0x56FC78AE }, VERSIOND2_1_14B },
  { { 0x572CDF4D }, VERSIOND2_1_14C },
  { { 0x572CDF52 }, VERSIOND2_1_14C },
  { { 0x574DDFBC }, VERSIOND2_1_14D },
  { { 0x574DDFC4 }, VERSIOND2_1_14D }
};

enum {
  GAME_EXE_TIMESTAMP_AND_D2_VERSION_COUNT =
      sizeof(GAME_EXE_TIMESTAMP_AND_D2_VERSIONS)
          / sizeof(GAME_EXE_TIMESTAMP_AND_D2_VERSIONS[0])
};

/**
 * External
 */

enum VersionD2 VersionD2_DetectFromGameExeTimestamp(
    const struct PeTimestamp* timestamp, struct SGD2Error* error) {
  struct TimestampAndD2Version search_key;
  const struct TimestampAndD2Version* search_result;

  search_key.timestamp = *timestamp;

  search_result =
      bsearch(
          &search_key,
          GAME_EXE_TIMESTAMP_AND_D2_VERSIONS,
          GAME_EXE_TIMESTAMP_AND_D2_VERSION_COUNT,
          sizeof(GAME_EXE_TIMESTAMP_AND_D2_VERSIONS[0]),
          &TimestampAndD2Version_CompareTimestampAsVoid);
  if (search_result == NULL) {
    if (error != NULL) {
        error->path = __FILEW__;
        error->line = __LINE__;
        error->function_name = L"VersionD2_DetectFromGameExeTimestamp";
        error->type = SGD2ERROR_UNEXPECTED_ERROR;
        error->unexpected_error.code =
            SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
    }
    goto error;
  }

  if (error != NULL) {
    error->type = SGD2ERROR_GOOD;
  }
  return search_result->version;

error:
  return VERSIOND2_UNSPECIFIED;
}
