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

#include "error_handling.h"

#include <stdarg.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>

/**
 * Error string lengths, including null-terminator.
 */
enum {
  kErrorMessageFormatCapacity = 512,
  kFullErrorMessageCapacity = 1024,
};

static const wchar_t* const kGeneralFailErrorFormat =
    L"File: %ls \n"
    L"Line: %d \n"
    L"\n"
    L"%ls";

static wchar_t error_message_format[kFullErrorMessageCapacity];
static wchar_t full_error_message[kFullErrorMessageCapacity];

void ExitFormattedOnGeneralFailure(
    const wchar_t* caption,
    const wchar_t* file_name,
    int line,
    const wchar_t* text_format,
    ...
) {
  va_list args;

  _snwprintf(
      error_message_format,
      kErrorMessageFormatCapacity,
      kGeneralFailErrorFormat,
      file_name,
      line,
      text_format
  );

  error_message_format[kErrorMessageFormatCapacity - 1] = L'\0';

  va_start(args, text_format);
  _vsnwprintf(
      full_error_message,
      kFullErrorMessageCapacity,
      error_message_format,
      args
  );
  va_end(args);

  full_error_message[kFullErrorMessageCapacity - 1] = L'\0';

  MessageBoxW(
      NULL,
      full_error_message,
      caption,
      MB_OK | MB_ICONERROR
  );

  exit(EXIT_FAILURE);
}

void ExitOnGeneralFailure(
    const wchar_t* message,
    const wchar_t* caption,
    const wchar_t* file_name,
    int line
) {
  swprintf(
      full_error_message,
      kFullErrorMessageCapacity,
      kGeneralFailErrorFormat,
      file_name,
      line,
      message
  );

  MessageBoxW(
      NULL,
      full_error_message,
      caption,
      MB_OK | MB_ICONERROR
  );

  exit(EXIT_FAILURE);
}

void ExitOnAllocationFailure(
    const wchar_t* file_name,
    int line
) {
  ExitFormattedOnGeneralFailure(
      L"Error",
      file_name,
      line,
      L"Memory allocation function failed."
  );
}

void ExitOnConstantMappingMissing(
    int value,
    const wchar_t* file_name,
    int line
) {
  ExitFormattedOnGeneralFailure(
      L"Error",
      file_name,
      line,
      L"Constant with value %d could not be mapped.",
      value
  );
}

void ExitOnCallOnceFailure(const wchar_t* file_name, int line) {
  ExitFormattedOnGeneralFailure(
      L"Error",
      file_name,
      line,
      L"call_once failed"
  );
}

void ExitOnWindowsFunctionFailureWithLastError(
    const wchar_t* function_name,
    DWORD last_error,
    const wchar_t* file_name,
    int line
) {
  ExitFormattedOnGeneralFailure(
      L"Error",
      file_name,
      line,
      L"The function %ls failed with error code 0x%X.",
      function_name,
      last_error
  );
}
