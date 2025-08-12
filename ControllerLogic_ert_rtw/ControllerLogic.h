//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ControllerLogic.h
//
// Code generated for Simulink model 'ControllerLogic'.
//
// Model version                  : 1.1
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Tue Aug 12 20:13:30 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef ControllerLogic_h_
#define ControllerLogic_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Class declaration for model ControllerLogic
class ControllerLogic final
{
  // public data and function members
 public:
  // Constant parameters (default storage)
  struct ConstP {
    // Expression: tanh([-5:5])
    //  Referenced by: '<Root>/1-D Lookup Table'

    real_T uDLookupTable_tableData[11];

    // Expression: [-5:5]
    //  Referenced by: '<Root>/1-D Lookup Table'

    real_T uDLookupTable_bp01Data[11];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T In1;                        // '<Root>/In1'
    real_T In2;                        // '<Root>/In2'
    real_T In3;                        // '<Root>/In3'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T Out1;                       // '<Root>/Out1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

  // Copy Constructor
  ControllerLogic(ControllerLogic const&) = delete;

  // Assignment Operator
  ControllerLogic& operator= (ControllerLogic const&) & = delete;

  // Move Constructor
  ControllerLogic(ControllerLogic &&) = delete;

  // Move Assignment Operator
  ControllerLogic& operator= (ControllerLogic &&) = delete;

  // Real-Time Model get method
  ControllerLogic::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // Constructor
  ControllerLogic();

  // Destructor
  ~ControllerLogic();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const ControllerLogic::ConstP rtConstP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ControllerLogic'

#endif                                 // ControllerLogic_h_

//
// File trailer for generated code.
//
// [EOF]
//
