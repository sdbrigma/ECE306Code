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
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
void Switches_Process(void){
//------------------------------------------------------------------------------
// Switch proccess sets LCD text when SW1 and SW2 are pressed
  if (!(P4IN & SW1)){ // Transmission at 9600 baud
    display_1 = "          ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = 2;
    display_3 = "Baud Rate";
    posL3 = ZERO;
    display_4 = "9600";
    posL4 = ZERO;
    Display_Process();
    
    UCA1IE |= UCTXIE; // Enable TX (transmit) interrupt
    CPU_Char_Tx[0] = 0x04;
    UCA1TXBUF = CPU_Char_Tx[0];
  }
  if (!(P4IN & SW2)) {
    /*display_1 = "Embedded";
    posL1 = SW2_posL1;
    display_2 = "Systems";
    posL2 = SW2_posL1;
    display_3 = "Rock!";
    posL3 = SW2_posL1;
    display_4 = "Go Pack!";
    posL4 = SW2_posL1;*/
      
          
    display_1 = "          ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = 2;
    display_3 = "Baud Rate";
    posL3 = ZERO;
    display_4 = "115000";
    posL4 = ZERO;
    Display_Process();
      
    // transmission at 115200 baud
    UCA1BRW = BAUD_115200;
    UCA1MCTLW = MOD_CTRL2;
    
    UCA1IE |= UCTXIE; // Enable TX (transmit) interrupt
    CPU_Char_Tx[0] = 0x09;
    UCA1TXBUF = CPU_Char_Tx[0];
}
//------------------------------------------------------------------------------
}