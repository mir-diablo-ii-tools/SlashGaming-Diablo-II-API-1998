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

#ifndef SGD2MAPI_C_CORE_ERROR_ERROR_H_
#define SGD2MAPI_C_CORE_ERROR_ERROR_H_

#include <windows.h>

#include "sgd2mapi/core/dllapi_c_define.inc"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

enum SGD2ErrorType {
  SGD2ERROR_UNDEFINED = 0,

  /** No error; everything is good. */
  SGD2ERROR_GOOD = 1,
  /** Standard library error. */
  SGD2ERROR_STDLIB_ERROR = 2,
  /** Windows error. */
  SGD2ERROR_WINDOWS_ERROR = 3,
  /** Unexpected error. */
  SGD2ERROR_UNEXPECTED_ERROR = 4
};

/* Next ID: 2 */
enum SGD2StdlibErrorCode {
  SGD2STDLIBERRORCODE_UNDEFINED = 0,

  /* Memory allocation (malloc, calloc, or realloc) failed. */
  SGD2STDLIBERRORCODE_MEM_ALLOC_FAILED = 1
};

struct SGD2StdlibError {
  enum SGD2StdlibErrorCode code;
};

struct SGD2WindowsError {
  DWORD code;
};

enum SGD2UnexpectedErrorCode {
  SGD2UNEXPECTEDERRORCODE_UNDEFINED = 0,

  SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING = 1
};

struct SGD2UnexpectedError {
  enum SGD2UnexpectedErrorCode code;
};

struct SGD2Error {
  int line;
  const wchar_t* path;
  const wchar_t* function_name;

  enum SGD2ErrorType type;
  union {
    struct SGD2StdlibError stdlib_error;
    struct SGD2WindowsError windows_error;
    struct SGD2UnexpectedError unexpected_error;
  };
};

#ifdef __cplusplus
}  /* extern "C" */
#endif  /* __cplusplus */

#include "sgd2mapi/core/dllapi_c_undef.inc"
#endif /* SGD2MAPI_C_CORE_ERROR_ERROR_H_ */
