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
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(20);
    i++;
  }  
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    UCA0TXBUF = CPU_Char_Rx[i];
    Five_msec_Delay(5);
      i++;
    }
  }

void getSSID(void){
  const char transmitA1[] = "AT+S.SSIDTXT\r";
  short unsigned int i = ZERO;
    while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  int m = 0;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
    if(CPU_Char_Rx[i] == 'n'){
      i++;
      if(CPU_Char_Rx[i] == 'c'){
        i++;
         if(CPU_Char_Rx[i] == 's'){
        i++;
         if(CPU_Char_Rx[i] == 'u'){
        i++;
      }
      }
      }
    }
      i++;
    }
}

void setHostName(void){
  const char transmitA1[] = "AT+S.SCFG=ip_hostname,ECE-306-02-Q\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void getHostName(void){
  const char transmitA1[] = "AT+S.GCFG=ip_hostname\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {
      break;
    }
    Five_msec_Delay(5);
    i++;
  }
  Five_msec_Delay(30);
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void setPrivacyMode(void){
  const char transmitA1[] = "AT+S.SCFG=wifi_priv_mode,0\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void getPrivacyMode(void){
  const char transmitA1[] = "AT+S.GCFG=wifi_priv_mode\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void setNetworkMode(void){
  const char transmitA1[] = "AT+S.SCFG=wifi_mode,1\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void getNetworkMode(void){
  const char transmitA1[] = "AT+S.GCFG=wifi_mode\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void iotSave(void){
  const char transmitA1[] = "AT&W\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void iotReset(void){
  short unsigned int i = ZERO;
  const char transmitA1[] = "AT+CFUN=1\r";
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    UCA1TXBUF = transmitA1[i];
    UCA0TXBUF = transmitA1[i];
    if(transmitA1[i] == END_COMMAND) {break;}
    Five_msec_Delay(5);
    i++;
  }
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
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
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == END_COMMAND) {break;}
    UCA0TXBUF = transmitA1[i];
    UCA1TXBUF = transmitA1[i];
    Five_msec_Delay(5);
    i++;
  }
  i = ZERO;
  while(CPU_Char_Rx[i] != 'O'){
    Five_msec_Delay(5);
      i++;
    }
}

void getIotStatus(void){
  const char transmitA1[] = "AT+S.STS\r";
  short unsigned int i = ZERO;
  while(i<IOT_RING_SIZE){
    CPU_Char_Rx[i] = ORIGINAL;
    i++;
  }
  i = ZERO;
  while(ALWAYS){
    if(transmitA1[i] == END_COMMAND) {break;}
    UCA1TXBUF = UCA0TXBUF = transmitA1[i];
    //UCA0TXBUF = UCA1RXBUF;
    Five_msec_Delay(10);
    i++;
  }  
  i = ZERO;
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