//******************************************************************************
//
//  Description: This file contains the ADC detection routine module
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Detect(void){
//******************************************************************************
//
//  Description: This file contains the ADC detection routine module
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: adc_RD_Enable, adc_LD_Enable, thumbEnable, tempEnable
// batEnable
//
// Passed:
//
// Local: 
//
// Return: VOID
//
//****************************************************************************** 
  display_1 = "  Detect  ";
  posL1 = LINE_POS_L0;
  display_2 = "LEFT:     ";
  posL2 = LINE_POS_L0;
  display_3 = "RIGHT:    ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  big = INITIAL;
  lcd_4line();
  Display_Process();
  
  adc_RD_Enable = FALSE;
  adc_LD_Enable = FALSE; 
  tempEnable = FALSE;
  batEnable  = FALSE;  
  
  // Enable Infrared Emitter
  P1OUT |= IR_LED;                    // P1OUT ->    1

  while(ALWAYS) {
      
    if (!(P4IN & SW2)) {
     Five_msec_Delay(LIL_SW_DELAY); 
     break;
    }
    if (thumbEnable) {
    ADC10_Process();
    Display_Thumb();
    }
    else {
    // Left Detector
    adc_RD_Enable = FALSE;
    adc_LD_Enable = TRUE; 
    ADC10_Process();
    Display_ADC();
    Five_msec_Delay(FIVE_CYCLES);
    // Right Detector
    adc_RD_Enable = TRUE;
    adc_LD_Enable = FALSE; 
    ADC10_Process();
    Display_ADC();
    }
    Five_msec_Delay(TEN_ITERATIONS);
  }
  
}