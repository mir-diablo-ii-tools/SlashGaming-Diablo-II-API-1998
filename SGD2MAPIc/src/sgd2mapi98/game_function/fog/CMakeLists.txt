target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_alloc_client_memory.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_free_client_memory.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_alloc_client_memory.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_free_client_memory.h")
