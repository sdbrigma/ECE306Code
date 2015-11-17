//******************************************************************************
//
//  Description: This file contains the ADC Routines
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Init_ADC(void){
  //******************************************************************************
  //
  //  Description: This file contains the ADC Configuration Routine
  //
  //
  //  Steffon Brigman
  //  Nov 2015
  //  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
  //
  // Globals:
  //
  // Passed:
  //
  // Local:
  //
  // Return: VOID
  //
  //****************************************************************************** 
  
  ADC10CTL0 = CLEAR_REGISTER; // Clear ADC10CTL0
  ADC10CTL0 |= ADC10SHT_2;    // 16 ADC clocks
  ADC10CTL0 &= ~ADC10MSC;     // Single Sequence
  ADC10CTL0 |= ADC10ON;       // ADC ON - Core Enabled
  
  ADC10CTL1 = CLEAR_REGISTER;    // Clear ADC10CTL1
  ADC10CTL1 |= ADC10SHS_0;     // ADC10SC bit
  ADC10CTL1 |= ADC10SHP;      // SAMPCON signal sourced from sampling timer
  ADC10CTL1 &= ~ADC10ISSH;    // The sample-input signal is not inverted
  ADC10CTL1 |= ADC10DIV_0;    // ADC10_B clock divider - divide by 1
  ADC10CTL1 |= ADC10SSEL_0;    // MODCLK
  ADC10CTL1 |= ADC10CONSEQ_0; // Single-channel, single-conversion
  
  ADC10CTL2 = CLEAR_REGISTER;    // Clear ADC10CTL2
  ADC10CTL2 |= ADC10DIV_0;    // Pre-divide by 1
  ADC10CTL2 |= ADC10RES;      // 10-bit resolution
  ADC10CTL2 &= ~ADC10DF;      // Binary unsigned
  ADC10CTL2 &= ~ADC10SR;      // Supports up to approximately 200 ksps
  
  ADC10MCTL0 = CLEAR_REGISTER;   // Clear ADC10MCTL0
  ADC10MCTL0 |= ADC10SREF_0;  // V(R+) = AVCC and V(R-) = AVSS
  ADC10MCTL0 |= ADC10INCH_0;  // Channel A0
  ADC10IE |= ADC10IE0;        // Enable ADC conversion complete interrupt
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
  //******************************************************************************
  //
  //  Description: This file contains the ADC interrupt service routine handler
  //  code that addresses different cases of the interrupt.
  //
  //
  //  Steffon Brigman
  //  Nov 2015
  //  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
  //
  // Globals: ADC_Thumb, ADC_Right_Detector, ADC_Left_Detector,
  // ADC_Temp, ADC_Bat, ADC_Channel
  //
  // Passed:
  //
  // Local:
  //
  // Return: VOID
  //
  //****************************************************************************** 
  
  switch(__even_in_range(ADC10IV,SW_SEL_12)) {
  case SW_SEL_0: break;
  case SW_SEL_2: break;
  case SW_SEL_4: break;
  case SW_SEL_6: break;
  case SW_SEL_8: break;
  case SW_SEL_10: break;
  case SW_SEL_12: 
    // Need this to change the ADC10INCH_x value.       
    ADC10CTL0 &= ~ADC10ENC;             // Toggle ENC bit. 
    
    switch (ADC_Channel++){  
      // Right Detector
    case Right_Detector:           
      ADC10MCTL0 = ADC10INCH_1;       // Next channel A1
      ADC_Left_Detector = ADC10MEM0; // Read Channel A0            
      break;
      // Left Detector
    case Left_Detector:           
      ADC10MCTL0 = ADC10INCH_3;       // Next channel A3           
      ADC_Right_Detector = ADC10MEM0;  // Read Channel A1            
      break;    
      // Thumbwheel
    case Thumbwheel:           
      ADC10MCTL0 = ADC10INCH_11;      // Next channel A11           
      ADC_Thumb = ADC10MEM0;          // Read Channel A3            
      break;
      // Temperature
    case CHANNEL_A10:           
      ADC10MCTL0 = ADC10INCH_10;      // Next channel A10           
      ADC_Temp = ADC10MEM0;           // Read Channel A10           
      break; 
      // Internal
    case CHANNEL_A11:           
      ADC10MCTL0 = ADC10INCH_0;       // Next channel A0           
      ADC_Bat = ADC10MEM0;            // Read Channel A11            
      ADC_Channel=INITIAL;           
      break;         
    default:         
      break;       
    }              
    break;
  default: break;
  }
}

void ADC10_Process(void){
  //******************************************************************************
  //
  //  Description: This file contains the ADC process routine
  //
  //
  //  Steffon Brigman
  //  Nov 2015
  //  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
  //
  // Globals:
  //
  // Passed:
  //
  // Local:
  //
  // Return: VOID
  //
  //****************************************************************************** 
  
  while (ADC10CTL1 & BUSY);             // Wait if ADC10 core is active
  ADC10CTL0 |= ADC10ENC + ADC10SC;      // Sampling and conversion start
  
}