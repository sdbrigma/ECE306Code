//******************************************************************************
//
//  Description: This file contains the hex conversion and display routine
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Display_ADC (void){
//******************************************************************************
//
//  Description: This file contains the hex conversion and display routine with
//  relation to the ADC
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: ADC_Thumb, ADC_Right_Detector, ADC_Left_Detector
// adc_RD_Enable, adc_LD_Enable
//
// Passed:
//
// Local: tmpWork, ADCtemp
//
// Return: VOID
//
//****************************************************************************** 
  
  // Initialize
  unsigned int ADCtemp = INITIAL;
  unsigned int tmpWork = INITIAL;
    
  if(adc_RD_Enable)ADCtemp = ADC_Right_Detector;        // HEX value to read
  if(adc_LD_Enable)ADCtemp = ADC_Left_Detector;         // HEX value to read 
  
  tmpWork = ADCtemp;                                    // Temporary Operator
  
  // First Nibble
  tmpWork = tmpWork & FIRST_NIBBLE;                     // Work with least significant nibble
  if (tmpWork >= LETTER_START) {
    tmpWork += LETTER_OP;                               // Code for 0xA - 0xF
  }
  else {
    tmpWork |= NUMBER_OP;                               // Code for 0x0 - 0x9
  }
  
  if(adc_RD_Enable)display_3[LINE_POS_L8] = tmpWork;    // Display character
  if(adc_LD_Enable)display_2[LINE_POS_L8] = tmpWork;    // Display character
  
  // Second Nibble
  tmpWork = ADCtemp;                                    // Use original value
  tmpWork &= SECOND_NIBBLE;                             // Second nibble
  tmpWork >>= SHIFT_4;                                  // Shift to lowest order bits
  if (tmpWork >= LETTER_START) {
    tmpWork += LETTER_OP;                               // Code for 0xA - 0xF
  }
  else {
    tmpWork |= NUMBER_OP;                               // Code for 0x0 - 0x9
  }
  if(adc_RD_Enable)display_3[LINE_POS_L7] = tmpWork;    // Display character
  if(adc_LD_Enable)display_2[LINE_POS_L7] = tmpWork;    // Display character
  
  // Third Nibble
  tmpWork = ADCtemp;                                    // Use original value
  tmpWork &= THIRD_NIBBLE;                              // Third nibble
  tmpWork >>= SHIFT_8;                                  // Shift to lowest order bits
  if (tmpWork >= LETTER_START) {
    tmpWork += LETTER_OP;                               // Code for 0xA - 0xF
  }
  else {
    tmpWork |= NUMBER_OP;                               // Code for 0x0 - 0x9
  }
  if(adc_RD_Enable)display_3[LINE_POS_L6] = tmpWork;    // Display character
  if(adc_LD_Enable)display_2[LINE_POS_L6] = tmpWork;    // Display character

  
  // Push changes to display
  Display_Process();
}

unsigned int intToHex (unsigned int intTemp){
//******************************************************************************
//
//  Description: This functions implements the integer to ASCII conversion
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: 
//
// Passed: conver
//
// Local: tmpHEX, intTemp
//
// Return: VOID
//
//****************************************************************************** 
  
  // Initialize
  unsigned int tmpHEX = INITIAL;
  unsigned int tmpReturn = INITIAL;
  
  tmpHEX = intTemp;                                    // Temporary Operator
  
  // First Nibble
  tmpHEX &= FIRST_NYBL;                     // Work with least significant nibble
  if (tmpHEX >= LETTER_START) {
    tmpHEX += LETTER_OP;                               // Code for 0xA - 0xF
  }
  else {
    tmpHEX |= NUMBER_OP;                               // Code for 0x0 - 0x9
  }
  
  tmpReturn |= tmpHEX;    // Display character
  
  // Second Nibble
  tmpHEX = intTemp;                                    // Use original value
  tmpHEX &= SECOND_NYBL;                             // Second nibble
  tmpHEX >>= SHIFT_4;                                  // Shift to lowest order bits
  if (tmpHEX >= LETTER_START) {
    tmpHEX += LETTER_OP;                               // Code for 0xA - 0xF
  }
  else {
    tmpHEX |= NUMBER_OP;                               // Code for 0x0 - 0x9
  }
  tmpHEX <<= SHIFT_4;
  tmpReturn |= tmpHEX;    // Display character
 
  tmpReturn &= CLEAN_NYBL;
  
  return tmpReturn;
 
}

unsigned int hexToInt (unsigned int hexTemp){
//******************************************************************************
//
//  Description: This functions implements the ASCII to Integer conversion
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: 
//
// Passed: conver
//
// Local: tmpHEX, intTemp
//
// Return: VOID
//
//****************************************************************************** 
  
  // Initialize
  unsigned int tmpReturn = INITIAL;
  
  tmpReturn = hexTemp;                                    // Temporary Operator
  tmpReturn -= NUMBER_OP;
  
  return tmpReturn;
 
}
