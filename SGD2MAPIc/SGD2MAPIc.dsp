# Microsoft Developer Studio Project File - Name="SGD2MAPIc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

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
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "SGD2MAPIc - Win32 Release"
# Name "SGD2MAPIc - Win32 Debug"
# Begin Group "Files"

# PROP Default_Filter ""
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

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\cdecl_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

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

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\esi_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

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

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\fastcall_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

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

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\stdcall_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

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

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\thiscall_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "backend_game_version_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\backend\game_version\file_signature.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_version\file_signature.h
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_version\file_version.c
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_version\file_version.h
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
# Begin Group "game_constant"

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
# Begin Source File

SOURCE=.\src\c\game_struct\d2_unicode_char.c
# End Source File
# End Group
# Begin Group "game_variable_c"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\src\c\default_game_library.c
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
# Begin Group "include"

# PROP Default_Filter ""
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
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_ascii_to_unicode.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strcat.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strcmp.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strcpy.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strlen.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strncat.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strncmp.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_strncpy.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_tolower.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_toupper.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_unicode_to_utf8.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_function\d2lang\d2lang_unicode_utf8_to_unicode.h
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
# Begin Source File

SOURCE=.\include\c\game_struct\d2_unicode_char.h
# End Source File
# End Group
# Begin Group "game_variable_h"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\include\d2api_version.h
# End Source File
# Begin Source File

SOURCE=.\include\c\default_game_library.h
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

SOURCE=.\include\c\game_undefined.h
# End Source File
# Begin Source File

SOURCE=.\include\c\game_version.h
# End Source File
# End Group
# End Group
# End Target
# End Project
