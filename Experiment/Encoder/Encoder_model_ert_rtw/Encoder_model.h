/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_model.h
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

#ifndef Encoder_model_h_
#define Encoder_model_h_
#ifndef Encoder_model_COMMON_INCLUDES_
#define Encoder_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#endif                                 /* Encoder_model_COMMON_INCLUDES_ */

#include "Encoder_model_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T CastToDouble5;                /* '<Root>/Cast To Double5' */
  real_T CastToDouble6;                /* '<Root>/Cast To Double6' */
  real_T CastToDouble7;                /* '<Root>/Cast To Double7' */
  real_T velocity;                     /* '<Root>/QEI_X4_Calculation AMT' */
  real_T position;                     /* '<Root>/QEI_X4_Calculation AMT' */
  real_T velocity_g;                   /* '<Root>/QEI_X2_Calculation AMT' */
  real_T position_c;                   /* '<Root>/QEI_X2_Calculation AMT' */
  real_T velocity_e;                   /* '<Root>/QEI_X1_Calculation AMT' */
  real_T position_j;                   /* '<Root>/QEI_X1_Calculation AMT' */
  uint32_T QEI_X4_AMT_RAW;             /* '<Root>/Encoder5' */
  uint32_T QEI_X2_AMT_RAW;             /* '<Root>/Encoder4' */
  uint32_T QEI_X1_AMT_RAW;             /* '<Root>/Encoder3' */
  boolean_T DIR_X4;                    /* '<Root>/Encoder5' */
  boolean_T DIR_X2;                    /* '<Root>/Encoder4' */
  boolean_T DIR_X1;                    /* '<Root>/Encoder3' */
} B_Encoder_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder5' */
  stm32cube_blocks_EncoderBlock_T obj_a;/* '<Root>/Encoder4' */
  stm32cube_blocks_EncoderBlock_T obj_n;/* '<Root>/Encoder3' */
  real_T pos;                          /* '<Root>/QEI_X4_Calculation AMT' */
  real_T pre_signal;                   /* '<Root>/QEI_X4_Calculation AMT' */
  real_T pre_pos;                      /* '<Root>/QEI_X4_Calculation AMT' */
  real_T pos_g;                        /* '<Root>/QEI_X2_Calculation AMT' */
  real_T pre_signal_k;                 /* '<Root>/QEI_X2_Calculation AMT' */
  real_T pre_pos_m;                    /* '<Root>/QEI_X2_Calculation AMT' */
  real_T pos_h;                        /* '<Root>/QEI_X1_Calculation AMT' */
  real_T pre_signal_h;                 /* '<Root>/QEI_X1_Calculation AMT' */
  real_T pre_pos_a;                    /* '<Root>/QEI_X1_Calculation AMT' */
} DW_Encoder_model_T;

/* Real-time Model Data Structure */
struct tag_RTM_Encoder_model_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_Encoder_model_T Encoder_model_B;

/* Block states (default storage) */
extern DW_Encoder_model_T Encoder_model_DW;

/* Model entry point functions */
extern void Encoder_model_initialize(void);
extern void Encoder_model_step(void);
extern void Encoder_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Encoder_model_T *const Encoder_model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Encoder_model'
 * '<S1>'   : 'Encoder_model/QEI_X1_Calculation AMT'
 * '<S2>'   : 'Encoder_model/QEI_X2_Calculation AMT'
 * '<S3>'   : 'Encoder_model/QEI_X4_Calculation AMT'
 */
#endif                                 /* Encoder_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
