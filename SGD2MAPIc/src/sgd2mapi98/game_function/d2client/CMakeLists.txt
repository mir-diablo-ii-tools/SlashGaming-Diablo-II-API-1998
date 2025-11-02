target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2client_draw_centered_unicode_text.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2client_draw_centered_unicode_text_shim.asm"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2client_draw_centered_unicode_text.h")
