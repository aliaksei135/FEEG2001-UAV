/*
 * sensorModel_data.c
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

/* Block parameters (default storage) */
P_sensorModel_T sensorModel_P = {
  /* Variable: magVar
   * Referenced by: '<Root>/MagVar'
   */
  -1.3,

  /* Mask Parameter: CheckStaticRange_max
   * Referenced by: '<S2>/max_val'
   */
  104325.0,

  /* Mask Parameter: CheckStaticRange1_max
   * Referenced by: '<S3>/max_val'
   */
  30.0,

  /* Mask Parameter: CheckStaticUpperBound_max
   * Referenced by: '<S4>/max_val'
   */
  5.0,

  /* Mask Parameter: CheckStaticRange_min
   * Referenced by: '<S2>/min_val'
   */
  97025.0,

  /* Mask Parameter: CheckStaticRange1_min
   * Referenced by: '<S3>/min_val'
   */
  -10.0,

  /* Mask Parameter: MinNumofSatsforgoodfix_const
   * Referenced by: '<S17>/Constant'
   */
  4U,

  /* Expression: 0
   * Referenced by: '<S386>/lat'
   */
  0.0,

  /* Computed Parameter: long_Y0
   * Referenced by: '<S386>/long'
   */
  0.0,

  /* Computed Parameter: alt_m_Y0
   * Referenced by: '<S386>/alt_m'
   */
  0.0,

  /* Computed Parameter: speed_kt_Y0
   * Referenced by: '<S386>/speed_kt'
   */
  0.0,

  /* Computed Parameter: trkAngle_deg_true_Y0
   * Referenced by: '<S386>/trkAngle_deg_true'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S33>/KalmanGainM'
   */
  0.19999999999999993,

  /* Expression: pInitialization.C
   * Referenced by: '<S7>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S7>/X0'
   */
  101325.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S77>/KalmanGainM'
   */
  0.19999999999999993,

  /* Expression: pInitialization.C
   * Referenced by: '<S8>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S8>/X0'
   */
  15.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S253>/KalmanGainM'
   */
  0.1674399363528016,

  /* Expression: pInitialization.C
   * Referenced by: '<S12>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S12>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S297>/KalmanGainM'
   */
  0.1674399363528016,

  /* Expression: pInitialization.C
   * Referenced by: '<S13>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S13>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S341>/KalmanGainM'
   */
  0.1674399363528016,

  /* Expression: pInitialization.C
   * Referenced by: '<S14>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S14>/X0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator11'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/Constant1'
   */
  0.3,

  /* Expression: 4
   * Referenced by: '<Root>/Constant'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<S5>/MeasurementFcn2Inputs'
   */
  1.0,

  /* Expression: p.R{1}
   * Referenced by: '<S5>/R1'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S5>/MeasurementFcn1Inputs'
   */
  0.0,

  /* Expression: p.R{2}
   * Referenced by: '<S6>/R2'
   */
  0.8,

  /* Expression: 1
   * Referenced by: '<S6>/MeasurementFcn2Inputs'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/MeasurementFcn1Inputs'
   */
  0.0,

  /* Expression: p.Q
   * Referenced by: '<S5>/Q'
   */
  1.0,

  /* Expression: p.InitialCovariance
   * Referenced by: '<S5>/DataStoreMemory - P'
   */
  3.0,

  /* Expression: p.InitialState
   * Referenced by: '<S5>/DataStoreMemory - x'
   */
  0.0,

  /* Expression: p.Q
   * Referenced by: '<S6>/Q'
   */
  1.0,

  /* Expression: p.InitialCovariance
   * Referenced by: '<S6>/DataStoreMemory - P'
   */
  1.0,

  /* Expression: p.InitialState
   * Referenced by: '<S6>/DataStoreMemory - x'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S7>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S7>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S33>/KalmanGainL'
   */
  0.19999999999999993,

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/u'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S8>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S8>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S77>/KalmanGainL'
   */
  0.19999999999999993,

  /* Expression: pInitialization.D
   * Referenced by: '<S8>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/u'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S12>/A'
   */
  0.95,

  /* Expression: pInitialization.B
   * Referenced by: '<S12>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S253>/KalmanGainL'
   */
  0.15906793953516152,

  /* Expression: pInitialization.D
   * Referenced by: '<S12>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/u'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S13>/A'
   */
  0.95,

  /* Expression: pInitialization.B
   * Referenced by: '<S13>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S297>/KalmanGainL'
   */
  0.15906793953516152,

  /* Expression: pInitialization.D
   * Referenced by: '<S13>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/u'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S14>/A'
   */
  0.95,

  /* Expression: pInitialization.B
   * Referenced by: '<S14>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S341>/KalmanGainL'
   */
  0.15906793953516152,

  /* Expression: pInitialization.D
   * Referenced by: '<S14>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/u'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S121>/KalmanGainM'
   */
  0.18904349198909179,

  /* Expression: pInitialization.C
   * Referenced by: '<S9>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S9>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S165>/KalmanGainM'
   */
  0.18904349198909179,

  /* Expression: pInitialization.C
   * Referenced by: '<S10>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S10>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S209>/KalmanGainM'
   */
  0.18904349198909179,

  /* Expression: pInitialization.C
   * Referenced by: '<S11>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S11>/X0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator5'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S9>/A'
   */
  0.95,

  /* Expression: pInitialization.B
   * Referenced by: '<S9>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S121>/KalmanGainL'
   */
  0.17959131738963718,

  /* Expression: pInitialization.D
   * Referenced by: '<S9>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/u'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S10>/A'
   */
  0.95,

  /* Expression: pInitialization.B
   * Referenced by: '<S10>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S165>/KalmanGainL'
   */
  0.17959131738963718,

  /* Expression: pInitialization.D
   * Referenced by: '<S10>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/u'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S11>/A'
   */
  0.95,

  /* Expression: pInitialization.B
   * Referenced by: '<S11>/B'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S209>/KalmanGainL'
   */
  0.17959131738963718,

  /* Expression: pInitialization.D
   * Referenced by: '<S11>/D'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/u'
   */
  0.0,

  /* Computed Parameter: MemoryX_DelayLength
   * Referenced by: '<S7>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_o
   * Referenced by: '<S8>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_n
   * Referenced by: '<S12>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_d
   * Referenced by: '<S13>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_dt
   * Referenced by: '<S14>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_p
   * Referenced by: '<S9>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_c
   * Referenced by: '<S10>/MemoryX'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_f
   * Referenced by: '<S11>/MemoryX'
   */
  1U,

  /* Computed Parameter: yBlockOrdering_Y0
   * Referenced by: '<S19>/yBlockOrdering'
   */
  0,

  /* Computed Parameter: yBlockOrdering_Y0_o
   * Referenced by: '<S20>/yBlockOrdering'
   */
  0,

  /* Computed Parameter: yBlockOrdering_Y0_h
   * Referenced by: '<S26>/yBlockOrdering'
   */
  0,

  /* Computed Parameter: yBlockOrdering_Y0_i
   * Referenced by: '<S27>/yBlockOrdering'
   */
  0,

  /* Expression: true()
   * Referenced by: '<S7>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S8>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S12>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S13>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S14>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S5>/BlockOrdering'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S5>/Enable1'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S5>/Enable2'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S6>/BlockOrdering'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S6>/Enable1'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S6>/Enable2'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S9>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S10>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S11>/Enable'
   */
  1,

  /* Computed Parameter: num_sat_Y0
   * Referenced by: '<S386>/num_sat'
   */
  0U,

  /* Start of '<S363>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S384>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S363>/Enabled Subsystem' */

  /* Start of '<S358>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S383>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S358>/MeasurementUpdate' */

  /* Start of '<S319>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S340>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S319>/Enabled Subsystem' */

  /* Start of '<S314>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S339>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S314>/MeasurementUpdate' */

  /* Start of '<S275>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S296>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S275>/Enabled Subsystem' */

  /* Start of '<S270>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S295>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S270>/MeasurementUpdate' */

  /* Start of '<S231>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S252>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S231>/Enabled Subsystem' */

  /* Start of '<S226>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S251>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S226>/MeasurementUpdate' */

  /* Start of '<S187>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S208>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S187>/Enabled Subsystem' */

  /* Start of '<S182>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S207>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S182>/MeasurementUpdate' */

  /* Start of '<S143>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S164>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S143>/Enabled Subsystem' */

  /* Start of '<S138>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S163>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S138>/MeasurementUpdate' */

  /* Start of '<S99>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S120>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S99>/Enabled Subsystem' */

  /* Start of '<S94>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S119>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S94>/MeasurementUpdate' */

  /* Start of '<S55>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S76>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S55>/Enabled Subsystem' */

  /* Start of '<S50>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S75>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  /* End of '<S50>/MeasurementUpdate' */
};
