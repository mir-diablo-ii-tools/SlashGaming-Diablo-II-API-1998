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

#include "../../../../include/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.hpp"

#include <sgd2mapi98.h>

namespace d2 {
namespace d2cmp {

Cel* GetCelFromCelContext(
    CelContext* cel_context
) {
  return ::D2_D2CMP_GetCelFromCelContext(cel_context);
}

Cel_1_00* GetCelFromCelContext_1_00(
    CelContext_1_00* cel_context
) {
  return ::D2_D2CMP_GetCelFromCelContext_1_00(cel_context);
}

Cel_1_00* GetCelFromCelContext_1_12A(
    CelContext_1_12A* cel_context
) {
  return ::D2_D2CMP_GetCelFromCelContext_1_12A(cel_context);
}

Cel_1_00* GetCelFromCelContext_1_13C(
    CelContext_1_13C* cel_context
) {
  return ::D2_D2CMP_GetCelFromCelContext_1_13C(cel_context);
}

} // namespace d2cmp
} // namespace d2
