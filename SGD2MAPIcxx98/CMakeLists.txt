# SlashGaming Diablo II Modding API for C++98
# Copyright (C) 2018-2021  Mir Drualga
#
# This file is part of SlashGaming Diablo II Modding API for C++98.
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

project(SGD2MAPIcxx98)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Header and source files
set(INCLUDE_HEADERS
    "include/cxx98/file/file_pe_signature.hpp"
    "include/cxx98/file/file_version_info.hpp"
    "include/cxx98/file/fixed_file_version.hpp"

    "include/cxx98/game_constant/d2_client_game_type.hpp"
    "include/cxx98/game_constant/d2_difficulty_level.hpp"
    "include/cxx98/game_constant/d2_draw_effect.hpp"
    "include/cxx98/game_constant/d2_screen_open_mode.hpp"
    "include/cxx98/game_constant/d2_text_color.hpp"
    "include/cxx98/game_constant/d2_text_font.hpp"
    "include/cxx98/game_constant/d2_video_mode.hpp"

    "include/cxx98/game_function/d2client/d2client_draw_centered_unicode_text.hpp"
    "include/cxx98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.hpp"
    "include/cxx98/game_function/d2common/d2common_get_global_belt_record.hpp"
    "include/cxx98/game_function/d2common/d2common_get_global_belt_slot_position.hpp"
    "include/cxx98/game_function/d2common/d2common_get_global_equipment_slot_layout.hpp"
    "include/cxx98/game_function/d2common/d2common_get_global_inventory_grid_layout.hpp"
    "include/cxx98/game_function/d2common/d2common_get_global_inventory_position.hpp"
    "include/cxx98/game_function/d2gfx/d2gfx_draw_cel_context.hpp"
    "include/cxx98/game_function/d2gfx/d2gfx_draw_rectangle.hpp"
    "include/cxx98/game_function/d2lang/d2lang_get_string_by_index.hpp"
    "include/cxx98/game_function/d2win/d2win_draw_unicode_text.hpp"
    "include/cxx98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.hpp"
    "include/cxx98/game_function/d2win/d2win_get_unicode_text_draw_width.hpp"
    "include/cxx98/game_function/d2win/d2win_get_unicode_text_n_draw_width.hpp"
    "include/cxx98/game_function/d2win/d2win_load_cel_file.hpp"
    "include/cxx98/game_function/d2win/d2win_load_mpq.hpp"
    "include/cxx98/game_function/d2win/d2win_set_pop_up_unicode_text.hpp"
    "include/cxx98/game_function/d2win/d2win_set_text_font.hpp"
    "include/cxx98/game_function/d2win/d2win_unload_cel_file.hpp"
    "include/cxx98/game_function/d2win/d2win_unload_mpq.hpp"
    "include/cxx98/game_function/fog/fog_alloc_client_memory.hpp"
    "include/cxx98/game_function/fog/fog_free_client_memory.hpp"
    "include/cxx98/game_function/storm/storm_s_file_close_archive.hpp"
    "include/cxx98/game_function/storm/storm_s_file_open_archive.hpp"

    "include/cxx98/game_function/bnclient_function.hpp"
    "include/cxx98/game_function/d2client_function.hpp"
    "include/cxx98/game_function/d2cmp_function.hpp"
    "include/cxx98/game_function/d2common_function.hpp"
    "include/cxx98/game_function/d2ddraw_function.hpp"
    "include/cxx98/game_function/d2direct3d_function.hpp"
    "include/cxx98/game_function/d2game_function.hpp"
    "include/cxx98/game_function/d2gdi_function.hpp"
    "include/cxx98/game_function/d2gfx_function.hpp"
    "include/cxx98/game_function/d2glide_function.hpp"
    "include/cxx98/game_function/d2lang_function.hpp"
    "include/cxx98/game_function/d2launch_function.hpp"
    "include/cxx98/game_function/d2mcpclient_function.hpp"
    "include/cxx98/game_function/d2multi_function.hpp"
    "include/cxx98/game_function/d2net_function.hpp"
    "include/cxx98/game_function/d2sound_function.hpp"
    "include/cxx98/game_function/d2win_function.hpp"
    "include/cxx98/game_function/fog_function.hpp"
    "include/cxx98/game_function/storm_function.hpp"

    "include/cxx98/game_struct/d2_belt_record/d2_belt_record_api.hpp"
    "include/cxx98/game_struct/d2_belt_record/d2_belt_record_struct.hpp"
    "include/cxx98/game_struct/d2_belt_record/d2_belt_record_view.hpp"
    "include/cxx98/game_struct/d2_belt_record/d2_belt_record_wrapper.hpp"
    "include/cxx98/game_struct/d2_cel/d2_cel_struct.hpp"
    "include/cxx98/game_struct/d2_cel/d2_cel_view.hpp"
    "include/cxx98/game_struct/d2_cel/d2_cel_wrapper.hpp"
    "include/cxx98/game_struct/d2_cel_context/d2_cel_context_api.hpp"
    "include/cxx98/game_struct/d2_cel_context/d2_cel_context_struct.hpp"
    "include/cxx98/game_struct/d2_cel_context/d2_cel_context_view.hpp"
    "include/cxx98/game_struct/d2_cel_context/d2_cel_context_wrapper.hpp"
    "include/cxx98/game_struct/d2_cel_file/d2_cel_file_api.hpp"
    "include/cxx98/game_struct/d2_cel_file/d2_cel_file_struct.hpp"
    "include/cxx98/game_struct/d2_cel_file/d2_cel_file_view.hpp"
    "include/cxx98/game_struct/d2_cel_file/d2_cel_file_wrapper.hpp"
    "include/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_api.hpp"
    "include/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_struct.hpp"
    "include/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_view.hpp"
    "include/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"
    "include/cxx98/game_struct/d2_grid_layout/d2_grid_layout_api.hpp"
    "include/cxx98/game_struct/d2_grid_layout/d2_grid_layout_struct.hpp"
    "include/cxx98/game_struct/d2_grid_layout/d2_grid_layout_view.hpp"
    "include/cxx98/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"
    "include/cxx98/game_struct/d2_inventory_record/d2_inventory_record_api.hpp"
    "include/cxx98/game_struct/d2_inventory_record/d2_inventory_record_struct.hpp"
    "include/cxx98/game_struct/d2_inventory_record/d2_inventory_record_view.hpp"
    "include/cxx98/game_struct/d2_inventory_record/d2_inventory_record_wrapper.hpp"
    "include/cxx98/game_struct/d2_mpq_archive/d2_mpq_archive_struct.hpp"
    "include/cxx98/game_struct/d2_mpq_archive/d2_mpq_archive_view.hpp"
    "include/cxx98/game_struct/d2_mpq_archive/d2_mpq_archive_wrapper.hpp"
    "include/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.hpp"
    "include/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_struct.hpp"
    "include/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_view.hpp"
    "include/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.hpp"
    "include/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.hpp"
    "include/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_struct.hpp"
    "include/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_view.hpp"
    "include/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"

    "include/cxx98/game_struct/d2_belt_record.hpp"
    "include/cxx98/game_struct/d2_cel.hpp"
    "include/cxx98/game_struct/d2_cel_context.hpp"
    "include/cxx98/game_struct/d2_cel_file.hpp"
    "include/cxx98/game_struct/d2_equipment_layout.hpp"
    "include/cxx98/game_struct/d2_grid_layout.hpp"
    "include/cxx98/game_struct/d2_inventory_record.hpp"
    "include/cxx98/game_struct/d2_mpq_archive.hpp"
    "include/cxx98/game_struct/d2_mpq_archive_handle.hpp"
    "include/cxx98/game_struct/d2_positional_rectangle.hpp"

    "include/cxx98/game_variable/bnclient/bnclient_gateway_domain_name.hpp"
    "include/cxx98/game_variable/bnclient/bnclient_gateway_ip_v4_address.hpp"
    "include/cxx98/game_variable/d2client/d2client_difficulty_level.hpp"
    "include/cxx98/game_variable/d2client/d2client_game_type.hpp"
    "include/cxx98/game_variable/d2client/d2client_general_display_height.hpp"
    "include/cxx98/game_variable/d2client/d2client_general_display_width.hpp"
    "include/cxx98/game_variable/d2client/d2client_general_play_area_camera_shift_x.hpp"
    "include/cxx98/game_variable/d2client/d2client_ingame_mouse_position_x.hpp"
    "include/cxx98/game_variable/d2client/d2client_ingame_mouse_position_y.hpp"
    "include/cxx98/game_variable/d2client/d2client_inventory_arrange_mode.hpp"
    "include/cxx98/game_variable/d2client/d2client_is_automap_open.hpp"
    "include/cxx98/game_variable/d2client/d2client_is_game_menu_open.hpp"
    "include/cxx98/game_variable/d2client/d2client_is_help_screen_open.hpp"
    "include/cxx98/game_variable/d2client/d2client_is_new_skill_button_pressed.hpp"
    "include/cxx98/game_variable/d2client/d2client_is_new_stats_button_pressed.hpp"
    "include/cxx98/game_variable/d2client/d2client_screen_open_mode.hpp"
    "include/cxx98/game_variable/d2client/d2client_screen_shift_x.hpp"
    "include/cxx98/game_variable/d2client/d2client_screen_shift_y.hpp"
    "include/cxx98/game_variable/d2common/d2common_global_belts_txt.hpp"
    "include/cxx98/game_variable/d2common/d2common_global_inventory_txt.hpp"
    "include/cxx98/game_variable/d2common/d2common_global_inventory_txt_records_count.hpp"
    "include/cxx98/game_variable/d2ddraw/d2ddraw_bit_block_height.hpp"
    "include/cxx98/game_variable/d2ddraw/d2ddraw_bit_block_width.hpp"
    "include/cxx98/game_variable/d2ddraw/d2ddraw_cel_display_left.hpp"
    "include/cxx98/game_variable/d2ddraw/d2ddraw_cel_display_right.hpp"
    "include/cxx98/game_variable/d2ddraw/d2ddraw_display_height.hpp"
    "include/cxx98/game_variable/d2ddraw/d2ddraw_display_width.hpp"
    "include/cxx98/game_variable/d2direct3d/d2direct3d_display_height.hpp"
    "include/cxx98/game_variable/d2direct3d/d2direct3d_display_width.hpp"
    "include/cxx98/game_variable/d2gdi/d2gdi_bit_block_height.hpp"
    "include/cxx98/game_variable/d2gdi/d2gdi_bit_block_width.hpp"
    "include/cxx98/game_variable/d2gdi/d2gdi_cel_display_left.hpp"
    "include/cxx98/game_variable/d2gdi/d2gdi_cel_display_right.hpp"
    "include/cxx98/game_variable/d2gfx/d2gfx_is_windowed_mode.hpp"
    "include/cxx98/game_variable/d2gfx/d2gfx_resolution_mode.hpp"
    "include/cxx98/game_variable/d2gfx/d2gfx_video_mode.hpp"
    "include/cxx98/game_variable/d2gfx/d2gfx_window_handle.hpp"
    "include/cxx98/game_variable/d2glide/d2glide_display_height.hpp"
    "include/cxx98/game_variable/d2glide/d2glide_display_width.hpp"
    "include/cxx98/game_variable/d2win/d2win_main_menu_mouse_position_x.hpp"
    "include/cxx98/game_variable/d2win/d2win_main_menu_mouse_position_y.hpp"

    "include/cxx98/game_variable/bnclient_variable.hpp"
    "include/cxx98/game_variable/d2client_variable.hpp"
    "include/cxx98/game_variable/d2cmp_variable.hpp"
    "include/cxx98/game_variable/d2common_variable.hpp"
    "include/cxx98/game_variable/d2ddraw_variable.hpp"
    "include/cxx98/game_variable/d2direct3d_variable.hpp"
    "include/cxx98/game_variable/d2game_variable.hpp"
    "include/cxx98/game_variable/d2gdi_variable.hpp"
    "include/cxx98/game_variable/d2gfx_variable.hpp"
    "include/cxx98/game_variable/d2glide_variable.hpp"
    "include/cxx98/game_variable/d2lang_variable.hpp"
    "include/cxx98/game_variable/d2launch_variable.hpp"
    "include/cxx98/game_variable/d2mcpclient_variable.hpp"
    "include/cxx98/game_variable/d2multi_variable.hpp"
    "include/cxx98/game_variable/d2net_variable.hpp"
    "include/cxx98/game_variable/d2sound_variable.hpp"
    "include/cxx98/game_variable/d2win_variable.hpp"
    "include/cxx98/game_variable/fog_variable.hpp"
    "include/cxx98/game_variable/storm_variable.hpp"

    "include/cxx98/helper/d2_determine_video_mode.hpp"

    "include/cxx98/default_game_library.hpp"
    "include/cxx98/file.hpp"
    "include/cxx98/game_address.hpp"
    "include/cxx98/game_bool.hpp"
    "include/cxx98/game_branch_type.hpp"
    "include/cxx98/game_constant.hpp"
    "include/cxx98/game_executable.hpp"
    "include/cxx98/game_function.hpp"
    "include/cxx98/game_patch.hpp"
    "include/cxx98/game_struct.hpp"
    "include/cxx98/game_undefined.hpp"
    "include/cxx98/game_variable.hpp"
    "include/cxx98/game_version.hpp"
    "include/cxx98/helper.hpp"

    "include/dllexport_define.inc"
    "include/dllexport_define.inc"

    "include/sgd2mapi.hpp"
)

set(SRC_C
    "src/cxx98/file/file_pe_signature.cpp"
    "src/cxx98/file/file_version_info.cpp"
    "src/cxx98/file/fixed_file_version.cpp"

    "src/cxx98/game_constant/d2_client_game_type.cpp"
    "src/cxx98/game_constant/d2_difficulty_level.cpp"
    "src/cxx98/game_constant/d2_draw_effect.cpp"
    "src/cxx98/game_constant/d2_screen_open_mode.cpp"
    "src/cxx98/game_constant/d2_text_color.cpp"
    "src/cxx98/game_constant/d2_text_font.cpp"
    "src/cxx98/game_constant/d2_video_mode.cpp"

    "src/cxx98/game_function/d2client/d2client_draw_centered_unicode_text.cpp"
    "src/cxx98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.cpp"
    "src/cxx98/game_function/d2common/d2common_get_global_belt_record.cpp"
    "src/cxx98/game_function/d2common/d2common_get_global_belt_slot_position.cpp"
    "src/cxx98/game_function/d2common/d2common_get_global_equipment_slot_layout.cpp"
    "src/cxx98/game_function/d2common/d2common_get_global_inventory_grid_layout.cpp"
    "src/cxx98/game_function/d2common/d2common_get_global_inventory_position.cpp"
    "src/cxx98/game_function/d2gfx/d2gfx_draw_cel_context.cpp"
    "src/cxx98/game_function/d2gfx/d2gfx_draw_rectangle.cpp"
    "src/cxx98/game_function/d2lang/d2lang_get_string_by_index.cpp"
    "src/cxx98/game_function/d2win/d2win_draw_unicode_text.cpp"
    "src/cxx98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.cpp"
    "src/cxx98/game_function/d2win/d2win_get_unicode_text_draw_width.cpp"
    "src/cxx98/game_function/d2win/d2win_get_unicode_text_n_draw_width.cpp"
    "src/cxx98/game_function/d2win/d2win_load_cel_file.cpp"
    "src/cxx98/game_function/d2win/d2win_load_mpq.cpp"
    "src/cxx98/game_function/d2win/d2win_set_pop_up_unicode_text.cpp"
    "src/cxx98/game_function/d2win/d2win_set_text_font.cpp"
    "src/cxx98/game_function/d2win/d2win_unload_cel_file.cpp"
    "src/cxx98/game_function/d2win/d2win_unload_mpq.cpp"
    "src/cxx98/game_function/fog/fog_alloc_client_memory.cpp"
    "src/cxx98/game_function/fog/fog_free_client_memory.cpp"
    "src/cxx98/game_function/storm/storm_s_file_close_archive.cpp"
    "src/cxx98/game_function/storm/storm_s_file_open_archive.cpp"

    "src/cxx98/game_struct/d2_belt_record/d2_belt_record_api.cpp"
    "src/cxx98/game_struct/d2_belt_record/d2_belt_record_view.cpp"
    "src/cxx98/game_struct/d2_belt_record/d2_belt_record_wrapper.cpp"
    "src/cxx98/game_struct/d2_cel/d2_cel_view.cpp"
    "src/cxx98/game_struct/d2_cel/d2_cel_wrapper.cpp"
    "src/cxx98/game_struct/d2_cel_context/d2_cel_context_api.cpp"
    "src/cxx98/game_struct/d2_cel_context/d2_cel_context_view.cpp"
    "src/cxx98/game_struct/d2_cel_context/d2_cel_context_wrapper.cpp"
    "src/cxx98/game_struct/d2_cel_file/d2_cel_file_api.cpp"
    "src/cxx98/game_struct/d2_cel_file/d2_cel_file_view.cpp"
    "src/cxx98/game_struct/d2_cel_file/d2_cel_file_wrapper.cpp"
    "src/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_api.cpp"
    "src/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_view.cpp"
    "src/cxx98/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.cpp"
    "src/cxx98/game_struct/d2_grid_layout/d2_grid_layout_api.cpp"
    "src/cxx98/game_struct/d2_grid_layout/d2_grid_layout_view.cpp"
    "src/cxx98/game_struct/d2_grid_layout/d2_grid_layout_wrapper.cpp"
    "src/cxx98/game_struct/d2_inventory_record/d2_inventory_record_api.cpp"
    "src/cxx98/game_struct/d2_inventory_record/d2_inventory_record_view.cpp"
    "src/cxx98/game_struct/d2_inventory_record/d2_inventory_record_wrapper.cpp"
    "src/cxx98/game_struct/d2_mpq_archive/d2_mpq_archive_view.cpp"
    "src/cxx98/game_struct/d2_mpq_archive/d2_mpq_archive_wrapper.cpp"
    "src/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.cpp"
    "src/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_view.cpp"
    "src/cxx98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.cpp"
    "src/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.cpp"
    "src/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_view.cpp"
    "src/cxx98/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.cpp"

    "src/cxx98/game_variable/bnclient/bnclient_gateway_domain_name.cpp"
    "src/cxx98/game_variable/bnclient/bnclient_gateway_ip_v4_address.cpp"
    "src/cxx98/game_variable/d2client/d2client_difficulty_level.cpp"
    "src/cxx98/game_variable/d2client/d2client_game_type.cpp"
    "src/cxx98/game_variable/d2client/d2client_general_display_height.cpp"
    "src/cxx98/game_variable/d2client/d2client_general_display_width.cpp"
    "src/cxx98/game_variable/d2client/d2client_general_play_area_camera_shift_x.cpp"
    "src/cxx98/game_variable/d2client/d2client_ingame_mouse_position_x.cpp"
    "src/cxx98/game_variable/d2client/d2client_ingame_mouse_position_y.cpp"
    "src/cxx98/game_variable/d2client/d2client_inventory_arrange_mode.cpp"
    "src/cxx98/game_variable/d2client/d2client_is_automap_open.cpp"
    "src/cxx98/game_variable/d2client/d2client_is_game_menu_open.cpp"
    "src/cxx98/game_variable/d2client/d2client_is_help_screen_open.cpp"
    "src/cxx98/game_variable/d2client/d2client_is_new_skill_button_pressed.cpp"
    "src/cxx98/game_variable/d2client/d2client_is_new_stats_button_pressed.cpp"
    "src/cxx98/game_variable/d2client/d2client_screen_open_mode.cpp"
    "src/cxx98/game_variable/d2client/d2client_screen_shift_x.cpp"
    "src/cxx98/game_variable/d2client/d2client_screen_shift_y.cpp"
    "src/cxx98/game_variable/d2common/d2common_global_belts_txt.cpp"
    "src/cxx98/game_variable/d2common/d2common_global_inventory_txt.cpp"
    "src/cxx98/game_variable/d2common/d2common_global_inventory_txt_records_count.cpp"
    "src/cxx98/game_variable/d2ddraw/d2ddraw_bit_block_height.cpp"
    "src/cxx98/game_variable/d2ddraw/d2ddraw_bit_block_width.cpp"
    "src/cxx98/game_variable/d2ddraw/d2ddraw_cel_display_left.cpp"
    "src/cxx98/game_variable/d2ddraw/d2ddraw_cel_display_right.cpp"
    "src/cxx98/game_variable/d2ddraw/d2ddraw_display_height.cpp"
    "src/cxx98/game_variable/d2ddraw/d2ddraw_display_width.cpp"
    "src/cxx98/game_variable/d2direct3d/d2direct3d_display_height.cpp"
    "src/cxx98/game_variable/d2direct3d/d2direct3d_display_width.cpp"
    "src/cxx98/game_variable/d2gdi/d2gdi_bit_block_height.cpp"
    "src/cxx98/game_variable/d2gdi/d2gdi_bit_block_width.cpp"
    "src/cxx98/game_variable/d2gdi/d2gdi_cel_display_left.cpp"
    "src/cxx98/game_variable/d2gdi/d2gdi_cel_display_right.cpp"
    "src/cxx98/game_variable/d2gfx/d2gfx_is_windowed_mode.cpp"
    "src/cxx98/game_variable/d2gfx/d2gfx_resolution_mode.cpp"
    "src/cxx98/game_variable/d2gfx/d2gfx_video_mode.cpp"
    "src/cxx98/game_variable/d2gfx/d2gfx_window_handle.cpp"
    "src/cxx98/game_variable/d2glide/d2glide_display_height.cpp"
    "src/cxx98/game_variable/d2glide/d2glide_display_width.cpp"
    "src/cxx98/game_variable/d2win/d2win_main_menu_mouse_position_x.cpp"
    "src/cxx98/game_variable/d2win/d2win_main_menu_mouse_position_y.cpp"

    "src/cxx98/helper/d2_determine_video_mode.cpp"

    "src/cxx98/default_game_library.cpp"
    "src/cxx98/game_address.cpp"
    "src/cxx98/game_executable.cpp"
    "src/cxx98/game_patch.cpp"
    "src/cxx98/game_version.cpp"

    "src/dll_main.cpp"
)

set(SRC_HEADERS)

# Output static LIB
add_library(libSGD2MAPIcxx98 STATIC ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_include_directories(libSGD2MAPIcxx98 PUBLIC "include")

target_link_libraries(libSGD2MAPIcxx98 libSGD2MAPIc libMDCcpp98 libMDCc)
add_dependencies(libSGD2MAPIcxx98 libSGD2MAPIc libMDCcpp98 libMDCc)

# Output DLL
add_library(SGD2MAPIcxx98 SHARED ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_compile_definitions(SGD2MAPIcxx98 PRIVATE SGD2MAPICXX98_DLLEXPORT)
target_compile_definitions(SGD2MAPIcxx98 INTERFACE SGD2MAPICXX98_DLLIMPORT)

target_include_directories(SGD2MAPIcxx98 PUBLIC "include")

target_link_libraries(SGD2MAPIcxx98 SGD2MAPIc libMDCcpp98 libMDCc version)
add_dependencies(SGD2MAPIcxx98 SGD2MAPIc libMDCcpp98 libMDCc)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        ${SRC_C}
        ${SRC_HEADERS}
        ${INCLUDE_HEADERS}
)

install(TARGETS SGD2MAPIcxx98 libSGD2MAPIcxx98)
