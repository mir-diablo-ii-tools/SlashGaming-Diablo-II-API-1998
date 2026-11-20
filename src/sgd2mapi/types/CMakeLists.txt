cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project("SGD2MAPIc.Types")

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
add_library(${PROJECT_NAME} INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/undefined.h")

add_subdirectory("d2")

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)

target_include_directories(
    ${PROJECT_NAME} INTERFACE "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME} INTERFACE MDCc)
