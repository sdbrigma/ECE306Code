//******************************************************************************
//
//  Description: Handles eUSCI_A interrupts
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

#pragma vector = USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){
//******************************************************************************
//
//  Description: Handles eUSCI_A interrupts
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: txRead RX_Char[WORD_LENGTH], TX_Char[WORD_LENGTH]
//
// Passed:
//
// Local: temp
//
// Return: VOID
//
//****************************************************************************** 
        unsigned volatile int temp = INITIAL;
	switch(__even_in_range(UCA1IV, USCI_val8)) {
		case SW_SEL_0:		//Vector 0 - No Interrupt
			break;
		case SW_SEL_2:		// Vector 2 - RXIFG
			// Code for Receive
                        temp = rxRead;
                        receiveEnable = TRUE;
                        RX_Char[rxRead] =  UCA1RXBUF;                        
                        if (++rxRead >= (SW_SEL_2)) {
                          rxRead = INITIAL;
                        }
			break;
		case SW_SEL_4:		// Vector 4 - TXIFG
			// Code for Transmit
			break;
		default: break;
	}

}