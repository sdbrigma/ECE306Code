//******************************************************************************
//
//  Description: This file contains code for motor control functions.
//
//
//  Steffon Brigman
//  Seppt 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//  File Name: motors.c
//  Gloabls Used: tmp
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
unsigned int tmp;
// NOTE: Macros with *_1 and *_2 naming denote left and right motors respectively.

void Init_Motors(void){
      /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Funcetion to turn off motor forward before any code runs.
*        Built with IAR Embedded Workbench Versiojn: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_Motors
*        Description: Initializes motors by turning them off.
*        Passed : no variables passed 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
// Turn off forward motors
  right_off();
  left_off();
// Turn off reverse motors
  r_reverse_off();
  l_reverse_off();
}

void motor_straight(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to run both motors to make a straight line for a specified time.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: motor_straight
*        Passed : time
*        Locals: i 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
   //int test = ISR_COUNT;
   while(ISR_COUNT<100){
     right_on(); // On for 500 ms
    //right_off();
    left_on();
    //left_off();
   }
  left_off();
  right_off();
  ISR_COUNT = 0;
  
  /*tmp = time + Time_Sequence;
  int i = ZERO;
while(i<time)
  {  
    right_on(STRAIGHT_SYNC); // On for 500 ms
    //right_off();
    left_on(STRAIGHT_SYNC);
    //left_off();
    i++;
  }
  left_off();
  right_off();*/
}

void motor_reverse(unsigned int time){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to run both motors to make a straight line in reverse for a specified time.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: motor_reverse
*        Passed : time
*        Locals: i 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  tmp = time + Time_Sequence;
  int i = ZERO;
while(i<time)
  {  
    r_reverse_on(); // On for 500 ms
    //r_reverse_off();
    l_reverse_on();
    //l_reverse_off();
    i++;
  }
  r_reverse_off();
  l_reverse_off();
}

void circle(void){ 
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Motor function that controls motors to make circle
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: circle
*        Passed : No varialbes passed
*        Locals: delay, i 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  int delay = ZERO;
  while(delay<SHAPE_DELAY){
    int i = ZERO;
    while(i<CIRCLE){
      //motor_straight(CIRCLE_STRAIGHT);
      left_on();
      left_off();
      i++;
    }
    if(delay<SHAPE_DELAY){
      right_on();
      right_off();
    }
    delay++;
    five_msec_sleep(HALF_SECOND);
  }
}

void figure_eight(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Motor function that controls motors to make a figure eight
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: figure_eight
*        Passed : No varialbes passed
*        Locals: delay, i 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  int delay = ZERO;
  while(delay<SHAPE_DELAY){
    int i = ZERO;
    while(i<FIGURE_1){// one complete circle running left motor
      //motor_straight(STRAIGHT_SYNC);
      left_on();
      left_off();
      i++;
    }
    i = ZERO;
    while(i<FIGURE_2){// one complete circle running right motor
      //motor_straight(STRAIGHT_SYNC);
      right_on();
      right_off();
      i++;
    }
    delay++;
    five_msec_sleep(HALF_SECOND);
  }
}

void triangle(void){ 
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Motor control function used to make two triangles
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: triangle
*        Passed : No varialbes passed
*        Locals: delay, i 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  int delay = ZERO;
  while(delay<SHAPE_DELAY){
    int i = ZERO;
    while(i<TRI_COUNT){
      //motor_straight(TRI_STRAIGHT);
      five_msec_sleep(TRI_DELAY);
      left_on();
      left_off();
      i++;
    }
    delay++;
    five_msec_sleep(HALF_SECOND);
  }
}
void right_off(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn off right motor.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: right_off
*        Passed : No varialbes passed
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  P3OUT &= ~R_FORWARD;
}

void r_reverse_off(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn off reverse on right motor.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: r_reverse_off
*        Passed : No varialbes passed
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  P3OUT &= ~R_REVERSE;
}

void left_off(void){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn off left motor.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: left_off
*        Passed : No varialbes passed
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
    P3OUT &= ~L_FORWARD;
}

void l_reverse_off(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn off reverse on LEFT motor.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: L_reverse_off
*        Passed : No varialbes passed
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  P3OUT &= ~L_REVERSE;
}

void right_on(){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn on right motor.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: right_on
*        Passed : time_synch
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: tmp
*******************************************************************************/
  // turn off right reverse before going forwrad
  r_reverse_off();
    P3OUT |= R_FORWARD;
}

void r_reverse_on(){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn run right motor in reverse
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: r_reverse_on
*        Passed : time_synch
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: tmp
*******************************************************************************/
  // turn off right forward before going in reverse
  right_off();
    P3OUT |= R_REVERSE;
}

void left_on(){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn on left motor.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: left_on
*        Passed : time_synch
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: tmp
*******************************************************************************/
  l_reverse_off();
    P3OUT |= L_FORWARD;
}

void l_reverse_on(){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Function to turn run left motor in reverse
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: l_reverse_on
*        Passed : time_synch
*        Locals: No variables defined
*        Returned: no values returned 
*        Globlas: tmp
*******************************************************************************/
  // Turn off left forwrad before going in reverse
  left_off();
    P3OUT |= L_REVERSE;
}