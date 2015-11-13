//******************************************************************************
//
//  Description: This file contains code for the switches prcesses function.
//   
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
void Switches_Process(void){
//******************************************************************************
//
//  Description: This functions sets code for switch 1 and 2 upon being pressed
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************
  if (!(P4IN & SW1)){ 
    ADC_Process();
    while(ALWAYS){
      if (!(P4IN & SW1)){break;}
      ADC_Process(); // read ADC value for thumbwheel
      if(ADC_Thumb <= 340){// Divides range of ADC values into three for main menu
        display_1 = "Resistors";
        posL1 = LINE_POS_L0;
        display_2 = "          ";
        posL2 = LINE_POS_L0;
        display_3 = "          ";
        posL3 = LINE_POS_L0;
        display_4 = "          ";
        posL4 = LINE_POS_L0;
        ADC_Process();
        
        // RESISTOR CODES
        if(!(P4IN & SW1)){
          while(ALWAYS){
            if (!(P4IN & SW2)){break;}
            ADC_Process();
            getResistorMenu(ADC_Thumb);
          }
        }
      } 
      
      else if(ADC_Thumb >= 681){ // this range the last third of the full range of values for the ADC
        display_1 = "Song";
        posL1 = LINE_POS_L3;
        display_2 = "          ";
        posL2 = LINE_POS_L0;
        display_3 = "          ";
        posL3 = LINE_POS_L0;
        display_4 = "          ";
        posL4 = LINE_POS_L0;
        ADC_Process();
      }
      
      else{ // If it's not in the lower or upper third it's in the middle
        display_1 = "Shapes";
        posL1 = LINE_POS_L2;
        display_2 = "          ";
        posL2 = LINE_POS_L0;
        display_3 = "          ";
        posL3 = LINE_POS_L0;
        display_4 = "          ";
        posL4 = LINE_POS_L0;
        ADC_Process();
        
        //SHAPES
        if(!(P4IN & SW1)){
         while(ALWAYS){
            if (!(P4IN & SW2)){break;}
            ADC_Process();
            getShapesMenu(ADC_Thumb);
          } 
        }
      }
    }
    
    
      /*while(ALWAYS){
        if (!(P4IN & SW2)) { break; }
        UCA1TXBUF = HW8_String[cpu_rx_ring_wr];
        display_1[LINE_POS_L9] = display_1[LINE_POS_L8];
        display_1[LINE_POS_L8] = display_1[LINE_POS_L7];
        display_1[LINE_POS_L7] = display_1[LINE_POS_L6];
        display_1[LINE_POS_L6] = display_1[LINE_POS_L5];
        display_1[LINE_POS_L5] = display_1[LINE_POS_L4];
        display_1[LINE_POS_L4] = display_1[LINE_POS_L3];
        display_1[LINE_POS_L3] = display_1[LINE_POS_L2];
        display_1[LINE_POS_L2] = display_1[LINE_POS_L1];
        display_1[LINE_POS_L1] = display_1[LINE_POS_L0];
        display_1[LINE_POS_L0] = UCA1RXBUF;
        posL1 = ZERO;
        display_2 = "          ";
        posL2 = ZERO;
        display_3 = " Baud Rate";
        posL3 = ZERO;
        display_4 = "  9600  ";
        posL4 = ZERO;
        Display_Process();
        Five_msec_Delay(transmit_delay);
      }*/
  }
  if (!(P4IN & SW2)) {
  display_1 = "NCSU";
  posL1 = SW1_posL1;
  display_2 = "WOLFPACK";
  posL2 = SW1_posL2;
  display_3 = "ECE306";
  posL3 = SW1_posL3;
  display_4 = "S Brigman";
  posL4 = SW1_posL4;
}
//------------------------------------------------------------------------------
}