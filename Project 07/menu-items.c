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

void Display_Config(void){
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
  
  switch_select = SW_SEL_1;
  display_1 = "Calibrate ";
  posL1 = LINE_POS_L0;
  display_2 = "IOT Config";
  posL2 = LINE_POS_L0;
  display_3 = " IOT CMD  ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
}

void Display_IOTCMD(void){
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
  
  switch_select = SW_SEL_2;
  display_1 = "IOT Config";
  posL1 = LINE_POS_L0;
  display_2 = " IOT CMD  ";
  posL2 = LINE_POS_L0;
  display_3 = "Back Door ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
}

void Display_Backdoor(void){
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
  
  switch_select = SW_SEL_3;
  display_1 = " IOT CMD  ";
  posL1 = LINE_POS_L0;
  display_2 = "Back Door ";
  posL2 = LINE_POS_L0;
  display_3 = "  Detect  ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
}

void Display_Detect(void){
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
  
  switch_select = SW_SEL_4;
  display_1 = "Back Door ";
  posL1 = LINE_POS_L0;
  display_2 = "  Detect  ";
  posL2 = LINE_POS_L0;
  display_3 = "Calibrate ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
}

void Display_Calibrate(void){
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
  
  switch_select = SW_SEL_5;
  display_1 = "  Detect  ";
  posL1 = LINE_POS_L0;
  display_2 = "Calibrate ";
  posL2 = LINE_POS_L0;
  display_3 = "IOT Config";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
}

void Display_Format(void){
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
  
  switch_select = SW_SEL_1;
  display_1 = "----------";
  posL1 = LINE_POS_L0;
  display_2 = "          ";
  posL2 = LINE_POS_L0;
  display_3 = "----------";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
}

void Display_Buffer(void){
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
  
  unsigned volatile int i = INITIAL;
  unsigned volatile int index = INITIAL;
  int OLD_ADC_Thumb;
  display_1 = "----------";
  display_2 = "          ";
  display_3 = "----------";
  display_4 = "          ";
  posL1 = LINE_POS_L0;
  posL2 = LINE_POS_L0;
  posL3 = LINE_POS_L0;
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  
  while(ALWAYS) {
	// Update all ADC channels
	  for(i = SW_SEL_5; i > INITIAL; i--) {
	  ADC10_Process();
	  }
	  
          // Only update when moving in the positive direction
          if (OLD_ADC_Thumb < INITIAL) OLD_ADC_Thumb = SW_SEL_1;
          if ((ADC_Thumb < OLD_ADC_Thumb - SW_SEL_1) && (ADC_Thumb > SW_SEL_1)) {
              index+=Pos2; 
          }
          
          if (receiveEnable) {
            UCA1IE |= UCTXIE;                       // Enable TX interrupt
            UCA1IE |= UCRXIE;	                    // Enable RX interrupt 
          }
          
          if (index > Pos30) index = INITIAL;
          
          // Sets previous thumbwheel value
          OLD_ADC_Thumb = ADC_Thumb - SW_SEL_6;
              
          // Scroll Fight Song
          display_2[SW_SEL_0] = RX_Char[index];
          display_2[SW_SEL_1] = RX_Char[index + SW_SEL_1];
          display_2[SW_SEL_2] = RX_Char[index + SW_SEL_2];
          display_2[SW_SEL_3] = RX_Char[index + SW_SEL_3];
          display_2[SW_SEL_4] = RX_Char[index + SW_SEL_4];
          display_2[SW_SEL_5] = RX_Char[index + SW_SEL_5];
          display_2[SW_SEL_6] = RX_Char[index + SW_SEL_6];
          display_2[SW_SEL_7] = RX_Char[index + SW_SEL_7];
          display_2[SW_SEL_8] = RX_Char[index + SW_SEL_8];
          display_2[SW_SEL_9] = RX_Char[index + SW_SEL_9];
 
          // Update LCD Display
	  Display_Process();
	  Five_msec_Delay(LIL_DELAY);
		
          // Clean before return
          if (!(P4IN & SW2)) {
            Five_msec_Delay(LIL_SW_DELAY);
            display_1 = "          ";
            display_2 = "          ";
            display_3 = "          ";
            display_4 = "          ";
            break;
          }
      }  
}