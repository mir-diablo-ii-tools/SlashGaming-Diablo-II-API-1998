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

#include "game_address_locator.h"

#include <mdc/object/integer_object.h>
#include "../../../wide_macro.h"
#include "../error_handling.h"

union Mapi_Impl_LocatorValue* Mapi_Impl_LocatorValue_InitFromLiteral(
    union Mapi_Impl_LocatorValue* locator_value,
    enum Mapi_Impl_LocatorType locator_type,
    union Mapi_Impl_LocatorValueLiteral* literal_locator_value
) {
  struct Mdc_BasicString* init_decorated_name;

  switch (locator_type) {
    case Mapi_Impl_LocatorType_kOffset: {
      locator_value->offset = literal_locator_value->offset;
      break;
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      locator_value->ordinal = literal_locator_value->ordinal;
      break;
    }

    case Mapi_Impl_LocatorType_kDecoratedName: {
      init_decorated_name = Mdc_BasicString_InitFromCStr(
          &locator_value->decorated_name,
          Mdc_CharTraitsChar_GetCharTraits(),
          literal_locator_value->decorated_name
      );

      if (init_decorated_name != &locator_value->decorated_name) {
        ExitOnMdcFunctionFailure(
            L"Mdc_BasicString_InitFromCStr",
            __FILEW__,
            __LINE__
        );

        goto return_bad;
      }

      break;
    }
  }

  return locator_value;

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitFromLocatorType(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    enum Mapi_Impl_LocatorType locator_type,
    union Mapi_Impl_LocatorValue locator_value
) {
  struct Mapi_Impl_GameAddressLocator* init_game_address_locator;

  switch (locator_type) {
    case Mapi_Impl_LocatorType_kOffset: {
      init_game_address_locator = Mapi_Impl_GameAddressLocator_InitOffsetLocator(
          game_address_locator,
          library_path,
          locator_value.offset
      );

      break;
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      init_game_address_locator = Mapi_Impl_GameAddressLocator_InitOrdinalLocator(
          game_address_locator,
          library_path,
          locator_value.ordinal
      );

      break;
    }

    case Mapi_Impl_LocatorType_kDecoratedName: {
      init_game_address_locator =
          Mapi_Impl_GameAddressLocator_InitDecoratedNameLocator(
              game_address_locator,
              library_path,
              Mdc_BasicString_DataConst(&locator_value.decorated_name)
          );

      break;
    }

    default: {
      ExitOnConstantMappingMissing(locator_type, __FILEW__, __LINE__);
      goto return_bad;
    }
  }

  if (init_game_address_locator != game_address_locator) {
    goto return_bad;
  }

  return game_address_locator;

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitDecoratedNameLocator(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    const char* decorated_name_cstr
) {
  struct Mdc_Fs_Path* init_library_path;

  struct Mdc_BasicString* decorated_name;
  struct Mdc_BasicString* init_decorated_name;

  init_library_path = Mdc_Fs_Path_InitCopy(
      &game_address_locator->library_path,
      library_path
  );

  if (init_library_path != &game_address_locator->library_path) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitCopy", __FILEW__, __LINE__);
    goto return_bad;
  }

  game_address_locator->locator_type = Mapi_Impl_LocatorType_kDecoratedName;

  decorated_name = &game_address_locator->locator_value.decorated_name;

  init_decorated_name = Mdc_BasicString_InitFromCStr(
      decorated_name,
      Mdc_CharTraitsChar_GetCharTraits(),
      decorated_name_cstr
  );

  if (init_decorated_name != decorated_name) {
    ExitOnMdcFunctionFailure(
        L"Mdc_BasicString_InitFromCStr",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  return game_address_locator;

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitOffsetLocator(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    ptrdiff_t offset
) {
  struct Mdc_Fs_Path* init_library_path;

  init_library_path = Mdc_Fs_Path_InitCopy(
      &game_address_locator->library_path,
      library_path
  );

  if (init_library_path != &game_address_locator->library_path) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitCopy", __FILEW__, __LINE__);
    goto return_bad;
  }

  game_address_locator->locator_type = Mapi_Impl_LocatorType_kOffset;
  game_address_locator->locator_value.offset = offset;

  return game_address_locator;

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator*
Mapi_Impl_GameAddressLocator_InitOrdinalLocator(
    struct Mapi_Impl_GameAddressLocator* game_address_locator,
    const struct Mdc_Fs_Path* library_path,
    int16_t ordinal
) {
  struct Mdc_Fs_Path* init_library_path;

  init_library_path = Mdc_Fs_Path_InitCopy(
      &game_address_locator->library_path,
      library_path
  );

  if (init_library_path != &game_address_locator->library_path) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitCopy", __FILEW__, __LINE__);
    goto return_bad;
  }

  game_address_locator->locator_type = Mapi_Impl_LocatorType_kOffset;
  game_address_locator->locator_value.ordinal = ordinal;

  return game_address_locator;

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_InitCopy(
    struct Mapi_Impl_GameAddressLocator* dest,
    const struct Mapi_Impl_GameAddressLocator* src
) {
  struct Mdc_Fs_Path* init_library_path;
  struct Mdc_BasicString* init_decorated_name;

  init_library_path = Mdc_Fs_Path_InitCopy(
      &dest->library_path,
      &src->library_path
  );

  if (init_library_path != &dest->library_path) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitCopy", __FILEW__, __LINE__);
    goto return_bad;
  }

  dest->locator_type = src->locator_type;

  switch (dest->locator_type) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      init_decorated_name = Mdc_BasicString_InitCopy(
          &dest->locator_value.decorated_name,
          &src->locator_value.decorated_name
      );

      if (init_decorated_name != &dest->locator_value.decorated_name) {
        ExitOnMdcFunctionFailure(
            L"Mdc_BasicString_InitCopy",
            __FILEW__,
            __LINE__
        );

        goto return_bad;
      }

      break;
    }

    case Mapi_Impl_LocatorType_kOffset: {
      dest->locator_value.offset = src->locator_value.offset;
      break;
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      dest->locator_value.ordinal = src->locator_value.ordinal;
      break;
    }
  }

  return dest;

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_InitMove(
    struct Mapi_Impl_GameAddressLocator* dest,
    struct Mapi_Impl_GameAddressLocator* src
) {
  struct Mdc_Fs_Path* init_library_path;
  struct Mdc_BasicString* init_decorated_name;

  init_library_path = Mdc_Fs_Path_InitMove(
      &dest->library_path,
      &src->library_path
  );

  if (init_library_path != &dest->library_path) {
    ExitOnMdcFunctionFailure(L"Mdc_Fs_Path_InitMove", __FILEW__, __LINE__);
    goto return_bad;
  }

  dest->locator_type = src->locator_type;

  switch (dest->locator_type) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      init_decorated_name = Mdc_BasicString_InitMove(
          &dest->locator_value.decorated_name,
          &src->locator_value.decorated_name
      );

      if (init_decorated_name != &dest->locator_value.decorated_name) {
        ExitOnMdcFunctionFailure(
            L"Mdc_BasicString_InitMove",
            __FILEW__,
            __LINE__
        );

        goto return_bad;
      }

      break;
    }

    case Mapi_Impl_LocatorType_kOffset: {
      dest->locator_value.offset = src->locator_value.offset;
      break;
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      dest->locator_value.ordinal = src->locator_value.ordinal;
      break;
    }
  }

  return dest;

return_bad:
  return NULL;
}

void Mapi_Impl_GameAddressLocator_Deinit(
    struct Mapi_Impl_GameAddressLocator* game_address_locator
) {
  switch (game_address_locator->locator_type) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      Mdc_BasicString_Deinit(
          &game_address_locator->locator_value.decorated_name
      );

      break;
    }

    case Mapi_Impl_LocatorType_kOffset:
    case Mapi_Impl_LocatorType_kOrdinal: {
      break;
    }

    default: {
      ExitOnConstantMappingMissing(
          game_address_locator->locator_type,
          __FILEW__,
          __LINE__
      );

      goto return_bad;
    }
  }

  Mdc_Fs_Path_Deinit(&game_address_locator->library_path);

  return;

return_bad:
  return;
}

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_AssignCopy(
    struct Mapi_Impl_GameAddressLocator* dest,
    const struct Mapi_Impl_GameAddressLocator* src
) {
  struct Mapi_Impl_GameAddressLocator temp_game_address_locator;
  struct Mapi_Impl_GameAddressLocator* init_temp_game_address_locator;

  struct Mapi_Impl_GameAddressLocator* assign_dest;

  if (dest == src) {
    return dest;
  }

  init_temp_game_address_locator = Mapi_Impl_GameAddressLocator_InitCopy(
      &temp_game_address_locator,
      src
  );

  if (init_temp_game_address_locator != &temp_game_address_locator) {
    goto return_bad;
  }

  assign_dest = Mapi_Impl_GameAddressLocator_AssignMove(
      dest,
      &temp_game_address_locator
  );

  if (assign_dest != dest) {
    goto deinit_temp_game_address_locator;
  }

  Mapi_Impl_GameAddressLocator_Deinit(&temp_game_address_locator);

  return dest;

deinit_temp_game_address_locator:
  Mapi_Impl_GameAddressLocator_Deinit(&temp_game_address_locator);

return_bad:
  return NULL;
}

struct Mapi_Impl_GameAddressLocator* Mapi_Impl_GameAddressLocator_AssignMove(
    struct Mapi_Impl_GameAddressLocator* dest,
    struct Mapi_Impl_GameAddressLocator* src
) {
  struct Mdc_Fs_Path* assign_library_path;
  struct Mdc_BasicString* assign_decorated_name;

  if (dest == src) {
    return dest;
  }

  assign_library_path = Mdc_Fs_Path_AssignMove(
      &dest->library_path,
      &src->library_path
  );

  if (assign_library_path != &dest->library_path) {
    ExitOnMdcFunctionFailure(
        L"Mdc_Fs_Path_AssignMove",
        __FILEW__,
        __LINE__
    );

    goto return_bad;
  }

  dest->locator_type = src->locator_type;

  switch (dest->locator_type) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      assign_decorated_name = Mdc_BasicString_AssignMove(
          &dest->locator_value.decorated_name,
          &src->locator_value.decorated_name
      );

      if (assign_decorated_name != &dest->locator_value.decorated_name) {
        ExitOnMdcFunctionFailure(
            L"Mdc_BasicString_AssignMove",
            __FILEW__,
            __LINE__
        );

        goto return_bad;
      }

      break;
    }

    case Mapi_Impl_LocatorType_kOffset: {
      dest->locator_value.offset = src->locator_value.offset;
      break;
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      dest->locator_value.ordinal = src->locator_value.ordinal;
      break;
    }
  }

  return dest;

return_bad:
  return NULL;
}

bool Mapi_Impl_GameAddressLocator_Equal(
    const struct Mapi_Impl_GameAddressLocator* game_address_locator1,
    const struct Mapi_Impl_GameAddressLocator* game_address_locator2
) {
  bool is_library_path_equal;

  enum Mapi_Impl_LocatorType locator_type1;
  enum Mapi_Impl_LocatorType locator_type2;

  const union Mapi_Impl_LocatorValue* locator_value1;
  const union Mapi_Impl_LocatorValue* locator_value2;

  if (game_address_locator1 == game_address_locator2) {
    return true;
  }

  is_library_path_equal = Mdc_Fs_Path_EqualPath(
      &game_address_locator1->library_path,
      &game_address_locator2->library_path
  );

  if (!is_library_path_equal) {
    return false;
  }

  locator_type1 = game_address_locator1->locator_type;
  locator_type2 = game_address_locator2->locator_type;

  if (locator_type1 != locator_type2) {
    return false;
  }

  locator_value1 = &game_address_locator1->locator_value;
  locator_value2 = &game_address_locator2->locator_value;

  switch (locator_type1) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      return Mdc_BasicString_EqualStr(
          &locator_value1->decorated_name,
          &locator_value2->decorated_name
      );
    }

    case Mapi_Impl_LocatorType_kOffset: {
      return locator_value1->offset == locator_value2->offset;
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      return locator_value1->ordinal == locator_value2->ordinal;
    }

    default: {
      ExitOnConstantMappingMissing(locator_type1, __FILEW__, __LINE__);
      goto return_bad;
    }
  }

return_bad:
  return false;
}

int Mapi_Impl_GameAddressLocator_Compare(
    const struct Mapi_Impl_GameAddressLocator* game_address_locator1,
    const struct Mapi_Impl_GameAddressLocator* game_address_locator2
) {
  int compare_library_path;

  enum Mapi_Impl_LocatorType locator_type1;
  enum Mapi_Impl_LocatorType locator_type2;

  const union Mapi_Impl_LocatorValue* locator_value1;
  const union Mapi_Impl_LocatorValue* locator_value2;

  if (game_address_locator1 == game_address_locator2) {
    return 0;
  }

  compare_library_path = Mdc_Fs_Path_ComparePath(
      &game_address_locator1->library_path,
      &game_address_locator2->library_path
  );

  if (compare_library_path != 0) {
    return compare_library_path;
  }

  locator_type1 = game_address_locator1->locator_type;
  locator_type2 = game_address_locator2->locator_type;

  if (locator_type1 != locator_type2) {
    return locator_type1 - locator_type2;
  }

  locator_value1 = &game_address_locator1->locator_value;
  locator_value2 = &game_address_locator2->locator_value;

  switch (locator_type1) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      return Mdc_BasicString_CompareStr(
          &locator_value1->decorated_name,
          &locator_value2->decorated_name
      );
    }

    case Mapi_Impl_LocatorType_kOffset: {
      if (locator_value1->offset < locator_value2->offset) {
        return -1;
      } else if (locator_value1->offset > locator_value2->offset) {
        return 1;
      } else {
        return 0;
      }
    }

    case Mapi_Impl_LocatorType_kOrdinal: {
      return locator_value1->ordinal - locator_value2->ordinal;
    }

    default: {
      ExitOnConstantMappingMissing(locator_type1, __FILEW__, __LINE__);
      goto return_bad;
    }
  }

return_bad:
  return -1;
}

struct Mapi_GameAddress* Mapi_Impl_GameAddressLocator_LocateGameAddress(
    struct Mapi_GameAddress* game_address,
    const struct Mapi_Impl_GameAddressLocator* game_address_locator
) {
  struct Mapi_GameAddress* init_game_address;

  const wchar_t* library_path_cstr;
  const union Mapi_Impl_LocatorValue* locator_value;

  library_path_cstr = Mdc_Fs_Path_CStr(&game_address_locator->library_path);
  locator_value = &game_address_locator->locator_value;

  switch (game_address_locator->locator_type) {
    case Mapi_Impl_LocatorType_kDecoratedName: {
      init_game_address =
          Mapi_GameAddress_InitFromLibraryPathAndDecoratedName(
              game_address,
              library_path_cstr,
              Mdc_BasicString_DataConst(&locator_value->decorated_name)
          );

      break;
    }

    case Mapi_Impl_LocatorType_kOffset: {
      init_game_address = Mapi_GameAddress_InitFromLibraryPathAndOffset(
          game_address,
          library_path_cstr,
          locator_value->offset
      );

      break;
    }
    case Mapi_Impl_LocatorType_kOrdinal: {
      init_game_address = Mapi_GameAddress_InitFromLibraryPathAndOrdinal(
          game_address,
          library_path_cstr,
          locator_value->ordinal
      );

      break;
    }

    default: {
      ExitOnConstantMappingMissing(
          game_address_locator->locator_type,
          __FILEW__,
          __LINE__
      );

      goto return_bad;
    }
  }

  if (init_game_address != game_address) {
    ExitFormattedOnGeneralFailure(
        L"Error",
        __FILEW__,
        __LINE__,
        L""
    );
    goto return_bad;
  }

  return game_address;

return_bad:
  return NULL;
}

void Mapi_Impl_GameAddressLocator_Swap(
    struct Mapi_Impl_GameAddressLocator* game_address_locator1,
    struct Mapi_Impl_GameAddressLocator* game_address_locator2
) {
  union Mapi_Impl_LocatorValue temp_locator_value;

  int locator_type1;
  int locator_type2;

  Mdc_Fs_Path_Swap(
      &game_address_locator1->library_path,
      &game_address_locator2->library_path
  );

  locator_type1 = game_address_locator1->locator_type;
  locator_type2 = game_address_locator2->locator_type;

  Mdc_Integer_Swap(
      &locator_type1,
      &locator_type2
  );

  game_address_locator1->locator_type = locator_type1;
  game_address_locator2->locator_type = locator_type2;

  temp_locator_value = game_address_locator1->locator_value;
  game_address_locator1->locator_value =
      game_address_locator2->locator_value;
  game_address_locator2->locator_value = temp_locator_value;
}
