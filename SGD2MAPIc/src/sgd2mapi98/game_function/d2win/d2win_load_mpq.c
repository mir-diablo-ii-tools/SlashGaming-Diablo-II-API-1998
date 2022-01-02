/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../../../include/sgd2mapi98/game_function/d2win/d2win_load_mpq.h"

#include "../../../../include/sgd2mapi98/default_game_library.h"
#include "../../../../include/sgd2mapi98/game_address.h"
#include "../../../../include/sgd2mapi98/game_version.h"
#include "../../backend/game_address_table.h"
#include "../../backend/game_function/fastcall_function.h"

static struct Mapi_GameAddress game_address;

static void InitGameAddress(void) {
  game_address = Mapi_GameAddressTable_GetFromLibrary(
      D2_DefaultLibrary_kD2Win,
      "LoadMpq"
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
 * Shims
 */

struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_11_Shim(
    intptr_t func_ptr,
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    mapi_bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    int32_t priority
);

/**
 * External
 */

struct D2_MpqArchiveHandle* D2_D2Win_LoadMpq(
    const char* mpq_file_name,
    int is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    int priority
) {
  enum D2_GameVersion running_game_version;

  InitStatic();

  running_game_version = D2_GameVersion_GetRunning();

  if (running_game_version <= D2_GameVersion_k1_02) {
    return (struct D2_MpqArchiveHandle*) D2_D2Win_LoadMpq_1_00(
        "sgd2mapi.DLL",
        mpq_file_name,
        "SGD2MAPI",
        0,
        on_fail_callback
    );
  } else if (running_game_version >= D2_GameVersion_k1_03
      && running_game_version <= D2_GameVersion_k1_06B) {
    return (struct D2_MpqArchiveHandle*) D2_D2Win_LoadMpq_1_03(
        "sgd2mapi.DLL",
        mpq_file_name,
        "SGD2MAPI",
        0,
        is_set_err_on_drive_query_fail,
        on_fail_callback
    );
  } else if (running_game_version >= D2_GameVersion_k1_07Beta
      && running_game_version <= D2_GameVersion_k1_10) {
    return (struct D2_MpqArchiveHandle*) D2_D2Win_LoadMpq_1_07(
        "sgd2mapi.DLL",
        mpq_file_name,
        "SGD2MAPI",
        0,
        is_set_err_on_drive_query_fail,
        on_fail_callback,
        priority
    );
  } else if (running_game_version >= D2_GameVersion_k1_11
      && running_game_version <= D2_GameVersion_k1_13D) {
    return (struct D2_MpqArchiveHandle*) D2_D2Win_LoadMpq_1_11(
        "sgd2mapi.DLL",
        mpq_file_name,
        "SGD2MAPI",
        is_set_err_on_drive_query_fail,
        on_fail_callback,
        priority
    );
  } else /* if (running_game_version >= D2_GameVersion_kClassic1_14A) */ {
    return (struct D2_MpqArchiveHandle*) D2_D2Win_LoadMpq_1_14A(
        mpq_file_name,
        is_set_err_on_drive_query_fail,
        on_fail_callback,
        priority
    );
  }
}

struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_00(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    int32_t unused,
    void* (*on_fail_callback)(void)
) {
  InitStatic();

  return (struct D2_MpqArchiveHandle_1_00*) CallFastcallFunction(
      game_address.raw_address,
      5,
      dll_file_name,
      mpq_file_name,
      mpq_name,
      unused,
      on_fail_callback
  );
}

struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_03(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    int32_t unused,
    mapi_bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void)
) {
  InitStatic();

  return (struct D2_MpqArchiveHandle_1_00*) CallFastcallFunction(
      game_address.raw_address,
      6,
      dll_file_name,
      mpq_file_name,
      mpq_name,
      unused,
      is_set_err_on_drive_query_fail,
      on_fail_callback
  );
}

struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_07(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    int32_t unused,
    mapi_bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    int32_t priority
) {
  InitStatic();

  return (struct D2_MpqArchiveHandle_1_00*) CallFastcallFunction(
      game_address.raw_address,
      7,
      dll_file_name,
      mpq_file_name,
      mpq_name,
      unused,
      is_set_err_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}

struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_11(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    mapi_bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    int32_t priority
) {
  InitStatic();

  return D2_D2Win_LoadMpq_1_11_Shim(
      game_address.raw_address,
      dll_file_name,
      mpq_file_name,
      mpq_name,
      is_set_err_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}

struct D2_MpqArchiveHandle_1_00* D2_D2Win_LoadMpq_1_14A(
    const char* mpq_file_name,
    mapi_bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    int32_t priority
) {
  InitStatic();

  return (struct D2_MpqArchiveHandle_1_00*) CallFastcallFunction(
      game_address.raw_address,
      4,
      mpq_file_name,
      is_set_err_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}
