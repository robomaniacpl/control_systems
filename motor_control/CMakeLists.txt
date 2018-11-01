

add_executable(motor_control motor_control.c matlab/dc_motor_model0.c
        cmsis/arm_pid_init_f32.c)
target_link_libraries(motor_control m)
