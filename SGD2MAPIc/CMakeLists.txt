# SlashGaming Diablo II Modding API for C
# Copyright (C) 2018-2021  Mir Drualga
#
# This file is part of SlashGaming Diablo II Modding API for C.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Additional permissions under GNU Affero General Public License version 3
# section 7
#
# If you modify this Program, or any covered work, by linking or combining
# it with Diablo II (or a modified version of that game and its
# libraries), containing parts covered by the terms of Blizzard End User
# License Agreement, the licensors of this Program grant you additional
# permission to convey the resulting work. This additional permission is
# also extended to any combination of expansions, mods, and remasters of
# the game.
#
# If you modify this Program, or any covered work, by linking or combining
# it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
# Glide, OpenGL, or Rave wrapper (or modified versions of those
# libraries), containing parts not covered by a compatible license, the
# licensors of this Program grant you additional permission to convey the
# resulting work.
#
# If you modify this Program, or any covered work, by linking or combining
# it with any library (or a modified version of that library) that links
# to Diablo II (or a modified version of that game and its libraries),
# containing parts not covered by a compatible license, the licensors of
# this Program grant you additional permission to convey the resulting
# work.

cmake_minimum_required(VERSION 3.10)

project(SGD2MAPIc)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_ASM_NASM_OBJECT_FORMAT win32)
enable_language(ASM_NASM)

if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# Header and source files
set(INCLUDE_HEADERS
    "include/c/file/file_pe_signature.h"
    "include/c/file/file_version_info.h"
    "include/c/file/fixed_file_version.h"

    "include/c/game_constant/d2_client_game_type.h"
    "include/c/game_constant/d2_difficulty_level.h"
    "include/c/game_constant/d2_draw_effect.h"
    "include/c/game_constant/d2_screen_open_mode.h"
    "include/c/game_constant/d2_text_color.h"
    "include/c/game_constant/d2_text_font.h"
    "include/c/game_constant/d2_video_mode.h"

    "include/c/game_function/d2client/d2client_draw_centered_unicode_text.h"
    "include/c/game_function/d2cmp/d2cmp_get_cel_from_cel_context.h"
    "include/c/game_function/d2common/d2common_get_global_belt_record.h"
    "include/c/game_function/d2common/d2common_get_global_belt_slot_position.h"
    "include/c/game_function/d2common/d2common_get_global_equipment_slot_layout.h"
    "include/c/game_function/d2common/d2common_get_global_inventory_grid_layout.h"
    "include/c/game_function/d2common/d2common_get_global_inventory_position.h"
    "include/c/game_function/d2gfx/d2gfx_draw_cel_context.h"
    "include/c/game_function/d2gfx/d2gfx_draw_rectangle.h"
    "include/c/game_function/d2lang/d2lang_get_string_by_index.h"
    "include/c/game_function/d2win/d2win_draw_unicode_text.h"
    "include/c/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.h"
    "include/c/game_function/d2win/d2win_get_unicode_text_draw_width.h"
    "include/c/game_function/d2win/d2win_get_unicode_text_n_draw_width.h"
    "include/c/game_function/d2win/d2win_load_cel_file.h"
    "include/c/game_function/d2win/d2win_load_mpq.h"
    "include/c/game_function/d2win/d2win_set_pop_up_unicode_text.h"
    "include/c/game_function/d2win/d2win_set_unicode_text_font.h"
    "include/c/game_function/d2win/d2win_unload_cel_file.h"
    "include/c/game_function/d2win/d2win_unload_mpq.h"
    "include/c/game_function/fog/fog_alloc_client_memory.h"
    "include/c/game_function/fog/fog_free_client_memory.h"
    "include/c/game_function/storm/storm_s_file_close_archive.h"
    "include/c/game_function/storm/storm_s_file_open_archive.h"

    "include/c/game_function/bnclient_function.h"
    "include/c/game_function/d2client_function.h"
    "include/c/game_function/d2cmp_function.h"
    "include/c/game_function/d2common_function.h"
    "include/c/game_function/d2ddraw_function.h"
    "include/c/game_function/d2direct3d_function.h"
    "include/c/game_function/d2game_function.h"
    "include/c/game_function/d2gdi_function.h"
    "include/c/game_function/d2gfx_function.h"
    "include/c/game_function/d2glide_function.h"
    "include/c/game_function/d2lang_function.h"
    "include/c/game_function/d2launch_function.h"
    "include/c/game_function/d2mcpclient_function.h"
    "include/c/game_function/d2multi_function.h"
    "include/c/game_function/d2net_function.h"
    "include/c/game_function/d2sound_function.h"
    "include/c/game_function/d2win_function.h"
    "include/c/game_function/fog_function.h"
    "include/c/game_function/storm_function.h"

    "include/c/game_struct/d2_belt_record.h"
    "include/c/game_struct/d2_cel.h"
    "include/c/game_struct/d2_cel_context.h"
    "include/c/game_struct/d2_cel_file.h"
    "include/c/game_struct/d2_equipment_layout.h"
    "include/c/game_struct/d2_grid_layout.h"
    "include/c/game_struct/d2_inventory_record.h"
    "include/c/game_struct/d2_mpq_archive.h"
    "include/c/game_struct/d2_mpq_archive_handle.h"
    "include/c/game_struct/d2_positional_rectangle.h"

    "include/c/game_variable/bnclient/bnclient_gateway_domain_name.h"
    "include/c/game_variable/bnclient/bnclient_gateway_ip_v4_address.h"
    "include/c/game_variable/d2client/d2client_difficulty_level.h"
    "include/c/game_variable/d2client/d2client_game_type.h"
    "include/c/game_variable/d2client/d2client_general_display_height.h"
    "include/c/game_variable/d2client/d2client_general_display_width.h"
    "include/c/game_variable/d2client/d2client_general_play_area_camera_shift_x.h"
    "include/c/game_variable/d2client/d2client_ingame_mouse_position_x.h"
    "include/c/game_variable/d2client/d2client_ingame_mouse_position_y.h"
    "include/c/game_variable/d2client/d2client_inventory_arrange_mode.h"
    "include/c/game_variable/d2client/d2client_is_automap_open.h"
    "include/c/game_variable/d2client/d2client_is_game_menu_open.h"
    "include/c/game_variable/d2client/d2client_is_help_screen_open.h"
    "include/c/game_variable/d2client/d2client_is_new_skill_button_pressed.h"
    "include/c/game_variable/d2client/d2client_is_new_stats_button_pressed.h"
    "include/c/game_variable/d2client/d2client_screen_open_mode.h"
    "include/c/game_variable/d2client/d2client_screen_shift_x.h"
    "include/c/game_variable/d2client/d2client_screen_shift_y.h"
    "include/c/game_variable/d2common/d2common_global_belts_txt.h"
    "include/c/game_variable/d2common/d2common_global_inventory_txt.h"
    "include/c/game_variable/d2common/d2common_global_inventory_txt_records_count.h"
    "include/c/game_variable/d2ddraw/d2ddraw_bit_block_height.h"
    "include/c/game_variable/d2ddraw/d2ddraw_bit_block_width.h"
    "include/c/game_variable/d2ddraw/d2ddraw_cel_display_left.h"
    "include/c/game_variable/d2ddraw/d2ddraw_cel_display_right.h"
    "include/c/game_variable/d2ddraw/d2ddraw_display_height.h"
    "include/c/game_variable/d2ddraw/d2ddraw_display_width.h"
    "include/c/game_variable/d2direct3d/d2direct3d_display_height.h"
    "include/c/game_variable/d2direct3d/d2direct3d_display_width.h"
    "include/c/game_variable/d2gdi/d2gdi_bit_block_height.h"
    "include/c/game_variable/d2gdi/d2gdi_bit_block_width.h"
    "include/c/game_variable/d2gdi/d2gdi_cel_display_left.h"
    "include/c/game_variable/d2gdi/d2gdi_cel_display_right.h"
    "include/c/game_variable/d2gfx/d2gfx_is_windowed_mode.h"
    "include/c/game_variable/d2gfx/d2gfx_resolution_mode.h"
    "include/c/game_variable/d2gfx/d2gfx_video_mode.h"
    "include/c/game_variable/d2gfx/d2gfx_window_handle.h"
    "include/c/game_variable/d2glide/d2glide_display_height.h"
    "include/c/game_variable/d2glide/d2glide_display_width.h"
    "include/c/game_variable/d2win/d2win_main_menu_mouse_position_x.h"
    "include/c/game_variable/d2win/d2win_main_menu_mouse_position_y.h"

    "include/c/game_variable/bnclient_variable.h"
    "include/c/game_variable/d2client_variable.h"
    "include/c/game_variable/d2cmp_variable.h"
    "include/c/game_variable/d2common_variable.h"
    "include/c/game_variable/d2ddraw_variable.h"
    "include/c/game_variable/d2direct3d_variable.h"
    "include/c/game_variable/d2game_variable.h"
    "include/c/game_variable/d2gdi_variable.h"
    "include/c/game_variable/d2gfx_variable.h"
    "include/c/game_variable/d2glide_variable.h"
    "include/c/game_variable/d2lang_variable.h"
    "include/c/game_variable/d2launch_variable.h"
    "include/c/game_variable/d2mcpclient_variable.h"
    "include/c/game_variable/d2multi_variable.h"
    "include/c/game_variable/d2net_variable.h"
    "include/c/game_variable/d2sound_variable.h"
    "include/c/game_variable/d2win_variable.h"
    "include/c/game_variable/fog_variable.h"
    "include/c/game_variable/storm_variable.h"

    "include/c/helper/d2_determine_video_mode.h"

    "include/c/default_game_library.h"
    "include/c/file.h"
    "include/c/game_address.h"
    "include/c/game_bool.h"
    "include/c/game_branch_type.h"
    "include/c/game_constant.h"
    "include/c/game_executable.h"
    "include/c/game_function.h"
    "include/c/game_patch.h"
    "include/c/game_struct.h"
    "include/c/game_undefined.h"
    "include/c/game_variable.h"
    "include/c/game_version.h"
    "include/c/helper.h"

    "include/d2api_version.h"
    "include/dllexport_define.inc"
    "include/dllexport_define.inc"
    "include/sgd2mapi.h"
)

set(SRC_ASM
    "src/c/backend/game_function/cdecl_function.asm"
    "src/c/backend/game_function/esi_function.asm"
    "src/c/backend/game_function/fastcall_function.asm"
    "src/c/backend/game_function/stdcall_function.asm"
    "src/c/backend/game_function/thiscall_function.asm"

    "src/c/game_function/d2client/d2client_draw_centered_unicode_text_shim.asm"
    "src/c/game_function/d2win/d2win_load_mpq_shim.asm"
)

set(SRC_C
    "src/c/backend/d2se/d2se_file_pe_signature.c"
    "src/c/backend/d2se/d2se_game_version.c"
    "src/c/backend/d2se/d2se_ini.c"

    "src/c/backend/game_address_table/game_address_table_impl.c"

    "src/c/backend/game_version/game_version_file_pe_signature.c"
    "src/c/backend/game_version/game_version_file_version.c"

    "src/c/backend/architecture_opcode.c"
    "src/c/backend/game_address_table.c"
    "src/c/backend/game_library.cpp"

    "src/c/file/file_pe_signature.c"
    "src/c/file/file_version_info.c"
    "src/c/file/fixed_file_version.c"

    "src/c/game_constant/d2_client_game_type.c"
    "src/c/game_constant/d2_difficulty_level.c"
    "src/c/game_constant/d2_draw_effect.c"
    "src/c/game_constant/d2_screen_open_mode.c"
    "src/c/game_constant/d2_text_color.c"
    "src/c/game_constant/d2_text_font.c"
    "src/c/game_constant/d2_video_mode.c"

    "src/c/game_function/d2client/d2client_draw_centered_unicode_text.c"
    "src/c/game_function/d2cmp/d2cmp_get_cel_from_cel_context.c"
    "src/c/game_function/d2common/d2common_get_global_belt_record.c"
    "src/c/game_function/d2common/d2common_get_global_belt_slot_position.c"
    "src/c/game_function/d2common/d2common_get_global_equipment_slot_layout.c"
    "src/c/game_function/d2common/d2common_get_global_inventory_grid_layout.c"
    "src/c/game_function/d2common/d2common_get_global_inventory_position.c"
    "src/c/game_function/d2gfx/d2gfx_draw_cel_context.c"
    "src/c/game_function/d2gfx/d2gfx_draw_rectangle.c"
    "src/c/game_function/d2lang/d2lang_get_string_by_index.c"
    "src/c/game_function/d2win/d2win_draw_unicode_text.c"
    "src/c/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.c"
    "src/c/game_function/d2win/d2win_get_unicode_text_draw_width.c"
    "src/c/game_function/d2win/d2win_get_unicode_text_n_draw_width.c"
    "src/c/game_function/d2win/d2win_load_cel_file.c"
    "src/c/game_function/d2win/d2win_load_mpq.c"
    "src/c/game_function/d2win/d2win_set_pop_up_unicode_text.c"
    "src/c/game_function/d2win/d2win_set_unicode_text_font.c"
    "src/c/game_function/d2win/d2win_unload_cel_file.c"
    "src/c/game_function/d2win/d2win_unload_mpq.c"
    "src/c/game_function/fog/fog_alloc_client_memory.c"
    "src/c/game_function/fog/fog_free_client_memory.c"
    "src/c/game_function/storm/storm_s_file_close_archive.c"
    "src/c/game_function/storm/storm_s_file_open_archive.c"

    "src/c/game_struct/d2_belt_record.c"
    "src/c/game_struct/d2_cel.c"
    "src/c/game_struct/d2_cel_context.c"
    "src/c/game_struct/d2_cel_file.c"
    "src/c/game_struct/d2_equipment_layout.c"
    "src/c/game_struct/d2_grid_layout.c"
    "src/c/game_struct/d2_inventory_record.c"
    "src/c/game_struct/d2_mpq_archive.c"
    "src/c/game_struct/d2_mpq_archive_handle.c"
    "src/c/game_struct/d2_positional_rectangle.c"

    "src/c/game_variable/bnclient/bnclient_gateway_domain_name.c"
    "src/c/game_variable/bnclient/bnclient_gateway_ip_v4_address.c"
    "src/c/game_variable/d2client/d2client_difficulty_level.c"
    "src/c/game_variable/d2client/d2client_game_type.c"
    "src/c/game_variable/d2client/d2client_general_display_height.c"
    "src/c/game_variable/d2client/d2client_general_display_width.c"
    "src/c/game_variable/d2client/d2client_general_play_area_camera_shift_x.c"
    "src/c/game_variable/d2client/d2client_ingame_mouse_position_x.c"
    "src/c/game_variable/d2client/d2client_ingame_mouse_position_y.c"
    "src/c/game_variable/d2client/d2client_inventory_arrange_mode.c"
    "src/c/game_variable/d2client/d2client_is_automap_open.c"
    "src/c/game_variable/d2client/d2client_is_game_menu_open.c"
    "src/c/game_variable/d2client/d2client_is_help_screen_open.c"
    "src/c/game_variable/d2client/d2client_is_new_skill_button_pressed.c"
    "src/c/game_variable/d2client/d2client_is_new_stats_button_pressed.c"
    "src/c/game_variable/d2client/d2client_screen_open_mode.c"
    "src/c/game_variable/d2client/d2client_screen_shift_x.c"
    "src/c/game_variable/d2client/d2client_screen_shift_y.c"
    "src/c/game_variable/d2common/d2common_global_belts_txt.c"
    "src/c/game_variable/d2common/d2common_global_inventory_txt.c"
    "src/c/game_variable/d2common/d2common_global_inventory_txt_records_count.c"
    "src/c/game_variable/d2ddraw/d2ddraw_bit_block_height.c"
    "src/c/game_variable/d2ddraw/d2ddraw_bit_block_width.c"
    "src/c/game_variable/d2ddraw/d2ddraw_cel_display_left.c"
    "src/c/game_variable/d2ddraw/d2ddraw_cel_display_right.c"
    "src/c/game_variable/d2ddraw/d2ddraw_display_height.c"
    "src/c/game_variable/d2ddraw/d2ddraw_display_width.c"
    "src/c/game_variable/d2direct3d/d2direct3d_display_height.c"
    "src/c/game_variable/d2direct3d/d2direct3d_display_width.c"
    "src/c/game_variable/d2gdi/d2gdi_bit_block_height.c"
    "src/c/game_variable/d2gdi/d2gdi_bit_block_width.c"
    "src/c/game_variable/d2gdi/d2gdi_cel_display_left.c"
    "src/c/game_variable/d2gdi/d2gdi_cel_display_right.c"
    "src/c/game_variable/d2gfx/d2gfx_is_windowed_mode.c"
    "src/c/game_variable/d2gfx/d2gfx_resolution_mode.c"
    "src/c/game_variable/d2gfx/d2gfx_video_mode.c"
    "src/c/game_variable/d2gfx/d2gfx_window_handle.c"
    "src/c/game_variable/d2glide/d2glide_display_height.c"
    "src/c/game_variable/d2glide/d2glide_display_width.c"
    "src/c/game_variable/d2win/d2win_main_menu_mouse_position_x.c"
    "src/c/game_variable/d2win/d2win_main_menu_mouse_position_y.c"

    "src/c/helper/d2_determine_video_mode.c"

    "src/c/default_game_library.c"
    "src/c/game_address.c"
    "src/c/game_executable.c"
    "src/c/game_patch.c"
    "src/c/game_version.c"

    "src/dll_main.c"
)

set(SRC_HEADERS
    "src/c/backend/d2se/d2se_file_pe_signature.h"
    "src/c/backend/d2se/d2se_game_version.h"
    "src/c/backend/d2se/d2se_ini.h"

    "src/c/backend/game_address_table/game_address_table_define.h"
    "src/c/backend/game_address_table/game_address_table_impl.h"

    "src/c/backend/game_function/cdecl_function.h"
    "src/c/backend/game_function/esi_function.h"
    "src/c/backend/game_function/fastcall_function.h"
    "src/c/backend/game_function/stdcall_function.h"
    "src/c/backend/game_function/thiscall_function.h"

    "src/c/backend/game_version/game_version_file_pe_signature.h"
    "src/c/backend/game_version/game_version_file_version.h"

    "src/c/backend/architecture_opcode.h"
    "src/c/backend/game_address_table.h"
    "src/c/backend/game_library.h"
)

# Output static LIB
add_library(libSGD2MAPIc STATIC ${SRC_ASM} ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_include_directories(libSGD2MAPIc PUBLIC "include")

target_link_libraries(libSGD2MAPIc PUBLIC libMDCc shlwapi version)
add_dependencies(libSGD2MAPIc libMDCc)

# Output DLL
add_library(SGD2MAPIc SHARED ${SRC_ASM} ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_compile_definitions(SGD2MAPIc PRIVATE SGD2MAPIC_DLLEXPORT)
target_compile_definitions(SGD2MAPIc INTERFACE SGD2MAPIC_DLLIMPORT)

target_include_directories(SGD2MAPIc PUBLIC "include")

target_link_libraries(SGD2MAPIc PUBLIC libMDCc shlwapi version)
add_dependencies(SGD2MAPIc libMDCc)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        ${SRC_ASM}
        ${SRC_C}
        ${SRC_HEADERS}
        ${INCLUDE_HEADERS}
)

install(TARGETS SGD2MAPIc libSGD2MAPIc)
