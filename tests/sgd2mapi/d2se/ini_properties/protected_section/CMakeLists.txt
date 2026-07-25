target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/d2core_test.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/d2core_test.c")

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
