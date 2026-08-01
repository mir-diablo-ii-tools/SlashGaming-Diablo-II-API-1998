
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

#include "sgd2mapi/d2se/ini_properties.h"

#include <mdc/std/wchar.h>

#include "ini_properties/protected_section.h"
#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/protected_section.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section.h"

/**
 * External
 */

struct D2SeIniProperties* D2SeIniProperties_ReadFrom(
    struct D2SeIniProperties* properties,
    const wchar_t* path,
    struct SGD2Error* error) {
  void* read_from_result;

  read_from_result =
      D2SeProtectedSection_ReadFrom(
          &properties->protected_section, path, error);
  if (read_from_result == NULL) {
    goto error;
  }

  read_from_result =
      D2SeUserSettingsSection_ReadFrom(
          &properties->user_settings, path, error);
  if (read_from_result == NULL) {
    goto error;
  }

  return properties;

error:
  return NULL;
}

int D2SeIniProperties_Equals(
    const struct D2SeIniProperties* lhs, const struct D2SeIniProperties* rhs) {
  int equals_result;

  equals_result =
      D2SeUserSettingsSection_Equals(&lhs->user_settings, &rhs->user_settings);
  if (!equals_result) {
    return 0;
  }

  equals_result =
      D2SeProtectedSection_Equals(
          &lhs->protected_section, &rhs->protected_section);
  if (!equals_result) {
    return 0;
  }

  return 1;
}
