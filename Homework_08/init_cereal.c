#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

/*
Transmit flag is already set
Set the baud rate
Set transmission buffer
*/
void Init_Serial_UCA1(void){
 int i;
 
 for(i=0; i<SMALL_RING_SIZE; i++){
 CPU_Char_Rx[i] = 0x00; // USB Rx Buffer
 }
 cpu_rx_ring_wr = BEGINNING;
 cpu_rx_ring_rd = BEGINNING;

 for(i=0; i<SMALL_RING_SIZE; i++){ // May not use this
 CPU_Char_Tx[i] = 0x00; // USB Tx Buffer
 }
 cpu_tx_ring_wr = BEGINNING;
 cpu_tx_ring_rd = BEGINNING;
 // Configure UART 0
 UCA1CTLW0 = ZERO; // Use word register
 UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA1CTLW0 |= UCSWRST; // Set Software reset enable, logic held in reset state
 UCA1BRW = BAUD_9600; // 9600 baud
 UCA1MCTLW = MOD_CTRL1;
 
 P2SEL1 |= CPU_TXD;
 P2SEL0 &= ~CPU_TXD;
 P2OUT  |= CPU_TXD;
 P2DIR |= CPU_TXD;
 
 P2SEL1 |= CPU_RXD;
 P2SEL0 &= ~CPU_RXD;
 P2OUT &= ~CPU_RXD;
 P2DIR &= ~CPU_RXD;
 
 UCA1CTLW0 &= ~UCSWRST; // Release from reset
 UCA1IE |= UCRXIE; // Enable RX (receive) interrupt
 UCA1IE |= UCTXIE; // Enable TX (transmit) interrupt 
}