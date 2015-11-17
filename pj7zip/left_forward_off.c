//******************************************************************************
//
//  Description: This file turns off the left forward port
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

void Left_Forward_Off(void){
//******************************************************************************
//
//  Description: This file turns off the left forward port
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
  
  P3OUT &= ~L_FORWARD;
  
}
