target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/dll_main.c"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/sgd2mapi98.h")

add_subdirectory("sgd2mapi98")
