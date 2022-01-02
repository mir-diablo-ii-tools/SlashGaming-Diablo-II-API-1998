/**
 * SlashGaming Diablo II Modding API for C++98
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../../../include/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_wrapper.hpp"

#include "../../../../include/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_api.hpp"

namespace d2 {

CelFile_Wrapper::CelFile_Wrapper(CelFile* cel_file) {
  this->cel_file_.v1_00 = reinterpret_cast<CelFile_1_00*>(cel_file);
}

CelFile_Wrapper::CelFile_Wrapper(CelFile_1_00* cel_file) {
  this->cel_file_.v1_00 = cel_file;
}

CelFile_Wrapper::operator CelFile_View() const {
  return CelFile_View(this->Get());
}

CelFile* CelFile_Wrapper::Get() {
  const CelFile_Wrapper* const_this = this;

  return const_cast<CelFile*>(const_this->Get());
}

bool CelFile_Wrapper::DrawFrame(
    int position_x,
    int position_y,
    unsigned int direction_index,
    unsigned int frame_index
) {
  CelContext_Api cel_context(
      this->Get(),
      direction_index,
      frame_index
  );

  return cel_context.DrawFrame(position_x, position_y);
}

Cel_Wrapper CelFile_Wrapper::GetCel(
    unsigned int direction_index,
    unsigned int frame_index
) {
  CelContext_Api cel_context(
      this->Get(),
      direction_index,
      frame_index
  );

  return cel_context.GetCel();
}

const CelFile* CelFile_Wrapper::Get() const {
  return reinterpret_cast<const CelFile*>(this->cel_file_.v1_00);
}

unsigned int CelFile_Wrapper::GetNumFrames() const {
  CelFile_View view(*this);

  return view.GetNumFrames();
}

void CelFile_Wrapper::SetNumFrames(unsigned int num_frames) {
  ::D2_CelFile_SetNumFrames(this->Get(), num_frames);
}

unsigned int CelFile_Wrapper::GetNumDirections() const {
  CelFile_View view(*this);

  return view.GetNumDirections();
}

void CelFile_Wrapper::SetNumDirections(unsigned int num_directions) {
  ::D2_CelFile_SetNumDirections(this->Get(), num_directions);
}

unsigned int CelFile_Wrapper::GetVersion() const {
  CelFile_View view(*this);

  return view.GetVersion();
}

void CelFile_Wrapper::SetVersion(unsigned int version) {
  ::D2_CelFile_SetVersion(this->Get(), version);
}

} // namespace d2
