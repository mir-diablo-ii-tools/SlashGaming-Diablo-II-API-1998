target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/protected_section_test.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/user_settings_section_test.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/protected_section_test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/user_settings_section_test.c")

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory("protected_section")
add_subdirectory("user_settings_section")
