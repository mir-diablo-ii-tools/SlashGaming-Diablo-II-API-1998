target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_cel_context.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_rectangle.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_cel_context.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_rectangle.h")
