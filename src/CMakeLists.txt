cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project("SGD2MAPIc")

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
    # add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
    # target_compile_definitions(${PROJECT_NAME}
    #     INTERFACE SGD2MAPI_C_DLLIMPORT
    #     PRIVATE SGD2MAPI_C_DLLEXPORT)
else()
    # add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif()

target_include_directories(
    ${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_SOURCE_DIR}")

# target_link_libraries(${PROJECT_NAME} PUBLIC MDCc shlwapi version)

add_subdirectory("sgd2mapi")
