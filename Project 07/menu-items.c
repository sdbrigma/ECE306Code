//******************************************************************************
//
//  Description: This file contains the functions to display repetitive
//  strings to the LCD screen
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Configuration(void){
//******************************************************************************
//
//  Description: This file updates the menu element based on selection
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4
//
// Local:
//
// Return: VOID
//
//******************************************************************************  
  
  sw_select = LINE_POS_L1;
  display_1 = "Calibrate ";
  posL1 = LINE_POS_L0;
  display_2 = "IOT Config";
  posL2 = LINE_POS_L0;
  display_3 = " IOT CMD  ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
}

void IOT_Commands(void){
//******************************************************************************
//
//  Description: This file updates the menu element based on selection
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4
//
// Local:
//
// Return: VOID
//
//******************************************************************************  
  
  sw_select = LINE_POS_L2;
  display_1 = "IOT Config";
  posL1 = LINE_POS_L0;
  display_2 = " IOT CMD  ";
  posL2 = LINE_POS_L0;
  display_3 = "Back Door ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
}

void backdoorDisplay(void){
//******************************************************************************
//
//  Description: This file updates the menu element based on selection
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4
//
// Local:
//
// Return: VOID
//
//******************************************************************************  
  
  sw_select = LINE_POS_L3;
  display_1 = " IOT CMD  ";
  posL1 = LINE_POS_L0;
  display_2 = "Back Door ";
  posL2 = LINE_POS_L0;
  display_3 = "  Detect  ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
}

void IOTDetect(void){
//******************************************************************************
//
//  Description: This file updates the menu element based on selection
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4
//
// Local:
//
// Return: VOID
//
//******************************************************************************  
  
  sw_select = LINE_POS_L4;
  display_1 = "Back Door ";
  posL1 = LINE_POS_L0;
  display_2 = "  Detect  ";
  posL2 = LINE_POS_L0;
  display_3 = "Calibrate ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
}

void calibrationDisplay(void){
//******************************************************************************
//
//  Description: This file updates the menu element based on selection
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4
//
// Local:
//
// Return: VOID
//
//******************************************************************************  
  
  sw_select = LINE_POS_L5;
  display_1 = "  Detect  ";
  posL1 = LINE_POS_L0;
  display_2 = "Calibrate ";
  posL2 = LINE_POS_L0;
  display_3 = "IOT Config";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
}

void formatDisplay(void){
//******************************************************************************
//
//  Description: This file updates the menu element based on selection
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals:
//
// Passed: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4
//
// Local:
//
// Return: VOID
//
//******************************************************************************  
  
  sw_select = LINE_POS_L1;
  display_1 = "----------";
  posL1 = LINE_POS_L0;
  display_2 = "          ";
  posL2 = LINE_POS_L0;
  display_3 = "----------";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
}

void bufferDisplay(void){
//******************************************************************************
//
//  Description: This function is used to test serial communcation lines
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: RX_Char
//
// Passed: 
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 
  
  unsigned volatile int i = ZERO;
  unsigned volatile int index = ZERO;
  int OLD_ADC_Thumb;
  display_1 = "----------";
  display_2 = "          ";
  display_3 = "----------";
  display_4 = "          ";
  posL1 = LINE_POS_L0;
  posL2 = LINE_POS_L0;
  posL3 = LINE_POS_L0;
  posL4 = LINE_POS_L0;
  big = ALWAYS;
  lcd_BIG_mid();
  
  while(ALWAYS) {
	// Update all ADC channels
	  for(i = LINE_POS_L5; i > ZERO; i--) {
	  ADC_Process();
	  }
	  
          // Only update when moving in the positive direction
          if (OLD_ADC_Thumb < ZERO) OLD_ADC_Thumb = LINE_POS_L1;
          if ((ADC_Thumb < OLD_ADC_Thumb - LINE_POS_L1) && (ADC_Thumb > LINE_POS_L1)) {
              index+=LINE_POS_L2; 
          }
          
          if (receiveEnable) {
            UCA1IE |= UCTXIE;                       // Enable TX interrupt
            UCA1IE |= UCRXIE;	                    // Enable RX interrupt 
          }
          
          if (index > Index30) index = ZERO;
          
          // Sets previous thumbwheel value
          OLD_ADC_Thumb = ADC_Thumb - LINE_POS_L6;
              
          // Scroll Fight Song
          display_2[LINE_POS_L0] = RX_Char[index];
          display_2[LINE_POS_L1] = RX_Char[index + LINE_POS_L1];
          display_2[LINE_POS_L2] = RX_Char[index + LINE_POS_L2];
          display_2[LINE_POS_L3] = RX_Char[index + LINE_POS_L3];
          display_2[LINE_POS_L4] = RX_Char[index + LINE_POS_L4];
          display_2[LINE_POS_L5] = RX_Char[index + LINE_POS_L5];
          display_2[LINE_POS_L6] = RX_Char[index + LINE_POS_L6];
          display_2[LINE_POS_L7] = RX_Char[index + LINE_POS_L7];
          display_2[LINE_POS_L8] = RX_Char[index + LINE_POS_L8];
          display_2[LINE_POS_L9] = RX_Char[index + LINE_POS_L9];
 
          // Update LCD Display
	  Display_Process();
	  Five_msec_Delay(small_delay);
		
          // Clean before return
          if (!(P4IN & SW2)) {
            Five_msec_Delay(small_delay);
            display_1 = "          ";
            display_2 = "          ";
            display_3 = "          ";
            display_4 = "          ";
            break;
          }
      }  
}