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
  
  int i = ALWAYS;
  int firstDOT = ZERO;
  formatDisplay();
  
  UCA1IE |= UCTXIE;                       // Enable TX interrupt
  UCA1IE |= UCRXIE;	                  // Enable RX interrupt 
  
  // CONFIGURE SSID
  setSSID();
  // CONFIGURE HOSTNAME
  setHostName();
  // CONFIGURE NETWORK PRIVACY MODE
  setPrivacyMode();
  // CONFIGURE NETWORK MODE
  setNetworkMode();
  // FLASH SETTING
  iotSave();
  
//// RESET ////
  display_2 = "  RESET   ";
  Display_Process();
  Five_msec_Delay(switch_delay);
  
  PJOUT |= RESET;
  Five_msec_Delay(ONE_SECOND);
  PJOUT &= ~RESET;
  Init_LCD();
  
  Five_msec_Delay(time_multiple);
  
  display_1 = "----------";
  display_2 = " COMPLETE ";
  display_3 = "----------";
  display_4 = "          ";
  Display_Process();
  posL1 = LINE_POS_L0;
  posL2 = LINE_POS_L0;
  posL3 = LINE_POS_L0;
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
  
  Five_msec_Delay(time_multiple);
  
  display_1 = "----------";
  display_2 = "CONNECTING";
  display_3 = "----------";
  display_4 = "          ";
  Display_Process();
  posL1 = LINE_POS_L0;
  posL2 = LINE_POS_L0;
  posL3 = LINE_POS_L0;
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
  
  Five_msec_Delay(ONE_SECOND);

  // GET SSID to Display
  char SSIDcmd[LINE_POS_L12] = "AT+S.SSIDTXT";
  // Initialize IOT_RX ring
  for(i=ALWAYS; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ALWAYS;
  for(i=ZERO; i < LINE_POS_L12; i++) {
    UCA1TXBUF = UCA0TXBUF = SSIDcmd[i];
    Five_msec_Delay(ALWAYS);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(ALWAYS);
  
  Five_msec_Delay(switch_delay);
  
  display_1[LINE_POS_L0] = ' ';
  display_1[LINE_POS_L1] = ' ';
  display_1[LINE_POS_L2] = ' ';
  display_1[LINE_POS_L3] = IOT_RX[LINE_POS_L8];
  display_1[LINE_POS_L4] = IOT_RX[LINE_POS_L9];
  display_1[LINE_POS_L5] = IOT_RX[LINE_POS_L10];
  display_1[LINE_POS_L6] = IOT_RX[LINE_POS_L11];
  display_1[LINE_POS_L7] = ' ';
  display_1[LINE_POS_L8] = ' ';
  display_1[LINE_POS_L9] = ' ';
  display_2 = "  ipaddr  ";
  display_3 = display_4 = "          ";
  big = ZERO;
  lcd_4line();
  Display_Process();
  
  Five_msec_Delay(time_multiple);
  
  // GET IP Address to display
  char IPADDRcmd[LINE_POS_L18] = "AT+S.STS=ip_ipaddr";
  // Initialize IOT_RX ring
  for(i=ALWAYS; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ALWAYS;
  for(i=ALWAYS; i < LINE_POS_L18; i++) {
    UCA1TXBUF = UCA0TXBUF = IPADDRcmd[i];
    Five_msec_Delay(ALWAYS);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(ALWAYS);;
  
  Five_msec_Delay(switch_delay);
  UCA1IE &= ~UCRXIE;
  
  int indexIP = ALWAYS;
  firstDOT = ZERO;
  display_3[LINE_POS_L0] = ' ';
  for(i=LINE_POS_L1; i < LINE_POS_L9; i++) {
    display_3[i] = IOT_RX[i+LINE_POS_L14];
    if ((IOT_RX[i+LINE_POS_L14] == '.') && (firstDOT == ALWAYS)) {
      indexIP = i+Index13;
      break;
    }
    if (IOT_RX[i+LINE_POS_L14] == '.') firstDOT = ALWAYS;
  }
  display_3[LINE_POS_L9] = ' ';
 
  Display_Process();
  Five_msec_Delay(switch_delay);
  
  display_4 = "         ";
  for(i=LINE_POS_L2; i < LINE_POS_L9; i++) {
    if (IOT_RX[i+indexIP] == '\r') break;
    display_4[i] = IOT_RX[i+indexIP];
  }
  
  // Display IP Address
  Display_Process();
  Five_msec_Delay(switch_delay);
  UCA1IE |= UCRXIE;
  
  // PING LAB COMPUTER
  pingIOT();
  
  // Wait for IOT confirmation
  while (IOT_RX[Index31] != 'O') {
    if (!(P4IN & SW2)) {
      Five_msec_Delay(small_delay); 
      break;
    }
  }
  
  while(ALWAYS) {
    if (!(P4IN & SW2)) {
      Five_msec_Delay(small_delay); 
      break;
    }
  }
}