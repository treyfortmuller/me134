/*
 * lab4_5_3_decay.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab4_5_3_decay".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Feb 28 13:34:53 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab4_5_3_decay.h"
#include "lab4_5_3_decay_private.h"
#include "lab4_5_3_decay_dt.h"

/* Block signals (auto storage) */
B_lab4_5_3_decay_T lab4_5_3_decay_B;

/* Continuous states */
X_lab4_5_3_decay_T lab4_5_3_decay_X;

/* Block states (auto storage) */
DW_lab4_5_3_decay_T lab4_5_3_decay_DW;

/* Real-time model */
RT_MODEL_lab4_5_3_decay_T lab4_5_3_decay_M_;
RT_MODEL_lab4_5_3_decay_T *const lab4_5_3_decay_M = &lab4_5_3_decay_M_;

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
  lab4_5_3_decay_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  lab4_5_3_decay_output();
  lab4_5_3_decay_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  lab4_5_3_decay_output();
  lab4_5_3_decay_derivatives();

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
void lab4_5_3_decay_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_TransferFcn;
  if (rtmIsMajorTimeStep(lab4_5_3_decay_M)) {
    /* set solver stop time */
    if (!(lab4_5_3_decay_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab4_5_3_decay_M->solverInfo,
                            ((lab4_5_3_decay_M->Timing.clockTickH0 + 1) *
        lab4_5_3_decay_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab4_5_3_decay_M->solverInfo,
                            ((lab4_5_3_decay_M->Timing.clockTick0 + 1) *
        lab4_5_3_decay_M->Timing.stepSize0 +
        lab4_5_3_decay_M->Timing.clockTickH0 *
        lab4_5_3_decay_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab4_5_3_decay_M)) {
    lab4_5_3_decay_M->Timing.t[0] = rtsiGetT(&lab4_5_3_decay_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab4_5_3_decay_M)) {
    /* Sin: '<Root>/Sine Wave' */
    if (lab4_5_3_decay_DW.systemEnable != 0) {
      lab4_5_3_decay_DW.lastSin = sin(lab4_5_3_decay_P.SineWave_Freq *
        lab4_5_3_decay_M->Timing.t[1]);
      lab4_5_3_decay_DW.lastCos = cos(lab4_5_3_decay_P.SineWave_Freq *
        lab4_5_3_decay_M->Timing.t[1]);
      lab4_5_3_decay_DW.systemEnable = 0;
    }

    lab4_5_3_decay_B.SineWave = ((lab4_5_3_decay_DW.lastSin *
      lab4_5_3_decay_P.SineWave_PCos + lab4_5_3_decay_DW.lastCos *
      lab4_5_3_decay_P.SineWave_PSin) * lab4_5_3_decay_P.SineWave_HCos +
      (lab4_5_3_decay_DW.lastCos * lab4_5_3_decay_P.SineWave_PCos -
       lab4_5_3_decay_DW.lastSin * lab4_5_3_decay_P.SineWave_PSin) *
      lab4_5_3_decay_P.SineWave_Hsin) * lab4_5_3_decay_P.SineWave_Amp +
      lab4_5_3_decay_P.SineWave_Bias;

    /* End of Sin: '<Root>/Sine Wave' */
  }

  /* Clock: '<Root>/Clock' */
  lab4_5_3_decay_B.Clock = lab4_5_3_decay_M->Timing.t[0];

  /* Product: '<Root>/Product' incorporates:
   *  Gain: '<Root>/Gain'
   *  Math: '<Root>/Math Function'
   *
   * About '<Root>/Math Function':
   *  Operator: exp
   */
  lab4_5_3_decay_B.Product = exp(lab4_5_3_decay_P.Gain_Gain *
    lab4_5_3_decay_B.Clock) * lab4_5_3_decay_B.SineWave;
  if (rtmIsMajorTimeStep(lab4_5_3_decay_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: lab4_5_3_decay/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(lab4_5_3_decay_DW.HILInitialize1_Card,
        lab4_5_3_decay_P.HILReadEncoder_channels, 2,
        &lab4_5_3_decay_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder_o1 = lab4_5_3_decay_DW.HILReadEncoder_Buffer[0];
        lab4_5_3_decay_B.HILReadEncoder_o2 =
          lab4_5_3_decay_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<Root>/Gain1' */
    lab4_5_3_decay_B.Gain1 = 1.0 / lab4_5_3_decay_P.res_a *
      rtb_HILReadEncoder_o1;
  }

  /* Sum: '<Root>/Sum' */
  lab4_5_3_decay_B.Sum = lab4_5_3_decay_B.Product - lab4_5_3_decay_B.Gain1;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_TransferFcn = lab4_5_3_decay_P.TransferFcn_C *
    lab4_5_3_decay_X.TransferFcn_CSTATE + lab4_5_3_decay_P.TransferFcn_D *
    lab4_5_3_decay_B.Sum;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_TransferFcn > lab4_5_3_decay_P.Saturation_UpperSat) {
    lab4_5_3_decay_B.Saturation = lab4_5_3_decay_P.Saturation_UpperSat;
  } else if (rtb_TransferFcn < lab4_5_3_decay_P.Saturation_LowerSat) {
    lab4_5_3_decay_B.Saturation = lab4_5_3_decay_P.Saturation_LowerSat;
  } else {
    lab4_5_3_decay_B.Saturation = rtb_TransferFcn;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(lab4_5_3_decay_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: lab4_5_3_decay/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(lab4_5_3_decay_DW.HILInitialize1_Card,
        &lab4_5_3_decay_P.HILWriteAnalog_channels, 1,
        &lab4_5_3_decay_B.Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void lab4_5_3_decay_update(void)
{
  real_T HoldSine;
  if (rtmIsMajorTimeStep(lab4_5_3_decay_M)) {
    /* Update for Sin: '<Root>/Sine Wave' */
    HoldSine = lab4_5_3_decay_DW.lastSin;
    lab4_5_3_decay_DW.lastSin = lab4_5_3_decay_DW.lastSin *
      lab4_5_3_decay_P.SineWave_HCos + lab4_5_3_decay_DW.lastCos *
      lab4_5_3_decay_P.SineWave_Hsin;
    lab4_5_3_decay_DW.lastCos = lab4_5_3_decay_DW.lastCos *
      lab4_5_3_decay_P.SineWave_HCos - HoldSine * lab4_5_3_decay_P.SineWave_Hsin;
  }

  if (rtmIsMajorTimeStep(lab4_5_3_decay_M)) {
    rt_ertODEUpdateContinuousStates(&lab4_5_3_decay_M->solverInfo);
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
  if (!(++lab4_5_3_decay_M->Timing.clockTick0)) {
    ++lab4_5_3_decay_M->Timing.clockTickH0;
  }

  lab4_5_3_decay_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lab4_5_3_decay_M->solverInfo);

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
    if (!(++lab4_5_3_decay_M->Timing.clockTick1)) {
      ++lab4_5_3_decay_M->Timing.clockTickH1;
    }

    lab4_5_3_decay_M->Timing.t[1] = lab4_5_3_decay_M->Timing.clockTick1 *
      lab4_5_3_decay_M->Timing.stepSize1 + lab4_5_3_decay_M->Timing.clockTickH1 *
      lab4_5_3_decay_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void lab4_5_3_decay_derivatives(void)
{
  XDot_lab4_5_3_decay_T *_rtXdot;
  _rtXdot = ((XDot_lab4_5_3_decay_T *) lab4_5_3_decay_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab4_5_3_decay_P.TransferFcn_A *
    lab4_5_3_decay_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab4_5_3_decay_B.Sum;
}

/* Model initialize function */
void lab4_5_3_decay_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: lab4_5_3_decay/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &lab4_5_3_decay_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab4_5_3_decay_DW.HILInitialize1_Card,
      " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
      return;
    }

    if ((lab4_5_3_decay_P.HILInitialize1_CKPStart && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(lab4_5_3_decay_DW.HILInitialize1_Card,
        (t_clock *) lab4_5_3_decay_P.HILInitialize1_CKChannels, 2U,
        (t_clock_mode *) lab4_5_3_decay_P.HILInitialize1_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(lab4_5_3_decay_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
      return;
    }

    if ((lab4_5_3_decay_P.HILInitialize1_AIPStart && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_AIPEnter && is_switching)) {
      lab4_5_3_decay_DW.HILInitialize1_AIMinimums[0] =
        (lab4_5_3_decay_P.HILInitialize1_AILow);
      lab4_5_3_decay_DW.HILInitialize1_AIMinimums[1] =
        (lab4_5_3_decay_P.HILInitialize1_AILow);
      lab4_5_3_decay_DW.HILInitialize1_AIMinimums[2] =
        (lab4_5_3_decay_P.HILInitialize1_AILow);
      lab4_5_3_decay_DW.HILInitialize1_AIMinimums[3] =
        (lab4_5_3_decay_P.HILInitialize1_AILow);
      lab4_5_3_decay_DW.HILInitialize1_AIMaximums[0] =
        lab4_5_3_decay_P.HILInitialize1_AIHigh;
      lab4_5_3_decay_DW.HILInitialize1_AIMaximums[1] =
        lab4_5_3_decay_P.HILInitialize1_AIHigh;
      lab4_5_3_decay_DW.HILInitialize1_AIMaximums[2] =
        lab4_5_3_decay_P.HILInitialize1_AIHigh;
      lab4_5_3_decay_DW.HILInitialize1_AIMaximums[3] =
        lab4_5_3_decay_P.HILInitialize1_AIHigh;
      result = hil_set_analog_input_ranges(lab4_5_3_decay_DW.HILInitialize1_Card,
        lab4_5_3_decay_P.HILInitialize1_AIChannels, 4U,
        &lab4_5_3_decay_DW.HILInitialize1_AIMinimums[0],
        &lab4_5_3_decay_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_decay_P.HILInitialize1_AOPStart && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_AOPEnter && is_switching)) {
      lab4_5_3_decay_DW.HILInitialize1_AOMinimums[0] =
        (lab4_5_3_decay_P.HILInitialize1_AOLow);
      lab4_5_3_decay_DW.HILInitialize1_AOMinimums[1] =
        (lab4_5_3_decay_P.HILInitialize1_AOLow);
      lab4_5_3_decay_DW.HILInitialize1_AOMinimums[2] =
        (lab4_5_3_decay_P.HILInitialize1_AOLow);
      lab4_5_3_decay_DW.HILInitialize1_AOMinimums[3] =
        (lab4_5_3_decay_P.HILInitialize1_AOLow);
      lab4_5_3_decay_DW.HILInitialize1_AOMaximums[0] =
        lab4_5_3_decay_P.HILInitialize1_AOHigh;
      lab4_5_3_decay_DW.HILInitialize1_AOMaximums[1] =
        lab4_5_3_decay_P.HILInitialize1_AOHigh;
      lab4_5_3_decay_DW.HILInitialize1_AOMaximums[2] =
        lab4_5_3_decay_P.HILInitialize1_AOHigh;
      lab4_5_3_decay_DW.HILInitialize1_AOMaximums[3] =
        lab4_5_3_decay_P.HILInitialize1_AOHigh;
      result = hil_set_analog_output_ranges
        (lab4_5_3_decay_DW.HILInitialize1_Card,
         lab4_5_3_decay_P.HILInitialize1_AOChannels, 4U,
         &lab4_5_3_decay_DW.HILInitialize1_AOMinimums[0],
         &lab4_5_3_decay_DW.HILInitialize1_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_decay_P.HILInitialize1_AOStart && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_AOEnter && is_switching)) {
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_3_decay_P.HILInitialize1_AOInitial;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_3_decay_P.HILInitialize1_AOInitial;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_3_decay_P.HILInitialize1_AOInitial;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_3_decay_P.HILInitialize1_AOInitial;
      result = hil_write_analog(lab4_5_3_decay_DW.HILInitialize1_Card,
        lab4_5_3_decay_P.HILInitialize1_AOChannels, 4U,
        &lab4_5_3_decay_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }

    if (lab4_5_3_decay_P.HILInitialize1_AOReset) {
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_3_decay_P.HILInitialize1_AOWatchdog;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_3_decay_P.HILInitialize1_AOWatchdog;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_3_decay_P.HILInitialize1_AOWatchdog;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_3_decay_P.HILInitialize1_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (lab4_5_3_decay_DW.HILInitialize1_Card,
         lab4_5_3_decay_P.HILInitialize1_AOChannels, 4U,
         &lab4_5_3_decay_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_decay_P.HILInitialize1_EIPStart && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_EIPEnter && is_switching)) {
      lab4_5_3_decay_DW.HILInitialize1_QuadratureModes[0] =
        lab4_5_3_decay_P.HILInitialize1_EIQuadrature;
      lab4_5_3_decay_DW.HILInitialize1_QuadratureModes[1] =
        lab4_5_3_decay_P.HILInitialize1_EIQuadrature;
      lab4_5_3_decay_DW.HILInitialize1_QuadratureModes[2] =
        lab4_5_3_decay_P.HILInitialize1_EIQuadrature;
      lab4_5_3_decay_DW.HILInitialize1_QuadratureModes[3] =
        lab4_5_3_decay_P.HILInitialize1_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (lab4_5_3_decay_DW.HILInitialize1_Card,
         lab4_5_3_decay_P.HILInitialize1_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &lab4_5_3_decay_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }

      lab4_5_3_decay_DW.HILInitialize1_FilterFrequency[0] =
        lab4_5_3_decay_P.HILInitialize1_EIFrequency;
      lab4_5_3_decay_DW.HILInitialize1_FilterFrequency[1] =
        lab4_5_3_decay_P.HILInitialize1_EIFrequency;
      lab4_5_3_decay_DW.HILInitialize1_FilterFrequency[2] =
        lab4_5_3_decay_P.HILInitialize1_EIFrequency;
      lab4_5_3_decay_DW.HILInitialize1_FilterFrequency[3] =
        lab4_5_3_decay_P.HILInitialize1_EIFrequency;
      result = hil_set_encoder_filter_frequency
        (lab4_5_3_decay_DW.HILInitialize1_Card,
         lab4_5_3_decay_P.HILInitialize1_EIChannels, 4U,
         &lab4_5_3_decay_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_3_decay_P.HILInitialize1_EIStart && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_EIEnter && is_switching)) {
      lab4_5_3_decay_DW.HILInitialize1_InitialEICounts[0] =
        lab4_5_3_decay_P.HILInitialize1_EIInitial;
      lab4_5_3_decay_DW.HILInitialize1_InitialEICounts[1] =
        lab4_5_3_decay_P.HILInitialize1_EIInitial;
      lab4_5_3_decay_DW.HILInitialize1_InitialEICounts[2] =
        lab4_5_3_decay_P.HILInitialize1_EIInitial;
      lab4_5_3_decay_DW.HILInitialize1_InitialEICounts[3] =
        lab4_5_3_decay_P.HILInitialize1_EIInitial;
      result = hil_set_encoder_counts(lab4_5_3_decay_DW.HILInitialize1_Card,
        lab4_5_3_decay_P.HILInitialize1_EIChannels, 4U,
        &lab4_5_3_decay_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  lab4_5_3_decay_X.TransferFcn_CSTATE = 0.0;

  /* Enable for Sin: '<Root>/Sine Wave' */
  lab4_5_3_decay_DW.systemEnable = 1;
}

/* Model terminate function */
void lab4_5_3_decay_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: lab4_5_3_decay/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(lab4_5_3_decay_DW.HILInitialize1_Card);
    hil_monitor_stop_all(lab4_5_3_decay_DW.HILInitialize1_Card);
    is_switching = false;
    if ((lab4_5_3_decay_P.HILInitialize1_AOTerminate && !is_switching) ||
        (lab4_5_3_decay_P.HILInitialize1_AOExit && is_switching)) {
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_3_decay_P.HILInitialize1_AOFinal;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_3_decay_P.HILInitialize1_AOFinal;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_3_decay_P.HILInitialize1_AOFinal;
      lab4_5_3_decay_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_3_decay_P.HILInitialize1_AOFinal;
      num_final_analog_outputs = 4U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(lab4_5_3_decay_DW.HILInitialize1_Card,
        lab4_5_3_decay_P.HILInitialize1_AOChannels, num_final_analog_outputs,
        &lab4_5_3_decay_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_3_decay_M, _rt_error_message);
      }
    }

    hil_task_delete_all(lab4_5_3_decay_DW.HILInitialize1_Card);
    hil_monitor_delete_all(lab4_5_3_decay_DW.HILInitialize1_Card);
    hil_close(lab4_5_3_decay_DW.HILInitialize1_Card);
    lab4_5_3_decay_DW.HILInitialize1_Card = NULL;
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
  lab4_5_3_decay_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab4_5_3_decay_update();
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
  lab4_5_3_decay_initialize();
}

void MdlTerminate(void)
{
  lab4_5_3_decay_terminate();
}

/* Registration function */
RT_MODEL_lab4_5_3_decay_T *lab4_5_3_decay(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab4_5_3_decay_M, 0,
                sizeof(RT_MODEL_lab4_5_3_decay_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab4_5_3_decay_M->solverInfo,
                          &lab4_5_3_decay_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab4_5_3_decay_M->solverInfo, &rtmGetTPtr(lab4_5_3_decay_M));
    rtsiSetStepSizePtr(&lab4_5_3_decay_M->solverInfo,
                       &lab4_5_3_decay_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab4_5_3_decay_M->solverInfo, &lab4_5_3_decay_M->derivs);
    rtsiSetContStatesPtr(&lab4_5_3_decay_M->solverInfo, (real_T **)
                         &lab4_5_3_decay_M->contStates);
    rtsiSetNumContStatesPtr(&lab4_5_3_decay_M->solverInfo,
      &lab4_5_3_decay_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab4_5_3_decay_M->solverInfo,
      &lab4_5_3_decay_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab4_5_3_decay_M->solverInfo,
      &lab4_5_3_decay_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab4_5_3_decay_M->solverInfo,
      &lab4_5_3_decay_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab4_5_3_decay_M->solverInfo, (&rtmGetErrorStatus
      (lab4_5_3_decay_M)));
    rtsiSetRTModelPtr(&lab4_5_3_decay_M->solverInfo, lab4_5_3_decay_M);
  }

  rtsiSetSimTimeStep(&lab4_5_3_decay_M->solverInfo, MAJOR_TIME_STEP);
  lab4_5_3_decay_M->intgData.y = lab4_5_3_decay_M->odeY;
  lab4_5_3_decay_M->intgData.f[0] = lab4_5_3_decay_M->odeF[0];
  lab4_5_3_decay_M->intgData.f[1] = lab4_5_3_decay_M->odeF[1];
  lab4_5_3_decay_M->intgData.f[2] = lab4_5_3_decay_M->odeF[2];
  lab4_5_3_decay_M->contStates = ((real_T *) &lab4_5_3_decay_X);
  rtsiSetSolverData(&lab4_5_3_decay_M->solverInfo, (void *)
                    &lab4_5_3_decay_M->intgData);
  rtsiSetSolverName(&lab4_5_3_decay_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab4_5_3_decay_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab4_5_3_decay_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab4_5_3_decay_M->Timing.sampleTimes =
      (&lab4_5_3_decay_M->Timing.sampleTimesArray[0]);
    lab4_5_3_decay_M->Timing.offsetTimes =
      (&lab4_5_3_decay_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab4_5_3_decay_M->Timing.sampleTimes[0] = (0.0);
    lab4_5_3_decay_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    lab4_5_3_decay_M->Timing.offsetTimes[0] = (0.0);
    lab4_5_3_decay_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab4_5_3_decay_M, &lab4_5_3_decay_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab4_5_3_decay_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab4_5_3_decay_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab4_5_3_decay_M, 20.0);
  lab4_5_3_decay_M->Timing.stepSize0 = 0.005;
  lab4_5_3_decay_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  lab4_5_3_decay_M->Sizes.checksums[0] = (2527869206U);
  lab4_5_3_decay_M->Sizes.checksums[1] = (3341929625U);
  lab4_5_3_decay_M->Sizes.checksums[2] = (4114908280U);
  lab4_5_3_decay_M->Sizes.checksums[3] = (2510989598U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab4_5_3_decay_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab4_5_3_decay_M->extModeInfo,
      &lab4_5_3_decay_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab4_5_3_decay_M->extModeInfo,
                        lab4_5_3_decay_M->Sizes.checksums);
    rteiSetTPtr(lab4_5_3_decay_M->extModeInfo, rtmGetTPtr(lab4_5_3_decay_M));
  }

  lab4_5_3_decay_M->solverInfoPtr = (&lab4_5_3_decay_M->solverInfo);
  lab4_5_3_decay_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&lab4_5_3_decay_M->solverInfo, 0.005);
  rtsiSetSolverMode(&lab4_5_3_decay_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab4_5_3_decay_M->blockIO = ((void *) &lab4_5_3_decay_B);
  (void) memset(((void *) &lab4_5_3_decay_B), 0,
                sizeof(B_lab4_5_3_decay_T));

  /* parameters */
  lab4_5_3_decay_M->defaultParam = ((real_T *)&lab4_5_3_decay_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab4_5_3_decay_X;
    lab4_5_3_decay_M->contStates = (x);
    (void) memset((void *)&lab4_5_3_decay_X, 0,
                  sizeof(X_lab4_5_3_decay_T));
  }

  /* states (dwork) */
  lab4_5_3_decay_M->dwork = ((void *) &lab4_5_3_decay_DW);
  (void) memset((void *)&lab4_5_3_decay_DW, 0,
                sizeof(DW_lab4_5_3_decay_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab4_5_3_decay_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab4_5_3_decay_M->Sizes.numContStates = (1);/* Number of continuous states */
  lab4_5_3_decay_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  lab4_5_3_decay_M->Sizes.numY = (0);  /* Number of model outputs */
  lab4_5_3_decay_M->Sizes.numU = (0);  /* Number of model inputs */
  lab4_5_3_decay_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab4_5_3_decay_M->Sizes.numSampTimes = (2);/* Number of sample times */
  lab4_5_3_decay_M->Sizes.numBlocks = (17);/* Number of blocks */
  lab4_5_3_decay_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  lab4_5_3_decay_M->Sizes.numBlockPrms = (89);/* Sum of parameter "widths" */
  return lab4_5_3_decay_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
