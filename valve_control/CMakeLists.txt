add_executable(valve_control valve_control.c)
set_target_properties(valve_control
        PROPERTIES
        LINK_FLAGS  "-Wl,--wrap=valve_tank,--wrap=valve_ambient"
        )

target_link_libraries(valve_control cmocka)