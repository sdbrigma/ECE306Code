//******************************************************************************
//
//  Description: This file is used to implement the test code for project 4
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Homework_7(void){
//******************************************************************************
//
//  Description: This file is used to implement the test code for project 4
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: display_1, display_2, display_3, display_4, posL1, posL2, posL3, 
// posL4, Time_Sequence, A0_time_count, buadToggle, transmitEnable, 
// receiveEnable, TX_Char[], RX_Char[], Time_Sequence, A0_Time_Count
//
// Passed: 
//
// Local: temp
//
// Return: VOID
//
//****************************************************************************** 

  unsigned int temp = INITIAL;
  
// Initial Display Set
  display_1 = "Switch Two";
  posL1 = LINE_POS_L0;
  display_2 = "  toggles ";
  posL2 = LINE_POS_L0;
  display_3 = "Baud Rates";
  posL3 = LINE_POS_L0;
  display_4 = "__________";
  posL4 = LINE_POS_L0;
  big = INITIAL;
  Display_Process();
  
  A0_time_count = INITIAL;  
  // Pause
  while(A0_time_count <= THREE_HALF_SEC_COUNT);
  A0_time_count = INITIAL;

  display_1 = "          ";
  posL1 = LINE_POS_L0;
  display_2 = "          ";
  posL2 = LINE_POS_L0;
  display_3 = "   Baud:  ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  Display_Process();

  while (ALWAYS)  {
  
  if (!(P4IN & SW1)){
          return;								// Leave Function
    }
  if (!(P4IN & SW2)) {
    Five_msec_Delay(LIL_SW_DELAY);      // 'debounce' delay
    transmitEnable = FALSE;				// Disable TX
    baudToggle ^= TRUE;					// 9600 or 115200
    Init_Serial_UCA1(baudToggle);       // Initialize USCI-Baud Rate
 
    if (baudToggle) {
      display_3 = "   Baud:  ";
      posL3 = LINE_POS_L0;
      display_4 = "   9600   ";
      posL4 = LINE_POS_L0;
    }
    else {
      display_3 = "   Baud:  ";
      posL3 = LINE_POS_L0;
      display_4 = "  115200  ";
      posL4 = LINE_POS_L0;      
    }
      
      display_1[LINE_POS_L9] = ' ';      
      
// Re-Enable TX
  transmitEnable = TRUE;
  Display_Process();
  }

      if (transmitEnable) { 
        // Transmit
          temp = txWrite++;
          UCA1TXBUF = TX_Char[temp];
          if (txWrite >= (SW_SEL_8)) {
            txWrite = INITIAL;
          }
          
		// Display with Marquee Shift
          display_1[LINE_POS_L0] = display_1[LINE_POS_L1];
          display_1[LINE_POS_L1] = display_1[LINE_POS_L2];
          display_1[LINE_POS_L2] = display_1[LINE_POS_L3];
          display_1[LINE_POS_L3] = display_1[LINE_POS_L4];
          display_1[LINE_POS_L4] = display_1[LINE_POS_L5];
          display_1[LINE_POS_L5] = display_1[LINE_POS_L6];
          display_1[LINE_POS_L6] = display_1[LINE_POS_L7];
          display_1[LINE_POS_L7] = display_1[LINE_POS_L8];
          display_1[LINE_POS_L8] = display_1[LINE_POS_L9];
          display_1[LINE_POS_L9] = RX_Char[LINE_POS_L0];
          
            display_2 = "          ";
            posL2 = LINE_POS_L0;
            
			// Receive continuously re-enabled by USCI A1 ISR
            receiveEnable = FALSE;
      }
	  
Display_Process();        		// Update LCD Display
      
  TX_Char[LINE_POS_L0] = 'N';
  TX_Char[LINE_POS_L1] = 'C';
  TX_Char[LINE_POS_L2] = 'S';
  TX_Char[LINE_POS_L3] = 'U';
  TX_Char[LINE_POS_L4] = ' ';
  TX_Char[LINE_POS_L5] = ' ';
  TX_Char[LINE_POS_L6] = '#';
  TX_Char[LINE_POS_L7] = '1';

  if (!receiveEnable) {
  RX_Char[LINE_POS_L0] = ' ';
  }
   
  if(Time_Sequence > CASE250){                  // Fail-safe for clock
    Time_Sequence = INITIAL;
  }
  if (A0_time_count > FIVE_SEC_COUNT) {
    A0_time_count = INITIAL;
  }

      A0_time_count = INITIAL;
      while(A0_time_count <= HALF_SEC_COUNT);
      A0_time_count = INITIAL;	  
}
}