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
  unsigned int color_right = black;
  unsigned int color_left = black;
void Switches_Process(void){
//------------------------------------------------------------------------------
// Switch proccess sets LCD text when SW1 and SW2 are pressed
  if (!(P4IN & SW1)){
    calibrate_detector();
    line_dance();
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
emitter_on();
unsigned int i = 0; // counter for time taken to reverse
    //ISR_COUNT = ZERO;
  while(ALWAYS){// loop to travel in reverse
    // give motors enough time to get away from black line
    if(i == 0){
        motor_reverse(50);
        i++;
    }
    i++;
    // MOTORS IN REVERSE
    ADC_Process();
    r_reverse_on();
    ADC_Process();
    l_reverse_on();
    ADC_Process();
    if((ADC_Right_Detector>tracking_value_high) || (ADC_Left_Detector>tracking_value_high)){
      l_reverse_off();
      r_reverse_off();
      Five_msec_Delay(25); // pause for quarter of a second
      break;
    }
  }
    emitter_off();
}
//------------------------------------------------------------------------------
}