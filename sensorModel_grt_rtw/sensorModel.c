/*
 * sensorModel.c
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

#include "sensorModel.h"
#include "sensorModel_private.h"

/* Block signals (default storage) */
B_sensorModel_T sensorModel_B;

/* Continuous states */
X_sensorModel_T sensorModel_X;

/* Block states (default storage) */
DW_sensorModel_T sensorModel_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_sensorModel_T sensorModel_Y;

/* Real-time model */
RT_MODEL_sensorModel_T sensorModel_M_;
RT_MODEL_sensorModel_T *const sensorModel_M = &sensorModel_M_;

/* Forward declaration for local functions */
static real_T sensorModel_mod(real_T x);

/* Forward declaration for local functions */
static void sensor_MedianFilterCG_resetImpl(dsp_private_MedianFilterCG_se_T *obj);
static void s_MedianFilterCG_trickleDownMax(dsp_private_MedianFilterCG_se_T *obj,
  real_T i);
static void s_MedianFilterCG_trickleDownMin(dsp_private_MedianFilterCG_se_T *obj,
  real_T i);
static void sensorMode_SystemCore_release_m(GPSParser_sensorModel_T *obj);
static void sensorModel_SystemCore_delete_m(GPSParser_sensorModel_T *obj);
static void matlabCodegenHandle_matlabCod_m(GPSParser_sensorModel_T *obj);
static void sensorModel_SystemCore_release(dsp_MedianFilter_sensorModel_T *obj);
static void sensorModel_SystemCore_delete(dsp_MedianFilter_sensorModel_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_MedianFilter_sensorModel_T *obj);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (sensorModel_M->Timing.TaskCounters.TID[2])++;
  if ((sensorModel_M->Timing.TaskCounters.TID[2]) > 18) {/* Sample time: [0.01s, 0.0s] */
    sensorModel_M->Timing.TaskCounters.TID[2] = 0;
  }

  (sensorModel_M->Timing.TaskCounters.TID[3])++;
  if ((sensorModel_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.010526315789473684s, 0.0s] */
    sensorModel_M->Timing.TaskCounters.TID[3] = 0;
  }

  (sensorModel_M->Timing.TaskCounters.TID[4])++;
  if ((sensorModel_M->Timing.TaskCounters.TID[4]) > 1899) {/* Sample time: [1.0s, 0.0s] */
    sensorModel_M->Timing.TaskCounters.TID[4] = 0;
  }
}

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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sensorModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  sensorModel_step();
  sensorModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  sensorModel_step();
  sensorModel_derivatives();

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

/*
 * Output and update for atomic system:
 *    '<S5>/Output'
 *    '<S6>/Output'
 */
void sensorModel_Output(boolean_T rtu_uBlockOrdering, B_Output_sensorModel_T
  *localB, real_T *rtd_P, real_T *rtd_x)
{
  /* DataStoreRead: '<S21>/Data Store Read' */
  localB->DataStoreRead = *rtd_x;

  /* DataStoreRead: '<S21>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_P;

  /* Inport: '<S21>/uBlockOrdering' */
  localB->uBlockOrdering = rtu_uBlockOrdering;
}

/*
 * System initialize for enable system:
 *    '<S50>/MeasurementUpdate'
 *    '<S94>/MeasurementUpdate'
 *    '<S138>/MeasurementUpdate'
 *    '<S182>/MeasurementUpdate'
 *    '<S226>/MeasurementUpdate'
 *    '<S270>/MeasurementUpdate'
 *    '<S314>/MeasurementUpdate'
 *    '<S358>/MeasurementUpdate'
 */
void sensorMo_MeasurementUpdate_Init(B_MeasurementUpdate_sensorMod_T *localB,
  P_MeasurementUpdate_sensorMod_T *localP)
{
  /* SystemInitialize for Outport: '<S75>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S50>/MeasurementUpdate'
 *    '<S94>/MeasurementUpdate'
 *    '<S138>/MeasurementUpdate'
 *    '<S182>/MeasurementUpdate'
 *    '<S226>/MeasurementUpdate'
 *    '<S270>/MeasurementUpdate'
 *    '<S314>/MeasurementUpdate'
 *    '<S358>/MeasurementUpdate'
 */
void senso_MeasurementUpdate_Disable(B_MeasurementUpdate_sensorMod_T *localB,
  DW_MeasurementUpdate_sensorMo_T *localDW, P_MeasurementUpdate_sensorMod_T
  *localP)
{
  /* Disable for Outport: '<S75>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S50>/MeasurementUpdate'
 *    '<S94>/MeasurementUpdate'
 *    '<S138>/MeasurementUpdate'
 *    '<S182>/MeasurementUpdate'
 *    '<S226>/MeasurementUpdate'
 *    '<S270>/MeasurementUpdate'
 *    '<S314>/MeasurementUpdate'
 *    '<S358>/MeasurementUpdate'
 */
void sensorModel_MeasurementUpdate(RT_MODEL_sensorModel_T * const sensorModel_M,
  boolean_T rtu_Enable, real_T rtu_Lk, real_T rtu_yk, real_T rtu_Ck, real_T
  rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk, B_MeasurementUpdate_sensorMod_T
  *localB, DW_MeasurementUpdate_sensorMo_T *localDW,
  P_MeasurementUpdate_sensorMod_T *localP)
{
  real_T tmp;

  /* Outputs for Enabled SubSystem: '<S50>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S75>/Enable'
   */
  if (rtmIsMajorTimeStep(sensorModel_M)) {
    if (rtu_Enable) {
      if (!localDW->MeasurementUpdate_MODE) {
        localDW->MeasurementUpdate_MODE = true;
      }
    } else {
      if (localDW->MeasurementUpdate_MODE) {
        senso_MeasurementUpdate_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->MeasurementUpdate_MODE) {
    /* Product: '<S75>/C[k]*xhat[k|k-1]' */
    localB->Ckxhatkk1 = rtu_Ck * rtu_xhatkk1;

    /* Product: '<S75>/D[k]*u[k]' */
    localB->Dkuk = rtu_Dk * rtu_uk;

    /* Sum: '<S75>/Add1' */
    localB->yhatkk1 = localB->Ckxhatkk1 + localB->Dkuk;

    /* Sum: '<S75>/Sum' */
    localB->Sum = rtu_yk - localB->yhatkk1;

    /* Product: '<S75>/Product3' */
    tmp = localB->Sum;
    localB->Product3 = rtu_Lk * tmp;
  }

  /* End of Outputs for SubSystem: '<S50>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S55>/Enabled Subsystem'
 *    '<S99>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S187>/Enabled Subsystem'
 *    '<S231>/Enabled Subsystem'
 *    '<S275>/Enabled Subsystem'
 *    '<S319>/Enabled Subsystem'
 *    '<S363>/Enabled Subsystem'
 */
void sensorMod_EnabledSubsystem_Init(B_EnabledSubsystem_sensorMode_T *localB,
  P_EnabledSubsystem_sensorMode_T *localP)
{
  /* SystemInitialize for Outport: '<S76>/deltax' */
  localB->Product2 = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S55>/Enabled Subsystem'
 *    '<S99>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S187>/Enabled Subsystem'
 *    '<S231>/Enabled Subsystem'
 *    '<S275>/Enabled Subsystem'
 *    '<S319>/Enabled Subsystem'
 *    '<S363>/Enabled Subsystem'
 */
void sensor_EnabledSubsystem_Disable(B_EnabledSubsystem_sensorMode_T *localB,
  DW_EnabledSubsystem_sensorMod_T *localDW, P_EnabledSubsystem_sensorMode_T
  *localP)
{
  /* Disable for Outport: '<S76>/deltax' */
  localB->Product2 = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S55>/Enabled Subsystem'
 *    '<S99>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S187>/Enabled Subsystem'
 *    '<S231>/Enabled Subsystem'
 *    '<S275>/Enabled Subsystem'
 *    '<S319>/Enabled Subsystem'
 *    '<S363>/Enabled Subsystem'
 */
void sensorModel_EnabledSubsystem(RT_MODEL_sensorModel_T * const sensorModel_M,
  boolean_T rtu_Enable, real_T rtu_Mk, real_T rtu_Ck, real_T rtu_yk, real_T
  rtu_xhatkk1, B_EnabledSubsystem_sensorMode_T *localB,
  DW_EnabledSubsystem_sensorMod_T *localDW, P_EnabledSubsystem_sensorMode_T
  *localP)
{
  real_T tmp;

  /* Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S76>/Enable'
   */
  if (rtmIsMajorTimeStep(sensorModel_M)) {
    if (rtu_Enable) {
      if (!localDW->EnabledSubsystem_MODE) {
        localDW->EnabledSubsystem_MODE = true;
      }
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        sensor_EnabledSubsystem_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* Product: '<S76>/Product' */
    localB->Product = rtu_Ck * rtu_xhatkk1;

    /* Sum: '<S76>/Add1' */
    localB->Add1 = rtu_yk - localB->Product;

    /* Product: '<S76>/Product2' */
    tmp = localB->Add1;
    localB->Product2 = rtu_Mk * tmp;
  }

  /* End of Outputs for SubSystem: '<S55>/Enabled Subsystem' */
}

/* Function for MATLAB Function: '<S386>/MATLAB Function' */
static real_T sensorModel_mod(real_T x)
{
  real_T r;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, 100.0);
      if (r == 0.0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += 100.0;
        }
      }
    }
  } else {
    r = (rtNaN);
  }

  return r;
}

/*
 * Output and update for atomic system:
 *    '<S386>/MATLAB Function'
 *    '<S386>/MATLAB Function1'
 */
void sensorModel_MATLABFunction(real_T rtu_dms, real_T *rty_decideg)
{
  /* :  if(dms == abs(dms)) */
  if (rtu_dms == fabs(rtu_dms)) {
    /* :  decideg = floor(abs(dms)/100) + mod(abs(dms), 100)/60; */
    *rty_decideg = floor(fabs(rtu_dms) / 100.0) + sensorModel_mod(fabs(rtu_dms))
      / 60.0;
  } else {
    /* :  else */
    /* :  decideg = -1 * floor(abs(dms)/100) + mod(abs(dms), 100)/60; */
    *rty_decideg = -floor(fabs(rtu_dms) / 100.0) + sensorModel_mod(fabs(rtu_dms))
      / 60.0;
  }
}

static void sensor_MedianFilterCG_resetImpl(dsp_private_MedianFilterCG_se_T *obj)
{
  real_T wlen;
  real_T cnt2;
  int32_T b_index;
  int32_T c_index;
  int32_T r;
  boolean_T rEQ0;
  memset(&obj->pBuf[0], 0, 20U * sizeof(real_T));
  memset(&obj->pPos[0], 0, 20U * sizeof(real_T));
  memset(&obj->pHeap[0], 0, 20U * sizeof(real_T));
  obj->pWinLen = 20.0;
  obj->pIdx = obj->pWinLen;
  wlen = (obj->pWinLen + 1.0) / 2.0;
  wlen = ceil(wlen);
  obj->pMidHeap = wlen;
  wlen = (obj->pWinLen - 1.0) / 2.0;
  wlen = trunc(wlen);
  obj->pMinHeapLength = wlen;
  wlen = obj->pWinLen / 2.0;
  wlen = trunc(wlen);
  obj->pMaxHeapLength = wlen;
  wlen = 1.0;
  cnt2 = obj->pWinLen;
  for (c_index = 0; c_index < 20; c_index++) {
    b_index = 20 - c_index;
    r = (int32_T)fmod(b_index, 2.0);
    rEQ0 = (r == 0);
    if (rEQ0) {
      r = 0;
    }

    if (r == 0) {
      obj->pPos[b_index - 1] = wlen;
      wlen++;
    } else {
      obj->pPos[b_index - 1] = cnt2;
      cnt2--;
    }

    obj->pHeap[(int32_T)obj->pPos[b_index - 1] - 1] = b_index;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void s_MedianFilterCG_trickleDownMax(dsp_private_MedianFilterCG_se_T *obj,
  real_T i)
{
  boolean_T flag;
  dsp_private_MedianFilterCG_se_T *obj_0;
  real_T ind2;
  real_T x;
  real_T temp;
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i >= -obj->pMaxHeapLength)) {
    if ((i < -1.0) && (i > -obj->pMaxHeapLength)) {
      obj_0 = obj;
      ind2 = i - 1.0;
      flag = (obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(i + obj_0->pMidHeap) -
              1] - 1] < obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(ind2 +
               obj_0->pMidHeap) - 1] - 1]);
      if (flag) {
        i--;
      }
    }

    x = i / 2.0;
    x = trunc(x);
    obj_0 = obj;
    flag = (obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(x + obj_0->pMidHeap) - 1]
            - 1] < obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(i +
             obj_0->pMidHeap) - 1] - 1]);
    if (!flag) {
      exitg1 = true;
    } else {
      x = i / 2.0;
      x = trunc(x);
      obj_0 = obj;
      ind2 = i;
      x += obj_0->pMidHeap;
      ind2 += obj_0->pMidHeap;
      temp = obj_0->pHeap[(int32_T)x - 1];
      obj_0->pHeap[(int32_T)x - 1] = obj_0->pHeap[(int32_T)ind2 - 1];
      obj_0->pHeap[(int32_T)ind2 - 1] = temp;
      obj_0->pPos[(int32_T)obj_0->pHeap[(int32_T)x - 1] - 1] = x;
      obj_0->pPos[(int32_T)obj_0->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
      i *= 2.0;
    }
  }
}

static void s_MedianFilterCG_trickleDownMin(dsp_private_MedianFilterCG_se_T *obj,
  real_T i)
{
  boolean_T flag;
  dsp_private_MedianFilterCG_se_T *obj_0;
  real_T ind1;
  real_T x;
  real_T temp;
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i <= obj->pMinHeapLength)) {
    if ((i > 1.0) && (i < obj->pMinHeapLength)) {
      obj_0 = obj;
      ind1 = i + 1.0;
      flag = (obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(ind1 + obj_0->pMidHeap)
              - 1] - 1] < obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(i +
               obj_0->pMidHeap) - 1] - 1]);
      if (flag) {
        i++;
      }
    }

    x = i / 2.0;
    x = trunc(x);
    obj_0 = obj;
    flag = (obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(i + obj_0->pMidHeap) - 1]
            - 1] < obj_0->pBuf[(int32_T)obj_0->pHeap[(int32_T)(x +
             obj_0->pMidHeap) - 1] - 1]);
    if (!flag) {
      exitg1 = true;
    } else {
      x = i / 2.0;
      x = trunc(x);
      obj_0 = obj;
      ind1 = i;
      ind1 += obj_0->pMidHeap;
      x += obj_0->pMidHeap;
      temp = obj_0->pHeap[(int32_T)ind1 - 1];
      obj_0->pHeap[(int32_T)ind1 - 1] = obj_0->pHeap[(int32_T)x - 1];
      obj_0->pHeap[(int32_T)x - 1] = temp;
      obj_0->pPos[(int32_T)obj_0->pHeap[(int32_T)ind1 - 1] - 1] = ind1;
      obj_0->pPos[(int32_T)obj_0->pHeap[(int32_T)x - 1] - 1] = x;
      i *= 2.0;
    }
  }
}

static void sensorMode_SystemCore_release_m(GPSParser_sensorModel_T *obj)
{
  GPSParser_sensorModel_T *obj_0;
  if (obj->isInitialized == 1) {
    obj_0 = obj;
    if (obj_0->isSetupComplete) {
      releaseBuffer();
    }
  }
}

static void sensorModel_SystemCore_delete_m(GPSParser_sensorModel_T *obj)
{
  sensorMode_SystemCore_release_m(obj);
}

static void matlabCodegenHandle_matlabCod_m(GPSParser_sensorModel_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sensorModel_SystemCore_delete_m(obj);
  }
}

static void sensorModel_SystemCore_release(dsp_MedianFilter_sensorModel_T *obj)
{
  dsp_MedianFilter_sensorModel_T *obj_0;
  dsp_private_MedianFilterCG_se_T *obj_1;
  if (obj->isInitialized == 1) {
    obj_0 = obj;
    if (obj_0->isSetupComplete) {
      obj_0->NumChannels = -1;
      obj_1 = &obj_0->pMID;
      if (obj_1->isInitialized == 1) {
        obj_1->isInitialized = 2;
      }
    }
  }
}

static void sensorModel_SystemCore_delete(dsp_MedianFilter_sensorModel_T *obj)
{
  sensorModel_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_MedianFilter_sensorModel_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sensorModel_SystemCore_delete(obj);
  }
}

/* Model step function */
void sensorModel_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  uint8_T data[32];
  uint8_T sts;
  dsp_MedianFilter_sensorModel_T *obj_0;
  dsp_private_MedianFilterCG_se_T *obj_1;
  dsp_private_MedianFilterCG_se_T *obj_2;
  dsp_private_MedianFilterCG_se_T *obj_3;
  boolean_T flag;
  dsp_private_MedianFilterCG_se_T *obj_4;
  int8_T b_varargout_1;
  uint8_T yout[80];
  int8_T status;
  uint32_T time;
  real_T latitude;
  real_T longitude;
  real_T alti;
  real_T msl;
  real_T speed;
  real_T tckAngle;
  uint32_T date;
  real_T BytesToRead;
  int32_T i;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(sensorModel_M)) {
    /* set solver stop time */
    if (!(sensorModel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sensorModel_M->solverInfo,
                            ((sensorModel_M->Timing.clockTickH0 + 1) *
        sensorModel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sensorModel_M->solverInfo,
                            ((sensorModel_M->Timing.clockTick0 + 1) *
        sensorModel_M->Timing.stepSize0 + sensorModel_M->Timing.clockTickH0 *
        sensorModel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sensorModel_M)) {
    sensorModel_M->Timing.t[0] = rtsiGetT(&sensorModel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* Delay: '<S7>/MemoryX' incorporates:
     *  Constant: '<S7>/X0'
     */
    if (sensorModel_DW.icLoad != 0) {
      sensorModel_DW.MemoryX_DSTATE = sensorModel_P.X0_Value;
    }

    sensorModel_B.MemoryX = sensorModel_DW.MemoryX_DSTATE;

    /* End of Delay: '<S7>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' */
    /* Constant: '<S7>/Enable' incorporates:
     *  Constant: '<S33>/KalmanGainM'
     *  Constant: '<S7>/C'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value,
      sensorModel_P.KalmanGainM_Value, sensorModel_P.C_Value, 0.0,
      sensorModel_B.MemoryX, &sensorModel_B.EnabledSubsystem,
      &sensorModel_DW.EnabledSubsystem, &sensorModel_P.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S55>/Enabled Subsystem' */

    /* Sum: '<S55>/Add' */
    sensorModel_B.Add = sensorModel_B.EnabledSubsystem.Product2 +
      sensorModel_B.MemoryX;

    /* Outport: '<Root>/Pressure' */
    sensorModel_Y.Pressure = sensorModel_B.Add;

    /* Delay: '<S8>/MemoryX' incorporates:
     *  Constant: '<S8>/X0'
     */
    if (sensorModel_DW.icLoad_j != 0) {
      sensorModel_DW.MemoryX_DSTATE_n = sensorModel_P.X0_Value_l;
    }

    sensorModel_B.MemoryX_p = sensorModel_DW.MemoryX_DSTATE_n;

    /* End of Delay: '<S8>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S99>/Enabled Subsystem' */
    /* Constant: '<S8>/Enable' incorporates:
     *  Constant: '<S77>/KalmanGainM'
     *  Constant: '<S8>/C'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_c,
      sensorModel_P.KalmanGainM_Value_o, sensorModel_P.C_Value_k, 0.0,
      sensorModel_B.MemoryX_p, &sensorModel_B.EnabledSubsystem_a,
      &sensorModel_DW.EnabledSubsystem_a, &sensorModel_P.EnabledSubsystem_a);

    /* End of Outputs for SubSystem: '<S99>/Enabled Subsystem' */

    /* Sum: '<S99>/Add' */
    sensorModel_B.Add_a = sensorModel_B.EnabledSubsystem_a.Product2 +
      sensorModel_B.MemoryX_p;

    /* Outport: '<Root>/Temperature' */
    sensorModel_Y.Temperature = sensorModel_B.Add_a;
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Delay: '<S12>/MemoryX' incorporates:
     *  Constant: '<S12>/X0'
     */
    if (sensorModel_DW.icLoad_o != 0) {
      sensorModel_DW.MemoryX_DSTATE_a = sensorModel_P.X0_Value_i;
    }

    sensorModel_B.MemoryX_n = sensorModel_DW.MemoryX_DSTATE_a;

    /* End of Delay: '<S12>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S275>/Enabled Subsystem' */
    /* Constant: '<S12>/Enable' incorporates:
     *  Constant: '<S12>/C'
     *  Constant: '<S253>/KalmanGainM'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_o,
      sensorModel_P.KalmanGainM_Value_n, sensorModel_P.C_Value_p, 0.0,
      sensorModel_B.MemoryX_n, &sensorModel_B.EnabledSubsystem_p,
      &sensorModel_DW.EnabledSubsystem_p, &sensorModel_P.EnabledSubsystem_p);

    /* End of Outputs for SubSystem: '<S275>/Enabled Subsystem' */

    /* Sum: '<S275>/Add' */
    sensorModel_B.Add_c = sensorModel_B.EnabledSubsystem_p.Product2 +
      sensorModel_B.MemoryX_n;

    /* Delay: '<S13>/MemoryX' incorporates:
     *  Constant: '<S13>/X0'
     */
    if (sensorModel_DW.icLoad_o2 != 0) {
      sensorModel_DW.MemoryX_DSTATE_b = sensorModel_P.X0_Value_c;
    }

    sensorModel_B.MemoryX_c = sensorModel_DW.MemoryX_DSTATE_b;

    /* End of Delay: '<S13>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S319>/Enabled Subsystem' */
    /* Constant: '<S13>/Enable' incorporates:
     *  Constant: '<S13>/C'
     *  Constant: '<S297>/KalmanGainM'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_f,
      sensorModel_P.KalmanGainM_Value_j, sensorModel_P.C_Value_i, 0.0,
      sensorModel_B.MemoryX_c, &sensorModel_B.EnabledSubsystem_e,
      &sensorModel_DW.EnabledSubsystem_e, &sensorModel_P.EnabledSubsystem_e);

    /* End of Outputs for SubSystem: '<S319>/Enabled Subsystem' */

    /* Sum: '<S319>/Add' */
    sensorModel_B.Add_j = sensorModel_B.EnabledSubsystem_e.Product2 +
      sensorModel_B.MemoryX_c;

    /* Delay: '<S14>/MemoryX' incorporates:
     *  Constant: '<S14>/X0'
     */
    if (sensorModel_DW.icLoad_e != 0) {
      sensorModel_DW.MemoryX_DSTATE_p = sensorModel_P.X0_Value_iz;
    }

    sensorModel_B.MemoryX_l = sensorModel_DW.MemoryX_DSTATE_p;

    /* End of Delay: '<S14>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S363>/Enabled Subsystem' */
    /* Constant: '<S14>/Enable' incorporates:
     *  Constant: '<S14>/C'
     *  Constant: '<S341>/KalmanGainM'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_l,
      sensorModel_P.KalmanGainM_Value_m, sensorModel_P.C_Value_m, 0.0,
      sensorModel_B.MemoryX_l, &sensorModel_B.EnabledSubsystem_ej,
      &sensorModel_DW.EnabledSubsystem_ej, &sensorModel_P.EnabledSubsystem_ej);

    /* End of Outputs for SubSystem: '<S363>/Enabled Subsystem' */

    /* Sum: '<S363>/Add' */
    sensorModel_B.Add_p = sensorModel_B.EnabledSubsystem_ej.Product2 +
      sensorModel_B.MemoryX_l;

    /* Outport: '<Root>/A_{be}' */
    sensorModel_Y.A_be[0] = sensorModel_B.Add_c;
    sensorModel_Y.A_be[1] = sensorModel_B.Add_j;
    sensorModel_Y.A_be[2] = sensorModel_B.Add_p;
  }

  /* Integrator: '<Root>/Integrator6' */
  sensorModel_B.Integrator6 = sensorModel_X.Integrator6_CSTATE;

  /* Integrator: '<Root>/Integrator7' */
  sensorModel_B.Integrator7 = sensorModel_X.Integrator7_CSTATE;

  /* Integrator: '<Root>/Integrator8' */
  sensorModel_B.Integrator8 = sensorModel_X.Integrator8_CSTATE;

  /* Outport: '<Root>/V_{b}' */
  sensorModel_Y.V_b[0] = sensorModel_B.Integrator6;
  sensorModel_Y.V_b[1] = sensorModel_B.Integrator7;
  sensorModel_Y.V_b[2] = sensorModel_B.Integrator8;

  /* Integrator: '<Root>/Integrator9' */
  sensorModel_B.Integrator9 = sensorModel_X.Integrator9_CSTATE;

  /* Integrator: '<Root>/Integrator10' */
  sensorModel_B.Integrator10 = sensorModel_X.Integrator10_CSTATE;

  /* Integrator: '<Root>/Integrator11' */
  sensorModel_B.Integrator11 = sensorModel_X.Integrator11_CSTATE;

  /* Outport: '<Root>/X_{e}' */
  sensorModel_Y.X_e[0] = sensorModel_B.Integrator9;
  sensorModel_Y.X_e[1] = sensorModel_B.Integrator10;
  sensorModel_Y.X_e[2] = sensorModel_B.Integrator11;
  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* MATLABSystem: '<S18>/Serial_Receive1' */
    obj = &sensorModel_DW.obj_b;
    MW_Serial_read(1, obj->DataSizeInBytes, data, &sts);
    for (i = 0; i < 32; i++) {
      sensorModel_B.RawSerialdata[i] = data[i];
    }

    sensorModel_B.Serial_Receive1_o2 = sts;

    /* End of MATLABSystem: '<S18>/Serial_Receive1' */

    /* Outputs for Enabled SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' incorporates:
     *  EnablePort: '<S386>/Enable'
     */
    if (rtmIsMajorTimeStep(sensorModel_M)) {
      if (sensorModel_B.Serial_Receive1_o2 > 0) {
        if (!sensorModel_DW.GPGGA_GPRMC_Parser1_MODE) {
          sensorModel_DW.GPGGA_GPRMC_Parser1_MODE = true;
        }
      } else {
        if (sensorModel_DW.GPGGA_GPRMC_Parser1_MODE) {
          /* Disable for Outport: '<S386>/lat' */
          sensorModel_B.VectorConcatenate[0] = sensorModel_P.lat_Y0;
          sensorModel_DW.GPGGA_GPRMC_Parser1_MODE = false;
        }
      }
    }

    if (sensorModel_DW.GPGGA_GPRMC_Parser1_MODE) {
      /* MATLABSystem: '<S386>/MATLAB_System' */
      for (i = 0; i < 32; i++) {
        data[i] = sensorModel_B.RawSerialdata[i];
      }

      b_varargout_1 = 0;
      latitude = 0.0;
      longitude = 0.0;
      sts = 0U;
      alti = 0.0;
      speed = 0.0;
      tckAngle = 0.0;
      readData(data, 32, 36, 13, 44, 42, yout, 80, &status);
      if (status == 1) {
        parseData(yout, &time, &latitude, &longitude, &sts, &BytesToRead, &alti,
                  &msl, &speed, &tckAngle, &date, 80, 44, &b_varargout_1);
      } else {
        if (status < 0) {
          b_varargout_1 = status;
        }
      }

      sensorModel_B.MATLAB_System_o1 = b_varargout_1;
      sensorModel_B.MATLAB_System_o2 = latitude;
      sensorModel_B.MATLAB_System_o3 = longitude;
      sensorModel_B.MATLAB_System_o4 = sts;
      sensorModel_B.MATLAB_System_o5 = alti;
      sensorModel_B.MATLAB_System_o6 = speed;
      sensorModel_B.MATLAB_System_o7 = tckAngle;

      /* End of MATLABSystem: '<S386>/MATLAB_System' */

      /* MATLAB Function: '<S386>/MATLAB Function' */
      sensorModel_MATLABFunction(sensorModel_B.MATLAB_System_o2,
        &sensorModel_B.VectorConcatenate[0]);

      /* MATLAB Function: '<S386>/MATLAB Function1' */
      sensorModel_MATLABFunction(sensorModel_B.MATLAB_System_o3,
        &sensorModel_B.VectorConcatenate[1]);

      /* SignalConversion: '<S386>/TmpMLSysMemLayoutBufferAtMATLAB_SystemOutport5' */
      sensorModel_B.VectorConcatenate[2] = sensorModel_B.MATLAB_System_o5;

      /* SignalConversion: '<S386>/TmpMLSysMemLayoutBufferAtMATLAB_SystemOutport6' */
      sensorModel_B.TmpMLSysMemLayoutBufferAtMATLAB =
        sensorModel_B.MATLAB_System_o6;

      /* SignalConversion: '<S386>/TmpMLSysMemLayoutBufferAtMATLAB_SystemOutport7' */
      sensorModel_B.TmpMLSysMemLayoutBufferAtMATL_e =
        sensorModel_B.MATLAB_System_o7;
    }

    /* End of Outputs for SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */

    /* Sum: '<Root>/Subtract2' incorporates:
     *  Constant: '<Root>/MagVar'
     */
    sensorModel_B.Subtract2 = sensorModel_B.TmpMLSysMemLayoutBufferAtMATL_e +
      sensorModel_P.magVar;

    /* Product: '<Root>/Divide' incorporates:
     *  Constant: '<Root>/Constant'
     */
    sensorModel_B.Divide = sensorModel_P.Constant_Value / (real_T)
      sensorModel_B.MATLAB_System_o4;

    /* Sum: '<Root>/Subtract3' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    sensorModel_B.Subtract3 = sensorModel_B.Divide -
      sensorModel_P.Constant1_Value;
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion: '<S385>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S16>/MATLAB Function'
     */
    sensorModel_B.TmpSignalConversionAtSFunctionI[0] = 0.0;
    sensorModel_B.TmpSignalConversionAtSFunctionI[1] = 0.0;
    sensorModel_B.TmpSignalConversionAtSFunctionI[2] = 0.0;

    /* MATLAB Function: '<S16>/MATLAB Function' */
    /* :  hdg_deg = rad2deg(atan2(magField(2), magField(1))); */
    sensorModel_B.hdg_deg = 57.295779513082323 * rt_atan2d_snf
      (sensorModel_B.TmpSignalConversionAtSFunctionI[1],
       sensorModel_B.TmpSignalConversionAtSFunctionI[0]);

    /* Outputs for Enabled SubSystem: '<S5>/Correct1' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    /* Constant: '<S5>/Enable1' */
    if (sensorModel_P.Enable1_Value) {
      /* DataStoreRead: '<S19>/Data Store ReadX' */
      sensorModel_B.DataStoreReadX_d = sensorModel_DW.x;

      /* DataStoreRead: '<S19>/Data Store ReadP' */
      sensorModel_B.P_ec = sensorModel_DW.P;

      /* MATLAB Function: '<S19>/Correct' incorporates:
       *  Constant: '<S5>/BlockOrdering'
       *  Constant: '<S5>/R1'
       */
      sensorModel_B.blockOrdering_g = sensorModel_P.BlockOrdering_Value;

      /* :  if pM.IsSimulinkFcn */
      /* :  else */
      /* :  MeasurementFcnH = str2func(pM.FcnName); */
      /* :  if pM.HasJacobian */
      /* :  MeasurementJacobianFcnH = []; */
      /* :  switch pM.NumberOfExtraArgumentInports */
      /* :  case 0 */
      /* :  extraArgs = {}; */
      /* :  xNew = zeros(size(x),'like',x); */
      /* :  if pM.HasAdditiveNoise */
      /* :  [xNew,P] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
      /* :          yMeas,R,x,P,MeasurementFcnH,MeasurementJacobianFcnH,extraArgs{:}); */
      /* 'baroMeasurementFunc:5' y = x; */
      latitude = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                      (sensorModel_B.DataStoreReadX_d));

      /* 'baroMeasurementFunc:5' y = x; */
      latitude = ((sensorModel_B.DataStoreReadX_d + latitude) -
                  sensorModel_B.DataStoreReadX_d) / latitude;

      /* 'baroMeasurementFunc:5' y = x; */
      longitude = sensorModel_B.P_ec * latitude / (latitude * sensorModel_B.P_ec
        * latitude + sensorModel_P.R1_Value);
      sensorModel_B.xNew_b = (sensorModel_B.hdg_deg -
        sensorModel_B.DataStoreReadX_d) * longitude +
        sensorModel_B.DataStoreReadX_d;
      sensorModel_B.P_ec -= longitude * latitude * sensorModel_B.P_ec;

      /* DataStoreWrite: '<S19>/Data Store WriteP' */
      sensorModel_DW.P = sensorModel_B.P_ec;

      /* DataStoreWrite: '<S19>/Data Store WriteX' */
      sensorModel_DW.x = sensorModel_B.xNew_b;
    }

    /* End of Constant: '<S5>/Enable1' */
    /* End of Outputs for SubSystem: '<S5>/Correct1' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/Correct2' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* Constant: '<S5>/Enable2' */
  if ((rtmIsMajorTimeStep(sensorModel_M) &&
       sensorModel_M->Timing.TaskCounters.TID[4] == 0) &&
      sensorModel_P.Enable2_Value) {
    /* DataStoreRead: '<S20>/Data Store ReadX' */
    sensorModel_B.DataStoreReadX_k = sensorModel_DW.x;

    /* DataStoreRead: '<S20>/Data Store ReadP' */
    sensorModel_B.P_j = sensorModel_DW.P;

    /* MATLAB Function: '<S20>/Correct' */
    sensorModel_B.blockOrdering_a = sensorModel_B.blockOrdering_g;

    /* :  if pM.IsSimulinkFcn */
    /* :  else */
    /* :  MeasurementFcnH = str2func(pM.FcnName); */
    /* :  if pM.HasJacobian */
    /* :  MeasurementJacobianFcnH = []; */
    /* :  switch pM.NumberOfExtraArgumentInports */
    /* :  case 0 */
    /* :  extraArgs = {}; */
    /* :  xNew = zeros(size(x),'like',x); */
    /* :  if pM.HasAdditiveNoise */
    /* :  [xNew,P] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
    /* :          yMeas,R,x,P,MeasurementFcnH,MeasurementJacobianFcnH,extraArgs{:}); */
    /* 'gpsMeasurementFunc:5' y = x; */
    latitude = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                    (sensorModel_B.DataStoreReadX_k));

    /* 'gpsMeasurementFunc:5' y = x; */
    latitude = ((sensorModel_B.DataStoreReadX_k + latitude) -
                sensorModel_B.DataStoreReadX_k) / latitude;

    /* 'gpsMeasurementFunc:5' y = x; */
    longitude = sensorModel_B.P_j * latitude / (latitude * sensorModel_B.P_j *
      latitude + sensorModel_B.Subtract3);
    sensorModel_B.xNew_d = (sensorModel_B.Subtract2 -
      sensorModel_B.DataStoreReadX_k) * longitude +
      sensorModel_B.DataStoreReadX_k;
    sensorModel_B.P_j -= longitude * latitude * sensorModel_B.P_j;

    /* DataStoreWrite: '<S20>/Data Store WriteP' */
    sensorModel_DW.P = sensorModel_B.P_j;

    /* DataStoreWrite: '<S20>/Data Store WriteX' */
    sensorModel_DW.x = sensorModel_B.xNew_d;
  }

  /* End of Constant: '<S5>/Enable2' */
  /* End of Outputs for SubSystem: '<S5>/Correct2' */
  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Atomic SubSystem: '<S5>/Output' */
    sensorModel_Output(sensorModel_B.blockOrdering_a, &sensorModel_B.Output,
                       &sensorModel_DW.P, &sensorModel_DW.x);

    /* End of Outputs for SubSystem: '<S5>/Output' */
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    sensorModel_B.Compare = (sensorModel_B.MATLAB_System_o4 <=
      sensorModel_P.MinNumofSatsforgoodfix_const);
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Switch: '<Root>/Hdg Selector' */
    if (sensorModel_B.Compare) {
      sensorModel_B.Heading = sensorModel_B.Output.DataStoreRead;
    } else {
      sensorModel_B.Heading = sensorModel_B.hdg_deg;
    }

    /* End of Switch: '<Root>/Hdg Selector' */

    /* Outport: '<Root>/Heading' */
    sensorModel_Y.Heading = sensorModel_B.Heading;
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* MATLABSystem: '<Root>/Median Filter' */
    alti = sensorModel_B.VectorConcatenate[0];
    msl = sensorModel_B.VectorConcatenate[1];
    latitude = sensorModel_B.VectorConcatenate[2];
    obj_0 = &sensorModel_DW.obj;
    obj_1 = &obj_0->pMID;
    if (obj_1->isInitialized != 1) {
      obj_2 = obj_1;
      obj_3 = obj_2;
      obj_3->isSetupComplete = false;
      obj_3->isInitialized = 1;
      obj_3->isSetupComplete = true;
      sensor_MedianFilterCG_resetImpl(obj_2);
    }

    obj_2 = obj_1;
    speed = obj_2->pBuf[(int32_T)obj_2->pIdx - 1];
    obj_2->pBuf[(int32_T)obj_2->pIdx - 1] = alti;
    longitude = obj_2->pPos[(int32_T)obj_2->pIdx - 1];
    obj_2->pIdx++;
    if (obj_2->pWinLen + 1.0 == obj_2->pIdx) {
      obj_2->pIdx = 1.0;
    }

    if (longitude > obj_2->pMidHeap) {
      if (speed < alti) {
        s_MedianFilterCG_trickleDownMin(obj_2, (longitude - obj_2->pMidHeap) *
          2.0);
      } else {
        obj_3 = obj_2;
        longitude -= obj_3->pMidHeap;
        exitg1 = false;
        while ((!exitg1) && (longitude > 0.0)) {
          alti = longitude / 2.0;
          alti = trunc(alti);
          obj_4 = obj_3;
          flag = (obj_4->pBuf[(int32_T)obj_4->pHeap[(int32_T)(longitude +
                   obj_4->pMidHeap) - 1] - 1] < obj_4->pBuf[(int32_T)
                  obj_4->pHeap[(int32_T)(alti + obj_4->pMidHeap) - 1] - 1]);
          if (!flag) {
            exitg1 = true;
          } else {
            alti = longitude / 2.0;
            alti = trunc(alti);
            obj_4 = obj_3;
            tckAngle = longitude;
            tckAngle += obj_4->pMidHeap;
            alti += obj_4->pMidHeap;
            speed = obj_4->pHeap[(int32_T)tckAngle - 1];
            obj_4->pHeap[(int32_T)tckAngle - 1] = obj_4->pHeap[(int32_T)alti - 1];
            obj_4->pHeap[(int32_T)alti - 1] = speed;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)tckAngle - 1] - 1] =
              tckAngle;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)alti - 1] - 1] = alti;
            longitude /= 2.0;
            longitude = trunc(longitude);
          }
        }

        flag = (longitude == 0.0);
        if (flag) {
          s_MedianFilterCG_trickleDownMax(obj_2, -1.0);
        }
      }
    } else if (longitude < obj_2->pMidHeap) {
      if (alti < speed) {
        s_MedianFilterCG_trickleDownMax(obj_2, (longitude - obj_2->pMidHeap) *
          2.0);
      } else {
        obj_3 = obj_2;
        longitude -= obj_3->pMidHeap;
        exitg1 = false;
        while ((!exitg1) && (longitude < 0.0)) {
          alti = longitude / 2.0;
          alti = trunc(alti);
          obj_4 = obj_3;
          flag = (obj_4->pBuf[(int32_T)obj_4->pHeap[(int32_T)(alti +
                   obj_4->pMidHeap) - 1] - 1] < obj_4->pBuf[(int32_T)
                  obj_4->pHeap[(int32_T)(longitude + obj_4->pMidHeap) - 1] - 1]);
          if (!flag) {
            exitg1 = true;
          } else {
            alti = longitude / 2.0;
            alti = trunc(alti);
            obj_4 = obj_3;
            tckAngle = longitude;
            alti += obj_4->pMidHeap;
            tckAngle += obj_4->pMidHeap;
            speed = obj_4->pHeap[(int32_T)alti - 1];
            obj_4->pHeap[(int32_T)alti - 1] = obj_4->pHeap[(int32_T)tckAngle - 1];
            obj_4->pHeap[(int32_T)tckAngle - 1] = speed;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)alti - 1] - 1] = alti;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)tckAngle - 1] - 1] =
              tckAngle;
            longitude /= 2.0;
            longitude = trunc(longitude);
          }
        }

        flag = (longitude == 0.0);
        if (flag) {
          s_MedianFilterCG_trickleDownMin(obj_2, 1.0);
        }
      }
    } else {
      if (obj_2->pMaxHeapLength != 0.0) {
        s_MedianFilterCG_trickleDownMax(obj_2, -1.0);
      }

      if (obj_2->pMinHeapLength > 0.0) {
        s_MedianFilterCG_trickleDownMin(obj_2, 1.0);
      }
    }

    obj_2 = obj_1;
    alti = obj_2->pBuf[(int32_T)obj_2->pHeap[(int32_T)obj_2->pMidHeap - 1] - 1];
    alti = (obj_2->pBuf[(int32_T)obj_2->pHeap[(int32_T)(obj_2->pMidHeap - 1.0) -
            1] - 1] + alti) / 2.0;
    BytesToRead = alti;
    obj_2 = obj_1;
    alti = msl;
    speed = obj_2->pBuf[(int32_T)obj_2->pIdx - 1];
    obj_2->pBuf[(int32_T)obj_2->pIdx - 1] = alti;
    longitude = obj_2->pPos[(int32_T)obj_2->pIdx - 1];
    obj_2->pIdx++;
    if (obj_2->pWinLen + 1.0 == obj_2->pIdx) {
      obj_2->pIdx = 1.0;
    }

    if (longitude > obj_2->pMidHeap) {
      if (speed < alti) {
        s_MedianFilterCG_trickleDownMin(obj_2, (longitude - obj_2->pMidHeap) *
          2.0);
      } else {
        obj_3 = obj_2;
        longitude -= obj_3->pMidHeap;
        exitg1 = false;
        while ((!exitg1) && (longitude > 0.0)) {
          alti = longitude / 2.0;
          alti = trunc(alti);
          obj_4 = obj_3;
          flag = (obj_4->pBuf[(int32_T)obj_4->pHeap[(int32_T)(longitude +
                   obj_4->pMidHeap) - 1] - 1] < obj_4->pBuf[(int32_T)
                  obj_4->pHeap[(int32_T)(alti + obj_4->pMidHeap) - 1] - 1]);
          if (!flag) {
            exitg1 = true;
          } else {
            alti = longitude / 2.0;
            alti = trunc(alti);
            obj_4 = obj_3;
            tckAngle = longitude;
            tckAngle += obj_4->pMidHeap;
            alti += obj_4->pMidHeap;
            speed = obj_4->pHeap[(int32_T)tckAngle - 1];
            obj_4->pHeap[(int32_T)tckAngle - 1] = obj_4->pHeap[(int32_T)alti - 1];
            obj_4->pHeap[(int32_T)alti - 1] = speed;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)tckAngle - 1] - 1] =
              tckAngle;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)alti - 1] - 1] = alti;
            longitude /= 2.0;
            longitude = trunc(longitude);
          }
        }

        flag = (longitude == 0.0);
        if (flag) {
          s_MedianFilterCG_trickleDownMax(obj_2, -1.0);
        }
      }
    } else if (longitude < obj_2->pMidHeap) {
      if (alti < speed) {
        s_MedianFilterCG_trickleDownMax(obj_2, (longitude - obj_2->pMidHeap) *
          2.0);
      } else {
        obj_3 = obj_2;
        longitude -= obj_3->pMidHeap;
        exitg1 = false;
        while ((!exitg1) && (longitude < 0.0)) {
          alti = longitude / 2.0;
          alti = trunc(alti);
          obj_4 = obj_3;
          flag = (obj_4->pBuf[(int32_T)obj_4->pHeap[(int32_T)(alti +
                   obj_4->pMidHeap) - 1] - 1] < obj_4->pBuf[(int32_T)
                  obj_4->pHeap[(int32_T)(longitude + obj_4->pMidHeap) - 1] - 1]);
          if (!flag) {
            exitg1 = true;
          } else {
            alti = longitude / 2.0;
            alti = trunc(alti);
            obj_4 = obj_3;
            tckAngle = longitude;
            alti += obj_4->pMidHeap;
            tckAngle += obj_4->pMidHeap;
            speed = obj_4->pHeap[(int32_T)alti - 1];
            obj_4->pHeap[(int32_T)alti - 1] = obj_4->pHeap[(int32_T)tckAngle - 1];
            obj_4->pHeap[(int32_T)tckAngle - 1] = speed;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)alti - 1] - 1] = alti;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)tckAngle - 1] - 1] =
              tckAngle;
            longitude /= 2.0;
            longitude = trunc(longitude);
          }
        }

        flag = (longitude == 0.0);
        if (flag) {
          s_MedianFilterCG_trickleDownMin(obj_2, 1.0);
        }
      }
    } else {
      if (obj_2->pMaxHeapLength != 0.0) {
        s_MedianFilterCG_trickleDownMax(obj_2, -1.0);
      }

      if (obj_2->pMinHeapLength > 0.0) {
        s_MedianFilterCG_trickleDownMin(obj_2, 1.0);
      }
    }

    obj_2 = obj_1;
    alti = obj_2->pBuf[(int32_T)obj_2->pHeap[(int32_T)obj_2->pMidHeap - 1] - 1];
    alti = (obj_2->pBuf[(int32_T)obj_2->pHeap[(int32_T)(obj_2->pMidHeap - 1.0) -
            1] - 1] + alti) / 2.0;
    msl = alti;
    obj_2 = obj_1;
    alti = latitude;
    speed = obj_2->pBuf[(int32_T)obj_2->pIdx - 1];
    obj_2->pBuf[(int32_T)obj_2->pIdx - 1] = alti;
    longitude = obj_2->pPos[(int32_T)obj_2->pIdx - 1];
    obj_2->pIdx++;
    if (obj_2->pWinLen + 1.0 == obj_2->pIdx) {
      obj_2->pIdx = 1.0;
    }

    if (longitude > obj_2->pMidHeap) {
      if (speed < alti) {
        s_MedianFilterCG_trickleDownMin(obj_2, (longitude - obj_2->pMidHeap) *
          2.0);
      } else {
        obj_3 = obj_2;
        longitude -= obj_3->pMidHeap;
        exitg1 = false;
        while ((!exitg1) && (longitude > 0.0)) {
          alti = longitude / 2.0;
          alti = trunc(alti);
          obj_4 = obj_3;
          flag = (obj_4->pBuf[(int32_T)obj_4->pHeap[(int32_T)(longitude +
                   obj_4->pMidHeap) - 1] - 1] < obj_4->pBuf[(int32_T)
                  obj_4->pHeap[(int32_T)(alti + obj_4->pMidHeap) - 1] - 1]);
          if (!flag) {
            exitg1 = true;
          } else {
            alti = longitude / 2.0;
            alti = trunc(alti);
            obj_4 = obj_3;
            tckAngle = longitude;
            tckAngle += obj_4->pMidHeap;
            alti += obj_4->pMidHeap;
            speed = obj_4->pHeap[(int32_T)tckAngle - 1];
            obj_4->pHeap[(int32_T)tckAngle - 1] = obj_4->pHeap[(int32_T)alti - 1];
            obj_4->pHeap[(int32_T)alti - 1] = speed;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)tckAngle - 1] - 1] =
              tckAngle;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)alti - 1] - 1] = alti;
            longitude /= 2.0;
            longitude = trunc(longitude);
          }
        }

        flag = (longitude == 0.0);
        if (flag) {
          s_MedianFilterCG_trickleDownMax(obj_2, -1.0);
        }
      }
    } else if (longitude < obj_2->pMidHeap) {
      if (alti < speed) {
        s_MedianFilterCG_trickleDownMax(obj_2, (longitude - obj_2->pMidHeap) *
          2.0);
      } else {
        obj_3 = obj_2;
        longitude -= obj_3->pMidHeap;
        exitg1 = false;
        while ((!exitg1) && (longitude < 0.0)) {
          alti = longitude / 2.0;
          alti = trunc(alti);
          obj_4 = obj_3;
          flag = (obj_4->pBuf[(int32_T)obj_4->pHeap[(int32_T)(alti +
                   obj_4->pMidHeap) - 1] - 1] < obj_4->pBuf[(int32_T)
                  obj_4->pHeap[(int32_T)(longitude + obj_4->pMidHeap) - 1] - 1]);
          if (!flag) {
            exitg1 = true;
          } else {
            alti = longitude / 2.0;
            alti = trunc(alti);
            obj_4 = obj_3;
            tckAngle = longitude;
            alti += obj_4->pMidHeap;
            tckAngle += obj_4->pMidHeap;
            speed = obj_4->pHeap[(int32_T)alti - 1];
            obj_4->pHeap[(int32_T)alti - 1] = obj_4->pHeap[(int32_T)tckAngle - 1];
            obj_4->pHeap[(int32_T)tckAngle - 1] = speed;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)alti - 1] - 1] = alti;
            obj_4->pPos[(int32_T)obj_4->pHeap[(int32_T)tckAngle - 1] - 1] =
              tckAngle;
            longitude /= 2.0;
            longitude = trunc(longitude);
          }
        }

        flag = (longitude == 0.0);
        if (flag) {
          s_MedianFilterCG_trickleDownMin(obj_2, 1.0);
        }
      }
    } else {
      if (obj_2->pMaxHeapLength != 0.0) {
        s_MedianFilterCG_trickleDownMax(obj_2, -1.0);
      }

      if (obj_2->pMinHeapLength > 0.0) {
        s_MedianFilterCG_trickleDownMin(obj_2, 1.0);
      }
    }

    obj_2 = obj_1;
    alti = obj_2->pBuf[(int32_T)obj_2->pHeap[(int32_T)obj_2->pMidHeap - 1] - 1];
    alti = (obj_2->pBuf[(int32_T)obj_2->pHeap[(int32_T)(obj_2->pMidHeap - 1.0) -
            1] - 1] + alti) / 2.0;
    sensorModel_B.GPS_LLA[0] = BytesToRead;

    /* Outport: '<Root>/GPS_LLA' */
    sensorModel_Y.GPS_LLA[0] = sensorModel_B.GPS_LLA[0];

    /* MATLABSystem: '<Root>/Median Filter' */
    sensorModel_B.GPS_LLA[1] = msl;

    /* Outport: '<Root>/GPS_LLA' */
    sensorModel_Y.GPS_LLA[1] = sensorModel_B.GPS_LLA[1];

    /* MATLABSystem: '<Root>/Median Filter' */
    sensorModel_B.GPS_LLA[2] = alti;

    /* Outport: '<Root>/GPS_LLA' */
    sensorModel_Y.GPS_LLA[2] = sensorModel_B.GPS_LLA[2];

    /* Outport: '<Root>/GPS_GS' */
    sensorModel_Y.GPS_GS = sensorModel_B.TmpMLSysMemLayoutBufferAtMATLAB;

    /* Outputs for Enabled SubSystem: '<S6>/Correct1' incorporates:
     *  EnablePort: '<S26>/Enable'
     */
    /* Constant: '<S6>/Enable1' */
    if (sensorModel_P.Enable1_Value_n) {
      /* DataStoreRead: '<S26>/Data Store ReadX' */
      sensorModel_B.DataStoreReadX_b = sensorModel_DW.x_f;

      /* DataStoreRead: '<S26>/Data Store ReadP' */
      sensorModel_B.P_i = sensorModel_DW.P_k;

      /* MATLAB Function: '<S26>/Correct' incorporates:
       *  Constant: '<S6>/BlockOrdering'
       */
      sensorModel_B.blockOrdering_o = sensorModel_P.BlockOrdering_Value_c;

      /* :  if pM.IsSimulinkFcn */
      /* :  else */
      /* :  MeasurementFcnH = str2func(pM.FcnName); */
      /* :  if pM.HasJacobian */
      /* :  MeasurementJacobianFcnH = []; */
      /* :  switch pM.NumberOfExtraArgumentInports */
      /* :  case 0 */
      /* :  extraArgs = {}; */
      /* :  xNew = zeros(size(x),'like',x); */
      /* :  if pM.HasAdditiveNoise */
      /* :  [xNew,P] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
      /* :          yMeas,R,x,P,MeasurementFcnH,MeasurementJacobianFcnH,extraArgs{:}); */
      /* 'gpsMeasurementFunc:5' y = x; */
      latitude = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                      (sensorModel_B.DataStoreReadX_b));

      /* 'gpsMeasurementFunc:5' y = x; */
      latitude = ((sensorModel_B.DataStoreReadX_b + latitude) -
                  sensorModel_B.DataStoreReadX_b) / latitude;

      /* 'gpsMeasurementFunc:5' y = x; */
      longitude = sensorModel_B.P_i * latitude / (latitude * sensorModel_B.P_i *
        latitude + sensorModel_B.Subtract3);
      sensorModel_B.xNew_i = (sensorModel_B.GPS_LLA[2] -
        sensorModel_B.DataStoreReadX_b) * longitude +
        sensorModel_B.DataStoreReadX_b;
      sensorModel_B.P_i -= longitude * latitude * sensorModel_B.P_i;

      /* DataStoreWrite: '<S26>/Data Store WriteP' */
      sensorModel_DW.P_k = sensorModel_B.P_i;

      /* DataStoreWrite: '<S26>/Data Store WriteX' */
      sensorModel_DW.x_f = sensorModel_B.xNew_i;
    }

    /* End of Constant: '<S6>/Enable1' */
    /* End of Outputs for SubSystem: '<S6>/Correct1' */

    /* Outputs for Enabled SubSystem: '<S6>/Correct2' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    /* Constant: '<S6>/Enable2' */
    if (sensorModel_P.Enable2_Value_k) {
      /* DataStoreRead: '<S27>/Data Store ReadX' */
      sensorModel_B.DataStoreReadX_l = sensorModel_DW.x_f;

      /* DataStoreRead: '<S27>/Data Store ReadP' */
      sensorModel_B.P_e = sensorModel_DW.P_k;

      /* MATLAB Function: '<S27>/Correct' incorporates:
       *  Constant: '<S6>/R2'
       */
      sensorModel_B.blockOrdering = sensorModel_B.blockOrdering_o;

      /* :  if pM.IsSimulinkFcn */
      /* :  else */
      /* :  MeasurementFcnH = str2func(pM.FcnName); */
      /* :  if pM.HasJacobian */
      /* :  MeasurementJacobianFcnH = []; */
      /* :  switch pM.NumberOfExtraArgumentInports */
      /* :  case 0 */
      /* :  extraArgs = {}; */
      /* :  xNew = zeros(size(x),'like',x); */
      /* :  if pM.HasAdditiveNoise */
      /* :  [xNew,P] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
      /* :          yMeas,R,x,P,MeasurementFcnH,MeasurementJacobianFcnH,extraArgs{:}); */
      /* 'baroMeasurementFunc:5' y = x; */
      latitude = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                      (sensorModel_B.DataStoreReadX_l));

      /* 'baroMeasurementFunc:5' y = x; */
      latitude = ((sensorModel_B.DataStoreReadX_l + latitude) -
                  sensorModel_B.DataStoreReadX_l) / latitude;

      /* 'baroMeasurementFunc:5' y = x; */
      longitude = sensorModel_B.P_e * latitude / (latitude * sensorModel_B.P_e *
        latitude + sensorModel_P.R2_Value);
      sensorModel_B.xNew_g = (0.0 - sensorModel_B.DataStoreReadX_l) * longitude
        + sensorModel_B.DataStoreReadX_l;
      sensorModel_B.P_e -= longitude * latitude * sensorModel_B.P_e;

      /* DataStoreWrite: '<S27>/Data Store WriteP' */
      sensorModel_DW.P_k = sensorModel_B.P_e;

      /* DataStoreWrite: '<S27>/Data Store WriteX' */
      sensorModel_DW.x_f = sensorModel_B.xNew_g;
    }

    /* End of Constant: '<S6>/Enable2' */
    /* End of Outputs for SubSystem: '<S6>/Correct2' */

    /* Outputs for Atomic SubSystem: '<S6>/Output' */
    sensorModel_Output(sensorModel_B.blockOrdering, &sensorModel_B.Output_d,
                       &sensorModel_DW.P_k, &sensorModel_DW.x_f);

    /* End of Outputs for SubSystem: '<S6>/Output' */

    /* Switch: '<Root>/Alt Selector' */
    if (sensorModel_B.Compare) {
      sensorModel_B.Altitude = (real32_T)sensorModel_B.Output_d.DataStoreRead;
    } else {
      sensorModel_B.Altitude = 0.0F;
    }

    /* End of Switch: '<Root>/Alt Selector' */

    /* Outport: '<Root>/Altitude' */
    sensorModel_Y.Altitude = sensorModel_B.Altitude;

    /* RelationalOperator: '<S2>/min_relop' incorporates:
     *  Constant: '<S2>/min_val'
     */
    sensorModel_B.min_relop = (sensorModel_P.CheckStaticRange_min <=
      sensorModel_B.Add);

    /* RelationalOperator: '<S2>/max_relop' incorporates:
     *  Constant: '<S2>/max_val'
     */
    sensorModel_B.max_relop = (sensorModel_B.Add <=
      sensorModel_P.CheckStaticRange_max);

    /* Logic: '<S2>/conjunction' */
    sensorModel_B.conjunction = (sensorModel_B.min_relop &&
      sensorModel_B.max_relop);

    /* Logic: '<Root>/NOT' */
    sensorModel_B.PRESS_OOB_ERROR = !sensorModel_B.conjunction;

    /* Outport: '<Root>/PRESS_OOB_ERROR' */
    sensorModel_Y.PRESS_OOB_ERROR = sensorModel_B.PRESS_OOB_ERROR;

    /* RelationalOperator: '<S3>/min_relop' incorporates:
     *  Constant: '<S3>/min_val'
     */
    sensorModel_B.min_relop_i = (sensorModel_P.CheckStaticRange1_min <=
      sensorModel_B.Add_a);

    /* RelationalOperator: '<S3>/max_relop' incorporates:
     *  Constant: '<S3>/max_val'
     */
    sensorModel_B.max_relop_o = (sensorModel_B.Add_a <=
      sensorModel_P.CheckStaticRange1_max);

    /* Logic: '<S3>/conjunction' */
    sensorModel_B.conjunction_a = (sensorModel_B.min_relop_i &&
      sensorModel_B.max_relop_o);

    /* Logic: '<Root>/NOT1' */
    sensorModel_B.TEMP_OOB_ERROR = !sensorModel_B.conjunction_a;

    /* Outport: '<Root>/TEMP_OOB_ERROR' */
    sensorModel_Y.TEMP_OOB_ERROR = sensorModel_B.TEMP_OOB_ERROR;

    /* Outport: '<Root>/GPS_FIX_BAD' */
    sensorModel_Y.GPS_FIX_BAD = sensorModel_B.Compare;
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Abs: '<Root>/Abs2' */
    sensorModel_B.Abs2[0] = fabs(sensorModel_B.Add_c);
    sensorModel_B.Abs2[1] = fabs(sensorModel_B.Add_j);
    sensorModel_B.Abs2[2] = fabs(sensorModel_B.Add_p);

    /* MinMax: '<Root>/MinMax' */
    latitude = sensorModel_B.Abs2[0];
    latitude = fmax(latitude, sensorModel_B.Abs2[1]);
    latitude = fmax(latitude, sensorModel_B.Abs2[2]);
    sensorModel_B.MinMax = latitude;

    /* RelationalOperator: '<S4>/max_relop' incorporates:
     *  Constant: '<S4>/max_val'
     */
    sensorModel_B.max_relop_e = (sensorModel_B.MinMax <=
      sensorModel_P.CheckStaticUpperBound_max);

    /* Outport: '<Root>/AIRFRAME_G_LIMIT_EXCEEDED' */
    sensorModel_Y.AIRFRAME_G_LIMIT_EXCEEDED = sensorModel_B.max_relop_e;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    sensorModel_B.ZeroOrderHold[0] = sensorModel_B.Integrator6;
    sensorModel_B.ZeroOrderHold[1] = sensorModel_B.Integrator7;
    sensorModel_B.ZeroOrderHold[2] = sensorModel_B.Integrator8;

    /* Outputs for Atomic SubSystem: '<S5>/Predict' */
    /* DataStoreRead: '<S22>/Data Store ReadX' */
    sensorModel_B.DataStoreReadX_i = sensorModel_DW.x;

    /* DataStoreRead: '<S22>/Data Store ReadP' */
    sensorModel_B.P_l = sensorModel_DW.P;

    /* MATLAB Function: '<S22>/Predict' incorporates:
     *  Constant: '<S5>/Q'
     */
    /* :  if pS.IsSimulinkFcn */
    /* :  else */
    /* :  StateTransitionFcnH = str2func(pS.FcnName); */
    /* :  if pS.HasJacobian */
    /* :  StateTransitionJacobianFcnH = []; */
    /* :  switch pS.NumberOfExtraArgumentInports */
    /* :  case 1 */
    /* :  extraArgs = {uState}; */
    /* :  xNew = zeros(size(x),'like',x); */
    /* :  if pS.HasAdditiveNoise */
    /* :  [xNew,P] = matlabshared.tracking.internal.EKFPredictorAdditive.predict(... */
    /* :          Q,x,P,StateTransitionFcnH,StateTransitionJacobianFcnH,extraArgs{:}); */
    /* 'headingStateTransitionFunc:7' dt = 1; */
    /* 'headingStateTransitionFunc:8' xhat = x + atan2(v(1), v(2))/dt; */
    latitude = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                    (sensorModel_B.DataStoreReadX_i));

    /* 'headingStateTransitionFunc:7' dt = 1; */
    /* 'headingStateTransitionFunc:8' xhat = x + atan2(v(1), v(2))/dt; */
    latitude = (((sensorModel_B.DataStoreReadX_i + latitude) + rt_atan2d_snf
                 (sensorModel_B.ZeroOrderHold[0], sensorModel_B.ZeroOrderHold[1]))
                - (sensorModel_B.DataStoreReadX_i + rt_atan2d_snf
                   (sensorModel_B.ZeroOrderHold[0], sensorModel_B.ZeroOrderHold
                    [1]))) / latitude;

    /* 'headingStateTransitionFunc:7' dt = 1; */
    /* 'headingStateTransitionFunc:8' xhat = x + atan2(v(1), v(2))/dt; */
    sensorModel_B.xNew_n = sensorModel_B.DataStoreReadX_i + rt_atan2d_snf
      (sensorModel_B.ZeroOrderHold[0], sensorModel_B.ZeroOrderHold[1]);
    sensorModel_B.P_l = latitude * sensorModel_B.P_l * latitude +
      sensorModel_P.Q_Value;

    /* DataStoreWrite: '<S22>/Data Store WriteP' */
    sensorModel_DW.P = sensorModel_B.P_l;

    /* DataStoreWrite: '<S22>/Data Store WriteX' */
    sensorModel_DW.x = sensorModel_B.xNew_n;

    /* End of Outputs for SubSystem: '<S5>/Predict' */

    /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
    if (rtmIsMajorTimeStep(sensorModel_M) &&
        sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
      sensorModel_B.ZeroOrderHold1[0] = sensorModel_B.ZeroOrderHold[0];
      sensorModel_B.ZeroOrderHold1[1] = sensorModel_B.ZeroOrderHold[1];
      sensorModel_B.ZeroOrderHold1[2] = sensorModel_B.ZeroOrderHold[2];
    }

    /* End of ZeroOrderHold: '<Root>/Zero-Order Hold1' */
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* Outputs for Atomic SubSystem: '<S6>/Predict' */
    /* DataStoreRead: '<S29>/Data Store ReadX' */
    sensorModel_B.DataStoreReadX = sensorModel_DW.x_f;

    /* DataStoreRead: '<S29>/Data Store ReadP' */
    sensorModel_B.P = sensorModel_DW.P_k;

    /* MATLAB Function: '<S29>/Predict' incorporates:
     *  Constant: '<S6>/Q'
     */
    /* :  if pS.IsSimulinkFcn */
    /* :  else */
    /* :  StateTransitionFcnH = str2func(pS.FcnName); */
    /* :  if pS.HasJacobian */
    /* :  StateTransitionJacobianFcnH = []; */
    /* :  switch pS.NumberOfExtraArgumentInports */
    /* :  case 1 */
    /* :  extraArgs = {uState}; */
    /* :  xNew = zeros(size(x),'like',x); */
    /* :  if pS.HasAdditiveNoise */
    /* :  [xNew,P] = matlabshared.tracking.internal.EKFPredictorAdditive.predict(... */
    /* :          Q,x,P,StateTransitionFcnH,StateTransitionJacobianFcnH,extraArgs{:}); */
    /* 'altitudeStateTransitionFunc:7' dt = 1; */
    /* 'altitudeStateTransitionFunc:8' xhat = x + v(3)/dt; */
    latitude = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                    (sensorModel_B.DataStoreReadX));

    /* 'altitudeStateTransitionFunc:7' dt = 1; */
    /* 'altitudeStateTransitionFunc:8' xhat = x + v(3)/dt; */
    latitude = (((sensorModel_B.DataStoreReadX + latitude) +
                 sensorModel_B.ZeroOrderHold1[2]) -
                (sensorModel_B.DataStoreReadX + sensorModel_B.ZeroOrderHold1[2]))
      / latitude;

    /* 'altitudeStateTransitionFunc:7' dt = 1; */
    /* 'altitudeStateTransitionFunc:8' xhat = x + v(3)/dt; */
    sensorModel_B.xNew = sensorModel_B.DataStoreReadX +
      sensorModel_B.ZeroOrderHold1[2];
    sensorModel_B.P = latitude * sensorModel_B.P * latitude +
      sensorModel_P.Q_Value_c;

    /* DataStoreWrite: '<S29>/Data Store WriteP' */
    sensorModel_DW.P_k = sensorModel_B.P;

    /* DataStoreWrite: '<S29>/Data Store WriteX' */
    sensorModel_DW.x_f = sensorModel_B.xNew;

    /* End of Outputs for SubSystem: '<S6>/Predict' */

    /* Product: '<S50>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S7>/A'
     */
    latitude = sensorModel_P.A_Value;
    longitude = sensorModel_B.MemoryX;
    sensorModel_B.Akxhatkk1 = latitude * longitude;

    /* Product: '<S50>/B[k]*u[k]' incorporates:
     *  Constant: '<S7>/B'
     *  Constant: '<S7>/u'
     */
    latitude = sensorModel_P.B_Value;
    longitude = sensorModel_P.u_Value;
    sensorModel_B.Bkuk = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S50>/MeasurementUpdate' */
    /* Constant: '<S7>/Enable' incorporates:
     *  Constant: '<S33>/KalmanGainL'
     *  Constant: '<S7>/C'
     *  Constant: '<S7>/D'
     *  Constant: '<S7>/u'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value,
      sensorModel_P.KalmanGainL_Value, 0.0, sensorModel_P.C_Value,
      sensorModel_B.MemoryX, sensorModel_P.D_Value, sensorModel_P.u_Value,
      &sensorModel_B.MeasurementUpdate, &sensorModel_DW.MeasurementUpdate,
      &sensorModel_P.MeasurementUpdate);

    /* End of Outputs for SubSystem: '<S50>/MeasurementUpdate' */

    /* Sum: '<S50>/Add' */
    sensorModel_B.Add_l = (sensorModel_B.Bkuk + sensorModel_B.Akxhatkk1) +
      sensorModel_B.MeasurementUpdate.Product3;

    /* Product: '<S94>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S8>/A'
     */
    latitude = sensorModel_P.A_Value_h;
    longitude = sensorModel_B.MemoryX_p;
    sensorModel_B.Akxhatkk1_e = latitude * longitude;

    /* Product: '<S94>/B[k]*u[k]' incorporates:
     *  Constant: '<S8>/B'
     *  Constant: '<S8>/u'
     */
    latitude = sensorModel_P.B_Value_i;
    longitude = sensorModel_P.u_Value_g;
    sensorModel_B.Bkuk_i = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S94>/MeasurementUpdate' */
    /* Constant: '<S8>/Enable' incorporates:
     *  Constant: '<S77>/KalmanGainL'
     *  Constant: '<S8>/C'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/u'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_c,
      sensorModel_P.KalmanGainL_Value_d, 0.0, sensorModel_P.C_Value_k,
      sensorModel_B.MemoryX_p, sensorModel_P.D_Value_a, sensorModel_P.u_Value_g,
      &sensorModel_B.MeasurementUpdate_e, &sensorModel_DW.MeasurementUpdate_e,
      &sensorModel_P.MeasurementUpdate_e);

    /* End of Outputs for SubSystem: '<S94>/MeasurementUpdate' */

    /* Sum: '<S94>/Add' */
    sensorModel_B.Add_o = (sensorModel_B.Bkuk_i + sensorModel_B.Akxhatkk1_e) +
      sensorModel_B.MeasurementUpdate_e.Product3;
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Product: '<S270>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S12>/A'
     */
    latitude = sensorModel_P.A_Value_i;
    longitude = sensorModel_B.MemoryX_n;
    sensorModel_B.Akxhatkk1_n = latitude * longitude;

    /* Product: '<S270>/B[k]*u[k]' incorporates:
     *  Constant: '<S12>/B'
     *  Constant: '<S12>/u'
     */
    latitude = sensorModel_P.B_Value_e;
    longitude = sensorModel_P.u_Value_p;
    sensorModel_B.Bkuk_l = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S270>/MeasurementUpdate' */
    /* Constant: '<S12>/Enable' incorporates:
     *  Constant: '<S12>/C'
     *  Constant: '<S12>/D'
     *  Constant: '<S12>/u'
     *  Constant: '<S253>/KalmanGainL'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_o,
      sensorModel_P.KalmanGainL_Value_p, 0.0, sensorModel_P.C_Value_p,
      sensorModel_B.MemoryX_n, sensorModel_P.D_Value_m, sensorModel_P.u_Value_p,
      &sensorModel_B.MeasurementUpdate_kg, &sensorModel_DW.MeasurementUpdate_kg,
      &sensorModel_P.MeasurementUpdate_kg);

    /* End of Outputs for SubSystem: '<S270>/MeasurementUpdate' */

    /* Sum: '<S270>/Add' */
    sensorModel_B.Add_f = (sensorModel_B.Bkuk_l + sensorModel_B.Akxhatkk1_n) +
      sensorModel_B.MeasurementUpdate_kg.Product3;

    /* Product: '<S314>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S13>/A'
     */
    latitude = sensorModel_P.A_Value_j;
    longitude = sensorModel_B.MemoryX_c;
    sensorModel_B.Akxhatkk1_f = latitude * longitude;

    /* Product: '<S314>/B[k]*u[k]' incorporates:
     *  Constant: '<S13>/B'
     *  Constant: '<S13>/u'
     */
    latitude = sensorModel_P.B_Value_f;
    longitude = sensorModel_P.u_Value_o;
    sensorModel_B.Bkuk_a = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S314>/MeasurementUpdate' */
    /* Constant: '<S13>/Enable' incorporates:
     *  Constant: '<S13>/C'
     *  Constant: '<S13>/D'
     *  Constant: '<S13>/u'
     *  Constant: '<S297>/KalmanGainL'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_f,
      sensorModel_P.KalmanGainL_Value_h, 0.0, sensorModel_P.C_Value_i,
      sensorModel_B.MemoryX_c, sensorModel_P.D_Value_am, sensorModel_P.u_Value_o,
      &sensorModel_B.MeasurementUpdate_el, &sensorModel_DW.MeasurementUpdate_el,
      &sensorModel_P.MeasurementUpdate_el);

    /* End of Outputs for SubSystem: '<S314>/MeasurementUpdate' */

    /* Sum: '<S314>/Add' */
    sensorModel_B.Add_oz = (sensorModel_B.Bkuk_a + sensorModel_B.Akxhatkk1_f) +
      sensorModel_B.MeasurementUpdate_el.Product3;

    /* Product: '<S358>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/A'
     */
    latitude = sensorModel_P.A_Value_hv;
    longitude = sensorModel_B.MemoryX_l;
    sensorModel_B.Akxhatkk1_eo = latitude * longitude;

    /* Product: '<S358>/B[k]*u[k]' incorporates:
     *  Constant: '<S14>/B'
     *  Constant: '<S14>/u'
     */
    latitude = sensorModel_P.B_Value_b;
    longitude = sensorModel_P.u_Value_b;
    sensorModel_B.Bkuk_o = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S358>/MeasurementUpdate' */
    /* Constant: '<S14>/Enable' incorporates:
     *  Constant: '<S14>/C'
     *  Constant: '<S14>/D'
     *  Constant: '<S14>/u'
     *  Constant: '<S341>/KalmanGainL'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_l,
      sensorModel_P.KalmanGainL_Value_a, 0.0, sensorModel_P.C_Value_m,
      sensorModel_B.MemoryX_l, sensorModel_P.D_Value_h, sensorModel_P.u_Value_b,
      &sensorModel_B.MeasurementUpdate_p, &sensorModel_DW.MeasurementUpdate_p,
      &sensorModel_P.MeasurementUpdate_p);

    /* End of Outputs for SubSystem: '<S358>/MeasurementUpdate' */

    /* Sum: '<S358>/Add' */
    sensorModel_B.Add_d = (sensorModel_B.Bkuk_o + sensorModel_B.Akxhatkk1_eo) +
      sensorModel_B.MeasurementUpdate_p.Product3;
  }

  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[3] == 0) {
    /* Delay: '<S9>/MemoryX' incorporates:
     *  Constant: '<S9>/X0'
     */
    if (sensorModel_DW.icLoad_ow != 0) {
      sensorModel_DW.MemoryX_DSTATE_c = sensorModel_P.X0_Value_ld;
    }

    sensorModel_B.MemoryX_l4 = sensorModel_DW.MemoryX_DSTATE_c;

    /* End of Delay: '<S9>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S143>/Enabled Subsystem' */
    /* Constant: '<S9>/Enable' incorporates:
     *  Constant: '<S121>/KalmanGainM'
     *  Constant: '<S9>/C'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_c5,
      sensorModel_P.KalmanGainM_Value_f, sensorModel_P.C_Value_j, 0.0,
      sensorModel_B.MemoryX_l4, &sensorModel_B.EnabledSubsystem_f,
      &sensorModel_DW.EnabledSubsystem_f, &sensorModel_P.EnabledSubsystem_f);

    /* End of Outputs for SubSystem: '<S143>/Enabled Subsystem' */

    /* Sum: '<S143>/Add' */
    sensorModel_B.Add_n = sensorModel_B.EnabledSubsystem_f.Product2 +
      sensorModel_B.MemoryX_l4;

    /* Delay: '<S10>/MemoryX' incorporates:
     *  Constant: '<S10>/X0'
     */
    if (sensorModel_DW.icLoad_p != 0) {
      sensorModel_DW.MemoryX_DSTATE_pl = sensorModel_P.X0_Value_n;
    }

    sensorModel_B.MemoryX_m = sensorModel_DW.MemoryX_DSTATE_pl;

    /* End of Delay: '<S10>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S187>/Enabled Subsystem' */
    /* Constant: '<S10>/Enable' incorporates:
     *  Constant: '<S10>/C'
     *  Constant: '<S165>/KalmanGainM'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_j,
      sensorModel_P.KalmanGainM_Value_i, sensorModel_P.C_Value_l, 0.0,
      sensorModel_B.MemoryX_m, &sensorModel_B.EnabledSubsystem_k,
      &sensorModel_DW.EnabledSubsystem_k, &sensorModel_P.EnabledSubsystem_k);

    /* End of Outputs for SubSystem: '<S187>/Enabled Subsystem' */

    /* Sum: '<S187>/Add' */
    sensorModel_B.Add_d0 = sensorModel_B.EnabledSubsystem_k.Product2 +
      sensorModel_B.MemoryX_m;

    /* Delay: '<S11>/MemoryX' incorporates:
     *  Constant: '<S11>/X0'
     */
    if (sensorModel_DW.icLoad_n != 0) {
      sensorModel_DW.MemoryX_DSTATE_bc = sensorModel_P.X0_Value_g;
    }

    sensorModel_B.MemoryX_mi = sensorModel_DW.MemoryX_DSTATE_bc;

    /* End of Delay: '<S11>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S231>/Enabled Subsystem' */
    /* Constant: '<S11>/Enable' incorporates:
     *  Constant: '<S11>/C'
     *  Constant: '<S209>/KalmanGainM'
     */
    sensorModel_EnabledSubsystem(sensorModel_M, sensorModel_P.Enable_Value_e,
      sensorModel_P.KalmanGainM_Value_k, sensorModel_P.C_Value_b, 0.0,
      sensorModel_B.MemoryX_mi, &sensorModel_B.EnabledSubsystem_n,
      &sensorModel_DW.EnabledSubsystem_n, &sensorModel_P.EnabledSubsystem_n);

    /* End of Outputs for SubSystem: '<S231>/Enabled Subsystem' */

    /* Sum: '<S231>/Add' */
    sensorModel_B.Add_m = sensorModel_B.EnabledSubsystem_n.Product2 +
      sensorModel_B.MemoryX_mi;

    /* Outport: '<Root>/omega_dot' */
    sensorModel_Y.omega_dot[0] = sensorModel_B.Add_n;
    sensorModel_Y.omega_dot[1] = sensorModel_B.Add_d0;
    sensorModel_Y.omega_dot[2] = sensorModel_B.Add_m;
  }

  /* Integrator: '<Root>/Integrator' */
  sensorModel_B.Integrator = sensorModel_X.Integrator_CSTATE;

  /* Integrator: '<Root>/Integrator1' */
  sensorModel_B.Integrator1 = sensorModel_X.Integrator1_CSTATE;

  /* Integrator: '<Root>/Integrator2' */
  sensorModel_B.Integrator2 = sensorModel_X.Integrator2_CSTATE;

  /* Outport: '<Root>/omega' */
  sensorModel_Y.omega[0] = sensorModel_B.Integrator;
  sensorModel_Y.omega[1] = sensorModel_B.Integrator1;
  sensorModel_Y.omega[2] = sensorModel_B.Integrator2;

  /* Integrator: '<Root>/Integrator3' */
  sensorModel_B.Integrator3 = sensorModel_X.Integrator3_CSTATE;

  /* Integrator: '<Root>/Integrator4' */
  sensorModel_B.Integrator4 = sensorModel_X.Integrator4_CSTATE;

  /* Integrator: '<Root>/Integrator5' */
  sensorModel_B.Integrator5 = sensorModel_X.Integrator5_CSTATE;

  /* Outport: '<Root>/phi_theta_psi' */
  sensorModel_Y.phi_theta_psi[0] = sensorModel_B.Integrator3;
  sensorModel_Y.phi_theta_psi[1] = sensorModel_B.Integrator4;
  sensorModel_Y.phi_theta_psi[2] = sensorModel_B.Integrator5;
  if (rtmIsMajorTimeStep(sensorModel_M) &&
      sensorModel_M->Timing.TaskCounters.TID[3] == 0) {
    /* Product: '<S138>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S9>/A'
     */
    latitude = sensorModel_P.A_Value_k;
    longitude = sensorModel_B.MemoryX_l4;
    sensorModel_B.Akxhatkk1_fm = latitude * longitude;

    /* Product: '<S138>/B[k]*u[k]' incorporates:
     *  Constant: '<S9>/B'
     *  Constant: '<S9>/u'
     */
    latitude = sensorModel_P.B_Value_k;
    longitude = sensorModel_P.u_Value_gd;
    sensorModel_B.Bkuk_f = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S138>/MeasurementUpdate' */
    /* Constant: '<S9>/Enable' incorporates:
     *  Constant: '<S121>/KalmanGainL'
     *  Constant: '<S9>/C'
     *  Constant: '<S9>/D'
     *  Constant: '<S9>/u'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_c5,
      sensorModel_P.KalmanGainL_Value_hr, 0.0, sensorModel_P.C_Value_j,
      sensorModel_B.MemoryX_l4, sensorModel_P.D_Value_j,
      sensorModel_P.u_Value_gd, &sensorModel_B.MeasurementUpdate_ec,
      &sensorModel_DW.MeasurementUpdate_ec, &sensorModel_P.MeasurementUpdate_ec);

    /* End of Outputs for SubSystem: '<S138>/MeasurementUpdate' */

    /* Sum: '<S138>/Add' */
    sensorModel_B.Add_b = (sensorModel_B.Bkuk_f + sensorModel_B.Akxhatkk1_fm) +
      sensorModel_B.MeasurementUpdate_ec.Product3;

    /* Product: '<S182>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S10>/A'
     */
    latitude = sensorModel_P.A_Value_ih;
    longitude = sensorModel_B.MemoryX_m;
    sensorModel_B.Akxhatkk1_np = latitude * longitude;

    /* Product: '<S182>/B[k]*u[k]' incorporates:
     *  Constant: '<S10>/B'
     *  Constant: '<S10>/u'
     */
    latitude = sensorModel_P.B_Value_h;
    longitude = sensorModel_P.u_Value_ou;
    sensorModel_B.Bkuk_g = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S182>/MeasurementUpdate' */
    /* Constant: '<S10>/Enable' incorporates:
     *  Constant: '<S10>/C'
     *  Constant: '<S10>/D'
     *  Constant: '<S10>/u'
     *  Constant: '<S165>/KalmanGainL'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_j,
      sensorModel_P.KalmanGainL_Value_i, 0.0, sensorModel_P.C_Value_l,
      sensorModel_B.MemoryX_m, sensorModel_P.D_Value_g, sensorModel_P.u_Value_ou,
      &sensorModel_B.MeasurementUpdate_k, &sensorModel_DW.MeasurementUpdate_k,
      &sensorModel_P.MeasurementUpdate_k);

    /* End of Outputs for SubSystem: '<S182>/MeasurementUpdate' */

    /* Sum: '<S182>/Add' */
    sensorModel_B.Add_g = (sensorModel_B.Bkuk_g + sensorModel_B.Akxhatkk1_np) +
      sensorModel_B.MeasurementUpdate_k.Product3;

    /* Product: '<S226>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S11>/A'
     */
    latitude = sensorModel_P.A_Value_n;
    longitude = sensorModel_B.MemoryX_mi;
    sensorModel_B.Akxhatkk1_i = latitude * longitude;

    /* Product: '<S226>/B[k]*u[k]' incorporates:
     *  Constant: '<S11>/B'
     *  Constant: '<S11>/u'
     */
    latitude = sensorModel_P.B_Value_a;
    longitude = sensorModel_P.u_Value_j;
    sensorModel_B.Bkuk_f2 = latitude * longitude;

    /* Outputs for Enabled SubSystem: '<S226>/MeasurementUpdate' */
    /* Constant: '<S11>/Enable' incorporates:
     *  Constant: '<S11>/C'
     *  Constant: '<S11>/D'
     *  Constant: '<S11>/u'
     *  Constant: '<S209>/KalmanGainL'
     */
    sensorModel_MeasurementUpdate(sensorModel_M, sensorModel_P.Enable_Value_e,
      sensorModel_P.KalmanGainL_Value_o, 0.0, sensorModel_P.C_Value_b,
      sensorModel_B.MemoryX_mi, sensorModel_P.D_Value_mn,
      sensorModel_P.u_Value_j, &sensorModel_B.MeasurementUpdate_kv,
      &sensorModel_DW.MeasurementUpdate_kv, &sensorModel_P.MeasurementUpdate_kv);

    /* End of Outputs for SubSystem: '<S226>/MeasurementUpdate' */

    /* Sum: '<S226>/Add' */
    sensorModel_B.Add_l4 = (sensorModel_B.Bkuk_f2 + sensorModel_B.Akxhatkk1_i) +
      sensorModel_B.MeasurementUpdate_kv.Product3;
  }

  if (rtmIsMajorTimeStep(sensorModel_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(sensorModel_M->rtwLogInfo, (sensorModel_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(sensorModel_M)) {
    if (rtmIsMajorTimeStep(sensorModel_M) &&
        sensorModel_M->Timing.TaskCounters.TID[4] == 0) {
      /* Update for Delay: '<S7>/MemoryX' */
      sensorModel_DW.icLoad = 0U;
      sensorModel_DW.MemoryX_DSTATE = sensorModel_B.Add_l;

      /* Update for Delay: '<S8>/MemoryX' */
      sensorModel_DW.icLoad_j = 0U;
      sensorModel_DW.MemoryX_DSTATE_n = sensorModel_B.Add_o;
    }

    if (rtmIsMajorTimeStep(sensorModel_M) &&
        sensorModel_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for Delay: '<S12>/MemoryX' */
      sensorModel_DW.icLoad_o = 0U;
      sensorModel_DW.MemoryX_DSTATE_a = sensorModel_B.Add_f;

      /* Update for Delay: '<S13>/MemoryX' */
      sensorModel_DW.icLoad_o2 = 0U;
      sensorModel_DW.MemoryX_DSTATE_b = sensorModel_B.Add_oz;

      /* Update for Delay: '<S14>/MemoryX' */
      sensorModel_DW.icLoad_e = 0U;
      sensorModel_DW.MemoryX_DSTATE_p = sensorModel_B.Add_d;
    }

    if (rtmIsMajorTimeStep(sensorModel_M) &&
        sensorModel_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update for Delay: '<S9>/MemoryX' */
      sensorModel_DW.icLoad_ow = 0U;
      sensorModel_DW.MemoryX_DSTATE_c = sensorModel_B.Add_b;

      /* Update for Delay: '<S10>/MemoryX' */
      sensorModel_DW.icLoad_p = 0U;
      sensorModel_DW.MemoryX_DSTATE_pl = sensorModel_B.Add_g;

      /* Update for Delay: '<S11>/MemoryX' */
      sensorModel_DW.icLoad_n = 0U;
      sensorModel_DW.MemoryX_DSTATE_bc = sensorModel_B.Add_l4;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(sensorModel_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(sensorModel_M)!=-1) &&
          !((rtmGetTFinal(sensorModel_M)-(((sensorModel_M->Timing.clockTick1+
               sensorModel_M->Timing.clockTickH1* 4294967296.0)) *
             0.0005263157894736842)) > (((sensorModel_M->Timing.clockTick1+
              sensorModel_M->Timing.clockTickH1* 4294967296.0)) *
            0.0005263157894736842) * (DBL_EPSILON))) {
        rtmSetErrorStatus(sensorModel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&sensorModel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sensorModel_M->Timing.clockTick0)) {
      ++sensorModel_M->Timing.clockTickH0;
    }

    sensorModel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&sensorModel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0005263157894736842s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0005263157894736842, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      sensorModel_M->Timing.clockTick1++;
      if (!sensorModel_M->Timing.clockTick1) {
        sensorModel_M->Timing.clockTickH1++;
      }
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void sensorModel_derivatives(void)
{
  XDot_sensorModel_T *_rtXdot;
  _rtXdot = ((XDot_sensorModel_T *) sensorModel_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = sensorModel_B.Add_c;

  /* Derivatives for Integrator: '<Root>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = sensorModel_B.Add_j;

  /* Derivatives for Integrator: '<Root>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = sensorModel_B.Add_p;

  /* Derivatives for Integrator: '<Root>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = sensorModel_B.Integrator6;

  /* Derivatives for Integrator: '<Root>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = sensorModel_B.Integrator7;

  /* Derivatives for Integrator: '<Root>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = sensorModel_B.Integrator8;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = sensorModel_B.Add_n;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = sensorModel_B.Add_d0;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = sensorModel_B.Add_m;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = sensorModel_B.Integrator;

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = sensorModel_B.Integrator1;

  /* Derivatives for Integrator: '<Root>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = sensorModel_B.Integrator2;
}

/* Model initialize function */
void sensorModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sensorModel_M, 0,
                sizeof(RT_MODEL_sensorModel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sensorModel_M->solverInfo,
                          &sensorModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&sensorModel_M->solverInfo, &rtmGetTPtr(sensorModel_M));
    rtsiSetStepSizePtr(&sensorModel_M->solverInfo,
                       &sensorModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&sensorModel_M->solverInfo, &sensorModel_M->derivs);
    rtsiSetContStatesPtr(&sensorModel_M->solverInfo, (real_T **)
                         &sensorModel_M->contStates);
    rtsiSetNumContStatesPtr(&sensorModel_M->solverInfo,
      &sensorModel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sensorModel_M->solverInfo,
      &sensorModel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sensorModel_M->solverInfo,
      &sensorModel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sensorModel_M->solverInfo,
      &sensorModel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&sensorModel_M->solverInfo, (&rtmGetErrorStatus
      (sensorModel_M)));
    rtsiSetRTModelPtr(&sensorModel_M->solverInfo, sensorModel_M);
  }

  rtsiSetSimTimeStep(&sensorModel_M->solverInfo, MAJOR_TIME_STEP);
  sensorModel_M->intgData.y = sensorModel_M->odeY;
  sensorModel_M->intgData.f[0] = sensorModel_M->odeF[0];
  sensorModel_M->intgData.f[1] = sensorModel_M->odeF[1];
  sensorModel_M->intgData.f[2] = sensorModel_M->odeF[2];
  sensorModel_M->contStates = ((X_sensorModel_T *) &sensorModel_X);
  rtsiSetSolverData(&sensorModel_M->solverInfo, (void *)&sensorModel_M->intgData);
  rtsiSetSolverName(&sensorModel_M->solverInfo,"ode3");
  rtmSetTPtr(sensorModel_M, &sensorModel_M->Timing.tArray[0]);
  rtmSetTFinal(sensorModel_M, 10.0);
  sensorModel_M->Timing.stepSize0 = 0.0005263157894736842;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    sensorModel_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sensorModel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sensorModel_M->rtwLogInfo, (NULL));
    rtliSetLogT(sensorModel_M->rtwLogInfo, "tout");
    rtliSetLogX(sensorModel_M->rtwLogInfo, "");
    rtliSetLogXFinal(sensorModel_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(sensorModel_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(sensorModel_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(sensorModel_M->rtwLogInfo, 0);
    rtliSetLogDecimation(sensorModel_M->rtwLogInfo, 1);
    rtliSetLogY(sensorModel_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(sensorModel_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(sensorModel_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &sensorModel_B), 0,
                sizeof(B_sensorModel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&sensorModel_X, 0,
                  sizeof(X_sensorModel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&sensorModel_DW, 0,
                sizeof(DW_sensorModel_T));

  /* external outputs */
  (void) memset((void *)&sensorModel_Y, 0,
                sizeof(ExtY_sensorModel_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(sensorModel_M->rtwLogInfo, 0.0, rtmGetTFinal
    (sensorModel_M), sensorModel_M->Timing.stepSize0, (&rtmGetErrorStatus
    (sensorModel_M)));

  {
    codertarget_arduinobase_inter_T *b_obj;
    uint16_T b;
    dsp_MedianFilter_sensorModel_T *b_obj_0;
    dsp_MedianFilter_sensorModel_T *obj;
    dsp_private_MedianFilterCG_se_T *b_obj_1;
    GPSParser_sensorModel_T *b_obj_2;

    /* Start for MATLABSystem: '<S18>/Serial_Receive1' */
    b_obj = &sensorModel_DW.obj_b;
    b_obj->isInitialized = 0;
    sensorModel_DW.objisempty_l = true;
    b_obj = &sensorModel_DW.obj_b;
    b_obj->isInitialized = 1;
    b_obj->DataTypeWidth = 1U;
    b = b_obj->DataTypeWidth;
    if (b > 2047) {
      b = MAX_uint16_T;
    } else {
      b = (uint16_T)(b << 5);
    }

    b_obj->DataSizeInBytes = b;

    /* End of Start for MATLABSystem: '<S18>/Serial_Receive1' */

    /* Start for Enabled SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */
    /* Start for MATLABSystem: '<S386>/MATLAB_System' */
    sensorModel_DW.obj_m.matlabCodegenIsDeleted = true;
    b_obj_2 = &sensorModel_DW.obj_m;
    b_obj_2->isInitialized = 0;
    b_obj_2->matlabCodegenIsDeleted = false;
    sensorModel_DW.objisempty = true;
    b_obj_2 = &sensorModel_DW.obj_m;
    b_obj_2->isSetupComplete = false;
    b_obj_2->isInitialized = 1;
    initialSetup(80.0);
    b_obj_2->isSetupComplete = true;

    /* End of Start for SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */

    /* Start for MATLABSystem: '<Root>/Median Filter' */
    sensorModel_DW.obj.matlabCodegenIsDeleted = true;
    b_obj_0 = &sensorModel_DW.obj;
    b_obj_0->isInitialized = 0;
    b_obj_0->NumChannels = -1;
    b_obj_0->matlabCodegenIsDeleted = false;
    sensorModel_DW.objisempty_f = true;
    b_obj_0 = &sensorModel_DW.obj;
    b_obj_0->isSetupComplete = false;
    b_obj_0->isInitialized = 1;
    obj = b_obj_0;
    obj->NumChannels = 1;
    b_obj_1 = &obj->pMID;
    b_obj_1->isInitialized = 0;
    b_obj_0->isSetupComplete = true;

    /* Start for DataStoreMemory: '<S5>/DataStoreMemory - P' */
    sensorModel_DW.P = sensorModel_P.DataStoreMemoryP_InitialValue;

    /* Start for DataStoreMemory: '<S5>/DataStoreMemory - x' */
    sensorModel_DW.x = sensorModel_P.DataStoreMemoryx_InitialValue;

    /* Start for DataStoreMemory: '<S6>/DataStoreMemory - P' */
    sensorModel_DW.P_k = sensorModel_P.DataStoreMemoryP_InitialValue_e;

    /* Start for DataStoreMemory: '<S6>/DataStoreMemory - x' */
    sensorModel_DW.x_f = sensorModel_P.DataStoreMemoryx_InitialValue_j;
  }

  {
    dsp_MedianFilter_sensorModel_T *obj;
    dsp_private_MedianFilterCG_se_T *obj_0;

    /* InitializeConditions for Delay: '<S7>/MemoryX' */
    sensorModel_DW.icLoad = 1U;

    /* InitializeConditions for Delay: '<S8>/MemoryX' */
    sensorModel_DW.icLoad_j = 1U;

    /* InitializeConditions for Delay: '<S12>/MemoryX' */
    sensorModel_DW.icLoad_o = 1U;

    /* InitializeConditions for Delay: '<S13>/MemoryX' */
    sensorModel_DW.icLoad_o2 = 1U;

    /* InitializeConditions for Delay: '<S14>/MemoryX' */
    sensorModel_DW.icLoad_e = 1U;

    /* InitializeConditions for Integrator: '<Root>/Integrator6' */
    sensorModel_X.Integrator6_CSTATE = sensorModel_P.Integrator6_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator7' */
    sensorModel_X.Integrator7_CSTATE = sensorModel_P.Integrator7_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator8' */
    sensorModel_X.Integrator8_CSTATE = sensorModel_P.Integrator8_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator9' */
    sensorModel_X.Integrator9_CSTATE = sensorModel_P.Integrator9_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator10' */
    sensorModel_X.Integrator10_CSTATE = sensorModel_P.Integrator10_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator11' */
    sensorModel_X.Integrator11_CSTATE = sensorModel_P.Integrator11_IC;

    /* InitializeConditions for Delay: '<S9>/MemoryX' */
    sensorModel_DW.icLoad_ow = 1U;

    /* InitializeConditions for Delay: '<S10>/MemoryX' */
    sensorModel_DW.icLoad_p = 1U;

    /* InitializeConditions for Delay: '<S11>/MemoryX' */
    sensorModel_DW.icLoad_n = 1U;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    sensorModel_X.Integrator_CSTATE = sensorModel_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    sensorModel_X.Integrator1_CSTATE = sensorModel_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator2' */
    sensorModel_X.Integrator2_CSTATE = sensorModel_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator3' */
    sensorModel_X.Integrator3_CSTATE = sensorModel_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator4' */
    sensorModel_X.Integrator4_CSTATE = sensorModel_P.Integrator4_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator5' */
    sensorModel_X.Integrator5_CSTATE = sensorModel_P.Integrator5_IC;

    /* SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem,
      &sensorModel_P.EnabledSubsystem);

    /* End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S99>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_a,
      &sensorModel_P.EnabledSubsystem_a);

    /* End of SystemInitialize for SubSystem: '<S99>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S275>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_p,
      &sensorModel_P.EnabledSubsystem_p);

    /* End of SystemInitialize for SubSystem: '<S275>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S319>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_e,
      &sensorModel_P.EnabledSubsystem_e);

    /* End of SystemInitialize for SubSystem: '<S319>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S363>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_ej,
      &sensorModel_P.EnabledSubsystem_ej);

    /* End of SystemInitialize for SubSystem: '<S363>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */
    /* SystemInitialize for Outport: '<S386>/lat' */
    sensorModel_B.VectorConcatenate[0] = sensorModel_P.lat_Y0;

    /* SystemInitialize for Outport: '<S386>/long' */
    sensorModel_B.VectorConcatenate[1] = sensorModel_P.long_Y0;

    /* SystemInitialize for Outport: '<S386>/alt_m' */
    sensorModel_B.VectorConcatenate[2] = sensorModel_P.alt_m_Y0;

    /* SystemInitialize for Outport: '<S386>/speed_kt' */
    sensorModel_B.TmpMLSysMemLayoutBufferAtMATLAB = sensorModel_P.speed_kt_Y0;

    /* SystemInitialize for Outport: '<S386>/trkAngle_deg_true' */
    sensorModel_B.TmpMLSysMemLayoutBufferAtMATL_e =
      sensorModel_P.trkAngle_deg_true_Y0;

    /* SystemInitialize for Outport: '<S386>/num_sat' */
    sensorModel_B.MATLAB_System_o4 = sensorModel_P.num_sat_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */

    /* SystemInitialize for Enabled SubSystem: '<S5>/Correct1' */
    /* SystemInitialize for Outport: '<S19>/yBlockOrdering' */
    sensorModel_B.blockOrdering_g = sensorModel_P.yBlockOrdering_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/Correct1' */

    /* SystemInitialize for Enabled SubSystem: '<S5>/Correct2' */
    /* SystemInitialize for Outport: '<S20>/yBlockOrdering' */
    sensorModel_B.blockOrdering_a = sensorModel_P.yBlockOrdering_Y0_o;

    /* End of SystemInitialize for SubSystem: '<S5>/Correct2' */

    /* InitializeConditions for MATLABSystem: '<Root>/Median Filter' */
    obj = &sensorModel_DW.obj;
    obj_0 = &obj->pMID;
    if (obj_0->isInitialized == 1) {
      sensor_MedianFilterCG_resetImpl(obj_0);
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Median Filter' */

    /* SystemInitialize for Enabled SubSystem: '<S6>/Correct1' */
    /* SystemInitialize for Outport: '<S26>/yBlockOrdering' */
    sensorModel_B.blockOrdering_o = sensorModel_P.yBlockOrdering_Y0_h;

    /* End of SystemInitialize for SubSystem: '<S6>/Correct1' */

    /* SystemInitialize for Enabled SubSystem: '<S6>/Correct2' */
    /* SystemInitialize for Outport: '<S27>/yBlockOrdering' */
    sensorModel_B.blockOrdering = sensorModel_P.yBlockOrdering_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S6>/Correct2' */

    /* SystemInitialize for Enabled SubSystem: '<S50>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate,
      &sensorModel_P.MeasurementUpdate);

    /* End of SystemInitialize for SubSystem: '<S50>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S94>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_e,
      &sensorModel_P.MeasurementUpdate_e);

    /* End of SystemInitialize for SubSystem: '<S94>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S270>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_kg,
      &sensorModel_P.MeasurementUpdate_kg);

    /* End of SystemInitialize for SubSystem: '<S270>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S314>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_el,
      &sensorModel_P.MeasurementUpdate_el);

    /* End of SystemInitialize for SubSystem: '<S314>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S358>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_p,
      &sensorModel_P.MeasurementUpdate_p);

    /* End of SystemInitialize for SubSystem: '<S358>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S143>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_f,
      &sensorModel_P.EnabledSubsystem_f);

    /* End of SystemInitialize for SubSystem: '<S143>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S187>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_k,
      &sensorModel_P.EnabledSubsystem_k);

    /* End of SystemInitialize for SubSystem: '<S187>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S231>/Enabled Subsystem' */
    sensorMod_EnabledSubsystem_Init(&sensorModel_B.EnabledSubsystem_n,
      &sensorModel_P.EnabledSubsystem_n);

    /* End of SystemInitialize for SubSystem: '<S231>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S138>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_ec,
      &sensorModel_P.MeasurementUpdate_ec);

    /* End of SystemInitialize for SubSystem: '<S138>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S182>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_k,
      &sensorModel_P.MeasurementUpdate_k);

    /* End of SystemInitialize for SubSystem: '<S182>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S226>/MeasurementUpdate' */
    sensorMo_MeasurementUpdate_Init(&sensorModel_B.MeasurementUpdate_kv,
      &sensorModel_P.MeasurementUpdate_kv);

    /* End of SystemInitialize for SubSystem: '<S226>/MeasurementUpdate' */
  }
}

/* Model terminate function */
void sensorModel_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */
  /* Terminate for MATLABSystem: '<S386>/MATLAB_System' */
  matlabCodegenHandle_matlabCod_m(&sensorModel_DW.obj_m);

  /* End of Terminate for SubSystem: '<S18>/$GPGGA_$GPRMC_Parser1' */

  /* Terminate for MATLABSystem: '<Root>/Median Filter' */
  matlabCodegenHandle_matlabCodeg(&sensorModel_DW.obj);
}
