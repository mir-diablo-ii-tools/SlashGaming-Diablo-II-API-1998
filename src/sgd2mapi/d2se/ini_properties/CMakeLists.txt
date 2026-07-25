target_sources(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/user_settings_section.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/user_settings_section.c")


add_subdirectory("protected_section")
add_subdirectory("user_settings_section")
