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

global DrawCenteredUnicodeText_1_11_Shim

section .data

section .bss

section .text

; void* __cdecl D2_D2Client_DrawCenteredUnicodeText_1_11_Shim(
;     int32_t left,
;     int32_t position_y,
;     const struct D2_UnicodeChar_1_00* text,
;     int32_t right,
;     /* enum D2_TextColor_1_00 */ int32_t text_color
; )
D2_D2Client_DrawCenteredUnicodeText_1_11_Shim:
    push ebp
    mov ebp, esp

    push eax
    push ecx
    push edx
    push ebx

    push dword [ebp + 28]
    mov eax, [ebp + 24]
    mov ebx, [ebp + 20]
    push dword [ebp + 16]
    mov ecx, [ebp + 12]
    call dword [ebp + 8]

    pop ebx
    pop edx
    pop ecx
    pop eax

    leave
    ret
