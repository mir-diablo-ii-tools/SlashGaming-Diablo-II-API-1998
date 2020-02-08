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

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "../backend/error_handling.h"
#include "../../../include/c/game_version.h"
#include "../../wide_macro.h"

/**
 * Static assertions (1.00)
 */

static_assert(
    sizeof(struct D2_CelContext_1_00) == 0x48,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_CelContext_1_00, cel_file) == 0x04,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_00, frame) == 0x08,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_00, direction) == 0x0C,
    "Incorrect member alignment."
);

/**
 * Static assertions (1.12A)
 */

static_assert(
    sizeof(struct D2_CelContext_1_12A) == 0x48,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_CelContext_1_12A, cel_file) == 0x3C,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_12A, frame) == 0x40,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_12A, direction) == 0x38,
    "Incorrect member alignment."
);

/**
 * Static assertions (1.13C)
 */

static_assert(
    sizeof(struct D2_CelContext_1_13C) == 0x48,
    "Incorrect size."
);

static_assert(
    offsetof(struct D2_CelContext_1_13C, cel_file) == 0x34,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_13C, frame) == 0x00,
    "Incorrect member alignment."
);

static_assert(
    offsetof(struct D2_CelContext_1_13C, direction) == 0x40,
    "Incorrect member alignment."
);

/**
 * Function definitions
 */

struct D2_CelContext* D2_CelContext_Create(
    struct D2_CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) {
  enum D2_GameVersion running_game_version = D2_GetRunningGameVersionId();

  if (running_game_version >= VERSION_1_00
      && running_game_version <= VERSION_1_10) {
    struct D2_CelContext_1_00* actual_cel_context =
        (struct D2_CelContext_1_00*) malloc(sizeof(*actual_cel_context));

    if (actual_cel_context == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
    }

    actual_cel_context->cel_file = (struct D2_CelFile_1_00*) cel_file;
    actual_cel_context->direction = direction;
    actual_cel_context->frame = frame;

    return (struct D2_CelContext*) actual_cel_context;
  } else if (running_game_version == VERSION_1_12A) {
    struct D2_CelContext_1_12A* actual_cel_context =
        (struct D2_CelContext_1_12A*) malloc(sizeof(*actual_cel_context));

    if (actual_cel_context == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
    }

    actual_cel_context->cel_file = (struct D2_CelFile_1_00*) cel_file;
    actual_cel_context->direction = direction;
    actual_cel_context->frame = frame;

    return (struct D2_CelContext*) actual_cel_context;
  } else /* if (running_game_version >= VERSION_1_13A_BETA
      && running_game_version <= LOD_1_14D) */ {
    struct D2_CelContext_1_13C* actual_cel_context =
        (struct D2_CelContext_1_13C*) malloc(sizeof(*actual_cel_context));

    if (actual_cel_context == NULL) {
      ExitOnAllocationFailure(__FILEW__, __LINE__);
    }

    actual_cel_context->cel_file = (struct D2_CelFile_1_00*) cel_file;
    actual_cel_context->direction = direction;
    actual_cel_context->frame = frame;

    return (struct D2_CelContext*) actual_cel_context;
  }
}

void D2_CelContext_Destroy(struct D2_CelContext* cel_context) {
  free(cel_context);
}

struct D2_CelFile* D2_CelContext_GetCelFile(
    struct D2_CelContext* cel_context
) {
  return (struct D2_CelFile*) D2_CelContext_GetConstCelFile(cel_context);
}

const struct D2_CelFile* D2_CelContext_GetConstCelFile(
    const struct D2_CelContext* cel_context
) {
  const struct D2_CelContext_1_00* actual_cel_context =
      (const struct D2_CelContext_1_00*) cel_context;

  return (const struct D2_CelFile*) actual_cel_context->cel_file;
}

void D2_CelContext_SetCelFile(
    struct D2_CelContext* cel_context,
    struct D2_CelFile* cel_file
) {
  struct D2_CelContext_1_00* actual_cel_context =
      (struct D2_CelContext_1_00*) cel_context;

  struct D2_CelFile_1_00* actual_cel_file =
      (struct D2_CelFile_1_00*) cel_file;

  actual_cel_context->cel_file = actual_cel_file;
}

unsigned int D2_CelContext_GetDirection(
    const struct D2_CelContext* cel_context
) {
  const struct D2_CelContext_1_00* actual_cel_context =
      (const struct D2_CelContext_1_00*) cel_context;

  return actual_cel_context->direction;
}

void D2_CelContext_SetDirection(
    struct D2_CelContext* cel_context,
    unsigned int direction
) {
  struct D2_CelContext_1_00* actual_cel_context =
      (struct D2_CelContext_1_00*) cel_context;

  actual_cel_context->direction = direction;
}

unsigned int D2_CelContext_GetFrame(
    const struct D2_CelContext* cel_context
) {
  const struct D2_CelContext_1_00* actual_cel_context =
      (const struct D2_CelContext_1_00*) cel_context;

  return actual_cel_context->frame;
}

void D2_CelContext_SetFrame(
    struct D2_CelContext* cel_context,
    unsigned int frame
) {
  struct D2_CelContext_1_00* actual_cel_context =
      (struct D2_CelContext_1_00*) cel_context;

  actual_cel_context->frame = frame;
}
