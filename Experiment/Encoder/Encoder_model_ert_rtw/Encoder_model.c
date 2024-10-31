/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_model.c
 *
 * Code generated for Simulink model 'Encoder_model'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 21:17:16 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder_model.h"
#include "Encoder_model_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "Encoder_model_private.h"

/* Block signals (default storage) */
B_Encoder_model_T Encoder_model_B;

/* Block states (default storage) */
DW_Encoder_model_T Encoder_model_DW;

/* Real-time model */
static RT_MODEL_Encoder_model_T Encoder_model_M_;
RT_MODEL_Encoder_model_T *const Encoder_model_M = &Encoder_model_M_;

/* Forward declaration for local functions */
static void Encoder_model_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_mode_SystemCore_setup_g(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_mod_SystemCore_setup_g1(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_model_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder3' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder3' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder3' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder3' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_mode_SystemCore_setup_g(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder4' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_mod_SystemCore_setup_g1(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder5' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder5' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder5' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder5' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Encoder_model_step(void)
{
  real_T diff;

  /* MATLABSystem: '<Root>/Encoder3' */
  Encoder_model_B.QEI_X1_AMT_RAW = getTimerCounterValueForG4
    (Encoder_model_DW.obj_n.TimerHandle, false, NULL);

  /* MATLABSystem: '<Root>/Encoder3' */
  Encoder_model_B.DIR_X1 = ouputDirectionOfCounter
    (Encoder_model_DW.obj_n.TimerHandle);

  /* DataTypeConversion: '<Root>/Cast To Double5' */
  Encoder_model_B.CastToDouble5 = Encoder_model_B.QEI_X1_AMT_RAW;

  /* MATLAB Function: '<Root>/QEI_X1_Calculation AMT' */
  diff = Encoder_model_B.CastToDouble5 - Encoder_model_DW.pre_signal_h;
  if (diff < -28672.0) {
    Encoder_model_DW.pos_h += (57345.0 - Encoder_model_DW.pre_signal_h) +
      Encoder_model_B.CastToDouble5;
  } else if (diff > 28672.0) {
    Encoder_model_DW.pos_h -= (57345.0 - Encoder_model_B.CastToDouble5) +
      Encoder_model_DW.pre_signal_h;
  } else {
    Encoder_model_DW.pos_h += diff;
  }

  Encoder_model_B.position_j = Encoder_model_DW.pos_h / 2048.0 * 2.0 *
    3.1415926535897931;
  Encoder_model_B.velocity_e = (Encoder_model_DW.pos_h -
    Encoder_model_DW.pre_pos_a) / 0.01 / 2048.0 * 6.2831853071795862;
  Encoder_model_DW.pre_signal_h = Encoder_model_B.CastToDouble5;
  Encoder_model_DW.pre_pos_a = Encoder_model_DW.pos_h;

  /* End of MATLAB Function: '<Root>/QEI_X1_Calculation AMT' */
  /* MATLABSystem: '<Root>/Encoder4' */
  Encoder_model_B.QEI_X2_AMT_RAW = getTimerCounterValueForG4
    (Encoder_model_DW.obj_a.TimerHandle, false, NULL);

  /* MATLABSystem: '<Root>/Encoder4' */
  Encoder_model_B.DIR_X2 = ouputDirectionOfCounter
    (Encoder_model_DW.obj_a.TimerHandle);

  /* DataTypeConversion: '<Root>/Cast To Double6' */
  Encoder_model_B.CastToDouble6 = Encoder_model_B.QEI_X2_AMT_RAW;

  /* MATLAB Function: '<Root>/QEI_X2_Calculation AMT' */
  diff = Encoder_model_B.CastToDouble6 - Encoder_model_DW.pre_signal_k;
  if (diff < -28672.0) {
    Encoder_model_DW.pos_g += (57345.0 - Encoder_model_DW.pre_signal_k) +
      Encoder_model_B.CastToDouble6;
  } else if (diff > 28672.0) {
    Encoder_model_DW.pos_g -= (57345.0 - Encoder_model_B.CastToDouble6) +
      Encoder_model_DW.pre_signal_k;
  } else {
    Encoder_model_DW.pos_g += diff;
  }

  Encoder_model_B.position_c = Encoder_model_DW.pos_g / 4096.0 * 2.0 *
    3.1415926535897931;
  Encoder_model_B.velocity_g = (Encoder_model_DW.pos_g -
    Encoder_model_DW.pre_pos_m) / 0.01 / 4096.0 * 6.2831853071795862;
  Encoder_model_DW.pre_signal_k = Encoder_model_B.CastToDouble6;
  Encoder_model_DW.pre_pos_m = Encoder_model_DW.pos_g;

  /* End of MATLAB Function: '<Root>/QEI_X2_Calculation AMT' */
  /* MATLABSystem: '<Root>/Encoder5' */
  Encoder_model_B.QEI_X4_AMT_RAW = getTimerCounterValueForG4
    (Encoder_model_DW.obj.TimerHandle, false, NULL);

  /* MATLABSystem: '<Root>/Encoder5' */
  Encoder_model_B.DIR_X4 = ouputDirectionOfCounter
    (Encoder_model_DW.obj.TimerHandle);

  /* DataTypeConversion: '<Root>/Cast To Double7' */
  Encoder_model_B.CastToDouble7 = Encoder_model_B.QEI_X4_AMT_RAW;

  /* MATLAB Function: '<Root>/QEI_X4_Calculation AMT' */
  diff = Encoder_model_B.CastToDouble7 - Encoder_model_DW.pre_signal;
  if (diff < -28672.0) {
    Encoder_model_DW.pos += (57345.0 - Encoder_model_DW.pre_signal) +
      Encoder_model_B.CastToDouble7;
  } else if (diff > 28672.0) {
    Encoder_model_DW.pos -= (57345.0 - Encoder_model_B.CastToDouble7) +
      Encoder_model_DW.pre_signal;
  } else {
    Encoder_model_DW.pos += diff;
  }

  Encoder_model_B.position = Encoder_model_DW.pos / 8192.0 * 2.0 *
    3.1415926535897931;
  Encoder_model_B.velocity = (Encoder_model_DW.pos - Encoder_model_DW.pre_pos) /
    0.01 / 8192.0 * 6.2831853071795862;
  Encoder_model_DW.pre_signal = Encoder_model_B.CastToDouble7;
  Encoder_model_DW.pre_pos = Encoder_model_DW.pos;

  /* End of MATLAB Function: '<Root>/QEI_X4_Calculation AMT' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder_model_M->Timing.taskTime0 =
    ((time_T)(++Encoder_model_M->Timing.clockTick0)) *
    Encoder_model_M->Timing.stepSize0;
}

/* Model initialize function */
void Encoder_model_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Encoder_model_M, -1);
  Encoder_model_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Encoder_model_M->Sizes.checksums[0] = (1526560057U);
  Encoder_model_M->Sizes.checksums[1] = (3051958754U);
  Encoder_model_M->Sizes.checksums[2] = (4059441918U);
  Encoder_model_M->Sizes.checksums[3] = (1483817431U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Encoder_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_model_M->extModeInfo,
      &Encoder_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_model_M->extModeInfo,
                        Encoder_model_M->Sizes.checksums);
    rteiSetTPtr(Encoder_model_M->extModeInfo, rtmGetTPtr(Encoder_model_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder3' */
  Encoder_model_DW.obj_n.isInitialized = 0;
  Encoder_model_DW.obj_n.matlabCodegenIsDeleted = false;
  Encoder_model_SystemCore_setup(&Encoder_model_DW.obj_n);

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  Encoder_model_DW.obj_a.isInitialized = 0;
  Encoder_model_DW.obj_a.matlabCodegenIsDeleted = false;
  Encoder_mode_SystemCore_setup_g(&Encoder_model_DW.obj_a);

  /* Start for MATLABSystem: '<Root>/Encoder5' */
  Encoder_model_DW.obj.isInitialized = 0;
  Encoder_model_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_mod_SystemCore_setup_g1(&Encoder_model_DW.obj);
}

/* Model terminate function */
void Encoder_model_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder3' */
  if (!Encoder_model_DW.obj_n.matlabCodegenIsDeleted) {
    Encoder_model_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Encoder_model_DW.obj_n.isInitialized == 1) &&
        Encoder_model_DW.obj_n.isSetupComplete) {
      disableCounter(Encoder_model_DW.obj_n.TimerHandle);
      disableTimerInterrupts(Encoder_model_DW.obj_n.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_model_DW.obj_n.TimerHandle, ChannelInfo);
      disableTimerChannel2(Encoder_model_DW.obj_n.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder3' */
  /* Terminate for MATLABSystem: '<Root>/Encoder4' */
  if (!Encoder_model_DW.obj_a.matlabCodegenIsDeleted) {
    Encoder_model_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Encoder_model_DW.obj_a.isInitialized == 1) &&
        Encoder_model_DW.obj_a.isSetupComplete) {
      disableCounter(Encoder_model_DW.obj_a.TimerHandle);
      disableTimerInterrupts(Encoder_model_DW.obj_a.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_model_DW.obj_a.TimerHandle, ChannelInfo);
      disableTimerChannel2(Encoder_model_DW.obj_a.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder4' */
  /* Terminate for MATLABSystem: '<Root>/Encoder5' */
  if (!Encoder_model_DW.obj.matlabCodegenIsDeleted) {
    Encoder_model_DW.obj.matlabCodegenIsDeleted = true;
    if ((Encoder_model_DW.obj.isInitialized == 1) &&
        Encoder_model_DW.obj.isSetupComplete) {
      disableCounter(Encoder_model_DW.obj.TimerHandle);
      disableTimerInterrupts(Encoder_model_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_model_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(Encoder_model_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder5' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
