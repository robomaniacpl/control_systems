//
// Created by lukas on 03/10/18.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "double_setpoint_controller.h"
#include "matlab/valves.h"

float pressure_actual = 0;
bool pressure_up = false;
float pressure_step = 0.1;

void valve_tank(int is_on);
void valve_ambient(int is_on);
void valve_control_loop(int printing_format);
void gripper(float control);

int main(int argc, char **argv)
{
    if(argc == 4)
    {
        set_a(atof(argv[2]));
        set_H(atof(argv[3]));
        valve_control_loop(atoi(argv[1]));

    }
    return 0;
}

void valve_control_loop(int printing_format)
{
    // printf("Error, Control , Pressure Demand, Pressure Actual\n");
    if(printing_format == 1)
        printf("Error, Control\n");
    else if(printing_format == 2)
        printf("Time, Pressure Demand, Pressure Actual\n");
    else if(printing_format == 3)
        printf("Time, Control\n");


    float pressure_demand = 2;
    pressure_actual = 0;
    float error = 100;
    int control = 0;
    float time;
    float dtime = 0.01;
    float timeEnd = 20;


    for(time=0;time<timeEnd;time+=dtime)
    {
        if(time>=4)
        {
            pressure_demand = 0;
        }
        if(time>=12)
        {
            pressure_demand = 9;
        }
        if(time>=16)
        {
            pressure_demand = 0;
        }

        error = pressure_demand-pressure_actual;

        control = double_setpoint_controller(error, control);

        gripper(control);

        pressure_actual-=0.01; //disturbaces

        if(printing_format == 1)
            printf("%.2f,%d\n", error, control);
        else if(printing_format == 2)
            printf("%.2f,%.2f,%.2f\n", time, pressure_demand, pressure_actual);
        else if(printing_format == 3)
            printf("%.2f,%d\n", time, control);
    }
}

void gripper(float control)
{
    // if(control == 1)
    // {
    //     valve_tank(1);
    //     valve_ambient(0);
    // }
    // else if (control == -1)
    // {
    //     valve_tank(0);
    //     valve_ambient(1);
    // }
    // else
    // {
    //     valve_tank(0);
    //     valve_ambient(0);
    // }
    rtU.control = control;
    valves_step();
    pressure_actual = rtY.actual_pressure;
    // if(pressure_up)
    //     pressure_actual+=pressure_step;
    // else
    //     pressure_actual-=pressure_step;
}

void valve_tank(int is_on){
    if(is_on)
        // pressure_up = true;
        pressure_actual+=pressure_step;
}
void valve_ambient(int is_on){
    if(is_on)
        // pressure_up = false;
        pressure_actual-=pressure_step;
}
