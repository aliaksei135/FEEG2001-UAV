/*
 * sensorModel_types.h
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

#ifndef RTW_HEADER_sensorModel_types_h_
#define RTW_HEADER_sensorModel_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef typedef_dsp_private_MedianFilterCG_se_T
#define typedef_dsp_private_MedianFilterCG_se_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pWinLen;
  real_T pBuf[20];
  real_T pHeap[20];
  real_T pMidHeap;
  real_T pIdx;
  real_T pPos[20];
  real_T pMinHeapLength;
  real_T pMaxHeapLength;
} dsp_private_MedianFilterCG_se_T;

#endif                                 /*typedef_dsp_private_MedianFilterCG_se_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  int32_T isInitialized;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_GPSParser_sensorModel_T
#define typedef_GPSParser_sensorModel_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} GPSParser_sensorModel_T;

#endif                                 /*typedef_GPSParser_sensorModel_T*/

#ifndef typedef_cell_wrap_sensorModel_T
#define typedef_cell_wrap_sensorModel_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_sensorModel_T;

#endif                                 /*typedef_cell_wrap_sensorModel_T*/

/* Custom Type definition for MATLAB Function: '<S27>/Correct' */
#ifndef struct_tag_sUAIaS8TPWuzgg7KvQbnkvB
#define struct_tag_sUAIaS8TPWuzgg7KvQbnkvB

struct tag_sUAIaS8TPWuzgg7KvQbnkvB
{
  char_T FcnName[19];
  boolean_T IsSimulinkFcn;
  real_T NumberOfExtraArgumentInports;
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sUAIaS8TPWuzgg7KvQbnkvB*/

#ifndef typedef_sUAIaS8TPWuzgg7KvQbnkvB_senso_T
#define typedef_sUAIaS8TPWuzgg7KvQbnkvB_senso_T

typedef struct tag_sUAIaS8TPWuzgg7KvQbnkvB sUAIaS8TPWuzgg7KvQbnkvB_senso_T;

#endif                                 /*typedef_sUAIaS8TPWuzgg7KvQbnkvB_senso_T*/

/* Custom Type definition for MATLAB Function: '<S26>/Correct' */
#ifndef struct_tag_sktc5FZkzfHrwlI6dEbqaEF
#define struct_tag_sktc5FZkzfHrwlI6dEbqaEF

struct tag_sktc5FZkzfHrwlI6dEbqaEF
{
  char_T FcnName[18];
  boolean_T IsSimulinkFcn;
  real_T NumberOfExtraArgumentInports;
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sktc5FZkzfHrwlI6dEbqaEF*/

#ifndef typedef_sktc5FZkzfHrwlI6dEbqaEF_senso_T
#define typedef_sktc5FZkzfHrwlI6dEbqaEF_senso_T

typedef struct tag_sktc5FZkzfHrwlI6dEbqaEF sktc5FZkzfHrwlI6dEbqaEF_senso_T;

#endif                                 /*typedef_sktc5FZkzfHrwlI6dEbqaEF_senso_T*/

/* Custom Type definition for MATLAB Function: '<S22>/Predict' */
#ifndef struct_tag_shtnxor9BIgJASjS9Gre29G
#define struct_tag_shtnxor9BIgJASjS9Gre29G

struct tag_shtnxor9BIgJASjS9Gre29G
{
  char_T FcnName[26];
  boolean_T IsSimulinkFcn;
  real_T NumberOfExtraArgumentInports;
  real_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_shtnxor9BIgJASjS9Gre29G*/

#ifndef typedef_shtnxor9BIgJASjS9Gre29G_senso_T
#define typedef_shtnxor9BIgJASjS9Gre29G_senso_T

typedef struct tag_shtnxor9BIgJASjS9Gre29G shtnxor9BIgJASjS9Gre29G_senso_T;

#endif                                 /*typedef_shtnxor9BIgJASjS9Gre29G_senso_T*/

/* Custom Type definition for MATLAB Function: '<S29>/Predict' */
#ifndef struct_tag_svOPLswpU6zM4xEQHc5jFb
#define struct_tag_svOPLswpU6zM4xEQHc5jFb

struct tag_svOPLswpU6zM4xEQHc5jFb
{
  char_T FcnName[27];
  boolean_T IsSimulinkFcn;
  real_T NumberOfExtraArgumentInports;
  real_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_svOPLswpU6zM4xEQHc5jFb*/

#ifndef typedef_svOPLswpU6zM4xEQHc5jFb_sensor_T
#define typedef_svOPLswpU6zM4xEQHc5jFb_sensor_T

typedef struct tag_svOPLswpU6zM4xEQHc5jFb svOPLswpU6zM4xEQHc5jFb_sensor_T;

#endif                                 /*typedef_svOPLswpU6zM4xEQHc5jFb_sensor_T*/

#ifndef typedef_dsp_MedianFilter_sensorModel_T
#define typedef_dsp_MedianFilter_sensorModel_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_sensorModel_T inputVarSize;
  int32_T NumChannels;
  dsp_private_MedianFilterCG_se_T pMID;
} dsp_MedianFilter_sensorModel_T;

#endif                                 /*typedef_dsp_MedianFilter_sensorModel_T*/

/* Parameters for system: '<S50>/MeasurementUpdate' */
typedef struct P_MeasurementUpdate_sensorMod_T_ P_MeasurementUpdate_sensorMod_T;

/* Parameters for system: '<S55>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_sensorMode_T_ P_EnabledSubsystem_sensorMode_T;

/* Parameters (default storage) */
typedef struct P_sensorModel_T_ P_sensorModel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_sensorModel_T RT_MODEL_sensorModel_T;

#endif                                 /* RTW_HEADER_sensorModel_types_h_ */
