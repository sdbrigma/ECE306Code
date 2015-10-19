/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains code to read data from the thumb wheel.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: thumbwheel.c
*        Passed : No variables passed 
*        Locals: No locals variables
*        Returned: no values returned 
*        Globlas: No variables used
*******************************************************************************/

// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char posL1;
extern char posL2;
extern char posL3;
extern unsigned int ADC_Right_Detector;
extern unsigned int ADC_thumb;
extern unsigned int ADC_Left_Detector;

void ADC_read(int detect_mode){
  // For detect mode 0 - right detector, 1 - left, 2 - thumbwheel
  unsigned int value;
  ADC_Channel = detect_mode;
  if(ADC_Channel == Right_Detector){value = ADC_Right_Detector;}
  if(ADC_Channel == Left_Detector){value = ADC_Left_Detector;}
  if(ADC_Channel == Thumbwheel){value = ADC_Thumb;}
  ADC_Process();
  // Hex conversion code
    unsigned int tmp = value & 0x000F; // Preserver first nibble of thumbwheel register
    if(tmp > 0x0009){
      tmp = tmp + 0x0037;
    }
    else{
      tmp = tmp | 0x0030;
    }
    if(detect_mode == 2)
      {display_1[6] = tmp;} // thumbwheel
    if(detect_mode == 1)
      {display_2[6] = tmp;} // left detect
    if(detect_mode == 0)
      {display_3[6] = tmp;} // right detect
    
    tmp = value & 0x00F0; // Preserver second nibble of thumbwheel register
    tmp >>= 4; 
    if(tmp > 0x0009){
      tmp = tmp + 0x0037;
    }
    else{
      tmp = tmp | 0x0030;
    }
    if(detect_mode == 2)
      {display_1[5] = tmp;}
    if(detect_mode == 1)
      {display_2[5] = tmp;} // left detect
    if(detect_mode == 0)
      {display_3[5] = tmp;} // right detect
    
      tmp = value & 0x0F00; // Preserver last nibble of thumbwheel register
      tmp >>= 8;
    if(tmp > 0x0009){
      tmp = tmp + 0x0037;
    }
    else{
      tmp = tmp | 0x0030;
    }
    if(detect_mode == 2)
      {display_1[4] = tmp; display_2="          "; display_3="          ";}
    if(detect_mode == 1)
      {display_2[4] = tmp;} // left detect
    if(detect_mode == 0)
      {display_3[4] = tmp;} // right detect
   
    Display_Process();
}
