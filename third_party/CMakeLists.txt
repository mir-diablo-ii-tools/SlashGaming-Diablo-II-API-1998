cmake_minimum_required(VERSION 3.11)

include(FetchContent)

FetchContent_Declare(MDC
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/MDC"
)

FetchContent_MakeAvailable(MDC)

add_subdirectory("cutest-1.5")
