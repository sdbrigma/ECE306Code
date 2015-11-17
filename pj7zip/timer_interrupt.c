//******************************************************************************
//
//  Description: Handles interrupts from the A0 Timer
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0_ISR(void){
//******************************************************************************
//
//  Description: Handles interrupts from the A0 Timer
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: A0_time_count
//
// Passed:
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 

if (A0_time_count >= TEN_SEC_COUNT) {
  A0_time_count = INITIAL;               // Reset A0 Time Count
}

A0_time_count++;                         // Increment A0 Time Counter
TA0CCR0 += TA0CCR0_INTERVAL;             // Increment CCR0 Register

}