#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getSongMenu(unsigned int adc_value){
  ADC_Process();
  //ClrDisplay();
  //Display_Process();
  char HW9_String[233] = "We're the Red and White from State And we know we are the best. A hand behind our back, We can take on all the rest. Come over the hill, Carolina. Devils and Deacs stand in line. The Red and White from N.C. State. Go State!";
  lcd_BIG_mid();
  unsigned int tmp;
  setLCD("----------",LINE_POS_L0,"          ",LINE_POS_L0,"----------",LINE_POS_L1,"----------",LINE_POS_L0);
  if(adc_value>ADC_Thumb){
    tmp = (1023-adc_value) / 70;
    display_2[LINE_POS_L0] = HW9_String[inc++];
    display_2[LINE_POS_L1] = HW9_String[inc++];
    display_2[LINE_POS_L2] = HW9_String[inc++];
    display_2[LINE_POS_L3] = HW9_String[inc++];
    display_2[LINE_POS_L4] = HW9_String[inc++];
    display_2[LINE_POS_L5] = HW9_String[inc++];
    display_2[LINE_POS_L6] = HW9_String[inc++];
    display_2[LINE_POS_L7] = HW9_String[inc++];
    display_2[LINE_POS_L8] = HW9_String[inc++];
    display_2[LINE_POS_L9] = HW9_String[inc++];
  }
  Five_msec_Delay(15);
  Display_Process();
  ADC_Process();
}