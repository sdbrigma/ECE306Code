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
*        Globlas: Listed in the globals section
*******************************************************************************/

// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

// GLobal Variables
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern unsigned int ADC_Right_Detector;
extern unsigned int ADC_thumb;
extern unsigned int ADC_Left_Detector;

void ADC_read(int detect_mode){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function converts ADC values to display to the LCD
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: ADC_read
*        Passed : detect_mode
*        Locals: value, tmp
*        Returned: no values returned 
*        Globlas: All listed in the globals section
*******************************************************************************/
  // For detect mode 0 - right detector, 1 - left, 2 - thumbwheel
  unsigned int value;
  ADC_Channel = detect_mode;
  if(ADC_Channel == Right_Detector){value = ADC_Right_Detector;}
  if(ADC_Channel == Left_Detector){value = ADC_Left_Detector;}
  if(ADC_Channel == Thumbwheel){value = ADC_Thumb;}
  ADC_Process();
  // Hex conversion code
    unsigned int tmp = value & NIBBLE1; // Preserver first nibble of thumbwheel register
    if(tmp > HEX_A){
      tmp = tmp + ADC_conv1;
    }
    else{
      tmp = tmp | ADC_conv2;
    }
    if(detect_mode == Thumbwheel)
      {display_1[line1] = tmp;} // thumbwheel
    if(detect_mode == Left_Detector)
      {display_2[line1] = tmp;} // left detect
    if(detect_mode == Right_Detector)
      {display_3[line1] = tmp;} // right detect
    
    tmp = value & NIBBLE2; // Preserver second nibble of thumbwheel register
    tmp >>= shift1; 
    if(tmp > HEX_A){
      tmp = tmp + ADC_conv1;
    }
    else{
      tmp = tmp | ADC_conv2;
    }
    if(detect_mode == Thumbwheel)
      {display_1[line2] = tmp;}
    if(detect_mode == Left_Detector)
      {display_2[line2] = tmp;} // left detect
    if(detect_mode == Right_Detector)
      {display_3[line2] = tmp;} // right detect
    
      tmp = value & NIBBLE3; // Preserver last nibble of thumbwheel register
      tmp >>= shift2;
    if(tmp > HEX_A){
      tmp = tmp + ADC_conv1;
    }
    else{
      tmp = tmp | ADC_conv2;
    }
    if(detect_mode == Thumbwheel)
      {display_1[line3] = tmp;}
    if(detect_mode == Left_Detector)
      {display_2[line3] = tmp;} // left detect
    if(detect_mode == Right_Detector)
      {display_3[line3] = tmp;} // right detect
    Display_Process();
}
