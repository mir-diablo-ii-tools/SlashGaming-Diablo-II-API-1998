target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/dll_main.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/sgd2mapi98.hpp")

add_subdirectory("sgd2mapi98")
