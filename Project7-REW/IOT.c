//***********************************************************************
//      Title: IOT.c
//      Description: This file handles interaction with IOT 
//      Rachel Williams
//      November 2015
//      Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//***********************************************************************

#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

//*****************************************************************************
//      Function name: IOT_config
//      Description: Configuration for IOT device on ncsu wifi  
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void IOT_config(void){
  lcd_4line();
  int i = ORIGINAL;
  int j = ORIGINAL;
  int k = ORIGINAL;
  
  //----------Set SSID------------------------------------------------------- 
  Set_SSID(); 
  
  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  //----------Get SSID--------------------------------------------------------
  Get_SSID(); 

  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  //----------Set host name--------------------------------------------------- 
  Set_HostN(); 
 
  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  //----------Get host name---------------------------------------------------
  Get_HostN(); 
 
  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  //----------Set network privacy mode----------------------------------------
  Set_NetP(); 

  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  //----------Get network privacy mode---------------------------------------- 
  Get_NetP(); 

  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  //----------Set network mode------------------------------------------------ 
  Set_NetM(); 
  
  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1); 
  
  //----------Get network mode------------------------------------------------ 
  Get_NetM(); 
 
  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1); 
  
  //----------Save settings on flash module-----------------------------------
  Save_All(); 
  
  // Waiting until "OK" is received 
  while(IOT_Char_Rx[i] != 'O')i++;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1); 
  
  //----------Reset module----------------------------------------------------
  Reset_All();
  
  // Reset line, delayed for one second, brought back
  PJOUT |= RESET;
  X_Seconds_Delay(POSIT_1); 
  PJOUT &= ~RESET;
  
  // Another 1 second delay, then re-initialize LCD 
  X_Seconds_Delay(POSIT_1); 
  Init_LCD(); 
  
  Out_To_LCD("Reset", POSIT_0, "Complete", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  X_Seconds_Delay(POSIT_2);
  
  //----------Connecting to network-------------------------------------------
  Out_To_LCD("Connecting", POSIT_0, "to", POSIT_0, "network...", POSIT_0, "", POSIT_0);
  Display_Process();
  Five_Msec_Delay(50); 
  
  // Checking if connection is successful 
  i = ORIGINAL;
  cpu_rx_ring_wr = ORIGINAL;
  while(ALWAYS){
    if(i)break; 
    if(IOT_Char_Rx[cpu_rx_ring_wr]== 'H'){
      if(IOT_Char_Rx[cpu_rx_ring_wr+POSIT_1]== 'a'){
        if(IOT_Char_Rx[cpu_rx_ring_wr+POSIT_2]== 'n'){
          i = ALWAYS;
        }
      }
    }
  }
  
  Out_To_LCD("Successful", POSIT_0, "connection", POSIT_0, "", POSIT_0, "", POSIT_0);
  Display_Process(); 
  X_Seconds_Delay(POSIT_2);
  
  //----------Roaming--------------------------------------------------------- 
//  Roam(); 
//  Five_Msec_Delay(POSIT_10);
  
  //---------Get SSID and display to LCD--------------------------------------
  Get_SSID(); 
  cpu_rx_ring_wr = ORIGINAL;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  // Parsing through Rx array until ncsu is reached 
  while(ALWAYS){
    if(i)break;
    if(IOT_Char_Rx[cpu_rx_ring_wr] == 'u'){
      if(IOT_Char_Rx[cpu_rx_ring_wr - POSIT_1] == 's'){
        i = ALWAYS;
      }
    }
    k = cpu_rx_ring_wr;
    cpu_rx_ring_wr++;
  }
  
  // Output SSID to LCD 
  display_1[POSIT_0] = ' '; 
  display_1[POSIT_1] = ' ';
  display_1[POSIT_2] = ' ';
  display_1[POSIT_3] = IOT_Char_Rx[k-POSIT_3];
  display_1[POSIT_4] = IOT_Char_Rx[k-POSIT_2];
  display_1[POSIT_5] = IOT_Char_Rx[k-POSIT_1];
  display_1[POSIT_6] = IOT_Char_Rx[k];
  display_1[POSIT_7] = ' ';
  display_1[POSIT_8] = ' ';
  display_1[POSIT_9] = ' ';
  
  Display_Process();
  cpu_rx_ring_wr = ORIGINAL;
  k = ORIGINAL;
  Five_Msec_Delay(500);
  
  
  //---------Get ip address---------------------------------------------------
  display_2 = "          ";
  display_2[POSIT_0] = ' '; 
  display_2[POSIT_1] = ' ';
  display_2[POSIT_2] = 'i';
  display_2[POSIT_3] = 'p';
  display_2[POSIT_4] = 'a';
  display_2[POSIT_5] = 'd';
  display_2[POSIT_6] = 'd';
  display_2[POSIT_7] = 'r';
  display_2[POSIT_8] = ' ';
  display_2[POSIT_9] = ' ';
  Display_Process(); 
  X_Seconds_Delay(POSIT_2);
 
  Check_Status(); 
  Five_Msec_Delay(25);
  cpu_rx_ring_wr = ORIGINAL;
  i = ORIGINAL;
  UCA1IE &= ~UCRXIE;             // Disable RX interrupt
  
  // Parsing through Rx array until ip_addr is reached 
  while(ALWAYS){
    if(i)break; 
    if(IOT_Char_Rx[cpu_rx_ring_wr] == 'i'){
      if(IOT_Char_Rx[cpu_rx_ring_wr+POSIT_1] == 'p'){
        if(IOT_Char_Rx[cpu_rx_ring_wr+POSIT_2] == 'a'){
          i = ALWAYS; 
          j = cpu_rx_ring_wr; 
          Display_Process(); 
          Five_Msec_Delay(20);
        }
      } 
    }
    cpu_rx_ring_wr++;
  }
  cpu_rx_ring_wr = ORIGINAL;
  k = j + POSIT_9;
  
  for(int inc=ORIGINAL; inc<=POSIT_9; inc++)display_3[inc] = ' '; 
  Display_Process(); 
  X_Seconds_Delay(POSIT_2);
  
  // Output ip address to LCD 
  display_3[POSIT_0] = ' '; 
  display_3[POSIT_1] = ' ';
  display_3[POSIT_2] = IOT_Char_Rx[k];
  display_3[POSIT_3] = IOT_Char_Rx[k+POSIT_1];
  display_3[POSIT_4] = IOT_Char_Rx[k+POSIT_2];
  display_3[POSIT_5] = IOT_Char_Rx[k+POSIT_3];
  display_3[POSIT_6] = IOT_Char_Rx[k+POSIT_4];
  display_3[POSIT_7] = IOT_Char_Rx[k+POSIT_5];
  display_3[POSIT_8] = ' ';
  display_3[POSIT_9] = ' '; 
  Display_Process();
  X_Seconds_Delay(POSIT_2); 
  Five_Msec_Delay(500);
  
  display_4 = "          ";
  display_4[POSIT_0] = ' '; 
  display_4[POSIT_1] = ' ';
  display_4[POSIT_2] = IOT_Char_Rx[k+POSIT_6];
  display_4[POSIT_3] = IOT_Char_Rx[k+POSIT_7];
  display_4[POSIT_4] = IOT_Char_Rx[k+POSIT_8];
  display_4[POSIT_5] = IOT_Char_Rx[k+POSIT_9];
  display_4[POSIT_6] = IOT_Char_Rx[k+POSIT_10];
  display_4[POSIT_7] = IOT_Char_Rx[k+POSIT_11];
  display_4[POSIT_8] = ' ';
  display_4[POSIT_9] = ' ';
  Display_Process(); 
  UCA1IE |= UCRXIE;                 // Re-Enable RX interrupt
  Five_Msec_Delay(500);

  // Waiting until "OK" has been received 
  i = ORIGINAL;
  while(IOT_Char_Rx[i] != 'O')i++; 
  
  //---------Ping lab computer------------------------------------------------ 
  Ping(); 
  cpu_rx_ring_wr = ORIGINAL;
  i = ORIGINAL;
  X_Seconds_Delay(POSIT_1);
  
  // Waiting until "OK" has been received 
  i = ORIGINAL;
  while(IOT_Char_Rx[i] != 'O')i++; 
}

//*****************************************************************************
//      Function name: Listen
//      Description: Configuration for IOT device on ncsu wifi  
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Listen(void){
  int inc = ORIGINAL;
  int i = ORIGINAL;
  char j = ' '; 
  char pin[POSIT_4] = "0124";
  char time[POSIT_4]; 
  int t; 
  lcd_BIG_mid();
  
  // initializing receive buffer
  for(int j1=POSIT_0; j1<SMALL_RING_SIZE; j1++)IOT_Char_Rx[j1]=POSIT_0;
   
  //----Receiving commands-------
  // Waiting until start command sequence identifier is seen 
  while(ALWAYS){
    if(IOT_Char_Rx[inc] == '*')break; 
    inc++;
  }
  i = ORIGINAL;
  
  // Examining for unique pin 
  while(ALWAYS){
    if(i)break;
    if(IOT_Char_Rx[inc] == pin[POSIT_0]){
      if(IOT_Char_Rx[inc+POSIT_1] == pin[POSIT_1]){
        if(IOT_Char_Rx[inc+POSIT_2] == pin[POSIT_2]){
          if(IOT_Char_Rx[inc+POSIT_3] == pin[POSIT_3]){
            i = ALWAYS;
          }
        }
      }
    }
    inc++;
  }
  i = ORIGINAL;
  inc = ORIGINAL;
  
  // Examining for direction type 
  while(ALWAYS){
    if(i)break; 
    j = IOT_Char_Rx[inc];
    switch(j){
    case 'F':
      Out_To_LCD("",POSIT_0,"Forward",POSIT_0,"",POSIT_0,"",POSIT_0);
      i = ALWAYS;
      break; 
    case 'B': 
      Out_To_LCD("",POSIT_0,"Backward",POSIT_0,"",POSIT_0,"",POSIT_0);
      i = ALWAYS;
      break; 
    case 'R':
      Out_To_LCD("",POSIT_0,"Right",POSIT_0,"",POSIT_0,"",POSIT_0);
      i = ALWAYS;
      break; 
    case 'L':
      Out_To_LCD("",POSIT_0,"Left",POSIT_0,"",POSIT_0,"",POSIT_0);
      i = ALWAYS;
      break; 
    }
    inc++; 
  }
  i = ORIGINAL;
  inc = ORIGINAL;
  
  // Examining for time units 
  while(ALWAYS){
    if(i)break;
    
    /* logic: time units occur after direction letter, so if the character 
     is bigger than 0x040, then it's a letter and can proceed to calculating
     time units */
    if(IOT_Char_Rx[inc] > LET_MIN){
      time[POSIT_0] = IOT_Char_Rx[inc+POSIT_1];  
      time[POSIT_1] = IOT_Char_Rx[inc+POSIT_2]; 
      time[POSIT_2] = IOT_Char_Rx[inc+POSIT_3]; 
      time[POSIT_3] = IOT_Char_Rx[inc+POSIT_4]; 
      i = ALWAYS;
    }
    inc++; 
  }
  i = ORIGINAL; 
  inc = ORIGINAL;
  
  // Converting time units from char to hex 
  inc = time[POSIT_0] - NUM_BASE;
  t = inc*1000; 
  inc = time[POSIT_1] - NUM_BASE;
  t = t+(inc*100); 
  inc = time[POSIT_2] - NUM_BASE;
  t = t+(inc*10); 
  inc = time[POSIT_3] - NUM_BASE;
  t = t+inc;

  // Proceeding with direction for number of time units 
  switch(j){
  case 'F':
    milli_counter = ORIGINAL;
    while(milli_counter < t){
      Left_Forward_On();
      Right_Forward_On();
    }
    Left_Forward_Off();
    Right_Forward_Off();
    break; 
  case 'B': 
    milli_counter = ORIGINAL;
    while(milli_counter < t){
      Left_Reverse_On();
      Right_Reverse_On();
    }
    Left_Reverse_Off();
    Right_Reverse_Off();
    break; 
  case 'R':
    milli_counter = ORIGINAL;
    while(milli_counter < t){
      Left_Forward_On();
      Right_Reverse_On();
    }
    Left_Forward_Off();
    Right_Reverse_Off();
    break; 
  case 'L':
    milli_counter = ORIGINAL;
    while(milli_counter < t){
      Left_Reverse_On();
      Right_Forward_On();
    }
    Left_Reverse_Off();
    Right_Forward_Off();
    break; 
  }
  

}

//*****************************************************************************
//      Function name: Set_SSID 
//      Description: Setting SSID 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Set_SSID(void){
  int i = ORIGINAL;
  char sSSID[SMALL_RING_SIZE] = "AT+S.SSIDTXT=ncsu\r"; 
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Set SSID", POSIT_0, "", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = sSSID[i]; 
    if(sSSID[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
}

//*****************************************************************************
//      Function name: Get_SSID
//      Description: Getting SSID 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Get_SSID(void){
  int i = ORIGINAL;
  char gSSID[SMALL_RING_SIZE] = "AT+S.SSIDTXT\r"; 
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Get SSID", POSIT_0, "", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = gSSID[i]; 
    if(gSSID[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_2);
}

//*****************************************************************************
//      Function name: Set_HostN
//      Description: Sets host name 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Set_HostN(void){
  int i = ORIGINAL;
  char sHostN[SMALL_RING_SIZE] = "AT+S.SCFG=ip_hostname,ECE-306_02_R\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Set", POSIT_0, "hostname", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = sHostN[i]; 
    if(sHostN[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Get_HostN
//      Description: Gets host name 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Get_HostN(void){
  int i = ORIGINAL;
  char gHostN[SMALL_RING_SIZE] = "AT+S.SCFG=ip_hostname\r";  
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Get", POSIT_0, "hostname", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = gHostN[i]; 
    if(gHostN[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
}

//*****************************************************************************
//      Function name: Set_NetP
//      Description: Setting network privacy mode 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Set_NetP(void){
  int i = ORIGINAL;
  char sNetP[SMALL_RING_SIZE] = "AT+S.SCFG=wifi_priv_mode,0\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Set", POSIT_0, "network", POSIT_0, "privacy", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = sNetP[i]; 
    if(sNetP[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Get_NetP
//      Description: Get network privacy mode  
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Get_NetP(void){
  int i = ORIGINAL;
  char gNetP[SMALL_RING_SIZE] = "AT+S.SCFG=wifi_priv_mode\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Get", POSIT_0, "network", POSIT_0, "privacy", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = gNetP[i]; 
    if(gNetP[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Set_NetM
//      Description: Setting network mode 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Set_NetM(void){
  int i = ORIGINAL;
  char sNetM[SMALL_RING_SIZE] = "AT+S.SCFG=wifi_mode,1\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Set", POSIT_0, "network", POSIT_0, "mode", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = sNetM[i]; 
    if(sNetM[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Get_NetM
//      Description: Getting network mode 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Get_NetM(void){
  int i = ORIGINAL;
  char gNetM[SMALL_RING_SIZE] = "AT+S.SCFG=wifi_mode\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Get", POSIT_0, "network", POSIT_0, "mode", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = gNetM[i]; 
    if(gNetM[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Save_All
//      Description: Save the settings on the flash memory   
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Save_All(void){
  int i = ORIGINAL;
  char save[SMALL_RING_SIZE] = "AT&W\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Save", POSIT_0, "settings", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = save[i]; 
    if(save[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Reset_All 
//      Description: Resets the module 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Reset_All(void){
  int i = ORIGINAL;
  char reset[SMALL_RING_SIZE] = "AT+CFUN=1\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Reset", POSIT_0, "module", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = reset[i]; 
    if(reset[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
} 

//*****************************************************************************
//      Function name: Roam
//      Description: Sets up roaming for wifi 
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Roam(void){
  int i = ORIGINAL;
  char roam[SMALL_RING_SIZE] = "AT+S.ROAM\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
  Out_To_LCD("Roaming...", POSIT_0, "", POSIT_0, "", POSIT_0, "", POSIT_0); 
  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = roam[i]; 
    if(roam[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
}

//*****************************************************************************
//      Function name: Check_Status
//      Description: Gets ip address  
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Check_Status(void){
  int i = ORIGINAL;
  char check[SMALL_RING_SIZE] = "AT+S.STS=ip_ipaddr\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = check[i]; 
    if(check[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
}

//*****************************************************************************
//      Function name: Ping
//      Description: Pings lab computer   
//      Global variables: 
//      Local variables:  
//      Return: VOID
//*****************************************************************************
void Ping(void){
  int i = ORIGINAL;
  char ping[SMALL_RING_SIZE] = "AT+S.PING= 152.14.99.126\r";
  
  // initializing receive buffer
  for(int j=POSIT_0; j<SMALL_RING_SIZE; j++)IOT_Char_Rx[j]=POSIT_0;
  
  // Updating display 
//  Out_To_LCD("Ping", POSIT_0, "lab", POSIT_0, "computer", POSIT_0, "", POSIT_0); 
//  Display_Process();
  
  // Transmitting commands 
  while(ALWAYS){
    UCA1TXBUF = UCA0TXBUF = ping[i]; 
    if(ping[i] == CAR_RET)break; 
    Five_Msec_Delay(POSIT_1); 
    i++;
  }
  Five_Msec_Delay(POSIT_5);
}