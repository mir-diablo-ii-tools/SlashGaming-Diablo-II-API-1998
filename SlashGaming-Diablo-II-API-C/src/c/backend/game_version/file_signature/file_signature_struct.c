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

#include "file_signature_struct.h"

#include <stdio.h>
#include <string.h>

#include "../../../../wide_macro.h"
#include "../../error_handling.h"

#define MAPI_IMPL_FILE_SIGNATURE_UNINIT { 0 }

static const struct Mapi_Impl_FileSignature
Mapi_Impl_FileSignature_kUninit = MAPI_IMPL_FILE_SIGNATURE_UNINIT;

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitFromLiteral(
    struct Mapi_Impl_FileSignature* file_signature,
    const struct Mapi_Impl_FileSignatureLiteral* lit
) {
  struct Mdc_Fs_Path* init_file_path;

  init_file_path = Mdc_Fs_Path_InitFromCWStr(
      &file_signature->file_path_,
      lit->file_path_cstr
  );

  if (init_file_path != &file_signature->file_path_) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_InitFromCWStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  file_signature->offset_ = lit->offset;

  memcpy(
      file_signature->signature_,
      lit->signature,
      sizeof(file_signature->signature_)
  );

  return file_signature;

return_bad:
  *file_signature = Mapi_Impl_FileSignature_kUninit;

  return NULL;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitFromPath(
    struct Mapi_Impl_FileSignature* file_signature,
    struct Mdc_Fs_Path* file_path,
    ptrdiff_t offset
) {
  struct Mdc_Fs_Path* init_file_path;

  init_file_path = Mdc_Fs_Path_InitMove(
      &file_signature->file_path_,
      file_path
  );

  if (init_file_path != &file_signature->file_path_) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitMove", __FILEW__, __LINE__);
    goto return_bad;
  }

  file_signature->offset_ = offset;

  return file_signature;

return_bad:
  return NULL;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitFromPathCopy(
    struct Mapi_Impl_FileSignature* file_signature,
    const struct Mdc_Fs_Path* file_path,
    ptrdiff_t offset
) {
  struct Mdc_Fs_Path file_path_copy;
  struct Mdc_Fs_Path* init_file_path_copy;

  struct Mapi_Impl_FileSignature* init_file_signature;

  init_file_path_copy = Mdc_Fs_Path_InitCopy(
      &file_path_copy,
      file_path
  );

  if (init_file_path_copy != &file_path_copy) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitCopy", __FILEW__, __LINE__);
    goto return_bad;
  }

  init_file_signature = Mapi_Impl_FileSignature_InitFromPath(
      file_signature,
      &file_path_copy,
      offset
  );

  if (init_file_signature != file_signature) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"Mapi_Impl_FileSignature_InitFromPath failed"
    );

    goto deinit_file_path_copy;
  }

  Mdc_Fs_Path_Deinit(&file_path_copy);

  return file_signature;

deinit_file_path_copy:
  Mdc_Fs_Path_Deinit(&file_path_copy);

return_bad:
  return NULL;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitCopy(
    struct Mapi_Impl_FileSignature* dest,
    const struct Mapi_Impl_FileSignature* src
) {
  struct Mdc_Fs_Path* init_file_path;

  init_file_path = Mdc_Fs_Path_InitCopy(
      &dest->file_path_,
      &src->file_path_
  );

  if (init_file_path != &dest->file_path_) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_InitCopy",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  dest->offset_ = src->offset_;

  memcpy(dest->signature_, src->signature_, sizeof(dest->signature_));

  return dest;

return_bad:
  *dest = Mapi_Impl_FileSignature_kUninit;

  return NULL;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_InitMove(
    struct Mapi_Impl_FileSignature* dest,
    struct Mapi_Impl_FileSignature* src
) {
  struct Mdc_Fs_Path* init_file_path;

  init_file_path = Mdc_Fs_Path_InitMove(
      &dest->file_path_,
      &src->file_path_
  );

  if (init_file_path != &dest->file_path_) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_InitMove",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  dest->offset_ = src->offset_;

  memcpy(dest->signature_, src->signature_, sizeof(dest->signature_));

  return dest;

return_bad:
  *dest = Mapi_Impl_FileSignature_kUninit;

  return NULL;
}

void Mapi_Impl_FileSignature_Deinit(
    struct Mapi_Impl_FileSignature* file_signature
) {
  Mdc_Fs_Path_Deinit(&file_signature->file_path_);

  *file_signature = Mapi_Impl_FileSignature_kUninit;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_AssignCopy(
    struct Mapi_Impl_FileSignature* dest,
    const struct Mapi_Impl_FileSignature* src
) {
  struct Mapi_Impl_FileSignature temp_file_signature;
  struct Mapi_Impl_FileSignature* init_temp_file_signature;

  struct Mapi_Impl_FileSignature* assign_dest;

  if (dest == src) {
    return dest;
  }

  init_temp_file_signature = Mapi_Impl_FileSignature_InitCopy(
      &temp_file_signature,
      src
  );

  if (init_temp_file_signature != &temp_file_signature) {
    goto return_bad;
  }

  assign_dest = Mapi_Impl_FileSignature_AssignMove(
      dest,
      &temp_file_signature
  );

  if (assign_dest != dest) {
    goto deinit_temp_file_signature;
  }

  Mapi_Impl_FileSignature_Deinit(&temp_file_signature);

  return dest;

deinit_temp_file_signature:
  Mapi_Impl_FileSignature_Deinit(&temp_file_signature);

return_bad:
  return NULL;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_AssignMove(
    struct Mapi_Impl_FileSignature* dest,
    struct Mapi_Impl_FileSignature* src
) {
  struct Mdc_Fs_Path* assign_file_path;

  if (dest == src) {
    return dest;
  }

  assign_file_path = Mdc_Fs_Path_AssignMove(
      &dest->file_path_,
      &src->file_path_
  );

  if (assign_file_path != &dest->file_path_) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_AssignMove",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  dest->offset_ = src->offset_;

  memcpy(
      dest->signature_,
      src->signature_,
      sizeof(dest->signature_)
  );

  return dest;

return_bad:
  return NULL;
}

bool Mapi_Impl_FileSignature_Equal(
    const struct Mapi_Impl_FileSignature* file_signature1,
    const struct Mapi_Impl_FileSignature* file_signature2
) {
  const struct Mdc_Fs_Path* file_path1;
  const struct Mdc_Fs_Path* file_path2;

  const uint8_t* signature1;
  const uint8_t* signature2;
  int signature_compare_result;

  if (file_signature1 == file_signature2) {
    return true;
  }

  file_path1 = &file_signature1->file_path_;
  file_path2 = &file_signature2->file_path_;

  if (!Mdc_Fs_Path_EqualPath(file_path1, file_path2)) {
    return false;
  }

  signature1 = file_signature1->signature_;
  signature2 = file_signature2->signature_;

  signature_compare_result = memcmp(
      signature1,
      signature2,
      sizeof(file_signature1->signature_)
  );

  return signature_compare_result == 0;
}

bool Mapi_Impl_FileSignature_Compare(
    const struct Mapi_Impl_FileSignature* file_signature1,
    const struct Mapi_Impl_FileSignature* file_signature2
) {
  const struct Mdc_Fs_Path* file_path1;
  const struct Mdc_Fs_Path* file_path2;
  int file_path_compare_result;

  const uint8_t* signature1;
  const uint8_t* signature2;
  int signature_compare_result;

  if (file_signature1 == file_signature2) {
    return 0;
  }

  file_path1 = &file_signature1->file_path_;
  file_path2 = &file_signature2->file_path_;

  file_path_compare_result = Mdc_Fs_Path_ComparePath(
      file_path1,
      file_path2
  );

  if (file_path_compare_result != 0) {
    return file_path_compare_result;
  }

  signature1 = file_signature1->signature_;
  signature2 = file_signature2->signature_;

  signature_compare_result = memcmp(
      signature1,
      signature2,
      sizeof(file_signature1->signature_)
  );

  return signature_compare_result;
}

struct Mapi_Impl_FileSignature* Mapi_Impl_FileSignature_ReadFileSignature(
    struct Mapi_Impl_FileSignature* file_signature,
    const struct Mdc_Fs_Path* file_path,
    ptrdiff_t offset
) {
  struct Mdc_Fs_Path* init_file_path;

  FILE* file;
  int fseek_result;
  size_t fread_result;

  init_file_path = Mdc_Fs_Path_InitCopy(
      &file_signature->file_path_,
      file_path
  );

  if (init_file_path != &file_signature->file_path_) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitCopy", __FILEW__, __LINE__);
    goto return_bad;
  }

  file_signature->offset_ = offset;

  file = _wfopen(Mdc_Fs_Path_CStr(&file_signature->file_path_), L"rb");
  if (file == NULL) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"_wfopen failed"
    );

    goto deinit_file_path;
  }

  fseek_result = fseek(file, offset, SEEK_SET);
  if (fseek_result != 0) {
    fclose(file);

    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"fseek failed"
    );

    goto deinit_file_path;
  }

  fread_result = fread(
      file_signature->signature_,
      sizeof(file_signature->signature_[0]),
      Mapi_Impl_FileSignature_kSignatureByteCount,
      file
  );

  if (fread_result < Mapi_Impl_FileSignature_kSignatureByteCount) {
    fclose(file);

    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L"fread failed"
    );

    goto deinit_file_path;
  }

  fclose(file);

  return file_signature;

deinit_file_path:
  Mdc_Fs_Path_Deinit(&file_signature->file_path_);

return_bad:
  *file_signature = Mapi_Impl_FileSignature_kUninit;

  return NULL;
}

void Mapi_Impl_FileSignature_Swap(
    struct Mapi_Impl_FileSignature* file_signature1,
    struct Mapi_Impl_FileSignature* file_signature2
) {
  uint8_t temp_signature[Mapi_Impl_FileSignature_kSignatureByteCount];
  ptrdiff_t temp_offset;

  Mdc_Fs_Path_Swap(
      &file_signature1->file_path_,
      &file_signature2->file_path_
  );

  temp_offset = file_signature1->offset_;
  file_signature1->offset_ = file_signature2->offset_;
  file_signature2->offset_ = temp_offset;

  memcpy(
      temp_signature,
      file_signature1->signature_,
      Mapi_Impl_FileSignature_kSignatureByteCount
  );

  memcpy(
      file_signature1->signature_,
      file_signature2->signature_,
      Mapi_Impl_FileSignature_kSignatureByteCount
  );

  memcpy(
      file_signature2->signature_,
      temp_signature,
      Mapi_Impl_FileSignature_kSignatureByteCount
  );
}
