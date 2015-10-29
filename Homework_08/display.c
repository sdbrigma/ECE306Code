//******************************************************************************
//
//  Description: This file contains the Dispaly Process function controlling
//  the LCD.
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------

#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void Display_Process(void){
// Function that initialezes LCD display
  ClrDisplay();
  lcd_out(display_1, LCD_HOME_L1, posL1);
  lcd_out(display_2, LCD_HOME_L2, posL2);
  lcd_out(display_3, LCD_HOME_L3, posL3);
  lcd_out(display_4, LCD_HOME_L4, posL4);
}