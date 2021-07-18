# Microsoft Developer Studio Project File - Name="SGD2MAPIc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=SGD2MAPIc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SGD2MAPIc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SGD2MAPIc.mak" CFG="SGD2MAPIc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SGD2MAPIc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "SGD2MAPIc - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "SGD2MAPIc - Win32 Release Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SGD2MAPIc - Win32 Debug Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /Fp"Release/libSGD2MAPIc.pch" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Release/libSGD2MAPIc.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\libSGD2MAPIc.lib"

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /Fp"Debug/libSGD2MAPIcD.pch" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/libSGD2MAPIcD.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\libSGD2MAPIcD.lib"

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDll"
# PROP BASE Intermediate_Dir "ReleaseDll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDll"
# PROP Intermediate_Dir "ReleaseDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EMPTYDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_USRDLL" /D "SGD2MAPIC_DLLEXPORT" /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 libunicows.lib libMDCc.lib shlwapi.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDll"
# PROP BASE Intermediate_Dir "DebugDll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDll"
# PROP Intermediate_Dir "DebugDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EMPTYDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_USRDLL" /D "SGD2MAPIC_DLLEXPORT" /YX /FD /GZ /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"DebugDll/SGD2MAPIcD.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib libMDCcD.lib shlwapi.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"DebugDll/SGD2MAPIcD.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SGD2MAPIc - Win32 Release"
# Name "SGD2MAPIc - Win32 Debug"
# Name "SGD2MAPIc - Win32 Release Dll"
# Name "SGD2MAPIc - Win32 Debug Dll"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "file_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\file\file_pe_signature.h
# End Source File
# Begin Source File

SOURCE=.\include\c\file\file_version_info.h
# End Source File
# Begin Source File

SOURCE=.\include\c\file\fixed_file_version.h
# End Source File
# End Group
# Begin Group "game_constant_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_constant\d2_client_game_type.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_constant\d2_difficulty_level.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_constant\d2_draw_effect.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_constant\d2_screen_open_mode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_constant\d2_text_color.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_constant\d2_text_font.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_constant\d2_video_mode.h
# End Source File
# End Group
# Begin Group "game_function_h"

# PROP Default_Filter ""
# Begin Group "d2client_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\d2client\d2client_draw_centered_unicode_text.h
# End Source File
# End Group
# Begin Group "d2cmp_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\d2cmp\d2cmp_get_cel_from_cel_context.h
# End Source File
# End Group
# Begin Group "d2common_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\d2common\d2common_get_global_belt_record.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2common\d2common_get_global_belt_slot_position.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2common\d2common_get_global_equipment_slot_layout.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2common\d2common_get_global_inventory_grid_layout.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2common\d2common_get_global_inventory_position.h
# End Source File
# End Group
# Begin Group "d2gfx_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\d2gfx\d2gfx_draw_cel_context.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2gfx\d2gfx_draw_rectangle.h
# End Source File
# End Group
# Begin Group "d2lang_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_get_string_by_index.h
# End Source File
# End Group
# Begin Group "d2win_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_draw_unicode_text.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_get_pop_up_unicode_text_width_and_height.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_get_unicode_text_draw_width.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_get_unicode_text_n_draw_width.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_load_cel_file.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_load_mpq.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_set_pop_up_unicode_text.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_set_text_font.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_unload_cel_file.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win\d2win_unload_mpq.h
# End Source File
# End Group
# Begin Group "fog_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\fog\fog_alloc_client_memory.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\fog\fog_free_client_memory.h
# End Source File
# End Group
# Begin Group "storm_function_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_function\storm\storm_s_file_close_archive.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\storm\storm_s_file_open_archive.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\c\game_function\bnclient_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2client_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2cmp_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2common_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2ddraw_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2direct3d_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2game_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2gdi_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2gfx_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2glide_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2launch_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2mcpclient_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2multi_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2net_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2sound_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2win_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\fog_function.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\storm_function.h
# End Source File
# End Group
# Begin Group "game_struct_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_struct\d2_belt_record.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_cel.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_cel_context.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_cel_file.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_equipment_layout.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_grid_layout.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_inventory_record.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_mpq_archive.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_mpq_archive_handle.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct\d2_positional_rectangle.h
# End Source File
# End Group
# Begin Group "game_variable_h"

# PROP Default_Filter ""
# Begin Group "bnclient_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\bnclient\bnclient_gateway_domain_name.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\bnclient\bnclient_gateway_ip_v4_address.h
# End Source File
# End Group
# Begin Group "d2client_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_difficulty_level.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_game_type.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_general_display_height.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_general_display_width.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_general_play_area_camera_shift_x.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_ingame_mouse_position_x.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_ingame_mouse_position_y.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_inventory_arrange_mode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_is_automap_open.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_is_game_menu_open.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_is_help_screen_open.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_is_new_skill_button_pressed.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_is_new_stats_button_pressed.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_screen_open_mode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_screen_shift_x.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client\d2client_screen_shift_y.h
# End Source File
# End Group
# Begin Group "d2common_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2common\d2common_global_belts_txt.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2common\d2common_global_inventory_txt.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2common\d2common_global_inventory_txt_records_count.h
# End Source File
# End Group
# Begin Group "d2ddraw_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2ddraw\d2ddraw_bit_block_height.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2ddraw\d2ddraw_bit_block_width.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2ddraw\d2ddraw_cel_display_left.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2ddraw\d2ddraw_cel_display_right.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2ddraw\d2ddraw_display_height.h
# End Source File
# End Group
# Begin Group "d2direct3d_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2direct3d\d2direct3d_display_height.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2direct3d\d2direct3d_display_width.h
# End Source File
# End Group
# Begin Group "d2gdi_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2gdi\d2gdi_bit_block_height.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gdi\d2gdi_bit_block_width.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gdi\d2gdi_cel_display_left.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gdi\d2gdi_cel_display_right.h
# End Source File
# End Group
# Begin Group "d2gfx_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2gfx\d2gfx_is_windowed_mode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gfx\d2gfx_resolution_mode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gfx\d2gfx_video_mode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gfx\d2gfx_window_handle.h
# End Source File
# End Group
# Begin Group "d2glide_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2glide\d2glide_display_height.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2glide\d2glide_display_width.h
# End Source File
# End Group
# Begin Group "d2win_variable_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\game_variable\d2win\d2win_main_menu_mouse_position_x.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2win\d2win_main_menu_mouse_position_y.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\c\game_variable\bnclient_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2client_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2cmp_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2common_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2ddraw_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2direct3d_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2game_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gdi_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2gfx_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2glide_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2lang_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2launch_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2mcpclient_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2multi_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2net_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2sound_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\d2win_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\fog_variable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_variable\storm_variable.h
# End Source File
# End Group
# Begin Group "helper_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\c\helper\d2_determine_video_mode.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\d2api_version.h
# End Source File
# Begin Source File

SOURCE=.\include\c\default_game_library.h
# End Source File
# Begin Source File

SOURCE=.\include\dllexport_define.inc
# End Source File
# Begin Source File

SOURCE=.\include\dllexport_undefine.inc
# End Source File
# Begin Source File

SOURCE=.\include\c\file.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_address.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_bool.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_branch_type.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_executable.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_patch.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_struct.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_undefined.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_version.h
# End Source File
# Begin Source File

SOURCE=.\include\c\helper.h
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "backend_c"

# PROP Default_Filter ""
# Begin Group "backend_game_address_table_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\backend\game_address_table\game_address_table_define.h
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_address_table\game_address_table_impl.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_address_table\game_address_table_impl.h
# End Source File
# End Group
# Begin Group "backend_game_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\backend\game_function\cdecl_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Release
InputPath=.\src\c\backend\game_function\cdecl_function.asm
InputName=cdecl_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Debug
InputPath=.\src\c\backend\game_function\cdecl_function.asm
InputName=cdecl_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\ReleaseDll
InputPath=.\src\c\backend\game_function\cdecl_function.asm
InputName=cdecl_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\DebugDll
InputPath=.\src\c\backend\game_function\cdecl_function.asm
InputName=cdecl_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\cdecl_function.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\esi_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Release
InputPath=.\src\c\backend\game_function\esi_function.asm
InputName=esi_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Debug
InputPath=.\src\c\backend\game_function\esi_function.asm
InputName=esi_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\ReleaseDll
InputPath=.\src\c\backend\game_function\esi_function.asm
InputName=esi_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\DebugDll
InputPath=.\src\c\backend\game_function\esi_function.asm
InputName=esi_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\esi_function.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\fastcall_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Release
InputPath=.\src\c\backend\game_function\fastcall_function.asm
InputName=fastcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Debug
InputPath=.\src\c\backend\game_function\fastcall_function.asm
InputName=fastcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\ReleaseDll
InputPath=.\src\c\backend\game_function\fastcall_function.asm
InputName=fastcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\DebugDll
InputPath=.\src\c\backend\game_function\fastcall_function.asm
InputName=fastcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\fastcall_function.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\stdcall_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Release
InputPath=.\src\c\backend\game_function\stdcall_function.asm
InputName=stdcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Debug
InputPath=.\src\c\backend\game_function\stdcall_function.asm
InputName=stdcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\ReleaseDll
InputPath=.\src\c\backend\game_function\stdcall_function.asm
InputName=stdcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\DebugDll
InputPath=.\src\c\backend\game_function\stdcall_function.asm
InputName=stdcall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\stdcall_function.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\thiscall_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Release
InputPath=.\src\c\backend\game_function\thiscall_function.asm
InputName=thiscall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\Debug
InputPath=.\src\c\backend\game_function\thiscall_function.asm
InputName=thiscall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\ReleaseDll
InputPath=.\src\c\backend\game_function\thiscall_function.asm
InputName=thiscall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\backend\game_function
IntDir=.\DebugDll
InputPath=.\src\c\backend\game_function\thiscall_function.asm
InputName=thiscall_function

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\thiscall_function.h
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "backend_game_version_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\backend\game_version\game_version_file_pe_signature.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_version\game_version_file_pe_signature.h
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_version\game_version_file_version.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_version\game_version_file_version.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\c\backend\architecture_opcode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\architecture_opcode.h
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_address_table.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_address_table.h
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_library.cpp
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_library.h
# End Source File
# End Group
# Begin Group "file_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\file\file_pe_signature.c
# End Source File
# Begin Source File

SOURCE=.\src\c\file\file_version_info.c
# End Source File
# Begin Source File

SOURCE=.\src\c\file\fixed_file_version.c
# End Source File
# End Group
# Begin Group "game_constant_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_constant\d2_client_game_type.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_constant\d2_difficulty_level.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_constant\d2_draw_effect.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_constant\d2_screen_open_mode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_constant\d2_text_color.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_constant\d2_text_font.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_constant\d2_video_mode.c
# End Source File
# End Group
# Begin Group "game_function_c"

# PROP Default_Filter ""
# Begin Group "d2client_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\d2client\d2client_draw_centered_unicode_text.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2client\d2client_draw_centered_unicode_text_shim.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\game_function\d2client
IntDir=.\Release
InputPath=.\src\c\game_function\d2client\d2client_draw_centered_unicode_text_shim.asm
InputName=d2client_draw_centered_unicode_text_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\game_function\d2client
IntDir=.\Debug
InputPath=.\src\c\game_function\d2client\d2client_draw_centered_unicode_text_shim.asm
InputName=d2client_draw_centered_unicode_text_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\game_function\d2client
IntDir=.\ReleaseDll
InputPath=.\src\c\game_function\d2client\d2client_draw_centered_unicode_text_shim.asm
InputName=d2client_draw_centered_unicode_text_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\game_function\d2client
IntDir=.\DebugDll
InputPath=.\src\c\game_function\d2client\d2client_draw_centered_unicode_text_shim.asm
InputName=d2client_draw_centered_unicode_text_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "d2cmp_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\d2cmp\d2cmp_get_cel_from_cel_context.c
# End Source File
# End Group
# Begin Group "d2common_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\d2common\d2common_get_global_belt_record.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2common\d2common_get_global_belt_slot_position.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2common\d2common_get_global_equipment_slot_layout.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2common\d2common_get_global_inventory_grid_layout.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2common\d2common_get_global_inventory_position.c
# End Source File
# End Group
# Begin Group "d2gfx_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\d2gfx\d2gfx_draw_cel_context.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2gfx\d2gfx_draw_rectangle.c
# End Source File
# End Group
# Begin Group "d2lang_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\d2lang\d2lang_get_string_by_index.c
# End Source File
# End Group
# Begin Group "d2win_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_draw_unicode_text.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_get_pop_up_unicode_text_width_and_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_get_unicode_text_draw_width.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_get_unicode_text_n_draw_width.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_load_cel_file.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_load_mpq.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_load_mpq_shim.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# Begin Custom Build
InputDir=.\src\c\game_function\d2win
IntDir=.\Release
InputPath=.\src\c\game_function\d2win\d2win_load_mpq_shim.asm
InputName=d2win_load_mpq_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# Begin Custom Build
InputDir=.\src\c\game_function\d2win
IntDir=.\Debug
InputPath=.\src\c\game_function\d2win\d2win_load_mpq_shim.asm
InputName=d2win_load_mpq_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Release Dll"

# Begin Custom Build
InputDir=.\src\c\game_function\d2win
IntDir=.\ReleaseDll
InputPath=.\src\c\game_function\d2win\d2win_load_mpq_shim.asm
InputName=d2win_load_mpq_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug Dll"

# Begin Custom Build
InputDir=.\src\c\game_function\d2win
IntDir=.\DebugDll
InputPath=.\src\c\game_function\d2win\d2win_load_mpq_shim.asm
InputName=d2win_load_mpq_shim

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasm.exe -f win32 -Xvc -o "$(IntDir)\$(InputName).obj" $(InputDir)\$(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_set_pop_up_unicode_text.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_set_text_font.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_unload_cel_file.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\d2win\d2win_unload_mpq.c
# End Source File
# End Group
# Begin Group "fog_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\fog\fog_alloc_client_memory.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\fog\fog_free_client_memory.c
# End Source File
# End Group
# Begin Group "storm_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_function\storm\storm_s_file_close_archive.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_function\storm\storm_s_file_open_archive.c
# End Source File
# End Group
# End Group
# Begin Group "game_struct_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_struct\d2_belt_record.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_cel.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_cel_context.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_cel_file.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_equipment_layout.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_grid_layout.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_inventory_record.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_mpq_archive.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_mpq_archive_handle.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_struct\d2_positional_rectangle.c
# End Source File
# End Group
# Begin Group "game_variable_c"

# PROP Default_Filter ""
# Begin Group "bnclient_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\bnclient\bnclient_gateway_domain_name.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\bnclient\bnclient_gateway_ip_v4_address.c
# End Source File
# End Group
# Begin Group "d2client_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_difficulty_level.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_game_type.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_general_display_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_general_display_width.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_general_play_area_camera_shift_x.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_ingame_mouse_position_x.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_ingame_mouse_position_y.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_inventory_arrange_mode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_is_automap_open.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_is_game_menu_open.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_is_help_screen_open.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_is_new_skill_button_pressed.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_is_new_stats_button_pressed.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_screen_open_mode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_screen_shift_x.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2client\d2client_screen_shift_y.c
# End Source File
# End Group
# Begin Group "d2common_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2common\d2common_global_belts_txt.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2common\d2common_global_inventory_txt.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2common\d2common_global_inventory_txt_records_count.c
# End Source File
# End Group
# Begin Group "d2ddraw_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2ddraw\d2ddraw_bit_block_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2ddraw\d2ddraw_bit_block_width.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2ddraw\d2ddraw_cel_display_left.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2ddraw\d2ddraw_cel_display_right.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2ddraw\d2ddraw_display_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2ddraw\d2ddraw_display_width.c
# End Source File
# End Group
# Begin Group "d2direct3d_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2direct3d\d2direct3d_display_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2direct3d\d2direct3d_display_width.c
# End Source File
# End Group
# Begin Group "d2gdi_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2gdi\d2gdi_bit_block_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2gdi\d2gdi_bit_block_width.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2gdi\d2gdi_cel_display_left.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2gdi\d2gdi_cel_display_right.c
# End Source File
# End Group
# Begin Group "d2gfx_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2gfx\d2gfx_is_windowed_mode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2gfx\d2gfx_resolution_mode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2gfx\d2gfx_video_mode.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2gfx\d2gfx_window_handle.c
# End Source File
# End Group
# Begin Group "d2glide_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2glide\d2glide_display_height.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2glide\d2glide_display_width.c
# End Source File
# End Group
# Begin Group "d2win_variable_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\game_variable\d2win\d2win_main_menu_mouse_position_x.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_variable\d2win\d2win_main_menu_mouse_position_y.c
# End Source File
# End Group
# End Group
# Begin Group "helper_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\helper\d2_determine_video_mode.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\c\default_game_library.c
# End Source File
# Begin Source File

SOURCE=.\src\dll_main.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_address.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_executable.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_patch.c
# End Source File
# Begin Source File

SOURCE=.\src\c\game_version.c
# End Source File
# End Group
# End Group
# End Target
# End Project
