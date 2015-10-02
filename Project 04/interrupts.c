#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains all interrupts used within this project.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: interrupts.c
*        Passed : No variables passed 
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no variables defined
*******************************************************************************/

// TimerA0 0 Interrupt handler
#pragma vector = TIMER0_A0_VECTOR

__interrupt void Timer0_A0_ISR(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions is an interrupt used to control the motors.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Timer0_A0_ISR
*        Passed : No variables passed 
*        Locals: TA0CCR0, ISR_COUNT
*        Returned: no values returned 
*        Globlas: no variables defined
*******************************************************************************/

 PJOUT ^= LED3; // Test signal
 ISR_COUNT++;
 TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
 if(ISR_COUNT>FIVE_SECONDS){
   ISR_COUNT = ZERO;
 }
}