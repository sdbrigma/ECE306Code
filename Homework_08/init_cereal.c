#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains code to initialize UART serial communication.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: init_cereal.c
*        Passed : No variables passed 
*        Returned: no values returned 
*        Globlas: None used
*******************************************************************************/
/*
Transmit flag is already set
Set the baud rate
Set transmission buffer
*/
void Init_Serial_UCA1(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This fucntion initialize UART serial communication for A1 registers.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Funcction name: Init_Serial_UCA1
*        Passed : No variables passed 
*        Returned: no values returned 
*        Locals: i
*        Globlas: cpu_rx_ring_wr, cpu_rx_ring_rd, cpu_rx_ring_wr,cpu_rt_ring_rd
*******************************************************************************/
 int i;
 
 for(i=ZERO; i<SMALL_RING_SIZE; i++){
 CPU_Char_Rx[i] = ORIGINAL; // USB Rx Buffer
 }
 cpu_rx_ring_wr = BEGINNING;
 cpu_rx_ring_rd = BEGINNING;

 for(i=ZERO; i<SMALL_RING_SIZE; i++){ // May not use this
 CPU_Char_Tx[i] = ORIGINAL; // USB Tx Buffer
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