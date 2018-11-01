

#include "double_setpoint_controller.h"


static float s_a = 0.2;
static float s_H = 0.5;

int double_setpoint_controller(float error, int control)
{

    if((error > s_a+s_H) || (error > s_a && control == 1))
    {
        control = 1;
    } else if((error < -s_a-s_H) || (error < -s_a && control == -1))
    {
        control = -1;
    } else
    {
        control = 0;
    }


    return control;
}

void set_a(float a)
{
    s_a = a;
}

void set_H(float H)
{
    s_H = H;
}
