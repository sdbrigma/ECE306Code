//******************************************************************************
//
//  Description: This file contains code to initialize conditions for LCD.
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

// Gloabl Variables
extern char display_line_1[DISPLAY_LENGTH];
extern char display_line_2[DISPLAY_LENGTH];
extern char display_line_3[DISPLAY_LENGTH];
extern char display_line_4[DISPLAY_LENGTH];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;

void Init_Conditions(void){
//------------------------------------------------------------------------------
// Initializations Configurations
//------------------------------------------------------------------------------
// Interrupts are disabled by default, enable them. 
  enable_interrupts();
  display_1 = &display_line_1[ZERO];
  display_2 = &display_line_2[ZERO];
  display_3 = &display_line_3[ZERO];
  display_4 = &display_line_4[ZERO];

//------------------------------------------------------------------------------
}