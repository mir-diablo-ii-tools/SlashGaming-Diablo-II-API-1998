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

#include "file_info.h"

#include "../error_handling.h"

#include <mdc/malloc/malloc.h>

/* Struct taken from Microsoft's example. */
struct LANGANDCODEPAGE {
  WORD wLanguage;
  WORD wCodePage;
};

void ExtractFileInfo(
    VS_FIXEDFILEINFO* file_info,
    const struct Mdc_Fs_Path* file_path
) {
  DWORD ignored;

  const wchar_t* file_path_cstr;

  void* file_version_info;
  DWORD file_version_info_size;

  BOOL is_get_file_version_info_success;
  BOOL is_ver_query_value_success;

  VS_FIXEDFILEINFO* temp_file_info;
  UINT temp_file_info_size;

  /* Check version size. */
  file_path_cstr = Mdc_Fs_Path_CStr(file_path);

  file_version_info_size = GetFileVersionInfoSizeW(
      file_path_cstr,
      &ignored
  );

  if (file_version_info_size == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoSizeW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Get the file version info.*/
  file_version_info = Mdc_malloc(file_version_info_size);

  if (file_version_info == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
    goto return_bad;
  }

  is_get_file_version_info_success = GetFileVersionInfoW(
      file_path_cstr,
      ignored,
      file_version_info_size,
      file_version_info
  );

  if (!is_get_file_version_info_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Gather all of the information into the specified buffer. */
  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      L"\\",
      (void**) &temp_file_info,
      &temp_file_info_size
  );

  if (!is_ver_query_value_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"VerQueryValueW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Copy the file info into the parameter. */
  *file_info = *temp_file_info;

  Mdc_free(file_version_info);

  return;

return_bad:
  return;
}

struct Mdc_BasicString* ExtractFileStringValue(
    struct Mdc_BasicString* string_value,
    const struct Mdc_Fs_Path* file_path,
    const wchar_t* string_name
) {
  void* realloc_result;
  DWORD ignored;

  struct Mdc_BasicString* init_string_value;

  const wchar_t* file_path_cstr;

  BOOL is_get_file_version_info_success;
  BOOL is_ver_query_value_success;
  int snwprintf_result;

  void* file_version_info;
  DWORD file_version_info_size;

  struct LANGANDCODEPAGE* lang_buffer;
  UINT lang_buffer_size;

  wchar_t* temp_file_string_value;

  UINT file_string_value_size;

  wchar_t* file_string_sub_block;
  size_t file_string_sub_block_capacity;
  size_t file_string_sub_block_new_capacity;

  /* Check version size. */
  file_path_cstr = Mdc_Fs_Path_CStr(file_path);

  file_version_info_size = GetFileVersionInfoSizeW(
      file_path_cstr,
      &ignored
  );

  if (file_version_info_size == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoSizeW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Get the file version info.*/
  file_version_info = Mdc_malloc(file_version_info_size);

  if (file_version_info == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
    goto return_bad;
  }

  is_get_file_version_info_success = GetFileVersionInfoW(
      file_path_cstr,
      ignored,
      file_version_info_size,
      file_version_info
  );

  if (!is_get_file_version_info_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Gather all of the information into the specified buffer. */
  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      L"\\VarFileInfo\\Translation",
      (void**) &lang_buffer,
      &lang_buffer_size
  );

  if (!is_ver_query_value_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"VerQueryValueW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Format text into the file string sub block. */
  file_string_sub_block_new_capacity = 1;
  file_string_sub_block = NULL;

  do {
    file_string_sub_block_capacity = file_string_sub_block_new_capacity;

    realloc_result = Mdc_realloc(
        file_string_sub_block,
        file_string_sub_block_capacity * sizeof(file_string_sub_block[0])
    );

    if (realloc_result == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
      goto return_bad;
    }

    file_string_sub_block = realloc_result;

    snwprintf_result = _snwprintf(
        file_string_sub_block,
        file_string_sub_block_capacity,
        L"\\StringFileInfo\\%04x%04x\\%ls",
        lang_buffer[0].wLanguage,
        lang_buffer[0].wCodePage,
        string_name
    );

    file_string_sub_block_new_capacity *= 2;
  } while (snwprintf_result == -1
      || snwprintf_result == file_string_sub_block_capacity);

  /* Query the file string value. */
  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      file_string_sub_block,
      (void**) &temp_file_string_value,
      &file_string_value_size
  );

  if (!is_ver_query_value_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"VerQueryValueW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  /* Return a copy of the file string value. */
  init_string_value = Mdc_BasicString_InitFromCStr(
      string_value,
      Mdc_CharTraitsWChar_GetCharTraits(),
      temp_file_string_value
  );

  if (init_string_value != string_value) {
    ExitOnMdcFunctionFailure(
        L"Mdc_BasicString_InitFromCStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  Mdc_free(file_string_sub_block);
  Mdc_free(file_version_info);

  return string_value;

return_bad:
  return NULL;
}
