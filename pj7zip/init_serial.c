//******************************************************************************
//
//  Description: Initializes serialized communications
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Init_Serial_UCA0(_Bool lowBaud) {
//******************************************************************************
//
//  Description: Initializes serialized communications
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: rxRead, rxWrite, txRead, txWrite, RX_Char[WORD_LENGTH],
// TX_Char[WORD_LENGTH],
//
// Passed: lowBaud
//
// Local: i
//
// Return: VOID
//
//****************************************************************************** 

// Configure UART 0
UCA0CTLW0 = INITIAL;			// Use Word register
UCA0CTLW0 |= UCSSEL__SMCLK;
UCA0CTL1 |= UCSWRST;			// Set Software reset enable

// Set Baudrate
if (lowBaud)
  {
    UCA0BRW = BRW9600;
    UCA0MCTLW = BAUD_9600;     // Set Baud Rate to 9600
  }
else 
  { 
    UCA0BRW = BRW115200;
    UCA0MCTLW = BAUD_115200;   // Set Baud Rate to 115200
  }

  // USB_TXD Initialization
  P2SEL0 &= ~USB_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= USB_TXD;                    // P2SEL1 ->    1
  P2OUT|= USB_TXD;                      // P2OUT ->     1
  P2DIR |= USB_TXD;                     // P2DIR ->     1

  // USB_RXD Initialization
  P2SEL0 &= ~USB_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= USB_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~USB_RXD;                    // P2OUT ->     0
  P2DIR  &= ~USB_RXD;                   // P2DIR ->     0

  // CPU_TXD Initialization
  P2SEL0 &= ~CPU_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_TXD;                    // P2SEL1 ->    1
  P2OUT |= CPU_TXD;                     // P2OUT ->      1
  P2DIR |= CPU_TXD;                     // P2DIR ->     1
  
  // CPU_RXD Initialization
  P2SEL0 &= ~CPU_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~CPU_RXD;                    // P2OUT ->     0
  P2DIR  &= ~CPU_RXD;                   // P2DIR ->     0
 
UCA0CTLW0 &= ~UCSWRST;			// Release from reset

UCA0IE |= UCTXIE;                       // Enable TX interrupt
UCA0IE |= UCRXIE;	                // Enable RX interrupt
}

void Init_Serial_UCA1(_Bool lowBaud) {
//******************************************************************************
//
//  Description: Initializes serialized communications
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: rxRead, rxWrite, txRead, txWrite, RX_Char[WORD_LENGTH],
// TX_Char[WORD_LENGTH],
//
// Passed: lowBaud
//
// Local: i
//
// Return: VOID
//
//****************************************************************************** 
  
// Count
int i;

// Initial RX
for (i=INITIAL; i<SMALL_RING_SIZE; i++) {
	RX_Char[i] = INITIALIZE_CHAR;
}
rxRead = INITIAL;


// Configure UART 0
UCA1CTLW0 = INITIAL;			// Use Word register
UCA1CTLW0 |= UCSSEL__SMCLK;
UCA1CTL1 |= UCSWRST;			// Set Software reset enable

// Optional Initialization Controls
//UCA1CTLW0 |= UCPEN;
//UCA1CTLW0 &= ~UCPAR;
//UCA1CTLW0 &= ~UCMSB;
//UCA1CTLW0 &= ~UC7BIT;
//UCA1CTLW0 &= ~UCSPB;
//UCA1CTLW0 &= ~UCMODE0;
//UCA1CTLW0 &= ~UCMODE1;
//UCA1CTLW0 &= ~UCSYNC;
//UCA1CTLW0 |= UCSSEL0;
//UCA1CTLW0 |= UCSSEL1;
//UCA1CTLW0 &= ~UCRXEIE;
//UCA1CTLW0 &= ~UCBRKIE;
//UCA1CTLW0 &= ~UCDORM;
//UCA1CTLW0 &= ~UCTXADDR;
//UCA1CTLW0 &= ~UCTXBRK;
//UCA1CTLW1 &= ~UCGLIT0;
//UCA1CTLW1 &= ~UCGLIT1;

// Set Baudrate
if (lowBaud)
  {
    UCA1BRW = BRW9600;
    UCA1MCTLW = BAUD_9600;     // Set Baud Rate to 9600
  }
else 
  { 
    UCA1BRW = BRW115200;
    UCA1MCTLW = BAUD_115200;   // Set Baud Rate to 115200
  }

  // USB_TXD Initialization
  P2SEL0 &= ~USB_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= USB_TXD;                    // P2SEL1 ->    1
  P2OUT|= USB_TXD;                      // P2OUT ->     1
  P2DIR |= USB_TXD;                     // P2DIR ->     1

  // USB_RXD Initialization
  P2SEL0 &= ~USB_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= USB_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~USB_RXD;                    // P2OUT ->     0
  P2DIR  &= ~USB_RXD;                   // P2DIR ->     0

  // CPU_TXD Initialization
  P2SEL0 &= ~CPU_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_TXD;                    // P2SEL1 ->    1
  P2OUT |= CPU_TXD;                     // P2OUT ->      1
  P2DIR |= CPU_TXD;                     // P2DIR ->     1
  
  // CPU_RXD Initialization
  P2SEL0 &= ~CPU_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~CPU_RXD;                    // P2OUT ->     0
  P2DIR  &= ~CPU_RXD;                   // P2DIR ->     0
  
UCA1CTLW0 &= ~UCSWRST;			// Release from reset

UCA1IE &= ~UCTXIE;                       // Disable TX interrupt
UCA1IE &= ~UCRXIE;	                // Disable RX interrupt
}