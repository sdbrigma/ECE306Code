//******************************************************************************
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

// Initialize Global Variables from macros.h
volatile unsigned char control_state[CNTL_STATE_INDEX];
volatile unsigned int Time_Sequence;
char led_smclk;
volatile char one_time;
extern char display_line_1[display_line_array];
extern char display_line_2[display_line_array];
extern char display_line_3[display_line_array];
extern char display_line_4[display_line_array];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
char posL1;
char posL2;
char posL3;
char posL4;
char size_count;
char big;
char switch_select;
volatile unsigned int A0_time_count;
volatile unsigned int ADC_Right_Detector;
volatile unsigned int ADC_Left_Detector;
volatile unsigned int ADC_Thumb;
volatile unsigned int ADC_Temp;
volatile unsigned int ADC_Bat;
volatile unsigned int ADC_Channel;
_Bool adc_RD_Enable;
_Bool adc_LD_Enable;
_Bool thumbEnable;
_Bool tempEnable;
_Bool batEnable;
unsigned int blackLineLeft;
unsigned int blackLineRight;
volatile unsigned int rxRead;
volatile unsigned int rxWrite;
volatile unsigned int txRead;
volatile unsigned int txWrite;
volatile char RX_Char[SMALL_RING_SIZE];
volatile char TX_Char[SMALL_RING_SIZE];
volatile _Bool transmitEnable;
volatile _Bool receiveEnable;
volatile _Bool baudToggle;
unsigned int tempCount;
unsigned int tempDisplay[SW_SEL_10];

void main(void){

//******************************************************************************
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// GLOBALS Declared  
// control_state[CNTL_STATE_INDEX]
// Time_Sequence
// led_smclk
// one_time
// display_line_1[display_line_array]
// display_line_2[display_line_array]
// display_line_3[display_line_array]
// display_line_4[display_line_array]
// *display_1
// *display_2
// *display_3
// *display_4
// posL1
// posL2
// posL3
// posL4
// size_count
// big
// switch_select
// A0_time_count
// ADC_Right_Detector
// ADC_Left_Detector
// ADC_Thumb
// ADC_Temp
// ADC_Bat
// ADC_Channel
// adc_RD_Enable
// adc_LD_Enable
// thumbEnable
// tempEnable
// batEnable
// blackLineLeft
// blackLineRight
// rxRead
// rxWrite
// txRead
// txWrite
// RX_Char[SMALL_RING_SIZE]
// TX_Char[SMALL_RING_SIZE]
// transmitEnable
// receiveEnable
// 
// Global: Time_Sequence, switch_select, display_1, display_2, display_3,
// display_4,  posL1, posL2, posL3, posL4, big, switch_select, A0_time_count,
// ADC_Out, rxRead, rxWrite, txRead, txWrite, RX_Char[SMALL_RING_SIZE],
// TX_Char[SMALL_RING_SIZE], transmitEnable, receiveEnable
//
// Passed:
//
// Local: temp
//
// Return:  VOID
//
//******************************************************************************

  Init_Ports();                             // Initialize Ports
  Init_Clocks();                            // Initialize Clock System 
  Init_Conditions();                        // Sets initial conditions for the LCD
  PJOUT |= BLINK_LED;                       // Turn LED 1 on to indicate boot
  Time_Sequence = INITIAL;                  // Sets Time_Sequence to 0
  Init_Timers();                            // Initialize Timers
  Five_msec_Delay(LIL_DELAY);               // Delay for the clock to settle
  PJOUT &= ~BLINK_LED;                      // Disable LED from boot wink
  Init_LEDs();                              // Initialize LEDs
  Init_LCD();                               // Initialize LCD
  Init_ADC();                               // Initialize ADC
  Init_Serial_UCA1(TRUE);                   // Initialize USCI-Baud Rate 9600
  blackLineLeft = ADC_Left_Detector;
  blackLineRight = ADC_Right_Detector;
  switch_select = INITIAL;
  A0_time_count = INITIAL;
  
// Initial Display Set
  display_1 = "NCSU";
  posL1 = LINE_POS_L3;
  display_2 = "WOLFPACK";
  posL2 = LINE_POS_L1;
  display_3 = "ECE306";
  posL3 = LINE_POS_L2;
  display_4 = "Ck.Woedy";
  posL4 = LINE_POS_L1;
  big = INITIAL;
  Display_Process();
  
//------------------------------------------------------------------------------
// Beginning of the "While" Operating System
//------------------------------------------------------------------------------
 while(ALWAYS) {                // Can the Operating system run
  
     switch(Time_Sequence){
    case CASE250:                               // 1000 msec  
      if(one_time){
        one_time = INITIAL;
      }
      Time_Sequence = INITIAL;                  // Resets clock
    case CASE200:                               // 1000 msec  
      if(one_time){
        one_time = INITIAL;
      }
    case CASE150:                               // 750 msec  
      if(one_time){
        one_time = INITIAL;
      }
    case CASE100:                               // 500 msec  
      if(one_time){
        one_time = INITIAL;
      }
    case  CASE50:                               // 250 msec  
      if(one_time){
        one_time = INITIAL;
      }
      Display_Process();        		// Update LCD Display
      break;                                
    default: break;  
  }
  ADC10_Process();
  Switches_Process();                           // Check for switch state change 
  if(Time_Sequence > CASE250){                  // Fail-safe for clock
    Time_Sequence = INITIAL;
  }
  if (A0_time_count > FIVE_SEC_COUNT) {
    A0_time_count = INITIAL;
  }
 }
}