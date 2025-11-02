target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/architecture_opcode.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_address_table.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/architecture_opcode.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_address_table.h")

add_subdirectory("d2se")
add_subdirectory("game_address_table")
add_subdirectory("game_function")
add_subdirectory("game_version")
