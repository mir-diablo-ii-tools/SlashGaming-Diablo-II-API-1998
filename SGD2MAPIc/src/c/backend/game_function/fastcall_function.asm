;
; SlashGaming Diablo II Modding API for C
; Copyright (C) 2018-2020  Mir Drualga
;
; This file is part of SlashGaming Diablo II Modding API for C.
;
;  This program is free software: you can redistribute it and/or modify
;  it under the terms of the GNU Affero General Public License as published
;  by the Free Software Foundation, either version 3 of the License, or
;  (at your option) any later version.
;
;  This program is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;  GNU Affero General Public License for more details.
;
;  You should have received a copy of the GNU Affero General Public License
;  along with this program.  If not, see <http://www.gnu.org/licenses/>.
;
;  Additional permissions under GNU Affero General Public License version 3
;  section 7
;
;  If you modify this Program, or any covered work, by linking or combining
;  it with Diablo II (or a modified version of that game and its
;  libraries), containing parts covered by the terms of Blizzard End User
;  License Agreement, the licensors of this Program grant you additional
;  permission to convey the resulting work. This additional permission is
;  also extended to any combination of expansions, mods, and remasters of
;  the game.
;
;  If you modify this Program, or any covered work, by linking or combining
;  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
;  Glide, OpenGL, or Rave wrapper (or modified versions of those
;  libraries), containing parts not covered by a compatible license, the
;  licensors of this Program grant you additional permission to convey the
;  resulting work.
;
;  If you modify this Program, or any covered work, by linking or combining
;  it with any library (or a modified version of that library) that links
;  to Diablo II (or a modified version of that game and its libraries),
;  containing parts not covered by a compatible license, the licensors of
;  this Program grant you additional permission to convey the resulting
;  work.
;

global _CallFastcallFunction

section .data

section .bss

section .text

; void* __cdecl CallFastcallFunction(intptr_t func_ptr, int num_params, ...)
_CallFastcallFunction:
    push ebp
    mov ebp, esp

    push ecx
    push edx
    push esi

    ; Push all the stack arguments.

    ; ecx = num_params;
    mov ecx, dword [ebp + 12]

    ; eax = &num_params;
    ; This will be used to get the pointer of the parameters after it.
    lea eax, dword [ebp + 12]
    lea eax, dword [eax + ecx * 4]

  PushStackArgsLoop:
    cmp ecx, 3
    jl PushStackArgsLoopEnd

    push dword [eax]
    sub ecx, 1
    sub eax, 4
    jmp PushStackArgsLoop

  PushStackArgsLoopEnd:

    ; We do not conditionally branch when setting the registers,
    ; because it incurs additional cost (in readability and execution)
    ; with no realistic benefit. If the called function has no
    ; parameters, the register values are overwritten anyways.

    ; Set the second parameter.
    mov edx, dword [ebp + 20]

    ; Set the first parameter.
    mov ecx, dword [ebp + 16]

    ; Call the function.
    call dword [ebp + 8]

    pop esi
    pop edx
    pop ecx

    leave
    ret
