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

#ifndef SGD2MAPI_CXX98_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_API_HPP_
#define SGD2MAPI_CXX98_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_API_HPP_

#include <stddef.h>

#include <mdc/std/assert.h>
#include <sgd2mapi98.h>
#include "d2_cel_file_struct.hpp"
#include "d2_cel_file_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelFile_Api {
 public:
  union ApiType {
    CelFile_1_00* v1_00;
  };

  CelFile_Api();

  CelFile_Api(const char* path, bool is_dcc_else_dc6);

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  CelFile_Api(const CelFile_Api& cel_file) = delete;

  CelFile_Api(CelFile_Api&& cel_file) noexcept;

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  ~CelFile_Api();

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  CelFile_Api& operator=(const CelFile_Api& cel_file) = delete;

  CelFile_Api& operator=(CelFile_Api&& cel_file) noexcept;

#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

  operator CelFile_View() const;

  operator CelFile_Wrapper();

  CelFile* Get();

  const CelFile* Get() const;

  void Close();

  bool DrawFrame(
      int position_x,
      int position_y,
      unsigned int direction_index,
      unsigned int frame_index
  );

  Cel_Wrapper GetCel(
      unsigned int direction_index,
      unsigned int frame_index
  );

  bool IsOpen() const;

  void Open(const char* path, bool is_dcc_else_dc6);

  unsigned int GetNumFrames() const;

  void SetNumFrames(unsigned int num_frames);

  unsigned int GetNumDirections() const;

  void SetNumDirections(unsigned int num_directions);

  unsigned int GetVersion() const;

  void SetVersion(unsigned int version);

 private:
  ApiType cel_file_;
  bool is_open_;

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

  /*
  * These functions are intentionally unusable. They need to be
  * defined for DLL export, however. They should not be used
  * internally and cannot be used externally.
  */

  CelFile_Api(const CelFile_Api&) {}
  CelFile_Api& operator=(const CelFile_Api&) {
    assert(false);
    return *this;
  }

#endif // __cplusplus < 201103L && _MSVC_LANG < 201103L
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif /* SGD2MAPI_CXX98_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_API_HPP_ */
