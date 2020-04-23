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

#include "encoding.h"

#include <windows.h>
#include <stddef.h>
#include <stdlib.h>

#include "error_handling.h"
#include "../../wide_macro.h"

wchar_t* ConvertUtf8ToWide(
    wchar_t* wide_string,
    const char* utf8_string,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  // Determine the number of characters needed.
  size_t num_wide_chars = MultiByteToWideChar(
      CP_UTF8,
      MB_ERR_INVALID_CHARS,
      utf8_string,
      -1,
      wide_string,
      0
  );

  if (num_wide_chars == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"MultiByteToWideChar",
        GetLastError(),
        source_code_file_path,
        source_code_line
    );
  }

  // Allocate space if the wide_string is NULL.
  if (wide_string == NULL) {
    wide_string = (wchar_t*) malloc(
        num_wide_chars * sizeof(wide_string[0])
    );

    if (wide_string == NULL) {
      ExitOnAllocationFailure(source_code_file_path, source_code_line);
    }
  }

  // Convert the UTF-8 string to wide string. Check that there was no failure.
  size_t converted_chars = MultiByteToWideChar(
      CP_UTF8,
      MB_ERR_INVALID_CHARS,
      utf8_string,
      -1,
      wide_string,
      num_wide_chars
  );

  if (converted_chars == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"MultiByteToWideChar",
        GetLastError(),
        source_code_file_path,
        source_code_line
    );
  } else if (converted_chars < num_wide_chars) {
    ExitOnGeneralFailure(
        L"The number of converted characters is less than the intended "
        L"count.",
        L"String Conversion Failed",
        __FILEW__,
        __LINE__
    );
  }

  return wide_string;
}

char* ConvertWideToUtf8(
    char* utf8_string,
    const wchar_t* wide_string,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  // Determine the number of characters needed.
  size_t num_utf8_chars = WideCharToMultiByte(
      CP_UTF8,
      WC_ERR_INVALID_CHARS,
      wide_string,
      -1,
      utf8_string,
      0,
      NULL,
      NULL
  );

  if (num_utf8_chars == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"WideCharToMultiByte",
        GetLastError(),
        source_code_file_path,
        source_code_line
    );
  }

  // Allocate space if the UTF-8 string is NULL.
  if (utf8_string == NULL) {
    utf8_string = (char*) malloc(num_utf8_chars * sizeof(utf8_string[0]));

    if (utf8_string == NULL) {
      ExitOnAllocationFailure(source_code_file_path, source_code_line);
    }
  }

  // Convert the UTF-8 string to wide string. Check that there was no failure.
  size_t converted_chars = WideCharToMultiByte(
      CP_UTF8,
      WC_ERR_INVALID_CHARS,
      wide_string,
      -1,
      utf8_string,
      num_utf8_chars,
      NULL,
      NULL
  );

  if (converted_chars == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"WideCharToMultiByte",
        GetLastError(),
        source_code_file_path,
        source_code_line
    );
  } else if (converted_chars < num_utf8_chars) {
    ExitOnGeneralFailure(
        L"The number of converted characters is less than the intended "
        L"count.",
        L"String Conversion Failed",
        __FILEW__,
        __LINE__
    );
  }

  return utf8_string;
}

wchar_t* ConvertMultibyteToWide(
    wchar_t* wide_string,
    const char* multibyte_string
) {
  size_t wide_string_len;
  size_t wide_string_size;
  mbstate_t mbstate;

  /* Determine the length of the new string. */
  memset(&mbstate, 0, sizeof(mbstate_t));
  wide_string_len = mbsrtowcs(NULL, &multibyte_string, 0, &mbstate);
  wide_string_size = (wide_string_len + 1) * sizeof(wide_string[0]);

  if (wide_string == NULL) {
    wide_string = malloc(wide_string_size);

    if (wide_string == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
    }
  }

  /* Convert multibyte string to wide string. */
  memset(&mbstate, 0, sizeof(mbstate_t));

  mbsrtowcs(
      wide_string,
      &multibyte_string,
      wide_string_size,
      &mbstate
  );

  wide_string[wide_string_len] = L'\0';

  return wide_string;
}

char* ConvertWideToMultibyte(
    char* multibyte_string,
    const wchar_t* wide_string
) {
  size_t multibyte_string_len;
  size_t multibyte_string_size;
  mbstate_t mbstate;

  /* Determine the length of the new string. */
  memset(&mbstate, 0, sizeof(mbstate_t));
  multibyte_string_len = wcsrtombs(NULL, &wide_string, 0, &mbstate);
  multibyte_string_size =
      (multibyte_string_len + 1) * sizeof(multibyte_string[0]);

  if (multibyte_string == NULL) {
    multibyte_string = malloc(multibyte_string_size);

    if (multibyte_string == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
    }
  }

  /* Convert wide string to multibyte string. */
  memset(&mbstate, 0, sizeof(mbstate_t));

  wcsrtombs(
      multibyte_string,
      &wide_string,
      multibyte_string_size,
      &mbstate
  );

  multibyte_string[multibyte_string_len] = '\0';

  return multibyte_string;
}
