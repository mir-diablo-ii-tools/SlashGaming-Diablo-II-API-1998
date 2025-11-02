target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2glide_display_height.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2glide_display_width.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2glide_display_height.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2glide_display_width.hpp")
