#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

int ISR_COUNT = 0;
// TimerA0 0 Interrupt handler
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void){
 PJOUT ^= LED1; // Test signal
 ISR_COUNT++;
 TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
}