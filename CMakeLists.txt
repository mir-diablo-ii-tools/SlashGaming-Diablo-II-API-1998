cmake_minimum_required(VERSION 3.10)

project(SGD2MAPI98)

if (MSVC)
    add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif (MSVC)

add_subdirectory(third_party)
add_subdirectory(SGD2MAPIc)
add_subdirectory(SGD2MAPIcpp98)
add_subdirectory("src")

# Tests
option(ENABLE_SGD2MAPIc_TESTS "Enable tests" OFF)
if (ENABLE_SGD2MAPIc_TESTS)
    enable_testing()
    add_subdirectory("tests")
endif (ENABLE_SGD2MAPIc_TESTS)
