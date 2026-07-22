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

#include "sgd2mapi/d2se/ini_properties/user_settings_section.h"

#include "sgd2mapi/core/error/error.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/direct.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_hc.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/enable_plugy.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/no_sound.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/renderer.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/skip_to_bnet.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/txt.h"
#include "sgd2mapi/d2se/ini_properties/user_settings_section/window_mode.h"

/**
 * External
 */

struct D2SeUserSettingsSection* D2SeUserSettingsSection_ReadFrom(
    struct D2SeUserSettingsSection* user_settings,
    const wchar_t* path,
    struct SGD2Error* error) {
  user_settings->renderer = D2SeRenderer_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->window_mode = D2SeWindowMode_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->no_sound = D2SeNoSound_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->enable_hc = D2SeEnableHc_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->enable_plugy = D2SeEnablePlugY_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->direct = D2SeDirect_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->txt = D2SeTxt_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  user_settings->skip_to_bnet = D2SeSkipToBNet_ReadFrom(path, error);
  if (error != NULL && error->type != SGD2ERROR_GOOD) {
    goto error;
  }

  return user_settings;

error:
  return NULL;
}

struct D2SeUserSettingsSection* D2SeUserSettingsSection_GetDefault(
    struct D2SeUserSettingsSection* user_settings) {
  user_settings->renderer = D2SeRenderer_GetDefault();
  user_settings->window_mode = D2SeWindowMode_GetDefault();
  user_settings->no_sound = D2SeNoSound_GetDefault();
  user_settings->enable_hc = D2SeEnableHc_GetDefault();
  user_settings->enable_plugy = D2SeEnablePlugY_GetDefault();
  user_settings->direct = D2SeDirect_GetDefault();
  user_settings->txt = D2SeTxt_GetDefault();
  user_settings->skip_to_bnet = D2SeSkipToBNet_GetDefault();

  return user_settings;
}

int D2SeUserSettingsSection_Equals(
    const struct D2SeUserSettingsSection* lhs,
    const struct D2SeUserSettingsSection* rhs) {
  return lhs->renderer == rhs->renderer
      && lhs->window_mode == rhs->window_mode
      && lhs->no_sound == rhs->no_sound
      && lhs->enable_hc == rhs->enable_hc
      && lhs->enable_plugy == rhs->enable_plugy
      && lhs->direct == rhs->direct
      && lhs->txt == rhs->txt
      && lhs->skip_to_bnet == rhs->skip_to_bnet;
}
