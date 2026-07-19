cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project("SGD2MAPIc.D2SE")

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable NASM
set(CMAKE_ASM_NASM_OBJECT_FORMAT win32)
enable_language(ASM_NASM)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# Build output
option(${PROJECT_NAME}_BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (${PROJECT_NAME}_BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED)
    target_compile_definitions(${PROJECT_NAME}
        INTERFACE SGD2MAPI_C_D2SE_DLLIMPORT
        PRIVATE SGD2MAPI_C_D2SE_DLLEXPORT)
else()
    add_library(${PROJECT_NAME} STATIC)
endif()

target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/exe_detect.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_c_define.inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_c_undef.inc"

        "${CMAKE_CURRENT_SOURCE_DIR}/exe_detect.c")

add_subdirectory("ini_properties")

if (MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -D_CRT_SECURE_NO_WARNINGS)
endif (MSVC)

target_include_directories(
    ${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        SGD2MAPIc.Core MDCc shlwapi version)
