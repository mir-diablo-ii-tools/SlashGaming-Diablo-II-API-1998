target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_close_archive.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_open_archive.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_close_archive.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/storm_s_file_open_archive.hpp")
