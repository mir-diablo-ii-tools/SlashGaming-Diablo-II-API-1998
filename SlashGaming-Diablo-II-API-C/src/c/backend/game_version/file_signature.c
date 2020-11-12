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

#include "file_signature.h"

#include <stddef.h>
#include <stdio.h>
#include <windows.h>

#include <mdc/object/integer_object.h>
#include <mdc/std/threads.h>
#include <mdc/std/wchar.h>
#include "../../backend/game_library.h"
#include "../error_handling.h"
#include "../default_game_library/default_game_library_path.h"
#include "../game_library.h"
#include "file_signature/file_signature_struct.h"
#include "file_signature/map_file_signature_game_version.h"
#include "file_signature/pair_file_signature_game_version.h"

struct Mapi_Impl_MapFileSignatureGameVersionLiteral {
  struct Mapi_Impl_FileSignatureLiteral file_signature;
  enum D2_GameVersion game_version;
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_00[] = {
    {
        { L"storm.dll", 0xF0, { 0x79, 0xBD, 0x20, 0x39 } },
        VERSION_BETA_1_02
    },
    {
        { L"storm.dll", 0xF0, { 0xB7, 0x70, 0xD0, 0x38 } },
        VERSION_BETA_STRESS_TEST_1_02
    },
    {
        { L"storm.dll", 0xF0, { 0xBC, 0xC7, 0x2E, 0x39 } },
        VERSION_1_00
    },
    {
        { L"storm.dll", 0xF0, { 0x25, 0x47, 0x52, 0x39 } },
        VERSION_1_01
    },
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_06[] = {
    {
        { L"storm.dll", 0xF0, { 0x43, 0x0C, 0xD6, 0x3A } },
        VERSION_1_06
    },
    {
        { L"storm.dll", 0xF0, { 0xC1, 0x7B, 0xE0, 0x3A } },
        VERSION_1_06B
    },
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_07[] = {
    {
        { L"storm.dll", 0xE8, { 0x32, 0xA6, 0xDC, 0x3A } },
        VERSION_1_07_BETA
    },
    {
        { L"storm.dll", 0xE8, { 0xB5, 0x92, 0xF5, 0x3A } },
        VERSION_1_07
    },
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_14A[] = {
    {
        { NULL, 0x120, { 0x38, 0x81, 0xD4, 0x56 } },
        CLASSIC_1_14A
    },
    {
        { NULL, 0x120, { 0x34, 0x81, 0xD4, 0x56 } },
        LOD_1_14A
    },
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_14B[] = {
    {
        { NULL, 0x110, { 0xAE, 0x78, 0xFC, 0x56 } },
        CLASSIC_1_14B
    },
    {
        { NULL, 0x110, { 0xA8, 0x78, 0xFC, 0x56 } },
        LOD_1_14B
    },
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_14C[] = {
    {
        { NULL, 0x110, { 0x52, 0xDF, 0x2C, 0x57 } },
        CLASSIC_1_14C
    },
    {
        { NULL, 0x110, { 0x4D, 0xDF, 0x2C, 0x57 } },
        LOD_1_14C
    },
};

static const struct Mapi_Impl_MapFileSignatureGameVersionLiteral
kSignatureTable1_14D[] = {
    {
        { NULL, 0x140, { 0x00, 0x50, 0x0A, 0x00 } },
        CLASSIC_1_14D
    },
    {
        { NULL, 0x140, { 0x00, 0x60, 0x0A, 0x00 } },
        LOD_1_14D
    },
};

enum {
  kSignatureTable1_00Count = sizeof(kSignatureTable1_00)
      / sizeof(kSignatureTable1_00[0]),

  kSignatureTable1_06Count = sizeof(kSignatureTable1_06)
      / sizeof(kSignatureTable1_06[0]),

  kSignatureTable1_07Count = sizeof(kSignatureTable1_07)
      / sizeof(kSignatureTable1_07[0]),

  kSignatureTable1_14ACount = sizeof(kSignatureTable1_14A)
      / sizeof(kSignatureTable1_14A[0]),

  kSignatureTable1_14BCount = sizeof(kSignatureTable1_14B)
      / sizeof(kSignatureTable1_14B[0]),

  kSignatureTable1_14CCount = sizeof(kSignatureTable1_14C)
      / sizeof(kSignatureTable1_14C[0]),

  kSignatureTable1_14DCount = sizeof(kSignatureTable1_14D)
      / sizeof(kSignatureTable1_14D[0])
};

static struct Mdc_Map signature_table_1_00;
static struct Mdc_Map signature_table_1_06;
static struct Mdc_Map signature_table_1_07;
static struct Mdc_Map signature_table_1_14a;
static struct Mdc_Map signature_table_1_14b;
static struct Mdc_Map signature_table_1_14c;
static struct Mdc_Map signature_table_1_14d;

static once_flag signature_tables_init_flag = ONCE_FLAG_INIT;

static struct Mdc_Map* Mapi_Impl_FileSignature_InitSignatureTableFromLit(
    struct Mdc_Map* signature_table,
    const struct Mapi_Impl_MapFileSignatureGameVersionLiteral*
        signature_table_lit,
    size_t count
) {
  size_t i;

  struct Mdc_Map* init_signature_table;

  struct Mapi_Impl_FileSignature file_signature;
  struct Mapi_Impl_FileSignature* init_file_signature;

  init_signature_table = Mdc_MapFileSignatureGameVersion_InitEmpty(
      signature_table
  );

  if (init_signature_table != signature_table) {
    goto return_bad;
  }

  for (i = 0; i < count; i += 1) {
    init_file_signature = Mapi_Impl_FileSignature_InitFromLiteral(
        &file_signature,
        &signature_table_lit[i].file_signature
    );

    if (init_file_signature != &file_signature) {
      goto return_bad;
    }

    Mdc_Map_Emplace(
        signature_table,
        &file_signature,
        Mdc_Integer_GetObjectMetadata()->functions.init_copy,
        &signature_table_lit[i].game_version
    );
  }

  return signature_table;

return_bad:
  return NULL;
}

static void Mapi_Impl_FileSignature_InitSignatureTables(void) {
  struct Mdc_Map* init_signature_table;

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_00,
      kSignatureTable1_00,
      kSignatureTable1_00Count
  );

  if (init_signature_table != &signature_table_1_00) {
    goto return_bad;
  }

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_06,
      kSignatureTable1_06,
      kSignatureTable1_06Count
  );

  if (init_signature_table != &signature_table_1_06) {
    goto return_bad;
  }

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_07,
      kSignatureTable1_07,
      kSignatureTable1_07Count
  );

  if (init_signature_table != &signature_table_1_07) {
    goto return_bad;
  }

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_14a,
      kSignatureTable1_14A,
      kSignatureTable1_14ACount
  );

  if (init_signature_table != &signature_table_1_14a) {
    goto return_bad;
  }

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_14b,
      kSignatureTable1_14B,
      kSignatureTable1_14BCount
  );

  if (init_signature_table != &signature_table_1_14b) {
    goto return_bad;
  }

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_14c,
      kSignatureTable1_14C,
      kSignatureTable1_14CCount
  );

  if (init_signature_table != &signature_table_1_14c) {
    goto return_bad;
  }

  init_signature_table = Mapi_Impl_FileSignature_InitSignatureTableFromLit(
      &signature_table_1_14d,
      kSignatureTable1_14D,
      kSignatureTable1_14DCount
  );

  if (init_signature_table != &signature_table_1_14d) {
    goto return_bad;
  }

  return;

return_bad:
  return;
}

static const struct Mapi_Impl_FileSignatureLiteral*
Mapi_Impl_FileSignature_GetVersionFirstLiteral(
    enum D2_GameVersion guess_game_version
) {
  switch (guess_game_version) {
    case VERSION_BETA_1_02:
    case VERSION_BETA_STRESS_TEST_1_02:
    case VERSION_1_00:
    case VERSION_1_01: {
      return &kSignatureTable1_00[0].file_signature;
    }

    case VERSION_1_06:
    case VERSION_1_06B: {
      return &kSignatureTable1_06[0].file_signature;
    }

    case VERSION_1_07_BETA:
    case VERSION_1_07: {
      return &kSignatureTable1_07[0].file_signature;
    }

    case CLASSIC_1_14A:
    case LOD_1_14A: {
      return &kSignatureTable1_14A[0].file_signature;
    }

    case CLASSIC_1_14B:
    case LOD_1_14B: {
      return &kSignatureTable1_14B[0].file_signature;
    }

    case CLASSIC_1_14C:
    case LOD_1_14C: {
      return &kSignatureTable1_14C[0].file_signature;
    }

    case CLASSIC_1_14D:
    case LOD_1_14D: {
      return &kSignatureTable1_14D[0].file_signature;
    }

    default: {
      return NULL;
    }
  }
}

static struct Mapi_Impl_FileSignature*
Mapi_Impl_FileSignature_ReadFromVersion(
    struct Mapi_Impl_FileSignature* file_signature,
    enum D2_GameVersion guess_game_version
) {
  struct Mapi_Impl_FileSignature* init_file_signature;

  const struct Mapi_Impl_FileSignatureLiteral* lit;

  struct Mdc_Fs_Path file_path;
  struct Mdc_Fs_Path* init_file_path;

  lit = Mapi_Impl_FileSignature_GetVersionFirstLiteral(
      guess_game_version
  );

  init_file_path = Mdc_Fs_Path_InitFromCWStr(
      &file_path,
      lit->file_path_cstr
  );

  if (init_file_path != &file_path) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_InitFromCWStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  init_file_signature = Mapi_Impl_FileSignature_ReadFileSignature(
      file_signature,
      &file_path,
      lit->offset
  );

  if (init_file_signature != file_signature) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"Mapi_Impl_FileSignature_ReadFileSignature failed"
    );

    goto return_bad;
  }

  Mdc_Fs_Path_Deinit(&file_path);

  return file_signature;

return_bad:
  return NULL;
}

static struct Mdc_Map* Mapi_Impl_FileSignature_GetSignatureTable(
    enum D2_GameVersion guess_game_version
) {
  switch (guess_game_version) {
    case VERSION_BETA_1_02:
    case VERSION_BETA_STRESS_TEST_1_02:
    case VERSION_1_00:
    case VERSION_1_01: {
      return &signature_table_1_00;
    }

    case VERSION_1_06:
    case VERSION_1_06B: {
      return &signature_table_1_06;
    }

    case VERSION_1_07_BETA:
    case VERSION_1_07: {
      return &signature_table_1_07;
    }

    case CLASSIC_1_14A:
    case LOD_1_14A: {
      return &signature_table_1_14a;
    }

    case CLASSIC_1_14B:
    case LOD_1_14B: {
      return &signature_table_1_14b;
    }

    case CLASSIC_1_14C:
    case LOD_1_14C: {
      return &signature_table_1_14c;
    }

    case CLASSIC_1_14D:
    case LOD_1_14D: {
      return &signature_table_1_14d;
    }

    default: {
      return NULL;
    }
  }
}

static void InitStatic(void) {
  call_once(
      &signature_tables_init_flag,
      &Mapi_Impl_FileSignature_InitSignatureTables
  );
}

enum D2_GameVersion Mapi_Signature_CorrectVersionGuess(
    enum D2_GameVersion guess_game_version
) {
  struct Mdc_Map* signature_table;
  enum D2_GameVersion* corrected_game_version;

  struct Mapi_Impl_FileSignature key;
  struct Mapi_Impl_FileSignature* init_key;

  InitStatic();

  signature_table = Mapi_Impl_FileSignature_GetSignatureTable(
      guess_game_version
  );

  if (signature_table == NULL) {
    return guess_game_version;
  }

  init_key = Mapi_Impl_FileSignature_ReadFromVersion(
      &key,
      guess_game_version
  );

  if (init_key != &key) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"Mapi_Impl_FileSignature_ReadFromVersion failed"
    );

    goto return_bad;
  }

  corrected_game_version = Mdc_Map_AtConst(
      signature_table,
      &key
  );

  if (corrected_game_version == NULL) {
    return guess_game_version;
  }

  return *corrected_game_version;

return_bad:
  return -1;
}
