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
volatile char CPU_Char_Rx[IOT_RING_SIZE];
volatile char CPU_Char_Tx[IOT_RING_SIZE];
unsigned int inc = ZERO;
unsigned int color = ALWAYS;
volatile char USB_Char_Rx[IOT_RING_SIZE];
volatile char USB_Char_Tx[IOT_RING_SIZE];
unsigned int usb_rx_ring_wr;
unsigned int usb_rx_ring_rd;
unsigned int usb_tx_ring_wr;
unsigned int usb_tx_ring_rd;

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
  Time_Sequence = ZERO;                        // 
  Init_Timers();                            // Initialize Timers
  Five_msec_Delay(QUARTER_SECOND);          // 250 msec delay for the clock to settle
  Init_LEDs();                              // Initialize LEDs
  Init_LCD();                               // Initialize LCD
  Init_Motors();                            // Turns off both motors
  Init_ADC();
  Init_Serial_UCA1();
  Init_Serial_UCA0();
  //Init_IOT();
  
//             1234567890
  clearLCD();
  setLCD("NCSU",SW1_posL1,"WOLFPACK",SW1_posL2,"ECE306",SW1_posL3,"S Brigman",SW1_posL4);
  big = ZERO;
  ADC_Channel = Thumbwheel;
  
  while (ALWAYS) {
    if (!(P4IN & SW1)) {
      Five_msec_Delay(switch_delay);
      break;
    }
    if (!(P4IN & SW2)) {
      Five_msec_Delay(switch_delay);
      break;
    }
  }
  
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
  
  // Update all ADC channels
  for(i = SW_SEL_5; i > ZERO; i--) {
  ADC_Process();
  }
  
  // START MAIN MENU//
  
  // ITEM ONE
  if ((ADC_Thumb > ZERO) && (ADC_Thumb <= MENU1)) {
    Display_Config();
  }
  // ITEM TWO
  else if ((ADC_Thumb > MENU1) && (ADC_Thumb <= MENU2)) {
    Display_IOTCMD();
  }
  // ITEM THREE
  else if ((ADC_Thumb > MENU2) && (ADC_Thumb <= MENU3)) {
    Display_Backdoor();
  }
  // ITEM FOUR
  else if ((ADC_Thumb > MENU3) && (ADC_Thumb <= MENU4)) {
    Display_Detect();
  }
  // ITEM FIVE
  else if ((ADC_Thumb > MENU4) && (ADC_Thumb <= MENU5)) {
    Display_Calibrate();
  }
  // ITEM SIX
  else if ((ADC_Thumb > MENU5) && (ADC_Thumb <= MENU6)) {
    Display_Config();
  }
  // ITEM SEVEN
  else if ((ADC_Thumb > MENU6) && (ADC_Thumb <= MENU7)) {
    Display_IOTCMD();
  }
  // ITEM EIGHT
  else if ((ADC_Thumb > MENU7) && (ADC_Thumb <= MENU8)) {
    Display_Backdoor();
  }
  // ITEM NINE
  else if ((ADC_Thumb > MENU8) && (ADC_Thumb <= MENU9)) {
    Display_Detect();
  }
  // ITEM TEN
  else if ((ADC_Thumb > MENU9) && (ADC_Thumb <= MENU10)) {
    Display_Calibrate();
  }
  else {

  }
  
  Display_Process();        		        // Update LCD Display
  Five_msec_Delay(LIL_DELAY);
  
  Switches_Process();                       // Check for switch state change 
  if(Time_Sequence > FULL_SECOND){ // 1000 msec
    Time_Sequence = ZERO;
  }
 }
//------------------------------------------------------------------------------
}
