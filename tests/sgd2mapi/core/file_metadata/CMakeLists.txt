target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_signature_tests.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_timestamp_tests.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_signature_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_timestamp_tests.c")

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
