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

#include "../../../../include/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_api.hpp"

#include <utility>

#include "../../../../include/sgd2mapi98/game_function/d2win/d2win_load_cel_file.hpp"
#include "../../../../include/sgd2mapi98/game_function/d2win/d2win_unload_cel_file.hpp"

namespace d2 {

CelFile_Api::CelFile_Api()
    : cel_file_(),
      is_open_(false) {
}

CelFile_Api::CelFile_Api(const char* path, bool is_dcc_else_dc6) {
  this->Open(path, is_dcc_else_dc6);
}

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

CelFile_Api::CelFile_Api(CelFile_Api&& cel_file) noexcept
    : cel_file_(
          ::std::move(cel_file.cel_file_)
      ),
      is_open_(::std::move(cel_file.is_open_)) {
  cel_file.cel_file_.v1_00 = NULL;
  cel_file.is_open_ = false;
}

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

CelFile_Api::~CelFile_Api() {
  this->Close();
}

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

CelFile_Api& CelFile_Api::operator=(
    CelFile_Api&& cel_file
) noexcept {
  if (this == &cel_file) {
    return *this;
  }

  this->cel_file_ = ::std::move(cel_file.cel_file_);
  this->is_open_ = ::std::move(cel_file.is_open_);

  cel_file.cel_file_.v1_00 = NULL;
  cel_file.is_open_ = false;

  return *this;
}

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

CelFile_Api::operator CelFile_View() const {
  return CelFile_View(this->Get());
}

CelFile_Api::operator CelFile_Wrapper() {
  return CelFile_Wrapper(this->Get());
}

CelFile* CelFile_Api::Get() {
  const CelFile_Api* const_this = this;

  return const_cast<CelFile*>(const_this->Get());
}

const CelFile* CelFile_Api::Get() const {
  return reinterpret_cast<const CelFile*>(this->cel_file_.v1_00);
}

void CelFile_Api::Close() {
  if (!this->IsOpen()) {
    return;
  }

  d2win::UnloadCelFile(this->Get());
  this->cel_file_.v1_00 = NULL;
  this->is_open_ = false;
}

bool CelFile_Api::DrawFrame(
    int position_x,
    int position_y,
    unsigned int direction_index,
    unsigned int frame_index
) {
  CelFile_Wrapper wrapper(*this);

  return wrapper.DrawFrame(
      position_x,
      position_y,
      direction_index,
      frame_index
  );
}

Cel_Wrapper CelFile_Api::GetCel(
    unsigned int direction_index,
    unsigned int frame_index
) {
  CelFile_Wrapper wrapper(*this);

  return wrapper.GetCel(
      direction_index,
      frame_index
  );
}

bool CelFile_Api::IsOpen() const {
  return this->is_open_;
}

void CelFile_Api::Open(const char* path, bool is_dcc_else_dc6) {
  this->Close();

  CelFile* cel_file = d2win::LoadCelFile(path, is_dcc_else_dc6);

  this->cel_file_.v1_00 = reinterpret_cast<CelFile_1_00*>(cel_file);

  this->is_open_ = (this->Get() != NULL);
}

unsigned int CelFile_Api::GetNumFrames() const {
  CelFile_View view(*this);

  return view.GetNumFrames();
}

void CelFile_Api::SetNumFrames(unsigned int num_frames) {
  CelFile_Wrapper wrapper(*this);

  wrapper.SetNumFrames(num_frames);
}

unsigned int CelFile_Api::GetNumDirections() const {
  CelFile_View view(*this);

  return view.GetNumDirections();
}

void CelFile_Api::SetNumDirections(unsigned int num_directions) {
  CelFile_Wrapper wrapper(*this);

  wrapper.SetNumDirections(num_directions);
}

unsigned int CelFile_Api::GetVersion() const {
  CelFile_View view(*this);

  return view.GetVersion();
}

void CelFile_Api::SetVersion(unsigned int version) {
  CelFile_Wrapper wrapper(*this);

  wrapper.SetVersion(version);
}

} // namespace d2
