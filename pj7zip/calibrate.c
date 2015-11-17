//******************************************************************************
//
//  Description: This file contains the calibration routine module
//
//
//  Steffon Brigman
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
//  Steffon Brigman
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

  display_1 = "  Detect  ";
  posL1 = LINE_POS_L0;
  display_2 = "LEFT:     ";
  posL2 = LINE_POS_L0;
  display_3 = "RIGHT:    ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  big = INITIAL;
  lcd_4line();
  Display_Process();
  
  // Enable Infrared Emitter
  P1OUT |= IR_LED;                    // P1OUT ->    1
  
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
      
      while(ALWAYS) {
        if (!(P4IN & SW2)) {
          Five_msec_Delay(LIL_SW_DELAY); 
          break;
        }
      }
  
}