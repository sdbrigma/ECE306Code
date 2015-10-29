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
//------------------------------------------------------------------------------
// Switch proccess sets LCD text when SW1 and SW2 are pressed
  const char HW8_String[] = "NCSU  #1  ";
  if (!(P4IN & SW1)){ // Transmission at 9600 baud
    UCA1BRW = BAUD_9600;
    UCA1MCTLW = MOD_CTRL1;
    display_1 = "          ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = ZERO;
    display_3 = "Baud Rate";
    posL3 = ALWAYS;
    display_4 = "   9600   ";
    posL4 = ZERO;
    Display_Process();
    
      while(ALWAYS){
        if (!(P4IN & SW2)) { break; }
        UCA1TXBUF = HW8_String[cpu_rx_ring_wr];
        display_1[LINE_POS_L9] = display_1[LINE_POS_L8];
        display_1[LINE_POS_L8] = display_1[LINE_POS_L7];
        display_1[LINE_POS_L7] = display_1[LINE_POS_L6];
        display_1[LINE_POS_L6] = display_1[LINE_POS_L5];
        display_1[LINE_POS_L5] = display_1[LINE_POS_L4];
        display_1[LINE_POS_L4] = display_1[LINE_POS_L3];
        display_1[LINE_POS_L3] = display_1[LINE_POS_L2];
        display_1[LINE_POS_L2] = display_1[LINE_POS_L1];
        display_1[LINE_POS_L1] = display_1[LINE_POS_L0];
        display_1[LINE_POS_L0] = UCA1RXBUF;
        posL1 = ZERO;
        display_2 = "          ";
        posL2 = ZERO;
        display_3 = " Baud Rate";
        posL3 = ZERO;
        display_4 = "  9600  ";
        posL4 = ZERO;
        Display_Process();
        Five_msec_Delay(75);
      }
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
    posL2 = ZERO;
    display_3 = "Baud Rate";
    posL3 = ALWAYS;
    display_4 = " 115200 ";
    posL4 = ZERO;
    Display_Process();
      
    // transmission at 115200 baud
    UCA1BRW = BAUD_115200;
    UCA1MCTLW = MOD_CTRL2;
    
    while(ALWAYS){
        if (!(P4IN & SW1)) { break; }
        UCA1TXBUF = HW8_String[cpu_rx_ring_wr];
        display_1[LINE_POS_L9] = display_1[LINE_POS_L8];
        display_1[LINE_POS_L8] = display_1[LINE_POS_L7];
        display_1[LINE_POS_L7] = display_1[LINE_POS_L6];
        display_1[LINE_POS_L6] = display_1[LINE_POS_L5];
        display_1[LINE_POS_L5] = display_1[LINE_POS_L4];
        display_1[LINE_POS_L4] = display_1[LINE_POS_L3];
        display_1[LINE_POS_L3] = display_1[LINE_POS_L2];
        display_1[LINE_POS_L2] = display_1[LINE_POS_L1];
        display_1[LINE_POS_L1] = display_1[LINE_POS_L0];
        display_1[LINE_POS_L0] = UCA1RXBUF;
        posL1 = ZERO;
        display_2 = "          ";
        posL2 = ZERO;
        display_3 = " Baud Rate";
        posL3 = ZERO;
        display_4 = " 115200 ";
        posL4 = ZERO;
        Display_Process();
        Five_msec_Delay(75);
    }
}
//------------------------------------------------------------------------------
}