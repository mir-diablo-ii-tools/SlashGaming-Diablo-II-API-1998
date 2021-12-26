/**
 * SlashGaming Diablo II Modding API for C
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "game_library.h"

#include <map>
#include <string>

#include <mdc/error/exit_on_error.h>
#include <mdc/std/threads.h>
#include <mdc/wchar_t/filew.h>

namespace mapi {

class GameLibrary {
 public:
  explicit GameLibrary(const wchar_t* file_path)
      : file_path_(file_path) {
    game_library_.file_path = file_path_.c_str();
    game_library_.base_address = LoadGameLibrary(file_path);
  }

  friend bool operator==(
      const GameLibrary& game_library1,
      const GameLibrary& game_library2
  ) {
    return game_library1.file_path_ == game_library2.file_path_;
  }

  friend bool operator<(
      const GameLibrary& game_library1,
      const GameLibrary& game_library2
  ) {
    return game_library1.file_path_ < game_library2.file_path_;
  }

  Mapi_GameLibrary& game_library() throw() {
    return this->game_library_;
  }

  const Mapi_GameLibrary& game_library() const throw() {
    return this->game_library_;
  }

 private:
  std::wstring file_path_;
  ::Mapi_GameLibrary game_library_;

  intptr_t LoadGameLibrary(const wchar_t* file_path) {
    HMODULE base_address = LoadLibraryW(file_path);

    if (base_address == NULL) {
      Mdc_Error_ExitOnWindowsFunctionError(
          __FILEW__,
          __LINE__,
          L"LoadLibraryW",
          GetLastError()
      );

      return NULL;
    }

    return reinterpret_cast<intptr_t>(base_address);
  }
};

} // namespace mapi

typedef std::map<std::wstring, mapi::GameLibrary> GameLibraryTable;

static GameLibraryTable*& GetGameLibraryTable() {
  static GameLibraryTable* game_library_sorted_table = NULL;

  return game_library_sorted_table;
}

static void InitGameLibraryTable() {
  GetGameLibraryTable() = new GameLibraryTable();
}

static void InitStatic() {
  static once_flag game_library_sorted_table_init_flag = ONCE_FLAG_INIT;

  call_once(
      &game_library_sorted_table_init_flag,
      &InitGameLibraryTable
  );
}

/**
 * External functions
 */

const Mapi_GameLibrary* Mapi_GameLibrary_GetFromPath(
    const wchar_t* file_path
) {
  InitStatic();

  GameLibraryTable& game_library_table = *GetGameLibraryTable();

  std::wstring file_path_str = file_path;
  GameLibraryTable::iterator find_result = game_library_table.find(
      file_path_str
  );

  if (find_result == game_library_table.end()) {
    std::pair<GameLibraryTable::iterator, bool> success_pair =
        game_library_table.insert(
            std::make_pair(
                file_path_str,
                mapi::GameLibrary(file_path)
            )
        );

    if (!success_pair.second) {
      Mdc_Error_ExitOnGeneralError(
          L"Error",
          L"Failed to insert path %s",
          __FILEW__,
          __LINE__,
          file_path
      );

      return NULL;
    }

    find_result = game_library_table.find(file_path_str);
  }

  return &find_result->second.game_library();
}
