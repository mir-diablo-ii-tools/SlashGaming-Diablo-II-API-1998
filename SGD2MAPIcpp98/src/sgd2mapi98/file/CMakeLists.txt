target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/file_version_info.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/fixed_file_version.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/file_version_info.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/fixed_file_version.hpp")
