//******************************************************************************
//
//  Description: This file contains the ADC detection routine module
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

void Detect(void){
//******************************************************************************
//
//  Description: This file contains the ADC detection routine module
//
//
//  Christopher Woedy
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
  
  adc_RD_Enable = FALSE;
  adc_LD_Enable = FALSE; 
  thumbEnable = FALSE;
  tempEnable = FALSE;
  batEnable  = FALSE;   

  while(ALWAYS) {
      
    if (!(P4IN & SW1)) break;
    // Left Detector
    adc_RD_Enable = FALSE;
    adc_LD_Enable = TRUE; 
    ADC10_Process();
    Display_ADC();
    Five_msec_Delay(FOUR_CYCLES);
    // Right Detector
    adc_RD_Enable = TRUE;
    adc_LD_Enable = FALSE; 
    ADC10_Process();
    Display_ADC();
    Five_msec_Delay(FOUR_CYCLES);
  }
  
}