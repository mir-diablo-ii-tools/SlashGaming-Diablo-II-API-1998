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

#include "../../../../include/c/game_function/d2lang/d2lang_unicode_tolower.h"

#include "../../../../include/c/default_game_library.h"
#include "../../../../include/c/game_address.h"
#include "../../../../include/c/game_version.h"
#include "../../backend/game_address_table.h"
#include "../../backend/game_function/thiscall_function.h"

static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  game_address = Mapi_GameAddressTable_GetFromLibrary(
      D2_DefaultLibrary_kD2Lang,
      "Unicode_tolower"
  );
}

static void InitStatic(void) {
  static int is_game_address_init = 0;

  if (!is_game_address_init) {
    InitGameAddress();

    is_game_address_init = 1;
  }
}

/**
 * External
 */

struct D2_UnicodeChar* D2_D2Lang_Unicode_tolower(
    const struct D2_UnicodeChar* src,
    struct D2_UnicodeChar* dest
) {
  InitStatic();

  return (struct D2_UnicodeChar*) D2_D2Lang_Unicode_tolower_1_00(
      (const struct D2_UnicodeChar_1_00*) src,
      (struct D2_UnicodeChar_1_00*) dest
  );
}

struct D2_UnicodeChar_1_00* D2_D2Lang_Unicode_tolower_1_00(
    const struct D2_UnicodeChar_1_00* src,
    struct D2_UnicodeChar_1_00* dest
) {
  InitStatic();

  return (struct D2_UnicodeChar_1_00*) CallThiscallFunction(
      game_address.raw_address,
      2,
      src,
      dest
  );
}
