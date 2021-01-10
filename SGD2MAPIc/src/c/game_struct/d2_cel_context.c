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

#include "../../../include/c/game_struct/d2_cel_context.h"

#include <mdc/error/exit_on_error.h>
#include <mdc/malloc/malloc.h>
#include <mdc/wchar_t/filew.h>
#include "../../../include/c/game_version.h"

/**
 * Function definitions
 */

struct D2_CelContext* D2_CelContext_Create(
    struct D2_CelFile* cel_file,
    unsigned int direction_index,
    unsigned int frame_index
) {
  union D2_CelContext_Wrapper wrapper;

  union D2_CelFile_Wrapper cel_file_wrapper;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    wrapper.ptr_1_00 = Mdc_malloc(sizeof(*wrapper.ptr_1_00));

    if (wrapper.ptr_1_00 == NULL) {
      Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
      goto return_bad;
    }

    cel_file_wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

    wrapper.ptr_1_00->cel_file = cel_file_wrapper.ptr_1_00;
    wrapper.ptr_1_00->direction_index = direction_index;
    wrapper.ptr_1_00->frame_index = frame_index;

    return (struct D2_CelContext*) wrapper.ptr_1_00;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    wrapper.ptr_1_12a = Mdc_malloc(sizeof(*wrapper.ptr_1_12a));

    if (wrapper.ptr_1_12a == NULL) {
      Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
      goto return_bad;
    }

    cel_file_wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

    wrapper.ptr_1_12a->cel_file = cel_file_wrapper.ptr_1_00;
    wrapper.ptr_1_12a->direction_index = direction_index;
    wrapper.ptr_1_12a->frame_index = frame_index;

    return (struct D2_CelContext*) wrapper.ptr_1_12a;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    wrapper.ptr_1_13c = Mdc_malloc(sizeof(*wrapper.ptr_1_13c));

    if (wrapper.ptr_1_13c == NULL) {
      Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
      goto return_bad;
    }

    cel_file_wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

    wrapper.ptr_1_13c->cel_file = cel_file_wrapper.ptr_1_00;
    wrapper.ptr_1_13c->direction_index = direction_index;
    wrapper.ptr_1_13c->frame_index = frame_index;

    return (struct D2_CelContext*) wrapper.ptr_1_13c;
  }

return_bad:
  return NULL;
}

void D2_CelContext_Destroy(struct D2_CelContext* cel_context) {
  Mdc_free(cel_context);
}

struct D2_CelContext* D2_CelContext_AssignMembers(
    struct D2_CelContext* dest,
    const struct D2_CelContext* src
) {
  union D2_CelContext_Wrapper dest_wrapper;
  union D2_CelContext_View src_view;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    dest_wrapper.ptr_1_00 = (struct D2_CelContext_1_00*) dest;
    src_view.ptr_1_00 = (const struct D2_CelContext_1_00*) src;

    *dest_wrapper.ptr_1_00 = *src_view.ptr_1_00;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    dest_wrapper.ptr_1_12a = (struct D2_CelContext_1_12A*) dest;
    src_view.ptr_1_12a = (const struct D2_CelContext_1_12A*) src;

    *dest_wrapper.ptr_1_12a = *src_view.ptr_1_12a;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    dest_wrapper.ptr_1_13c = (struct D2_CelContext_1_13C*) dest;
    src_view.ptr_1_13c = (const struct D2_CelContext_1_13C*) src;

    *dest_wrapper.ptr_1_13c = *src_view.ptr_1_13c;
  }

  return dest;
}

struct D2_CelFile* D2_CelContext_GetCelFile(
    struct D2_CelContext* cel_context
) {
  return (struct D2_CelFile*) D2_CelContext_GetCelFileConst(cel_context);
}

const struct D2_CelFile* D2_CelContext_GetCelFileConst(
    const struct D2_CelContext* cel_context
) {
  union D2_CelContext_View view;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    view.ptr_1_00 = (const struct D2_CelContext_1_00*) cel_context;

    return (struct D2_CelFile*) view.ptr_1_00->cel_file;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    view.ptr_1_12a = (const struct D2_CelContext_1_12A*) cel_context;

    return (struct D2_CelFile*) view.ptr_1_12a->cel_file;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    view.ptr_1_13c = (const struct D2_CelContext_1_13C*) cel_context;

    return (struct D2_CelFile*) view.ptr_1_13c->cel_file;
  }
}

void D2_CelContext_SetCelFile(
    struct D2_CelContext* cel_context,
    struct D2_CelFile* cel_file
) {
  union D2_CelContext_Wrapper wrapper;
  union D2_CelFile_Wrapper cel_file_wrapper;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    wrapper.ptr_1_00 = (struct D2_CelContext_1_00*) cel_context;
    cel_file_wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

    wrapper.ptr_1_00->cel_file = cel_file_wrapper.ptr_1_00;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    wrapper.ptr_1_12a = (struct D2_CelContext_1_12A*) cel_context;
    cel_file_wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

    wrapper.ptr_1_12a->cel_file = cel_file_wrapper.ptr_1_00;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    wrapper.ptr_1_13c = (struct D2_CelContext_1_13C*) cel_context;
    cel_file_wrapper.ptr_1_00 = (struct D2_CelFile_1_00*) cel_file;

    wrapper.ptr_1_13c->cel_file = cel_file_wrapper.ptr_1_00;
  }
}

unsigned int D2_CelContext_GetDirectionIndex(
    const struct D2_CelContext* cel_context
) {
  union D2_CelContext_View view;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    view.ptr_1_00 = (const struct D2_CelContext_1_00*) cel_context;

    return view.ptr_1_00->direction_index;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    view.ptr_1_12a = (const struct D2_CelContext_1_12A*) cel_context;

    return view.ptr_1_12a->direction_index;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    view.ptr_1_13c = (const struct D2_CelContext_1_13C*) cel_context;

    return view.ptr_1_13c->direction_index;
  }
}

void D2_CelContext_SetDirectionIndex(
    struct D2_CelContext* cel_context,
    unsigned int direction_index
) {
  union D2_CelContext_Wrapper wrapper;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    wrapper.ptr_1_00 = (struct D2_CelContext_1_00*) cel_context;

    wrapper.ptr_1_00->direction_index = direction_index;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    wrapper.ptr_1_12a = (struct D2_CelContext_1_12A*) cel_context;

    wrapper.ptr_1_12a->direction_index = direction_index;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    wrapper.ptr_1_13c = (struct D2_CelContext_1_13C*) cel_context;

    wrapper.ptr_1_13c->direction_index = direction_index;
  }
}

unsigned int D2_CelContext_GetFrameIndex(
    const struct D2_CelContext* cel_context
) {
  union D2_CelContext_View view;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    view.ptr_1_00 = (const struct D2_CelContext_1_00*) cel_context;

    return view.ptr_1_00->frame_index;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    view.ptr_1_12a = (const struct D2_CelContext_1_12A*) cel_context;

    return view.ptr_1_12a->frame_index;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    view.ptr_1_13c = (const struct D2_CelContext_1_13C*) cel_context;

    return view.ptr_1_13c->frame_index;
  }
}

void D2_CelContext_SetFrameIndex(
    struct D2_CelContext* cel_context,
    unsigned int frame_index
) {
  union D2_CelContext_Wrapper wrapper;

  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersion();

  if (running_game_version >= D2_GameVersion_k1_00
      && running_game_version <= D2_GameVersion_k1_10) {
    wrapper.ptr_1_00 = (struct D2_CelContext_1_00*) cel_context;

    wrapper.ptr_1_00->frame_index = frame_index;
  } else if (running_game_version == D2_GameVersion_k1_12A) {
    wrapper.ptr_1_12a = (struct D2_CelContext_1_12A*) cel_context;

    wrapper.ptr_1_12a->frame_index = frame_index;
  } else /* if (running_game_version >= D2_GameVersion_k1_13ABeta
      && running_game_version <= D2_GameVersion_kLod1_14D) */ {
    wrapper.ptr_1_13c = (struct D2_CelContext_1_13C*) cel_context;

    wrapper.ptr_1_13c->frame_index = frame_index;
  }
}
