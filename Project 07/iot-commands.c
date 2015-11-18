#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

// Use UCA1
void setSSID(void){
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
// Local: i, SSIDcmd
//
// Return: VOID
//
//****************************************************************************** 
  
  int i = ZERO;
  
 //// SET SSID ////
  displayLine2("  SET SSID  ",ZERO);
  Five_msec_Delay(switch_delay);
  char SSIDcmd[Index17] = "AT+S.SSIDTXT=ncsu";
  
  // Initialize IOT_RX ring
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index17; i++) {
    UCA1TXBUF = UCA0TXBUF = SSIDcmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1);
  
  // Wait for IOT confirmation
  while (IOT_RX[Index2] != 'O');
  }
void setHostName(void){
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
// Local: i, HOSTcmd
//
// Return: VOID
//
//****************************************************************************** 
  
  int i = ZERO;
  
//// SET HOSTNAME ////
  display_2 = " SET HOST ";
  Display_Process();
  Five_msec_Delay(switch_delay);
 char HOSTcmd[Index34] = "AT+S.SCFG=ip_hostname,ECE-306_02_Q";
  
  // Initialize IOT_RX ring
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index34; i++) {
    UCA1TXBUF = UCA0TXBUF = HOSTcmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1);
  
  // Wait for IOT confirmation
  while (IOT_RX[Index2] != 'O');
}

void setPrivacyMode(void){
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
// Local: i, NPMcmd
//
// Return: VOID
//
//****************************************************************************** 
  
  int i = ZERO;
  
//// SET NETWORK PRIVACY MODE////
  display_2 = " SET NPM  ";
  Display_Process();
  Five_msec_Delay(switch_delay);
 char NPMcmd[Index26] = "AT+S.SCFG=wifi_priv_mode,0";
  
  // Initialize IOT_RX ring
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index26; i++) {
    UCA1TXBUF = UCA0TXBUF = NPMcmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1);
  
  // Wait for IOT confirmation
  while (IOT_RX[Index2] != 'O');
}

void setNetworkMode(void){
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
// Local: i, NPMcmd
//
// Return: VOID
//
//****************************************************************************** 
  
  int i = ZERO;
  
//// SET NETWORK MODE ////
  display_2 = " SET MODE ";
  Display_Process();
  Five_msec_Delay(switch_delay);
 char NETcmd[Index21] = "AT+S.SCFG=wifi_mode,1";
  
  // Initialize IOT_RX ring
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index21; i++) {
    UCA1TXBUF = UCA0TXBUF = NETcmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1);  
  // Wait for IOT confirmation
  while (IOT_RX[Index2] != 'O');
}

void iotSave(void){
  int i = ZERO;
  
//// Begin Flash ////
  display_2 = " SET MODE ";
  Display_Process();
  Five_msec_Delay(switch_delay);
  char F1cmd[Index4] = "AT&W";
  char F2cmd[Index9] = "AT+CFUN=0";
  
  // Initialize IOT_RX ring
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index4; i++) {
    UCA1TXBUF = UCA0TXBUF = F1cmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1);
  
  // Wait for IOT confirmation
  while (IOT_RX[Index2] != 'O');
  
//// Finalize Flash ////
  display_2 = " GET MODE ";
  Display_Process();
  Five_msec_Delay(switch_delay);
  
 // Initialize IOT_RX ring
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index9; i++) {
    UCA1TXBUF = UCA0TXBUF = F2cmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1);
  
  Five_msec_Delay(switch_delay);
}

void pingIOT(void){
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
// Local: i, NPMcmd
//
// Return: VOID
//
//****************************************************************************** 
  
  int i = ZERO;
  
  // Initialize IOT_RX ring
  char PINGcmd[Index23] = "AT+S.PING=152.14.99.126";
  for(i=ZERO; i < SMALL_RING_SIZE; i++) IOT_RX[i] = ZERO;
  
  IOTRead = ZERO;
  for(i=ZERO; i < Index23; i++) {
    UCA1TXBUF = UCA0TXBUF = PINGcmd[i];
    Five_msec_Delay(Index1);
  }
  UCA1TXBUF = UCA0TXBUF = END_COMMAND;
  Five_msec_Delay(Index1); 
}