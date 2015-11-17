//******************************************************************************
//
//  Description: This file contains code for the switches prcesses function.
//   
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
void Switches_Process(void){
//******************************************************************************
//
//  Description: This functions sets code for switch 1 and 2 upon being pressed
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************
 if (!(P4IN & SW1)){
   Five_msec_Delay(LIL_SW_DELAY);                   
   
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
    Five_msec_Delay(LIL_SW_DELAY);               

  }
//------------------------------------------------------------------------------
}