/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_model.h
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

#ifndef Encoder_model_h_
#define Encoder_model_h_
#ifndef Encoder_model_COMMON_INCLUDES_
#define Encoder_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
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
  real_T CastToDouble8;                /* '<Root>/Cast To Double8' */
  real_T CastToDouble9;                /* '<Root>/Cast To Double9' */
  real_T position;                     /* '<Root>/X4 AMT' */
  real_T velocity;                     /* '<Root>/X4 AMT' */
  real_T raw;                          /* '<Root>/X4 AMT' */
  real_T position_b;                   /* '<Root>/X2 AMT' */
  real_T velocity_j;                   /* '<Root>/X2 AMT' */
  real_T raw_p;                        /* '<Root>/X2 AMT' */
  real_T position_k;                   /* '<Root>/X1 AMT' */
  real_T velocity_j2;                  /* '<Root>/X1 AMT' */
  real_T raw_p3;                       /* '<Root>/X1 AMT' */
  boolean_T DigitalPortRead;           /* '<S9>/Digital Port Read' */
  boolean_T DigitalPortRead_m;         /* '<S7>/Digital Port Read' */
} B_Encoder_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T pre_A;                        /* '<Root>/X4 AMT' */
  real_T pre_B;                        /* '<Root>/X4 AMT' */
  real_T pos;                          /* '<Root>/X4 AMT' */
  real_T pre_pos;                      /* '<Root>/X4 AMT' */
  real_T pre_A_j;                      /* '<Root>/X2 AMT' */
  real_T pos_p;                        /* '<Root>/X2 AMT' */
  real_T pre_pos_b;                    /* '<Root>/X2 AMT' */
  real_T pre_A_h;                      /* '<Root>/X1 AMT' */
  real_T pos_k;                        /* '<Root>/X1 AMT' */
  real_T pre_pos_e;                    /* '<Root>/X1 AMT' */
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
 * '<S1>'   : 'Encoder_model/Digital Port Read2'
 * '<S2>'   : 'Encoder_model/Digital Port Read3'
 * '<S3>'   : 'Encoder_model/X1 AMT'
 * '<S4>'   : 'Encoder_model/X2 AMT'
 * '<S5>'   : 'Encoder_model/X4 AMT'
 * '<S6>'   : 'Encoder_model/Digital Port Read2/ECSoC'
 * '<S7>'   : 'Encoder_model/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S8>'   : 'Encoder_model/Digital Port Read3/ECSoC'
 * '<S9>'   : 'Encoder_model/Digital Port Read3/ECSoC/ECSimCodegen'
 */
#endif                                 /* Encoder_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
