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
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char ADC_TEST;
extern char posL4;
int button_counter1 = ZERO;
int button_counter2 = ZERO;
void Switches_Process(void){
//------------------------------------------------------------------------------
// Switch proccess sets LCD text when SW1 and SW2 are pressed
  if (!(P4IN & SW1)){
    display_1 = "          ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = ZERO;
    display_3 = "          ";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
    /*
    display_1 = "NCSU";
    posL1 = SW1_posL1;
    display_2 = "WOLFPACK";
    posL2 = SW1_posL2;
    display_3 = "ECE306";
    posL3 = SW1_posL3;
    display_4 = "S Brigman";
    posL4 = SW1_posL4;
    */
    while(ALWAYS){
      ADC_read(2);
      Five_msec_Delay(30);  
    }
  }
  if (!(P4IN & SW2)) {
    /*display_1 = "Embedded";
    posL1 = SW2_posL1;
    display_2 = "Systems";
    posL2 = SW2_posL1;
    display_3 = "Rock!";
    posL3 = SW2_posL1;
    display_4 = "Go Pack!";
    posL4 = SW2_posL1;*/
    
    display_1 = "          ";
    posL1 = ZERO;
    display_2 = "          ";
    posL2 = ZERO;
    display_3 = "          ";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
    
    while(ALWAYS){
      ADC_read(1); // read right detecter Black = 0x3E6 and White = 
      Five_msec_Delay(25);  
      /*ADC_read(1);
      Five_msec_Delay(25);*/
    }
  }
//------------------------------------------------------------------------------
}