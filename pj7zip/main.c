//******************************************************************************
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Steffon Brigman
//  Nov 2015
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
volatile unsigned int IOTRead;
volatile char RX_Char[SMALL_RING_SIZE];
volatile char IOT_RX[SMALL_RING_SIZE];
volatile _Bool receiveEnable;
volatile _Bool baudToggle;

void main(void){

//******************************************************************************
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Steffon Brigman
//  Nov 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
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
  Time_Sequence = INITIAL;                  // Sets Time_Sequence to 0
  Init_Timers();                            // Initialize Timers
  Five_msec_Delay(LIL_DELAY);               // Delay for the clock to settle
  Init_LCD();                               // Initialize LCD
  Init_ADC();                               // Initialize ADC
  Init_Serial_UCA0(TRUE);                   // Initialize USCI-Baud Rate 9600
  Init_Serial_UCA1(TRUE);                   // Initialize USCI-Baud Rate 9600
  receiveEnable = FALSE;
  blackLineLeft = ADC_Left_Detector;
  blackLineRight = ADC_Right_Detector;
  switch_select = INITIAL;
  A0_time_count = INITIAL;
  int i = INITIAL;
  
// Initial Display Set
  display_1 = " Steffon  ";
  posL1 = LINE_POS_L0;
  display_2 = "Project 07";
  posL2 = LINE_POS_L0;
  display_3 = " Brigman  ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  Display_Process();
  
  while (ALWAYS) {
    if (!(P4IN & SW1)) {
      Five_msec_Delay(LIL_SW_DELAY);
      break;
    }
    if (!(P4IN & SW2)) {
      Five_msec_Delay(LIL_SW_DELAY);
      break;
    }
  }
  
  // Initial Menu
  display_1 = "          ";
  posL1 = LINE_POS_L0;
  display_2 = "          ";
  posL2 = LINE_POS_L0;
  display_3 = "          ";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  Display_Process();
  
//------------------------------------------------------------------------------
// Beginning of the "While" Operating System
//------------------------------------------------------------------------------
 while(ALWAYS) {                // Can the Operating system run
  
     switch(Time_Sequence){
    case CASE250:                              
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

      break;                                
    default: break;  
  }
  
  // Update all ADC channels
  for(i = SW_SEL_5; i > INITIAL; i--) {
  ADC10_Process();
  }
  
  // START MAIN MENU//
  
  // ITEM ONE
  if ((ADC_Thumb > ITEM_ONE) && (ADC_Thumb <= ITEM_TWO)) {
    Display_Config();
  }
  // ITEM TWO
  else if ((ADC_Thumb > ITEM_TWO) && (ADC_Thumb <= ITEM_THREE)) {
    Display_IOTCMD();
  }
  // ITEM THREE
  else if ((ADC_Thumb > ITEM_THREE) && (ADC_Thumb <= ITEM_FOUR)) {
    Display_Backdoor();
  }
  // ITEM FOUR
  else if ((ADC_Thumb > ITEM_FOUR) && (ADC_Thumb <= ITEM_FIVE)) {
    Display_Detect();
  }
  // ITEM FIVE
  else if ((ADC_Thumb > ITEM_FIVE) && (ADC_Thumb <= ITEM_SIX)) {
    Display_Calibrate();
  }
  // ITEM SIX
  else if ((ADC_Thumb > ITEM_SIX) && (ADC_Thumb <= ITEM_SEVEN)) {
    Display_Config();
  }
  // ITEM SEVEN
  else if ((ADC_Thumb > ITEM_SEVEN) && (ADC_Thumb <= ITEM_EIGHT)) {
    Display_IOTCMD();
  }
  // ITEM EIGHT
  else if ((ADC_Thumb > ITEM_EIGHT) && (ADC_Thumb <= ITEM_NINE)) {
    Display_Backdoor();
  }
  // ITEM NINE
  else if ((ADC_Thumb > ITEM_NINE) && (ADC_Thumb <= ITEM_TEN)) {
    Display_Detect();
  }
  // ITEM TEN
  else if ((ADC_Thumb > ITEM_TEN) && (ADC_Thumb <= ITEM_END)) {
    Display_Calibrate();
  }
  else {

  }
  
  Display_Process();        		        // Update LCD Display
  Five_msec_Delay(LIL_DELAY);
  
  Switches_Process();                           // Check for switch state change 
  if(Time_Sequence > CASE250){                  // Fail-safe for clock
    Time_Sequence = INITIAL;
  }
  if (A0_time_count > FIVE_SEC_COUNT) {
    A0_time_count = INITIAL;
  }
 }
}