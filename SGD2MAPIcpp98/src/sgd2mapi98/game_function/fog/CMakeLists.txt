target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_alloc_client_memory.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_free_client_memory.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_alloc_client_memory.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/fog_free_client_memory.hpp")
