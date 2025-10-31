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
    "src/sgd2mapi98/file/file_pe_signature.h"
    "src/sgd2mapi98/file/file_version_info.h"
    "src/sgd2mapi98/file/fixed_file_version.h"

    "src/sgd2mapi98/game_constant/d2_client_game_type.h"
    "src/sgd2mapi98/game_constant/d2_difficulty_level.h"
    "src/sgd2mapi98/game_constant/d2_draw_effect.h"
    "src/sgd2mapi98/game_constant/d2_screen_open_mode.h"
    "src/sgd2mapi98/game_constant/d2_text_color.h"
    "src/sgd2mapi98/game_constant/d2_text_font.h"
    "src/sgd2mapi98/game_constant/d2_video_mode.h"

    "src/sgd2mapi98/game_function/d2client/d2client_draw_centered_unicode_text.h"
    "src/sgd2mapi98/game_function/d2cmp/d2cmp_get_cel_from_cel_context.h"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_record.h"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_belt_slot_position.h"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_equipment_slot_layout.h"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_grid_layout.h"
    "src/sgd2mapi98/game_function/d2common/d2common_get_global_inventory_position.h"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_cel_context.h"
    "src/sgd2mapi98/game_function/d2gfx/d2gfx_draw_rectangle.h"
    "src/sgd2mapi98/game_function/d2lang/d2lang_get_string_by_index.h"
    "src/sgd2mapi98/game_function/d2win/d2win_draw_unicode_text.h"
    "src/sgd2mapi98/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.h"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_draw_width.h"
    "src/sgd2mapi98/game_function/d2win/d2win_get_unicode_text_n_draw_width.h"
    "src/sgd2mapi98/game_function/d2win/d2win_load_cel_file.h"
    "src/sgd2mapi98/game_function/d2win/d2win_load_mpq.h"
    "src/sgd2mapi98/game_function/d2win/d2win_set_pop_up_unicode_text.h"
    "src/sgd2mapi98/game_function/d2win/d2win_set_unicode_text_font.h"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_cel_file.h"
    "src/sgd2mapi98/game_function/d2win/d2win_unload_mpq.h"
    "src/sgd2mapi98/game_function/fog/fog_alloc_client_memory.h"
    "src/sgd2mapi98/game_function/fog/fog_free_client_memory.h"
    "src/sgd2mapi98/game_function/storm/storm_s_file_close_archive.h"
    "src/sgd2mapi98/game_function/storm/storm_s_file_open_archive.h"

    "src/sgd2mapi98/game_function/bnclient_function.h"
    "src/sgd2mapi98/game_function/d2client_function.h"
    "src/sgd2mapi98/game_function/d2cmp_function.h"
    "src/sgd2mapi98/game_function/d2common_function.h"
    "src/sgd2mapi98/game_function/d2ddraw_function.h"
    "src/sgd2mapi98/game_function/d2direct3d_function.h"
    "src/sgd2mapi98/game_function/d2game_function.h"
    "src/sgd2mapi98/game_function/d2gdi_function.h"
    "src/sgd2mapi98/game_function/d2gfx_function.h"
    "src/sgd2mapi98/game_function/d2glide_function.h"
    "src/sgd2mapi98/game_function/d2lang_function.h"
    "src/sgd2mapi98/game_function/d2launch_function.h"
    "src/sgd2mapi98/game_function/d2mcpclient_function.h"
    "src/sgd2mapi98/game_function/d2multi_function.h"
    "src/sgd2mapi98/game_function/d2net_function.h"
    "src/sgd2mapi98/game_function/d2sound_function.h"
    "src/sgd2mapi98/game_function/d2win_function.h"
    "src/sgd2mapi98/game_function/fog_function.h"
    "src/sgd2mapi98/game_function/storm_function.h"

    "src/sgd2mapi98/game_struct/d2_belt_record.h"
    "src/sgd2mapi98/game_struct/d2_cel.h"
    "src/sgd2mapi98/game_struct/d2_cel_context.h"
    "src/sgd2mapi98/game_struct/d2_cel_file.h"
    "src/sgd2mapi98/game_struct/d2_equipment_layout.h"
    "src/sgd2mapi98/game_struct/d2_grid_layout.h"
    "src/sgd2mapi98/game_struct/d2_inventory_record.h"
    "src/sgd2mapi98/game_struct/d2_mpq_archive.h"
    "src/sgd2mapi98/game_struct/d2_mpq_archive_handle.h"
    "src/sgd2mapi98/game_struct/d2_positional_rectangle.h"

    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_domain_name.h"
    "src/sgd2mapi98/game_variable/bnclient/bnclient_gateway_ip_v4_address.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_difficulty_level.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_game_type.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_height.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_display_width.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_general_play_area_camera_shift_x.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_x.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_ingame_mouse_position_y.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_inventory_arrange_mode.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_automap_open.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_game_menu_open.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_help_screen_open.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_skill_button_pressed.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_is_new_stats_button_pressed.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_open_mode.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_x.h"
    "src/sgd2mapi98/game_variable/d2client/d2client_screen_shift_y.h"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_belts_txt.h"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt.h"
    "src/sgd2mapi98/game_variable/d2common/d2common_global_inventory_txt_records_count.h"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_height.h"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_bit_block_width.h"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_left.h"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_cel_display_right.h"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_height.h"
    "src/sgd2mapi98/game_variable/d2ddraw/d2ddraw_display_width.h"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_height.h"
    "src/sgd2mapi98/game_variable/d2direct3d/d2direct3d_display_width.h"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_height.h"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_bit_block_width.h"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_left.h"
    "src/sgd2mapi98/game_variable/d2gdi/d2gdi_cel_display_right.h"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_is_windowed_mode.h"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_resolution_mode.h"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_video_mode.h"
    "src/sgd2mapi98/game_variable/d2gfx/d2gfx_window_handle.h"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_height.h"
    "src/sgd2mapi98/game_variable/d2glide/d2glide_display_width.h"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_x.h"
    "src/sgd2mapi98/game_variable/d2win/d2win_main_menu_mouse_position_y.h"

    "src/sgd2mapi98/game_variable/bnclient_variable.h"
    "src/sgd2mapi98/game_variable/d2client_variable.h"
    "src/sgd2mapi98/game_variable/d2cmp_variable.h"
    "src/sgd2mapi98/game_variable/d2common_variable.h"
    "src/sgd2mapi98/game_variable/d2ddraw_variable.h"
    "src/sgd2mapi98/game_variable/d2direct3d_variable.h"
    "src/sgd2mapi98/game_variable/d2game_variable.h"
    "src/sgd2mapi98/game_variable/d2gdi_variable.h"
    "src/sgd2mapi98/game_variable/d2gfx_variable.h"
    "src/sgd2mapi98/game_variable/d2glide_variable.h"
    "src/sgd2mapi98/game_variable/d2lang_variable.h"
    "src/sgd2mapi98/game_variable/d2launch_variable.h"
    "src/sgd2mapi98/game_variable/d2mcpclient_variable.h"
    "src/sgd2mapi98/game_variable/d2multi_variable.h"
    "src/sgd2mapi98/game_variable/d2net_variable.h"
    "src/sgd2mapi98/game_variable/d2sound_variable.h"
    "src/sgd2mapi98/game_variable/d2win_variable.h"
    "src/sgd2mapi98/game_variable/fog_variable.h"
    "src/sgd2mapi98/game_variable/storm_variable.h"

    "src/sgd2mapi98/helper/d2_determine_video_mode.h"

    "src/sgd2mapi98/default_game_library.h"
    "src/sgd2mapi98/file.h"
    "src/sgd2mapi98/game_address.h"
    "src/sgd2mapi98/game_bool.h"
    "src/sgd2mapi98/game_branch_type.h"
    "src/sgd2mapi98/game_constant.h"
    "src/sgd2mapi98/game_executable.h"
    "src/sgd2mapi98/game_function.h"
    "src/sgd2mapi98/game_patch.h"
    "src/sgd2mapi98/game_struct.h"
    "src/sgd2mapi98/game_undefined.h"
    "src/sgd2mapi98/game_variable.h"
    "src/sgd2mapi98/game_version.h"
    "src/sgd2mapi98/helper.h"

    "src/d2api_version.h"
    "src/dllexport_define.inc"
    "src/dllexport_define.inc"
    "src/sgd2mapi98.h"
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
)

set(SOURCE_FILES
    ${SRC_ASM}
    ${SRC_C}
    ${SRC_HEADERS}
    ${INCLUDE_HEADERS}
)

# Build output
option(${PROJECT_NAME}_BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (${PROJECT_NAME}_BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
    target_compile_definitions(${PROJECT_NAME}
        INTERFACE SGD2MAPI_C_DLLIMPORT
        PRIVATE SGD2MAPI_C_DLLEXPORT)
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif()

target_include_directories(
    ${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME} PUBLIC MDCc shlwapi version)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
