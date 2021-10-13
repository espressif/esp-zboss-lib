cmake_minimum_required(VERSION 3.5)

set(include_dirs
    )
set(src_dirs
    )

idf_component_register(SRC_DIRS "${src_dirs}"
                        INCLUDE_DIRS "${include_dirs}"      
)

if(CONFIG_ZB_ENABLED)

        target_include_directories(${COMPONENT_LIB} INTERFACE "include" "private_include")
        idf_component_get_property(esp_phy_lib esp_phy COMPONENT_LIB)
	idf_component_get_property(vfs_lib vfs COMPONENT_LIB)
        idf_component_get_property(esp_hw_support_lib esp_hw_support COMPONENT_LIB)
        add_prebuilt_library(zboss_port_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_port.a")
        if(CONFIG_ZB_ZCZR)
            add_prebuilt_library(zboss_stack_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_stack.zczr.a")
        else()
            add_prebuilt_library(zboss_stack_lib "${CMAKE_CURRENT_SOURCE_DIR}/lib/${idf_target}/libzboss_stack.ed.a")
        endif()
        target_link_libraries(${COMPONENT_LIB} INTERFACE -Wl,--start-group zboss_port_lib zboss_stack_lib -Wl,--end-group)
    	target_link_libraries(zboss_port_lib INTERFACE lib802154.a $<TARGET_FILE:${esp_phy_lib}> libphy.a libbtbb.a $<TARGET_FILE:${vfs_lib}> $<TARGET_FILE:${esp_hw_support_lib}>)

endif()
