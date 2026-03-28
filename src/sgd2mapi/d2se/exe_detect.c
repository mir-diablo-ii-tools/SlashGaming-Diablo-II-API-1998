
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

#include "sgd2mapi/d2se/exe_detect.h"

#include <stddef.h>
#include <stdlib.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/std/wchar.h>

#include "sgd2mapi/core/file_metadata/pe_timestamp.h"

/** A sorted set of PE timestamps belonging to D2SE. */
static const struct PeTimestamp EXE_TIMESTAMPS[] = {
  { 0x4DB5DC5F }
};

enum {
  EXE_TIMESTAMP_COUNT = sizeof(EXE_TIMESTAMPS) / sizeof(EXE_TIMESTAMPS[0])
};

static int PeTimestamp_CompareAsVoid(const void* lhs, const void* rhs) {
  return PeTimestamp_Compare(lhs, rhs);
}

/**
 * External
 */

int D2Se_MatchTimestamp(
    const struct PeTimestamp *timestamp, struct SGD2Error *error) {
  const struct PeTimestamp* search_result;

  search_result =
      bsearch(
          timestamp,
          EXE_TIMESTAMPS,
          EXE_TIMESTAMP_COUNT,
          sizeof(EXE_TIMESTAMPS[0]),
          &PeTimestamp_CompareAsVoid);
  error->type = SGD2ERROR_GOOD;

  return search_result != NULL;
}
