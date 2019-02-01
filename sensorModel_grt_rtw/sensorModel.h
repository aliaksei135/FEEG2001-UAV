/*
 * sensorModel.h
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

#ifndef RTW_HEADER_sensorModel_h_
#define RTW_HEADER_sensorModel_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef sensorModel_COMMON_INCLUDES_
# define sensorModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MW_SerialRead.h"
#include "gps_parser.h"
#endif                                 /* sensorModel_COMMON_INCLUDES_ */

#include "sensorModel_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals for system '<S5>/Output' */
typedef struct {
  real_T DataStoreRead;                /* '<S21>/Data Store Read' */
  real_T DataStoreRead1;               /* '<S21>/Data Store Read1' */
  boolean_T uBlockOrdering;            /* '<S21>/uBlockOrdering' */
} B_Output_sensorModel_T;

/* Block signals for system '<S50>/MeasurementUpdate' */
typedef struct {
  real_T Ckxhatkk1;                    /* '<S75>/C[k]*xhat[k|k-1]' */
  real_T Dkuk;                         /* '<S75>/D[k]*u[k]' */
  real_T yhatkk1;                      /* '<S75>/Add1' */
  real_T Sum;                          /* '<S75>/Sum' */
  real_T Product3;                     /* '<S75>/Product3' */
} B_MeasurementUpdate_sensorMod_T;

/* Block states (default storage) for system '<S50>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S50>/MeasurementUpdate' */
} DW_MeasurementUpdate_sensorMo_T;

/* Block signals for system '<S55>/Enabled Subsystem' */
typedef struct {
  real_T Product;                      /* '<S76>/Product' */
  real_T Add1;                         /* '<S76>/Add1' */
  real_T Product2;                     /* '<S76>/Product2' */
} B_EnabledSubsystem_sensorMode_T;

/* Block states (default storage) for system '<S55>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S55>/Enabled Subsystem' */
} DW_EnabledSubsystem_sensorMod_T;

/* Block signals (default storage) */
typedef struct {
  real_T MemoryX;                      /* '<S7>/MemoryX' */
  real_T Add;                          /* '<S55>/Add' */
  real_T MemoryX_p;                    /* '<S8>/MemoryX' */
  real_T Add_a;                        /* '<S99>/Add' */
  real_T MemoryX_n;                    /* '<S12>/MemoryX' */
  real_T Add_c;                        /* '<S275>/Add' */
  real_T MemoryX_c;                    /* '<S13>/MemoryX' */
  real_T Add_j;                        /* '<S319>/Add' */
  real_T MemoryX_l;                    /* '<S14>/MemoryX' */
  real_T Add_p;                        /* '<S363>/Add' */
  real_T Integrator6;                  /* '<Root>/Integrator6' */
  real_T Integrator7;                  /* '<Root>/Integrator7' */
  real_T Integrator8;                  /* '<Root>/Integrator8' */
  real_T Integrator9;                  /* '<Root>/Integrator9' */
  real_T Integrator10;                 /* '<Root>/Integrator10' */
  real_T Integrator11;                 /* '<Root>/Integrator11' */
  real_T Subtract2;                    /* '<Root>/Subtract2' */
  real_T Divide;                       /* '<Root>/Divide' */
  real_T Subtract3;                    /* '<Root>/Subtract3' */
  real_T Heading;                      /* '<Root>/Hdg Selector' */
  real_T VectorConcatenate[3];         /* '<S18>/Vector Concatenate' */
  real_T Abs2[3];                      /* '<Root>/Abs2' */
  real_T MinMax;                       /* '<Root>/MinMax' */
  real_T ZeroOrderHold[3];             /* '<Root>/Zero-Order Hold' */
  real_T ZeroOrderHold1[3];            /* '<Root>/Zero-Order Hold1' */
  real_T Akxhatkk1;                    /* '<S50>/A[k]*xhat[k|k-1]' */
  real_T Bkuk;                         /* '<S50>/B[k]*u[k]' */
  real_T Add_l;                        /* '<S50>/Add' */
  real_T Akxhatkk1_e;                  /* '<S94>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_i;                       /* '<S94>/B[k]*u[k]' */
  real_T Add_o;                        /* '<S94>/Add' */
  real_T Akxhatkk1_n;                  /* '<S270>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_l;                       /* '<S270>/B[k]*u[k]' */
  real_T Add_f;                        /* '<S270>/Add' */
  real_T Akxhatkk1_f;                  /* '<S314>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_a;                       /* '<S314>/B[k]*u[k]' */
  real_T Add_oz;                       /* '<S314>/Add' */
  real_T Akxhatkk1_eo;                 /* '<S358>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_o;                       /* '<S358>/B[k]*u[k]' */
  real_T Add_d;                        /* '<S358>/Add' */
  real_T MemoryX_l4;                   /* '<S9>/MemoryX' */
  real_T Add_n;                        /* '<S143>/Add' */
  real_T MemoryX_m;                    /* '<S10>/MemoryX' */
  real_T Add_d0;                       /* '<S187>/Add' */
  real_T MemoryX_mi;                   /* '<S11>/MemoryX' */
  real_T Add_m;                        /* '<S231>/Add' */
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T Integrator3;                  /* '<Root>/Integrator3' */
  real_T Integrator4;                  /* '<Root>/Integrator4' */
  real_T Integrator5;                  /* '<Root>/Integrator5' */
  real_T Akxhatkk1_fm;                 /* '<S138>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_f;                       /* '<S138>/B[k]*u[k]' */
  real_T Add_b;                        /* '<S138>/Add' */
  real_T Akxhatkk1_np;                 /* '<S182>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_g;                       /* '<S182>/B[k]*u[k]' */
  real_T Add_g;                        /* '<S182>/Add' */
  real_T Akxhatkk1_i;                  /* '<S226>/A[k]*xhat[k|k-1]' */
  real_T Bkuk_f2;                      /* '<S226>/B[k]*u[k]' */
  real_T Add_l4;                       /* '<S226>/Add' */
  real_T TmpMLSysMemLayoutBufferAtMATLAB;/* '<S386>/MATLAB_System' */
  real_T TmpMLSysMemLayoutBufferAtMATL_e;/* '<S386>/MATLAB_System' */
  real_T MATLAB_System_o2;             /* '<S386>/MATLAB_System' */
  real_T MATLAB_System_o3;             /* '<S386>/MATLAB_System' */
  real_T MATLAB_System_o5;             /* '<S386>/MATLAB_System' */
  real_T MATLAB_System_o6;             /* '<S386>/MATLAB_System' */
  real_T MATLAB_System_o7;             /* '<S386>/MATLAB_System' */
  real_T TmpSignalConversionAtSFunctionI[3];/* '<S16>/MATLAB Function' */
  real_T hdg_deg;                      /* '<S16>/MATLAB Function' */
  real_T DataStoreReadX;               /* '<S29>/Data Store ReadX' */
  real_T xNew;                         /* '<S29>/Predict' */
  real_T P;                            /* '<S29>/Predict' */
  real_T DataStoreReadX_l;             /* '<S27>/Data Store ReadX' */
  real_T xNew_g;                       /* '<S27>/Correct' */
  real_T P_e;                          /* '<S27>/Correct' */
  real_T DataStoreReadX_b;             /* '<S26>/Data Store ReadX' */
  real_T xNew_i;                       /* '<S26>/Correct' */
  real_T P_i;                          /* '<S26>/Correct' */
  real_T DataStoreReadX_i;             /* '<S22>/Data Store ReadX' */
  real_T xNew_n;                       /* '<S22>/Predict' */
  real_T P_l;                          /* '<S22>/Predict' */
  real_T DataStoreReadX_k;             /* '<S20>/Data Store ReadX' */
  real_T xNew_d;                       /* '<S20>/Correct' */
  real_T P_j;                          /* '<S20>/Correct' */
  real_T DataStoreReadX_d;             /* '<S19>/Data Store ReadX' */
  real_T xNew_b;                       /* '<S19>/Correct' */
  real_T P_ec;                         /* '<S19>/Correct' */
  real_T GPS_LLA[3];                   /* '<Root>/Median Filter' */
  real32_T Altitude;                   /* '<Root>/Alt Selector' */
  uint8_T MATLAB_System_o4;            /* '<S386>/MATLAB_System' */
  uint8_T RawSerialdata[32];           /* '<S18>/Serial_Receive1' */
  uint8_T Serial_Receive1_o2;          /* '<S18>/Serial_Receive1' */
  int8_T MATLAB_System_o1;             /* '<S386>/MATLAB_System' */
  boolean_T Compare;                   /* '<S17>/Compare' */
  boolean_T min_relop;                 /* '<S2>/min_relop' */
  boolean_T max_relop;                 /* '<S2>/max_relop' */
  boolean_T conjunction;               /* '<S2>/conjunction' */
  boolean_T PRESS_OOB_ERROR;           /* '<Root>/NOT' */
  boolean_T min_relop_i;               /* '<S3>/min_relop' */
  boolean_T max_relop_o;               /* '<S3>/max_relop' */
  boolean_T conjunction_a;             /* '<S3>/conjunction' */
  boolean_T TEMP_OOB_ERROR;            /* '<Root>/NOT1' */
  boolean_T max_relop_e;               /* '<S4>/max_relop' */
  boolean_T blockOrdering;             /* '<S27>/Correct' */
  boolean_T blockOrdering_o;           /* '<S26>/Correct' */
  boolean_T blockOrdering_a;           /* '<S20>/Correct' */
  boolean_T blockOrdering_g;           /* '<S19>/Correct' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_ej;/* '<S363>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_p;/* '<S358>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_e;/* '<S319>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_el;/* '<S314>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_p;/* '<S275>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_kg;/* '<S270>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_n;/* '<S231>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_kv;/* '<S226>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_k;/* '<S187>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_k;/* '<S182>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_f;/* '<S143>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_ec;/* '<S138>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem_a;/* '<S99>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate_e;/* '<S94>/MeasurementUpdate' */
  B_EnabledSubsystem_sensorMode_T EnabledSubsystem;/* '<S55>/Enabled Subsystem' */
  B_MeasurementUpdate_sensorMod_T MeasurementUpdate;/* '<S50>/MeasurementUpdate' */
  B_Output_sensorModel_T Output_d;     /* '<S6>/Output' */
  B_Output_sensorModel_T Output;       /* '<S5>/Output' */
} B_sensorModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_MedianFilter_sensorModel_T obj;  /* '<Root>/Median Filter' */
  GPSParser_sensorModel_T obj_m;       /* '<S386>/MATLAB_System' */
  real_T MemoryX_DSTATE;               /* '<S7>/MemoryX' */
  real_T MemoryX_DSTATE_n;             /* '<S8>/MemoryX' */
  real_T MemoryX_DSTATE_a;             /* '<S12>/MemoryX' */
  real_T MemoryX_DSTATE_b;             /* '<S13>/MemoryX' */
  real_T MemoryX_DSTATE_p;             /* '<S14>/MemoryX' */
  real_T MemoryX_DSTATE_c;             /* '<S9>/MemoryX' */
  real_T MemoryX_DSTATE_pl;            /* '<S10>/MemoryX' */
  real_T MemoryX_DSTATE_bc;            /* '<S11>/MemoryX' */
  real_T P;                            /* '<S5>/DataStoreMemory - P' */
  real_T x;                            /* '<S5>/DataStoreMemory - x' */
  real_T P_k;                          /* '<S6>/DataStoreMemory - P' */
  real_T x_f;                          /* '<S6>/DataStoreMemory - x' */
  codertarget_arduinobase_inter_T obj_b;/* '<S18>/Serial_Receive1' */
  uint8_T icLoad;                      /* '<S7>/MemoryX' */
  uint8_T icLoad_j;                    /* '<S8>/MemoryX' */
  uint8_T icLoad_o;                    /* '<S12>/MemoryX' */
  uint8_T icLoad_o2;                   /* '<S13>/MemoryX' */
  uint8_T icLoad_e;                    /* '<S14>/MemoryX' */
  uint8_T icLoad_ow;                   /* '<S9>/MemoryX' */
  uint8_T icLoad_p;                    /* '<S10>/MemoryX' */
  uint8_T icLoad_n;                    /* '<S11>/MemoryX' */
  boolean_T objisempty;                /* '<S386>/MATLAB_System' */
  boolean_T objisempty_l;              /* '<S18>/Serial_Receive1' */
  boolean_T objisempty_f;              /* '<Root>/Median Filter' */
  boolean_T GPGGA_GPRMC_Parser1_MODE;  /* '<S18>/$GPGGA_$GPRMC_Parser1' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_ej;/* '<S363>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_p;/* '<S358>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_e;/* '<S319>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_el;/* '<S314>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_p;/* '<S275>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_kg;/* '<S270>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_n;/* '<S231>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_kv;/* '<S226>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_k;/* '<S187>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_k;/* '<S182>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_f;/* '<S143>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_ec;/* '<S138>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem_a;/* '<S99>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate_e;/* '<S94>/MeasurementUpdate' */
  DW_EnabledSubsystem_sensorMod_T EnabledSubsystem;/* '<S55>/Enabled Subsystem' */
  DW_MeasurementUpdate_sensorMo_T MeasurementUpdate;/* '<S50>/MeasurementUpdate' */
} DW_sensorModel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<Root>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<Root>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<Root>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<Root>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<Root>/Integrator11' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
} X_sensorModel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<Root>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<Root>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<Root>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<Root>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<Root>/Integrator11' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
} XDot_sensorModel_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator6_CSTATE;        /* '<Root>/Integrator6' */
  boolean_T Integrator7_CSTATE;        /* '<Root>/Integrator7' */
  boolean_T Integrator8_CSTATE;        /* '<Root>/Integrator8' */
  boolean_T Integrator9_CSTATE;        /* '<Root>/Integrator9' */
  boolean_T Integrator10_CSTATE;       /* '<Root>/Integrator10' */
  boolean_T Integrator11_CSTATE;       /* '<Root>/Integrator11' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<Root>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<Root>/Integrator5' */
} XDis_sensorModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Pressure;                     /* '<Root>/Pressure' */
  real_T Temperature;                  /* '<Root>/Temperature' */
  real_T omega_dot[3];                 /* '<Root>/omega_dot' */
  real_T omega[3];                     /* '<Root>/omega' */
  real_T phi_theta_psi[3];             /* '<Root>/phi_theta_psi' */
  real_T A_be[3];                      /* '<Root>/A_{be}' */
  real_T V_b[3];                       /* '<Root>/V_{b}' */
  real_T X_e[3];                       /* '<Root>/X_{e}' */
  real_T Heading;                      /* '<Root>/Heading' */
  real_T GPS_LLA[3];                   /* '<Root>/GPS_LLA' */
  real_T GPS_GS;                       /* '<Root>/GPS_GS' */
  real32_T Altitude;                   /* '<Root>/Altitude' */
  boolean_T PRESS_OOB_ERROR;           /* '<Root>/PRESS_OOB_ERROR' */
  boolean_T TEMP_OOB_ERROR;            /* '<Root>/TEMP_OOB_ERROR' */
  boolean_T AIRFRAME_G_LIMIT_EXCEEDED; /* '<Root>/AIRFRAME_G_LIMIT_EXCEEDED' */
  boolean_T GPS_FIX_BAD;               /* '<Root>/GPS_FIX_BAD' */
} ExtY_sensorModel_T;

/* Parameters for system: '<S50>/MeasurementUpdate' */
struct P_MeasurementUpdate_sensorMod_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S75>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S55>/Enabled Subsystem' */
struct P_EnabledSubsystem_sensorMode_T_ {
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S76>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_sensorModel_T_ {
  real_T magVar;                       /* Variable: magVar
                                        * Referenced by: '<Root>/MagVar'
                                        */
  real_T CheckStaticRange_max;         /* Mask Parameter: CheckStaticRange_max
                                        * Referenced by: '<S2>/max_val'
                                        */
  real_T CheckStaticRange1_max;        /* Mask Parameter: CheckStaticRange1_max
                                        * Referenced by: '<S3>/max_val'
                                        */
  real_T CheckStaticUpperBound_max;    /* Mask Parameter: CheckStaticUpperBound_max
                                        * Referenced by: '<S4>/max_val'
                                        */
  real_T CheckStaticRange_min;         /* Mask Parameter: CheckStaticRange_min
                                        * Referenced by: '<S2>/min_val'
                                        */
  real_T CheckStaticRange1_min;        /* Mask Parameter: CheckStaticRange1_min
                                        * Referenced by: '<S3>/min_val'
                                        */
  uint8_T MinNumofSatsforgoodfix_const;/* Mask Parameter: MinNumofSatsforgoodfix_const
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T lat_Y0;                       /* Expression: 0
                                        * Referenced by: '<S386>/lat'
                                        */
  real_T long_Y0;                      /* Computed Parameter: long_Y0
                                        * Referenced by: '<S386>/long'
                                        */
  real_T alt_m_Y0;                     /* Computed Parameter: alt_m_Y0
                                        * Referenced by: '<S386>/alt_m'
                                        */
  real_T speed_kt_Y0;                  /* Computed Parameter: speed_kt_Y0
                                        * Referenced by: '<S386>/speed_kt'
                                        */
  real_T trkAngle_deg_true_Y0;         /* Computed Parameter: trkAngle_deg_true_Y0
                                        * Referenced by: '<S386>/trkAngle_deg_true'
                                        */
  real_T KalmanGainM_Value;            /* Expression: pInitialization.M
                                        * Referenced by: '<S33>/KalmanGainM'
                                        */
  real_T C_Value;                      /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T X0_Value;                     /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T KalmanGainM_Value_o;          /* Expression: pInitialization.M
                                        * Referenced by: '<S77>/KalmanGainM'
                                        */
  real_T C_Value_k;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S8>/C'
                                        */
  real_T X0_Value_l;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S8>/X0'
                                        */
  real_T KalmanGainM_Value_n;          /* Expression: pInitialization.M
                                        * Referenced by: '<S253>/KalmanGainM'
                                        */
  real_T C_Value_p;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S12>/C'
                                        */
  real_T X0_Value_i;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S12>/X0'
                                        */
  real_T KalmanGainM_Value_j;          /* Expression: pInitialization.M
                                        * Referenced by: '<S297>/KalmanGainM'
                                        */
  real_T C_Value_i;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S13>/C'
                                        */
  real_T X0_Value_c;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S13>/X0'
                                        */
  real_T KalmanGainM_Value_m;          /* Expression: pInitialization.M
                                        * Referenced by: '<S341>/KalmanGainM'
                                        */
  real_T C_Value_m;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S14>/C'
                                        */
  real_T X0_Value_iz;                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S14>/X0'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator6'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator7'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator8'
                                        */
  real_T Integrator9_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator9'
                                        */
  real_T Integrator10_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator10'
                                        */
  real_T Integrator11_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator11'
                                        */
  real_T Constant1_Value;              /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 4
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T MeasurementFcn2Inputs_Value;  /* Expression: 1
                                        * Referenced by: '<S5>/MeasurementFcn2Inputs'
                                        */
  real_T R1_Value;                     /* Expression: p.R{1}
                                        * Referenced by: '<S5>/R1'
                                        */
  real_T MeasurementFcn1Inputs_Value;  /* Expression: 0
                                        * Referenced by: '<S5>/MeasurementFcn1Inputs'
                                        */
  real_T R2_Value;                     /* Expression: p.R{2}
                                        * Referenced by: '<S6>/R2'
                                        */
  real_T MeasurementFcn2Inputs_Value_g;/* Expression: 1
                                        * Referenced by: '<S6>/MeasurementFcn2Inputs'
                                        */
  real_T MeasurementFcn1Inputs_Value_p;/* Expression: 0
                                        * Referenced by: '<S6>/MeasurementFcn1Inputs'
                                        */
  real_T Q_Value;                      /* Expression: p.Q
                                        * Referenced by: '<S5>/Q'
                                        */
  real_T DataStoreMemoryP_InitialValue;/* Expression: p.InitialCovariance
                                        * Referenced by: '<S5>/DataStoreMemory - P'
                                        */
  real_T DataStoreMemoryx_InitialValue;/* Expression: p.InitialState
                                        * Referenced by: '<S5>/DataStoreMemory - x'
                                        */
  real_T Q_Value_c;                    /* Expression: p.Q
                                        * Referenced by: '<S6>/Q'
                                        */
  real_T DataStoreMemoryP_InitialValue_e;/* Expression: p.InitialCovariance
                                          * Referenced by: '<S6>/DataStoreMemory - P'
                                          */
  real_T DataStoreMemoryx_InitialValue_j;/* Expression: p.InitialState
                                          * Referenced by: '<S6>/DataStoreMemory - x'
                                          */
  real_T A_Value;                      /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value;                      /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T KalmanGainL_Value;            /* Expression: pInitialization.L
                                        * Referenced by: '<S33>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T u_Value;                      /* Expression: 0
                                        * Referenced by: '<S7>/u'
                                        */
  real_T A_Value_h;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S8>/A'
                                        */
  real_T B_Value_i;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S8>/B'
                                        */
  real_T KalmanGainL_Value_d;          /* Expression: pInitialization.L
                                        * Referenced by: '<S77>/KalmanGainL'
                                        */
  real_T D_Value_a;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S8>/D'
                                        */
  real_T u_Value_g;                    /* Expression: 0
                                        * Referenced by: '<S8>/u'
                                        */
  real_T A_Value_i;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S12>/A'
                                        */
  real_T B_Value_e;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S12>/B'
                                        */
  real_T KalmanGainL_Value_p;          /* Expression: pInitialization.L
                                        * Referenced by: '<S253>/KalmanGainL'
                                        */
  real_T D_Value_m;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S12>/D'
                                        */
  real_T u_Value_p;                    /* Expression: 0
                                        * Referenced by: '<S12>/u'
                                        */
  real_T A_Value_j;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S13>/A'
                                        */
  real_T B_Value_f;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S13>/B'
                                        */
  real_T KalmanGainL_Value_h;          /* Expression: pInitialization.L
                                        * Referenced by: '<S297>/KalmanGainL'
                                        */
  real_T D_Value_am;                   /* Expression: pInitialization.D
                                        * Referenced by: '<S13>/D'
                                        */
  real_T u_Value_o;                    /* Expression: 0
                                        * Referenced by: '<S13>/u'
                                        */
  real_T A_Value_hv;                   /* Expression: pInitialization.A
                                        * Referenced by: '<S14>/A'
                                        */
  real_T B_Value_b;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S14>/B'
                                        */
  real_T KalmanGainL_Value_a;          /* Expression: pInitialization.L
                                        * Referenced by: '<S341>/KalmanGainL'
                                        */
  real_T D_Value_h;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S14>/D'
                                        */
  real_T u_Value_b;                    /* Expression: 0
                                        * Referenced by: '<S14>/u'
                                        */
  real_T KalmanGainM_Value_f;          /* Expression: pInitialization.M
                                        * Referenced by: '<S121>/KalmanGainM'
                                        */
  real_T C_Value_j;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T X0_Value_ld;                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S9>/X0'
                                        */
  real_T KalmanGainM_Value_i;          /* Expression: pInitialization.M
                                        * Referenced by: '<S165>/KalmanGainM'
                                        */
  real_T C_Value_l;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S10>/C'
                                        */
  real_T X0_Value_n;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S10>/X0'
                                        */
  real_T KalmanGainM_Value_k;          /* Expression: pInitialization.M
                                        * Referenced by: '<S209>/KalmanGainM'
                                        */
  real_T C_Value_b;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S11>/C'
                                        */
  real_T X0_Value_g;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S11>/X0'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator5'
                                        */
  real_T A_Value_k;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S9>/A'
                                        */
  real_T B_Value_k;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S9>/B'
                                        */
  real_T KalmanGainL_Value_hr;         /* Expression: pInitialization.L
                                        * Referenced by: '<S121>/KalmanGainL'
                                        */
  real_T D_Value_j;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S9>/D'
                                        */
  real_T u_Value_gd;                   /* Expression: 0
                                        * Referenced by: '<S9>/u'
                                        */
  real_T A_Value_ih;                   /* Expression: pInitialization.A
                                        * Referenced by: '<S10>/A'
                                        */
  real_T B_Value_h;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S10>/B'
                                        */
  real_T KalmanGainL_Value_i;          /* Expression: pInitialization.L
                                        * Referenced by: '<S165>/KalmanGainL'
                                        */
  real_T D_Value_g;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S10>/D'
                                        */
  real_T u_Value_ou;                   /* Expression: 0
                                        * Referenced by: '<S10>/u'
                                        */
  real_T A_Value_n;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S11>/A'
                                        */
  real_T B_Value_a;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S11>/B'
                                        */
  real_T KalmanGainL_Value_o;          /* Expression: pInitialization.L
                                        * Referenced by: '<S209>/KalmanGainL'
                                        */
  real_T D_Value_mn;                   /* Expression: pInitialization.D
                                        * Referenced by: '<S11>/D'
                                        */
  real_T u_Value_j;                    /* Expression: 0
                                        * Referenced by: '<S11>/u'
                                        */
  uint32_T MemoryX_DelayLength;        /* Computed Parameter: MemoryX_DelayLength
                                        * Referenced by: '<S7>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_o;      /* Computed Parameter: MemoryX_DelayLength_o
                                        * Referenced by: '<S8>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_n;      /* Computed Parameter: MemoryX_DelayLength_n
                                        * Referenced by: '<S12>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_d;      /* Computed Parameter: MemoryX_DelayLength_d
                                        * Referenced by: '<S13>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_dt;     /* Computed Parameter: MemoryX_DelayLength_dt
                                        * Referenced by: '<S14>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_p;      /* Computed Parameter: MemoryX_DelayLength_p
                                        * Referenced by: '<S9>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_c;      /* Computed Parameter: MemoryX_DelayLength_c
                                        * Referenced by: '<S10>/MemoryX'
                                        */
  uint32_T MemoryX_DelayLength_f;      /* Computed Parameter: MemoryX_DelayLength_f
                                        * Referenced by: '<S11>/MemoryX'
                                        */
  boolean_T yBlockOrdering_Y0;         /* Computed Parameter: yBlockOrdering_Y0
                                        * Referenced by: '<S19>/yBlockOrdering'
                                        */
  boolean_T yBlockOrdering_Y0_o;       /* Computed Parameter: yBlockOrdering_Y0_o
                                        * Referenced by: '<S20>/yBlockOrdering'
                                        */
  boolean_T yBlockOrdering_Y0_h;       /* Computed Parameter: yBlockOrdering_Y0_h
                                        * Referenced by: '<S26>/yBlockOrdering'
                                        */
  boolean_T yBlockOrdering_Y0_i;       /* Computed Parameter: yBlockOrdering_Y0_i
                                        * Referenced by: '<S27>/yBlockOrdering'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  boolean_T Enable_Value_c;            /* Expression: true()
                                        * Referenced by: '<S8>/Enable'
                                        */
  boolean_T Enable_Value_o;            /* Expression: true()
                                        * Referenced by: '<S12>/Enable'
                                        */
  boolean_T Enable_Value_f;            /* Expression: true()
                                        * Referenced by: '<S13>/Enable'
                                        */
  boolean_T Enable_Value_l;            /* Expression: true()
                                        * Referenced by: '<S14>/Enable'
                                        */
  boolean_T BlockOrdering_Value;       /* Expression: true()
                                        * Referenced by: '<S5>/BlockOrdering'
                                        */
  boolean_T Enable1_Value;             /* Expression: true()
                                        * Referenced by: '<S5>/Enable1'
                                        */
  boolean_T Enable2_Value;             /* Expression: true()
                                        * Referenced by: '<S5>/Enable2'
                                        */
  boolean_T BlockOrdering_Value_c;     /* Expression: true()
                                        * Referenced by: '<S6>/BlockOrdering'
                                        */
  boolean_T Enable1_Value_n;           /* Expression: true()
                                        * Referenced by: '<S6>/Enable1'
                                        */
  boolean_T Enable2_Value_k;           /* Expression: true()
                                        * Referenced by: '<S6>/Enable2'
                                        */
  boolean_T Enable_Value_c5;           /* Expression: true()
                                        * Referenced by: '<S9>/Enable'
                                        */
  boolean_T Enable_Value_j;            /* Expression: true()
                                        * Referenced by: '<S10>/Enable'
                                        */
  boolean_T Enable_Value_e;            /* Expression: true()
                                        * Referenced by: '<S11>/Enable'
                                        */
  uint8_T num_sat_Y0;                  /* Computed Parameter: num_sat_Y0
                                        * Referenced by: '<S386>/num_sat'
                                        */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_ej;/* '<S363>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_p;/* '<S358>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_e;/* '<S319>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_el;/* '<S314>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_p;/* '<S275>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_kg;/* '<S270>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_n;/* '<S231>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_kv;/* '<S226>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_k;/* '<S187>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_k;/* '<S182>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_f;/* '<S143>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_ec;/* '<S138>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem_a;/* '<S99>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate_e;/* '<S94>/MeasurementUpdate' */
  P_EnabledSubsystem_sensorMode_T EnabledSubsystem;/* '<S55>/Enabled Subsystem' */
  P_MeasurementUpdate_sensorMod_T MeasurementUpdate;/* '<S50>/MeasurementUpdate' */
};

/* Real-time Model Data Structure */
struct tag_RTM_sensorModel_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_sensorModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint16_T TID[5];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_sensorModel_T sensorModel_P;

/* Block signals (default storage) */
extern B_sensorModel_T sensorModel_B;

/* Continuous states (default storage) */
extern X_sensorModel_T sensorModel_X;

/* Block states (default storage) */
extern DW_sensorModel_T sensorModel_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_sensorModel_T sensorModel_Y;

/* Model entry point functions */
extern void sensorModel_initialize(void);
extern void sensorModel_step(void);
extern void sensorModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sensorModel_T *const sensorModel_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Assertion' : Unused code path elimination
 * Block '<S3>/Assertion' : Unused code path elimination
 * Block '<S4>/Assertion' : Unused code path elimination
 * Block '<S19>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S20>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S22>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S5>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S5>/checkMeasurementFcn2Signals' : Unused code path elimination
 * Block '<S5>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S26>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S27>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S29>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S6>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S6>/checkMeasurementFcn2Signals' : Unused code path elimination
 * Block '<S6>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S33>/ConstantP' : Unused code path elimination
 * Block '<S33>/CovarianceZ' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Conversion' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Conversion' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Constant' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Conversion' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
 * Block '<S51>/Constant' : Unused code path elimination
 * Block '<S7>/Reset' : Unused code path elimination
 * Block '<S7>/Reshapeyhat' : Unused code path elimination
 * Block '<S70>/CheckSignalProperties' : Unused code path elimination
 * Block '<S77>/ConstantP' : Unused code path elimination
 * Block '<S77>/CovarianceZ' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Conversion' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Conversion' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Constant' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Conversion' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/G' : Unused code path elimination
 * Block '<S8>/H' : Unused code path elimination
 * Block '<S8>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S8>/N' : Unused code path elimination
 * Block '<S8>/P0' : Unused code path elimination
 * Block '<S8>/Q' : Unused code path elimination
 * Block '<S8>/R' : Unused code path elimination
 * Block '<S95>/Constant' : Unused code path elimination
 * Block '<S8>/Reset' : Unused code path elimination
 * Block '<S8>/Reshapeyhat' : Unused code path elimination
 * Block '<S114>/CheckSignalProperties' : Unused code path elimination
 * Block '<S121>/ConstantP' : Unused code path elimination
 * Block '<S121>/CovarianceZ' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Conversion' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Conversion' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Constant' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Conversion' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/G' : Unused code path elimination
 * Block '<S9>/H' : Unused code path elimination
 * Block '<S9>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S9>/N' : Unused code path elimination
 * Block '<S9>/P0' : Unused code path elimination
 * Block '<S9>/Q' : Unused code path elimination
 * Block '<S9>/R' : Unused code path elimination
 * Block '<S139>/Constant' : Unused code path elimination
 * Block '<S9>/Reset' : Unused code path elimination
 * Block '<S9>/Reshapeyhat' : Unused code path elimination
 * Block '<S158>/CheckSignalProperties' : Unused code path elimination
 * Block '<S165>/ConstantP' : Unused code path elimination
 * Block '<S165>/CovarianceZ' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Conversion' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S206>/Conversion' : Unused code path elimination
 * Block '<S206>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Constant' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Conversion' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/G' : Unused code path elimination
 * Block '<S10>/H' : Unused code path elimination
 * Block '<S10>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S10>/N' : Unused code path elimination
 * Block '<S10>/P0' : Unused code path elimination
 * Block '<S10>/Q' : Unused code path elimination
 * Block '<S10>/R' : Unused code path elimination
 * Block '<S183>/Constant' : Unused code path elimination
 * Block '<S10>/Reset' : Unused code path elimination
 * Block '<S10>/Reshapeyhat' : Unused code path elimination
 * Block '<S202>/CheckSignalProperties' : Unused code path elimination
 * Block '<S209>/ConstantP' : Unused code path elimination
 * Block '<S209>/CovarianceZ' : Unused code path elimination
 * Block '<S247>/Data Type Duplicate' : Unused code path elimination
 * Block '<S248>/Data Type Duplicate' : Unused code path elimination
 * Block '<S249>/Conversion' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate' : Unused code path elimination
 * Block '<S250>/Conversion' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Constant' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S215>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S218>/Conversion' : Unused code path elimination
 * Block '<S218>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/G' : Unused code path elimination
 * Block '<S11>/H' : Unused code path elimination
 * Block '<S11>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S11>/N' : Unused code path elimination
 * Block '<S11>/P0' : Unused code path elimination
 * Block '<S11>/Q' : Unused code path elimination
 * Block '<S11>/R' : Unused code path elimination
 * Block '<S227>/Constant' : Unused code path elimination
 * Block '<S11>/Reset' : Unused code path elimination
 * Block '<S11>/Reshapeyhat' : Unused code path elimination
 * Block '<S246>/CheckSignalProperties' : Unused code path elimination
 * Block '<S253>/ConstantP' : Unused code path elimination
 * Block '<S253>/CovarianceZ' : Unused code path elimination
 * Block '<S291>/Data Type Duplicate' : Unused code path elimination
 * Block '<S292>/Data Type Duplicate' : Unused code path elimination
 * Block '<S293>/Conversion' : Unused code path elimination
 * Block '<S293>/Data Type Duplicate' : Unused code path elimination
 * Block '<S294>/Conversion' : Unused code path elimination
 * Block '<S294>/Data Type Duplicate' : Unused code path elimination
 * Block '<S254>/Constant' : Unused code path elimination
 * Block '<S255>/Data Type Duplicate' : Unused code path elimination
 * Block '<S256>/Data Type Duplicate' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Conversion' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S264>/Data Type Duplicate' : Unused code path elimination
 * Block '<S265>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S266>/Data Type Duplicate' : Unused code path elimination
 * Block '<S267>/Data Type Duplicate' : Unused code path elimination
 * Block '<S268>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/G' : Unused code path elimination
 * Block '<S12>/H' : Unused code path elimination
 * Block '<S12>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S12>/N' : Unused code path elimination
 * Block '<S12>/P0' : Unused code path elimination
 * Block '<S12>/Q' : Unused code path elimination
 * Block '<S12>/R' : Unused code path elimination
 * Block '<S271>/Constant' : Unused code path elimination
 * Block '<S12>/Reset' : Unused code path elimination
 * Block '<S12>/Reshapeyhat' : Unused code path elimination
 * Block '<S290>/CheckSignalProperties' : Unused code path elimination
 * Block '<S297>/ConstantP' : Unused code path elimination
 * Block '<S297>/CovarianceZ' : Unused code path elimination
 * Block '<S335>/Data Type Duplicate' : Unused code path elimination
 * Block '<S336>/Data Type Duplicate' : Unused code path elimination
 * Block '<S337>/Conversion' : Unused code path elimination
 * Block '<S337>/Data Type Duplicate' : Unused code path elimination
 * Block '<S338>/Conversion' : Unused code path elimination
 * Block '<S338>/Data Type Duplicate' : Unused code path elimination
 * Block '<S298>/Constant' : Unused code path elimination
 * Block '<S299>/Data Type Duplicate' : Unused code path elimination
 * Block '<S300>/Data Type Duplicate' : Unused code path elimination
 * Block '<S301>/Data Type Duplicate' : Unused code path elimination
 * Block '<S302>/Data Type Duplicate' : Unused code path elimination
 * Block '<S303>/Data Type Duplicate' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate' : Unused code path elimination
 * Block '<S305>/Data Type Duplicate' : Unused code path elimination
 * Block '<S306>/Conversion' : Unused code path elimination
 * Block '<S306>/Data Type Duplicate' : Unused code path elimination
 * Block '<S307>/Data Type Duplicate' : Unused code path elimination
 * Block '<S308>/Data Type Duplicate' : Unused code path elimination
 * Block '<S309>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S310>/Data Type Duplicate' : Unused code path elimination
 * Block '<S311>/Data Type Duplicate' : Unused code path elimination
 * Block '<S312>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/G' : Unused code path elimination
 * Block '<S13>/H' : Unused code path elimination
 * Block '<S13>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S13>/N' : Unused code path elimination
 * Block '<S13>/P0' : Unused code path elimination
 * Block '<S13>/Q' : Unused code path elimination
 * Block '<S13>/R' : Unused code path elimination
 * Block '<S315>/Constant' : Unused code path elimination
 * Block '<S13>/Reset' : Unused code path elimination
 * Block '<S13>/Reshapeyhat' : Unused code path elimination
 * Block '<S334>/CheckSignalProperties' : Unused code path elimination
 * Block '<S341>/ConstantP' : Unused code path elimination
 * Block '<S341>/CovarianceZ' : Unused code path elimination
 * Block '<S379>/Data Type Duplicate' : Unused code path elimination
 * Block '<S380>/Data Type Duplicate' : Unused code path elimination
 * Block '<S381>/Conversion' : Unused code path elimination
 * Block '<S381>/Data Type Duplicate' : Unused code path elimination
 * Block '<S382>/Conversion' : Unused code path elimination
 * Block '<S382>/Data Type Duplicate' : Unused code path elimination
 * Block '<S342>/Constant' : Unused code path elimination
 * Block '<S343>/Data Type Duplicate' : Unused code path elimination
 * Block '<S344>/Data Type Duplicate' : Unused code path elimination
 * Block '<S345>/Data Type Duplicate' : Unused code path elimination
 * Block '<S346>/Data Type Duplicate' : Unused code path elimination
 * Block '<S347>/Data Type Duplicate' : Unused code path elimination
 * Block '<S348>/Data Type Duplicate' : Unused code path elimination
 * Block '<S349>/Data Type Duplicate' : Unused code path elimination
 * Block '<S350>/Conversion' : Unused code path elimination
 * Block '<S350>/Data Type Duplicate' : Unused code path elimination
 * Block '<S351>/Data Type Duplicate' : Unused code path elimination
 * Block '<S352>/Data Type Duplicate' : Unused code path elimination
 * Block '<S353>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S354>/Data Type Duplicate' : Unused code path elimination
 * Block '<S355>/Data Type Duplicate' : Unused code path elimination
 * Block '<S356>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/G' : Unused code path elimination
 * Block '<S14>/H' : Unused code path elimination
 * Block '<S14>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S14>/N' : Unused code path elimination
 * Block '<S14>/P0' : Unused code path elimination
 * Block '<S14>/Q' : Unused code path elimination
 * Block '<S14>/R' : Unused code path elimination
 * Block '<S359>/Constant' : Unused code path elimination
 * Block '<S14>/Reset' : Unused code path elimination
 * Block '<S14>/Reshapeyhat' : Unused code path elimination
 * Block '<S378>/CheckSignalProperties' : Unused code path elimination
 * Block '<S1>/ODR' : Eliminated since input and output rates are identical
 * Block '<S1>/ODR1' : Eliminated since input and output rates are identical
 * Block '<S1>/ODR2' : Eliminated since input and output rates are identical
 * Block '<S5>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_Enable2' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_R2' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_uMeas2' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_y2' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_Enable2' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_R2' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_uMeas2' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S6>/DataTypeConversion_y2' : Eliminate redundant data type conversion
 * Block '<S71>/Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S46>/Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapeu' : Reshape block reduction
 * Block '<S7>/Reshapexhat' : Reshape block reduction
 * Block '<S7>/Reshapey' : Reshape block reduction
 * Block '<S115>/Conversion' : Eliminate redundant data type conversion
 * Block '<S116>/Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S90>/Conversion' : Eliminate redundant data type conversion
 * Block '<S94>/Reshape' : Reshape block reduction
 * Block '<S8>/ReshapeX0' : Reshape block reduction
 * Block '<S8>/Reshapeu' : Reshape block reduction
 * Block '<S8>/Reshapexhat' : Reshape block reduction
 * Block '<S8>/Reshapey' : Reshape block reduction
 * Block '<S159>/Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S134>/Conversion' : Eliminate redundant data type conversion
 * Block '<S138>/Reshape' : Reshape block reduction
 * Block '<S9>/ReshapeX0' : Reshape block reduction
 * Block '<S9>/Reshapeu' : Reshape block reduction
 * Block '<S9>/Reshapexhat' : Reshape block reduction
 * Block '<S9>/Reshapey' : Reshape block reduction
 * Block '<S203>/Conversion' : Eliminate redundant data type conversion
 * Block '<S204>/Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S178>/Conversion' : Eliminate redundant data type conversion
 * Block '<S182>/Reshape' : Reshape block reduction
 * Block '<S10>/ReshapeX0' : Reshape block reduction
 * Block '<S10>/Reshapeu' : Reshape block reduction
 * Block '<S10>/Reshapexhat' : Reshape block reduction
 * Block '<S10>/Reshapey' : Reshape block reduction
 * Block '<S247>/Conversion' : Eliminate redundant data type conversion
 * Block '<S248>/Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S222>/Conversion' : Eliminate redundant data type conversion
 * Block '<S226>/Reshape' : Reshape block reduction
 * Block '<S11>/ReshapeX0' : Reshape block reduction
 * Block '<S11>/Reshapeu' : Reshape block reduction
 * Block '<S11>/Reshapexhat' : Reshape block reduction
 * Block '<S11>/Reshapey' : Reshape block reduction
 * Block '<S291>/Conversion' : Eliminate redundant data type conversion
 * Block '<S292>/Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S266>/Conversion' : Eliminate redundant data type conversion
 * Block '<S270>/Reshape' : Reshape block reduction
 * Block '<S12>/ReshapeX0' : Reshape block reduction
 * Block '<S12>/Reshapeu' : Reshape block reduction
 * Block '<S12>/Reshapexhat' : Reshape block reduction
 * Block '<S12>/Reshapey' : Reshape block reduction
 * Block '<S335>/Conversion' : Eliminate redundant data type conversion
 * Block '<S336>/Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S310>/Conversion' : Eliminate redundant data type conversion
 * Block '<S314>/Reshape' : Reshape block reduction
 * Block '<S13>/ReshapeX0' : Reshape block reduction
 * Block '<S13>/Reshapeu' : Reshape block reduction
 * Block '<S13>/Reshapexhat' : Reshape block reduction
 * Block '<S13>/Reshapey' : Reshape block reduction
 * Block '<S379>/Conversion' : Eliminate redundant data type conversion
 * Block '<S380>/Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S354>/Conversion' : Eliminate redundant data type conversion
 * Block '<S358>/Reshape' : Reshape block reduction
 * Block '<S14>/ReshapeX0' : Reshape block reduction
 * Block '<S14>/Reshapeu' : Reshape block reduction
 * Block '<S14>/Reshapexhat' : Reshape block reduction
 * Block '<S14>/Reshapey' : Reshape block reduction
 * Block '<S15>/ODR' : Eliminated since input and output rates are identical
 * Block '<S16>/ODR' : Eliminated since input and output rates are identical
 * Block '<S16>/ODR1' : Eliminated since input and output rates are identical
 */

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
 * '<Root>' : 'sensorModel'
 * '<S1>'   : 'sensorModel/BMP280 PAT Sensor '
 * '<S2>'   : 'sensorModel/Check  Static Range'
 * '<S3>'   : 'sensorModel/Check  Static Range1'
 * '<S4>'   : 'sensorModel/Check Static  Upper Bound'
 * '<S5>'   : 'sensorModel/EKF'
 * '<S6>'   : 'sensorModel/EXF1'
 * '<S7>'   : 'sensorModel/Filter1'
 * '<S8>'   : 'sensorModel/Filter2'
 * '<S9>'   : 'sensorModel/Filter4'
 * '<S10>'  : 'sensorModel/Filter5'
 * '<S11>'  : 'sensorModel/Filter6'
 * '<S12>'  : 'sensorModel/Filter7'
 * '<S13>'  : 'sensorModel/Filter8'
 * '<S14>'  : 'sensorModel/Filter9'
 * '<S15>'  : 'sensorModel/L3GD20 3 Axis Gyro Sensor'
 * '<S16>'  : 'sensorModel/LSM303 Accel + Compass Sensor'
 * '<S17>'  : 'sensorModel/Min Num of Sats for good fix'
 * '<S18>'  : 'sensorModel/Ultimate GPS Shield'
 * '<S19>'  : 'sensorModel/EKF/Correct1'
 * '<S20>'  : 'sensorModel/EKF/Correct2'
 * '<S21>'  : 'sensorModel/EKF/Output'
 * '<S22>'  : 'sensorModel/EKF/Predict'
 * '<S23>'  : 'sensorModel/EKF/Correct1/Correct'
 * '<S24>'  : 'sensorModel/EKF/Correct2/Correct'
 * '<S25>'  : 'sensorModel/EKF/Predict/Predict'
 * '<S26>'  : 'sensorModel/EXF1/Correct1'
 * '<S27>'  : 'sensorModel/EXF1/Correct2'
 * '<S28>'  : 'sensorModel/EXF1/Output'
 * '<S29>'  : 'sensorModel/EXF1/Predict'
 * '<S30>'  : 'sensorModel/EXF1/Correct1/Correct'
 * '<S31>'  : 'sensorModel/EXF1/Correct2/Correct'
 * '<S32>'  : 'sensorModel/EXF1/Predict/Predict'
 * '<S33>'  : 'sensorModel/Filter1/CalculatePL'
 * '<S34>'  : 'sensorModel/Filter1/CalculateYhat'
 * '<S35>'  : 'sensorModel/Filter1/DataTypeConversionA'
 * '<S36>'  : 'sensorModel/Filter1/DataTypeConversionB'
 * '<S37>'  : 'sensorModel/Filter1/DataTypeConversionC'
 * '<S38>'  : 'sensorModel/Filter1/DataTypeConversionD'
 * '<S39>'  : 'sensorModel/Filter1/DataTypeConversionG'
 * '<S40>'  : 'sensorModel/Filter1/DataTypeConversionH'
 * '<S41>'  : 'sensorModel/Filter1/DataTypeConversionN'
 * '<S42>'  : 'sensorModel/Filter1/DataTypeConversionP'
 * '<S43>'  : 'sensorModel/Filter1/DataTypeConversionP0'
 * '<S44>'  : 'sensorModel/Filter1/DataTypeConversionQ'
 * '<S45>'  : 'sensorModel/Filter1/DataTypeConversionR'
 * '<S46>'  : 'sensorModel/Filter1/DataTypeConversionX'
 * '<S47>'  : 'sensorModel/Filter1/DataTypeConversionX0'
 * '<S48>'  : 'sensorModel/Filter1/DataTypeConversionu'
 * '<S49>'  : 'sensorModel/Filter1/MemoryP'
 * '<S50>'  : 'sensorModel/Filter1/Observer'
 * '<S51>'  : 'sensorModel/Filter1/ReducedQRN'
 * '<S52>'  : 'sensorModel/Filter1/ScalarExpansionP0'
 * '<S53>'  : 'sensorModel/Filter1/ScalarExpansionQ'
 * '<S54>'  : 'sensorModel/Filter1/ScalarExpansionR'
 * '<S55>'  : 'sensorModel/Filter1/UseCurrentEstimator'
 * '<S56>'  : 'sensorModel/Filter1/checkA'
 * '<S57>'  : 'sensorModel/Filter1/checkB'
 * '<S58>'  : 'sensorModel/Filter1/checkC'
 * '<S59>'  : 'sensorModel/Filter1/checkD'
 * '<S60>'  : 'sensorModel/Filter1/checkEnable'
 * '<S61>'  : 'sensorModel/Filter1/checkG'
 * '<S62>'  : 'sensorModel/Filter1/checkH'
 * '<S63>'  : 'sensorModel/Filter1/checkN'
 * '<S64>'  : 'sensorModel/Filter1/checkP0'
 * '<S65>'  : 'sensorModel/Filter1/checkQ'
 * '<S66>'  : 'sensorModel/Filter1/checkR'
 * '<S67>'  : 'sensorModel/Filter1/checkReset'
 * '<S68>'  : 'sensorModel/Filter1/checkX0'
 * '<S69>'  : 'sensorModel/Filter1/checku'
 * '<S70>'  : 'sensorModel/Filter1/checky'
 * '<S71>'  : 'sensorModel/Filter1/CalculatePL/DataTypeConversionL'
 * '<S72>'  : 'sensorModel/Filter1/CalculatePL/DataTypeConversionM'
 * '<S73>'  : 'sensorModel/Filter1/CalculatePL/DataTypeConversionP'
 * '<S74>'  : 'sensorModel/Filter1/CalculatePL/DataTypeConversionZ'
 * '<S75>'  : 'sensorModel/Filter1/Observer/MeasurementUpdate'
 * '<S76>'  : 'sensorModel/Filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S77>'  : 'sensorModel/Filter2/CalculatePL'
 * '<S78>'  : 'sensorModel/Filter2/CalculateYhat'
 * '<S79>'  : 'sensorModel/Filter2/DataTypeConversionA'
 * '<S80>'  : 'sensorModel/Filter2/DataTypeConversionB'
 * '<S81>'  : 'sensorModel/Filter2/DataTypeConversionC'
 * '<S82>'  : 'sensorModel/Filter2/DataTypeConversionD'
 * '<S83>'  : 'sensorModel/Filter2/DataTypeConversionG'
 * '<S84>'  : 'sensorModel/Filter2/DataTypeConversionH'
 * '<S85>'  : 'sensorModel/Filter2/DataTypeConversionN'
 * '<S86>'  : 'sensorModel/Filter2/DataTypeConversionP'
 * '<S87>'  : 'sensorModel/Filter2/DataTypeConversionP0'
 * '<S88>'  : 'sensorModel/Filter2/DataTypeConversionQ'
 * '<S89>'  : 'sensorModel/Filter2/DataTypeConversionR'
 * '<S90>'  : 'sensorModel/Filter2/DataTypeConversionX'
 * '<S91>'  : 'sensorModel/Filter2/DataTypeConversionX0'
 * '<S92>'  : 'sensorModel/Filter2/DataTypeConversionu'
 * '<S93>'  : 'sensorModel/Filter2/MemoryP'
 * '<S94>'  : 'sensorModel/Filter2/Observer'
 * '<S95>'  : 'sensorModel/Filter2/ReducedQRN'
 * '<S96>'  : 'sensorModel/Filter2/ScalarExpansionP0'
 * '<S97>'  : 'sensorModel/Filter2/ScalarExpansionQ'
 * '<S98>'  : 'sensorModel/Filter2/ScalarExpansionR'
 * '<S99>'  : 'sensorModel/Filter2/UseCurrentEstimator'
 * '<S100>' : 'sensorModel/Filter2/checkA'
 * '<S101>' : 'sensorModel/Filter2/checkB'
 * '<S102>' : 'sensorModel/Filter2/checkC'
 * '<S103>' : 'sensorModel/Filter2/checkD'
 * '<S104>' : 'sensorModel/Filter2/checkEnable'
 * '<S105>' : 'sensorModel/Filter2/checkG'
 * '<S106>' : 'sensorModel/Filter2/checkH'
 * '<S107>' : 'sensorModel/Filter2/checkN'
 * '<S108>' : 'sensorModel/Filter2/checkP0'
 * '<S109>' : 'sensorModel/Filter2/checkQ'
 * '<S110>' : 'sensorModel/Filter2/checkR'
 * '<S111>' : 'sensorModel/Filter2/checkReset'
 * '<S112>' : 'sensorModel/Filter2/checkX0'
 * '<S113>' : 'sensorModel/Filter2/checku'
 * '<S114>' : 'sensorModel/Filter2/checky'
 * '<S115>' : 'sensorModel/Filter2/CalculatePL/DataTypeConversionL'
 * '<S116>' : 'sensorModel/Filter2/CalculatePL/DataTypeConversionM'
 * '<S117>' : 'sensorModel/Filter2/CalculatePL/DataTypeConversionP'
 * '<S118>' : 'sensorModel/Filter2/CalculatePL/DataTypeConversionZ'
 * '<S119>' : 'sensorModel/Filter2/Observer/MeasurementUpdate'
 * '<S120>' : 'sensorModel/Filter2/UseCurrentEstimator/Enabled Subsystem'
 * '<S121>' : 'sensorModel/Filter4/CalculatePL'
 * '<S122>' : 'sensorModel/Filter4/CalculateYhat'
 * '<S123>' : 'sensorModel/Filter4/DataTypeConversionA'
 * '<S124>' : 'sensorModel/Filter4/DataTypeConversionB'
 * '<S125>' : 'sensorModel/Filter4/DataTypeConversionC'
 * '<S126>' : 'sensorModel/Filter4/DataTypeConversionD'
 * '<S127>' : 'sensorModel/Filter4/DataTypeConversionG'
 * '<S128>' : 'sensorModel/Filter4/DataTypeConversionH'
 * '<S129>' : 'sensorModel/Filter4/DataTypeConversionN'
 * '<S130>' : 'sensorModel/Filter4/DataTypeConversionP'
 * '<S131>' : 'sensorModel/Filter4/DataTypeConversionP0'
 * '<S132>' : 'sensorModel/Filter4/DataTypeConversionQ'
 * '<S133>' : 'sensorModel/Filter4/DataTypeConversionR'
 * '<S134>' : 'sensorModel/Filter4/DataTypeConversionX'
 * '<S135>' : 'sensorModel/Filter4/DataTypeConversionX0'
 * '<S136>' : 'sensorModel/Filter4/DataTypeConversionu'
 * '<S137>' : 'sensorModel/Filter4/MemoryP'
 * '<S138>' : 'sensorModel/Filter4/Observer'
 * '<S139>' : 'sensorModel/Filter4/ReducedQRN'
 * '<S140>' : 'sensorModel/Filter4/ScalarExpansionP0'
 * '<S141>' : 'sensorModel/Filter4/ScalarExpansionQ'
 * '<S142>' : 'sensorModel/Filter4/ScalarExpansionR'
 * '<S143>' : 'sensorModel/Filter4/UseCurrentEstimator'
 * '<S144>' : 'sensorModel/Filter4/checkA'
 * '<S145>' : 'sensorModel/Filter4/checkB'
 * '<S146>' : 'sensorModel/Filter4/checkC'
 * '<S147>' : 'sensorModel/Filter4/checkD'
 * '<S148>' : 'sensorModel/Filter4/checkEnable'
 * '<S149>' : 'sensorModel/Filter4/checkG'
 * '<S150>' : 'sensorModel/Filter4/checkH'
 * '<S151>' : 'sensorModel/Filter4/checkN'
 * '<S152>' : 'sensorModel/Filter4/checkP0'
 * '<S153>' : 'sensorModel/Filter4/checkQ'
 * '<S154>' : 'sensorModel/Filter4/checkR'
 * '<S155>' : 'sensorModel/Filter4/checkReset'
 * '<S156>' : 'sensorModel/Filter4/checkX0'
 * '<S157>' : 'sensorModel/Filter4/checku'
 * '<S158>' : 'sensorModel/Filter4/checky'
 * '<S159>' : 'sensorModel/Filter4/CalculatePL/DataTypeConversionL'
 * '<S160>' : 'sensorModel/Filter4/CalculatePL/DataTypeConversionM'
 * '<S161>' : 'sensorModel/Filter4/CalculatePL/DataTypeConversionP'
 * '<S162>' : 'sensorModel/Filter4/CalculatePL/DataTypeConversionZ'
 * '<S163>' : 'sensorModel/Filter4/Observer/MeasurementUpdate'
 * '<S164>' : 'sensorModel/Filter4/UseCurrentEstimator/Enabled Subsystem'
 * '<S165>' : 'sensorModel/Filter5/CalculatePL'
 * '<S166>' : 'sensorModel/Filter5/CalculateYhat'
 * '<S167>' : 'sensorModel/Filter5/DataTypeConversionA'
 * '<S168>' : 'sensorModel/Filter5/DataTypeConversionB'
 * '<S169>' : 'sensorModel/Filter5/DataTypeConversionC'
 * '<S170>' : 'sensorModel/Filter5/DataTypeConversionD'
 * '<S171>' : 'sensorModel/Filter5/DataTypeConversionG'
 * '<S172>' : 'sensorModel/Filter5/DataTypeConversionH'
 * '<S173>' : 'sensorModel/Filter5/DataTypeConversionN'
 * '<S174>' : 'sensorModel/Filter5/DataTypeConversionP'
 * '<S175>' : 'sensorModel/Filter5/DataTypeConversionP0'
 * '<S176>' : 'sensorModel/Filter5/DataTypeConversionQ'
 * '<S177>' : 'sensorModel/Filter5/DataTypeConversionR'
 * '<S178>' : 'sensorModel/Filter5/DataTypeConversionX'
 * '<S179>' : 'sensorModel/Filter5/DataTypeConversionX0'
 * '<S180>' : 'sensorModel/Filter5/DataTypeConversionu'
 * '<S181>' : 'sensorModel/Filter5/MemoryP'
 * '<S182>' : 'sensorModel/Filter5/Observer'
 * '<S183>' : 'sensorModel/Filter5/ReducedQRN'
 * '<S184>' : 'sensorModel/Filter5/ScalarExpansionP0'
 * '<S185>' : 'sensorModel/Filter5/ScalarExpansionQ'
 * '<S186>' : 'sensorModel/Filter5/ScalarExpansionR'
 * '<S187>' : 'sensorModel/Filter5/UseCurrentEstimator'
 * '<S188>' : 'sensorModel/Filter5/checkA'
 * '<S189>' : 'sensorModel/Filter5/checkB'
 * '<S190>' : 'sensorModel/Filter5/checkC'
 * '<S191>' : 'sensorModel/Filter5/checkD'
 * '<S192>' : 'sensorModel/Filter5/checkEnable'
 * '<S193>' : 'sensorModel/Filter5/checkG'
 * '<S194>' : 'sensorModel/Filter5/checkH'
 * '<S195>' : 'sensorModel/Filter5/checkN'
 * '<S196>' : 'sensorModel/Filter5/checkP0'
 * '<S197>' : 'sensorModel/Filter5/checkQ'
 * '<S198>' : 'sensorModel/Filter5/checkR'
 * '<S199>' : 'sensorModel/Filter5/checkReset'
 * '<S200>' : 'sensorModel/Filter5/checkX0'
 * '<S201>' : 'sensorModel/Filter5/checku'
 * '<S202>' : 'sensorModel/Filter5/checky'
 * '<S203>' : 'sensorModel/Filter5/CalculatePL/DataTypeConversionL'
 * '<S204>' : 'sensorModel/Filter5/CalculatePL/DataTypeConversionM'
 * '<S205>' : 'sensorModel/Filter5/CalculatePL/DataTypeConversionP'
 * '<S206>' : 'sensorModel/Filter5/CalculatePL/DataTypeConversionZ'
 * '<S207>' : 'sensorModel/Filter5/Observer/MeasurementUpdate'
 * '<S208>' : 'sensorModel/Filter5/UseCurrentEstimator/Enabled Subsystem'
 * '<S209>' : 'sensorModel/Filter6/CalculatePL'
 * '<S210>' : 'sensorModel/Filter6/CalculateYhat'
 * '<S211>' : 'sensorModel/Filter6/DataTypeConversionA'
 * '<S212>' : 'sensorModel/Filter6/DataTypeConversionB'
 * '<S213>' : 'sensorModel/Filter6/DataTypeConversionC'
 * '<S214>' : 'sensorModel/Filter6/DataTypeConversionD'
 * '<S215>' : 'sensorModel/Filter6/DataTypeConversionG'
 * '<S216>' : 'sensorModel/Filter6/DataTypeConversionH'
 * '<S217>' : 'sensorModel/Filter6/DataTypeConversionN'
 * '<S218>' : 'sensorModel/Filter6/DataTypeConversionP'
 * '<S219>' : 'sensorModel/Filter6/DataTypeConversionP0'
 * '<S220>' : 'sensorModel/Filter6/DataTypeConversionQ'
 * '<S221>' : 'sensorModel/Filter6/DataTypeConversionR'
 * '<S222>' : 'sensorModel/Filter6/DataTypeConversionX'
 * '<S223>' : 'sensorModel/Filter6/DataTypeConversionX0'
 * '<S224>' : 'sensorModel/Filter6/DataTypeConversionu'
 * '<S225>' : 'sensorModel/Filter6/MemoryP'
 * '<S226>' : 'sensorModel/Filter6/Observer'
 * '<S227>' : 'sensorModel/Filter6/ReducedQRN'
 * '<S228>' : 'sensorModel/Filter6/ScalarExpansionP0'
 * '<S229>' : 'sensorModel/Filter6/ScalarExpansionQ'
 * '<S230>' : 'sensorModel/Filter6/ScalarExpansionR'
 * '<S231>' : 'sensorModel/Filter6/UseCurrentEstimator'
 * '<S232>' : 'sensorModel/Filter6/checkA'
 * '<S233>' : 'sensorModel/Filter6/checkB'
 * '<S234>' : 'sensorModel/Filter6/checkC'
 * '<S235>' : 'sensorModel/Filter6/checkD'
 * '<S236>' : 'sensorModel/Filter6/checkEnable'
 * '<S237>' : 'sensorModel/Filter6/checkG'
 * '<S238>' : 'sensorModel/Filter6/checkH'
 * '<S239>' : 'sensorModel/Filter6/checkN'
 * '<S240>' : 'sensorModel/Filter6/checkP0'
 * '<S241>' : 'sensorModel/Filter6/checkQ'
 * '<S242>' : 'sensorModel/Filter6/checkR'
 * '<S243>' : 'sensorModel/Filter6/checkReset'
 * '<S244>' : 'sensorModel/Filter6/checkX0'
 * '<S245>' : 'sensorModel/Filter6/checku'
 * '<S246>' : 'sensorModel/Filter6/checky'
 * '<S247>' : 'sensorModel/Filter6/CalculatePL/DataTypeConversionL'
 * '<S248>' : 'sensorModel/Filter6/CalculatePL/DataTypeConversionM'
 * '<S249>' : 'sensorModel/Filter6/CalculatePL/DataTypeConversionP'
 * '<S250>' : 'sensorModel/Filter6/CalculatePL/DataTypeConversionZ'
 * '<S251>' : 'sensorModel/Filter6/Observer/MeasurementUpdate'
 * '<S252>' : 'sensorModel/Filter6/UseCurrentEstimator/Enabled Subsystem'
 * '<S253>' : 'sensorModel/Filter7/CalculatePL'
 * '<S254>' : 'sensorModel/Filter7/CalculateYhat'
 * '<S255>' : 'sensorModel/Filter7/DataTypeConversionA'
 * '<S256>' : 'sensorModel/Filter7/DataTypeConversionB'
 * '<S257>' : 'sensorModel/Filter7/DataTypeConversionC'
 * '<S258>' : 'sensorModel/Filter7/DataTypeConversionD'
 * '<S259>' : 'sensorModel/Filter7/DataTypeConversionG'
 * '<S260>' : 'sensorModel/Filter7/DataTypeConversionH'
 * '<S261>' : 'sensorModel/Filter7/DataTypeConversionN'
 * '<S262>' : 'sensorModel/Filter7/DataTypeConversionP'
 * '<S263>' : 'sensorModel/Filter7/DataTypeConversionP0'
 * '<S264>' : 'sensorModel/Filter7/DataTypeConversionQ'
 * '<S265>' : 'sensorModel/Filter7/DataTypeConversionR'
 * '<S266>' : 'sensorModel/Filter7/DataTypeConversionX'
 * '<S267>' : 'sensorModel/Filter7/DataTypeConversionX0'
 * '<S268>' : 'sensorModel/Filter7/DataTypeConversionu'
 * '<S269>' : 'sensorModel/Filter7/MemoryP'
 * '<S270>' : 'sensorModel/Filter7/Observer'
 * '<S271>' : 'sensorModel/Filter7/ReducedQRN'
 * '<S272>' : 'sensorModel/Filter7/ScalarExpansionP0'
 * '<S273>' : 'sensorModel/Filter7/ScalarExpansionQ'
 * '<S274>' : 'sensorModel/Filter7/ScalarExpansionR'
 * '<S275>' : 'sensorModel/Filter7/UseCurrentEstimator'
 * '<S276>' : 'sensorModel/Filter7/checkA'
 * '<S277>' : 'sensorModel/Filter7/checkB'
 * '<S278>' : 'sensorModel/Filter7/checkC'
 * '<S279>' : 'sensorModel/Filter7/checkD'
 * '<S280>' : 'sensorModel/Filter7/checkEnable'
 * '<S281>' : 'sensorModel/Filter7/checkG'
 * '<S282>' : 'sensorModel/Filter7/checkH'
 * '<S283>' : 'sensorModel/Filter7/checkN'
 * '<S284>' : 'sensorModel/Filter7/checkP0'
 * '<S285>' : 'sensorModel/Filter7/checkQ'
 * '<S286>' : 'sensorModel/Filter7/checkR'
 * '<S287>' : 'sensorModel/Filter7/checkReset'
 * '<S288>' : 'sensorModel/Filter7/checkX0'
 * '<S289>' : 'sensorModel/Filter7/checku'
 * '<S290>' : 'sensorModel/Filter7/checky'
 * '<S291>' : 'sensorModel/Filter7/CalculatePL/DataTypeConversionL'
 * '<S292>' : 'sensorModel/Filter7/CalculatePL/DataTypeConversionM'
 * '<S293>' : 'sensorModel/Filter7/CalculatePL/DataTypeConversionP'
 * '<S294>' : 'sensorModel/Filter7/CalculatePL/DataTypeConversionZ'
 * '<S295>' : 'sensorModel/Filter7/Observer/MeasurementUpdate'
 * '<S296>' : 'sensorModel/Filter7/UseCurrentEstimator/Enabled Subsystem'
 * '<S297>' : 'sensorModel/Filter8/CalculatePL'
 * '<S298>' : 'sensorModel/Filter8/CalculateYhat'
 * '<S299>' : 'sensorModel/Filter8/DataTypeConversionA'
 * '<S300>' : 'sensorModel/Filter8/DataTypeConversionB'
 * '<S301>' : 'sensorModel/Filter8/DataTypeConversionC'
 * '<S302>' : 'sensorModel/Filter8/DataTypeConversionD'
 * '<S303>' : 'sensorModel/Filter8/DataTypeConversionG'
 * '<S304>' : 'sensorModel/Filter8/DataTypeConversionH'
 * '<S305>' : 'sensorModel/Filter8/DataTypeConversionN'
 * '<S306>' : 'sensorModel/Filter8/DataTypeConversionP'
 * '<S307>' : 'sensorModel/Filter8/DataTypeConversionP0'
 * '<S308>' : 'sensorModel/Filter8/DataTypeConversionQ'
 * '<S309>' : 'sensorModel/Filter8/DataTypeConversionR'
 * '<S310>' : 'sensorModel/Filter8/DataTypeConversionX'
 * '<S311>' : 'sensorModel/Filter8/DataTypeConversionX0'
 * '<S312>' : 'sensorModel/Filter8/DataTypeConversionu'
 * '<S313>' : 'sensorModel/Filter8/MemoryP'
 * '<S314>' : 'sensorModel/Filter8/Observer'
 * '<S315>' : 'sensorModel/Filter8/ReducedQRN'
 * '<S316>' : 'sensorModel/Filter8/ScalarExpansionP0'
 * '<S317>' : 'sensorModel/Filter8/ScalarExpansionQ'
 * '<S318>' : 'sensorModel/Filter8/ScalarExpansionR'
 * '<S319>' : 'sensorModel/Filter8/UseCurrentEstimator'
 * '<S320>' : 'sensorModel/Filter8/checkA'
 * '<S321>' : 'sensorModel/Filter8/checkB'
 * '<S322>' : 'sensorModel/Filter8/checkC'
 * '<S323>' : 'sensorModel/Filter8/checkD'
 * '<S324>' : 'sensorModel/Filter8/checkEnable'
 * '<S325>' : 'sensorModel/Filter8/checkG'
 * '<S326>' : 'sensorModel/Filter8/checkH'
 * '<S327>' : 'sensorModel/Filter8/checkN'
 * '<S328>' : 'sensorModel/Filter8/checkP0'
 * '<S329>' : 'sensorModel/Filter8/checkQ'
 * '<S330>' : 'sensorModel/Filter8/checkR'
 * '<S331>' : 'sensorModel/Filter8/checkReset'
 * '<S332>' : 'sensorModel/Filter8/checkX0'
 * '<S333>' : 'sensorModel/Filter8/checku'
 * '<S334>' : 'sensorModel/Filter8/checky'
 * '<S335>' : 'sensorModel/Filter8/CalculatePL/DataTypeConversionL'
 * '<S336>' : 'sensorModel/Filter8/CalculatePL/DataTypeConversionM'
 * '<S337>' : 'sensorModel/Filter8/CalculatePL/DataTypeConversionP'
 * '<S338>' : 'sensorModel/Filter8/CalculatePL/DataTypeConversionZ'
 * '<S339>' : 'sensorModel/Filter8/Observer/MeasurementUpdate'
 * '<S340>' : 'sensorModel/Filter8/UseCurrentEstimator/Enabled Subsystem'
 * '<S341>' : 'sensorModel/Filter9/CalculatePL'
 * '<S342>' : 'sensorModel/Filter9/CalculateYhat'
 * '<S343>' : 'sensorModel/Filter9/DataTypeConversionA'
 * '<S344>' : 'sensorModel/Filter9/DataTypeConversionB'
 * '<S345>' : 'sensorModel/Filter9/DataTypeConversionC'
 * '<S346>' : 'sensorModel/Filter9/DataTypeConversionD'
 * '<S347>' : 'sensorModel/Filter9/DataTypeConversionG'
 * '<S348>' : 'sensorModel/Filter9/DataTypeConversionH'
 * '<S349>' : 'sensorModel/Filter9/DataTypeConversionN'
 * '<S350>' : 'sensorModel/Filter9/DataTypeConversionP'
 * '<S351>' : 'sensorModel/Filter9/DataTypeConversionP0'
 * '<S352>' : 'sensorModel/Filter9/DataTypeConversionQ'
 * '<S353>' : 'sensorModel/Filter9/DataTypeConversionR'
 * '<S354>' : 'sensorModel/Filter9/DataTypeConversionX'
 * '<S355>' : 'sensorModel/Filter9/DataTypeConversionX0'
 * '<S356>' : 'sensorModel/Filter9/DataTypeConversionu'
 * '<S357>' : 'sensorModel/Filter9/MemoryP'
 * '<S358>' : 'sensorModel/Filter9/Observer'
 * '<S359>' : 'sensorModel/Filter9/ReducedQRN'
 * '<S360>' : 'sensorModel/Filter9/ScalarExpansionP0'
 * '<S361>' : 'sensorModel/Filter9/ScalarExpansionQ'
 * '<S362>' : 'sensorModel/Filter9/ScalarExpansionR'
 * '<S363>' : 'sensorModel/Filter9/UseCurrentEstimator'
 * '<S364>' : 'sensorModel/Filter9/checkA'
 * '<S365>' : 'sensorModel/Filter9/checkB'
 * '<S366>' : 'sensorModel/Filter9/checkC'
 * '<S367>' : 'sensorModel/Filter9/checkD'
 * '<S368>' : 'sensorModel/Filter9/checkEnable'
 * '<S369>' : 'sensorModel/Filter9/checkG'
 * '<S370>' : 'sensorModel/Filter9/checkH'
 * '<S371>' : 'sensorModel/Filter9/checkN'
 * '<S372>' : 'sensorModel/Filter9/checkP0'
 * '<S373>' : 'sensorModel/Filter9/checkQ'
 * '<S374>' : 'sensorModel/Filter9/checkR'
 * '<S375>' : 'sensorModel/Filter9/checkReset'
 * '<S376>' : 'sensorModel/Filter9/checkX0'
 * '<S377>' : 'sensorModel/Filter9/checku'
 * '<S378>' : 'sensorModel/Filter9/checky'
 * '<S379>' : 'sensorModel/Filter9/CalculatePL/DataTypeConversionL'
 * '<S380>' : 'sensorModel/Filter9/CalculatePL/DataTypeConversionM'
 * '<S381>' : 'sensorModel/Filter9/CalculatePL/DataTypeConversionP'
 * '<S382>' : 'sensorModel/Filter9/CalculatePL/DataTypeConversionZ'
 * '<S383>' : 'sensorModel/Filter9/Observer/MeasurementUpdate'
 * '<S384>' : 'sensorModel/Filter9/UseCurrentEstimator/Enabled Subsystem'
 * '<S385>' : 'sensorModel/LSM303 Accel + Compass Sensor/MATLAB Function'
 * '<S386>' : 'sensorModel/Ultimate GPS Shield/$GPGGA_$GPRMC_Parser1'
 * '<S387>' : 'sensorModel/Ultimate GPS Shield/$GPGGA_$GPRMC_Parser1/MATLAB Function'
 * '<S388>' : 'sensorModel/Ultimate GPS Shield/$GPGGA_$GPRMC_Parser1/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_sensorModel_h_ */
