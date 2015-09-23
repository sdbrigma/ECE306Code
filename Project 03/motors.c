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

void Init_Motors(void){
  // Funcetion to turn off motor forward before any code runs.
  right_off();
  left_off();
}

void motor_straight(unsigned int test_time){
  // Function to run both motors to make a straight line for a specified time.
  //tmp = Time_Sequence+time;
  int i = 0;
while(i<5) // Stop after Time_Sequence has counted up to new time.
  {  
    left_on();
    five_msec_sleep(2);
    left_off();
    right_on();
    five_msec_sleep(2);
    right_off();
    i++;
  }
  left_off();
  right_off();
}

void right_off(void){
  // Function to turn off right motor.
  P3OUT &= ~R_FORWARD;
}

void left_off(void){
  // Function to turn off left motor.
    P3OUT &= ~L_FORWARD;
}

void right_on(void){
  // Function to turn on right motor.
  P3OUT |= R_FORWARD;
  five_msec_sleep(2);
}

void left_on(void){
  // Function to turn on left motor.
  P3OUT |= L_FORWARD;
}
