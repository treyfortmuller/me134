/*
 * lab4_5_1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab4_5_1".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Feb 28 12:31:52 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab4_5_1.h"
#include "lab4_5_1_private.h"

/* Block parameters (auto storage) */
P_lab4_5_1_T lab4_5_1_P = {
  100.0,                               /* Variable: K
                                        * Referenced by: '<Root>/Gain'
                                        */
  44000.0,                             /* Variable: res_a
                                        * Referenced by: '<Root>/Gain1'
                                        */

  /*  Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },
  0U,                                  /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  10.0,                                /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  -10.0,                               /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  10.0,                                /* Expression: analog_output_maximums
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  -10.0,                               /* Expression: analog_output_minimums
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: initial_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1.6666666666666668E+7,               /* Expression: encoder_filter_frequency
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  16276.041666666668,                  /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<Root>/Step'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -6.0,                                /* Expression: -6
                                        * Referenced by: '<Root>/Saturation'
                                        */

  /*  Computed Parameter: HILInitialize1_CKChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0, 1 },

  /*  Computed Parameter: HILInitialize1_CKModes
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0, 0 },
  2,                                   /* Computed Parameter: HILInitialize1_DOWatchdog
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_EIInitial
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_POModes
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */

  /*  Computed Parameter: HILInitialize1_AIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize1_AOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize1_EIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U },
  4U,                                  /* Computed Parameter: HILInitialize1_EIQuadrature
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_Active
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_AOTerminate
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_AOExit
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_DOTerminate
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_DOExit
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_POTerminate
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_POExit
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_CKPStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_CKPEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_CKStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_CKEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_AIPStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_AIPEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_AOPStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_AOPEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_AOStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_AOEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_AOReset
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_DOPStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_DOPEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_DOStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_DOEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_DOReset
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_EIPStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_EIPEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_EIStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_EIEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_POPStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_POPEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_POStart
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_POEnter
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_POReset
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  0,                                   /* Computed Parameter: HILInitialize1_OOReset
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_DOFinal
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILInitialize1_DOInitial
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<Root>/HIL Read Encoder'
                                        */
  0                                    /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
};
