target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2direct3d_display_height.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2direct3d_display_width.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2direct3d_display_height.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2direct3d_display_width.h")
