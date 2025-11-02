target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_cel_context.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_rectangle.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_cel_context.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2gfx_draw_rectangle.hpp")
