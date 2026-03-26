target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_signature.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_timestamp.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_signature.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/pe_timestamp.c")
