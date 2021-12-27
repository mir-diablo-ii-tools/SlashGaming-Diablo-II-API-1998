/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2021  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++98.
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

#ifndef SGD2MAPI_CPP98_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_WRAPPER_HPP_
#define SGD2MAPI_CPP98_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_WRAPPER_HPP_

#include <stddef.h>

#include <sgd2mapi98.h>
#include "../d2_mpq_archive/d2_mpq_archive_view.hpp"
#include "../d2_mpq_archive/d2_mpq_archive_wrapper.hpp"
#include "d2_mpq_archive_handle_struct.hpp"
#include "d2_mpq_archive_handle_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT MpqArchiveHandle_Wrapper {
 public:
  union WrapperType {
    MpqArchiveHandle_1_00* v1_00;
  };

  MpqArchiveHandle_Wrapper(MpqArchiveHandle* mpq_archive_handle);

  explicit MpqArchiveHandle_Wrapper(
      MpqArchiveHandle_1_00* mpq_archive_handle
  );

  MpqArchiveHandle_View operator[](size_t index) const;

  MpqArchiveHandle_Wrapper operator[](size_t index);

  operator MpqArchiveHandle_View() const;

  MpqArchiveHandle* Get();

  const MpqArchiveHandle* Get() const;

  void AssignMembers(MpqArchiveHandle_View src);

  MpqArchive_View GetMpqArchive() const;

  MpqArchive_Wrapper GetMpqArchive();

  void SetMpqArchive(MpqArchive_Wrapper mpq_archive);

  char* GetMpqArchivePath();

  const char* GetMpqArchivePath() const;

 private:
  WrapperType mpq_archive_handle_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CPP98_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_WRAPPER_HPP_ */