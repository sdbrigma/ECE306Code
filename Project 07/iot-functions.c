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
void Init_IOT(void){
  //******************************************************************************
//
//  Description: This function is used to configure the IOT device on NCSU
//  wireless network
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: IOT_RX[SMALL_RING_SIZE], display_1, display_2, display_3,
// display_4
//
// Passed: 
//
// Local: i, firstDOT, secondDOT
//
// Return: VOID
//
//****************************************************************************** 
  
  int i = INITIAL;
  _Bool firstDOT = FALSE;
  Display_Format();
  
  UCA1IE |= UCTXIE;                       // Enable TX interrupt
  UCA1IE |= UCRXIE;	                  // Enable RX interrupt 
  
  // CONFIGURE SSID
  SSID();
  // CONFIGURE HOSTNAME
  HOST();
  // CONFIGURE NETWORK PRIVACY MODE
  NPM();
  // CONFIGURE NETWORK MODE
  NET_MODE();
  // FLASH SETTING
  FLASH();
  
//// RESET ////
  display_2 = "  RESET   ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
  PJOUT |= RESET;
  Five_msec_Delay(ONE_SEC_COUNT);
  PJOUT &= ~RESET;
  Init_LCD();
  
  Five_msec_Delay(ONE_SEC_MULT);
  
  display_1 = "----------";
  display_2 = " COMPLETE ";
  display_3 = "----------";
  display_4 = "          ";
  Display_Process();
  posL1 = LINE_POS_L0;
  posL2 = LINE_POS_L0;
  posL3 = LINE_POS_L0;
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  
  Five_msec_Delay(ONE_SEC_MULT);
  
  display_1 = "----------";
  display_2 = "CONNECTING";
  display_3 = "----------";
  display_4 = "          ";
  Display_Process();
  posL1 = LINE_POS_L0;
  posL2 = LINE_POS_L0;
  posL3 = LINE_POS_L0;
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  
  Five_msec_Delay(FIVE_SEC_MULT);

  // GET SSID to Display
  char SSIDcmd[Pos12] = "AT+S.SSIDTXT";
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos12; i++) {
    UCA1TXBUF = UCA0TXBUF = SSIDcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  Five_msec_Delay(BIG_DELAY);
  
  display_1[Pos0] = ' ';
  display_1[Pos1] = ' ';
  display_1[Pos2] = ' ';
  display_1[Pos3] = IOT_RX[Pos8];
  display_1[Pos4] = IOT_RX[Pos9];
  display_1[Pos5] = IOT_RX[Pos10];
  display_1[Pos6] = IOT_RX[Pos11];
  display_1[Pos7] = ' ';
  display_1[Pos8] = ' ';
  display_1[Pos9] = ' ';
  display_2 = "  ipaddr  ";
  display_3 = display_4 = "          ";
  big = INITIAL;
  lcd_4line();
  Display_Process();
  
  Five_msec_Delay(ONE_SEC_MULT);
  
  // GET IP Address to display
  char IPADDRcmd[Pos18] = "AT+S.STS=ip_ipaddr";
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos18; i++) {
    UCA1TXBUF = UCA0TXBUF = IPADDRcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  Five_msec_Delay(BIG_DELAY);
  UCA1IE &= ~UCRXIE;
  
  int indexIP = INITIAL;
  firstDOT = FALSE;
  display_3[Pos0] = ' ';
  for(i=Pos1; i < Pos9; i++) {
    display_3[i] = IOT_RX[i+Pos14];
    if ((IOT_RX[i+Pos14] == '.') && (firstDOT == TRUE)) {
      indexIP = i+Pos13;
      break;
    }
    if (IOT_RX[i+Pos14] == '.') firstDOT = TRUE;
  }
  display_3[Pos9] = ' ';
 
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
  display_4 = "         ";
  for(i=Pos2; i < Pos9; i++) {
    if (IOT_RX[i+indexIP] == '\r') break;
    display_4[i] = IOT_RX[i+indexIP];
  }
  
  // Display IP Address
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  UCA1IE |= UCRXIE;
  
  // PING LAB COMPUTER
  PING();
  
  // Wait for IOT confirmation
  while (IOT_RX[Pos31] != 'O') {
    if (!(P4IN & SW2)) {
      Five_msec_Delay(LIL_SW_DELAY); 
      break;
    }
  }
  
  while(ALWAYS) {
    if (!(P4IN & SW2)) {
      Five_msec_Delay(LIL_SW_DELAY); 
      break;
    }
  }
}