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


ALL FUNCTIONS ONLY SET IOT TO OPERATE ON NCSU WIFI
TO DO - MAKE FUNCTIONS CUSTOMIZABLE


*/
void Init_IOT(void){
  setSSID();
  setHostName();
  setPrivacyMode();
  setNetworkMode();
  iotSave();
  iotReset();
}
// Use UCA1
void setSSID(void){
  const char transmitA1[] = "AT+S.SSIDTXT=ncsu";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void getSSID(void){
  const char transmitA1[] = "AT+S.SSIDTXT";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
   UCA1TXBUF = END_COMMAND;
}

void setHostName(void){
  const char transmitA1[] = "AT+S.SCFG=ip_hostname,ECE-306-02-Q";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
   UCA1TXBUF = END_COMMAND;
}

void getHostName(void){
  const char transmitA1[] = "AT+S.GCFG=ip_hostname";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void setPrivacyMode(void){
  const char transmitA1[] = "AT+S.SCFG=wifi_priv_mode,0";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void getPrivacyMode(void){
  const char transmitA1[] = "AT+S.GCFG=wifi_priv_mode";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void setNetworkMode(void){
  const char transmitA1[] = "AT+S.SCFG=wifi_mode,1";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void getNetworkMode(void){
  const char transmitA1[] = "AT+S.GCFG=wifi_mode";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void iotSave(void){
  const char transmitA1[] = "AT&W";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
}

void iotReset(void){
  short unsigned int i = ZERO;
  const char transmitA1[] = "AT+CFUN=1";
  while(ALWAYS){
    if(transmitA1[i] == ORIGINAL) {break;}
    UCA1TXBUF = transmitA1[i];
    i++;
  }
  UCA1TXBUF = END_COMMAND;
  
  PJOUT |= RESET;
  while(ISR_COUNT<Second_1){}
  ISR_COUNT = ZERO;
  PJOUT &= ~RESET;
  Init_LCD();
}