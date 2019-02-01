/*
 * sensorModel_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sensorModel".
 *
 * Model version              : 1.41
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Fri Dec 14 16:19:44 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: All passed
 */

#ifndef RTW_HEADER_sensorModel_private_h_
#define RTW_HEADER_sensorModel_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "sensorModel.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void sensorModel_Output(boolean_T rtu_uBlockOrdering,
  B_Output_sensorModel_T *localB, real_T *rtd_P, real_T *rtd_x);
extern void sensorMo_MeasurementUpdate_Init(B_MeasurementUpdate_sensorMod_T
  *localB, P_MeasurementUpdate_sensorMod_T *localP);
extern void senso_MeasurementUpdate_Disable(B_MeasurementUpdate_sensorMod_T
  *localB, DW_MeasurementUpdate_sensorMo_T *localDW,
  P_MeasurementUpdate_sensorMod_T *localP);
extern void sensorModel_MeasurementUpdate(RT_MODEL_sensorModel_T * const
  sensorModel_M, boolean_T rtu_Enable, real_T rtu_Lk, real_T rtu_yk, real_T
  rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_sensorMod_T *localB, DW_MeasurementUpdate_sensorMo_T
  *localDW, P_MeasurementUpdate_sensorMod_T *localP);
extern void sensorMod_EnabledSubsystem_Init(B_EnabledSubsystem_sensorMode_T
  *localB, P_EnabledSubsystem_sensorMode_T *localP);
extern void sensor_EnabledSubsystem_Disable(B_EnabledSubsystem_sensorMode_T
  *localB, DW_EnabledSubsystem_sensorMod_T *localDW,
  P_EnabledSubsystem_sensorMode_T *localP);
extern void sensorModel_EnabledSubsystem(RT_MODEL_sensorModel_T * const
  sensorModel_M, boolean_T rtu_Enable, real_T rtu_Mk, real_T rtu_Ck, real_T
  rtu_yk, real_T rtu_xhatkk1, B_EnabledSubsystem_sensorMode_T *localB,
  DW_EnabledSubsystem_sensorMod_T *localDW, P_EnabledSubsystem_sensorMode_T
  *localP);
extern void sensorModel_MATLABFunction(real_T rtu_dms, real_T *rty_decideg);

/* private model entry point functions */
extern void sensorModel_derivatives(void);

#endif                                 /* RTW_HEADER_sensorModel_private_h_ */
