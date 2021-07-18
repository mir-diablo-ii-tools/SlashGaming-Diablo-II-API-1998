/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "d2se_game_version.h"

#include <stddef.h>
#include <stdlib.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/filew.h>

struct VersionTableEntry {
  const wchar_t* key;
  enum D2_GameVersion value;
};

static int VersionTableEntry_CompareKey(
    const struct VersionTableEntry* entry1,
    const struct VersionTableEntry* entry2
) {
  return wcscmp(entry1->key, entry2->key);
}

static int VersionTableEntry_CompareKeyAsVoid(
    const void* entry1,
    const void* entry2
) {
  return VersionTableEntry_CompareKey(entry1, entry2);
}

/*
 * D2SE detects version strings in a case-insensitive manner, so all
 * version strings need to be lower case.
 */
static const struct VersionTableEntry kVersionSortedTable[] = {
    { L"1.07", D2_GameVersion_k1_07 },
    { L"1.08", D2_GameVersion_k1_08 },
    { L"1.09b", D2_GameVersion_k1_09B },
    { L"1.09d", D2_GameVersion_k1_09D },
    { L"1.10f", D2_GameVersion_k1_10 },
    { L"1.11b", D2_GameVersion_k1_11B },
    { L"1.12a", D2_GameVersion_k1_12A },
    { L"1.13c", D2_GameVersion_k1_13C }
};

enum {
  kVersionSortedTableCount = sizeof(kVersionSortedTable)
      / sizeof(kVersionSortedTable[0]),

  kVersionStringMaxLength = 5,
  kVersionStringCapacity = kVersionStringMaxLength + 1,
};

static void ExitOnUnknownD2seVersionString(
    const wchar_t* version_str,
    const wchar_t* file_path,
    int line
) {
  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"Unknown D2SE.ini Diablo II version string %ls.",
      file_path,
      line,
      version_str
  );
}

enum D2_GameVersion SearchTable(const wchar_t* version_str) {
  const struct VersionTableEntry* search_result;

  search_result = bsearch(
      &version_str,
      kVersionSortedTable,
      kVersionSortedTableCount,
      sizeof(kVersionSortedTable[0]),
      &VersionTableEntry_CompareKeyAsVoid
  );

  if (search_result == NULL) {
    ExitOnUnknownD2seVersionString(version_str, __FILEW__, __LINE__);
    return -1;
  }

  return search_result->value;
}

/**
 * External
 */

enum D2_GameVersion D2seIni_GuessGameVersion(const wchar_t* version_str) {
  size_t i;

  size_t version_str_length;
  wchar_t lower_version_str[kVersionStringCapacity];

  /*
   * The table uses lowercase version strings, therefore the input
   * version string should be made lowercase.
   */
  for (i = 0; version_str[i] != L'\0' && i < kVersionStringCapacity; ++i) {
    lower_version_str[i] = towlower(version_str[i]);
  }

  version_str_length = i;
  lower_version_str[version_str_length] = L'\0';

  if (version_str_length > kVersionStringMaxLength) {
    ExitOnUnknownD2seVersionString(version_str, __FILEW__, __LINE__);
    return -1;
  }

  return SearchTable(lower_version_str);
}
