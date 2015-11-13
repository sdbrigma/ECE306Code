//******************************************************************************
//
//  Description: This file contains the calibration routine module
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Calibrate(void){
//******************************************************************************
//
//  Description: This file contains the calibration routine module
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: blackLineLeft, blackLineRight
//
// Passed:
//
// Local: i
//
// Return: VOID
//
//****************************************************************************** 

int i= TEN_ITERATIONS;
while(i) {
ADC10_Process();
  i--;
}
  
blackLineLeft = ADC_Left_Detector;
blackLineRight = ADC_Right_Detector;
 
      display_1 = "Detectors";
      posL1 = LINE_POS_L0;
      display_2 = "Calibrated";
      posL2 = LINE_POS_L0;
      display_3 = "Push";
      posL3 = LINE_POS_L3;
      display_4 =  "Select";
      posL4 = LINE_POS_L2;
      Display_Process();
  
}