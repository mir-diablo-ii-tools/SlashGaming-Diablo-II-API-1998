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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_UNICODE_CHAR_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_UNICODE_CHAR_H_

#include <stddef.h>
#include <stdint.h>

#include "../../dllexport_define.inc"

/**
 * Generic struct definition
 */

struct D2_UnicodeChar;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

struct D2_UnicodeChar_1_00 {
  int16_t ch;
};

#pragma pack(pop)

/**
 * Function declarations
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a generic UnicodeChar initialized as the null-terminator character.
 */
DLLEXPORT struct D2_UnicodeChar* D2_UnicodeChar_CreateDefault(void);

/**
 * Creates a generic UnicodeChar with a 7-bit ASCII character.
 */
DLLEXPORT struct D2_UnicodeChar* D2_UnicodeChar_CreateWithAsciiChar(char ch);


/**
 * Creates a generic UnicodeChar string with all characters initialized with
 * the null-terminator character.
 */
DLLEXPORT struct D2_UnicodeChar* D2_UnicodeChar_CreateStringWithCount(size_t count);

/**
 * Creates a generic UnicodeChar string with a null-terminated 7-bit ASCII
 * character string.
 */
DLLEXPORT struct D2_UnicodeChar* D2_UnicodeChar_CreateStringWithAsciiString(
    const char* str
);

/**
 * Creates a generic UnicodeChar string with a null-terminated UTF-8 character
 * string.
 */
DLLEXPORT struct D2_UnicodeChar* D2_UnicodeChar_CreateStringWithUtf8String(
    const char* str
);

/**
 * Creates a generic UnicodeChar string with a null-terminated wide character
 * string.
 */
DLLEXPORT struct D2_UnicodeChar* D2_UnicodeChar_CreateStringWithWideString(
    const wchar_t* str
);

/**
 * Destroy the UnicodeChar, freeing up resources.
 */
DLLEXPORT void D2_UnicodeChar_Destroy(struct D2_UnicodeChar* unicode_char);

/**
 * Replaces the character with the specified 7-bit ASCII character.
 */
DLLEXPORT void D2_UnicodeChar_SetCharWithAsciiChar(
    struct D2_UnicodeChar* unicode_char,
    char ch
);

/**
 * Replaces the character with the one in the specified UnicodeChar.
 */
DLLEXPORT void D2_UnicodeChar_CopyChar(
    struct D2_UnicodeChar* unicode_char,
    const struct D2_UnicodeChar* src
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_UNICODE_CHAR_H_
