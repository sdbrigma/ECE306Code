//******************************************************************************
//
//  Description: This file contains code for the switches prcesses function.
//   Controls currently being implemented by switch include the motors, LCD
//   and Port 3 configurations.
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//  File Name: switch.c
/*
    Globals Used:
      *display_1
      *display_2
      *display_3
      *display_4
      posL1
      posL2
      posL3
      posL4
*/
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;

void Switches_Process(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Switch proccess sets LCD text or change Port 3 configuratiosn when SW1 and SW2 are pressed
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Switches_Process 
*        Description: Adds functionality to switches SW1 and SW2
*        Passed : P4IN, SW1, and SW2 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: display_1 throught display_4 and posL1 throught posL4
*******************************************************************************/
  if (!(P4IN & SW1)){
    Init_Port3(USE_R_FORWARD);    
    display_1 = "NCSU";
    posL1 = SW1_posL1;
    display_2 = "WOLFPACK";
    posL2 = SW1_posL2;
    display_3 = "ECE306";
    posL3 = SW1_posL3;
    display_4 = "S Brigman";
    posL4 = SW1_posL4;
  }
  if (!(P4IN & SW2)) {
    Init_Port3(USE_SMCLK);
    display_1 = "Embedded";
    posL1 = SW2_posL1;
    display_2 = "Systems";
    posL2 = SW2_posL1;
    display_3 = "Rock!";
    posL3 = SW2_posL1;
    display_4 = "Go Pack!";
    posL4 = SW2_posL1;    
  }
//------------------------------------------------------------------------------
}