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

#include "../../../../include/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.hpp"

#include "../../../../include/cxx98/game_function/d2win/d2win_load_mpq.hpp"
#include "../../../../include/cxx98/game_function/d2win/d2win_unload_mpq.hpp"

namespace d2 {

MpqArchiveHandle_Api::MpqArchiveHandle_Api()
    : mpq_archive_handle_(),
      is_open_(false) {
}

MpqArchiveHandle_Api::MpqArchiveHandle_Api(
    const char* path,
    bool is_set_error_on_drive_query_fail,
    int priority
) {
  this->Open(path, is_set_error_on_drive_query_fail, NULL, priority);
}

MpqArchiveHandle_Api::MpqArchiveHandle_Api(
    const char* path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) {
  this->Open(
      path,
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}

MpqArchiveHandle_Api::~MpqArchiveHandle_Api() {
  this->Close();
}

MpqArchiveHandle_Api::operator MpqArchiveHandle_View() const {
  return MpqArchiveHandle_View(this->Get());
}

MpqArchiveHandle_Api::operator MpqArchiveHandle_Wrapper() {
  return MpqArchiveHandle_Wrapper(this->Get());
}

MpqArchiveHandle* MpqArchiveHandle_Api::Get() {
  const MpqArchiveHandle_Api* const_this = this;

  return const_cast<MpqArchiveHandle*>(const_this->Get());
}

const MpqArchiveHandle* MpqArchiveHandle_Api::Get() const {
  return reinterpret_cast<const MpqArchiveHandle*>(
      this->mpq_archive_handle_.v1_00
  );
}

void MpqArchiveHandle_Api::Close() {
  if (!this->IsOpen()) {
    return;
  }

  d2win::UnloadMpq(this->Get());
  this->mpq_archive_handle_.v1_00 = NULL;
  this->is_open_ = false;
}

bool MpqArchiveHandle_Api::IsOpen() const {
  return this->is_open_;
}

void MpqArchiveHandle_Api::Open(
    const char* path,
    bool is_set_error_on_drive_query_fail,
    int priority
) {
  this->Open(
      path,
      is_set_error_on_drive_query_fail,
      NULL,
      priority
  );
}

void MpqArchiveHandle_Api::Open(
    const char* path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) {
  this->Close();
  
  MpqArchiveHandle* loaded_mpq = d2win::LoadMpq(
      path,
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );

  this->mpq_archive_handle_.v1_00 = reinterpret_cast<MpqArchiveHandle_1_00*>(
      loaded_mpq
  );

  this->is_open_ = (this->Get() != NULL);
}

MpqArchive_View MpqArchiveHandle_Api::GetMpqArchive() const {
  MpqArchiveHandle_View view(*this);

  return view.GetMpqArchive();
}

MpqArchive_Wrapper MpqArchiveHandle_Api::GetMpqArchive() {
  MpqArchiveHandle_Wrapper wrapper(*this);

  return wrapper.GetMpqArchive();
}

void MpqArchiveHandle_Api::SetMpqArchive(MpqArchive_Wrapper mpq_archive) {
  MpqArchiveHandle_Wrapper wrapper(*this);

  wrapper.SetMpqArchive(mpq_archive);
}

char* MpqArchiveHandle_Api::GetMpqArchivePath() {
  MpqArchiveHandle_Wrapper wrapper(*this);

  return wrapper.GetMpqArchivePath();
}

const char* MpqArchiveHandle_Api::GetMpqArchivePath() const {
  MpqArchiveHandle_View view(*this);

  return view.GetMpqArchivePath();
}

} // namespace d2
