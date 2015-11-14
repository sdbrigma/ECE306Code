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

void setLCD(char display1[], int pos1, char display2[], int pos2,
            char display3[], int pos3, char display4[], int pos4){
  display_1 = display1;
  posL1 = pos1;
  display_2 = display2;
  posL2 = pos2;
  display_3 = display3;
  posL3 = pos3;
  display_4 = display4;
  posL4 = pos4;
  Display_Process();
  Five_msec_Delay(15);
}

void clearLCD(void){
  setLCD("          ",ZERO,"          ",ZERO,"          ",ZERO,"          ",ZERO);
}