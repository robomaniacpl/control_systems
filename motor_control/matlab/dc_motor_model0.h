/*
 * File: dc_motor_model0.h
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

#ifndef RTW_HEADER_dc_motor_model0_h_
#define RTW_HEADER_dc_motor_model0_h_
#ifndef dc_motor_model0_COMMON_INCLUDES_
# define dc_motor_model0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* dc_motor_model0_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T Velocity_states[2];           /* '<S1>/Velocity' */
  real_T Current_states[2];            /* '<S1>/Current' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T control;                      /* '<Root>/control' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T velocity;                     /* '<Root>/velocity' */
  real_T current;                      /* '<Root>/current' */
} ExtY;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void dc_motor_model0_initialize(void);
extern void dc_motor_model0_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('dc_motor_model_simulink/dc_motor_model')    - opens subsystem dc_motor_model_simulink/dc_motor_model
 * hilite_system('dc_motor_model_simulink/dc_motor_model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'dc_motor_model_simulink'
 * '<S1>'   : 'dc_motor_model_simulink/dc_motor_model'
 */
#endif                                 /* RTW_HEADER_dc_motor_model0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
