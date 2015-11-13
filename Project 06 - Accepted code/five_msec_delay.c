//******************************************************************************
//
//  Description: This file contains the five_msec_delay routine
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Five_msec_Delay(unsigned int delay_multiplyer){
//******************************************************************************
//
//  Description: This file contains the five_msec_delay routine
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: A0_time_count
//
// Passed: delay_multiplyer
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 
  
  A0_time_count = INITIAL;
  while(A0_time_count <= (FIVE_MSEC*delay_multiplyer));
  A0_time_count = INITIAL;
        
//------------------------------------------------------------------------------
}