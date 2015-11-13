//******************************************************************************
//
//  Description: Handles interrupts from the A0 Timer
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

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0_ISR(void){
//******************************************************************************
//
//  Description: Handles interrupts from the A0 Timer
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: sw1_isr_set, sw1_time_count, sw2_isr_set, sw2_time_count,
// A0_time_Count, timer_isr_set
//
// Passed:
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 
  
      if (sw1_time_count >= FIFTY_MSEC) {
          PJOUT &= ~LED3;
          sw1_isr_set = INITIAL;
          sw1_time_count = INITIAL;
          //timer_isr_set = INITIAL;
          P4IFG &= ~SW1;	                // P4 IFG cleared
          P4IE |= SW1;
          TA0CCTL0 &= ~CCIE;			// CCR0 disable interrupt
  }
      if (sw2_time_count >= FIFTY_MSEC) {
          PJOUT &= ~LED3;
          sw2_isr_set = INITIAL;
          sw2_time_count = INITIAL;
          //timer_isr_set = INITIAL;
          P4IFG &= ~SW2;	                // P4 IFG cleared
          P4IE |= SW2;
          TA0CCTL0 &= ~CCIE;			// CCR0 disable interrupt
    }
  
  if (sw1_isr_set == ALWAYS) sw1_time_count++;
  if (sw2_isr_set == ALWAYS) sw2_time_count++;
  if (timer_isr_set == ALWAYS)  fifty_msec_count++;
  A0_time_count++;                         // Increment A0 Time Counter
  TA0CCR0 += TA0CCR0_INTERVAL;             // Increment CCR0 Register
}