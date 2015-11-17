//******************************************************************************
//
//  Description: This file contains the Switch Routine
//
//
//  Steffon Brigman
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
//  Steffon Brigman
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
   
   if (switch_select == SW_SEL_1) {
    NCSU_Config();
   }
   else if (switch_select == SW_SEL_2) {
    Command_IOT();
   }
   else if (switch_select == SW_SEL_3) {
    Display_Buffer();
   }
   else if (switch_select == SW_SEL_4) {
    Detect();
   }
   else if (switch_select == SW_SEL_5) {
    Calibrate();
   }
   else {
     switch_select = SW_SEL_1;
   }
}
  if (!(P4IN & SW2)) {
    Five_msec_Delay(LIL_SW_DELAY);                      // 'debounce' delay

  }
  
}