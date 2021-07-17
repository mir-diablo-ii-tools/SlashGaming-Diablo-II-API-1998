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

global _D2_D2Win_LoadMpq_1_11_Shim

section .data

section .bss

section .text

; struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_11_Shim(
;     intptr_t func_ptr,
;     const char* dll_file_name,
;     const char* mpq_file_name,
;     const char* mpq_name,
;     mapi_bool32 is_set_err_on_drive_query_fail,
;     void* (*on_fail_callback)(void),
;     int32_t priority
; )
_D2_D2Win_LoadMpq_1_11_Shim:
  push ebp
  mov ebp, esp

  push ecx
  push edx

  mov eax, dword [ebp + 32]
  push dword [ebp + 28]
  push dword [ebp + 24]
  push dword [ebp + 20]
  push dword [ebp + 16]
  push dword [ebp + 12]
  call dword [ebp + 8]

  pop edx
  pop ecx

  leave
  ret
