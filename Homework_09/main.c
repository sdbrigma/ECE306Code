//******************************************************************************
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

// Global Variables
volatile unsigned char control_state[CNTL_STATE_INDEX];
volatile unsigned int Time_Sequence;
char led_smclk;
int ISR_COUNT = ZERO;
int UPDATE_LCD = ZERO;
unsigned int ADC_Thumb;
unsigned int ADC_Right_Detector;
unsigned int ADC_Left_Detector;
unsigned int ADC_Temp;
unsigned int ADC_Bat;
unsigned int tracking_value_high;
unsigned int tracking_value_low;
unsigned int tracking_value;
unsigned int ambience;
int ADC_Channel = ZERO;
volatile char one_time;
extern char display_line_1[DISPLAY_LENGTH];
extern char display_line_2[DISPLAY_LENGTH];
extern char display_line_3[DISPLAY_LENGTH];
extern char display_line_4[DISPLAY_LENGTH];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
char posL1;
char posL2;
char posL3;
char posL4;
char size_count;
unsigned int cpu_rx_ring_wr;
unsigned int cpu_rx_ring_rd;
unsigned int cpu_tx_ring_wr;
unsigned int cpu_tx_ring_rd;
char big;
volatile char CPU_Char_Rx[16];
volatile char CPU_Char_Tx[16];
unsigned int inc = ZERO;
unsigned int color = ALWAYS;

void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
// 
//------------------------------------------------------------------------------
  Init_Ports();
  Init_Clocks();                            // Initialize Clock System 
  Init_Conditions();
  PJOUT |= LED1;                            // Turn LED 1 on to indicate boot
  Time_Sequence = ZERO;                        // 
  Init_Timers();                            // Initialize Timers
  five_msec_sleep(QUARTER_SECOND);          // 250 msec delay for the clock to settle
  Init_LEDs();                              // Initialize LEDs
  Init_LCD();                               // Initialize LCD
  Init_Motors();                            // Turns off both motors
  Init_ADC();
  Init_Serial_UCA1();
  
//             1234567890
  clearLCD();
  setLCD("NCSU",SW1_posL1,"WOLFPACK",SW1_posL2,"ECE306",SW1_posL3,"S Brigman",SW1_posL4);
  big = ZERO;
  ADC_Channel = Thumbwheel;
//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
 while(ALWAYS) {  
   ADC_Process();
   // Can the Operating system run
  switch(Time_Sequence){
    case FULL_SECOND:                               // 1000 msec  
      if(one_time){
        //Init_LEDs();                        // Initialize LEDs
        one_time = ZERO;
      }
      Time_Sequence = ZERO;                    // 
    case THOU_MS:                               // 1000 msec  
      if(one_time){
        //P3OUT |= LED5;                      // Change State of LED 5
        one_time = ZERO;
      }
    case THIRD_SECOND:                               // 750 msec  
      if(one_time){
        //PJOUT |= LED3;                      // Change State of LED 3
        //P3OUT |= LED6;                      // Change State of LED 6
        one_time = ZERO;
      }
    case HALF_SECOND:                               // 500 msec  
      if(one_time){
        //PJOUT |= LED2;                      // Change State of LED 2
        //P3OUT |= LED7;                      // Change State of LED 7
        one_time = ZERO;
      }
    case  QUARTER_SECOND:                               // 250 msec  
      if(one_time){
        //PJOUT |= LED1;                      // Change State of LED 1
        //P3OUT |= LED8;                      // Change State of LED 8
        one_time = ZERO;
      }
      Display_Process();
      break;                                // 
    default: break; 
  }
  Switches_Process();                       // Check for switch state change 
  if(Time_Sequence > FULL_SECOND){ // 1000 msec
    Time_Sequence = ZERO;
  }
 }
//------------------------------------------------------------------------------
}
