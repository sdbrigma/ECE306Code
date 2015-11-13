// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getResistorMenu(unsigned int adc_value){
  adc_value = adc_value >> 6; // shift 10 bit value by 6 bits
  switch(adc_value){
  case MENU1:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Black";
    posL2 = LINE_POS_L3;
    display_4 = "0";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU2:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Brown";
    posL2 = LINE_POS_L3;
    display_4 = "1";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU3:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Red";
    posL2 = LINE_POS_L4;
    display_4 = "2";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU4:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Orange";
    posL2 = LINE_POS_L2;
    display_4 = "3";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU5:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Yellow";
    posL2 = LINE_POS_L2;
    display_4 = "4";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU6:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Green";
    posL2 = LINE_POS_L3;
    display_4 = "5";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU7:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Blue";
    posL2 = LINE_POS_L3;
    display_4 = "6";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU8:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Violet";
    posL2 = LINE_POS_L2;
    display_4 = "7";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU9:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "Gray";
    posL2 = LINE_POS_L3;
    display_4 = "8";
    posL4 = LINE_POS_L5;
    ADC_Process();
  case MENU10:
    display_1 = "Color";
    posL1 = LINE_POS_L3;
    display_3 = "Value";
    posL3 = LINE_POS_L3;
    display_2 = "White";
    posL2 = LINE_POS_L3;
    display_4 = "9";
    posL4 = LINE_POS_L5;
    ADC_Process();
    
  default: break;
  }
}