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

#include "../../../include/c/game_struct/d2_mpq_archive_handle.h"

#include <stdlib.h>

#include "../../wide_macro.h"
#include "../backend/error_handling.h"

union D2_MpqArchiveHandle_View {
  const struct D2_MpqArchiveHandle_1_00* _1_00;
};

union D2_MpqArchiveHandle_Wrapper {
  struct D2_MpqArchiveHandle_1_00* _1_00;
};

/**
 * Function definitions
 */

struct D2_MpqArchive* D2_MpqArchiveHandle_GetMpqArchive(
    struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  return (struct D2_MpqArchive*) D2_MpqArchiveHandle_GetConstMpqArchive(
      mpq_archive_handle
  );
}

const struct D2_MpqArchive* D2_MpqArchiveHandle_GetConstMpqArchive(
    const struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  union D2_MpqArchiveHandle_View view;

  view._1_00 = (const struct D2_MpqArchiveHandle_1_00*) mpq_archive_handle;

  return (const struct D2_MpqArchive*) view._1_00->mpq_archive;
}

void D2_MpqArchiveHandle_SetMpqArchive(
    struct D2_MpqArchiveHandle* mpq_archive_handle,
    struct D2_MpqArchive* mpq_archive
) {
  union D2_MpqArchiveHandle_Wrapper wrapper;

  wrapper._1_00 = (struct D2_MpqArchiveHandle_1_00*) mpq_archive_handle;
  wrapper._1_00->mpq_archive = (struct D2_MpqArchive_1_00*) mpq_archive;
}

char* D2_MpqArchiveHandle_GetMpqArchivePath(
    struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  return (char*) D2_MpqArchiveHandle_GetConstMpqArchivePath(
      mpq_archive_handle
  );
}

const char* D2_MpqArchiveHandle_GetConstMpqArchivePath(
    const struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  union D2_MpqArchiveHandle_View view;

  view._1_00 = (const struct D2_MpqArchiveHandle_1_00*) mpq_archive_handle;

  return view._1_00->mpq_archive_path;
}
