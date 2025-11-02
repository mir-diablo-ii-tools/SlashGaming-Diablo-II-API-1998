target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/bnclient_gateway_domain_name.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/bnclient_gateway_ip_v4_address.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/bnclient_gateway_domain_name.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/bnclient_gateway_ip_v4_address.hpp")
