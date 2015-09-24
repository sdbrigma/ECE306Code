//******************************************************************************
//
//  Description: This file contains code for motor control functions.
//
//
//  Steffon Brigman
//  Seppt 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
unsigned int tmp;
//volatile unsigned int Time_Sequence;

void Init_Motors(void){
  // Funcetion to turn off motor forward before any code runs.
  right_off();
  left_off();
}

void motor_straight(unsigned int time){
  // Function to run both motors to make a straight line for a specified time.
  //Time_Sequence = 0;
  tmp = time + Time_Sequence;
  int i = 0;
while(i<(1*time))
  {  
    //five_msec_sleep(STRAIGHT_SYNCH);
    right_on(1); // On for 500 ms
    right_off();
    left_on(1);
    left_off();
    //five_msec_sleep(1);
    //Time_Sequence++;
    i++;
  }
  left_off();
  right_off();
}

void circle(void){
  //motor_straight(2);
  int delay = 0;
  while(delay<2){
    int i = 0;
    while(i<75){
      motor_straight(2);
      left_on(13);
      left_off();
      i++;
    }
    delay++;
    left_on(5);
    left_off();
    five_msec_sleep(FULL_SECOND);
  }
}

void triangle(void){
  //int delay = 0;
  int i = 0;
  while(i<3){
    motor_straight(70);
    five_msec_sleep(10);
    left_on(90);
    left_off();
    i++;
  }
}
void right_off(void){
  // Function to turn off right motor.
  P3OUT &= ~R_FORWARD;
}

void left_off(void){
  // Function to turn off left motor.
    P3OUT &= ~L_FORWARD;
}

void right_on(unsigned int time_synch){
  // Function to turn on right motor.
    //Time_Sequence = 0;
    tmp = time_synch + Time_Sequence;
  while(Time_Sequence<tmp)
  {
    P3OUT |= R_FORWARD;
    //five_msec_sleep(1);
  }
}

void left_on(unsigned int time_synch){
  // Function to turn on left motor.
    //Time_Sequence = 0;
    tmp = time_synch + Time_Sequence;
  while(Time_Sequence<tmp)
  {
    P3OUT |= L_FORWARD;
  }
}
