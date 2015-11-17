//******************************************************************************
//
//  Description: This file contains the five_msec_delay routine
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void One_msec_Delay(){
//******************************************************************************
//
//  Description: This file contains the one_msec_delay routine
//
//
//  Steffon Brigman
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
  while(A0_time_count <= (ONE_MSEC));
  A0_time_count = INITIAL;
        
//------------------------------------------------------------------------------
}