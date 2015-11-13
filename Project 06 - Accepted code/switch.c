//******************************************************************************
//
//  Description: This file contains the Switch Routine
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Switches_Process(void){
//******************************************************************************
//
//  Description: This file contains the Switch Routine
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed:
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 
  
if (!(P4IN & SW1)){
    Five_msec_Delay(LIL_SW_DELAY);                      // 'debounce' delay
    if (switch_select == SW_SEL_0) {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "|> P.Six";
      posL2 = LINE_POS_L0;
      display_3 = "| HW7";
      posL3 = LINE_POS_L0;
      display_4 =  "| Detect";
      posL4 = LINE_POS_L0; 
      Display_Process();      
      switch_select++;  // Set to 1
      }
    else if (switch_select == SW_SEL_1) {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "| P.Six";
      posL2 = LINE_POS_L0;
      display_3 = "|> HW7";
      posL3 = LINE_POS_L0;
      display_4 =  "| Detect";
      posL4 = LINE_POS_L0;
      Display_Process();      
      switch_select++;  // Set to 2
      }
    else if (switch_select == SW_SEL_2) {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "| HW7";
      posL2 = LINE_POS_L0;
      display_3 = "|> Detect";
      posL3 = LINE_POS_L0;
      display_4 =  "| Calibr8";
      posL4 = LINE_POS_L0;
      Display_Process();      
      switch_select++;  // Set to 3
      }
    else if (switch_select == SW_SEL_3) {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "| Detect";
      posL2 = LINE_POS_L0;
      display_3 = "|> Calibr8";
      posL3 = LINE_POS_L0;
      display_4 =  "| P.Five";
      posL4 = LINE_POS_L0;
      Display_Process();      
      switch_select++;  // Set to 4
      }
    else if (switch_select == SW_SEL_4) {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "| Calibr8";
      posL2 = LINE_POS_L0;
      display_3 = "|> P.Five";
      posL3 = LINE_POS_L0;
      display_4 =  "| P.Four";
      posL4 = LINE_POS_L0; 
      Display_Process();      
      switch_select++;  // Set to 5
      }
    else if (switch_select == SW_SEL_5) {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "| P.Five";
      posL2 = LINE_POS_L0;
      display_3 = "|> P. Four";
      posL3 = LINE_POS_L0;
      display_4 =  "| P.Six";
      posL4 = LINE_POS_L0; 
      Display_Process();      
      switch_select++;  // Set to 6
      }
    else {
      display_1 = "Function:";
      posL1 = LINE_POS_L0;
      display_2 = "| P.Four";
      posL2 = LINE_POS_L0;
      display_3 = "|> P.Six";
      posL3 = LINE_POS_L0;
      display_4 =  "| HW7";
      posL4 = LINE_POS_L0; 
      Display_Process();
      switch_select = SW_SEL_1; // Set to 1
      }
   
  }
  if (!(P4IN & SW2)) {
    Five_msec_Delay(LIL_SW_DELAY);                      // 'debounce' delay
  
    
    if (switch_select == SW_SEL_1) {
      Project_6();     
      }
    else if (switch_select == SW_SEL_2) {
      Homework_7();     
      }
    else if (switch_select == SW_SEL_3) {
      display_1 = "Detecting:";
      posL1 = LINE_POS_L0;
      display_2 = " L: 0xXXX ";
      posL2 = LINE_POS_L0;
      display_3 = " R: 0xXXX ";
      posL3 = LINE_POS_L0;
      display_4 =  "          ";
      posL4 = LINE_POS_L0; 
      Display_Process();
      Detect();
    }
    else if (switch_select == SW_SEL_4) {
      Calibrate();     
      }
    else if (switch_select == SW_SEL_5) {
      P_Five_Drive();    
      }
    else if (switch_select == SW_SEL_6) {
      P_Four_Drive();    
      }
    else {
      display_1 = "No Valid";
      posL1 = LINE_POS_L1;
      display_2 = "Function";
      posL2 = LINE_POS_L1;
      display_3 = "Detected";
      posL3 = LINE_POS_L1;
      display_4 =  "";
      posL4 = LINE_POS_L0;
      Display_Process();
      }
    
  }
  
}