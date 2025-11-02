target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/game_address_table_impl.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/game_address_table_define.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_address_table_impl.h")
