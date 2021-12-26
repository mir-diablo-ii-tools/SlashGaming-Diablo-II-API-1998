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

cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project(SGD2MAPIc)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define requirements for C++
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable NASM
set(CMAKE_ASM_NASM_OBJECT_FORMAT win32)
enable_language(ASM_NASM)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# List all of the source files here
set(INCLUDE_HEADERS
    "include/sgd2mapi98/file/file_pe_signature.h"
    "include/sgd2mapi98/file/file_version_info.h"
    "include/sgd2mapi98/file/fixed_file_version.h"

    "include/sgd2mapi98/game_constant/d2_client_game_type.h"
    "include/sgd2mapi98/game_constant/d2_difficulty_level.h"
    "include/sgd2mapi98/game_constant/d2_draw_effect.h"
    "include/sgd2mapi98/game_constant/d2_screen_open_mode.h"
    "include/sgd2mapi98/game_constant/d2_text_color.h"
    "include/sgd2mapi98/game_constant/d2_text_font.h"
    "include/sgd2mapi98/game_constant/d2_video_mode.h"

    "include/sgd2mapi98/game_function/d2client/d2client_draw_centered_unicode_text.h"
    "include/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.h"
    "include/sgd2mapi98/game_function/d2common/d2common_get_global_belt_record.h"
    "include/sgd2mapi98/game_function/d2common/d2common_get_global_belt_slot_position.h"
    "include/sgd2mapi98/game_function/d2common/d2common_get_global_equipment_slot_layout.h"
    "include/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_grid_layout.h"
    "include/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_position.h"
    "include/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.h"
    "include/sgd2mapi98/game_function/d2gfx/d2gfx_draw_rectangle.h"
    "include/sgd2mapi98/game_function/d2lang/d2lang_get_string_by_index.h"
    "include/sgd2mapi98/game_function/d2win/d2win_draw_unicode_text.h"
    "include/sgd2mapi98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.h"
    "include/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_draw_width.h"
    "include/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_n_draw_width.h"
    "include/sgd2mapi98/game_function/d2win/d2win_load_cel_file.h"
    "include/sgd2mapi98/game_function/d2win/d2win_load_mpq.h"
    "include/sgd2mapi98/game_function/d2win/d2win_set_pop_up_unicode_text.h"
    "include/sgd2mapi98/game_function/d2win/d2win_set_unicode_text_font.h"
    "include/sgd2mapi98/game_function/d2win/d2win_unload_cel_file.h"
    "include/sgd2mapi98/game_function/d2win/d2win_unload_mpq.h"
    "include/sgd2mapi98/game_function/fog/fog_alloc_client_memory.h"
    "include/sgd2mapi98/game_function/fog/fog_free_client_memory.h"
    "include/sgd2mapi98/game_function/storm/storm_s_file_close_archive.h"
    "include/sgd2mapi98/game_function/storm/storm_s_file_open_archive.h"

    "include/sgd2mapi98/game_function/bnclient_function.h"
    "include/sgd2mapi98/game_function/d2client_function.h"
    "include/sgd2mapi98/game_function/d2cmp_function.h"
    "include/sgd2mapi98/game_function/d2common_function.h"
    "include/sgd2mapi98/game_function/d2ddraw_function.h"
    "include/sgd2mapi98/game_function/d2direct3d_function.h"
    "include/sgd2mapi98/game_function/d2game_function.h"
    "include/sgd2mapi98/game_function/d2gdi_function.h"
    "include/sgd2mapi98/game_function/d2gfx_function.h"
    "include/sgd2mapi98/game_function/d2glide_function.h"
    "include/sgd2mapi98/game_function/d2lang_function.h"
    "include/sgd2mapi98/game_function/d2launch_function.h"
    "include/sgd2mapi98/game_function/d2mcpclient_function.h"
    "include/sgd2mapi98/game_function/d2multi_function.h"
    "include/sgd2mapi98/game_function/d2net_function.h"
    "include/sgd2mapi98/game_function/d2sound_function.h"
    "include/sgd2mapi98/game_function/d2win_function.h"
    "include/sgd2mapi98/game_function/fog_function.h"
    "include/sgd2mapi98/game_function/storm_function.h"

    "include/sgd2mapi98/game_struct/d2_belt_record.h"
    "include/sgd2mapi98/game_struct/d2_cel.h"
    "include/sgd2mapi98/game_struct/d2_cel_context.h"
    "include/sgd2mapi98/game_struct/d2_cel_file.h"
    "include/sgd2mapi98/game_struct/d2_equipment_layout.h"
    "include/sgd2mapi98/game_struct/d2_grid_layout.h"
    "include/sgd2mapi98/game_struct/d2_inventory_record.h"
    "include/sgd2mapi98/game_struct/d2_mpq_archive.h"
    "include/sgd2mapi98/game_struct/d2_mpq_archive_handle.h"
    "include/sgd2mapi98/game_struct/d2_positional_rectangle.h"

    "include/sgd2mapi98/game_variable/bnclient/bnclient_gateway_domain_name.h"
    "include/sgd2mapi98/game_variable/bnclient/bnclient_gateway_ip_v4_address.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_difficulty_level.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_game_type.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_general_display_height.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_general_display_width.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_general_play_area_camera_shift_x.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_x.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_y.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_inventory_arrange_mode.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_is_automap_open.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_is_game_menu_open.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_is_help_screen_open.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_is_new_skill_button_pressed.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_is_new_stats_button_pressed.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_screen_open_mode.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_screen_shift_x.h"
    "include/sgd2mapi98/game_variable/d2client/d2client_screen_shift_y.h"
    "include/sgd2mapi98/game_variable/d2common/d2common_global_belts_txt.h"
    "include/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt.h"
    "include/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt_records_count.h"
    "include/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_height.h"
    "include/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_width.h"
    "include/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_left.h"
    "include/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_right.h"
    "include/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_height.h"
    "include/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_width.h"
    "include/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_height.h"
    "include/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_width.h"
    "include/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_height.h"
    "include/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_width.h"
    "include/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_left.h"
    "include/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_right.h"
    "include/sgd2mapi98/game_variable/d2gfx/d2gfx_is_windowed_mode.h"
    "include/sgd2mapi98/game_variable/d2gfx/d2gfx_resolution_mode.h"
    "include/sgd2mapi98/game_variable/d2gfx/d2gfx_video_mode.h"
    "include/sgd2mapi98/game_variable/d2gfx/d2gfx_window_handle.h"
    "include/sgd2mapi98/game_variable/d2glide/d2glide_display_height.h"
    "include/sgd2mapi98/game_variable/d2glide/d2glide_display_width.h"
    "include/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_x.h"
    "include/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_y.h"

    "include/sgd2mapi98/game_variable/bnclient_variable.h"
    "include/sgd2mapi98/game_variable/d2client_variable.h"
    "include/sgd2mapi98/game_variable/d2cmp_variable.h"
    "include/sgd2mapi98/game_variable/d2common_variable.h"
    "include/sgd2mapi98/game_variable/d2ddraw_variable.h"
    "include/sgd2mapi98/game_variable/d2direct3d_variable.h"
    "include/sgd2mapi98/game_variable/d2game_variable.h"
    "include/sgd2mapi98/game_variable/d2gdi_variable.h"
    "include/sgd2mapi98/game_variable/d2gfx_variable.h"
    "include/sgd2mapi98/game_variable/d2glide_variable.h"
    "include/sgd2mapi98/game_variable/d2lang_variable.h"
    "include/sgd2mapi98/game_variable/d2launch_variable.h"
    "include/sgd2mapi98/game_variable/d2mcpclient_variable.h"
    "include/sgd2mapi98/game_variable/d2multi_variable.h"
    "include/sgd2mapi98/game_variable/d2net_variable.h"
    "include/sgd2mapi98/game_variable/d2sound_variable.h"
    "include/sgd2mapi98/game_variable/d2win_variable.h"
    "include/sgd2mapi98/game_variable/fog_variable.h"
    "include/sgd2mapi98/game_variable/storm_variable.h"

    "include/sgd2mapi98/helper/d2_determine_video_mode.h"

    "include/sgd2mapi98/default_game_library.h"
    "include/sgd2mapi98/file.h"
    "include/sgd2mapi98/game_address.h"
    "include/sgd2mapi98/game_bool.h"
    "include/sgd2mapi98/game_branch_type.h"
    "include/sgd2mapi98/game_constant.h"
    "include/sgd2mapi98/game_executable.h"
    "include/sgd2mapi98/game_function.h"
    "include/sgd2mapi98/game_patch.h"
    "include/sgd2mapi98/game_struct.h"
    "include/sgd2mapi98/game_undefined.h"
    "include/sgd2mapi98/game_variable.h"
    "include/sgd2mapi98/game_version.h"
    "include/sgd2mapi98/helper.h"

    "include/d2api_version.h"
    "include/dllexport_define.inc"
    "include/dllexport_define.inc"
    "include/sgd2mapi98.h"
)

set(SRC_ASM
    "src/sgd2mapi98/backend/game_function/cdecl_function.asm"
    "src/sgd2mapi98/backend/game_function/esi_function.asm"
    "src/sgd2mapi98/backend/game_function/fastcall_function.asm"
    "src/sgd2mapi98/backend/game_function/stdcall_function.asm"
    "src/sgd2mapi98/backend/game_function/thiscall_function.asm"

    "src/sgd2mapi98/game_function/d2client/d2client_draw_centered_unicode_text_shim.asm"
    "src/sgd2mapi98/game_function/d2win/d2win_load_mpq_shim.asm"
)

set(SRC_C
    "src/sgd2mapi98/backend/d2se/d2se_file_pe_signature.c"
    "src/sgd2mapi98/backend/d2se/d2se_game_version.c"
    "src/sgd2mapi98/backend/d2se/d2se_ini.c"

    "src/sgd2mapi98/backend/game_address_table/game_address_table_impl.c"

    "src/sgd2mapi98/backend/game_version/game_version_file_pe_signature.c"
    "src/sgd2mapi98/backend/game_version/game_version_file_version.c"

    "src/sgd2mapi98/backend/architecture_opcode.c"
    "src/sgd2mapi98/backend/game_address_table.c"
    "src/sgd2mapi98/backend/game_library.cpp"

    "src/sgd2mapi98/file/file_pe_signature.c"
    "src/sgd2mapi98/file/file_version_info.c"
    "src/sgd2mapi98/file/fixed_file_version.c"

    "src/sgd2mapi98/game_constant/d2_client_game_type.c"
    "src/sgd2mapi98/game_constant/d2_difficulty_level.c"
    "src/sgd2mapi98/game_constant/d2_draw_effect.c"
    "src/sgd2mapi98/game_constant/d2_screen_open_mode.c"
    "src/sgd2mapi98/game_constant/d2_text_color.c"
    "src/sgd2mapi98/game_constant/d2_text_font.c"
    "src/sgd2mapi98/game_constant/d2_video_mode.c"

    "src/sgd2mapi98/game_function/d2client/d2client_draw_centered_unicode_text.c"
    "src/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.c"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_record.c"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_slot_position.c"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_equipment_slot_layout.c"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_grid_layout.c"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_position.c"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.c"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_rectangle.c"
    "src/sgd2mapi98/game_function/d2lang/d2lang_get_string_by_index.c"
    "src/sgd2mapi98/game_function/d2win/d2win_draw_unicode_text.c"
    "src/sgd2mapi98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.c"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_draw_width.c"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_n_draw_width.c"
    "src/sgd2mapi98/game_function/d2win/d2win_load_cel_file.c"
    "src/sgd2mapi98/game_function/d2win/d2win_load_mpq.c"
    "src/sgd2mapi98/game_function/d2win/d2win_set_pop_up_unicode_text.c"
    "src/sgd2mapi98/game_function/d2win/d2win_set_unicode_text_font.c"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_cel_file.c"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_mpq.c"
    "src/sgd2mapi98/game_function/fog/fog_alloc_client_memory.c"
    "src/sgd2mapi98/game_function/fog/fog_free_client_memory.c"
    "src/sgd2mapi98/game_function/storm/storm_s_file_close_archive.c"
    "src/sgd2mapi98/game_function/storm/storm_s_file_open_archive.c"

    "src/sgd2mapi98/game_struct/d2_belt_record.c"
    "src/sgd2mapi98/game_struct/d2_cel.c"
    "src/sgd2mapi98/game_struct/d2_cel_context.c"
    "src/sgd2mapi98/game_struct/d2_cel_file.c"
    "src/sgd2mapi98/game_struct/d2_equipment_layout.c"
    "src/sgd2mapi98/game_struct/d2_grid_layout.c"
    "src/sgd2mapi98/game_struct/d2_inventory_record.c"
    "src/sgd2mapi98/game_struct/d2_mpq_archive.c"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle.c"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle.c"

    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_domain_name.c"
    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_ip_v4_address.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_difficulty_level.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_game_type.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_height.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_width.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_play_area_camera_shift_x.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_x.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_y.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_inventory_arrange_mode.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_automap_open.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_game_menu_open.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_help_screen_open.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_skill_button_pressed.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_stats_button_pressed.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_open_mode.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_x.c"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_y.c"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_belts_txt.c"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt.c"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt_records_count.c"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_height.c"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_width.c"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_left.c"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_right.c"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_height.c"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_width.c"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_height.c"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_width.c"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_height.c"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_width.c"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_left.c"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_right.c"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_is_windowed_mode.c"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_resolution_mode.c"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_video_mode.c"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_window_handle.c"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_height.c"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_width.c"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_x.c"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_y.c"

    "src/sgd2mapi98/helper/d2_determine_video_mode.c"

    "src/sgd2mapi98/default_game_library.c"
    "src/sgd2mapi98/game_address.c"
    "src/sgd2mapi98/game_executable.c"
    "src/sgd2mapi98/game_patch.c"
    "src/sgd2mapi98/game_version.c"

    "src/dll_main.c"
)

set(SRC_HEADERS
    "src/sgd2mapi98/backend/d2se/d2se_file_pe_signature.h"
    "src/sgd2mapi98/backend/d2se/d2se_game_version.h"
    "src/sgd2mapi98/backend/d2se/d2se_ini.h"

    "src/sgd2mapi98/backend/game_address_table/game_address_table_define.h"
    "src/sgd2mapi98/backend/game_address_table/game_address_table_impl.h"

    "src/sgd2mapi98/backend/game_function/cdecl_function.h"
    "src/sgd2mapi98/backend/game_function/esi_function.h"
    "src/sgd2mapi98/backend/game_function/fastcall_function.h"
    "src/sgd2mapi98/backend/game_function/stdcall_function.h"
    "src/sgd2mapi98/backend/game_function/thiscall_function.h"

    "src/sgd2mapi98/backend/game_version/game_version_file_pe_signature.h"
    "src/sgd2mapi98/backend/game_version/game_version_file_version.h"

    "src/sgd2mapi98/backend/architecture_opcode.h"
    "src/sgd2mapi98/backend/game_address_table.h"
    "src/sgd2mapi98/backend/game_library.h"
)

set(SOURCE_FILES
    ${SRC_ASM}
    ${SRC_C}
    ${SRC_HEADERS}
    ${INCLUDE_HEADERS}
)

# Output static LIB
add_library(lib${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(lib${PROJECT_NAME} PUBLIC "include")

target_link_libraries(lib${PROJECT_NAME} PUBLIC libMDCc shlwapi version)
add_dependencies(lib${PROJECT_NAME} libMDCc)

# Output DLL
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME} PRIVATE SGD2MAPIC_DLLEXPORT)
target_compile_definitions(${PROJECT_NAME} INTERFACE SGD2MAPIC_DLLIMPORT)

target_include_directories(${PROJECT_NAME} PUBLIC "include")

target_link_libraries(${PROJECT_NAME} PUBLIC MDCc shlwapi version)
add_dependencies(${PROJECT_NAME} MDCc)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} lib${PROJECT_NAME})
