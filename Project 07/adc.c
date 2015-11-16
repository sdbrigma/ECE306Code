/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This files contains code to setup the ADC.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: adc.c
*        Passed : No variables passed 
*        Locals: No locals variables
*        Returned: no values returned 
*        Globlas: No variables used
*******************************************************************************/

// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

//------------------------------------------------------------------------------
// Configure ADC10_B
void Init_ADC(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function initializes the ADC
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_ADC
*        Passed : None passed
*        Locals: None declared
*        Returned: no values returned 
*        Globlas: None used
*******************************************************************************/
 ADC10CTL0 = CLEAR_REGISTER; // Clear ADC10CTL0
 ADC10CTL0 |= ADC10SHT_2; // 16 ADC clocks
 ADC10CTL0 &= ~ADC10MSC; // Single Sequence
 ADC10CTL0 |= ADC10ON; // ADC ON - Core Enabled
 ADC10CTL1 = CLEAR_REGISTER; // Clear ADC10CTL1
 ADC10CTL1 |= ADC10SHS_0; // ADC10SC bit
 ADC10CTL1 |= ADC10SHP; // SAMPCON signal sourced from sampling timer
 ADC10CTL1 &= ~ADC10ISSH; // The sample-input signal is not inverted.
 ADC10CTL1 |= ADC10DIV_0; // ADC10_B clock divider – Divide by 1.
 ADC10CTL1 |= ADC10SSEL_0; // MODCLK
 ADC10CTL1 |= ADC10CONSEQ_0; // Single-channel, single-conversion
 ADC10CTL2 = CLEAR_REGISTER; // Clear ADC10CTL2
 ADC10CTL2 |= ADC10DIV_0; // Pre-divide by 1
 ADC10CTL2 |= ADC10RES; // 10-bit resolution
 ADC10CTL2 &= ~ADC10DF; // Binary unsigned
 ADC10CTL2 &= ~ADC10SR; // supports up to approximately 200 ksps
 ADC10MCTL0 = CLEAR_REGISTER; // Clear ADC10MCTL0
 ADC10MCTL0 |= ADC10SREF_0; // V(R+) = AVCC and V(R-) = AVSS
 ADC10MCTL0 |= ADC10INCH_3; // Channel A3 Thumb Wheel
 ADC10IE |= ADC10IE0; // Enable ADC conversion complete interrupt
}
//---------------------------------------------------------------------

//------------------------------------------------------------------------------
void ADC_Process(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function prepars the ADC to take sampes
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: ADC_Process
*        Passed : None passed
*        Locals: None declared
*        Returned: no values returned 
*        Globlas: None used
*******************************************************************************/
 while (ADC10CTL1 & BUSY); // Wait if ADC10 core is active
 ADC10CTL0 |= ADC10ENC + ADC10SC; // Sampling and conversion start
}
//------------------------------------------------------------------------------