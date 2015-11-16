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
*        Globlas: Listed below includes section
*******************************************************************************/

// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void line_dance(void){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions is an interrupt used to control the motors.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: line_dance
*        Passed : No variables passed 
*        Locals: i
*        Returned: no values returned 
*        Globlas: Uses all gloabls listed in the globals section
*******************************************************************************/
  emitter_on();
    display_1 = "==========";
    posL1 = ZERO;
    display_2 = "FORWARD";
    posL2 = ZERO;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();

  while(ALWAYS){// loop to travel straight
    // read left and right detectors
    /*if(ADC_Left_Detector>tracking_value_high){
      Five_msec_Delay(25); // pause for quarter of a second
      break;
    }*/
    ADC_Process();ADC_Process();ADC_Process();ADC_Process();ADC_Process();
    motor_straight();
    ADC_Process();
    if((ADC_Right_Detector>tracking_value_high)||(ADC_Left_Detector>tracking_value_high)){
      Five_msec_Delay(QUARTER_WAIT); // pause for quarter of a second
      break;
    }    
  }
  
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "REVERSE";
    posL2 = ZERO;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();

  
    unsigned int i = ZERO; // counter for time taken to reverse
    //ISR_COUNT = ZERO;
  while(ALWAYS){// loop to travel in reverse
    // give motors enough time to get away from black line
    if(i == ZERO){
        motor_reverse(PAUSE);
        i++;
    }
    i++;
    // MOTORS IN REVERSE
    ADC_Process();
    r_reverse_on();
    l_reverse_on();
    ADC_Process();
    if((ADC_Right_Detector>(tracking_value_high*avg)) || (ADC_Left_Detector>(tracking_value_high*avg))){
      l_reverse_off();
      r_reverse_off();
      Five_msec_Delay(QUARTER_WAIT); // pause for quarter of a second
      break;
    }
  }
  ISR_COUNT = ZERO;
  emitter_off();
  display_1 = "==========";
    posL1 = ZERO;
    display_2 = "FORWARD";
    posL2 = ZERO;
    display_3 = "==========";
    posL3 = ZERO;
    display_4 = "          ";
    posL4 = ZERO;
    Display_Process();
  
  i = i / time_correction;
  unsigned int a = ZERO;
  while(a<i){
    motor_straight();
    a++;
  }
  Five_msec_Delay(QUARTER_WAIT);
  
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
  while(ISR_COUNT<clock_wise_time){
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
  while(ISR_COUNT<clock_wise_time){
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
    posL3 = ZERO;
    display_4 = "==========";
    posL4 = ZERO;
    Display_Process();
}

void emitter_on(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function turns on the emitter
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: emitter_on
*        Passed : No variables passed 
*        Locals: No variables declared
*        Returned: no values returned 
*        Globlas: None used
*******************************************************************************/
  P1OUT |= IR_LED;
}

void emitter_off(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function turns off the emitter
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: emitter_off
*        Passed : No variables passed 
*        Locals: No variables declared
*        Returned: no values returned 
*        Globlas: None used
*******************************************************************************/
  P1OUT &= ~IR_LED;
}

void calibrate_detector(void){
      /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This function calibrates the detectors for the ADC
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: calibrate_detectors
*        Passed : No variables passed 
*        Locals: No variables declared
*        Returned: no values returned 
*        Globlas: Uses all gloabls listed in the globals section
*******************************************************************************/
  display_1 = "==========";
  posL1 = ZERO;
  display_2 = "CALIBRATE";
  posL2 = ZERO;
  display_3 = "DETECTORS";
  posL3 = ZERO;
  display_4 = "==========";
  posL4 = ZERO;
  Display_Process();
  ISR_COUNT = ZERO;
  while(ISR_COUNT<calibrate){
    ADC_Process();
    ambience = (ADC_Right_Detector + ADC_Left_Detector) / avg;
  }
  ISR_COUNT = ZERO;
  ambience = ADC_RESOLUTION - ambience; // ambience correction factor
  ambience = ambience * avg;
    
  emitter_on();
  while(ISR_COUNT < calibrate){
    ADC_Process();
    tracking_value = (ADC_Right_Detector + ADC_Left_Detector) / avg;
  }
  ISR_COUNT = ZERO;
  tracking_value_high = tracking_value + ambience;
  tracking_value_low = tracking_value - ambience;
  emitter_off();  
}