cmake_minimum_required(VERSION 3.20)

project("Tests.SGD2MAPIc.Version")

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

unset(CMAKE_CXX_STANDARD)
unset(CMAKE_CXX_STANDARD_REQUIRED)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# Define test targets
add_executable(${PROJECT_NAME}
    "${CMAKE_CURRENT_SOURCE_DIR}/version_tests.c")

target_compile_definitions(${PROJECT_NAME} PRIVATE NOMINMAX)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/tests"
        "${CMAKE_SOURCE_DIR}/third_party/cutest-1.5")
target_link_libraries(${PROJECT_NAME} PRIVATE SGD2MAPIc.Core SGD2MAPIc.D2SE SGD2MAPIc.Version CuTest)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
