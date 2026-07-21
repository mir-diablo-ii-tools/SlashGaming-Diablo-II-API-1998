target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/enable_hc_test.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/enable_plugy_test.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/no_sound_test.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/renderer_test.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/window_mode_test.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/enable_hc_test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/enable_plugy_test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/no_sound_test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/renderer_test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/window_mode_test.c")

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
