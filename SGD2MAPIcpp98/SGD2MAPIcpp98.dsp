# Microsoft Developer Studio Project File - Name="SGD2MAPIcpp98" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=SGD2MAPIcpp98 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SGD2MAPIcpp98.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SGD2MAPIcpp98.mak" CFG="SGD2MAPIcpp98 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SGD2MAPIcpp98 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "SGD2MAPIcpp98 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "SGD2MAPIcpp98 - Win32 Release Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SGD2MAPIcpp98 - Win32 Debug Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "SGD2MAPIcpp98 - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../third_party/MDC/MDCc/include" /I "../third_party/MDC/MDCcpp98/include" /I "../SGD2MAPIc/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Release/libSGD2MAPIcpp98.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\libSGD2MAPIcpp98.lib"

!ELSEIF  "$(CFG)" == "SGD2MAPIcpp98 - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../third_party/MDC/MDCc/include" /I "../third_party/MDC/MDCcpp98/include" /I "../SGD2MAPIc/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/libSGD2MAPIcpp98D.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\libSGD2MAPIcpp98D.lib"

!ELSEIF  "$(CFG)" == "SGD2MAPIcpp98 - Win32 Release Dll"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../third_party/MDC/MDCc/include" /I "../third_party/MDC/MDCcpp98/include" /I "../SGD2MAPIc/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "MDC_C_DLLIMPORT" /D "MDC_CPP98_DLLIMPORT" /D "SGD2MAPIC_DLLIMPORT" /D "SGD2MAPICPP98_DLLEXPORT" /FD /c
# SUBTRACT CPP /YX
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
# ADD LINK32 libunicows.lib MDCc.lib MDCcpp98.lib SGD2MAPIc.lib shlwapi.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /libpath:"../third_party/MDC/MDCc/ReleaseDll" /libpath:"../third_party/MDC/MDCcpp98/ReleaseDll" /libpath:"../SGD2MAPIc/ReleaseDll"

!ELSEIF  "$(CFG)" == "SGD2MAPIcpp98 - Win32 Debug Dll"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../third_party/MDC/MDCc/include" /I "../third_party/MDC/MDCcpp98/include" /I "../SGD2MAPIc/include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "MDC_C_DLLIMPORT" /D "MDC_CPP98_DLLIMPORT" /D "SGD2MAPIC_DLLIMPORT" /D "SGD2MAPICPP98_DLLEXPORT" /FD /GZ /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"DebugDll/SGD2MAPIcpp98D.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib MDCcD.lib MDCcpp98D.lib SGD2MAPIcD.lib shlwapi.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"DebugDll/SGD2MAPIcpp98D.dll" /pdbtype:sept /libpath:"../third_party/MDC/MDCc/DebugDll" /libpath:"../third_party/MDC/MDCcpp98/DebugDll" /libpath:"../SGD2MAPIc/DebugDll"

!ENDIF 

# Begin Target

# Name "SGD2MAPIcpp98 - Win32 Release"
# Name "SGD2MAPIcpp98 - Win32 Debug"
# Name "SGD2MAPIcpp98 - Win32 Release Dll"
# Name "SGD2MAPIcpp98 - Win32 Debug Dll"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "file_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\file\file_pe_signature.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\file\file_version_info.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\file\fixed_file_version.hpp
# End Source File
# End Group
# Begin Group "game_constant_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_client_game_type.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_difficulty_level.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_draw_effect.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_screen_open_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_text_color.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_text_font.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_constant\d2_video_mode.hpp
# End Source File
# End Group
# Begin Group "game_function_hpp"

# PROP Default_Filter ""
# Begin Group "bnclient_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2client_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2client\d2client_draw_centered_unicode_text.hpp
# End Source File
# End Group
# Begin Group "d2cmp_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2cmp\d2cmp_get_cel_from_cel_context.hpp
# End Source File
# End Group
# Begin Group "d2common_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2common\d2common_get_global_belt_record.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2common\d2common_get_global_belt_slot_position.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2common\d2common_get_global_equipment_slot_layout.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2common\d2common_get_global_inventory_grid_layout.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2common\d2common_get_global_inventory_position.hpp
# End Source File
# End Group
# Begin Group "d2ddraw_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2direct3d_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2game_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2gdi_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2gfx_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2gfx\d2gfx_draw_cel_context.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2gfx\d2gfx_draw_rectangle.hpp
# End Source File
# End Group
# Begin Group "d2glide_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2lang_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2lang\d2lang_get_string_by_index.hpp
# End Source File
# End Group
# Begin Group "d2launch_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2mcpclient_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2multi_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2net_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2sound_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2win_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_draw_unicode_text.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_get_pop_up_unicode_text_width_and_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_get_unicode_text_draw_width.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_get_unicode_text_n_draw_width.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_load_cel_file.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_load_mpq.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_set_pop_up_unicode_text.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_set_unicode_text_font.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_unload_cel_file.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win\d2win_unload_mpq.hpp
# End Source File
# End Group
# Begin Group "fog_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\fog\fog_alloc_client_memory.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\fog\fog_free_client_memory.hpp
# End Source File
# End Group
# Begin Group "storm_function_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\storm\storm_s_file_close_archive.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\storm\storm_s_file_open_archive.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\bnclient_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2client_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2cmp_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2common_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2ddraw_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2direct3d_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2game_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2gdi_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2gfx_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2glide_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2lang_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2launch_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2mcpclient_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2multi_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2net_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2sound_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\d2win_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\fog_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function\storm_function.hpp
# End Source File
# End Group
# Begin Group "game_struct_hpp"

# PROP Default_Filter ""
# Begin Group "d2_belt_record_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_cel_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel\d2_cel_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel\d2_cel_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel\d2_cel_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_cel_context_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_cel_file_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_equipment_layout_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_grid_layout_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_inventory_record_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_mpq_archive_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive\d2_mpq_archive_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive\d2_mpq_archive_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive\d2_mpq_archive_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_mpq_archive_handle_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_positional_rectangle_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_wrapper.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_belt_record.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_context.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_cel_file.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_equipment_layout.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_grid_layout.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_inventory_record.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_mpq_archive_handle.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct\d2_positional_rectangle.hpp
# End Source File
# End Group
# Begin Group "game_variable_hpp"

# PROP Default_Filter ""
# Begin Group "bnclient_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\bnclient\bnclient_gateway_domain_name.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\bnclient\bnclient_gateway_ip_v4_address.hpp
# End Source File
# End Group
# Begin Group "d2client_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_difficulty_level.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_game_type.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_general_display_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_general_display_width.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_general_play_area_camera_shift_x.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_ingame_mouse_position_x.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_ingame_mouse_position_y.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_inventory_arrange_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_is_automap_open.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_is_game_menu_open.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_is_help_screen_open.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_is_new_skill_button_pressed.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_is_new_stats_button_pressed.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_screen_open_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_screen_shift_x.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client\d2client_screen_shift_y.hpp
# End Source File
# End Group
# Begin Group "d2cmp_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2common_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2common\d2common_global_belts_txt.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2common\d2common_global_inventory_txt.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2common\d2common_global_inventory_txt_records_count.hpp
# End Source File
# End Group
# Begin Group "d2ddraw_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw\d2ddraw_bit_block_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw\d2ddraw_bit_block_width.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw\d2ddraw_cel_display_left.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw\d2ddraw_cel_display_right.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw\d2ddraw_display_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw\d2ddraw_display_width.hpp
# End Source File
# End Group
# Begin Group "d2direct3d_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2direct3d\d2direct3d_display_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2direct3d\d2direct3d_display_width.hpp
# End Source File
# End Group
# Begin Group "d2game_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2gdi_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gdi\d2gdi_bit_block_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gdi\d2gdi_bit_block_width.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gdi\d2gdi_cel_display_left.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gdi\d2gdi_cel_display_right.hpp
# End Source File
# End Group
# Begin Group "d2gfx_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gfx\d2gfx_is_windowed_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gfx\d2gfx_resolution_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gfx\d2gfx_video_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gfx\d2gfx_window_handle.hpp
# End Source File
# End Group
# Begin Group "d2glide_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2glide\d2glide_display_height.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2glide\d2glide_display_width.hpp
# End Source File
# End Group
# Begin Group "d2lang_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2launch_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2mcpclient_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2multi_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2net_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2sound_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2win_variable_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2win\d2win_main_menu_mouse_position_x.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2win\d2win_main_menu_mouse_position_y.hpp
# End Source File
# End Group
# Begin Group "fog_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "storm_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\bnclient_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2client_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2cmp_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2common_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2ddraw_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2direct3d_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2game_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gdi_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2gfx_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2glide_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2lang_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2launch_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2mcpclient_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2multi_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2net_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2sound_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\d2win_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\fog_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable\storm_variable.hpp
# End Source File
# End Group
# Begin Group "helper_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\sgd2mapi98\helper\d2_determine_video_mode.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\sgd2mapi98\default_game_library.hpp
# End Source File
# Begin Source File

SOURCE=.\include\dllexport_define.inc
# End Source File
# Begin Source File

SOURCE=.\include\dllexport_undefine.inc
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\file.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_address.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_bool.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_branch_type.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_executable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_function.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_patch.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_undefined.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\game_version.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98\helper.hpp
# End Source File
# Begin Source File

SOURCE=.\include\sgd2mapi98.hpp
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "file_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\file\file_pe_signature.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\file\file_version_info.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\file\fixed_file_version.cpp
# End Source File
# End Group
# Begin Group "game_constant_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_client_game_type.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_difficulty_level.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_draw_effect.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_screen_open_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_text_color.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_text_font.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_constant\d2_video_mode.cpp
# End Source File
# End Group
# Begin Group "game_function_cpp"

# PROP Default_Filter ""
# Begin Group "bnclient_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2client_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2client\d2client_draw_centered_unicode_text.cpp
# End Source File
# End Group
# Begin Group "d2cmp_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2cmp\d2cmp_get_cel_from_cel_context.cpp
# End Source File
# End Group
# Begin Group "d2common_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2common\d2common_get_global_belt_record.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2common\d2common_get_global_belt_slot_position.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2common\d2common_get_global_equipment_slot_layout.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2common\d2common_get_global_inventory_grid_layout.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2common\d2common_get_global_inventory_position.cpp
# End Source File
# End Group
# Begin Group "d2ddraw_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2direct3d_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2game_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2gdi_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2gfx_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2gfx\d2gfx_draw_cel_context.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2gfx\d2gfx_draw_rectangle.cpp
# End Source File
# End Group
# Begin Group "d2glide_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2lang_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2lang\d2lang_get_string_by_index.cpp
# End Source File
# End Group
# Begin Group "d2launch_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2mcpclient_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2multi_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2net_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2sound_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2win_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_draw_unicode_text.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_get_pop_up_unicode_text_width_and_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_get_unicode_text_draw_width.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_get_unicode_text_n_draw_width.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_load_cel_file.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_load_mpq.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_set_pop_up_unicode_text.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_set_unicode_text_font.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_unload_cel_file.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\d2win\d2win_unload_mpq.cpp
# End Source File
# End Group
# Begin Group "fog_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\fog\fog_alloc_client_memory.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\fog\fog_free_client_memory.cpp
# End Source File
# End Group
# Begin Group "storm_function_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\storm\storm_s_file_close_archive.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_function\storm\storm_s_file_open_archive.cpp
# End Source File
# End Group
# End Group
# Begin Group "game_struct_cpp"

# PROP Default_Filter ""
# Begin Group "d2_belt_record_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_belt_record\d2_belt_record_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_cel_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel\d2_cel_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel\d2_cel_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_cel_context_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel_context\d2_cel_context_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_cel_file_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_cel_file\d2_cel_file_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_equipment_layout_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_equipment_layout\d2_equipment_layout_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_grid_layout_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_grid_layout\d2_grid_layout_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_inventory_record_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_inventory_record\d2_inventory_record_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_mpq_archive_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_mpq_archive\d2_mpq_archive_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_mpq_archive\d2_mpq_archive_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_mpq_archive_handle_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_positional_rectangle_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_struct\d2_positional_rectangle\d2_positional_rectangle_wrapper.cpp
# End Source File
# End Group
# End Group
# Begin Group "game_variable_cpp"

# PROP Default_Filter ""
# Begin Group "bnclient_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\bnclient\bnclient_gateway_domain_name.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\bnclient\bnclient_gateway_ip_v4_address.cpp
# End Source File
# End Group
# Begin Group "d2client_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_difficulty_level.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_game_type.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_general_display_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_general_display_width.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_general_play_area_camera_shift_x.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_ingame_mouse_position_x.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_ingame_mouse_position_y.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_inventory_arrange_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_is_automap_open.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_is_game_menu_open.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_is_help_screen_open.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_is_new_skill_button_pressed.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_is_new_stats_button_pressed.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_screen_open_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_screen_shift_x.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2client\d2client_screen_shift_y.cpp
# End Source File
# End Group
# Begin Group "d2cmp_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2common_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2common\d2common_global_belts_txt.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2common\d2common_global_inventory_txt.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2common\d2common_global_inventory_txt_records_count.cpp
# End Source File
# End Group
# Begin Group "d2ddraw_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2ddraw\d2ddraw_bit_block_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2ddraw\d2ddraw_bit_block_width.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2ddraw\d2ddraw_cel_display_left.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2ddraw\d2ddraw_cel_display_right.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2ddraw\d2ddraw_display_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2ddraw\d2ddraw_display_width.cpp
# End Source File
# End Group
# Begin Group "d2direct3d_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2direct3d\d2direct3d_display_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2direct3d\d2direct3d_display_width.cpp
# End Source File
# End Group
# Begin Group "d2game_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2gdi_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gdi\d2gdi_bit_block_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gdi\d2gdi_bit_block_width.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gdi\d2gdi_cel_display_left.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gdi\d2gdi_cel_display_right.cpp
# End Source File
# End Group
# Begin Group "d2gfx_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gfx\d2gfx_is_windowed_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gfx\d2gfx_resolution_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gfx\d2gfx_video_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2gfx\d2gfx_window_handle.cpp
# End Source File
# End Group
# Begin Group "d2glide_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2glide\d2glide_display_height.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2glide\d2glide_display_width.cpp
# End Source File
# End Group
# Begin Group "d2lang_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2launch_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2mcpclient_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2multi_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2net_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2sound_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2win_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2win\d2win_main_menu_mouse_position_x.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_variable\d2win\d2win_main_menu_mouse_position_y.cpp
# End Source File
# End Group
# Begin Group "fog_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "storm_variable_cpp"

# PROP Default_Filter ""
# End Group
# End Group
# Begin Group "helper_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\sgd2mapi98\helper\d2_determine_video_mode.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\sgd2mapi98\default_game_library.cpp
# End Source File
# Begin Source File

SOURCE=.\src\dll_main.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_address.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_executable.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_patch.cpp
# End Source File
# Begin Source File

SOURCE=.\src\sgd2mapi98\game_version.cpp
# End Source File
# End Group
# End Group
# End Target
# End Project
