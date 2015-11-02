//******************************************************************************
//
//  Description: This file contains code to initialize the timers.
//
//
//  Steffon Brigman
//  Seppt 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void Init_Timers(void){
//------------------------------------------------------------------------------
// Timer Configurations
//------------------------------------------------------------------------------
  Init_Timer_A0(); //
//  Init_Timer_A1(); // 
//  Init_Timer_B0(); // 
//  Init_Timer_B1(); //  
  Init_Timer_B2();   //  Required for provided compiled code to work
//------------------------------------------------------------------------------
}

//------------------------------------------------------------------------------
// Timer A0 initialization sets up both A0_0 and A0_1-A0_2
void Init_Timer_A0(void) {
 TA0CTL = TASSEL__SMCLK; // SMCLK source
 TA0CTL |= TACLR; // Resets TA0R, clock divider, count direction
 TA0CTL |= MC__CONTINOUS; // Continuous up
 TA0CTL |= ID__2; // Divide clock by 2
 TA0CTL &= ~TAIE; // Disable Overflow Interrupt
 TA0CTL &= ~TAIFG; // Clear Overflow Interrupt flag

 TA0EX0 = TAIDEX_7; // Divide clock by an additional 8

 TA0CCR0 = TA0CCR0_INTERVAL; // CCR0
 TA0CCTL0 |= CCIE; // CCR0 enable interrupt
// TA0CCR1 = TA0CCR1_INTERVAL; // CCR1
// TA0CCTL1 |= CCIE; // CCR1 enable interrupt
// TA0CCR2 = TA0CCR2_INTERVAL; // CCR2
// TA0CCTL2 |= CCIE; // CCR2 enable interrupt
}