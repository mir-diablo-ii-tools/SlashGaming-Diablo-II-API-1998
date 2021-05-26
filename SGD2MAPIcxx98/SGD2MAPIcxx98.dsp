# Microsoft Developer Studio Project File - Name="SGD2MAPIcxx98" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=SGD2MAPIcxx98 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SGD2MAPIcxx98.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SGD2MAPIcxx98.mak" CFG="SGD2MAPIcxx98 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SGD2MAPIcxx98 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "SGD2MAPIcxx98 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "SGD2MAPIcxx98 - Win32 Release Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SGD2MAPIcxx98 - Win32 Debug Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "SGD2MAPIcxx98 - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "SGD2MAPIcxx98 - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "SGD2MAPIcxx98 - Win32 Release Dll"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_USRDLL" /D "SGD2MAPICXX98_DLLEXPORT" /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"ReleaseDll/SGD2MAPIcxx98Dll.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 libunicows.lib MDCc.lib SGD2MAPIcDDll.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"ReleaseDll/SGD2MAPIcDll.dll"

!ELSEIF  "$(CFG)" == "SGD2MAPIcxx98 - Win32 Debug Dll"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_USRDLL" /D "SGD2MAPICXX98_DLLEXPORT" /YX /FD /GZ /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"DebugDll/SGD2MAPIcxx98DDll.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib MDCcD.lib SGD2MAPIcDDll.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"DebugDll/SGD2MAPIcxx98DDll.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SGD2MAPIcxx98 - Win32 Release"
# Name "SGD2MAPIcxx98 - Win32 Debug"
# Name "SGD2MAPIcxx98 - Win32 Release Dll"
# Name "SGD2MAPIcxx98 - Win32 Debug Dll"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "game_constant_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_client_game_type.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_difficulty_level.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_draw_effect.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_screen_open_mode.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_text_color.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_text_font.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_constant\d2_video_mode.hpp
# End Source File
# End Group
# Begin Group "game_function_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "game_struct_hpp"

# PROP Default_Filter ""
# Begin Group "d2_belt_record_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_belt_record\d2_belt_record_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_belt_record\d2_belt_record_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_belt_record\d2_belt_record_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_belt_record\d2_belt_record_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_cel_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_cel\d2_cel_struct.hpp
# End Source File
# End Group
# Begin Group "d2_cel_context_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_cel_context\d2_cel_context_struct.hpp
# End Source File
# End Group
# Begin Group "d2_cel_file_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_cel_file\d2_cel_file_struct.hpp
# End Source File
# End Group
# Begin Group "d2_equipment_layout_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_grid_layout_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_grid_layout\d2_grid_layout_struct.hpp
# End Source File
# End Group
# Begin Group "d2_inventory_record_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_inventory_record\d2_inventory_record_struct.hpp
# End Source File
# End Group
# Begin Group "d2_mpq_archive_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_mpq_archive\d2_mpq_archive_struct.hpp
# End Source File
# End Group
# Begin Group "d2_mpq_archive_handle_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_mpq_archive_handle\d2_mpq_archive_handle_struct.hpp
# End Source File
# End Group
# Begin Group "d2_positional_rectangle_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_api.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_struct.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_view.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_wrapper.hpp
# End Source File
# End Group
# Begin Group "d2_unicode_char_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_unicode_char\d2_unicode_char_struct.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_belt_record.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_cel.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_cel_context.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_cel_file.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_equipment_layout.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_grid_layout.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_inventory_record.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_mpq_archive.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_mpq_archive_handle.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_positional_rectangle.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_struct\d2_unicode_char.hpp
# End Source File
# End Group
# Begin Group "game_variable_hpp"

# PROP Default_Filter ""
# End Group
# Begin Group "helper_hpp"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\include\cxx98\default_game_library.hpp
# End Source File
# Begin Source File

SOURCE=.\include\dllexport_define.inc
# End Source File
# Begin Source File

SOURCE=.\include\dllexport_undefine.inc
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_address.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_bool.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_branch_type.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_executable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_patch.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_undefined.hpp
# End Source File
# Begin Source File

SOURCE=.\include\cxx98\game_version.hpp
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "game_constant_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_client_game_type.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_difficulty_level.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_draw_effect.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_screen_open_mode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_text_color.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_text_font.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_constant\d2_video_mode.cpp
# End Source File
# End Group
# Begin Group "game_function_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "game_struct_cpp"

# PROP Default_Filter ""
# Begin Group "d2_belt_record_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_belt_record\d2_belt_record_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_belt_record\d2_belt_record_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_belt_record\d2_belt_record_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_cel_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_cel_context_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_cel_file_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_equipment_layout_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_equipment_layout\d2_equipment_layout_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_grid_layout_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_inventory_record_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_mpq_archive_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_mpq_archive_handle_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "d2_positional_rectangle_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_api.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_view.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_struct\d2_positional_rectangle\d2_positional_rectangle_wrapper.cpp
# End Source File
# End Group
# Begin Group "d2_unicode_char_cpp"

# PROP Default_Filter ""
# End Group
# End Group
# Begin Group "game_variable_cpp"

# PROP Default_Filter ""
# End Group
# Begin Group "helper_cpp"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\src\cxx98\default_game_library.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_address.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_executable.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_patch.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cxx98\game_version.cpp
# End Source File
# End Group
# End Group
# End Target
# End Project
