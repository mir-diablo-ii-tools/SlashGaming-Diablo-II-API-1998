target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/file_version_info.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/fixed_file_version.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/file_version_info.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/fixed_file_version.h")
