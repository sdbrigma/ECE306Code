//******************************************************************************
//
//  Description: This file turns off the right forward port
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

void Right_Forward_Off(void){
//******************************************************************************
//
//  Description: This file turns off the right forward port
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: 
//
// Local: tmp
//
// Return: VOID
//
//****************************************************************************** 
  
  P3OUT &= ~R_FORWARD;
  
}
