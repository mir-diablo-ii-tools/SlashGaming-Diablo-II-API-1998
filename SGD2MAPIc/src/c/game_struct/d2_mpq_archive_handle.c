/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

/**
 * View and wrapper declarations
 */

struct D2_MpqArchiveHandle_View {
  union {
    const struct D2_MpqArchiveHandle_1_00* v1_00;
  } ptr;
};

struct D2_MpqArchiveHandle_Wrapper {
  union {
    struct D2_MpqArchiveHandle_1_00* v1_00;
  } ptr;
};

/**
 * Function definitions
 */

struct D2_MpqArchiveHandle* D2_MpqArchiveHandle_Access(
    struct D2_MpqArchiveHandle* mpq_archive_handle,
    size_t index
) {
  return (struct D2_MpqArchiveHandle*)
      D2_MpqArchiveHandle_AccessConst(mpq_archive_handle, index);
}

const struct D2_MpqArchiveHandle* D2_MpqArchiveHandle_AccessConst(
    const struct D2_MpqArchiveHandle* mpq_archive_handle,
    size_t index
) {
  struct D2_MpqArchiveHandle_View view;

  view.ptr.v1_00 = (const struct D2_MpqArchiveHandle_1_00*)
      mpq_archive_handle;

  return (const struct D2_MpqArchiveHandle*) &view.ptr.v1_00[index];
}

struct D2_MpqArchiveHandle* D2_MpqArchiveHandle_AssignMembers(
    struct D2_MpqArchiveHandle* dest,
    const struct D2_MpqArchiveHandle* src
) {
  struct D2_MpqArchiveHandle_Wrapper dest_wrapper;
  struct D2_MpqArchiveHandle_View src_view;

  dest_wrapper.ptr.v1_00 = (struct D2_MpqArchiveHandle_1_00*) dest;
  src_view.ptr.v1_00 = (const struct D2_MpqArchiveHandle_1_00*) src;

  *dest_wrapper.ptr.v1_00 = *src_view.ptr.v1_00;

  return dest;
}

struct D2_MpqArchive* D2_MpqArchiveHandle_GetMpqArchive(
    struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  return (struct D2_MpqArchive*) D2_MpqArchiveHandle_GetMpqArchiveConst(
      mpq_archive_handle
  );
}

const struct D2_MpqArchive* D2_MpqArchiveHandle_GetMpqArchiveConst(
    const struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  struct D2_MpqArchiveHandle_View view;

  view.ptr.v1_00 = (const struct D2_MpqArchiveHandle_1_00*) mpq_archive_handle;

  return (const struct D2_MpqArchive*) view.ptr.v1_00->mpq_archive;
}

void D2_MpqArchiveHandle_SetMpqArchive(
    struct D2_MpqArchiveHandle* mpq_archive_handle,
    struct D2_MpqArchive* mpq_archive
) {
  struct D2_MpqArchiveHandle_Wrapper wrapper;

  wrapper.ptr.v1_00 = (struct D2_MpqArchiveHandle_1_00*) mpq_archive_handle;

  wrapper.ptr.v1_00->mpq_archive = (struct D2_MpqArchive_1_00*) mpq_archive;
}

char* D2_MpqArchiveHandle_GetMpqArchivePath(
    struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  return (char*) D2_MpqArchiveHandle_GetMpqArchivePathConst(
      mpq_archive_handle
  );
}

const char* D2_MpqArchiveHandle_GetMpqArchivePathConst(
    const struct D2_MpqArchiveHandle* mpq_archive_handle
) {
  struct D2_MpqArchiveHandle_View view;

  view.ptr.v1_00 = (const struct D2_MpqArchiveHandle_1_00*) mpq_archive_handle;

  return view.ptr.v1_00->mpq_archive_path;
}
