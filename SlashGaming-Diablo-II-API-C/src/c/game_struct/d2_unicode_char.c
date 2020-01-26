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

#include "../../../include/c/game_struct/d2_unicode_char.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../../../include/c/game_function/d2lang/d2lang_unicode_ascii_to_unicode.h"
#include "../../../include/c/game_function/d2lang/d2lang_unicode_unicode_to_utf8.h"
#include "../../../include/c/game_function/d2lang/d2lang_unicode_utf8_to_unicode.h"
#include "../backend/error_handling.h"
#include "../../wide_macro.h"

/**
 * Static assertions
 */

static_assert(
    offsetof(struct D2_UnicodeChar_1_00, ch) == 0,
    "Incorrect member alignment."
);

static_assert(sizeof(struct D2_UnicodeChar_1_00) == 2, "Incorrect size.");

/**
 * Function definitions
 */

struct D2_UnicodeChar* D2_UnicodeChar_CreateDefault(void) {
  return D2_UnicodeChar_CreateWithAsciiChar('\0');
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateWithAsciiChar(char ch) {
  struct D2_UnicodeChar_1_00* actual_unicode_char =
      (struct D2_UnicodeChar_1_00*) malloc(sizeof(*actual_unicode_char));

  actual_unicode_char->ch = ch;

  return (struct D2_UnicodeChar*) actual_unicode_char;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateWithAsciiString(const char* str) {
  size_t str_len = strlen(str);

  struct D2_UnicodeChar_1_00* actual_unicode_char =
      (struct D2_UnicodeChar_1_00*) malloc(
          (str_len + 1) * sizeof(*actual_unicode_char)
      );

  if (actual_unicode_char == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  D2_D2Lang_Unicode_AsciiToUnicode(actual_unicode_char, str, str_len + 1);

  return (struct D2_UnicodeChar*) actual_unicode_char;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateWithUtf8String(const char* str) {
  size_t str_len = strlen(str);

  struct D2_UnicodeChar_1_00* actual_unicode_char =
      (struct D2_UnicodeChar_1_00*) malloc(
          (str_len + 1) * sizeof(*actual_unicode_char)
      );

  if (actual_unicode_char == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  D2_D2Lang_Unicode_Utf8ToUnicode(actual_unicode_char, str, str_len + 1);

  return (struct D2_UnicodeChar*) actual_unicode_char;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateWithWideString(
    const wchar_t* str
) {
  size_t str_len = wcslen(str);

  struct D2_UnicodeChar_1_00* actual_unicode_char =
      (struct D2_UnicodeChar_1_00*) malloc(
          (str_len + 1) * sizeof(*actual_unicode_char)
      );

  if (actual_unicode_char == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  for (size_t i = 0; i < str_len; i += 1) {
    actual_unicode_char[i].ch = str[i];
  }

  actual_unicode_char[str_len].ch = '\0';

  return (struct D2_UnicodeChar*) actual_unicode_char;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateArray(size_t count) {
  struct D2_UnicodeChar_1_00* actual_unicode_char =
      (struct D2_UnicodeChar_1_00*) malloc(
          count * sizeof(*actual_unicode_char)
      );

  if (actual_unicode_char == NULL) {
    ExitOnAllocationFailure(__FILEW__, __LINE__);
  }

  for (size_t i = 0; i < count; i += 1) {
    actual_unicode_char[i].ch = '\0';
  }

  return (struct D2_UnicodeChar*) actual_unicode_char;
}

void D2_UnicodeChar_Destroy(struct D2_UnicodeChar* unicode_char) {
  free(unicode_char);
}

void D2_UnicodeChar_SetCharWithAsciiChar(
    struct D2_UnicodeChar* unicode_char,
    char ch
) {
  struct D2_UnicodeChar_1_00* actual_unicode_char =
      (struct D2_UnicodeChar_1_00*) unicode_char;

  actual_unicode_char->ch = ch;
}

void D2_UnicodeChar_CopyChar(
    struct D2_UnicodeChar* ptr,
    const struct D2_UnicodeChar* src
) {
  struct D2_UnicodeChar_1_00* actual_ptr = (struct D2_UnicodeChar*) ptr;
  const struct D2_UnicodeChar_1_00* actual_src =
      (const struct D2_UnicodeChar_1_00*) src;

  actual_ptr->ch = actual_src->ch;
}
