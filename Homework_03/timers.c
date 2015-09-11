//******************************************************************************
//
//  Description: This file contains code to initialize the timers.
//
//
//  Steffon Brigman
//  Seppt 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void Init_Timers(void){
//------------------------------------------------------------------------------
// Timer Configurations
//------------------------------------------------------------------------------
//  Init_Timer_A0(); //
//  Init_Timer_A1(); // 
//  Init_Timer_B0(); // 
//  Init_Timer_B1(); //  
  Init_Timer_B2();   //  Required for provided compiled code to work
//------------------------------------------------------------------------------
}