/*
 * File: valves.h
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

#ifndef RTW_HEADER_valves_h_
#define RTW_HEADER_valves_h_
#ifndef valves_COMMON_INCLUDES_
# define valves_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* valves_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<Root>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T control;                      /* '<Root>/control' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T actual_pressure;              /* '<Root>/actual_pressure' */
} ExtY;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void valves_initialize(void);
extern void valves_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'valves'
 */
#endif                                 /* RTW_HEADER_valves_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
