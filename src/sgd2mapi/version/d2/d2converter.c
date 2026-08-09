/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2025  Mir Drualga
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

#include "sgd2mapi/version/d2/d2converter.h"

#include <stddef.h>

#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/protected_section/d2core.h"
#include "sgd2mapi/version/d2/d2types.h"

/**
 * External
 */

enum VersionD2 VersionD2_FromD2SeD2Core(
    enum D2SeD2Core d2core, struct SGD2Error* error) {
  if (error != NULL) {
    error->type = SGD2ERROR_GOOD;
  }

  switch (d2core) {
    case D2SED2CORE_1_07:
      return VERSIOND2_1_07;
    case D2SED2CORE_1_08:
      return VERSIOND2_1_08;
    case D2SED2CORE_1_09B:
      return VERSIOND2_1_09B;
    case D2SED2CORE_1_09D:
      return VERSIOND2_1_09D;
    case D2SED2CORE_1_10F:
      return VERSIOND2_1_10;
    case D2SED2CORE_1_11B:
      return VERSIOND2_1_11B;
    case D2SED2CORE_1_12A:
      return VERSIOND2_1_12;
    case D2SED2CORE_1_13C:
      return VERSIOND2_1_13C;
    default:
      if (error != NULL) {
        error->path = __FILEW__;
        error->line = __LINE__;
        error->function_name = L"VersionD2_FromD2SeD2Core";
        error->type = SGD2ERROR_UNEXPECTED_ERROR;
        error->unexpected_error.code =
            SGD2UNEXPECTEDERRORCODE_NO_CONSTANT_MAPPING;
      }
      goto error;
  }

error:
  return VERSIOND2_UNSPECIFIED;
}
