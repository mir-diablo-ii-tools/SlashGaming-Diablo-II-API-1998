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

#include "stdcall_function.h"

#include "../../../asm_x86_macro.h"

__declspec(naked) void* __cdecl CallStdcallFunction(
    intptr_t func_ptr,
    int num_params,
    ...
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push ecx);
  ASM_X86(push edx);

  /* Push all the stack arguments. */

  /* Load num_params into ecx. */
  ASM_X86(mov ecx, dword ptr [ebp + 12]);

  /*
  * Load pointer of num_params into eax, which will be used to get
  * the pointer of the parameters after it.
  */
  ASM_X86(lea eax, dword ptr [ebp + 12]);
  ASM_X86(lea eax, dword ptr [eax + ecx * 4]);
ASM_X86_LABEL(CallFastcallFunction_PushStackArgsLoop);
  ASM_X86(test ecx, ecx);
  ASM_X86(jz CallFastcallFunction_PushStackArgsLoopEnd);

  ASM_X86(push dword ptr [eax]);
  ASM_X86(sub ecx, 1);
  ASM_X86(sub eax, 4);
  ASM_X86(jmp CallFastcallFunction_PushStackArgsLoop);
ASM_X86_LABEL(CallFastcallFunction_PushStackArgsLoopEnd);

  /* Call the function. */
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);

  ASM_X86(leave);
  ASM_X86(ret);
}
