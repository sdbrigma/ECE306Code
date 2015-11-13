//******************************************************************************
//
//  Description: This file turns on the right forward port
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

void Right_Forward_On(int runRight){
//******************************************************************************
//
//  Description: This file turns on the right forward port
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runRight
//
// Local: tmp
//
// Return: VOID
//
//****************************************************************************** 
  
  int tmp = runRight;
  Time_Sequence = INITIAL;
  P3OUT &= ~R_REVERSE;
      
    while(Time_Sequence < tmp) {
      P3OUT |= R_FORWARD;
    }
  
}