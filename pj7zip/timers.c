//******************************************************************************
//
//  Description: This file contains the Timer Routine
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Init_Timers(void){
//******************************************************************************
//
//  Description: This file contains the Timer Routine
//
//
//  Steffon Brigman
//  Nov 2015
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
  
  Init_Timer_A0();   // Enable Timer A0
//  Init_Timer_A1(); // 
//  Init_Timer_B0(); // 
//  Init_Timer_B1(); //  
  Init_Timer_B2();   //  Required for provided compiled code to work
//------------------------------------------------------------------------------
}