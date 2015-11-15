#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getSongMenu(unsigned int adc_value){
  ADC_Process();
  char HW9_String[233] = "We're the Red and White from State And we know we are the best. A hand behind our back, We can take on all the rest. Come over the hill, Carolina. Devils and Deacs stand in line. The Red and White from N.C. State. Go State!";
  if(adc_value > (ADC_Thumb + LINE_POS_L3)){
    if(color == ALWAYS){
      display_1 = "Red";
      posL1 = LINE_POS_L4;
      display_3 = "White";
      posL3 = LINE_POS_L3;
      color++;
    }
    else {
      display_1 = "White";
      posL1 = LINE_POS_L3;
      display_3 = "Red";
      posL3 = LINE_POS_L4;
      color--;
    }
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
    Display_Process();
    Five_msec_Delay(15);
    inc = inc + 10;
    /*unsigned int tmp = adc_value-ADC_Thumb;
    if(tmp>3){
      inc = inc + 10;
    }*/
  }
}