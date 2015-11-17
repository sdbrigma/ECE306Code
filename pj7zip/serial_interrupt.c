//******************************************************************************
//
//  Description: Handles eUSCI_A interrupts
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

#pragma vector = USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
//******************************************************************************
//
//  Description: Handles eUSCI_A0 interrupts
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: rxRead RX_Char[WORD_LENGTH], receiveEnable
//
// Passed:
//
// Local: temp
//
// Return: VOID
//
//****************************************************************************** 
  unsigned int temp = INITIAL;
  switch(__even_in_range(UCA0IV, USCI_val8)) {
  case SW_SEL_0:		//Vector 0 - No Interrupt
    break;
  case SW_SEL_2:		// Vector 2 - RXIFG
    // Code for Receive
    temp = rxRead;
    receiveEnable = TRUE;           // Tranmission received
    RX_Char[temp] =  UCA0RXBUF;   // Store Transmission                    
    if (++rxRead >= (SMALL_RING_SIZE)) {
      rxRead = INITIAL;             // Reset Index
    }
    break;
  case SW_SEL_4:		// Vector 4 - TXIFG
    // Code for Transmit
    break;
  default: break;
  }
  
}

#pragma vector = USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){
//******************************************************************************
//
//  Description: Handles eUSCI_A interrupts
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: rxRead RX_Char[WORD_LENGTH], receiveEnable
//
// Passed:
//
// Local: temp
//
// Return: VOID
//
//****************************************************************************** 
  unsigned int temp = INITIAL;
  switch(__even_in_range(UCA1IV, USCI_val8)) {
  case SW_SEL_0:		//Vector 0 - No Interrupt
    break;
  case SW_SEL_2:		// Vector 2 - RXIFG
    // Code for Receive
    temp = IOTRead;
    IOT_RX[temp] =  UCA1RXBUF;   // Store Transmission 
    if (IOT_RX[temp] == '*') {
      IOTRead = INITIAL;
      IOT_RX[Pos0] = IOT_RX[temp];
    }
    if (++IOTRead >= (SMALL_RING_SIZE)) {
      IOTRead = INITIAL;         // Reset Index
    }
    break;
  case SW_SEL_4:		// Vector 4 - TXIFG
    // Code for Transmit
    break;
  default: break;
  }

}