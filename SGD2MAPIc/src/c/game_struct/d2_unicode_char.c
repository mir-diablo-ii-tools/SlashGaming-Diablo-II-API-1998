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

#include "../../../include/c/game_struct/d2_unicode_char.h"

/**
 * View and wrapper declarations
 */

struct D2_UnicodeChar_View {
  union {
    const struct D2_UnicodeChar_1_00* v1_00;
  } ptr;
};

struct D2_UnicodeChar_Wrapper {
  union {
    struct D2_UnicodeChar_1_00* v1_00;
  } ptr;
};

/**
 * Function definitions
 */

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
  struct D2_UnicodeChar_View view;

  view.ptr.v1_00 = (const struct D2_UnicodeChar_1_00*) unicode_char;

  return (const struct D2_UnicodeChar*) &view.ptr.v1_00[index];
}

void D2_UnicodeChar_AssignMembers(
    struct D2_UnicodeChar* dest,
    const struct D2_UnicodeChar* src
) {
  struct D2_UnicodeChar_Wrapper dest_wrapper;
  struct D2_UnicodeChar_View src_view;

  dest_wrapper.ptr.v1_00 = (struct D2_UnicodeChar_1_00*) dest;
  src_view.ptr.v1_00 = (const struct D2_UnicodeChar_1_00*) src;

  *dest_wrapper.ptr.v1_00 = *src_view.ptr.v1_00;
}

void D2_UnicodeChar_SetCharFromAsciiChar(
    struct D2_UnicodeChar* unicode_char,
    char ch
) {
  struct D2_UnicodeChar_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_UnicodeChar_1_00*) unicode_char;

  wrapper.ptr.v1_00->ch = ch;
}

void D2_UnicodeChar_SetCharFromUtf16CodeUnit(
    struct D2_UnicodeChar* unicode_char,
    uint_least16_t ch
) {
  struct D2_UnicodeChar_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_UnicodeChar_1_00*) unicode_char;

  wrapper.ptr.v1_00->ch = ch;
}

/**
 * API functions
 */

struct D2_UnicodeChar_Api D2_UnicodeChar_Api_InitNull(void) {
  return D2_UnicodeChar_Api_InitFromAsciiChar('\0');
}

struct D2_UnicodeChar_Api D2_UnicodeChar_Api_InitFromAsciiChar(
    char ascii_ch
) {
  struct D2_UnicodeChar_Api unicode_ch;

  D2_UnicodeChar_SetCharFromAsciiChar(
      D2_UnicodeChar_Api_Get(&unicode_ch),
      ascii_ch
  );

  return unicode_ch;
}

void D2_UnicodeChar_Api_Deinit(struct D2_UnicodeChar_Api* unicode_char) {
}

struct D2_UnicodeChar* D2_UnicodeChar_Api_Get(
    struct D2_UnicodeChar_Api* unicode_char
) {
  return (struct D2_UnicodeChar*) D2_UnicodeChar_Api_GetConst(unicode_char);
}

const struct D2_UnicodeChar* D2_UnicodeChar_Api_GetConst(
    const struct D2_UnicodeChar_Api* unicode_char
) {
  return (const struct D2_UnicodeChar*) &unicode_char->value.v1_00;
}
