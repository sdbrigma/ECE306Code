//******************************************************************************
//
//  Description: This file contains code for the switches prcesses function.
//   
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
void Switches_Process(void){
//******************************************************************************
//
//  Description: This functions sets code for switch 1 and 2 upon being pressed
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************
  //const char HW8_String[] = "NCSU  #1  ";
  if (!(P4IN & SW1)){ // Transmission at 9600 baud    
  count(0x007E); // tilde reset
  Five_msec_Delay(20);
    display_1 = "    000    ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = ZERO;
    display_3 = "          ";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
  }
  if (!(P4IN & SW2)) {
    Five_msec_Delay(35);
    display_1 = "    000   ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = ZERO;
    display_3 = "          ";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
     UCA1TXBUF = 0x0030;
    while(ALWAYS){
    if (!(P4IN & SW1)) { count(0x007E); break; }
      count(UCA1RXBUF);
    }
   }
}
//------------------------------------------------------------------------------