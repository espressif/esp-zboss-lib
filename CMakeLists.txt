cmake_minimum_required(VERSION 3.16)

idf_component_register(
    INCLUDE_DIRS include
)

if(CONFIG_ZB_ENABLED)

    set(ZBOSS_LIBS "")
    if(CONFIG_ZB_ZCZR)
        add_prebuilt_library(zboss_stack_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_stack.zczr.a")
    elseif(CONFIG_ZB_ZED)
        add_prebuilt_library(zboss_stack_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_stack.ed.a")
    elseif(CONFIG_ZB_RCP)
        add_prebuilt_library(zboss_stack_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_stack.rcp.a")
    endif()
    if(IDF_TARGET STREQUAL "esp32h2")
    if(CONFIG_IDF_TARGET_ESP32H2_BETA_VERSION_1)
    add_prebuilt_library(zboss_port_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/rev1/libzboss_port.a"
                             PRIV_REQUIRES ieee802154 efuse esp_system esp_hw_support)
    endif()
    if(CONFIG_IDF_TARGET_ESP32H2_BETA_VERSION_2)
    add_prebuilt_library(zboss_port_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/rev2/libzboss_port.a"
                             PRIV_REQUIRES ieee802154 efuse esp_system esp_hw_support)
    endif()

    else()
    add_prebuilt_library(zboss_port_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_port.a"
                             PRIV_REQUIRES ieee802154 efuse esp_system esp_hw_support)
    endif()
    list(APPEND ZBOSS_LIBS zboss_stack_lib zboss_port_lib)

    target_link_libraries(${COMPONENT_LIB} INTERFACE ${ZBOSS_LIBS})
    target_compile_options(${COMPONENT_LIB} INTERFACE "-Wno-strict-prototypes")
endif()
