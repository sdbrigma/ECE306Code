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
  
  int i = INITIAL;
  
 //// SET SSID ////
  display_2 = " SET SSID ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  char SSIDcmd[Pos17] = "AT+S.SSIDTXT=ncsu";
  
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos17; i++) {
    UCA1TXBUF = UCA0TXBUF = SSIDcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  // Wait for IOT confirmation
  while (IOT_RX[Pos2] != 'O');
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
  
  int i = INITIAL;
  
//// SET HOSTNAME ////
  display_2 = " SET HOST ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
 char HOSTcmd[Pos34] = "AT+S.SCFG=ip_hostname,ECE-306_02_C";
  
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos34; i++) {
    UCA1TXBUF = UCA0TXBUF = HOSTcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  // Wait for IOT confirmation
  while (IOT_RX[Pos2] != 'O');
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
  
  int i = INITIAL;
  
//// SET NETWORK PRIVACY MODE////
  display_2 = " SET NPM  ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
 char NPMcmd[Pos26] = "AT+S.SCFG=wifi_priv_mode,0";
  
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos26; i++) {
    UCA1TXBUF = UCA0TXBUF = NPMcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  // Wait for IOT confirmation
  while (IOT_RX[Pos2] != 'O');
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
  
  int i = INITIAL;
  
//// SET NETWORK MODE ////
  display_2 = " SET MODE ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
 char NETcmd[Pos21] = "AT+S.SCFG=wifi_mode,1";
  
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos21; i++) {
    UCA1TXBUF = UCA0TXBUF = NETcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  // Wait for IOT confirmation
  while (IOT_RX[Pos2] != 'O');
}

void iotSave(void){
  int i = INITIAL;
  
//// Begin Flash ////
  display_2 = " SET MODE ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  char F1cmd[Pos4] = "AT&W";
  char F2cmd[Pos9] = "AT+CFUN=0";
  
  // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos4; i++) {
    UCA1TXBUF = UCA0TXBUF = F1cmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  // Wait for IOT confirmation
  while (IOT_RX[Pos2] != 'O');
  
//// Finalize Flash ////
  display_2 = " GET MODE ";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
 // Initialize IOT_RX ring
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos9; i++) {
    UCA1TXBUF = UCA0TXBUF = F2cmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay();
  
  Five_msec_Delay(BIGGER_DELAY);
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
  
  int i = INITIAL;
  
  // Initialize IOT_RX ring
  char PINGcmd[Pos23] = "AT+S.PING=152.14.99.126";
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  
  IOTRead = INITIAL;
  for(i=INITIAL; i < Pos23; i++) {
    UCA1TXBUF = UCA0TXBUF = PINGcmd[i];
    One_msec_Delay();
  }
  UCA1TXBUF = UCA0TXBUF = TX_FINISH;
  One_msec_Delay(); 
}