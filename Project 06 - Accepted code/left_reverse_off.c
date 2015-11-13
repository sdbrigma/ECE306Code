//******************************************************************************
//
//  Description: This file turns off the left reverse port
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

void Left_Reverse_Off(void){
//******************************************************************************
//
//  Description: This file turns off the left reverse port
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
  
  P3OUT &= ~L_REVERSE;
  
}
