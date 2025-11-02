target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/game_version_file_pe_signature.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_version_file_version.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/game_version_file_pe_signature.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_version_file_version.h")
