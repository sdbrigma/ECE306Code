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
*        Globlas: SW1_state and SW2_state
*******************************************************************************/
_Bool SW1_state;
_Bool SW2_state;
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

 //PJOUT ^= LED3; // Test signal
 ISR_COUNT++;
 LCD_COUNT++;
 TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
 
 if(LCD_COUNT == ONE_s){
     P3OUT ^= LCD_BACKLITE;
     LCD_COUNT =  ZERO;
    }
 if(SW1_state == ALWAYS){
   D_count1++;
   if(D_count1>DEBOUNCE){
     PJOUT &= ~LED3;
     D_count1 = ZERO;
     SW1_state = ZERO;
     P4IFG &= ~SW1;
     P4IE |= SW1;
   }
 }
 
  if(SW2_state == ALWAYS){
   D_count2++;
   if(D_count2>DEBOUNCE){
     PJOUT &= ~LED2;
     D_count2 = ZERO;
     SW2_state = ZERO;
     P4IFG &= ~SW2;
     P4IE |= SW2;
   }
 }
 
 if(ISR_COUNT>FIVE_SECONDS){
   ISR_COUNT = ZERO;
 }
}

// Interrupt for SW1 and SW2
#pragma vector=PORT4_VECTOR
__interrupt void switch_interrupt(void){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: Interrupt function for SW1 and SW2
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: switch_interrupt
*        Passed : No variables passed 
*        Locals: no variables declared
*        Returned: no values returned 
*        Globlas: SW1_state and SW2_state
*******************************************************************************/
// Switch 1
 if (P4IFG & SW1) {
 SW1_state = ALWAYS; // SW1 has been pressed
 PJOUT |= LED3; // led on

  // disable interrupt
 P4IFG &= ~SW1; // clear interrupt flag
 P4IE &= ~SW1;
 }
// Switch 2
 if (P4IFG & SW2) {
 SW2_state = ALWAYS;
 PJOUT |= LED2; // led on

 // disable interrupt
  P4IFG &= ~SW2; // clear interrupt flag
  P4IE &= ~SW2;
 }
}