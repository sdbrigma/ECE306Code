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
      
      //_Bool hitNine = FALSE;
      unsigned int receiveTMP[SW_SEL_10];
      unsigned int restoreTMP = HEX_ZERO;
      
        receiveTMP[SW_SEL_0] = HEX_ZERO;
        receiveTMP[SW_SEL_1] = HEX_ZERO;
        receiveTMP[SW_SEL_2] = HEX_ZERO;
        receiveTMP[SW_SEL_3] = HEX_ZERO;
        receiveTMP[SW_SEL_4] = HEX_ZERO;
        receiveTMP[SW_SEL_5] = HEX_ZERO;
        receiveTMP[SW_SEL_6] = HEX_ZERO;
        receiveTMP[SW_SEL_7] = HEX_ZERO;
        receiveTMP[SW_SEL_8] = HEX_ZERO;
        receiveTMP[SW_SEL_9] = HEX_ZERO;
        
        UCA1TXBUF = TILDE;
  
  while (ALWAYS) {   
      
      receiveTMP[SW_SEL_0] = RX_Char;
      
            if ((receiveTMP[SW_SEL_0] ==  HEX_A) 
               || (receiveTMP[SW_SEL_0] == HEX_B) 
                 || (receiveTMP[SW_SEL_0] == HEX_C) 
                   || (receiveTMP[SW_SEL_0] == HEX_D) 
                     || (receiveTMP[SW_SEL_0] == HEX_E) 
                       || (receiveTMP[SW_SEL_0] == HEX_F) ){
                       receiveTMP[SW_SEL_0] -= HEX_SBTRCT;
                       }
      
      if ((receiveTMP[SW_SEL_0] == TILDE)||(receiveTMP[SW_SEL_0] == INITIAL)) {
        receiveTMP[SW_SEL_0] = HEX_ZERO;
        receiveTMP[SW_SEL_1] = HEX_ZERO;
        receiveTMP[SW_SEL_2] = HEX_ZERO;
        receiveTMP[SW_SEL_3] = HEX_ZERO;
        receiveTMP[SW_SEL_4] = HEX_ZERO;
        receiveTMP[SW_SEL_5] = HEX_ZERO;
        receiveTMP[SW_SEL_6] = HEX_ZERO;
        receiveTMP[SW_SEL_7] = HEX_ZERO;
        receiveTMP[SW_SEL_8] = HEX_ZERO;
        receiveTMP[SW_SEL_9] = HEX_ZERO;

        Five_msec_Delay(SW_SEL_1);
        
        receiveTMP[SW_SEL_0] = RX_Char;
        
        if (receiveTMP[SW_SEL_0] == HEX_SEVEN) {
          
          receiveTMP[SW_SEL_0] = hexToInt(receiveTMP[SW_SEL_0]);
          receiveTMP[SW_SEL_0]++;
          receiveTMP[SW_SEL_0] = intToHex(receiveTMP[SW_SEL_0]);
          if ((receiveTMP[SW_SEL_0] <= HEX_TEN) || (receiveTMP[SW_SEL_0] == TILDE)) UCA1TXBUF = receiveTMP[SW_SEL_0];
        }
        else {
          UCA1TXBUF = TILDE;
          Five_msec_Delay(LIL_DELAY);
          receiveTMP[SW_SEL_0] = hexToInt(receiveTMP[SW_SEL_0]);
          receiveTMP[SW_SEL_0]++;
          receiveTMP[SW_SEL_0] = intToHex(receiveTMP[SW_SEL_0]);
          if ((receiveTMP[SW_SEL_0] <= HEX_TEN) || (receiveTMP[SW_SEL_0] == TILDE)) UCA1TXBUF = receiveTMP[SW_SEL_0];
        } 
      }
      else if ((receiveTMP[SW_SEL_0] ==  HEX_ZERO) 
               || (receiveTMP[SW_SEL_0] == HEX_ONE) 
                 || (receiveTMP[SW_SEL_0] == HEX_TWO) 
                   || (receiveTMP[SW_SEL_0] == HEX_THREE) 
                     || (receiveTMP[SW_SEL_0] == HEX_FOUR) 
                       || (receiveTMP[SW_SEL_0] == HEX_FIVE) 
                         || (receiveTMP[SW_SEL_0] == HEX_SIX)
                           || (receiveTMP[SW_SEL_0] == HEX_SEVEN) 
                             || (receiveTMP[SW_SEL_0] == HEX_EIGHT)
                               || (receiveTMP[SW_SEL_0] == HEX_NINE)) {

       //Convert to integer  
       restoreTMP = receiveTMP[SW_SEL_0];
                                 
       receiveTMP[SW_SEL_0] = hexToInt(receiveTMP[SW_SEL_0]);
       receiveTMP[SW_SEL_1] = hexToInt(receiveTMP[SW_SEL_1]);
       receiveTMP[SW_SEL_2] = hexToInt(receiveTMP[SW_SEL_2]);
       receiveTMP[SW_SEL_3] = hexToInt(receiveTMP[SW_SEL_3]);
       receiveTMP[SW_SEL_4] = hexToInt(receiveTMP[SW_SEL_4]);
       receiveTMP[SW_SEL_5] = hexToInt(receiveTMP[SW_SEL_5]);
       receiveTMP[SW_SEL_6] = hexToInt(receiveTMP[SW_SEL_6]);
       receiveTMP[SW_SEL_7] = hexToInt(receiveTMP[SW_SEL_7]);
       receiveTMP[SW_SEL_8] = hexToInt(receiveTMP[SW_SEL_8]);
       receiveTMP[SW_SEL_9] = hexToInt(receiveTMP[SW_SEL_9]);
                       
       // Add one
       receiveTMP[SW_SEL_0]++;  
        
       
       if (receiveTMP[SW_SEL_1] == SW_SEL_9) {
         receiveTMP[SW_SEL_2]++;
         receiveTMP[SW_SEL_1] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_2] == SW_SEL_9) {
         receiveTMP[SW_SEL_3]++;
         receiveTMP[SW_SEL_2] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_3] == SW_SEL_9) {
         receiveTMP[SW_SEL_4]++;
         receiveTMP[SW_SEL_3] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_5] == SW_SEL_9) {
         receiveTMP[SW_SEL_6]++;
         receiveTMP[SW_SEL_5] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_6] == SW_SEL_9) {
         receiveTMP[SW_SEL_7]++;
         receiveTMP[SW_SEL_6] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_7] == SW_SEL_9) {
         receiveTMP[SW_SEL_8]++;
         receiveTMP[SW_SEL_7] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_8] == SW_SEL_9) {
         receiveTMP[SW_SEL_9]++;
         receiveTMP[SW_SEL_8] = SW_SEL_0;
       }
       if (receiveTMP[SW_SEL_9] == SW_SEL_9) {
         receiveTMP[SW_SEL_0] = SW_SEL_0;
         receiveTMP[SW_SEL_1] = SW_SEL_0;
         receiveTMP[SW_SEL_2] = SW_SEL_0;
         receiveTMP[SW_SEL_3] = SW_SEL_0;
         receiveTMP[SW_SEL_4] = SW_SEL_0;
         receiveTMP[SW_SEL_5] = SW_SEL_0;
         receiveTMP[SW_SEL_6] = SW_SEL_0;
         receiveTMP[SW_SEL_7] = SW_SEL_0;
         receiveTMP[SW_SEL_8] = SW_SEL_0;
         receiveTMP[SW_SEL_9] = SW_SEL_0;
       }

//       if (receiveTMP[SW_SEL_0] >= HEX_Bnorm) {
//         receiveTMP[SW_SEL_0] = SW_SEL_9;
//       }
       
       if (receiveTMP[SW_SEL_0] >= HEX_Anorm) {
         receiveTMP[SW_SEL_0] = SW_SEL_0;
         receiveTMP[SW_SEL_1]++;
       }


                                    
        // Convert to ASCII
        receiveTMP[SW_SEL_0] = intToHex(receiveTMP[SW_SEL_0]);
        receiveTMP[SW_SEL_1] = intToHex(receiveTMP[SW_SEL_1]);
        receiveTMP[SW_SEL_2] = intToHex(receiveTMP[SW_SEL_2]);
        receiveTMP[SW_SEL_3] = intToHex(receiveTMP[SW_SEL_3]);
        receiveTMP[SW_SEL_4] = intToHex(receiveTMP[SW_SEL_4]);
        receiveTMP[SW_SEL_5] = intToHex(receiveTMP[SW_SEL_5]);
        receiveTMP[SW_SEL_6] = intToHex(receiveTMP[SW_SEL_6]);
        receiveTMP[SW_SEL_7] = intToHex(receiveTMP[SW_SEL_7]);
        receiveTMP[SW_SEL_8] = intToHex(receiveTMP[SW_SEL_8]);
        receiveTMP[SW_SEL_9] = intToHex(receiveTMP[SW_SEL_9]);
                       
        if ((receiveTMP[SW_SEL_0] <= HEX_TEN) || (receiveTMP[SW_SEL_0] == TILDE)) UCA1TXBUF = receiveTMP[SW_SEL_0];
                       
        display_3[SW_SEL_0] = receiveTMP[SW_SEL_9];
        display_3[SW_SEL_1] = receiveTMP[SW_SEL_8];
        display_3[SW_SEL_2] = receiveTMP[SW_SEL_7];
        display_3[SW_SEL_3] = receiveTMP[SW_SEL_6];
        display_3[SW_SEL_4] = receiveTMP[SW_SEL_5];
        display_3[SW_SEL_5] = receiveTMP[SW_SEL_4];
        display_3[SW_SEL_6] = receiveTMP[SW_SEL_3];
        display_3[SW_SEL_7] = receiveTMP[SW_SEL_2];
        display_3[SW_SEL_8] = receiveTMP[SW_SEL_1];
        display_3[SW_SEL_9] = receiveTMP[SW_SEL_0];
        
      }
      else {
          //UCA1TXBUF = restoreTMP;
      }
      
      
      if (!(P4IN & SW1)){
        receiveTMP[SW_SEL_0] = HEX_ZERO;
        receiveTMP[SW_SEL_1] = HEX_ZERO;
        receiveTMP[SW_SEL_2] = HEX_ZERO;
        receiveTMP[SW_SEL_3] = HEX_ZERO;
        receiveTMP[SW_SEL_4] = HEX_ZERO;
        receiveTMP[SW_SEL_5] = HEX_ZERO;
        receiveTMP[SW_SEL_6] = HEX_ZERO;
        receiveTMP[SW_SEL_7] = HEX_ZERO;
        receiveTMP[SW_SEL_8] = HEX_ZERO;
        receiveTMP[SW_SEL_9] = HEX_ZERO;
        
        UCA1TXBUF = TILDE;
        Five_msec_Delay(LIL_DELAY);
        UCA1TXBUF = receiveTMP[SW_SEL_0];
      }
      if (!(P4IN & SW2)){
        break;
      }
      receiveEnable = FALSE;
      Display_Process();
      Five_msec_Delay(BIG_DELAY+LIL_DELAY);

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