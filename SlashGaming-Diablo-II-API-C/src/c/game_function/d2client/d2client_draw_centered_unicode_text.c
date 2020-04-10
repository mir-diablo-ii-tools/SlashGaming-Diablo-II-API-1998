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

#include "../../../../include/c/game_function/d2client/d2client_draw_centered_unicode_text.h"

#include <pthread.h>
#include <stdint.h>

#include "../../../../include/c/game_version.h"
#include "../../../asm_x86_macro.h"
#include "../../../wide_macro.h"
#include "../../backend/game_function/fastcall_function.h"
#include "../../backend/game_address_table.h"
#include "../../backend/error_handling.h"

static pthread_once_t once_flag = PTHREAD_ONCE_INIT;
static const struct MAPI_GameAddress* game_address;

static void InitGameAddress(void) {
  game_address = GetGameAddress(
      "D2Client.dll",
      "DrawCenteredUnicodeText"
  );
}

__declspec(naked) static void* __cdecl
D2_D2Client_DrawCenteredUnicodeText_1_12A_Shim(
    intptr_t func_ptr,
    int32_t left,
    int32_t position_y,
    const struct D2_UnicodeChar_1_00* text,
    int32_t right,
    /* enum D2_TextColor_1_00 */ int32_t text_color
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push eax);
  ASM_X86(push ebx);
  ASM_X86(push ecx);
  ASM_X86(push edx);

  // Push the args.
  ASM_X86(push dword ptr [ebp + 28]);
  ASM_X86(mov eax, dword ptr [ebp + 24]);
  ASM_X86(mov ebx, dword ptr [ebp + 20]);
  ASM_X86(push dword ptr [ebp + 16]);
  ASM_X86(mov ecx, dword ptr [ebp + 12]);

  // Call the function.
  ASM_X86(call dword ptr [ebp + 8]);
  ASM_X86(add esp, 20);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);
  ASM_X86(pop ebx);
  ASM_X86(pop eax);

  ASM_X86(leave);
  ASM_X86(ret);
}

void D2_D2Client_DrawCenteredUnicodeText(
    int left,
    int position_y,
    const struct D2_UnicodeChar* text,
    int right,
    enum D2_TextColor text_color
) {
  struct D2_UnicodeChar_1_00* actual_text =
      (struct D2_UnicodeChar_1_00*) text;

  enum D2_TextColor text_color_game_value =
      D2_TextColor_ToGameValue(text_color);

  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10
      || running_game_version >= CLASSIC_1_14A) {
    D2_D2Client_DrawCenteredUnicodeText_1_00(
        left,
        position_y,
        actual_text,
        right,
        text_color_game_value
    );
  } else /* if (running_game_version >= VERSION_1_11
      && running_game_version <= VERSION_1_13D) */ {
    D2_D2Client_DrawCenteredUnicodeText_1_12A(
        left,
        position_y,
        actual_text,
        right,
        text_color_game_value
    );
  }
}

void D2_D2Client_DrawCenteredUnicodeText_1_00(
    int32_t left,
    int32_t position_y,
    const struct D2_UnicodeChar_1_00* text,
    int32_t right,
    int32_t text_color
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  CallFastcallFunction(
      game_address->raw_address,
      5,
      left,
      position_y,
      text,
      right,
      text_color
  );
}

void D2_D2Client_DrawCenteredUnicodeText_1_12A(
    int32_t left,
    int32_t position_y,
    const struct D2_UnicodeChar_1_00* text,
    int32_t right,
    /* enum D2_TextColor_1_00 */ int32_t text_color
) {
  int once_return = pthread_once(&once_flag, &InitGameAddress);

  if (once_return != 0) {
    ExitOnCallOnceFailure(__FILEW__, __LINE__);
  }

  D2_D2Client_DrawCenteredUnicodeText_1_12A_Shim(
      game_address->raw_address,
      left,
      position_y,
      text,
      right,
      text_color
  );
}
