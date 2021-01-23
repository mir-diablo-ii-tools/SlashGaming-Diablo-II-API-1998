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

#include "file_version.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>

const VS_FIXEDFILEINFO Vs_FixedFileInfo_kUninit = { 0 };

/**
 * File version struct
 */

struct FileVersion {
  DWORD major_version_left;
  DWORD major_version_right;
  DWORD minor_version_left;
  DWORD minor_version_right;
};

struct FileVersionTableEntry {
  struct FileVersion file_version;
  enum D2_GameVersion game_version;
};

static const struct FileVersionTableEntry
kFileVersionSortedTable[] = {
    { { 1, 0, 0, 1 }, D2_GameVersion_k1_01 },
    { { 1, 0, 2, 0 }, D2_GameVersion_k1_02 },
    { { 1, 0, 3, 0 }, D2_GameVersion_k1_03 },

    /* 1.04B and 1.04C use the same DLLs. */
    { { 1, 0, 4, 1 }, D2_GameVersion_k1_04B_C },
    { { 1, 0, 4, 2 }, D2_GameVersion_k1_04B_C },
    { { 1, 0, 5, 0 }, D2_GameVersion_k1_05 },
    { { 1, 0, 5, 1 }, D2_GameVersion_k1_05B },

    /*
    * 1.06 & 1.06B have the same version #, but use completely
    * different DLLs.
    */
    { { 1, 0, 6, 0 }, D2_GameVersion_k1_06B },

    /*
    * 1.07 Beta & 1.07 have the same version #, but use completely
    * different DLLs.
    */
    { { 1, 0, 7, 0 }, D2_GameVersion_k1_07 },
    { { 1, 0, 8, 28 }, D2_GameVersion_k1_08 },
    { { 1, 0, 9, 19 }, D2_GameVersion_k1_09 },
    { { 1, 0, 9, 20 }, D2_GameVersion_k1_09B },
    { { 1, 0, 9, 22 }, D2_GameVersion_k1_09D },
    { { 1, 0, 10, 9 }, D2_GameVersion_k1_10Beta },
    { { 1, 0, 10, 10 }, D2_GameVersion_k1_10SBeta },
    { { 1, 0, 10, 39 }, D2_GameVersion_k1_10 },
    { { 1, 0, 11, 45 }, D2_GameVersion_k1_11 },
    { { 1, 0, 11, 46 }, D2_GameVersion_k1_11B },
    { { 1, 0, 12, 49 }, D2_GameVersion_k1_12A },
    { { 1, 0, 13, 55 }, D2_GameVersion_k1_13ABeta },
    { { 1, 0, 13, 60 }, D2_GameVersion_k1_13C },
    { { 1, 0, 13, 64 }, D2_GameVersion_k1_13D },

    { { 1, 0, 14, 64 }, D2_GameVersion_kLod1_14A },
    { { 1, 0, 14, 68 }, D2_GameVersion_kLod1_14B },
    { { 1, 0, 14, 70 }, D2_GameVersion_kLod1_14C },
    { { 1, 0, 14, 71 }, D2_GameVersion_kLod1_14D },
};

enum {
  kFileVersionSortedTableCount = sizeof(kFileVersionSortedTable) /
      sizeof(kFileVersionSortedTable[0])
};

static int FileVersion_Compare(
    const struct FileVersion* file_version1,
    const struct FileVersion* file_version2
) {
  DWORD major_version_left1;
  DWORD major_version_left2;
  DWORD major_version_right1;
  DWORD major_version_right2;
  DWORD minor_version_left1;
  DWORD minor_version_left2;
  DWORD minor_version_right1;
  DWORD minor_version_right2;

  if (file_version1 == file_version2) {
    return 0;
  }

  major_version_left1 = file_version1->major_version_left;
  major_version_left2 = file_version2->major_version_left;

  if (major_version_left1 < major_version_left2) {
    return -1;
  } else if (major_version_left1 > major_version_left2) {
    return 1;
  }

  major_version_right1 = file_version1->major_version_right;
  major_version_right2 = file_version2->major_version_right;

  if (major_version_right1 < major_version_right2) {
    return -1;
  } else if (major_version_right1 > major_version_right2) {
    return 1;
  }

  minor_version_left1 = file_version1->minor_version_left;
  minor_version_left2 = file_version2->minor_version_left;

  if (minor_version_left1 < minor_version_left2) {
    return -1;
  } else if (minor_version_left1 > minor_version_left2) {
    return 1;
  }

  minor_version_right1 = file_version1->minor_version_right;
  minor_version_right2 = file_version2->minor_version_right;

  if (minor_version_right1 < minor_version_right2) {
    return -1;
  } else if (minor_version_right1 > minor_version_right2) {
    return 1;
  }

  return 0;
}

static int FileVersionTableEntry_CompareKey(
    const struct FileVersionTableEntry* table_entry1,
    const struct FileVersionTableEntry* table_entry2
) {
  return FileVersion_Compare(
      &table_entry1->file_version,
      &table_entry2->file_version
  );
}

static int FileVersionTableEntry_CompareKeyAsVoid(
    const void* table_entry1,
    const void* table_entry2
) {
  return FileVersionTableEntry_CompareKey(table_entry1, table_entry2);
}

/**
 * External functions
 */

VS_FIXEDFILEINFO Mapi_GetFixedFileInfo(const wchar_t* file_path) {
  /*
  * All the code for this function originated from StackOverflow user
  * crashmstr. Some parts were refactored and altered for clarity and
  * correctness.
  */

  VS_FIXEDFILEINFO fixed_file_info;

  DWORD ignored;

  BOOL is_get_file_version_info_success;
  BOOL is_ver_query_value_success;

  void* file_version_info;
  DWORD file_version_info_size;

  UINT fixed_file_info_size;
  VS_FIXEDFILEINFO* fixed_file_info_src;

  /* Check version size. */
  file_version_info_size = GetFileVersionInfoSizeW(
      file_path,
      &ignored
  );

  if (file_version_info_size == 0) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoSizeW",
        GetLastError()
    );

    goto return_bad;
  }

  /* Get the file version info. */
  file_version_info = Mdc_malloc(file_version_info_size);
  if (file_version_info == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  ignored = 0;
  is_get_file_version_info_success = GetFileVersionInfoW(
      file_path,
      ignored,
      file_version_info_size,
      file_version_info
  );

  if (!is_get_file_version_info_success) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoW",
        GetLastError()
    );

    goto free_file_version_info;
  }

  /*
  * Gather all of the information into the specified buffer, then
  * check version info signature.
  */

  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      L"\\",
      &fixed_file_info_src,
      &fixed_file_info_size
  );

  if (!is_ver_query_value_success) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    goto free_file_version_info;
  }

  fixed_file_info = *fixed_file_info_src;

  Mdc_free(file_version_info);

  return fixed_file_info;

free_file_version_info:
  Mdc_free(file_version_info);

return_bad:
  return Vs_FixedFileInfo_kUninit;
}

enum D2_GameVersion Mapi_GameVersion_GetFromFileVersion(
    const VS_FIXEDFILEINFO* fixed_file_info
) {
  struct FileVersionTableEntry file_version_table_entry_search_key;
  const struct FileVersionTableEntry* file_version_table_entry_search_result;

  struct FileVersion* file_version_search_key;

  file_version_search_key =
      &file_version_table_entry_search_key.file_version;

  file_version_search_key->major_version_left =
      (fixed_file_info->dwFileVersionMS >> 16) & 0xFFFF;
  file_version_search_key->major_version_right =
      (fixed_file_info->dwFileVersionMS >> 0) & 0xFFFF;
  file_version_search_key->minor_version_left =
      (fixed_file_info->dwFileVersionLS >> 16) & 0xFFFF;
  file_version_search_key->minor_version_right =
      (fixed_file_info->dwFileVersionLS >> 0) & 0xFFFF;

  file_version_table_entry_search_result = bsearch(
      &file_version_table_entry_search_key,
      kFileVersionSortedTable,
      kFileVersionSortedTableCount,
      sizeof(kFileVersionSortedTable[0]),
      &FileVersionTableEntry_CompareKeyAsVoid
  );

  return file_version_table_entry_search_result->game_version;
}
