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

#include "pair_file_signature_game_version.h"

#include <mdc/object/integer_object.h>
#include <mdc/std/threads.h>

/**
 * Static functions
 */

static struct Mdc_ObjectMetadata object_metadata;
static once_flag object_metadata_init_flag = ONCE_FLAG_INIT;

static struct Mdc_PairMetadata pair_metadata;
static once_flag pair_metadata_init_flag = ONCE_FLAG_INIT;

static void Mdc_PairFileSignatureGameVersion_InitObjectMetadata(void) {
  object_metadata = *Mdc_Pair_GetObjectMetadataTemplate();
}

static void Mdc_PairFileSignatureGameVersion_InitPairMetadata(void) {
  Mdc_PairMetadata_Init(
      &pair_metadata,
      Mapi_Impl_FileSignature_GetObjectMetadata(),
      Mdc_Integer_GetObjectMetadata()
  );
}

static void InitStatic(void) {
  call_once(
      &object_metadata_init_flag,
      &Mdc_PairFileSignatureGameVersion_InitObjectMetadata
  );

  call_once(
      &pair_metadata_init_flag,
      &Mdc_PairFileSignatureGameVersion_InitPairMetadata
  );
}

/**
 * External functions
 */

const struct Mdc_ObjectMetadata*
Mdc_PairFileSignatureGameVersion_GetObjectMetadata(void) {
  InitStatic();

  return &object_metadata;
}

const struct Mdc_PairMetadata*
Mdc_PairFileSignatureGameVersion_GetPairMetadata(void) {
  InitStatic();

  return &pair_metadata;
}
