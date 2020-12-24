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
# Begin Group "backend_game_function_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\c\backend\game_function\cdecl_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

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

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\esi_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

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

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\fastcall_function.asm

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

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

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\stdcall_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

!ELSEIF  "$(CFG)" == "SGD2MAPIc - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_function\thiscall_function.h

!IF  "$(CFG)" == "SGD2MAPIc - Win32 Release"

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

SOURCE=.\src\c\backend\game_library.cpp
# End Source File
# Begin Source File

SOURCE=.\src\c\backend\game_library.h
# End Source File
# End Group
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
