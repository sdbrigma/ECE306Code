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
  const char transmitA1[] = "AT+S.SSIDTXT=ncsu\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }  
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
  displayIOT();
}

void getSSID(void){
  const char transmitA1[] = "AT+S.SSIDTXT\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
  displayIOT();
}

void setHostName(void){
  const char transmitA1[] = "AT+S.SCFG=ip_hostname,ECE-306-02-Q\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
  displayIOT();
}

void getHostName(void){
  const char transmitA1[] = "AT+S.GCFG=ip_hostname\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {
      break;
    }
    Five_msec_Delay(1);
    i++;
  }
  Five_msec_Delay(30);
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
  displayIOT();
}

void setPrivacyMode(void){
  const char transmitA1[] = "AT+S.SCFG=wifi_priv_mode,0\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
}

void getPrivacyMode(void){
  const char transmitA1[] = "AT+S.GCFG=wifi_priv_mode\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
}

void setNetworkMode(void){
  const char transmitA1[] = "AT+S.SCFG=wifi_mode,1\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
}

void getNetworkMode(void){
  const char transmitA1[] = "AT+S.GCFG=wifi_mode\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
}

void iotSave(void){
  const char transmitA1[] = "AT&W\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
}

void iotReset(void){
  short unsigned int i = ZERO;
  const char transmitA1[] = "AT+CFUN=1\r";
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(1);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    i++;
  }
  
  PJOUT |= RESET;
  while(ISR_COUNT<Second_1){}
  ISR_COUNT = ZERO;
  PJOUT &= ~RESET;
  Init_LCD();
}

void getIpAddress(void){
  const char transmitA1[] = "AT+S.STS=ip_ipaddr\r";
  short unsigned int i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == END_COMMAND) {break;}
    UCA1TXBUF = transmitA1[i];
    Five_msec_Delay(1);
    i++;
  }
}
void displayIOT(void){
  int i = ZERO;
  while(i<10){
    display_1[i] = CPU_Char_Rx[i];
    i++;
  }
  i = ZERO;
  
  while(i<10){
    display_2[i] = CPU_Char_Rx[i + 10];
    i++;
  }
  i = ZERO;
  while(i<10){
    display_3[i] = CPU_Char_Rx[i + 20];
    i++;
  }
  i = ZERO;
  while(i<10){
    display_4[i] = CPU_Char_Rx[i + 30];
    i++;
  }
  i = ZERO;
  posL1 = ZERO;
  posL2 = ZERO;
  posL3 = ZERO;
  posL4 = ZERO;
  Display_Process();
  Five_msec_Delay(20);
}