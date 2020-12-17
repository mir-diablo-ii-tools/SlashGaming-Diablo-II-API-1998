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

#include <stdlib.h>

#include <mdc/malloc/malloc.h>
#include "../../../include/c/game_version.h"
#include "../../wide_macro.h"
#include "../backend/error_handling.h"

union D2_CelContext_View {
  const struct D2_CelContext_1_00* _1_00;
  const struct D2_CelContext_1_12A* _1_12a;
  const struct D2_CelContext_1_13C* _1_13c;
};

union D2_CelContext_Wrapper {
  struct D2_CelContext_1_00* _1_00;
  struct D2_CelContext_1_12A* _1_12a;
  struct D2_CelContext_1_13C* _1_13c;
};

/**
 * Function definitions
 */

struct D2_CelContext* D2_CelContext_Create(
    struct D2_CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) {
  enum D2_GameVersion running_game_version;
  union D2_CelContext_Wrapper actual_cel_context;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    actual_cel_context._1_00 = (struct D2_CelContext_1_00*)
        Mdc_malloc(sizeof(*actual_cel_context._1_00));

    if (actual_cel_context._1_00 == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
      goto return_bad;
    }

    actual_cel_context._1_00->cel_file =
        (struct D2_CelFile_1_00*) cel_file;
    actual_cel_context._1_00->direction = direction;
    actual_cel_context._1_00->frame = frame;

    return (struct D2_CelContext*) actual_cel_context._1_00;
  } else if (running_game_version == VERSION_1_12A) {
    actual_cel_context._1_12a = (struct D2_CelContext_1_12A*)
        Mdc_malloc(sizeof(*actual_cel_context._1_12a));

    if (actual_cel_context._1_12a == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
      goto return_bad;
    }

    actual_cel_context._1_12a->cel_file =
        (struct D2_CelFile_1_00*) cel_file;
    actual_cel_context._1_12a->direction = direction;
    actual_cel_context._1_12a->frame = frame;

    return (struct D2_CelContext*) actual_cel_context._1_12a;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    actual_cel_context._1_13c = (struct D2_CelContext_1_13C*)
        Mdc_malloc(sizeof(*actual_cel_context._1_13c));

    if (actual_cel_context._1_13c == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
      goto return_bad;
    }

    actual_cel_context._1_13c->cel_file =
        (struct D2_CelFile_1_00*) cel_file;
    actual_cel_context._1_13c->direction = direction;
    actual_cel_context._1_13c->frame = frame;

    return (struct D2_CelContext*) actual_cel_context._1_13c;
  }

return_bad:
  return NULL;
}

void D2_CelContext_Destroy(struct D2_CelContext* cel_context) {
  Mdc_free(cel_context);
}

struct D2_CelFile* D2_CelContext_GetCelFile(
    struct D2_CelContext* cel_context
) {
  return (struct D2_CelFile*) D2_CelContext_GetConstCelFile(cel_context);
}

const struct D2_CelFile* D2_CelContext_GetConstCelFile(
    const struct D2_CelContext* cel_context
) {
  union D2_CelContext_View view;
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    view._1_00 = (const struct D2_CelContext_1_00*) cel_context;

    return (const struct D2_CelFile*) view._1_00->cel_file;
  } else if (running_game_version == VERSION_1_12A) {
    view._1_12a = (const struct D2_CelContext_1_12A*) cel_context;

    return (const struct D2_CelFile*) view._1_12a->cel_file;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    view._1_13c = (const struct D2_CelContext_1_13C*) cel_context;

    return (const struct D2_CelFile*) view._1_13c->cel_file;
  }
}

void D2_CelContext_SetCelFile(
    struct D2_CelContext* cel_context,
    struct D2_CelFile* cel_file
) {
  union D2_CelContext_Wrapper wrapper;
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    wrapper._1_00 = (struct D2_CelContext_1_00*) cel_context;
    wrapper._1_00->cel_file = (struct D2_CelFile_1_00*) cel_file;
  } else if (running_game_version == VERSION_1_12A) {
    wrapper._1_12a = (struct D2_CelContext_1_12A*) cel_context;
    wrapper._1_12a->cel_file = (struct D2_CelFile_1_00*) cel_file;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    wrapper._1_13c = (struct D2_CelContext_1_13C*) cel_context;
    wrapper._1_13c->cel_file = (struct D2_CelFile_1_00*) cel_file;
  }
}

unsigned int D2_CelContext_GetDirection(
    const struct D2_CelContext* cel_context
) {
  union D2_CelContext_View view;
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    view._1_00 = (const struct D2_CelContext_1_00*) cel_context;

    return view._1_00->direction;
  } else if (running_game_version == VERSION_1_12A) {
    view._1_12a = (const struct D2_CelContext_1_12A*) cel_context;

    return view._1_12a->direction;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    view._1_13c = (const struct D2_CelContext_1_13C*) cel_context;

    return view._1_13c->direction;
  }
}

void D2_CelContext_SetDirection(
    struct D2_CelContext* cel_context,
    unsigned int direction
) {
  union D2_CelContext_Wrapper wrapper;
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    wrapper._1_00 = (struct D2_CelContext_1_00*) cel_context;
    wrapper._1_00->direction = direction;
  } else if (running_game_version == VERSION_1_12A) {
    wrapper._1_12a = (struct D2_CelContext_1_12A*) cel_context;
    wrapper._1_12a->direction = direction;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    wrapper._1_13c = (struct D2_CelContext_1_13C*) cel_context;
    wrapper._1_13c->direction = direction;
  }
}

unsigned int D2_CelContext_GetFrame(
    const struct D2_CelContext* cel_context
) {
  union D2_CelContext_View view;
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    view._1_00 = (const struct D2_CelContext_1_00*) cel_context;

    return view._1_00->frame;
  } else if (running_game_version == VERSION_1_12A) {
    view._1_12a = (const struct D2_CelContext_1_12A*) cel_context;

    return view._1_12a->frame;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    view._1_13c = (const struct D2_CelContext_1_13C*) cel_context;

    return view._1_13c->frame;
  }
}

void D2_CelContext_SetFrame(
    struct D2_CelContext* cel_context,
    unsigned int frame
) {
  union D2_CelContext_Wrapper wrapper;
  enum D2_GameVersion running_game_version;

  running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version <= VERSION_1_10) {
    wrapper._1_00 = (struct D2_CelContext_1_00*) cel_context;
    wrapper._1_00->frame = frame;
  } else if (running_game_version == VERSION_1_12A) {
    wrapper._1_12a = (struct D2_CelContext_1_12A*) cel_context;
    wrapper._1_12a->frame = frame;
  } else /* if (running_game_version >= VERSION_1_13A_BETA) */ {
    wrapper._1_13c = (struct D2_CelContext_1_13C*) cel_context;
    wrapper._1_13c->frame = frame;
  }
}
