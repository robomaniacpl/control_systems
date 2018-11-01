//
// Created by lukas on 12/10/18.
//

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include "matlab/dc_motor_model0.h"
#include "cmsis/arm_math.h"


void twiddle(float threshold, int current_loop);
float motor_control_loop(float sim_time, float demand_position, float parameters[3], int print_flag, int current_loop);
void step(float control);

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        step(1);
    }
    if( argc== 3 )
    {
        printf("Start Twiddle algorith with parameter %s\n", argv[1]);
        dc_motor_model0_initialize();
        twiddle(atof(argv[2]), atoi(argv[1]));
    }
    if( argc == 6)
    {
        float demand_position = 1;
        float parameters[3] = {atof(argv[3]),atof(argv[4]),atof(argv[5])};

        dc_motor_model0_initialize();
        motor_control_loop(atof(argv[2]), demand_position, parameters, 1, atoi(argv[1]));
//        printf("Error = %f\n", error);
    }



    return 0;
}

void twiddle(float threshold, int current_loop)
{
    float p[3] = {0,0,0};
    float dp[3] = {1,1,1};
    float best_err = motor_control_loop(2, 10, p, 0, current_loop);
    float err = 0;
    int n = 0;

    while( (dp[0]+dp[1]+dp[2]) > threshold)
    {
        printf("Twiddle # %d: %.4f %.4f %.4f -> %f\n", n, p[0], p[1], p[2], best_err);
//        printf("dp %f\n", dp[0]+dp[1]+dp[2]);

        for(int i = 0; i<3; ++i)
        {
            p[i] += dp[i];
            err = motor_control_loop(2, 10, p, 0, current_loop);

            if(err < best_err)
            {
                best_err = err;
                dp[i] *= 1.1;
            }
            else
            {
                p[i] -= 2*dp[i];
                err = motor_control_loop(2, 10, p, 0, current_loop);

                if(err < best_err)
                {
                    best_err = err;
                    dp[i] *= 1.1;
                }
                else
                {
                    p[i] += dp[1];
                    dp[i] *= 0.9;
                }
            }
        }
        n++;
    }
}


float motor_control_loop(float sim_time, float demand_position,float parameters[3], int print_flag, int current_loop) {
    if(print_flag == 1)
        printf("Time (seconds), Demand Position(rad), Actual Position (rad), Control, Error\n");

    arm_pid_instance_f32 velocity_linear_pid;

    velocity_linear_pid.Kp = parameters[0];
    velocity_linear_pid.Ki = parameters[1];
    velocity_linear_pid.Kd = parameters[2];

    arm_pid_init_f32(&velocity_linear_pid,1);

    float actual_position = 0;  // (rad)
//    float actual_velocity = 0;
    float error;                // (rad)
    float control = 0;              // (volt)
    float dtime = 0.001;        // (sec)
    float timeEnd = sim_time;        // (sec)
    float time = 0;             // (sec)
    float error_total = 0;
//    int N = (int)timeEnd/dtime;

    while(time < timeEnd)
    {

        error = demand_position-actual_position;

        //PID control
        if(((int)(time*1000)%10) == 0) // 10ms control loop
        {
            control = arm_pid_f32(&velocity_linear_pid, error);
        }

        rtU.control = control;

        dc_motor_model0_step();

        if(current_loop)
            actual_position = rtY.current;
        else
            actual_position = rtY.position;

        if(print_flag == 1)
            printf("%.3f,%.2f,%.2f,%.2f,%.2f\n", time, demand_position, actual_position, control,error);

        error_total += pow(error,2);
        time += dtime;
    }
//    if(print_flag == 0)
//        printf("Error %f\n", error_total/500);


    return error_total/2000;
}


void step(float control)
{
    printf("Time (seconds), Actual Position(rad), Actual Velocity (rad/s), Actual Current (A), Control (V)\n");

    float actual_position = 0;  // (rad)
    float actual_velocity = 0;
    float actual_current = 0;
//    float actual_velocity = 0;
    float dtime = 0.001;        // (sec)
    float timeEnd = 0.5;        // (sec)
    float time = 0;             // (sec)

    while(time < timeEnd)
    {
        rtU.control = control;
        dc_motor_model0_step();
        actual_position = rtY.position;
        actual_velocity = rtY.velocity;
        actual_current  = rtY.current;
//        actual_velocity = rtY.velocity;
//        printf("e: %.2f, u: %d, pd: %.2f, pa: %.2f\n", error, control, pressure_demand, pressure_actual);
//        printf("%.2f,%.2f,%.2f,%.2f\n", error, control, demand_position, actual_position);
        printf("%.3f,%.2f,%.2f,%.2f,%.2f\n", time, actual_position, actual_velocity, actual_current,control);

        time += dtime;
    }

}
