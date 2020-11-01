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

#include "file_version_struct.h"

#include "../../error_handling.h"

struct Mapi_FileVersion* Mapi_FileVersion_InitDefault(
    struct Mapi_FileVersion* file_version
){
  /* This is empty on purpose. */
}

struct Mapi_FileVersion* Mapi_FileVersion_InitCopy(
    struct Mapi_FileVersion* dest,
    const struct Mapi_FileVersion* src
) {
  *dest = *src;

  return dest;
}

struct Mapi_FileVersion* Mapi_FileVersion_InitMove(
    struct Mapi_FileVersion* dest,
    struct Mapi_FileVersion* src
) {
  return Mapi_FileVersion_InitCopy(dest, src);
}

void Mapi_FileVersion_Deinit(
    struct Mapi_FileVersion* file_version
) {
  /* This is empty on purpose. */
}

struct Mapi_FileVersion* Mapi_FileVersion_AssignCopy(
    struct Mapi_FileVersion* dest,
    const struct Mapi_FileVersion* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

struct Mapi_FileVersion* Mapi_FileVersion_AssignMove(
    struct Mapi_FileVersion* dest,
    struct Mapi_FileVersion* src
) {
  return Mapi_FileVersion_AssignCopy(dest, src);
}

bool Mapi_FileVersion_Equal(
    const struct Mapi_FileVersion* file_version1,
    const struct Mapi_FileVersion* file_version2
) {
  if (file_version1->major_left != file_version2->major_left) {
    return false;
  }

  if (file_version1->major_right != file_version2->major_right) {
    return false;
  }

  if (file_version1->minor_left != file_version2->minor_left) {
    return false;
  }

  if (file_version1->minor_right != file_version2->minor_right) {
    return false;
  }

  return true;
}

int Mapi_FileVersion_Compare(
    const struct Mapi_FileVersion* file_version1,
    const struct Mapi_FileVersion* file_version2
) {
  if (file_version1->major_left < file_version2->major_left) {
    return -1;
  } else if (file_version1->major_left > file_version2->major_left) {
    return 1;
  }

  if (file_version1->major_right < file_version2->major_right) {
    return -1;
  } else if (file_version1->major_right > file_version2->major_right) {
    return 1;
  }

  if (file_version1->minor_left < file_version2->minor_left) {
    return -1;
  } else if (file_version1->minor_left > file_version2->minor_left) {
    return 1;
  }

  if (file_version1->minor_right < file_version2->minor_right) {
    return -1;
  } else if (file_version1->minor_right > file_version2->minor_right) {
    return 1;
  }

  return 0;
}

void Mapi_FileVersion_Swap(
    struct Mapi_FileVersion* file_version1,
    struct Mapi_FileVersion* file_version2
) {
  struct Mapi_FileVersion temp_file_version;
  struct Mapi_FileVersion* init_temp_file_version;

  struct Mapi_FileVersion* assign_file_version1;
  struct Mapi_FileVersion* assign_file_version2;

  init_temp_file_version = Mapi_FileVersion_InitMove(
      &temp_file_version,
      file_version1
  );

  if (init_temp_file_version != &temp_file_version) {
    goto return_bad;
  }

  assign_file_version1 = Mapi_FileVersion_AssignMove(
      file_version1,
      file_version2
  );

  if (assign_file_version1 != file_version1) {
    goto return_bad;
  }

  assign_file_version2 = Mapi_FileVersion_AssignMove(
      file_version2,
      &temp_file_version
  );

  if (assign_file_version2 != file_version2) {
    goto return_bad;
  }

  return;

return_bad:
  return;
}
