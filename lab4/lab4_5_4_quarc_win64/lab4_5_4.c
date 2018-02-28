/*
 * lab4_5_4.c
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

#include "lab4_5_4.h"
#include "lab4_5_4_private.h"
#include "lab4_5_4_dt.h"

/* Block signals (auto storage) */
B_lab4_5_4_T lab4_5_4_B;

/* Block states (auto storage) */
DW_lab4_5_4_T lab4_5_4_DW;

/* Real-time model */
RT_MODEL_lab4_5_4_T lab4_5_4_M_;
RT_MODEL_lab4_5_4_T *const lab4_5_4_M = &lab4_5_4_M_;

/* Model output function */
void lab4_5_4_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T currentTime;

  /* Clock: '<Root>/Clock' */
  lab4_5_4_B.Clock = lab4_5_4_M->Timing.t[0];

  /* Step: '<Root>/Step' */
  currentTime = lab4_5_4_M->Timing.t[0];
  if (currentTime < lab4_5_4_P.Step_Time) {
    lab4_5_4_B.Step = lab4_5_4_P.Step_Y0;
  } else {
    lab4_5_4_B.Step = lab4_5_4_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: lab4_5_4/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(lab4_5_4_DW.HILInitialize1_Card,
      lab4_5_4_P.HILReadEncoder_channels, 2, &lab4_5_4_DW.HILReadEncoder_Buffer
      [0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder_o1 = lab4_5_4_DW.HILReadEncoder_Buffer[0];
      lab4_5_4_B.HILReadEncoder_o2 = lab4_5_4_DW.HILReadEncoder_Buffer[1];
    }
  }

  /* Gain: '<Root>/Gain1' */
  lab4_5_4_B.Gain1 = 1.0 / lab4_5_4_P.res_a * rtb_HILReadEncoder_o1;

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  currentTime = (lab4_5_4_B.Step - lab4_5_4_B.Gain1) * lab4_5_4_P.K;

  /* Saturate: '<Root>/Saturation' */
  if (currentTime > lab4_5_4_P.Saturation_UpperSat) {
    lab4_5_4_B.Saturation = lab4_5_4_P.Saturation_UpperSat;
  } else if (currentTime < lab4_5_4_P.Saturation_LowerSat) {
    lab4_5_4_B.Saturation = lab4_5_4_P.Saturation_LowerSat;
  } else {
    lab4_5_4_B.Saturation = currentTime;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: lab4_5_4/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(lab4_5_4_DW.HILInitialize1_Card,
      &lab4_5_4_P.HILWriteAnalog_channels, 1, &lab4_5_4_B.Saturation);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
    }
  }
}

/* Model update function */
void lab4_5_4_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab4_5_4_M->Timing.clockTick0)) {
    ++lab4_5_4_M->Timing.clockTickH0;
  }

  lab4_5_4_M->Timing.t[0] = lab4_5_4_M->Timing.clockTick0 *
    lab4_5_4_M->Timing.stepSize0 + lab4_5_4_M->Timing.clockTickH0 *
    lab4_5_4_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++lab4_5_4_M->Timing.clockTick1)) {
      ++lab4_5_4_M->Timing.clockTickH1;
    }

    lab4_5_4_M->Timing.t[1] = lab4_5_4_M->Timing.clockTick1 *
      lab4_5_4_M->Timing.stepSize1 + lab4_5_4_M->Timing.clockTickH1 *
      lab4_5_4_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void lab4_5_4_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: lab4_5_4/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &lab4_5_4_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab4_5_4_DW.HILInitialize1_Card, " ",
      2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
      return;
    }

    if ((lab4_5_4_P.HILInitialize1_CKPStart && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(lab4_5_4_DW.HILInitialize1_Card, (t_clock *)
        lab4_5_4_P.HILInitialize1_CKChannels, 2U, (t_clock_mode *)
        lab4_5_4_P.HILInitialize1_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(lab4_5_4_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
      return;
    }

    if ((lab4_5_4_P.HILInitialize1_AIPStart && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_AIPEnter && is_switching)) {
      lab4_5_4_DW.HILInitialize1_AIMinimums[0] =
        (lab4_5_4_P.HILInitialize1_AILow);
      lab4_5_4_DW.HILInitialize1_AIMinimums[1] =
        (lab4_5_4_P.HILInitialize1_AILow);
      lab4_5_4_DW.HILInitialize1_AIMinimums[2] =
        (lab4_5_4_P.HILInitialize1_AILow);
      lab4_5_4_DW.HILInitialize1_AIMinimums[3] =
        (lab4_5_4_P.HILInitialize1_AILow);
      lab4_5_4_DW.HILInitialize1_AIMaximums[0] =
        lab4_5_4_P.HILInitialize1_AIHigh;
      lab4_5_4_DW.HILInitialize1_AIMaximums[1] =
        lab4_5_4_P.HILInitialize1_AIHigh;
      lab4_5_4_DW.HILInitialize1_AIMaximums[2] =
        lab4_5_4_P.HILInitialize1_AIHigh;
      lab4_5_4_DW.HILInitialize1_AIMaximums[3] =
        lab4_5_4_P.HILInitialize1_AIHigh;
      result = hil_set_analog_input_ranges(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_AIChannels, 4U,
        &lab4_5_4_DW.HILInitialize1_AIMinimums[0],
        &lab4_5_4_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_4_P.HILInitialize1_AOPStart && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_AOPEnter && is_switching)) {
      lab4_5_4_DW.HILInitialize1_AOMinimums[0] =
        (lab4_5_4_P.HILInitialize1_AOLow);
      lab4_5_4_DW.HILInitialize1_AOMinimums[1] =
        (lab4_5_4_P.HILInitialize1_AOLow);
      lab4_5_4_DW.HILInitialize1_AOMinimums[2] =
        (lab4_5_4_P.HILInitialize1_AOLow);
      lab4_5_4_DW.HILInitialize1_AOMinimums[3] =
        (lab4_5_4_P.HILInitialize1_AOLow);
      lab4_5_4_DW.HILInitialize1_AOMaximums[0] =
        lab4_5_4_P.HILInitialize1_AOHigh;
      lab4_5_4_DW.HILInitialize1_AOMaximums[1] =
        lab4_5_4_P.HILInitialize1_AOHigh;
      lab4_5_4_DW.HILInitialize1_AOMaximums[2] =
        lab4_5_4_P.HILInitialize1_AOHigh;
      lab4_5_4_DW.HILInitialize1_AOMaximums[3] =
        lab4_5_4_P.HILInitialize1_AOHigh;
      result = hil_set_analog_output_ranges(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_AOChannels, 4U,
        &lab4_5_4_DW.HILInitialize1_AOMinimums[0],
        &lab4_5_4_DW.HILInitialize1_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_4_P.HILInitialize1_AOStart && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_AOEnter && is_switching)) {
      lab4_5_4_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_4_P.HILInitialize1_AOInitial;
      lab4_5_4_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_4_P.HILInitialize1_AOInitial;
      lab4_5_4_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_4_P.HILInitialize1_AOInitial;
      lab4_5_4_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_4_P.HILInitialize1_AOInitial;
      result = hil_write_analog(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_AOChannels, 4U,
        &lab4_5_4_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }

    if (lab4_5_4_P.HILInitialize1_AOReset) {
      lab4_5_4_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_4_P.HILInitialize1_AOWatchdog;
      lab4_5_4_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_4_P.HILInitialize1_AOWatchdog;
      lab4_5_4_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_4_P.HILInitialize1_AOWatchdog;
      lab4_5_4_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_4_P.HILInitialize1_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (lab4_5_4_DW.HILInitialize1_Card, lab4_5_4_P.HILInitialize1_AOChannels,
         4U, &lab4_5_4_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_4_P.HILInitialize1_EIPStart && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_EIPEnter && is_switching)) {
      lab4_5_4_DW.HILInitialize1_QuadratureModes[0] =
        lab4_5_4_P.HILInitialize1_EIQuadrature;
      lab4_5_4_DW.HILInitialize1_QuadratureModes[1] =
        lab4_5_4_P.HILInitialize1_EIQuadrature;
      lab4_5_4_DW.HILInitialize1_QuadratureModes[2] =
        lab4_5_4_P.HILInitialize1_EIQuadrature;
      lab4_5_4_DW.HILInitialize1_QuadratureModes[3] =
        lab4_5_4_P.HILInitialize1_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_EIChannels, 4U, (t_encoder_quadrature_mode *)
        &lab4_5_4_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }

      lab4_5_4_DW.HILInitialize1_FilterFrequency[0] =
        lab4_5_4_P.HILInitialize1_EIFrequency;
      lab4_5_4_DW.HILInitialize1_FilterFrequency[1] =
        lab4_5_4_P.HILInitialize1_EIFrequency;
      lab4_5_4_DW.HILInitialize1_FilterFrequency[2] =
        lab4_5_4_P.HILInitialize1_EIFrequency;
      lab4_5_4_DW.HILInitialize1_FilterFrequency[3] =
        lab4_5_4_P.HILInitialize1_EIFrequency;
      result = hil_set_encoder_filter_frequency(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_EIChannels, 4U,
        &lab4_5_4_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_5_4_P.HILInitialize1_EIStart && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_EIEnter && is_switching)) {
      lab4_5_4_DW.HILInitialize1_InitialEICounts[0] =
        lab4_5_4_P.HILInitialize1_EIInitial;
      lab4_5_4_DW.HILInitialize1_InitialEICounts[1] =
        lab4_5_4_P.HILInitialize1_EIInitial;
      lab4_5_4_DW.HILInitialize1_InitialEICounts[2] =
        lab4_5_4_P.HILInitialize1_EIInitial;
      lab4_5_4_DW.HILInitialize1_InitialEICounts[3] =
        lab4_5_4_P.HILInitialize1_EIInitial;
      result = hil_set_encoder_counts(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_EIChannels, 4U,
        &lab4_5_4_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void lab4_5_4_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: lab4_5_4/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(lab4_5_4_DW.HILInitialize1_Card);
    hil_monitor_stop_all(lab4_5_4_DW.HILInitialize1_Card);
    is_switching = false;
    if ((lab4_5_4_P.HILInitialize1_AOTerminate && !is_switching) ||
        (lab4_5_4_P.HILInitialize1_AOExit && is_switching)) {
      lab4_5_4_DW.HILInitialize1_AOVoltages[0] =
        lab4_5_4_P.HILInitialize1_AOFinal;
      lab4_5_4_DW.HILInitialize1_AOVoltages[1] =
        lab4_5_4_P.HILInitialize1_AOFinal;
      lab4_5_4_DW.HILInitialize1_AOVoltages[2] =
        lab4_5_4_P.HILInitialize1_AOFinal;
      lab4_5_4_DW.HILInitialize1_AOVoltages[3] =
        lab4_5_4_P.HILInitialize1_AOFinal;
      num_final_analog_outputs = 4U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(lab4_5_4_DW.HILInitialize1_Card,
        lab4_5_4_P.HILInitialize1_AOChannels, num_final_analog_outputs,
        &lab4_5_4_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_5_4_M, _rt_error_message);
      }
    }

    hil_task_delete_all(lab4_5_4_DW.HILInitialize1_Card);
    hil_monitor_delete_all(lab4_5_4_DW.HILInitialize1_Card);
    hil_close(lab4_5_4_DW.HILInitialize1_Card);
    lab4_5_4_DW.HILInitialize1_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  lab4_5_4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab4_5_4_update();
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
  lab4_5_4_initialize();
}

void MdlTerminate(void)
{
  lab4_5_4_terminate();
}

/* Registration function */
RT_MODEL_lab4_5_4_T *lab4_5_4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab4_5_4_M, 0,
                sizeof(RT_MODEL_lab4_5_4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab4_5_4_M->solverInfo,
                          &lab4_5_4_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab4_5_4_M->solverInfo, &rtmGetTPtr(lab4_5_4_M));
    rtsiSetStepSizePtr(&lab4_5_4_M->solverInfo, &lab4_5_4_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&lab4_5_4_M->solverInfo, (&rtmGetErrorStatus
      (lab4_5_4_M)));
    rtsiSetRTModelPtr(&lab4_5_4_M->solverInfo, lab4_5_4_M);
  }

  rtsiSetSimTimeStep(&lab4_5_4_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&lab4_5_4_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab4_5_4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab4_5_4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab4_5_4_M->Timing.sampleTimes = (&lab4_5_4_M->Timing.sampleTimesArray[0]);
    lab4_5_4_M->Timing.offsetTimes = (&lab4_5_4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab4_5_4_M->Timing.sampleTimes[0] = (0.0);
    lab4_5_4_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    lab4_5_4_M->Timing.offsetTimes[0] = (0.0);
    lab4_5_4_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab4_5_4_M, &lab4_5_4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab4_5_4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab4_5_4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab4_5_4_M, -1);
  lab4_5_4_M->Timing.stepSize0 = 0.005;
  lab4_5_4_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  lab4_5_4_M->Sizes.checksums[0] = (253746628U);
  lab4_5_4_M->Sizes.checksums[1] = (2638670302U);
  lab4_5_4_M->Sizes.checksums[2] = (6055365U);
  lab4_5_4_M->Sizes.checksums[3] = (3336094668U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab4_5_4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab4_5_4_M->extModeInfo,
      &lab4_5_4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab4_5_4_M->extModeInfo, lab4_5_4_M->Sizes.checksums);
    rteiSetTPtr(lab4_5_4_M->extModeInfo, rtmGetTPtr(lab4_5_4_M));
  }

  lab4_5_4_M->solverInfoPtr = (&lab4_5_4_M->solverInfo);
  lab4_5_4_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&lab4_5_4_M->solverInfo, 0.005);
  rtsiSetSolverMode(&lab4_5_4_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab4_5_4_M->blockIO = ((void *) &lab4_5_4_B);
  (void) memset(((void *) &lab4_5_4_B), 0,
                sizeof(B_lab4_5_4_T));

  /* parameters */
  lab4_5_4_M->defaultParam = ((real_T *)&lab4_5_4_P);

  /* states (dwork) */
  lab4_5_4_M->dwork = ((void *) &lab4_5_4_DW);
  (void) memset((void *)&lab4_5_4_DW, 0,
                sizeof(DW_lab4_5_4_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab4_5_4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab4_5_4_M->Sizes.numContStates = (0);/* Number of continuous states */
  lab4_5_4_M->Sizes.numY = (0);        /* Number of model outputs */
  lab4_5_4_M->Sizes.numU = (0);        /* Number of model inputs */
  lab4_5_4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab4_5_4_M->Sizes.numSampTimes = (2);/* Number of sample times */
  lab4_5_4_M->Sizes.numBlocks = (14);  /* Number of blocks */
  lab4_5_4_M->Sizes.numBlockIO = (5);  /* Number of block outputs */
  lab4_5_4_M->Sizes.numBlockPrms = (82);/* Sum of parameter "widths" */
  return lab4_5_4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
