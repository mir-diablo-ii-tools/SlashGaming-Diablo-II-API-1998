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

#include <stdlib.h>
#include <windows.h>
#include <wchar.h>

/**
 * Error string lengths, including null-terminator.
 */
enum {
  ERROR_MESSAGE_LENGTH = 1024,
  ERROR_CAPTION_LENGTH = 256
};

static const wchar_t* kFunctionFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"\n"
    L"The function %s failed with error code %X.";

static const wchar_t* kGeneralFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"\n"
    L"%s";

static const wchar_t* kConstantMappingMissingErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"\n"
    L"Constant with value %d could not be mapped.";

void ExitOnGeneralFailure(
    const wchar_t* message,
    const wchar_t* caption,
    const wchar_t* file_name,
    int line
) {
#ifndef NDEBUG
  wchar_t full_message[ERROR_MESSAGE_LENGTH];

  swprintf(
      full_message,
      sizeof(full_message) / sizeof(full_message[0]),
      kGeneralFailErrorFormat,
      file_name,
      line,
      message
  );

  MessageBoxW(
      NULL,
      full_message,
      caption,
      MB_OK | MB_ICONERROR
  );
#endif /* NDEBUG */

  exit(EXIT_FAILURE);
}

void ExitOnAllocationFailure(
    const wchar_t* file_name,
    int line
) {
  ExitOnGeneralFailure(
      L"Allocation function failed.",
      L"Memory Allocation Failed",
      file_name,
      line
  );
}

void ExitOnConstantMappingMissing(
    int value,
    const wchar_t* file_name,
    int line
) {
#ifndef NDEBUG
  wchar_t full_message[ERROR_MESSAGE_LENGTH];

  swprintf(
      full_message,
      sizeof(full_message) / sizeof(full_message[0]),
      kConstantMappingMissingErrorFormat,
      file_name,
      line,
      value
  );

  MessageBoxW(
      NULL,
      full_message,
      L"Constant Error",
      MB_OK | MB_ICONERROR
  );
#endif /* NDEBUG */

  exit(EXIT_FAILURE);
}

void ExitOnCallOnceFailure(const wchar_t* file_name, int line) {
  ExitOnGeneralFailure(
      L"pthread_once failed.",
      L"Call Once Failed",
      file_name,
      line
  );
}

void ExitOnWindowsFunctionFailureWithLastError(
    const wchar_t* function_name,
    DWORD last_error,
    const wchar_t* file_name,
    int line
) {
#ifndef NDEBUG
  wchar_t full_message[ERROR_MESSAGE_LENGTH];

  swprintf(
      full_message,
      sizeof(full_message) / sizeof(full_message[0]),
      kFunctionFailErrorFormat,
      file_name,
      line,
      function_name,
      last_error
  );

  wchar_t message_box_caption[ERROR_CAPTION_LENGTH];
  swprintf(
      message_box_caption,
      sizeof(message_box_caption) / sizeof(message_box_caption[0]),
      L"%s Failed",
      function_name
  );

  MessageBoxW(
      NULL,
      full_message,
      message_box_caption,
      MB_OK | MB_ICONERROR
  );
#endif /* NDEBUG */

  exit(EXIT_FAILURE);
}
