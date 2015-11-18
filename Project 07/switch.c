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
   Five_msec_Delay(small_delay);                   
   
   if (sw_select == LINE_POS_L1) {
    Init_IOT();
   }
   else if (sw_select == LINE_POS_L2) {
    IOT_Commands();
   }
   else if (sw_select == LINE_POS_L3) {
    bufferDisplay();
   }
   else if (sw_select == LINE_POS_L4) {
    IOTDetect();
   }
   else if (sw_select == LINE_POS_L5) {
    calibrationDisplay();
   }
   else {
     sw_select = LINE_POS_L1;
   }
}
  if (!(P4IN & SW2)) {
    Five_msec_Delay(small_delay);               

  }
//------------------------------------------------------------------------------
}