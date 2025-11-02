target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_close_archive.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_open_archive.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_close_archive.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_open_archive.h")
