#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains delay functions using the timer interrupt
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: interrupt_timer.c
*        Passed : No variables passed 
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no variables declared
*******************************************************************************/

void Five_msec_Delay(unsigned int delay){
 /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions delays the code based on 5ms delay increments.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Five_msec_Delay
*        Passed : delay 
*        Locals: no varialbes declared
*        Returned: no values returned 
*        Globlas: ISR_COUNT
*******************************************************************************/
  int i = ZERO;
  while(ISR_COUNT<delay){
    i++;
  }
  ISR_COUNT = ZERO;
}