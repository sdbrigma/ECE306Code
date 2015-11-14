// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getResistorMenu(unsigned int adc_value){
  char value = adc_value >> SHIFT6; // shift 10 bit value by 6 bits
  lcd_4line();
  big = ZERO;
    if(value <= MENU1){
      setLCD("Color",LINE_POS_L3,"Black",LINE_POS_L3,"Value",LINE_POS_L3,"0",LINE_POS_L5);
      ADC_Process();
    }
  else if(value == MENU2){
    setLCD("Color",LINE_POS_L3,"Brown",LINE_POS_L3,"Value",LINE_POS_L3,"1",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU3){
    setLCD("Color",LINE_POS_L3,"Red",LINE_POS_L4,"Value",LINE_POS_L3,"3",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU4){
    setLCD("Color",LINE_POS_L3,"Orange",LINE_POS_L2,"Value",LINE_POS_L3,"3",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU5){
    setLCD("Color",LINE_POS_L3,"Yellow",LINE_POS_L2,"Value",LINE_POS_L3,"4",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU6){
    setLCD("Color",LINE_POS_L3,"Green",LINE_POS_L3,"Value",LINE_POS_L3,"5",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU7){
    setLCD("Color",LINE_POS_L3,"Blue",LINE_POS_L3,"Value",LINE_POS_L3,"6",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU8){
    setLCD("Color",LINE_POS_L3,"Violet",LINE_POS_L3,"Value",LINE_POS_L3,"7",LINE_POS_L5);
    ADC_Process();
  }
  else if(value == MENU9){
    setLCD("Color",LINE_POS_L3,"Gray",LINE_POS_L3,"Value",LINE_POS_L3,"8",LINE_POS_L5);
    ADC_Process();
  }
  else{
    setLCD("Color",LINE_POS_L3,"White",LINE_POS_L3,"Value",LINE_POS_L3,"9",LINE_POS_L5);
    ADC_Process();
  }
}