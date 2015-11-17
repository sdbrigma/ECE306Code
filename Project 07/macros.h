//******************************************************************************
//
//  Description: This file contains all macros used within this workspace.
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

//------------------------------------------------------------------------------
#define ALWAYS                  (1)
#define ONE                     (1)
#define DISPLAY_LENGTH          (11)
#define LCD                     (300)
#define BIG_LETTERS             (5)
#define ZERO                    (0)
#define QUARTER_SECOND          (50)
#define HALF_SECOND             (100)
#define THIRD_SECOND            (150)
#define THOU_MS                 (200)
#define FULL_SECOND             (250)
#define STRAIGHT_TEST           (750) // 3 SECONDS
#define CLEAR_REGISTER          (0x0000)
#define CNTL_STATE_INDEX        (3) // Control States
#define LED1                 (0x01) // LED 1
#define LED2                 (0x02) // LED 2
#define LED3                 (0x04) // LED 3
#define LED5                 (0x10) // LED 5
#define LED6                 (0x20) // LED 6
#define LED7                 (0x40) // LED 7
#define LED8                 (0x80) // LED 8
#define BLINK_LED            (0x01) // Allow LED to Blink
#define SW1                  (0x01) // Switch 1
#define SW2                  (0x02) // Switch 2

// LCD
#define LCD_LINE_1           (0x80) // Position Cursor at Character 01 of Line 1
#define LCD_LINE_2           (0xC0) // Position Cursor at Character 01 of Line 2
#define LCD_HOME_L1	          0x80
#define LCD_HOME_L2         	0xA0
#define LCD_HOME_L3         	0xC0
#define LCD_HOME_L4         	0xE0

#define GPS_ONOFF            (0x08) //
#define USE_LED5             (0x40)  //
#define USE_SMCLK            (0x00)  //
#define USE_NFETS            (0xA0)  //
#define CLEAR_DISPLAY        (0x01)

#define CSLOCK               (0x01) // Any incorrect password locks registers

// Set LCD Line Positions
// Switch 1
#define SW1_posL1   (3) 
#define SW1_posL2   (1)
#define SW1_posL3   (2)
#define SW1_posL4   (1)

// Switch 2
#define SW2_posL1   (1) 
#define SW2_posL2   (2)
#define SW2_posL3   (3)
#define SW2_posL4   (1)

// Display Modes
#define ORIGINAL             (0x00) //

#define FLLN_BITS          (0x03ffu)
#define FLLN_255           (0x00ffu)

// Port J Pins
#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR

// Port 1 Macros
#define V_DETECT_R      (0x01) // P1.0
#define V_DETECT_L      (0x02) // P1.1
#define IR_LED          (0x04) // P1.2
#define V_THUMB         (0x08) // P1.3
#define SPI_CS_LCD      (0x10) // P1.4
#define RS_LCD          (0x20) // P1.5
#define SPI_SIMO        (0x40) // P1.6
#define SPI_SOMI        (0x80) // P1.7

// Port 2 Macros
#define USB_TXD      (0x01) // P2.0
#define USB_RXD      (0x02) // P2.1
#define SPI_SCK      (0x04) // P2.2
#define UNK_2P3      (0x08) // P2.3
#define UNK_2P4      (0x10) // P2.4
#define CPU_TXD      (0x20) // P2.5
#define CPU_RXD      (0x40) // P2.6
#define UNK_2P7      (0x80) // P2.7

// Port 3 Macros
#define X               (0x01) // P3.0
#define Y               (0x02) // P3.1
#define Z1               (0x04) // P3.2
#define LCD_BACKLITE    (0x08) // P3.3
#define R_FORWARD       (0x10) // P3.4
#define R_REVERSE       (0x20) // P3.5
#define L_FORWARD       (0x40) // P3.6
#define L_REVERSE       (0x80) // P3.7

// Port 4 Macros
#define SW1     (0x01) // P4.0
#define SW2     (0x02) // P4.1

// Port J Macros
#define IOT_FACTORY     (0x01) // PJ.0
#define IOT_WAKEUP      (0x02) // PJ.1
#define IOT_STA_MINIAP  (0x04) // PJ.2
#define RESET           (0x08) // PJ.3

//  Straight Function for Motors
#define STRAIGHT_I      (20) // Codes takes about 1 second per 20 loops
#define STRAIGHT_SYNC   (1)  // number used in delays
#define CIRCLE            (30) // number of iterations needed to complete 1 circle
#define SHAPE_DELAY      (2) // make shapes twice
#define CIRCLE_STRAIGHT  (2) // time to run motors straight in circle fucntion
#define CIRCLE_1         (13) // time needed to run left motor for circle function
#define CIRCLE_2         (13) // time needed to run right motor for circle function
#define CIRCLE_CORRECTION (5) // time to run right between shape delay
#define FIGURE_1         (22) // Iterations needed for left motor to do half of figure 8
#define FIGURE_2         (18) // Iterations needed for right motor to do half of figure 8
#define TRI_COUNT        (3) // iterations needed to make triangle
#define TRI_DELAY        (5) // Delay b/w making angle and line in triangle function
#define TRI_STRAIGHT     (35) // Time needed to make leg of triangle
#define TRI_ANGLE        (90) // Time needed for left motor to make angle of triangle

// For Timers
#define TA0CCR0_INTERVAL (10000) // 8,000,000 / 8 / 2 / 10000 = 200Hz => 5msec 

// Macros for interrupts
#define FIVE_SECONDS     (251) // Number of iterations in the interrupt before clearing ISR_COUNT
#define TWO_s            (200) // Number of incrememnts in ISR_COUNT to equal two seconds
#define PAUSE    (50) // Iterations needed to pause for 1/2 seconds in dance.c
#define STRAIGHT_TIME           (50) 
#define REVERSE_TIME            (100)
#define Second_1 (100)

// ADC Maros
#define Right_Detector          (0)
#define Left_Detector           (1)
#define Thumbwheel              (2)
#define CHANNEL_A10             (3)
#define CHANNEL_A11             (4)
#define BEGINNING (0)
#define SMALL_RING_SIZE (16)
#define white                   (0x064) //This is a high side value low side is 0x034
#define black                   (0x250) // Lowest value that counts as black
#define NIBBLE1                 (0x000F)
#define NIBBLE2                 (0x00F0)
#define NIBBLE3                 (0x0F00)
#define ADC_RESOLUTION          (1024)
#define QUARTER_WAIT            (25)
#define time_correction         (756)
#define clock_wise_time         (225)
#define calibrate               (100)
#define avg                     (2)
#define shift1                  (4)
#define shift2                  (8)
#define HEX_A                   (0x0009)
#define ADC_conv1               (0x0037)
#define ADC_conv2               (0x0030)
#define line1                   (6)
#define line2                   (5)
#define line3                   (4)

// Macros used to set baude rates
#define BAUD_9600 (52) // set UCAxBRW equal to this
#define MOD_CTRL1 (0x4911) // set UCAxMCTLW equal to this

// For baude rate 115200
#define BAUD_115200 (4)
#define MOD_CTRL2 (0x5551)

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

#define RING_8 (10) // ring of size 8
#define transmit_delay (75)
#define RECEIVE (2)
#define TRANSMIT (4)
#define UART_MAX (0x08)
#define IOT_RING_SIZE (40)

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

#define MENU10 (1023)
#define MENU1 (102)
#define MENU2 (205)
#define MENU3 (307)
#define MENU4 (409)
#define MENU5 (512)
#define MENU6 (614)
#define MENU7 (716)
#define MENU8 (818)
#define MENU9 (921)

// shift bits
#define SHIFT1 (1)
#define SHIFT2 (2)
#define SHIFT3 (3)
#define SHIFT4 (4)
#define SHIFT5 (5)
#define SHIFT6 (6)
#define SHIFT7 (7)
#define SHIFT8 (8)
#define SHIFT9 (9)

// IOT Commands
#define END_COMMAND (0x0D)
#define switch_delay (45)

extern volatile unsigned int Time_Sequence;
extern int ISR_COUNT;
extern int UPDATE_LCD;
extern unsigned int ADC_Thumb;
extern unsigned int ADC_Right_Detector;
extern unsigned int ADC_Left_Detector;
extern unsigned int ADC_Temp;
extern unsigned int ADC_Bat;
extern unsigned int tracking_value_high;
extern unsigned int tracking_value_low;
extern unsigned int tracking_value;
extern unsigned int ambience;
extern volatile char CPU_Char_Rx[40];
extern volatile char CPU_Char_Tx[40];
extern unsigned int cpu_rx_ring_wr;
extern unsigned int cpu_rx_ring_rd;
extern unsigned int cpu_tx_ring_wr;
extern unsigned int cpu_tx_ring_rd;
extern volatile char USB_Char_Rx[IOT_RING_SIZE];
extern volatile char USB_Char_Tx[IOT_RING_SIZE];
extern unsigned int usb_rx_ring_wr;
extern unsigned int usb_rx_ring_rd;
extern unsigned int usb_tx_ring_wr;
extern unsigned int usb_tx_ring_rd;
extern int ADC_Channel;
extern char display_line_1[DISPLAY_LENGTH];
extern char display_line_2[DISPLAY_LENGTH];
extern char display_line_3[DISPLAY_LENGTH];
extern char display_line_4[DISPLAY_LENGTH];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char big;
extern char posL3;
extern unsigned int color;
extern char posL4;
extern unsigned int inc;