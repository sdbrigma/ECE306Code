//******************************************************************************
//
//  Description: Controls serialized communications
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

void Init_Serial_UCA1(_Bool lowBaud) {
//******************************************************************************
//
//  Description: Controls serialized communications
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: rxRead, rxWrite, txRead, txWrite, RX_Char[WORD_LENGTH],
// TX_Char[WORD_LENGTH],
//
// Passed:
//
// Local: i
//
// Return: VOID
//
//****************************************************************************** 
  
// Count
int i;

// Initial RX
RX_Char = INITIALIZE_CHAR;

rxWrite = INITIAL;
rxRead = INITIAL;

// Initial TX Array
for (i=INITIAL; i<SMALL_RING_SIZE; i++) {
	TX_Char[i] = INITIALIZE_CHAR;
}

txWrite = INITIAL;
txRead = INITIAL;

// Configure UART 0
UCA1CTLW0 = INITIAL;			// Use Word register
UCA1CTLW0 |= UCSSEL__SMCLK;
UCA1CTL1 |= UCSWRST;			// Set Software reset enable

UCA1CTLW0 |= UCPEN;
UCA1CTLW0 &= ~UCPAR;
UCA1CTLW0 &= ~UCMSB;
UCA1CTLW0 &= ~UC7BIT;
UCA1CTLW0 |= UCSPB;
UCA1CTLW0 &= ~UCMODE0;
UCA1CTLW0 &= ~UCMODE1;
UCA1CTLW0 &= ~UCSYNC;
UCA1CTLW0 |= UCSSEL0;
UCA1CTLW0 |= UCSSEL1;
UCA1CTLW0 &= ~UCRXEIE;
UCA1CTLW0 &= ~UCBRKIE;
UCA1CTLW0 &= ~UCDORM;
UCA1CTLW0 &= ~UCTXADDR;
UCA1CTLW0 &= ~UCTXBRK;

UCA1CTLW1 &= ~UCGLIT0;
UCA1CTLW1 &= ~UCGLIT1;

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

//UCA1STATW &= ~UCLISTEN; 
//UCA1STATW &= ~UCFE;
//UCA1STATW &= ~UCOE;
//UCA1STATW &= ~UCPE;
//UCA1STATW &= ~UCBRK;
//UCA1STATW &= ~UCRXERR;
//UCA1STATW &= ~UCADDR;
//UCA1STATW &= ~UCIDLE;
//
//UCA1ABCTL &= ~UCDELIM0;
//UCA1ABCTL &= ~UCDELIM1;
//UCA1ABCTL &= ~UCSTOE;
//UCA1ABCTL &= ~UCBTOE;
//UCA1ABCTL &= ~UCABDEN;
//
//UCA1IRCTL &= ~UCIRRXFL0;
//UCA1IRCTL &= ~UCIRRXFL1;
//UCA1IRCTL &= ~UCIRRXFL2;
//UCA1IRCTL &= ~UCIRRXFL3;
//UCA1IRCTL &= ~UCIRRXFL4;
//UCA1IRCTL &= ~UCIRRXFL5;
//UCA1IRCTL &= ~UCIRRXPL;
//UCA1IRCTL &= ~UCIRRXFE;
//UCA1IRCTL &= ~UCIRTXPL0;
//UCA1IRCTL &= ~UCIRTXPL1;
//UCA1IRCTL &= ~UCIRTXPL2;
//UCA1IRCTL &= ~UCIRTXPL3;
//UCA1IRCTL &= ~UCIRTXPL4;
//UCA1IRCTL &= ~UCIRTXPL5;
//UCA1IRCTL &= ~UCIRTXCLK;
//UCA1IRCTL &= ~UCIREN;
//
//UCA1IE &= ~UCTXCPTIE;
//UCA1IE &= ~UCSTTIE;
//UCA1IE |= UCTXIE;
//UCA1IE |= UCRXIE;
//
//UCA1IFG &= ~UCTXCPTIFG;
//UCA1IFG &= ~UCSTTIFG;
//UCA1IFG |= UCTXIFG;
//UCA1IFG &= ~UCRXIFG;
//
//UCA1IV = INITIAL;

  // CPU_TXD Initialization
  P2SEL0 &= ~CPU_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_TXD;                    // P2SEL1 ->    1
  P2OUT |= CPU_TXD;                    // P2OUT ->      1
  P2DIR |= CPU_TXD;                     // P2DIR ->     1
  
  // CPU_RXD Initialization
  P2SEL0 &= ~CPU_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~CPU_RXD;                    // P2OUT ->     0
  P2DIR  &= ~CPU_RXD;                   // P2DIR ->     0
  
UCA1CTLW0 &= ~UCSWRST;			// Release from reset

UCA1IE |= UCTXIE;
UCA1IE |= UCRXIE;	        // Enable  RX  interrupt
}