cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project(SGD2MAPIcpp98)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define requirements for C++
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# List all of the source files here
set(INCLUDE_HEADERS
    "src/sgd2mapi98/file/file_pe_signature.hpp"
    "src/sgd2mapi98/file/file_version_info.hpp"
    "src/sgd2mapi98/file/fixed_file_version.hpp"

    "src/sgd2mapi98/game_constant/d2_client_game_type.hpp"
    "src/sgd2mapi98/game_constant/d2_difficulty_level.hpp"
    "src/sgd2mapi98/game_constant/d2_draw_effect.hpp"
    "src/sgd2mapi98/game_constant/d2_screen_open_mode.hpp"
    "src/sgd2mapi98/game_constant/d2_text_color.hpp"
    "src/sgd2mapi98/game_constant/d2_text_font.hpp"
    "src/sgd2mapi98/game_constant/d2_video_mode.hpp"

    "src/sgd2mapi98/game_function/d2client/d2client_draw_centered_unicode_text.hpp"
    "src/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.hpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_record.hpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_slot_position.hpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_equipment_slot_layout.hpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_grid_layout.hpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_position.hpp"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.hpp"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_rectangle.hpp"
    "src/sgd2mapi98/game_function/d2lang/d2lang_get_string_by_index.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_draw_unicode_text.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_draw_width.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_n_draw_width.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_load_cel_file.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_load_mpq.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_set_pop_up_unicode_text.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_set_unicode_text_font.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_cel_file.hpp"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_mpq.hpp"
    "src/sgd2mapi98/game_function/fog/fog_alloc_client_memory.hpp"
    "src/sgd2mapi98/game_function/fog/fog_free_client_memory.hpp"
    "src/sgd2mapi98/game_function/storm/storm_s_file_close_archive.hpp"
    "src/sgd2mapi98/game_function/storm/storm_s_file_open_archive.hpp"

    "src/sgd2mapi98/game_function/bnclient_function.hpp"
    "src/sgd2mapi98/game_function/d2client_function.hpp"
    "src/sgd2mapi98/game_function/d2cmp_function.hpp"
    "src/sgd2mapi98/game_function/d2common_function.hpp"
    "src/sgd2mapi98/game_function/d2ddraw_function.hpp"
    "src/sgd2mapi98/game_function/d2direct3d_function.hpp"
    "src/sgd2mapi98/game_function/d2game_function.hpp"
    "src/sgd2mapi98/game_function/d2gdi_function.hpp"
    "src/sgd2mapi98/game_function/d2gfx_function.hpp"
    "src/sgd2mapi98/game_function/d2glide_function.hpp"
    "src/sgd2mapi98/game_function/d2lang_function.hpp"
    "src/sgd2mapi98/game_function/d2launch_function.hpp"
    "src/sgd2mapi98/game_function/d2mcpclient_function.hpp"
    "src/sgd2mapi98/game_function/d2multi_function.hpp"
    "src/sgd2mapi98/game_function/d2net_function.hpp"
    "src/sgd2mapi98/game_function/d2sound_function.hpp"
    "src/sgd2mapi98/game_function/d2win_function.hpp"
    "src/sgd2mapi98/game_function/fog_function.hpp"
    "src/sgd2mapi98/game_function/storm_function.hpp"

    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_api.hpp"
    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_view.hpp"
    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_cel/d2_cel_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_cel/d2_cel_view.hpp"
    "src/sgd2mapi98/game_struct/d2_cel/d2_cel_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_api.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_view.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_api.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_view.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_api.hpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_view.hpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_api.hpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_view.hpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_api.hpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_view.hpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive/d2_mpq_archive_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive/d2_mpq_archive_view.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive/d2_mpq_archive_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_view.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.hpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.hpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_struct.hpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_view.hpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"

    "src/sgd2mapi98/game_struct/d2_belt_record.hpp"
    "src/sgd2mapi98/game_struct/d2_cel.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_context.hpp"
    "src/sgd2mapi98/game_struct/d2_cel_file.hpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout.hpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout.hpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive.hpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle.hpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle.hpp"

    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_domain_name.hpp"
    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_ip_v4_address.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_difficulty_level.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_game_type.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_height.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_width.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_play_area_camera_shift_x.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_x.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_y.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_inventory_arrange_mode.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_automap_open.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_game_menu_open.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_help_screen_open.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_skill_button_pressed.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_stats_button_pressed.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_open_mode.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_x.hpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_y.hpp"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_belts_txt.hpp"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt.hpp"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt_records_count.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_height.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_width.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_left.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_right.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_height.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_width.hpp"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_height.hpp"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_width.hpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_height.hpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_width.hpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_left.hpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_right.hpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_is_windowed_mode.hpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_resolution_mode.hpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_video_mode.hpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_window_handle.hpp"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_height.hpp"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_width.hpp"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_x.hpp"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_y.hpp"

    "src/sgd2mapi98/game_variable/bnclient_variable.hpp"
    "src/sgd2mapi98/game_variable/d2client_variable.hpp"
    "src/sgd2mapi98/game_variable/d2cmp_variable.hpp"
    "src/sgd2mapi98/game_variable/d2common_variable.hpp"
    "src/sgd2mapi98/game_variable/d2ddraw_variable.hpp"
    "src/sgd2mapi98/game_variable/d2direct3d_variable.hpp"
    "src/sgd2mapi98/game_variable/d2game_variable.hpp"
    "src/sgd2mapi98/game_variable/d2gdi_variable.hpp"
    "src/sgd2mapi98/game_variable/d2gfx_variable.hpp"
    "src/sgd2mapi98/game_variable/d2glide_variable.hpp"
    "src/sgd2mapi98/game_variable/d2lang_variable.hpp"
    "src/sgd2mapi98/game_variable/d2launch_variable.hpp"
    "src/sgd2mapi98/game_variable/d2mcpclient_variable.hpp"
    "src/sgd2mapi98/game_variable/d2multi_variable.hpp"
    "src/sgd2mapi98/game_variable/d2net_variable.hpp"
    "src/sgd2mapi98/game_variable/d2sound_variable.hpp"
    "src/sgd2mapi98/game_variable/d2win_variable.hpp"
    "src/sgd2mapi98/game_variable/fog_variable.hpp"
    "src/sgd2mapi98/game_variable/storm_variable.hpp"

    "src/sgd2mapi98/helper/d2_determine_video_mode.hpp"

    "src/sgd2mapi98/default_game_library.hpp"
    "src/sgd2mapi98/file.hpp"
    "src/sgd2mapi98/game_address.hpp"
    "src/sgd2mapi98/game_bool.hpp"
    "src/sgd2mapi98/game_branch_type.hpp"
    "src/sgd2mapi98/game_constant.hpp"
    "src/sgd2mapi98/game_executable.hpp"
    "src/sgd2mapi98/game_function.hpp"
    "src/sgd2mapi98/game_patch.hpp"
    "src/sgd2mapi98/game_struct.hpp"
    "src/sgd2mapi98/game_undefined.hpp"
    "src/sgd2mapi98/game_variable.hpp"
    "src/sgd2mapi98/game_version.hpp"
    "src/sgd2mapi98/helper.hpp"

    "src/sgd2mapi98/dllapi_cpp98_define.inc"
    "src/sgd2mapi98/dllapi_cpp98_undef.inc"

    "src/sgd2mapi98.hpp"
)

set(SRC_C
    "src/sgd2mapi98/file/file_pe_signature.cpp"
    "src/sgd2mapi98/file/file_version_info.cpp"
    "src/sgd2mapi98/file/fixed_file_version.cpp"

    "src/sgd2mapi98/game_constant/d2_client_game_type.cpp"
    "src/sgd2mapi98/game_constant/d2_difficulty_level.cpp"
    "src/sgd2mapi98/game_constant/d2_draw_effect.cpp"
    "src/sgd2mapi98/game_constant/d2_screen_open_mode.cpp"
    "src/sgd2mapi98/game_constant/d2_text_color.cpp"
    "src/sgd2mapi98/game_constant/d2_text_font.cpp"
    "src/sgd2mapi98/game_constant/d2_video_mode.cpp"

    "src/sgd2mapi98/game_function/d2client/d2client_draw_centered_unicode_text.cpp"
    "src/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.cpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_record.cpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_slot_position.cpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_equipment_slot_layout.cpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_grid_layout.cpp"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_position.cpp"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.cpp"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_rectangle.cpp"
    "src/sgd2mapi98/game_function/d2lang/d2lang_get_string_by_index.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_draw_unicode_text.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_draw_width.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_n_draw_width.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_load_cel_file.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_load_mpq.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_set_pop_up_unicode_text.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_set_unicode_text_font.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_cel_file.cpp"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_mpq.cpp"
    "src/sgd2mapi98/game_function/fog/fog_alloc_client_memory.cpp"
    "src/sgd2mapi98/game_function/fog/fog_free_client_memory.cpp"
    "src/sgd2mapi98/game_function/storm/storm_s_file_close_archive.cpp"
    "src/sgd2mapi98/game_function/storm/storm_s_file_open_archive.cpp"

    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_api.cpp"
    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_view.cpp"
    "src/sgd2mapi98/game_struct/d2_belt_record/d2_belt_record_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_cel/d2_cel_view.cpp"
    "src/sgd2mapi98/game_struct/d2_cel/d2_cel_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_api.cpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_view.cpp"
    "src/sgd2mapi98/game_struct/d2_cel_context/d2_cel_context_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_api.cpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_view.cpp"
    "src/sgd2mapi98/game_struct/d2_cel_file/d2_cel_file_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_api.cpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_view.cpp"
    "src/sgd2mapi98/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_api.cpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_view.cpp"
    "src/sgd2mapi98/game_struct/d2_grid_layout/d2_grid_layout_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_api.cpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_view.cpp"
    "src/sgd2mapi98/game_struct/d2_inventory_record/d2_inventory_record_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive/d2_mpq_archive_view.cpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive/d2_mpq_archive_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.cpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_view.cpp"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.cpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.cpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_view.cpp"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.cpp"

    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_domain_name.cpp"
    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_ip_v4_address.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_difficulty_level.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_game_type.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_height.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_width.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_play_area_camera_shift_x.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_x.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_y.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_inventory_arrange_mode.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_automap_open.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_game_menu_open.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_help_screen_open.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_skill_button_pressed.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_stats_button_pressed.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_open_mode.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_x.cpp"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_y.cpp"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_belts_txt.cpp"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt.cpp"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt_records_count.cpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_height.cpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_width.cpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_left.cpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_right.cpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_height.cpp"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_width.cpp"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_height.cpp"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_width.cpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_height.cpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_width.cpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_left.cpp"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_right.cpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_is_windowed_mode.cpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_resolution_mode.cpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_video_mode.cpp"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_window_handle.cpp"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_height.cpp"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_width.cpp"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_x.cpp"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_y.cpp"

    "src/sgd2mapi98/helper/d2_determine_video_mode.cpp"

    "src/sgd2mapi98/default_game_library.cpp"
    "src/sgd2mapi98/game_address.cpp"
    "src/sgd2mapi98/game_executable.cpp"
    "src/sgd2mapi98/game_patch.cpp"
    "src/sgd2mapi98/game_version.cpp"

    "src/dll_main.cpp"
)

set(SRC_HEADERS)

set(SOURCE_FILES
    ${SRC_C}
    ${SRC_HEADERS}
    ${INCLUDE_HEADERS}
)

# Build output
option(${PROJECT_NAME}_BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (${PROJECT_NAME}_BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
    target_compile_definitions(${PROJECT_NAME}
        INTERFACE SGD2MAPI_CPP98_DLLIMPORT
        PRIVATE SGD2MAPI_CPP98_DLLEXPORT)
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif()

target_include_directories(
    ${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME} PUBLIC SGD2MAPIc MDCcpp98 MDCc version)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES}
)
