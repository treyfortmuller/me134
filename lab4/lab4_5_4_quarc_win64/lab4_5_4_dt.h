/*
 * lab4_5_4_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab4_5_4".
 *
 * Model version              : 1.15
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Feb 28 13:43:27 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&lab4_5_4_B.Clock), 0, 0, 5 }
  ,

  { (char_T *)(&lab4_5_4_DW.HILInitialize1_AIMinimums[0]), 0, 0, 24 },

  { (char_T *)(&lab4_5_4_DW.HILInitialize1_Card), 14, 0, 1 },

  { (char_T *)(&lab4_5_4_DW.ToWorkspace2_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&lab4_5_4_DW.HILInitialize1_QuadratureModes[0]), 6, 0, 10 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&lab4_5_4_P.K), 0, 0, 2 },

  { (char_T *)(&lab4_5_4_P.HILReadEncoder_channels[0]), 7, 0, 3 },

  { (char_T *)(&lab4_5_4_P.HILInitialize1_OOTerminate), 0, 0, 20 },

  { (char_T *)(&lab4_5_4_P.HILInitialize1_CKChannels[0]), 6, 0, 7 },

  { (char_T *)(&lab4_5_4_P.HILInitialize1_AIChannels[0]), 7, 0, 13 },

  { (char_T *)(&lab4_5_4_P.HILInitialize1_Active), 8, 0, 37 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] lab4_5_4_dt.h */
