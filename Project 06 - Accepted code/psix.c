//******************************************************************************
//
//  Description: This file is used to implement the test code for project 6
//
//
//  Christopher Woedy
//  Oct 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Project_6(void){
//******************************************************************************
//
//  Description: This file is used to implement the test code for project 6
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: RX_Char
//
// Passed: 
//
// Local: receiveTMP[SW_SEL_10]
//
// Return: VOID
//
//****************************************************************************** 
  
      Init_Serial_UCA1(TRUE);
  
      display_1 = "----------";
      posL1 = LINE_POS_L0;
      display_2 = " Counter: ";
      posL2 = LINE_POS_L0;
      display_3 = "          ";
      posL3 = LINE_POS_L0;
      display_4 =  "----------";
      posL4 = LINE_POS_L0;
      Display_Process();
      
	  char packet1 = INITIAL;
 	  char packet2 = INITIAL;
          RX_Char[LINE_POS_L0] = INITIAL;
          RX_Char[LINE_POS_L1] = INITIAL;
	  unsigned int tmpPacket = INITIAL;
	  unsigned int count = INITIAL;
	  
      while (ALWAYS) {
        
       	  UCA1TXBUF = packet1;
	  Five_msec_Delay(SW_SEL_1);
       	  UCA1TXBUF = packet2;
	  Five_msec_Delay(SW_SEL_1);
        
	  packet1 = RX_Char[LINE_POS_L0];
	  packet2 = RX_Char[LINE_POS_L1];
	  
          count = packet2;
          count <<= SHIFT_8;
          count |= packet1; 
          count++;
          hexToInt(count);
          
          packet1 = (char) count;
          tmpPacket = count >> SHIFT_8;
          packet2 = (char) tmpPacket;
          
       	  UCA1TXBUF = packet1;
	  Five_msec_Delay(SW_SEL_1);
       	  UCA1TXBUF = packet2;
	  Five_msec_Delay(SW_SEL_1);
          	  
	  
     if (!(P4IN & SW1)){
        packet1 = INITIAL;
        packet2 = INITIAL;
        count = INITIAL;
        tmpPacket = INITIAL;
        RX_Char[LINE_POS_L0] = INITIAL;
        RX_Char[LINE_POS_L1] = INITIAL;
      }	  
     if (!(P4IN & SW2)){
        break;
      }
     Display_Process();
     Five_msec_Delay(BIGGER_DELAY);
 }
                
      display_1 = "P. Six";
      posL1 = LINE_POS_L2;
      display_2 = "Complete!";
      posL2 = LINE_POS_L1;
      display_3 = "          ";
      posL3 = LINE_POS_L0;
      display_4 =  "          ";
      posL4 = LINE_POS_L0;
      Display_Process();
      
}