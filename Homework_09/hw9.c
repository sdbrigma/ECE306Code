// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getResistorMenu(unsigned int adc_value){
  adc_value = adc_value >> 6; // shift 10 bit value by 6 bits
  switch(adc_value){
  case MENU1:
      display_2 = "Black";
      posL2 = LINE_POS_L3;
      display_4 = "0";
      posL4 = LINE_POS_L5;
  }
}