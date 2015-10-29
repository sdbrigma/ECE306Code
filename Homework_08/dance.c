  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions is an interrupt used to control the motors.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: dance.c
*        Passed : No variables passed 
*        Locals: No locals variables
*        Returned: no values returned 
*        Globlas: display_1 through display_4 and posL1 through posL4
*******************************************************************************/
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void twerk(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This functions is an interrupt used to control the motors.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: twerk.c
*        Passed : No variables passed 
*        Locals: No locals variables
*        Returned: no values returned 
*        Globlas: ISR_COUNT, display_1 through display_4, and posL1 through posL4
*******************************************************************************/
    while(ISR_COUNT<TWO_s){ // pause for 2 s
   left_off();
   right_off();
  }
  ISR_COUNT = ZERO;
  
     display_1 = "=====";
    posL1 = ZERO;
    display_2 = "FORWARD";
    posL2 = ZERO;
    display_3 = "=====";
    posL3 = ZERO;
    display_4 = "=====";
    posL4 = ZERO;
    Display_Process();
  
  // STRAIGHT
     while(ISR_COUNT<STRAIGHT_TIME){ // straight for 1 s
     right_on();
    left_on();
   }
  left_off();
  right_off();
  ISR_COUNT = ZERO;
//------------------------------------------------------------------------------  

  while(ISR_COUNT<PAUSE){ // pause for 1/2 s
   left_off();
   right_off();
  }
  ISR_COUNT = ZERO;
  
  display_1 = "=====";
    posL1 = ZERO;
    display_2 = "REVERSE";
    posL2 = ZERO;
    display_3 = "=====";
    posL3 = ZERO;
    display_4 = "======";
    posL4 = ZERO;
    Display_Process();
  
  // REVERSE for 2 seconds
  while(ISR_COUNT<REVERSE_TIME){
    l_reverse_on();
    r_reverse_on();
  }
  
  l_reverse_off();
  r_reverse_off();
  ISR_COUNT = ZERO;
  
//------------------------------------------------------------------------------  
  
  while(ISR_COUNT<PAUSE){ // pause for 1/2 s
   left_off();
   right_off();
  }
  ISR_COUNT = ZERO;
  
  display_1 = "=====";
    posL1 = ZERO;
    display_2 = "FORWARD";
    posL2 = ZERO;
    display_3 = "=====";
    posL3 = ZERO;
    display_4 = "=====";
    posL4 = ZERO;
    Display_Process();
  
    // straight
     while(ISR_COUNT<STRAIGHT_TIME){ // straight for 1s
     right_on();
    left_on();
   }
  left_off();
  right_off();
  ISR_COUNT = ZERO;
//------------------------------------------------------------------------------
  while(ISR_COUNT<PAUSE){ // pause for 1/2 s
   left_off();
   right_off();
  }
  ISR_COUNT = ZERO;
  
     display_1 = "=====";
    posL1 = ZERO;
    display_2 = "Clockwise";
    posL2 = ZERO;
    display_3 = "=====";
    posL3 = ZERO;
    display_4 = "=====";
    posL4 = ZERO;
    Display_Process();
  
  // CW CIrcle
  while(ISR_COUNT<STRAIGHT_TIME){
    left_on();
    r_reverse_on();
  }
  left_off();
  r_reverse_off();
  ISR_COUNT = ZERO;
//------------------------------------------------------------------------------
   while(ISR_COUNT<PAUSE){ // pause for 1/2 s
   left_off();
   right_off();
  }
  ISR_COUNT = ZERO;
  
     display_1 = "=====";
    posL1 = ZERO;
    display_2 = "CCW CIRCLE";
    posL2 = ZERO;
    display_3 = "=====";
    posL3 = ZERO;
    display_4 = "=====";
    posL4 = ZERO;
    Display_Process();
  
  while(ISR_COUNT<STRAIGHT_TIME){
    right_on();
    l_reverse_on();
  }
  right_off();
  l_reverse_off();
  ISR_COUNT = ZERO;
  
  display_1 = "Embedded";
    posL1 = SW2_posL1;
    display_2 = "Systems";
    posL2 = SW2_posL1;
    display_3 = "Rock!";
    posL3 = SW2_posL1;
    display_4 = "Go Pack!";
    posL4 = SW2_posL1;
    Display_Process();
 }