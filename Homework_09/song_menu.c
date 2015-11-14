#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getSongMenu(unsigned int adc_value){
  unsigned int color = ZERO;
  ADC_Process();
  char HW9_String[233] = "We're the Red and White from State And we know we are the best. A hand behind our back, We can take on all the rest. Come over the hill, Carolina. Devils and Deacs stand in line. The Red and White from N.C. State. Go State!";
  lcd_BIG_mid();
  ADC_Process();
  if(adc_value>ADC_Thumb){
    display_2[LINE_POS_L0] = HW9_String[inc];
    display_2[LINE_POS_L1] = HW9_String[inc + LINE_POS_L1];
    display_2[LINE_POS_L2] = HW9_String[inc + LINE_POS_L2];
    display_2[LINE_POS_L3] = HW9_String[inc + LINE_POS_L3];
    display_2[LINE_POS_L4] = HW9_String[inc + LINE_POS_L4];
    display_2[LINE_POS_L5] = HW9_String[inc + LINE_POS_L5];
    display_2[LINE_POS_L6] = HW9_String[inc + LINE_POS_L6];
    display_2[LINE_POS_L7] = HW9_String[inc + LINE_POS_L7];
    display_2[LINE_POS_L8] = HW9_String[inc + LINE_POS_L8];
    display_2[LINE_POS_L9] = HW9_String[inc + LINE_POS_L9];
    ADC_Process();
    if(color == ZERO){
      display_3 = "White";
      display_1 = "Red";
      posL3 = 3;
      posL4 = 4;
      color = ALWAYS;
      Five_msec_Delay(25);
      Display_Process();
    }
    else {
      display_3 = "Red";
      display_1 = "White";
      posL3 = 3;
      posL4 = 4;
      color = ZERO;
      Five_msec_Delay(25);
      Display_Process();
    }
    unsigned int tmp = adc_value-ADC_Thumb;
    if(tmp>10){
      inc = inc + 10;
    }
  }
  ADC_Process();
  clearLCD();
}