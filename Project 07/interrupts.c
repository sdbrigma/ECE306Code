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
*        Globlas: ADC_Thumb
*******************************************************************************/
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
 UPDATE_LCD++;
 /*if((UPDATE_LCD == LCD) && (big == ZERO)){
   Display_Process(); 
   UPDATE_LCD = ZERO;} // reset UPDATE_LCD every 200ms*/
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
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions is an interrupt used to control the motors.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: ADC10_ISR
*        Passed : No variables passed 
*        Locals: none declared
*        Returned: no values returned 
*        Globlas: ADC_Right_Detector, ADC_Left_Detector, ADC_Thumb
*******************************************************************************/
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
     ADC_Channel = ZERO;
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

//------------------------------------------------------------------------------
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function is the transmit and receive interrupt for UART
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: USCI_A1_ISR
*        Passed : No variables passed 
*        Returned: no values returned 
*        Globlas: temp, cpu_rx_ring_wr
*******************************************************************************/
  // CPU and IOT interrupts are the same (This is the back door)
unsigned int temp = INITIAL;
  switch(__even_in_range(UCA1IV, USCI_val8)) {
  case SW_SEL_0:		//Vector 0 - No Interrupt
    break;
  case SW_SEL_2:		// Vector 2 - RXIFG
    // Code for Receive
    temp = IOTRead;
    IOT_RX[temp] =  UCA1RXBUF;   // Store Transmission 
    if (IOT_RX[temp] == '*') {
      IOTRead = INITIAL;
      IOT_RX[Pos0] = IOT_RX[temp];
    }
    if (++IOTRead >= (SMALL_RING_SIZE)) {
      IOTRead = INITIAL;         // Reset Index
    }
    break;
  case SW_SEL_4:		// Vector 4 - TXIFG
    // Code for Transmit
    break;
  default: break;
  }
}
//------------------------------------------------------------------------------

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function is the transmit and receive interrupt for UART
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: USCI_A1_ISR
*        Passed : No variables passed 
*        Returned: no values returned 
*        Globlas: temp, cpu_rx_ring_wr
*******************************************************************************/
  // CPU and IOT interrupts are the same (This is the back door)
   unsigned int temp = INITIAL;
  switch(__even_in_range(UCA0IV, USCI_val8)) {
  case SW_SEL_0:		//Vector 0 - No Interrupt
    break;
  case SW_SEL_2:		// Vector 2 - RXIFG
    // Code for Receive
    temp = rxRead;
    receiveEnable = TRUE;           // Tranmission received
    RX_Char[temp] =  UCA0RXBUF;   // Store Transmission                    
    if (++rxRead >= (SMALL_RING_SIZE)) {
      rxRead = INITIAL;             // Reset Index
    }
    break;
  case SW_SEL_4:		// Vector 4 - TXIFG
    // Code for Transmit
    break;
  default: break;
  }
}
//------------------------------------------------------------------------------