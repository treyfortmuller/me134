/*
 * lab4_5_3_pulse.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab4_5_3_pulse".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Feb 28 13:06:55 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab4_5_3_pulse.h"
#include "lab4_5_3_pulse_private.h"
#include "lab4_5_3_pulse_dt.h"

/* Block signals (auto storage) */
B_lab4_5_3_pulse_T lab4_5_3_pulse_B;

/* Continuous states */
X_lab4_5_3_pulse_T lab4_5_3_pulse_X;

/* Block states (auto storage) */
DW_lab4_5_3_pulse_T lab4_5_3_pulse_DW;

/* Real-time model */
RT_MODEL_lab4_5_3_pulse_T lab4_5_3_pulse_M_;
RT_MODEL_lab4_5_3_pulse_T *const lab4_5_3_pulse_M = &lab4_5_3_pulse_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  lab4_5_3_pulse_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  lab4_5_3_pulse_output();
  lab4_5_3_pulse_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  lab4_5_3_pulse_output();
  lab4_5_3_pulse_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lab4_5_3_pulse_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_TransferFcn;
  if (rtmIsMajorTimeStep(lab4_5_3_pulse_M)) {
    /* set solver stop time */
    if (!(lab4_5_3_pulse_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab4_5_3_pulse_M->solverInfo,
                            ((lab4_5_3_pulse_M->Timing.clockTickH0 + 1) *
        lab4_5_3_pulse_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab4_5_3_pulse_M->solverInfo,
                            ((lab4_5_3_pulse_M->Timing.clockTick0 + 1) *
        lab4_5_3_pulse_M->Timing.stepSize0 +
        lab4_5_3_pulse_M->Timing.clockTickH0 *
        lab4_5_3_pulse_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab4_5_3_pulse_M)) {
    lab4_5_3_pulse_M->Timing.t[0] = rtsiGetT(&lab4_5_3_pulse_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab4_5_3_pulse_M)) {
  }

  /* Clock: '<Root>/Clock' */
  lab4_5_3_pulse_B.Clock = lab4_5_3_pulse_M->Timing.t[0];
  if (rtmIsMajorTimeStep(lab4_5_3_pulse_M)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    lab4_5_3_pulse_B.PulseGenerator = (lab4_5_3_pulse_DW.clockTickCounter <
      lab4_5_3_pulse_P.PulseGenerator_Duty) &&
      (lab4_5_3_pulse_DW.clockTickCounter >= 0) ?
      lab4_5_3_pulse_P.PulseGenerator_Amp : 0.0;
    if (lab4_5_3_pulse_DW.clockTickCounter >=
        lab4_5_3_pulse_P.PulseGenerator_Period - 1.0) {
      lab4_5_3_pulse_DW.clockTickCounter = 0;
    } else {
      lab4_5_3_pulse_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: lab4_5_3_pulse/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(lab4_5_3_pulse_DW.HILInitialize1_Card,
        lab4_5_3_pulse_P.HILReadEncoder_channels, 2,
        &lab4_5_3_pulse_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder_o1 = lab4_5_3_pulse_DW.HILReadEncoder_Buffer[0];
        lab4_5_3_pulse_B.HILReadEncoder_o2 =
          lab4_5_3_pulse_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<Root>/Gain1' */
    lab4_5_3_pulse_B.Gain1 = 1.0 / lab4_5_3_pulse_P.res_a *
      rtb_HILReadEncoder_o1;

    /* Sum: '<Root>/Sum' */
    lab4_5_3_pulse_B.Sum = lab4_5_3_pulse_B.PulseGenerator -
      lab4_5_3_pulse_B.Gain1;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_TransferFcn = lab4_5_3_pulse_P.TransferFcn_C *
    lab4_5_3_pulse_X.TransferFcn_CSTATE + lab4_5_3_pulse_P.TransferFcn_D *
    lab4_5_3_pulse_B.Sum;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_TransferFcn > lab4_5_3_pulse_P.Saturation_UpperSat) {
    lab4_5_3_pulse_B.Saturation = lab4_5_3_pulse_P.Saturation_UpperSat;
  } else if (rtb_TransferFcn < lab4_5_3_pulse_P.Saturation_LowerSat) {
    lab4_5_3_pulse_B.Saturation = lab4_5_3_pulse_P.Saturation_LowerSat;
  } else {
    lab4_5_3_pulse_B.Saturation = rtb_TransferFcn;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(lab4_5_3_pulse_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: lab4_5_3_pulse/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(lab4_5_3_pulse_DW.HILInitialize1_Card,
        &lab4_5_3_pulse_P.HILWriteAnalog_channels, 1,
        &lab4_5_3_pulse_B.Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void lab4_5_3_pulse_update(void)
{
  if (rtmIsMajorTimeStep(lab4_5_3_pulse_M)) {
    rt_ertODEUpdateContinuousStates(&lab4_5_3_pulse_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab4_5_3_pulse_M->Timing.clockTick0)) {
    ++lab4_5_3_pulse_M->Timing.clockTickH0;
  }

  lab4_5_3_pulse_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lab4_5_3_pulse_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab4_5_3_pulse_M->Timing.clockTick1)) {
      ++lab4_5_3_pulse_M->Timing.clockTickH1;
    }

    lab4_5_3_pulse_M->Timing.t[1] = lab4_5_3_pulse_M->Timing.clockTick1 *
      lab4_5_3_pulse_M->Timing.stepSize1 + lab4_5_3_pulse_M->Timing.clockTickH1 *
      lab4_5_3_pulse_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void lab4_5_3_pulse_derivatives(void)
{
  XDot_lab4_5_3_pulse_T *_rtXdot;
  _rtXdot = ((XDot_lab4_5_3_pulse_T *) lab4_5_3_pulse_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab4_5_3_pulse_P.TransferFcn_A *
    lab4_5_3_pulse_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab4_5_3_pulse_B.Sum;
}

/* Model initialize function */
void lab4_5_3_pulse_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: lab4_5_3_pulse/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &lab4_5_3_pulse_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab4_5_3_pulse_DW.HILInitialize1_Card,
      " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
      return;
    }

    if ((lab4_5_3_pulse_P.HILInitialize1_CKPStart && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(lab4_5_3_pulse_DW.HILInitialize1_Card,
        (t_clock *) lab4_5_3_pulse_P.HILInitialize1_CKChannels, 2U,
        (t_clock_mode *) lab4_5_3_pulse_P.HILInitialize1_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(lab4_5_3_pulse_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
      return;
    }

    if ((lab4_5_3_pulse_P.HILInitialize1_AIPStart && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_AIPEnter && is_switching)) {
      lab4_5_3_pulse_DW.HILInitialize1_AIMinimums[0] =
        (lab4_5_3_pulse_P.HILInitialize1_AILow);
      lab4_5_3_pulse_DW.HILInitialize1_AIMinimums[1] =
        (lab4_5_3_pulse_P.HILInitialize1_AILow);
      lab4_5_3_pulse_DW.HILInitialize1_AIMinimums[2] =
        (lab4_5_3_pulse_P.HILInitialize1_AILow);
      lab4_5_3_pulse_DW.HILInitialize1_AIMinimums[3] =
        (lab4_5_3_pulse_P.HILInitialize1_AILow);
      lab4_5_3_pulse_DW.HILInitialize1_AIMaximums[0] =
        lab4_5_3_pulse_P.HILInitialize1_AIHigh;
      lab4_5_3_pulse_DW.HILInitialize1_AIMaximums[1] =
        lab4_5_3_pulse_P.HILInitialize1_AIHigh;
      lab4_5_3_pulse_DW.HILInitialize1_AIMaximums[2] =
        lab4_5_3_pulse_P.HILInitialize1_AIHigh;
      lab4_5_3_pulse_DW.HILInitialize1_AIMaximums[3] =
        lab4_5_3_pulse_P.HILInitialize1_AIHigh;
      result = hil_set_analog_input_ranges(lab4_5_3_pulse_DW.HILInitialize1_Card,
        lab4_5_3_pulse_P.HILInitialize1_AIChannels, 4U,
        &lab4_5_3_pulse_DW.HILInitialize1_AIMinimums[0],
        &lab4_5_3_pulse_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_pulse_P.HILInitialize1_AOPStart && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_AOPEnter && is_switching)) {
      lab4_5_3_pulse_DW.HILInitialize1_AOMinimums[0] =
        (lab4_5_3_pulse_P.HILInitialize1_AOLow);
      lab4_5_3_pulse_DW.HILInitialize1_AOMinimums[1] =
        (lab4_5_3_pulse_P.HILInitialize1_AOLow);
      lab4_5_3_pulse_DW.HILInitialize1_AOMinimums[2] =
        (lab4_5_3_pulse_P.HILInitialize1_AOLow);
      lab4_5_3_pulse_DW.HILInitialize1_AOMinimums[3] =
        (lab4_5_3_pulse_P.HILInitialize1_AOLow);
      lab4_5_3_pulse_DW.HILInitialize1_AOMaximums[0] =
        lab4_5_3_pulse_P.HILInitialize1_AOHigh;
      lab4_5_3_pulse_DW.HILInitialize1_AOMaximums[1] =
        lab4_5_3_pulse_P.HILInitialize1_AOHigh;
      lab4_5_3_pulse_DW.HILInitialize1_AOMaximums[2] =
        lab4_5_3_pulse_P.HILInitialize1_AOHigh;
      lab4_5_3_pulse_DW.HILInitialize1_AOMaximums[3] =
        lab4_5_3_pulse_P.HILInitialize1_AOHigh;
      result = hil_set_analog_output_ranges
        (lab4_5_3_pulse_DW.HILInitialize1_Card,
         lab4_5_3_pulse_P.HILInitialize1_AOChannels, 4U,
         &lab4_5_3_pulse_DW.HILInitialize1_AOMinimums[0],
         &lab4_5_3_pulse_DW.HILInitialize1_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_pulse_P.HILInitialize1_AOStart && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_AOEnter && is_switching)) {
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_3_pulse_P.HILInitialize1_AOInitial;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_3_pulse_P.HILInitialize1_AOInitial;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_3_pulse_P.HILInitialize1_AOInitial;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_3_pulse_P.HILInitialize1_AOInitial;
      result = hil_write_analog(lab4_5_3_pulse_DW.HILInitialize1_Card,
        lab4_5_3_pulse_P.HILInitialize1_AOChannels, 4U,
        &lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }

    if (lab4_5_3_pulse_P.HILInitialize1_AOReset) {
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_3_pulse_P.HILInitialize1_AOWatchdog;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_3_pulse_P.HILInitialize1_AOWatchdog;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_3_pulse_P.HILInitialize1_AOWatchdog;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_3_pulse_P.HILInitialize1_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (lab4_5_3_pulse_DW.HILInitialize1_Card,
         lab4_5_3_pulse_P.HILInitialize1_AOChannels, 4U,
         &lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_pulse_P.HILInitialize1_EIPStart && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_EIPEnter && is_switching)) {
      lab4_5_3_pulse_DW.HILInitialize1_QuadratureModes[0] =
        lab4_5_3_pulse_P.HILInitialize1_EIQuadrature;
      lab4_5_3_pulse_DW.HILInitialize1_QuadratureModes[1] =
        lab4_5_3_pulse_P.HILInitialize1_EIQuadrature;
      lab4_5_3_pulse_DW.HILInitialize1_QuadratureModes[2] =
        lab4_5_3_pulse_P.HILInitialize1_EIQuadrature;
      lab4_5_3_pulse_DW.HILInitialize1_QuadratureModes[3] =
        lab4_5_3_pulse_P.HILInitialize1_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (lab4_5_3_pulse_DW.HILInitialize1_Card,
         lab4_5_3_pulse_P.HILInitialize1_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &lab4_5_3_pulse_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }

      lab4_5_3_pulse_DW.HILInitialize1_FilterFrequency[0] =
        lab4_5_3_pulse_P.HILInitialize1_EIFrequency;
      lab4_5_3_pulse_DW.HILInitialize1_FilterFrequency[1] =
        lab4_5_3_pulse_P.HILInitialize1_EIFrequency;
      lab4_5_3_pulse_DW.HILInitialize1_FilterFrequency[2] =
        lab4_5_3_pulse_P.HILInitialize1_EIFrequency;
      lab4_5_3_pulse_DW.HILInitialize1_FilterFrequency[3] =
        lab4_5_3_pulse_P.HILInitialize1_EIFrequency;
      result = hil_set_encoder_filter_frequency
        (lab4_5_3_pulse_DW.HILInitialize1_Card,
         lab4_5_3_pulse_P.HILInitialize1_EIChannels, 4U,
         &lab4_5_3_pulse_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_pulse_P.HILInitialize1_EIStart && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_EIEnter && is_switching)) {
      lab4_5_3_pulse_DW.HILInitialize1_InitialEICounts[0] =
        lab4_5_3_pulse_P.HILInitialize1_EIInitial;
      lab4_5_3_pulse_DW.HILInitialize1_InitialEICounts[1] =
        lab4_5_3_pulse_P.HILInitialize1_EIInitial;
      lab4_5_3_pulse_DW.HILInitialize1_InitialEICounts[2] =
        lab4_5_3_pulse_P.HILInitialize1_EIInitial;
      lab4_5_3_pulse_DW.HILInitialize1_InitialEICounts[3] =
        lab4_5_3_pulse_P.HILInitialize1_EIInitial;
      result = hil_set_encoder_counts(lab4_5_3_pulse_DW.HILInitialize1_Card,
        lab4_5_3_pulse_P.HILInitialize1_EIChannels, 4U,
        &lab4_5_3_pulse_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  lab4_5_3_pulse_DW.clockTickCounter = 0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  lab4_5_3_pulse_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void lab4_5_3_pulse_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: lab4_5_3_pulse/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(lab4_5_3_pulse_DW.HILInitialize1_Card);
    hil_monitor_stop_all(lab4_5_3_pulse_DW.HILInitialize1_Card);
    is_switching = false;
    if ((lab4_5_3_pulse_P.HILInitialize1_AOTerminate && !is_switching) ||
        (lab4_5_3_pulse_P.HILInitialize1_AOExit && is_switching)) {
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_3_pulse_P.HILInitialize1_AOFinal;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_3_pulse_P.HILInitialize1_AOFinal;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_3_pulse_P.HILInitialize1_AOFinal;
      lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_3_pulse_P.HILInitialize1_AOFinal;
      num_final_analog_outputs = 4U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(lab4_5_3_pulse_DW.HILInitialize1_Card,
        lab4_5_3_pulse_P.HILInitialize1_AOChannels, num_final_analog_outputs,
        &lab4_5_3_pulse_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_pulse_M, _rt_error_message);
      }
    }

    hil_task_delete_all(lab4_5_3_pulse_DW.HILInitialize1_Card);
    hil_monitor_delete_all(lab4_5_3_pulse_DW.HILInitialize1_Card);
    hil_close(lab4_5_3_pulse_DW.HILInitialize1_Card);
    lab4_5_3_pulse_DW.HILInitialize1_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  lab4_5_3_pulse_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab4_5_3_pulse_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lab4_5_3_pulse_initialize();
}

void MdlTerminate(void)
{
  lab4_5_3_pulse_terminate();
}

/* Registration function */
RT_MODEL_lab4_5_3_pulse_T *lab4_5_3_pulse(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab4_5_3_pulse_M, 0,
                sizeof(RT_MODEL_lab4_5_3_pulse_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab4_5_3_pulse_M->solverInfo,
                          &lab4_5_3_pulse_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab4_5_3_pulse_M->solverInfo, &rtmGetTPtr(lab4_5_3_pulse_M));
    rtsiSetStepSizePtr(&lab4_5_3_pulse_M->solverInfo,
                       &lab4_5_3_pulse_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab4_5_3_pulse_M->solverInfo, &lab4_5_3_pulse_M->derivs);
    rtsiSetContStatesPtr(&lab4_5_3_pulse_M->solverInfo, (real_T **)
                         &lab4_5_3_pulse_M->contStates);
    rtsiSetNumContStatesPtr(&lab4_5_3_pulse_M->solverInfo,
      &lab4_5_3_pulse_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab4_5_3_pulse_M->solverInfo,
      &lab4_5_3_pulse_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab4_5_3_pulse_M->solverInfo,
      &lab4_5_3_pulse_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab4_5_3_pulse_M->solverInfo,
      &lab4_5_3_pulse_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab4_5_3_pulse_M->solverInfo, (&rtmGetErrorStatus
      (lab4_5_3_pulse_M)));
    rtsiSetRTModelPtr(&lab4_5_3_pulse_M->solverInfo, lab4_5_3_pulse_M);
  }

  rtsiSetSimTimeStep(&lab4_5_3_pulse_M->solverInfo, MAJOR_TIME_STEP);
  lab4_5_3_pulse_M->intgData.y = lab4_5_3_pulse_M->odeY;
  lab4_5_3_pulse_M->intgData.f[0] = lab4_5_3_pulse_M->odeF[0];
  lab4_5_3_pulse_M->intgData.f[1] = lab4_5_3_pulse_M->odeF[1];
  lab4_5_3_pulse_M->intgData.f[2] = lab4_5_3_pulse_M->odeF[2];
  lab4_5_3_pulse_M->contStates = ((real_T *) &lab4_5_3_pulse_X);
  rtsiSetSolverData(&lab4_5_3_pulse_M->solverInfo, (void *)
                    &lab4_5_3_pulse_M->intgData);
  rtsiSetSolverName(&lab4_5_3_pulse_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab4_5_3_pulse_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab4_5_3_pulse_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab4_5_3_pulse_M->Timing.sampleTimes =
      (&lab4_5_3_pulse_M->Timing.sampleTimesArray[0]);
    lab4_5_3_pulse_M->Timing.offsetTimes =
      (&lab4_5_3_pulse_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab4_5_3_pulse_M->Timing.sampleTimes[0] = (0.0);
    lab4_5_3_pulse_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    lab4_5_3_pulse_M->Timing.offsetTimes[0] = (0.0);
    lab4_5_3_pulse_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab4_5_3_pulse_M, &lab4_5_3_pulse_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab4_5_3_pulse_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab4_5_3_pulse_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab4_5_3_pulse_M, 20.0);
  lab4_5_3_pulse_M->Timing.stepSize0 = 0.005;
  lab4_5_3_pulse_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  lab4_5_3_pulse_M->Sizes.checksums[0] = (976115405U);
  lab4_5_3_pulse_M->Sizes.checksums[1] = (2394631971U);
  lab4_5_3_pulse_M->Sizes.checksums[2] = (4092023533U);
  lab4_5_3_pulse_M->Sizes.checksums[3] = (3174190706U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab4_5_3_pulse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab4_5_3_pulse_M->extModeInfo,
      &lab4_5_3_pulse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab4_5_3_pulse_M->extModeInfo,
                        lab4_5_3_pulse_M->Sizes.checksums);
    rteiSetTPtr(lab4_5_3_pulse_M->extModeInfo, rtmGetTPtr(lab4_5_3_pulse_M));
  }

  lab4_5_3_pulse_M->solverInfoPtr = (&lab4_5_3_pulse_M->solverInfo);
  lab4_5_3_pulse_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&lab4_5_3_pulse_M->solverInfo, 0.005);
  rtsiSetSolverMode(&lab4_5_3_pulse_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab4_5_3_pulse_M->blockIO = ((void *) &lab4_5_3_pulse_B);
  (void) memset(((void *) &lab4_5_3_pulse_B), 0,
                sizeof(B_lab4_5_3_pulse_T));

  /* parameters */
  lab4_5_3_pulse_M->defaultParam = ((real_T *)&lab4_5_3_pulse_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab4_5_3_pulse_X;
    lab4_5_3_pulse_M->contStates = (x);
    (void) memset((void *)&lab4_5_3_pulse_X, 0,
                  sizeof(X_lab4_5_3_pulse_T));
  }

  /* states (dwork) */
  lab4_5_3_pulse_M->dwork = ((void *) &lab4_5_3_pulse_DW);
  (void) memset((void *)&lab4_5_3_pulse_DW, 0,
                sizeof(DW_lab4_5_3_pulse_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab4_5_3_pulse_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab4_5_3_pulse_M->Sizes.numContStates = (1);/* Number of continuous states */
  lab4_5_3_pulse_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  lab4_5_3_pulse_M->Sizes.numY = (0);  /* Number of model outputs */
  lab4_5_3_pulse_M->Sizes.numU = (0);  /* Number of model inputs */
  lab4_5_3_pulse_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab4_5_3_pulse_M->Sizes.numSampTimes = (2);/* Number of sample times */
  lab4_5_3_pulse_M->Sizes.numBlocks = (14);/* Number of blocks */
  lab4_5_3_pulse_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  lab4_5_3_pulse_M->Sizes.numBlockPrms = (85);/* Sum of parameter "widths" */
  return lab4_5_3_pulse_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
