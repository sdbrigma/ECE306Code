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
#define BIG_LETTERS             (5)
#define ZERO                    (0)
#define QUARTER_SECOND          (50)
#define HALF_SECOND             (100)
#define THIRD_SECOND            (150)
#define THOU_MS                 (200)
#define FULL_SECOND             (250)
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