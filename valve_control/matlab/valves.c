/*
 * File: valves.c
 *
 * Code generated for Simulink model 'valves'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Nov  1 22:34:00 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "valves.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Model step function */
void valves_step(void)
{
  /* Outport: '<Root>/actual_pressure' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
   */
  rtY.actual_pressure = 0.0001 * rtDW.DiscreteTransferFcn_states;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  rtDW.DiscreteTransferFcn_states = rtDW.DiscreteTimeIntegrator_DSTATE - -0.999 *
    rtDW.DiscreteTransferFcn_states;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Update for Inport: '<Root>/control'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += rtU.control;
}

/* Model initialize function */
void valves_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
