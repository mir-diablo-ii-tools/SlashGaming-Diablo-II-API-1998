/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#ifndef SGD2MAPI_C_TYPES_D2_MPQ_HANDLE_H_
#define SGD2MAPI_C_TYPES_D2_MPQ_HANDLE_H_

#include <windows.h>

#include "sgd2mapi/types/d2/mpq.h"

/* Confirmed members and size from 1.00 to 1.14d. */

/* sizeof: 0x108 */ struct D2MpqHandle_1_00 {
  /* offsetof: 0x00 */ struct D2Mpq_1_00* mpq;
  /* offsetof: 0x04 */ char path[MAX_PATH];
};

#define D2MpqHandle_1_01 D2MpqHandle_1_00
#define D2MpqHandle_1_02 D2MpqHandle_1_01
#define D2MpqHandle_1_03 D2MpqHandle_1_02
#define D2MpqHandle_1_04 D2MpqHandle_1_03
#define D2MpqHandle_1_04b D2MpqHandle_1_04
#define D2MpqHandle_1_04c D2MpqHandle_1_04b
#define D2MpqHandle_1_05 D2MpqHandle_1_04c
#define D2MpqHandle_1_05b D2MpqHandle_1_05
#define D2MpqHandle_1_06 D2MpqHandle_1_05b
#define D2MpqHandle_1_06b D2MpqHandle_1_06
#define D2MpqHandle_1_07Beta D2MpqHandle_1_06b
#define D2MpqHandle_1_07 D2MpqHandle_1_07Beta
#define D2MpqHandle_1_08 D2MpqHandle_1_07
#define D2MpqHandle_1_09 D2MpqHandle_1_08
#define D2MpqHandle_1_09b D2MpqHandle_1_09
#define D2MpqHandle_1_09c D2MpqHandle_1_09b
#define D2MpqHandle_1_09d D2MpqHandle_1_09c
#define D2MpqHandle_1_10Beta D2MpqHandle_1_09d
#define D2MpqHandle_1_10sBeta D2MpqHandle_1_10Beta
#define D2MpqHandle_1_10 D2MpqHandle_1_10sBeta
#define D2MpqHandle_1_11 D2MpqHandle_1_10
#define D2MpqHandle_1_11b D2MpqHandle_1_11
#define D2MpqHandle_1_12 D2MpqHandle_1_11b
#define D2MpqHandle_1_13a D2MpqHandle_1_12
#define D2MpqHandle_1_13b D2MpqHandle_1_13a
#define D2MpqHandle_1_13c D2MpqHandle_1_13b
#define D2MpqHandle_1_13d D2MpqHandle_1_13c
#define D2MpqHandle_1_14a D2MpqHandle_1_13d
#define D2MpqHandle_1_14b D2MpqHandle_1_14a
#define D2MpqHandle_1_14c D2MpqHandle_1_14b
#define D2MpqHandle_1_14d D2MpqHandle_1_14c

#endif /* SGD2MAPI_C_TYPES_D2_MPQ_HANDLE_H_ */
