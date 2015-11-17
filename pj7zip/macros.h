//******************************************************************************
//
//  Description: This file contains the systems macros
//
//
//  Steffon Brigman
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

//// Timer Macros
#define TA0CCR0_INTERVAL (125)	        // Used to set the A0 timer to 1 msec

//// A0 Macros
#define FOUR_CYCLES (4)
#define FIVE_CYCLES (5)
#define TEN_ITERATIONS (10)
#define ONE_MSEC (1)
#define FIVE_MSEC (5)
#define WFIFTY_MSEC (49)
#define FIFTY_MSEC (50)
#define ONE_SEC_MULT (200)
#define TWO_SEC_MULT (400)
#define FIVE_SEC_MULT (1000)
#define SIX_SEC_MULT (1200)
#define HALF_SEC_COUNT (500)
#define ONE_SEC_COUNT (1000)
#define TWO_SEC_COUNT (2000)
#define THREE_HALF_SEC_COUNT (3500)
#define FOUR_SEC_COUNT (4000)
#define FIVE_SEC_COUNT (5000)
#define TEN_SEC_COUNT (10000)

//// Switch Macros
#define LIL_DELAY (25)
#define LIL_SW_DELAY (31)
#define BIGGER_DELAY (75)
#define BIG_DELAY (50)
#define TWO_CYCLES (2)

// Thumb Wheel Macros
#define ITEM_ONE (0)
#define ITEM_TWO (102)
#define ITEM_THREE (205)
#define ITEM_FOUR (307)
#define ITEM_FIVE (409)
#define ITEM_SIX (512)
#define ITEM_SEVEN (614)
#define ITEM_EIGHT (716)
#define ITEM_NINE (818)
#define ITEM_TEN (921)
#define ITEM_END (1023)

// Selection Macros
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
#define SW_SEL_14 (14)

// ADC Macros
#define Right_Detector (0)
#define Left_Detector (1)
#define Thumbwheel (2)
#define CHANNEL_A10 (3)
#define CHANNEL_A11 (4)

// USCI Macros
#define USCI_val8 (0x08)
#define SMALL_RING_SIZE (40)
#define BAUD_9600 (0x4911)
#define BAUD_115200 (0x5551)
#define BRW9600 (52)
#define BRW115200 (4)

// IOT Macros
#define TX_FINISH (0x0D)

// Array Macros
#define Pos0 (0)
#define Pos1 (1)
#define Pos2 (2)
#define Pos3 (3)
#define Pos4 (4)
#define Pos5 (5)
#define Pos6 (6)
#define Pos7 (7)
#define Pos8 (8)
#define Pos9 (9)
#define Pos10 (10)
#define Pos11 (11)
#define Pos12 (12)
#define Pos13 (13)
#define Pos14 (14)
#define Pos15 (15)
#define Pos16 (16)
#define Pos17 (17)
#define Pos18 (18)
#define Pos19 (19)
#define Pos20 (20)
#define Pos21 (21)
#define Pos22 (22)
#define Pos23 (23)
#define Pos24 (24)
#define Pos25 (25)
#define Pos26 (26)
#define Pos27 (27)
#define Pos28 (28)
#define Pos29 (29)
#define Pos30 (30)
#define Pos31 (31)
#define Pos32 (32)
#define Pos33 (33)
#define Pos34 (34)
#define Pos35 (35)
#define Pos36 (36)
#define Pos37 (37)
#define Pos38 (38)
#define Pos39 (39)

//// HEX Macros
#define FIRST_BYTE (0x00FF)
#define FIRST_NYBL (0x0F)
#define SECOND_NYBL (0xF0)
#define FIRST_NIBBLE (0x000F)
#define SECOND_NIBBLE (0x00F0)
#define THIRD_NIBBLE (0x0F00)
#define SHIFT_4 (4)
#define SHIFT_8 (8)
#define LETTER_START (0x00A)
#define LETTER_OP (0x037)
#define NUMBER_OP (0x030)
#define NUMBER_MAX (0x039)

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
extern volatile unsigned int IOTRead;
extern volatile char RX_Char[SMALL_RING_SIZE];
extern volatile char IOT_RX[SMALL_RING_SIZE];
extern volatile char test;
extern volatile _Bool receiveEnable;
extern volatile _Bool USB_Received;
extern volatile _Bool IOT_Received;
extern volatile _Bool baudToggle;
// Calibrate
extern unsigned int blackLineLeft;
extern unsigned int blackLineRight;
extern unsigned int tempCount;
extern unsigned int tempDisplay[SW_SEL_10];

#endif