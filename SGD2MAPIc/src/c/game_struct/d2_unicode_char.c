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

#include <string.h>

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>
#include <mdc/wchar_t/wide_decoding.h>
#include "../../../include/c/game_function/d2lang/d2lang_unicode_ascii_to_unicode.h"
#include "../../../include/c/game_function/d2lang/d2lang_unicode_unicode_to_utf8.h"
#include "../../../include/c/game_function/d2lang/d2lang_unicode_utf8_to_unicode.h"

/**
 * Function definitions
 */

struct D2_UnicodeChar* D2_UnicodeChar_CreateEmpty(void) {
  return D2_UnicodeChar_CreateFromAsciiChar('\0');
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateFromAsciiChar(char ch) {
  union D2_UnicodeChar_Wrapper wrapper;

  wrapper.ptr_1_00 = Mdc_malloc(sizeof(*wrapper.ptr_1_00));
  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  wrapper.ptr_1_00->ch = ch;

  return (struct D2_UnicodeChar*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateFromAsciiString(const char* str) {
  size_t i;

  union D2_UnicodeChar_Wrapper wrapper; 
  size_t str_len;

  str_len = strlen(str);

  wrapper.ptr_1_00 = Mdc_malloc(
      (str_len + 1) * sizeof(wrapper.ptr_1_00[0])
  );

  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  for (i = 0; i < str_len; i += 1) {
    wrapper.ptr_1_00[i].ch = str[i];
  }

  wrapper.ptr_1_00[i].ch = '\0'; 

  return (struct D2_UnicodeChar*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateFromUtf8String(const char* str) {
  union D2_UnicodeChar_Wrapper wrapper;
  size_t str_len;
  wchar_t* decode_result;

  str_len = Mdc_Wide_DecodeUtf8Length(str);

  wrapper.ptr_1_00 = Mdc_malloc((str_len + 1) * sizeof(wrapper.ptr_1_00[0]));

  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  decode_result = Mdc_Wide_DecodeUtf8((wchar_t*) wrapper.ptr_1_00, str);
  if (decode_result != (wchar_t*) wrapper.ptr_1_00) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"%ls failed.",
        __FILEW__,
        __LINE__,
        L"Mdc_Wide_DecodeUtf8"
    );

    goto free_wrapper;
  }

  return (struct D2_UnicodeChar*) wrapper.ptr_1_00;

free_wrapper:
  Mdc_free(*(void**) &wrapper);

return_bad:
  return NULL;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateFromWideString(
    const wchar_t* str
) {
  union D2_UnicodeChar_Wrapper wrapper;

  size_t str_len;

  str_len = wcslen(str);

  wrapper.ptr_1_00 = Mdc_malloc(
      (str_len + 1) * sizeof(*wrapper.ptr_1_00)
  );

  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  wcscpy((wchar_t*) wrapper.ptr_1_00, str);

  return (struct D2_UnicodeChar*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateArray(size_t count) { 
  union D2_UnicodeChar_Wrapper wrapper;

  wrapper.ptr_1_00 = Mdc_malloc(count * sizeof(wrapper.ptr_1_00[0]));
  if (wrapper.ptr_1_00 == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  return (struct D2_UnicodeChar*) wrapper.ptr_1_00;

return_bad:
  return NULL;
}

void D2_UnicodeChar_Destroy(struct D2_UnicodeChar* unicode_char) {
  Mdc_free(unicode_char);
}

struct D2_UnicodeChar* D2_UnicodeChar_AssignMembers(
    struct D2_UnicodeChar* dest,
    const struct D2_UnicodeChar* src
) {
  union D2_UnicodeChar_Wrapper dest_wrapper;
  union D2_UnicodeChar_View src_view;

  dest_wrapper.ptr_1_00 = (struct D2_UnicodeChar_1_00*) dest;
  src_view.ptr_1_00 = (const struct D2_UnicodeChar_1_00*) src;

  *dest_wrapper.ptr_1_00 = *src_view.ptr_1_00;

  return dest;
}

struct D2_UnicodeChar* D2_UnicodeChar_Access(
    struct D2_UnicodeChar* unicode_char,
    size_t index
) {
  return (struct D2_UnicodeChar*) D2_UnicodeChar_AccessConst(
      unicode_char,
      index
  );
}

const struct D2_UnicodeChar* D2_UnicodeChar_AccessConst(
    const struct D2_UnicodeChar* unicode_char,
    size_t index
) {
  union D2_UnicodeChar_View view;

  view.ptr_1_00 = (const struct D2_UnicodeChar_1_00*) unicode_char;

  return (const struct D2_UnicodeChar*) &view.ptr_1_00[index];
}

void D2_UnicodeChar_SetCharFromAsciiChar(
    struct D2_UnicodeChar* unicode_char,
    char ch
) {
  union D2_UnicodeChar_Wrapper wrapper;

  wrapper.ptr_1_00 = (struct D2_UnicodeChar_1_00*) unicode_char;

  wrapper.ptr_1_00->ch = ch;
}
