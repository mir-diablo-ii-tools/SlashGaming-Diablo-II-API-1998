/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2020  Mir Drualga
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

#include "file_version.h"

struct GameVersionTableEntry {
  struct FileVersion file_version;
  enum D2_GameVersion game_version;
};

static const struct GameVersionTableEntry kGameVersionTable[] = {
    /* 1.0.0.1 */
    { { 1, 0, 0, 1 }, VERSION_1_01 },

    /* 1.0.2.0 */
    { { 1, 0, 2, 0 }, VERSION_1_02 },

    /* 1.0.3.0 */
    { { 1, 0, 3, 0 }, VERSION_1_03 },

    /* 1.0.4.1 */
    { { 1, 0, 4, 1 }, VERSION_1_04B_C },

    /* 1.0.4.2 */
    { { 1, 0, 4, 2 }, VERSION_1_04B_C },

    /* 1.0.5.0 */
    { { 1, 0, 5, 0 }, VERSION_1_05 },

    /* 1.0.5.1 */
    { { 1, 0, 5, 1 }, VERSION_1_05B },

    /* 1.0.6.0 */
    { { 1, 0, 6, 0 }, VERSION_1_06B },

    /* 1.0.7.0 */
    { { 1, 0, 7, 0 }, VERSION_1_07 },

    /* 1.0.8.28 */
    { { 1, 0, 8, 28 }, VERSION_1_08 },

    /* 1.0.8.28 */
    { { 1, 0, 8, 28 }, VERSION_1_08 },

    /* 1.0.9.19 */
    { { 1, 0, 9, 19 }, VERSION_1_09 },

    /* 1.0.9.20 */
    { { 1, 0, 9, 20 }, VERSION_1_09B },

    /* 1.0.9.22 */
    { { 1, 0, 9, 22 }, VERSION_1_09D },

    /* 1.0.10.9 */
    { { 1, 0, 10, 9 }, VERSION_1_10_BETA },

    /* 1.0.10.10 */
    { { 1, 0, 10, 10 }, VERSION_1_10S_BETA },

    /* 1.0.10.39 */
    { { 1, 0, 10, 39 }, VERSION_1_10 },

    /* 1.0.11.45 */
    { { 1, 0, 11, 45 }, VERSION_1_11 },

    /* 1.0.11.46 */
    { { 1, 0, 11, 46 }, VERSION_1_11B },

    /* 1.0.12.49 */
    { { 1, 0, 12, 49 }, VERSION_1_12A },

    /* 1.0.13.55 */
    { { 1, 0, 13, 55 }, VERSION_1_13A_PTR },

    /* 1.0.13.60 */
    { { 1, 0, 13, 60 }, VERSION_1_13C },

    /* 1.0.13.64 */
    { { 1, 0, 13, 64 }, VERSION_1_13D },

    /* 1.14.0.64 */
    { { 1, 14, 0, 64 }, LOD_1_14A },

    /* 1.14.1.68 */
    { { 1, 14, 1, 68 }, LOD_1_14B },

    /* 1.14.2.70 */
    { { 1, 14, 2, 70 }, LOD_1_14C },

    /* 1.14.3.71 */
    { { 1, 14, 3, 71 }, LOD_1_14D }
};

enum FILE_SCOPE_CONSTANTS_02 {
  kGameVersionTableCount = sizeof(kGameVersionTable)
      / sizeof(kGameVersionTable[0])
};

static int FileVersion_CompareAll(
    const struct FileVersion* version1,
    const struct FileVersion* version2
) {
  int diff;

  diff = version1->major_left - version2->major_left;
  if (diff != 0) {
    return diff;
  }

  diff = version1->major_right - version2->major_right;
  if (diff != 0) {
    return diff;
  }

  diff = version1->minor_left - version2->minor_left;
  if (diff != 0) {
    return diff;
  }

  diff = version1->minor_right - version2->minor_right;
  if (diff != 0) {
    return diff;
  }

  return 0;
}

static int FileVersion_CompareAsVoidAll(
    const void* version1,
    const void* version2
) {
  return FileVersion_CompareAll(
      (const struct FileVersion*) version1,
      (const struct FileVersion*) version2
  );
}

static int GameVersionTableEntry_CompareKey(
    const struct GameVersionTableEntry* entry1,
    const struct GameVersionTableEntry* entry2
) {
  return FileVersion_CompareAll(
      &entry1->file_version,
      &entry2->file_version
  );
}

static int GameVersionTableEntry_CompareAsVoidKey(
    const void* entry1,
    const void* entry2
) {
  return GameVersionTableEntry_CompareKey(
      (const struct GameVersionTableEntry*) entry1,
      (const struct GameVersionTableEntry*) entry2
  );
}

enum D2_GameVersion FileVersion_SearchGameVersionTable(
    const struct FileVersion* file_version
) {
  struct GameVersionTableEntry search_entry;
  struct GameVersionTableEntry* search_result;

  search_entry.file_version = *file_version;

  search_result = bsearch(
      &search_entry,
      kGameVersionTable,
      kGameVersionTableCount,
      sizeof(kGameVersionTable[0]),
      &GameVersionTableEntry_CompareAsVoidKey
  );

  return search_result->game_version;
}
