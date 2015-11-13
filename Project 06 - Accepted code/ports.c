//******************************************************************************
//
//  Description: This file contains the Ports Routine
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


// Call port initialization for ports 1, 2, 3, 4, and J
void Init_Ports(void){
  
//******************************************************************************
//
//  Description: Initializes Ports
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//    
// Globals:
// Passed: USE_R_FORWARD to clock_state in Init_Port3
// Local:
// Return: VOID
//******************************************************************************
  
  Init_Port1();
  Init_Port2();
  Init_Port3(USE_R_FORWARD);
  Init_Port4();
  Init_PortJ();
}

void Init_Port1(void) {
//******************************************************************************
//
//  Description: Initializes Port 1
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//    
  // Globals:
  // Passed:
  // Local:
  // Return: VOID
//******************************************************************************


  // Configure PORT 1
  // V_DETECT_R         (0x01)
  // V_DETECT_L         (0x02)
  // IR_LED             (0x04)
  // V_THUMB            (0x08)
  // SPI_CS_LCD         (0x10)
  // SAO_LCD            (0x20)
  // SPI_SIMO           (0x40)
  // SPI_SOMI           (0x80)
  
  // Set Port 1 Registers 
    
    P1SEL0 = CLEAR_REGISTER;
    P1SEL1 = CLEAR_REGISTER;
    P1DIR = CLEAR_REGISTER;
    
    // V_DETECT_R Initialization
    P1SEL0 |= V_DETECT_R;               // P1SEL0 ->    1
    P1SEL1 |= V_DETECT_R;               // P1SEL1 ->    1
    P1OUT &= ~V_DETECT_R;               // P1OUT ->     0
    P1DIR &= ~V_DETECT_R;               // P1DIR ->     0
    
    // V_DETECT_L Initialization
    P1SEL0 |= V_DETECT_L;               // P1SEL0 ->    1
    P1SEL1 |= V_DETECT_L;               // P1SEL1 ->    1
    P1OUT &= ~V_DETECT_L;               // P1OUT ->     0
    P1DIR &= ~V_DETECT_L;               // P1DIR ->     0
    
    // IR_LED Initialization
    P1SEL0 &= ~IR_LED;                  // P1SEL0 ->    0
    P1SEL1 &= ~IR_LED;                  // P1SEL1 ->    0
    P1OUT |= IR_LED;                    // P1OUT ->     1
    P1DIR |= IR_LED;                    // P1DIR ->     1
    
    // V_THUMB Initialization
    P1SEL0 |= V_THUMB;                  // P1SEL0 ->    1
    P1SEL1 |= V_THUMB;                  // P1SEL1 ->    1
    P1OUT &= ~V_THUMB;                  // P1OUT ->     0
    P1DIR &= ~V_THUMB;                  // P1DIR ->     0
    
    // SPI_CS_LCD Initialization
    P1SEL0 &= ~SPI_CS_LCD;              // P1SEL0 ->    0
    P1SEL1 &= ~SPI_CS_LCD;              // P1SEL1 ->    0
    P1OUT |= SPI_CS_LCD;                // P1OUT ->     1
    P1DIR |= SPI_CS_LCD;                // P1DIR ->     1
    
    P1SEL0 &= ~SA0_LCD;                 // P1SEL0 ->    0
    P1SEL1 &= ~SA0_LCD;                 // P1SEL1 ->    0
    P1OUT &=  ~SA0_LCD;                 // P1OUT ->     0
    P1DIR |= SA0_LCD;                   // P1DIR ->     1
    
    P1SEL0 &= ~SPI_SIMO;                // P1SEL0 ->    0
    P1SEL1 |= SPI_SIMO;                 // P1SEL1 ->    1
    P1OUT &= ~SPI_SIMO;                 // P1OUT ->     0
    P1DIR |= SPI_SIMO;                  // P1DIR ->     1
    
    P1SEL0 &= ~SPI_SOMI;                // P1SEL0 ->    0
    P1SEL1 |= SPI_SOMI;                 // P1SEL1 ->    1
    P1OUT &= ~SPI_SOMI;                 // P1OUT ->     0
    P1DIR &= ~SPI_SOMI;                 // P1DIR ->     0
    P1REN |= SPI_SOMI;                  // P1REN ->     1
  }

void Init_Port2(void) {
  //******************************************************************************
//
//  Description: Initializes Port 2
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//    
// Globals:
// Passed:
// Local:
// Return: VOID
//******************************************************************************
  
  // Configure PORT2
  // USB_TXD
  // USB_RXD
  // SPI_SCK
  // P2PIN3
  // P2PIN4
  // CPU_TXD
  // CPU_RXD
  // P2PIN7
  
  // Set Port 2 Registers 
    P2SEL0 = CLEAR_REGISTER;               
    P2SEL1 = CLEAR_REGISTER;
    P2OUT = CLEAR_REGISTER;
    P2DIR = CLEAR_REGISTER;
    
  // USB_TXD Initialization
  P2SEL0 &= ~USB_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= USB_TXD;                    // P2SEL1 ->    1
  P2OUT &= ~USB_TXD;                    // P2OUT ->     0
  P2DIR |= USB_TXD;                     // P2DIR ->     1
  
  // USB_RXD Initialization
  P2SEL0 &= ~USB_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= USB_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~USB_TXD;                    // P2OUT ->     0
  P2DIR  &= ~USB_RXD;                   // P2DIR ->     0
  
  // SPI_SCK Initialization
  P2SEL0 &= ~SPI_SCK;                   // P2SEL0 ->    0
  P2SEL1 |= SPI_SCK;                    // P2SEL1 ->    1
  P2OUT |= SPI_SCK;                     // P2OUT ->     1
  P2DIR |= SPI_SCK;                     // P2DIR ->     1
  
  // P2PIN3 Initialization
  P2SEL0 &= ~P2PIN3;                    // P2SEL0 ->    0
  P2SEL1 &= ~P2PIN3;                    // P2SEL1 ->    0
  P2OUT &= ~P2PIN3;                     // P2OUT ->     0
  P2DIR |= P2PIN3;                      // P2DIR ->     1
  P2REN &= ~P2PIN3;                     // P2REN ->     0
    
  // P2PIN4 Initialization
  P2SEL0 &= ~P2PIN4;                    // P2SEL0 ->    0
  P2SEL1 &= ~P2PIN4;                    // P2SEL1 ->    0
  P2OUT &= ~P2PIN4;                     // P2OUT ->     0
  P2DIR |= P2PIN4;                      // P2DIR ->     1
  P2REN &= ~P2PIN4;                     // P2REN ->     0
    
  // CPU_TXD Initialization
  P2SEL0 &= ~CPU_TXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_TXD;                    // P2SEL1 ->    1
  P2OUT &= ~CPU_TXD;                    // P2OUT ->     0
  P2DIR |= CPU_TXD;                     // P2DIR ->     1
  
  // CPU_RXD Initialization
  P2SEL0 &= ~CPU_RXD;                   // P2SEL0 ->    0
  P2SEL1 |= CPU_RXD;                    // P2SEL1 ->    1
  P2OUT &= ~CPU_RXD;                    // P2OUT ->     0
  P2DIR  &= ~CPU_RXD;                   // P2DIR ->     0
  
  // P2PIN7 Initialization
  P2SEL0 &= ~P2PIN7;                    // P2SEL0 ->    0
  P2SEL1 &= ~P2PIN7;                    // P2SEL1 ->    0
  P2OUT &= ~P2PIN7;                     // P2OUT ->     0
  P2DIR |= P2PIN7;                      // P2DIR ->     1
  P2REN &= ~P2PIN7;                     // P2REN ->     0
  
}

void Init_Port3(char clock_state) {
  
  //******************************************************************************
//
//  Description: Initializes Port 3
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//    
// Globals:
// Passed: clock_state
// Local:
// Return: VOID
//******************************************************************************

  
  // Configure PORT 3
  // X
  // Y
  // Z
  // LCD_BACKLITE
  // R_FORWARD
  // R_REVERSE
  // L_FORWARD
  // L_REVERSE
  
  // Set Port 3 Registers 
    P3SEL0 = CLEAR_REGISTER;               
    P3SEL1 = CLEAR_REGISTER;
    P3OUT = CLEAR_REGISTER;
    P3DIR = CLEAR_REGISTER;
    
  // P3X Initialization
  P3SEL0 &= ~P3X;                       // P3SEL0 ->    0
  P3SEL1 &= ~P3X;                       // P3SEL1 ->    0
  P3OUT &= ~P3X;                        // P3OUT ->     0
  P3DIR &= ~P3X;                        // P3DIR ->     0
  P3REN &= ~P3X;                        // P3REN ->     0
  
  // P3Y Initialization
  P3SEL0 &= ~P3Y;                       // P3SEL0 ->    0
  P3SEL1 &= ~P3Y;                       // P3SEL1 ->    0
  P3OUT &= ~P3Y;                        // P3OUT ->     0
  P3DIR &= ~P3Y;                        // P3DIR ->     0
  P3REN &= ~P3Y;                        // P3REN ->     0
  
  // Z Initialization
  P3SEL0 &= ~P3Z;                       // P3SEL0 ->    0
  P3SEL1 &= ~P3Z;                       // P3SEL1 ->    0
  P3OUT &= ~P3Z;                        // P3OUT ->     0
  P3DIR &= ~P3Z;                        // P3DIR ->     0
  P3REN &= ~P3Z;                        // P3REN ->     0
  
  // LCD_BACKLITE Initialization
  P3SEL0 &= ~LCD_BACKLITE;              // P3SEL0 ->    0
  P3SEL1 &= ~LCD_BACKLITE;              // P3SEL1 ->    0
  P3OUT |= LCD_BACKLITE;               // P3OUT ->     0
  P3DIR |= LCD_BACKLITE;                // P3DIR ->     1
  
  if (clock_state == USE_R_FORWARD) {
  // R_FORWARD
  P3SEL0 &= ~R_FORWARD;
  P3SEL1 &= ~R_FORWARD;
  P3OUT &= ~R_FORWARD;
  P3DIR |= R_FORWARD;
  }
  else {
  P3SEL0 |= SET_SMCLK;
  P3SEL1 |= SET_SMCLK;
  P3OUT |= SET_SMCLK;
  P3DIR |= SET_SMCLK;
  }
  // R_REVERSE
  P3SEL0 &= ~R_REVERSE;
  P3SEL1 &= ~R_REVERSE;
  P3OUT &= ~R_REVERSE;
  P3DIR |= R_REVERSE;
  
  // L_FORWARD
  P3SEL0 &= ~L_FORWARD;
  P3SEL1 &= ~L_FORWARD;
  P3OUT &= ~L_FORWARD;
  P3DIR |= L_FORWARD;
  
  // L_REVERSE
  P3SEL0 &= ~L_REVERSE;
  P3SEL1 &= ~L_REVERSE;
  P3OUT &= ~L_REVERSE;
  P3DIR |= L_REVERSE;
  
}

void Init_Port4(void) {
  
//******************************************************************************
//
//  Description: Initializes Port 4
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//    
  // Globals:
  // Passed:
  // Local:
  // Return: VOID
//******************************************************************************
  
  // Configure PORT 4
  // SW1                (0x01)
  // SW2                (0x02)
  
  // Set Port 4 Registers 
    P4SEL0 = CLEAR_REGISTER;
    P4SEL1 = CLEAR_REGISTER;
    P4OUT = CLEAR_REGISTER;
    P4DIR = CLEAR_REGISTER;

  // SW1 Initialization
  P4SEL0 &= ~SW1;               // SW1 set as I/O
  P4SEL1 &= ~SW1;               // SW1 set as I/O
  P4OUT |= SW1;                 // Configures SW1 for pullup resistor operation
  P4DIR &= ~SW1;                // Direction set as input
  P4REN |= SW1;                 // Enables Pull-up Resistor
  //P4IES |= SW1;               // SW1 Hi/Lo Edge Interrupt 
  
  // SW2 Initialization
  P4SEL0 &= ~SW2;               // SW2 set as I/O
  P4SEL1 &= ~SW2;               // SW2 set as I/O
  P4OUT |= SW2;                 // Configures SW1 for pullup resistor operation
  P4DIR &= ~SW2;                // Direction set as input
  P4REN |= SW2;                 // Enables Pull-up Resistor
  //P4IES |= SW2;               // SW2 Hi/Lo Edge Interrupt 
  
}

void Init_PortJ(void) {

//******************************************************************************
//
//  Description: Initializes Port J
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//    
  // Globals:
  // Passed:
  // Local:
  // Return: VOID
//******************************************************************************

  // Configure PORT J
  // IOT_FACTORY
  // IOT_WAKEUP
  // IOT_STA_MINIAP
  // RESET
  
  // Set Port J Registers 
  PJSEL0 = CLEAR_REGISTER;
  PJSEL1 = CLEAR_REGISTER;
  PJOUT = CLEAR_REGISTER;
  PJDIR = CLEAR_REGISTER;
    
  PJSEL0 &= ~IOT_FACTORY;
  PJSEL1 &= ~IOT_FACTORY;
  PJOUT &= ~IOT_FACTORY;
  PJDIR |= IOT_FACTORY;

  PJSEL0 &= ~IOT_WAKEUP;
  PJSEL1 &= ~IOT_WAKEUP;
  PJOUT &= ~IOT_WAKEUP;
  PJDIR |= IOT_WAKEUP;
  
  PJSEL0 &= ~IOT_STA_MINIAP;
  PJSEL1 &= ~IOT_STA_MINIAP;
  PJOUT &= ~IOT_STA_MINIAP;
  PJDIR |= IOT_STA_MINIAP;
  
  PJSEL0 &= ~RESET;
  PJSEL1 &= ~RESET;
  PJOUT |= RESET;
  PJDIR |= RESET;
  
  PJSEL0 |= XINR;
  PJSEL0 |= XOUTR;
  
}
