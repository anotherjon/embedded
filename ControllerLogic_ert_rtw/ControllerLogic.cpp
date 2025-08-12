//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ControllerLogic.cpp
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
#include "ControllerLogic.h"

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

// Model step function
void ControllerLogic::step()
{
  // Outport: '<Root>/Out1' incorporates:
  //   Constant: '<Root>/Parameter'
  //   Inport: '<Root>/In1'
  //   Inport: '<Root>/In2'
  //   Inport: '<Root>/In3'
  //   Lookup_n-D: '<Root>/1-D Lookup Table'
  //   Product: '<Root>/Product'
  //   Sum: '<Root>/Add'

  rtY.Out1 = ((rtU.In1 + rtU.In2) + 1.0) * look1_binlx(rtU.In3,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 10U);
}

// Model initialize function
void ControllerLogic::initialize()
{
  // (no initialization code required)
}

const char_T* ControllerLogic::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void ControllerLogic::RT_MODEL::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
ControllerLogic::ControllerLogic() :
  rtU(),
  rtY(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
ControllerLogic::~ControllerLogic() = default;

// Real-Time Model get method
ControllerLogic::RT_MODEL * ControllerLogic::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
