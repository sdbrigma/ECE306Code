/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains code that runs motor with ADC values
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: line-dance.c
*        Passed : No variables passed 
*        Locals: No locals variables
*        Returned: no values returned 
*        Globlas: No variables used
*******************************************************************************/

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
extern char posL4;
extern unsigned int ADC_Right_Detector;
extern unsigned int ADC_thumb;
extern unsigned int ADC_Left_Detector;
extern unsigned int tracking_value;


void line_dance(void){  
  emitter_on();
    display_1 = "==========";
    posL1 = ZERO;
    display_2 = "FORWARD";
    posL2 = 2;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
  
  while(ALWAYS){// loop to travel straight
    // read left and right detectors
    ADC_Process();
    motor_straight();
    if((ADC_Left_Detector>=tracking_value) || (ADC_Right_Detector>=tracking_value)){
      Five_msec_Delay(25); // pause for quarter of a second
      break;
    }    
  }
  
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "REVERSE";
    posL2 = 2;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
  
    unsigned int i = 0; // counter for time taken to reverse
  while(ALWAYS){// loop to travel in reverse
    // give motors enough time to get away from black line
    if(i == 0){
        motor_reverse(50);
    }
    // MOTORS IN REVERSE
    ADC_Process();
    r_reverse_on();
    l_reverse_on();
    i++;
    if((ADC_Right_Detector>=tracking_value) || (ADC_Left_Detector>=tracking_value)){
      i = ISR_COUNT;
      l_reverse_off();
      r_reverse_off();
      Five_msec_Delay(25); // pause for quarter of a second
      break;
    }
  }
  emitter_off();
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "FORWARD";
    posL2 = 2;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
  
  i = i / 2;
  while(i>ZERO){
    i--;
    motor_straight();
  }
  
  ISR_COUNT = ZERO;
  Five_msec_Delay(25);
  
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "CLOCKWISE";
    posL2 = ZERO;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
  
  // CW Circle
  while(ISR_COUNT<225){
    left_on();
    r_reverse_on();
  }
  left_off();
  r_reverse_off();
  ISR_COUNT = ZERO;
  
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "COUNTER";
    posL2 = ZERO;
    display_3 = "CLOCKWISE";
    posL3 = ZERO;
    display_4 = "==========";
    posL4 = ZERO;
    Display_Process();
  
  // CCW Circle
  while(ISR_COUNT<225){
    right_on();
    l_reverse_on();
  }
  right_off();
  l_reverse_off();
  ISR_COUNT = ZERO;
  
    display_1 = "==========";
    posL1 = ZERO;
    display_2 = "==========";
    posL2 = ZERO;
    display_3 = "DONE!!!";
    posL3 = 2;
    display_4 = "==========";
    posL4 = ZERO;
    Display_Process();
}

void emitter_on(void){
  P1OUT |= IR_LED;
}

void emitter_off(void){
  P1OUT &= ~IR_LED;
}

void calibrate_detector(void){
  display_1 = "==========";
  posL1 = ZERO;
  display_2 = "CALIBRATE";
  posL2 = ZERO;
  display_3 = "DETECTORS";
  posL3 = ZERO;
  display_4 = "==========";
  posL4 = ZERO;
  Display_Process();
  
  Five_msec_Delay(100);
  
  int i = 0;
  emitter_on();
  while(i < 10){
    ADC_Process();
    tracking_value = ADC_Right_Detector + ADC_Left_Detector / 2;
  }
  emitter_off();
  
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "==========";
    posL2 = ZERO;
    display_3 = "DONE!!!";
    posL3 = 2;
    display_4 = "==========";
    posL4 = ZERO;
    Display_Process();
  Five_msec_Delay(200);
  
}