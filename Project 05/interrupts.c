#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains all interrupts used within this project.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: interrupts.c
*        Passed : No variables passed 
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no variables defined
*******************************************************************************/
unsigned int ADC_Thumb; 
// TimerA0 0 Interrupt handler
#pragma vector = TIMER0_A0_VECTOR

__interrupt void Timer0_A0_ISR(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions is an interrupt used to control the motors.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Timer0_A0_ISR
*        Passed : No variables passed 
*        Locals: TA0CCR0, ISR_COUNT
*        Returned: no values returned 
*        Globlas: no variables defined
*******************************************************************************/

 PJOUT ^= LED3; // Test signal
 ISR_COUNT++;
 TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
 if(ISR_COUNT>FIVE_SECONDS){
   ISR_COUNT = ZERO;
 }
}

//------------------------------------------------------------------------------
// ADC10 interrupt service routine
// ADC_Right_Detector; // A00 ADC10INCH_0 - P1.0
// ADC_Left_Detector; // A01 ADC10INCH_1 - P1.1
// ADC_Thumb; // A03 ADC10INCH_3 - P1.3
// ADC_Temp; // A10 ADC10INCH_10 – Temperature REF module
// ADC_Bat; // A11 ADC10INCH_11 - Internal
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
 switch(__even_in_range(ADC10IV,12)) {
 case 0: break; // No interrupt
 case 2: break; // conversion result overflow
 case 4: break; // conversion time overflow
 case 6: break; // ADC10HI
 case 8: break; // ADC10LO
 case 10: break; // ADC10IN
 case 12:
       // Need this to change the ADC10INCH_x value.
     ADC10CTL0 &= ~ADC10ENC; // Toggle ENC bit.
     
     switch (ADC_Channel){
     case Right_Detector:
     ADC10MCTL0 = ADC10INCH_0; //  channel A0
     ADC_Right_Detector = ADC10MEM0; // Read Channel A0
     ADC_Channel++;
     break;
     
     case Left_Detector:
     ADC10MCTL0 = ADC10INCH_1; //  channel A1
     ADC_Left_Detector = ADC10MEM0; // Read Channel A1
     ADC_Channel = ZERO;
     break;
     
     case Thumbwheel:
     ADC10MCTL0 = ADC10INCH_3; // Next channel A0
     ADC_Thumb = ADC10MEM0; // Read Channel A3
     //ADC_Channel = ZERO;
     break;
     
     /*case CHANNEL_A10:
     ADC10MCTL0 = ADC10INCH_10; // Next channel A10
     ADC_Temp = ADC10MEM0; // Read Channel A10
     ADC_Channel++;
     break;
     
     case CHANNEL_A11:
     ADC10MCTL0 = ADC10INCH_0; // Next channel A0
     ADC_Bat = ADC10MEM0; // Read Channel A11
     ADC_Channel= ZERO;
     break;*/
     
     default: break;
     }
   ADC10CTL0 |= ADC10ENC | ADC10SC; // Start next sample.
 default: break;
   }
}
//-----------------------------------------------------------------------------