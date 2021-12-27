cmake_minimum_required(VERSION 3.5)

idf_component_register(
    INCLUDE_DIRS include
)

if(CONFIG_ZB_ENABLED)
    idf_component_get_property(esp_hw_support_lib esp_hw_support COMPONENT_LIB)

    target_link_libraries(${COMPONENT_LIB} INTERFACE "-L ${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}")

    set(ZBOSS_LIBS "")
    if(CONFIG_ZB_ZCZR)
        list(APPEND ZBOSS_LIBS libzboss_stack.zczr.a)
    elseif(CONFIG_ZB_ZED)
        list(APPEND ZBOSS_LIBS libzboss_stack.ed.a)
    elseif(CONFIG_ZB_RCP)
        list(APPEND ZBOSS_LIBS libzboss_stack.rcp.a)
    endif()

    list(APPEND ZBOSS_LIBS libzboss_port.a)

    target_link_libraries(${COMPONENT_LIB} INTERFACE ${ZBOSS_LIBS} $<TARGET_FILE:${esp_hw_support_lib}>)
endif()
