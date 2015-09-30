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
extern char posL4;
int button_counter1 = 0;
int button_counter2 = 0;
void Switches_Process(void){
//------------------------------------------------------------------------------
// Switch proccess sets LCD text when SW1 and SW2 are pressed
  if (!(P4IN & SW1)){
    /*display_1 = "Shape?";
    posL1 = 0;
    display_2 = ">1) Circle";
    posL2 = 0;
    display_3 = ">2) 3Angle";
    posL3 = 0;
    display_4 = ">3) Figure8";
    posL4 = 0;*/
    display_1 = "NCSU";
    posL1 = SW1_posL1;
    display_2 = "WOLFPACK";
    posL2 = SW1_posL2;
    display_3 = "ECE306";
    posL3 = SW1_posL3;
    display_4 = "S Brigman";
    posL4 = SW1_posL4;
    five_msec_sleep(HALF_SECOND); // wait 3s to run motor
    //figure_eight();
    motor_straight(1000);
  }
  if (!(P4IN & SW2)) {
    /*while(button_counter2!=0){
      button_counter2++;
      switch(button_counter2-1){
      case 1:
        display_1 = "";
        posL1 = 0;
        display_2 = "Driving";
        posL2 = 0;
        display_3 = "Straight";
        posL3 = 0;
        display_4 = "";
        posL4 = 0;
        Display_Process();
        five_msec_sleep(750);
         motor_straight(5);
         button_counter2 = 0;
         break;
      case 2:
        display_1 = "";
        posL1 = 0;
        display_2 = "";
        posL2 = 0;
        display_3 = "Making A Circle";
        posL3 = 0;
        display_4 = "";
        posL4 = 0;
        Display_Process();
        five_msec_sleep(750);
         circle();
         button_counter2 = 0;
         break;
      case 3:
        display_1 = "";
        posL1 = 0;
        display_2 = "";
        posL2 = 0;
        display_3 = "Making 3Angle";
        posL3 = 0;
        display_4 = "";
        posL4 = 0;
        Display_Process();
        five_msec_sleep(750);
        motor_straight(5);
        button_counter2 = 0;
        break;
      case 4:
      display_1 = "";
        posL1 = 0;
        display_2 = "";
        posL2 = 0;
        display_3 = "Figure8";
        posL3 = 0;
        display_4 = "";
        posL4 = 0;
        Display_Process();
        five_msec_sleep(FULL_SECOND);
        motor_straight(5);
        button_counter2 = 0;
        break;
      default:
        display_1 = "";
        posL1 = 0;
        display_2 = "No Choice";
        posL2 = 0;
        display_3 = "Was Made!";
        posL3 = 0;
        display_4 = "";
        posL4 = 0;
        Display_Process();
        five_msec_sleep(FULL_SECOND);
        button_counter2 = 0;
        break;
      }
    }*/
    display_1 = "Embedded";
    posL1 = SW2_posL1;
    display_2 = "Systems";
    posL2 = SW2_posL1;
    display_3 = "Rock!";
    posL3 = SW2_posL1;
    display_4 = "Go Pack!";
    posL4 = SW2_posL1;
    five_msec_sleep(HALF_SECOND); // wait 3s to run motor
    if(button_counter2>0){
      circle();
      button_counter2 = 0;
    }
    else{
      triangle();
      button_counter2++;
    }
  }
//------------------------------------------------------------------------------
}