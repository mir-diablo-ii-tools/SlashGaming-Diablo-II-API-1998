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

static char* ConvertWideToChar(
    char* char_string,
    const wchar_t* wide_string,
    unsigned int code_page,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  /* Determine the number of characters needed. */
  int num_chars = WideCharToMultiByte(
      code_page,
      0,
      wide_string,
      -1,
      char_string,
      0,
      NULL,
      NULL
  );

  if (num_chars == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"WideCharToMultiByte",
        GetLastError(),
        source_code_file_path,
        source_code_line
    );
  }

  /* Allocate space if the char string is NULL. */
  if (char_string == NULL) {
    char_string = (char*) malloc(
        num_chars * sizeof(char_string[0])
    );

    if (char_string == NULL) {
      ExitOnAllocationFailure(
          source_code_file_path,
          source_code_line
      );
    }
  }

  /*
  * Convert the wide string to char string. Check that there was no failure.
  */
  int converted_chars = WideCharToMultiByte(
      code_page,
      0,
      wide_string,
      -1,
      char_string,
      num_chars,
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
  } else if (converted_chars < num_chars) {
    ExitOnGeneralFailure(
        L"The number of converted characters is less than the intended "
        L"count.",
        L"String Conversion Failed",
        source_code_file_path,
        source_code_line
    );
  }

  return char_string;
}

static wchar_t* ConvertCharToWide(
    wchar_t* wide_string,
    const char* char_string,
    unsigned int code_page,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  /* Determine the number of characters needed. */
  int num_wide_chars = MultiByteToWideChar(
      code_page,
      0,
      char_string,
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

  /* Allocate space if the wide_string is NULL. */
  if (wide_string == NULL) {
    wide_string = (wchar_t*) malloc(
        num_wide_chars * sizeof(wide_string[0])
    );

    if (wide_string == NULL) {
      ExitOnAllocationFailure(
          source_code_file_path,
          source_code_line
      );
    }
  }

  /*
  * Convert the UTF-8 string to wide string. Check that there was no failure.
  */
  int converted_chars = MultiByteToWideChar(
      code_page,
      0,
      char_string,
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
        source_code_file_path,
        source_code_line
    );
  }

  return wide_string;
}

wchar_t* ConvertUtf8ToWide(
    wchar_t* wide_string,
    const char* utf8_string,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  return ConvertCharToWide(
      wide_string,
      utf8_string,
      CP_UTF8,
      source_code_file_path,
      source_code_line
  );
}

char* ConvertWideToUtf8(
    char* utf8_string,
    const wchar_t* wide_string,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  return ConvertWideToChar(
      utf8_string,
      wide_string,
      CP_UTF8,
      source_code_file_path,
      source_code_line
  );
}

wchar_t* ConvertMultibyteToWide(
    wchar_t* wide_string,
    const char* multibyte_string,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  return ConvertCharToWide(
      wide_string,
      multibyte_string,
      CP_ACP,
      source_code_file_path,
      source_code_line
  );
}

char* ConvertWideToMultibyte(
    char* multibyte_string,
    const wchar_t* wide_string,
    const wchar_t* source_code_file_path,
    int source_code_line
) {
  return ConvertWideToChar(
      multibyte_string,
      wide_string,
      CP_ACP,
      source_code_file_path,
      source_code_line
  );
}
