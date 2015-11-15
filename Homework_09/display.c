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

void setLCD(const char display1[], int pos1, const char display2[], int pos2,// ONLY TAKES STRINGS
            const char display3[], int pos3, const char display4[], int pos4){
              
  int i = ZERO;
  posL1 = pos1;
  posL2 = pos2;
  posL3 = pos3;
  posL4 = pos4;
  while(i<10){
    display_1[i] = display1[i];
    display_2[i] = display2[i];
    display_3[i] = display3[i];
    display_4[i] = display4[i];
    i++;
  }
  Display_Process();
  Five_msec_Delay(50);
}

void clearLCD(void){
  int i = ZERO;
  posL1 = ZERO;
  posL2 = ZERO;
  posL3 = ZERO;
  posL4 = ZERO;
  while(i<10){
    display_1[i] = ORIGINAL;
    display_2[i] = ORIGINAL;
    display_3[i] = ORIGINAL;
    display_4[i] = ORIGINAL;
    i++;
  }
  Display_Process();
  Five_msec_Delay(40);
}