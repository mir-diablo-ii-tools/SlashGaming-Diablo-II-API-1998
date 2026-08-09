target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2converter_test.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2types_test.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2converter_test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/d2types_test.c")
