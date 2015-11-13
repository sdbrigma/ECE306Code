//******************************************************************************
//
//  Description: This file turns on the left forward port
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

void Left_Forward_On(int runLeft){
//******************************************************************************
//
//  Description: This file turns on the left forward port
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runLeft
//
// Local: tmp
//
// Return: VOID
//
//****************************************************************************** 
    int tmp = runLeft;
    Time_Sequence = INITIAL;
    P3OUT &= ~L_REVERSE;
    
    while(Time_Sequence < tmp) {
      P3OUT |= L_FORWARD;
    }
  
}