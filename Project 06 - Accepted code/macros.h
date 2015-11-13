//******************************************************************************
//
//  Description: This file contains the systems macros
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

// Preprocessing logic statements to avoid reinitialization
#ifndef MACROS_H
#define MACROS_H

// Required defines
// In the event the universe no longer exists, this bit will reset

#define INITIAL (0)
#define INITIALIZE_CHAR  (0x00)
#define ALWAYS (1)
#define FALSE (0)                    
#define TRUE (1)
#define CNTL_STATE_INDEX (3) // Control States
//#define LED1 (0x01) // LED 1
//#define LED2 (0x02) // LED 2
//#define LED3 (0x04) // LED 3
//#define LED5 (0x10) // LED 5
//#define LED6 (0x20) // LED 6
//#define LED7 (0x40) // LED 7
//#define LED8 (0x80) // LED 8

#define CASE50 (50)
#define CASE100 (100)
#define CASE150 (150)
#define CASE200 (200)
#define CASE250 (250)

// Port 1
#define V_DETECT_R (0x01)
#define V_DETECT_L  (0x02)
#define IR_LED (0x04)
#define V_THUMB (0x08)
#define SPI_CS_LCD (0x10)
#define SA0_LCD (0x20)
#define SPI_SIMO (0x40)
#define SPI_SOMI (0x80)


// Port 2
#define USB_TXD (0x01)
#define USB_RXD (0x02)
#define SPI_SCK (0x04)
#define P2PIN3 (0x08)
#define P2PIN4 (0x10)
#define CPU_TXD (0x20)
#define CPU_RXD (0x40)
#define P2PIN7 (0x80)


// Port 3
#define P3X (0x01)
#define P3Y (0x02)
#define P3Z (0x04)
#define LCD_BACKLITE (0x08)
#define R_FORWARD (0x10)
#define R_REVERSE (0x20)
#define L_FORWARD (0x40)
#define L_REVERSE (0x80)

#define SET_SMCLK (0x10)

#define USE_R_FORWARD (0x00)
#define USE_SMCLK (0x01)


// Port 4
#define SW1 (0x01) // Switch 1
#define SW2 (0x02) // Switch 2


// Port J
#define IOT_FACTORY (0x01)
#define IOT_WAKEUP (0x02)
#define IOT_STA_MINIAP (0x04)
#define RESET (0x08)
#define XINR (0x10) // XINR
#define XOUTR (0x20) // XOUTR
#define CLEAR_REGISTER (0X0000)


// LCD
#define LCD_HOME_L1 (0x80)
#define LCD_HOME_L2 (0xA0)
#define LCD_HOME_L3 (0xC0)
#define LCD_HOME_L4 (0xE0)

#define BLINK_LED (0x01) // Allow LED to Blink
#define LCD_LINE_1 (0x80) // Position Cursor at Character 01 of Line 1
#define LCD_LINE_2 (0xC0) // Position Cursor at Character 01 of Line 2
#define GPS_ONOFF (0x08)
#define USE_LED5 (0x40)
#define USE_NFETS (0xA0) 
#define CLEAR_DISPLAY (0x01)

#define CSLOCK (0x01) // Any incorrect password locks registers

#define display_line_array (11)
#define LINE_POS_L0 (0)
#define LINE_POS_L1 (1)
#define LINE_POS_L2 (2)
#define LINE_POS_L3 (3)
#define LINE_POS_L4 (4)
#define LINE_POS_L5 (5)
#define LINE_POS_L6 (6)
#define LINE_POS_L7 (7)
#define LINE_POS_L8 (8)
#define LINE_POS_L9 (9)

// Display Modes
#define ORIGINAL 

// Clocks Macros
#define FLLN_BITS (0x03ffu)
#define FLLN_255 (0x00ffu)

// Timer Macros
#define TA0CCR0_INTERVAL (125)	        // Used to set the A0 timer to 1 msec

// A0 Macros
#define FOUR_CYCLES (4)
#define TEN_ITERATIONS (10)
#define FIVE_MSEC (5)
#define WFIFTY_MSEC (49)
#define FIFTY_MSEC (50)
#define HALF_SEC_COUNT (500)
#define ONE_SEC_COUNT (1000)
#define TWO_SEC_COUNT (2000)
#define THREE_HALF_SEC_COUNT (3500)
#define FOUR_SEC_COUNT (4000)
#define FIVE_SEC_COUNT (5000)
#define TEN_SEC_COUNT (10000)

// Switch Macros
#define LIL_DELAY (25)
#define LIL_SW_DELAY (31)
#define BIGGER_DELAY (75)
#define BIG_DELAY (50)
#define TWO_CYCLES (2)
#define SW_SEL_0 (0)
#define SW_SEL_1 (1)
#define SW_SEL_2 (2)
#define SW_SEL_3 (3)
#define SW_SEL_4 (4)
#define SW_SEL_5 (5)
#define SW_SEL_6 (6)
#define SW_SEL_7 (7)
#define SW_SEL_8 (8)
#define SW_SEL_9 (9)
#define SW_SEL_10 (10)
#define SW_SEL_11 (11)
#define SW_SEL_12 (12)

// ADC Macros
#define Right_Detector (0)
#define Left_Detector (1)
#define Thumbwheel (2)
#define CHANNEL_A10 (3)
#define CHANNEL_A11 (4)

// USCI Macros
#define USCI_val8 (0x08)
#define SMALL_RING_SIZE (16)
#define BAUD_9600 (0x4911)
#define BAUD_115200 (0x5551)
#define TRANSMIT_SYNC (0x55)
#define BRW9600 (52)
#define BRW115200 (4)

#define TILDE (0x7E)
#define HEX_ROUND (0x2F)
#define HEX_ZERO (0x30)
#define HEX_ONE (0x31)
#define HEX_TWO (0x32)
#define HEX_THREE (0x33)
#define HEX_FOUR (0x34)
#define HEX_FIVE (0x35)
#define HEX_SIX (0x36)
#define HEX_SEVEN (0x37)
#define HEX_EIGHT (0x38)
#define HEX_NINE (0x39)
#define HEX_TEN (0x3A)
#define HEX_A (0x41)
#define HEX_B (0x42)
#define HEX_C (0x43)
#define HEX_D (0x44)
#define HEX_E (0x45)
#define HEX_F (0x46)
#define HEX_Anorm (0x0A)
#define HEX_Bnorm (0x0B)
#define HEX_Cnorm (0x0C)
#define HEX_Dnorm (0x0D)
#define HEX_Enorm (0x0E)
#define HEX_Fnorm (0x0F)
#define HEX_SBTRCT (0x10)
#define HEX_GARBAGE (0x7D)
#define HEX_GARBAGE2 (0x7C)


// HEX Macros
#define FIRST_BYTE (0x00FF)
#define SECOND_BYTE (0xFF00)
#define FIRST_NYBL (0x0F)
#define SECOND_NYBL (0xF0)
#define FIRST_NIBBLE (0x000F)
#define SECOND_NIBBLE (0x00F0)
#define THIRD_NIBBLE (0x0F00)
#define FOURTH_NIBBLE (0xF000)
#define SHIFT_4 (4)
#define SHIFT_8 (8)
#define SHIFT_12 (12)
#define LETTER_START (0x00A)
#define LETTER_OP (0x037)
#define NUMBER_OP (0x030)
#define NUMBER_MAX (0x039)

// Calibrate Macros
#define LEFT_BASE (0x150)
#define RIGHT_BASE (0x150)
#define TOLERANCE (0x170)

// Motor Macros
#define MOTOR_ENABLE (1)
#define CIRCLE_LEFT (6)
#define CIRCLE_RIGHT (8)

// Circles Macros
#define C_ONE_SEC_COUNT          (1000)
#define C_TWO_SEC_COUNT          (2500)

// Figure 8 Macros
#define FIG8_STEP1 (23)
#define FIG8_STEP2 (15)
#define FIG8_STEP3 (15)
#define FIG8_STEP4 (19)
#define FIG8_STEP5 (15)
#define FIG8_STEP6 (10)

// Triangle Macros
#define TRI_STRGHT (23)
#define TRI_TURN1 (57)
#define TRI_TURN2 (44)
#define TRI_TURN3 (54)


// Global Variables
extern volatile unsigned char control_state[CNTL_STATE_INDEX];
extern volatile unsigned int Time_Sequence;
extern char led_smclk;
extern volatile char one_time;
extern char display_line_1[11];
extern char display_line_2[11];
extern char display_line_3[11];
extern char display_line_4[11];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char size_count;
extern char big;
// Switch
extern char switch_select;
// A0 Interrupt Handler
extern volatile unsigned int A0_time_count;
// ADC Interrupt Handler
extern volatile unsigned int ADC_Right_Detector;
extern volatile unsigned int ADC_Left_Detector;
extern volatile unsigned int ADC_Thumb;
extern volatile unsigned int ADC_Temp;
extern volatile unsigned int ADC_Bat;
extern volatile unsigned int ADC_Channel;
extern _Bool adc_RD_Enable;
extern _Bool adc_LD_Enable;
extern _Bool thumbEnable;
extern _Bool tempEnable;
extern _Bool batEnable;
// USCI Interrupt Handler
extern volatile unsigned int rxRead;
extern volatile unsigned int rxWrite;
extern volatile unsigned int txRead;
extern volatile unsigned int txWrite;
extern volatile char RX_Char[SMALL_RING_SIZE];
extern volatile char TX_Char[SMALL_RING_SIZE];
extern volatile _Bool transmitEnable;
extern volatile _Bool receiveEnable;
extern volatile _Bool baudToggle;

// Calibrate
extern unsigned int blackLineLeft;
extern unsigned int blackLineRight;

extern unsigned int tempCount;
extern unsigned int tempDisplay[SW_SEL_10];

#endif