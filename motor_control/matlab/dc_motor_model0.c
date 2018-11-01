/*
 * File: dc_motor_model0.c
 *
 * Code generated for Simulink model 'dc_motor_model0'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Oct 30 22:31:58 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "dc_motor_model0.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Model step function */
void dc_motor_model0_step(void)
{
  real_T rtb_Velocity;
  real_T rtb_Current;

  /* Outport: '<Root>/position' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  rtY.position = rtDW.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteTransferFcn: '<S1>/Velocity' */
  rtb_Velocity = 0.4698 * rtDW.Velocity_states[0] + 0.03616 *
    rtDW.Velocity_states[1];

  /* Outport: '<Root>/velocity' */
  rtY.velocity = rtb_Velocity;

  /* Outport: '<Root>/current' incorporates:
   *  DiscreteTransferFcn: '<S1>/Current'
   */
  rtY.current = 0.2209 * rtDW.Current_states[0] + 1.902E-5 *
    rtDW.Current_states[1];

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/control'
   */
  if (rtU.control > 12.0) {
    rtb_Current = 12.0;
  } else if (rtU.control < -12.0) {
    rtb_Current = -12.0;
  } else {
    rtb_Current = rtU.control;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += rtb_Velocity;

  /* Update for DiscreteTransferFcn: '<S1>/Velocity' */
  rtb_Velocity = (rtb_Current - -0.5819 * rtDW.Velocity_states[0]) - 8.944E-6 *
    rtDW.Velocity_states[1];
  rtDW.Velocity_states[1] = rtDW.Velocity_states[0];
  rtDW.Velocity_states[0] = rtb_Velocity;

  /* Update for DiscreteTransferFcn: '<S1>/Current' */
  rtb_Velocity = (rtb_Current - -0.5819 * rtDW.Current_states[0]) - 8.944E-6 *
    rtDW.Current_states[1];
  rtDW.Current_states[1] = rtDW.Current_states[0];
  rtDW.Current_states[0] = rtb_Velocity;
}

/* Model initialize function */
void dc_motor_model0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
