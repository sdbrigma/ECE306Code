//******************************************************************************
//
//  Description: Initializes the A0 Timer
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

void Init_Timer_A0(void){
//******************************************************************************
//
//  Description: Initializes the A0 Timer
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed:
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 

TA0CTL = TASSEL__SMCLK;		        // SMCLK source
TA0CTL |= TACLR;			// Resets TA0R, clock divider, count direction
TA0CTL |= MC__CONTINOUS;	        // Sets timer to count up continuously and then reset to zero
TA0CTL |= ID__8;			// Divide the clock by 8
TA0CTL &= ~TAIE;			// Disable overflow interrupt
TA0CTL &= ~TAIFG;			// Clear overflow interrupt flag

TA0EX0 = TAIDEX_7;			// Divide the clock by an additional 8

TA0CCR0 = TA0CCR0_INTERVAL;	        // CCR0
TA0CCTL0 |= CCIE;			// CCR0 enable interrupt

// TA0CCR1 = TA0CCR1_INTERVAL	// CCR1
// TA0CCTL1 |= CCIE;			// CCR1 enable interrupt

// TA0CCR2 = TA0CCR2_INTERVAL	// CCR2
// TA0CCTL2 |= CCIE;			// CCR2 enable interrupt

}