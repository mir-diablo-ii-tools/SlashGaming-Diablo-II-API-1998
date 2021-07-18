cmake_minimum_required(VERSION 3.10)

project(SGD2MAPI98)

if (MSVC)
    add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif (MSVC)

add_subdirectory(third_party)
add_subdirectory(SGD2MAPIc)
add_subdirectory(SGD2MAPIcxx98)
