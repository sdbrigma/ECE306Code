//***********************************************************************
//      Title: switch.c 
//      Description: This file contains code for handling switches 
//      Rachel Williams
//      September 2015
//      Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//***********************************************************************

#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

//***********************************************************************
//      Function name: Switches_Process
//      Description: Handles cases for SW1 and SW2  
//      Global variables: NONE
//      Local variables: NONE
//      Return: VOID
//***********************************************************************
void Switches_Process(void){
  if (!(P4IN & SW1)){ 
    Out_To_LCD(" ", POSIT_0, " ", POSIT_0, " ", POSIT_0, " ", POSIT_0);
    Display_Process();
    X_Seconds_Delay(POSIT_2);
    IOT_config();


  }
  if (!(P4IN & SW2)) {
    enabled_RX = ORIGINAL;
    Out_To_LCD(" ", POSIT_0, " ", POSIT_0, " ", POSIT_0, " ", POSIT_0);
    Display_Process();
    X_Seconds_Delay(POSIT_2);
    Listen();  
  }
}     