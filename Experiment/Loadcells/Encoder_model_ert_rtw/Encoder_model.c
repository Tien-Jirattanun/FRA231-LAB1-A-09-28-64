/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_model.c
 *
 * Code generated for Simulink model 'Encoder_model'.
 *
 * Model version                  : 1.202
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Nov  1 00:57:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder_model.h"
#include "rtwtypes.h"
#include "Encoder_model_private.h"

/* Block signals (default storage) */
B_Encoder_model_T Encoder_model_B;

/* Block states (default storage) */
DW_Encoder_model_T Encoder_model_DW;

/* Real-time model */
static RT_MODEL_Encoder_model_T Encoder_model_M_;
RT_MODEL_Encoder_model_T *const Encoder_model_M = &Encoder_model_M_;

/* Model step function */
void Encoder_model_step(void)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S7>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S7>/Digital Port Read' */
  Encoder_model_B.DigitalPortRead_m = ((pinReadLoc & 32U) != 0U);

  /* DataTypeConversion: '<Root>/Cast To Double8' */
  Encoder_model_B.CastToDouble8 = Encoder_model_B.DigitalPortRead_m;

  /* MATLABSystem: '<S9>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S9>/Digital Port Read' */
  Encoder_model_B.DigitalPortRead = ((pinReadLoc & 1024U) != 0U);

  /* DataTypeConversion: '<Root>/Cast To Double9' */
  Encoder_model_B.CastToDouble9 = Encoder_model_B.DigitalPortRead;

  /* MATLAB Function: '<Root>/X1 AMT' */
  if ((Encoder_model_B.CastToDouble8 == 0.0) && (Encoder_model_DW.pre_A_h == 1.0))
  {
    if (Encoder_model_B.CastToDouble9 == 1.0) {
      Encoder_model_DW.pos_k++;
    } else {
      Encoder_model_DW.pos_k--;
    }
  }

  Encoder_model_B.velocity_j2 = (Encoder_model_DW.pos_k -
    Encoder_model_DW.pre_pos_e) / 0.01 / 2048.0 * 6.2831853071795862;
  Encoder_model_B.position_k = Encoder_model_DW.pos_k / 2048.0 * 2.0 *
    3.1415926535897931;
  Encoder_model_B.raw_p3 = Encoder_model_DW.pos_k;
  Encoder_model_DW.pre_pos_e = Encoder_model_DW.pos_k;
  Encoder_model_DW.pre_A_h = Encoder_model_B.CastToDouble8;

  /* End of MATLAB Function: '<Root>/X1 AMT' */
  /* MATLAB Function: '<Root>/X2 AMT' */
  if ((Encoder_model_B.CastToDouble8 == 0.0) && (Encoder_model_DW.pre_A_j == 1.0))
  {
    if (Encoder_model_B.CastToDouble9 == 1.0) {
      Encoder_model_DW.pos_p++;
    } else {
      Encoder_model_DW.pos_p--;
    }
  }

  if ((Encoder_model_B.CastToDouble8 == 1.0) && (Encoder_model_DW.pre_A_j == 0.0))
  {
    if (Encoder_model_B.CastToDouble9 == 0.0) {
      Encoder_model_DW.pos_p++;
    } else {
      Encoder_model_DW.pos_p--;
    }
  }

  Encoder_model_B.velocity_j = (Encoder_model_DW.pos_p -
    Encoder_model_DW.pre_pos_b) / 0.01 / 4096.0 * 6.2831853071795862;
  Encoder_model_B.position_b = Encoder_model_DW.pos_p / 4096.0 * 2.0 *
    3.1415926535897931;
  Encoder_model_B.raw_p = Encoder_model_DW.pos_p;
  Encoder_model_DW.pre_pos_b = Encoder_model_DW.pos_p;
  Encoder_model_DW.pre_A_j = Encoder_model_B.CastToDouble8;

  /* End of MATLAB Function: '<Root>/X2 AMT' */
  /* MATLAB Function: '<Root>/X4 AMT' */
  if ((Encoder_model_B.CastToDouble8 == 0.0) && (Encoder_model_DW.pre_A == 1.0))
  {
    if (Encoder_model_B.CastToDouble9 == 1.0) {
      Encoder_model_DW.pos++;
    } else {
      Encoder_model_DW.pos--;
    }
  }

  if ((Encoder_model_B.CastToDouble8 == 1.0) && (Encoder_model_DW.pre_A == 0.0))
  {
    if (Encoder_model_B.CastToDouble9 == 0.0) {
      Encoder_model_DW.pos++;
    } else {
      Encoder_model_DW.pos--;
    }
  }

  if ((Encoder_model_B.CastToDouble9 == 0.0) && (Encoder_model_DW.pre_B == 1.0))
  {
    if (Encoder_model_B.CastToDouble8 == 0.0) {
      Encoder_model_DW.pos++;
    } else {
      Encoder_model_DW.pos--;
    }
  }

  if ((Encoder_model_B.CastToDouble9 == 1.0) && (Encoder_model_DW.pre_B == 0.0))
  {
    if (Encoder_model_B.CastToDouble8 == 1.0) {
      Encoder_model_DW.pos++;
    } else {
      Encoder_model_DW.pos--;
    }
  }

  Encoder_model_B.velocity = (Encoder_model_DW.pos - Encoder_model_DW.pre_pos) /
    0.01 / 8192.0 * 6.2831853071795862;
  Encoder_model_B.position = Encoder_model_DW.pos / 8192.0 * 2.0 *
    3.1415926535897931;
  Encoder_model_B.raw = Encoder_model_DW.pos;
  Encoder_model_DW.pre_pos = Encoder_model_DW.pos;
  Encoder_model_DW.pre_A = Encoder_model_B.CastToDouble8;
  Encoder_model_DW.pre_B = Encoder_model_B.CastToDouble9;

  /* End of MATLAB Function: '<Root>/X4 AMT' */

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
  Encoder_model_M->Sizes.checksums[0] = (2699838577U);
  Encoder_model_M->Sizes.checksums[1] = (4202322398U);
  Encoder_model_M->Sizes.checksums[2] = (2293565725U);
  Encoder_model_M->Sizes.checksums[3] = (2847369904U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Encoder_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_model_M->extModeInfo,
      &Encoder_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_model_M->extModeInfo,
                        Encoder_model_M->Sizes.checksums);
    rteiSetTPtr(Encoder_model_M->extModeInfo, rtmGetTPtr(Encoder_model_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/X1 AMT' */
  Encoder_model_DW.pre_A_h = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/X2 AMT' */
  Encoder_model_DW.pre_A_j = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/X4 AMT' */
  Encoder_model_DW.pre_A = 1.0;
  Encoder_model_DW.pre_B = 1.0;
}

/* Model terminate function */
void Encoder_model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
