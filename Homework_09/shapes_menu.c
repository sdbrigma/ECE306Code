#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getShapesMenu(unsigned int adc_value){
  char value = adc_value >> SHIFT6; // shift 10 bit value by 6 bits
  if(value <= MENU1){
    display_1 = "No Shape";
    posL1 = LINE_POS_L0;
    display_2 = "Circle";
    posL2 = LINE_POS_L2;
    display_3 = "Square";
    posL3 = LINE_POS_L0;
    display_4 = "TEST";
    posL4 = LINE_POS_L2;
    lcd_BIG_mid();
    ADC_Process();
  }
  else if(value == MENU2){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU3){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU4){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU5){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU6){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU7){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU8){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else if(value == MENU9){
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
  else{
    display_1 = "Color";
    posL1 = LINE_POS_L3;

    ADC_Process();
  }
}