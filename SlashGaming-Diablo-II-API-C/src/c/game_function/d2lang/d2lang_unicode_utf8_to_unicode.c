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

#include "../../../../include/c/game_function/d2lang/d2lang_unicode_utf8_to_unicode.h"

#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.h"

static __declspec(naked) struct D2_UnicodeChar_1_00* __cdecl
D2Lang_Unicode_UnicodeToUtf8_1_00(
    intptr_t func_ptr,
    struct D2_UnicodeChar_1_00* dest,
    const char* src,
    int32_t count_including_null_terminator
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(push dword ptr [ebp + 20]);
  ASM_X86(mov edx, dword ptr [ebp + 16]);
  ASM_X86(mov ecx, dword ptr [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);

  ASM_X86(leave);
  ASM_X86(ret);
}

struct D2_UnicodeChar* D2_D2Lang_Unicode_Utf8ToUnicode(
    struct D2_UnicodeChar* dest,
    const char* src,
    int count_including_null_terminator
) {
  struct D2_UnicodeChar_1_00* actual_dest =
      (struct D2_UnicodeChar_1_00*) dest;

  struct D2_UnicodeChar_1_00* actual_return_value =
      D2_D2Lang_Unicode_Utf8ToUnicode_1_00(
          actual_dest,
          src,
          count_including_null_terminator
      );

  return (struct D2_UnicodeChar*) actual_return_value;
}

struct D2_UnicodeChar_1_00* D2_D2Lang_Unicode_Utf8ToUnicode_1_00(
    struct D2_UnicodeChar_1_00* dest,
    const char* src,
    int32_t count_including_null_terminator
) {
  struct MAPI_GameAddress* game_address = GetGameAddress(
      "D2Lang.dll",
      "Unicode_Utf8ToUnicode"
  );

  return D2Lang_Unicode_UnicodeToUtf8_1_00(
      game_address->raw_address,
      dest,
      src,
      count_including_null_terminator
  );
}
