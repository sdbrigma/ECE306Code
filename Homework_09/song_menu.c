#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
//******************************************************************************
//
//  Description: This file contains code for the last option, "Song", in the top menu 
//   
//
//  Steffon Brigman
//  Noember 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

void getSongMenu(unsigned int adc_value){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   November 2015
*        Description: This fucntion displays options under "Song" in the top menu
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*        Funcction name: getShapesMenu
*        Passed : adc-value
*        Returned: no values returned 
*        Locals: adc_value, HW9_String
*        Globlas: color, inc, display_2, posL1, posL3, display_1, display_3
*******************************************************************************/
  ADC_Process();
  char HW9_String[HW9_string] = "We're the Red and White from State And we know we are the best. A hand behind our back, We can take on all the rest. Come over the hill, Carolina. Devils and Deacs stand in line. The Red and White from N.C. State. Go State!";
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
    Five_msec_Delay(switch_delay);
    inc = inc + window_size;
    /*unsigned int tmp = adc_value-ADC_Thumb;
    if(tmp>3){
      inc = inc + 10;
    }*/
  }
}