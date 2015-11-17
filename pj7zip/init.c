//******************************************************************************
//
//  Description: This file contains the INIT Routine that sets the displays
//  initial conditions for operations
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

void Init_Conditions(void){
//******************************************************************************
//
//  Description: This file contains the INIT Routine that sets the displays
//  Initial conditions for operations
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: display_1, display_2, display_3, display_4, &display_line_1,
// &display_line_2, &display_line_3, &display_line_4
//
// Passed: 
//
// Local: 
//
// Return: VOID
//
//******************************************************************************  
  
// Interrupts are disabled by default; thus, enable them
  enable_interrupts();
  display_1 = &display_line_1[INITIAL];
  display_2 = &display_line_2[INITIAL];
  display_3 = &display_line_3[INITIAL];
  display_4 = &display_line_4[INITIAL];

//------------------------------------------------------------------------------
}