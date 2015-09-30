/*******************************************************************************
*       Title: ports.c
*       Author: Steffon Brigman
*       Date:   September 2015
*       Description: Contains all ports configurations.
*       Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*******************************************************************************/

//------------------------------------------------------------------------------

// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
void Init_Ports(void){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Contains all ports configurations.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_Ports
*        Description: Initializes all ports. 
*        Passed : no variables passed 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  Init_Port1();
  Init_Port2();
  Init_Port3(USE_SMCLK);
  Init_Port4();
  Init_PortJ();
}
void Init_Port1(void){
  /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Contains all ports configurations.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_Port1 
*        Description: Initializes port 1
*        Passed : no variables passed 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
//------------------------------------------------------------------------------
//Configure Port 1
// V_DETECT_R (0x01) //
// V_DETECT_L (0x02) //
// IR_LED (0x04) //
// V_THUMB (0x08) //
// SPI_CS_LCD (0x10) // LCD Chip Select
// SA0_LCD (0x20) // LCD SA0 H/L Slave Address
// SIMO_B (0x40) // SPI mode - slave in/master out of USCI_B0
// SOMI_B (0x80) // SPI mode - slave out/master in of USCI_B0
//------------------------------------------------------------------------------
 P1SEL0 = CLEAR_REGISTER; // P1 set as I/0
 P1SEL1 = CLEAR_REGISTER; // P1 set as I/0
 P1DIR = CLEAR_REGISTER; // Set P1 direction to input
 
 P1SEL0 |= V_DETECT_R; // V_DETECT_R selected
 P1SEL1 |= V_DETECT_R; // V_DETECT_R selected
 P1OUT &= ~V_DETECT_R;
 P1SEL0 |= V_DETECT_L; // V_DETECT_L selected
 P1SEL1 |= V_DETECT_L; // V_DETECT_L selected
 P1OUT &= ~V_DETECT_L;
 
 P1SEL0 &= ~IR_LED; // IR_LED GPI/O selected
 P1SEL1 &= ~IR_LED; // IR_LED GPI/O selected
 P1OUT |= IR_LED; // P1 IR_LED Port Pin set low
 P1DIR |= IR_LED; // Set P1 IR_LED direction to output
 
 P1SEL0 |= V_THUMB; // V_THUMB selected
 P1SEL1 |= V_THUMB; // V_THUMB selected
 P1OUT &= ~V_THUMB;
 
 P1SEL0 &= ~SPI_CS_LCD; // SPI_CS_LCD GPI/O selected
 P1SEL1 &= ~SPI_CS_LCD; // SPI_CS_LCD GPI/O selected
 P1OUT |= SPI_CS_LCD; // P1 SPI_CS_LCD Port Pin set high
 P1DIR |= SPI_CS_LCD; // Set SPI_CS_LCD output direction
 
 P1SEL0 &= ~RS_LCD; // SA0_LCD GPI/O selected
 P1SEL1 &= ~RS_LCD; // SA0_LCD GPI/O selected
 P1OUT &= ~RS_LCD; // P1 SA0_LCD Port Pin set low
 P1DIR |= RS_LCD; // Set SA0_LCD output direction
 
 P1SEL0 &= ~SPI_SIMO; // SIMO_B selected
 P1SEL1 |= SPI_SIMO; // SIMO_B selected
 P1OUT &= ~SPI_SIMO;
 P1DIR |= SPI_SIMO; // SIMO_B set to Output
 P1SEL0 &= ~SPI_SOMI; // SOMI_B is used on the LCD
 P1SEL1 |= SPI_SOMI; // SOMI_B is used on the LCD
 P1OUT &= ~SPI_SOMI;
 P1DIR &= ~SPI_SOMI; // SOMI_B set to Input
 P1REN |= SPI_SOMI; // Enable pullup resistor
}

void Init_Port2(void){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Contains all ports configurations.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_Port2 
*        Description: Initializes port 2
*        Passed : no variables passed 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
  //------------------------------------------------------------------------------
//Configure Port 2
// USB_TXD (0x01) //
// USB_RXD (0x02) //
// SPI_SCK (0x04) //
// UNKN_2P3 (0x08) //
// UNKN_2P4 (0x10)
// CPU_TXD (0x20)
// CPU_RXD (0x40)
// UN5N_2P4 (0x80)
//------------------------------------------------------------------------------
 P2SEL0 = CLEAR_REGISTER; // P2 set as I/0
 P2SEL1 = CLEAR_REGISTER; // P2 set as I/0
 P2DIR = CLEAR_REGISTER; // Set P2 direction to input
 P2OUT = CLEAR_REGISTER;
 
 P2SEL1 |= USB_TXD;
 P2SEL0 &= ~USB_TXD;
 P2SEL1 |= USB_RXD;
 P2SEL0 &= ~USB_RXD;
 P2SEL0 &= ~UNK_2P3; // SW1 set as I/0
 P2SEL1 &= ~UNK_2P3; // SW1 set as I/0
 P2SEL1 |= SPI_SCK;
 P2SEL0 &= ~SPI_SCK;
 P2OUT |= SPI_SCK;
 P2DIR |= SPI_SCK;
 P2OUT |= UNK_2P3; // Configure pullup resistor
 P2DIR &= ~UNK_2P3; // Direction = input
 P2REN &= ~UNK_2P3; // Enable pullup resistor
 P2IES &= ~UNK_2P3; // SW1 Hi/Lo edge interrupt
 P2SEL0 &= ~UNK_2P4; // SW1 set as I/0
 P2SEL1 &= ~UNK_2P4; // SW1 set as I/0
 P2OUT |= UNK_2P4; // Configure pullup resistor
 P2DIR &= ~UNK_2P4; // Direction = input
 P2REN &= ~UNK_2P4; // Enable pullup resistor
 P2IES &= ~UNK_2P4; // SW1 Hi/Lo edge interrupt
 P2SEL1 |= CPU_TXD;
 P2SEL0 &= ~CPU_TXD;
 P2SEL1 |= CPU_RXD;
 P2SEL0 &= ~CPU_RXD;
 
 P2SEL0 &= ~UNK_2P7; // SW1 set as I/0
 P2SEL1 &= ~UNK_2P7; // SW1 set as I/0
 P2OUT |= UNK_2P7; // Configure pullup resistor
 P2DIR &= ~UNK_2P7; // Direction = input
 P2REN &= ~UNK_2P7; // Enable pullup resistor
 P2IES &= ~UNK_2P7; // SW1 Hi/Lo edge interrupt
}

void Init_Port3(char pin){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Contains all ports configurations.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_Port3 
*        Description: Initializes port 3
*        Passed : pin 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
/*------------------------------------------------------------------------------
  Configure Port 3
  X               (0x01)
  Y               (0x02) 
  Z1               (0x04)
 LCD_BACKLITE    (0x08) 
 R_FORWARD       (0x10) 
 R_REVERSE       (0x20) 
 L_FORWARD       (0x40) 
 L_REVERSE       (0x80)
 ------------------------------------------------------------------------------
 */
  
  P3SEL0 = CLEAR_REGISTER; // P4 set as I/0
  P3SEL1 = CLEAR_REGISTER; // P4 set as I/0
  P3DIR = CLEAR_REGISTER; // Set P4 direction to input
  P3OUT = CLEAR_REGISTER;
  
  P3SEL1 &= ~X; // Set  to GPIO output for P3.0
  P3SEL0 &= ~X;
  P3DIR &= ~X; 
  P3REN &= ~X; // Enable pullup resistor
  P3SEL1 &= ~Y; // Set  to GPIO output for P3.1
  P3SEL0 &= ~Y;
  P3DIR &= ~Y; 
  P3REN &= ~Y; // Enable pullup resistor
  P3SEL1 &= ~Z1; // Set  to GPIO output for P3.2
  P3SEL0 &= ~Z1;
  P3DIR &= ~Z1; 
  P3REN &= ~Z1; // Enable pullup resistor
  
  P3SEL1 &= ~LCD_BACKLITE; // Set LCD_BACKLITE to GPIO output for P3.3
  P3SEL0 &= ~LCD_BACKLITE;
  P3OUT |= LCD_BACKLITE;
  P3DIR |= LCD_BACKLITE;
  if(pin == USE_R_FORWARD){
    P3SEL1 &= ~R_FORWARD; // Set R_FORWARD to GPIO output for P3.4
    P3SEL0 &= ~R_FORWARD;
    P3OUT &= ~R_FORWARD;
    P3DIR |= R_FORWARD;
}
else{
    P3SEL1 |= R_FORWARD; // Set USE_SMCLK to GPIO output for P3.4
    P3SEL0 |= R_FORWARD;
    P3OUT |= R_FORWARD;
    P3DIR |= R_FORWARD; 
}
  P3SEL1 &= ~LED6; // Set R_REVERSE to GPIO output for P3.5
  P3SEL0 &= ~LED6;
  P3OUT &= ~LED6;
  P3DIR |= LED6;
  P3SEL1 &= ~L_FORWARD; // Set L_FORWARD to GPIO output for P3.6
  P3SEL0 &= ~L_FORWARD;
  P3OUT &= ~L_FORWARD; 
  P3DIR |= L_FORWARD;
  P3SEL1 &= ~LED8; // Set L_REVERSE to GPIO output for P3.7
  P3SEL0 &= ~LED8;
  P3OUT &= ~LED8;
  P3DIR |= LED8;
}

void Init_Port4(void){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Contains all ports configurations.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_Port4 
*        Description: Initializes port 4
*        Passed : no variables passed 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
//------------------------------------------------------------------------------
// Configure PORT 4
// Port 4 has only two pins
// Port 4 Pins
// SW1 (0x01) // Switch 1
// SW2 (0x02) // Switch 2
//------------------------------------------------------------------------------
 P4SEL0 = CLEAR_REGISTER; // P4 set as I/0
 P4SEL1 = CLEAR_REGISTER; // P4 set as I/0
 P4DIR = CLEAR_REGISTER; // Set P4 direction to input
 P4OUT = CLEAR_REGISTER;
// SW1
 P4SEL0 &= ~SW1; // SW1 set as I/0
 P4SEL1 &= ~SW1; // SW1 set as I/0
 P4OUT |= SW1; // Configure pullup resistor
 P4DIR &= ~SW1; // Direction = input
 P4REN |= SW1; // Enable pullup resistor
 //P4IES |= SW1; // SW1 Hi/Lo edge interrupt
// SW2
 P4SEL0 &= ~SW2; // SW2 set as I/0
 P4SEL1 &= ~SW2; // SW2 set as I/0
 P4OUT |= SW2; // Configure pullup resistor
 P4DIR &= ~SW2; // Direction = input
 P4REN |= SW2; // Enable pullup resistor
 //P4IES |= SW2; // SW2 Hi/Lo edge interrupt
//------------------------------------------------------------------------------
}

void Init_PortJ(void){
    /*******************************************************************************
*        Author: Steffon Brigman
*        Date:   September 2015
*        Description: Contains all ports configurations.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: Init_PortJ 
*        Description: Initializes port J
*        Passed : no variables passed 
*        Locals: no variables declared 
*        Returned: no values returned 
*        Globlas: no values defined
*******************************************************************************/
//------------------------------------------------------------------------------
// Configure Port J
// Port J Pins
// LED1 (0x01) // LED 5
// LED2 (0x02) // LED 6
// LED3 (0x04) // LED 7
// LED4 (0x08) // LED 8
// XINR (0x10) // XINR
// XOUTR (0x20) // XOUTR
//------------------------------------------------------------------------------
 PJSEL0 = CLEAR_REGISTER; // PJ set as I/0
 PJSEL1 = CLEAR_REGISTER; // PJ set as I/0
 PJDIR = CLEAR_REGISTER; // Set PJ direction to output
 PJOUT = CLEAR_REGISTER;
 PJSEL0 &= ~LED1;
PJSEL1 &= ~LED1;
PJOUT &= ~LED1;
 PJDIR |= LED1; // Set PJ Pin 1 direction to output
 PJSEL0 &= ~LED2;
 PJSEL1 &= ~LED2;
 PJOUT &= ~LED2;
PJDIR |= LED2; // Set PJ Pin 2 direction to output
 PJSEL0 &= ~LED3;
 PJSEL1 &= ~LED3;
 PJOUT &= ~LED3;
PJDIR |= LED3; // Set PJ Pin 3 direction to output
 PJSEL0 &= ~RESET;
 PJSEL1 &= ~RESET;
  PJOUT &= ~RESET;
  PJDIR |= RESET; // Set PJ Pin 4 direction to input

// XT1 Setup
 PJSEL0 |= XINR;
 PJSEL0 |= XOUTR;
//------------------------------------------------------------------------------
}