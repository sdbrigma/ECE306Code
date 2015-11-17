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
  if (!(P4IN & SW1)){
    //getIotStatus();
    const char transmitA1[] = "AT+S.STS\r";
    int i = ZERO;
    while(ALWAYS){
      if(transmitA1[i] == END_COMMAND){break;}
      UCA1TXBUF = transmitA1[i];
      i++;
      Five_msec_Delay(30);
    }
  }
  if (!(P4IN & SW2)) {
    int i = ZERO;
  UCA0TXBUF = 0x40;
  while(ALWAYS){
    i++;
    if(USB_Char_Rx[i] == 0x40){
      i++;
      break;
    }
  }
}
//------------------------------------------------------------------------------
}