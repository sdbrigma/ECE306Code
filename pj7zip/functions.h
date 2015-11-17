//******************************************************************************
//
//  Description: This file contains function prototypes
//
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

// Preprocessing logic statements to avoid reinitialization
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function prototypes main
void main(void);
void Init_Conditions(void);
void Switches_Process(void);
void Init_Timers(void);

// Function prototypes clocks
void Init_Clocks(void);
void One_msec_Delay();
void Five_msec_Delay(unsigned int delay_multiplyer);

// Function prototypes systems
void enable_interrupts(void);

// Timer prototypes
__interrupt void TIMER0_A0_ISR(void);
void Init_Timer_A0(void);
__interrupt void Timer2_B0_ISR(void);
 __interrupt void TIMER2_B1_ISR(void);
void Init_Timer_B2(void);
void measure_delay(void);
void usleep10(unsigned int usec);

// IOT prototypes
void NCSU_Config(void);
void Command_IOT(void);
void IOT_driveForward(unsigned int leftDrive, unsigned int rightDrive, unsigned int runTime);
void IOT_driveReverse(unsigned int leftDrive, unsigned int rightDrive, unsigned int runTime);
void IOT_Clockwise(unsigned int runTime);
void IOT_Counterclockwise(unsigned int runTime);
void SSID(void);
void HOST(void);
void NPM(void);
void NET_MODE(void);
void FLASH(void);
void PING(void);
void ROAM(void);

// Function prototypes ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(char clock_state);
void Init_Port4(void);
void Init_PortJ(void);

// Function prototypes motors
void Left_Forward_Off(void);
void Left_Forward_On(int runLeft);
void Right_Forward_Off(void);
void Right_Forward_On(int runRight);
void Left_Reverse_Off(void);
void Left_Reverse_On(int runLeft);
void Right_Reverse_Off(void);
void Right_Reverse_On(int runRight);

// Function prototypes drives
unsigned int intToHex (unsigned int intTemp);
void hexToInt (unsigned int hexTemp);

// LCD
void Init_LCD(void);
void WriteIns(char instruction);
void WriteData(char data);
void ClrDisplay(void);
void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);
void Display_Process(void);

// Display Functions
void Display_Config(void);
void Display_IOTCMD(void);
void Display_Backdoor(void);
void Display_Detect(void);
void Display_Calibrate(void);
void Display_Format(void);
void Display_Buffer(void);

// SPI
void Init_SPI_B0(void);
void SPI_B0_write(char byte);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);

// ADC
void Init_ADC(void);
__interrupt void ADC10_ISR(void);
void ADC10_Process(void);
void Display_ADC(void);
void Display_Thumb (void);
void Detect(void);
void Calibrate(void);

// USCI
__interrupt void USC1_A0_ISR(void);
__interrupt void USC1_A1_ISR(void);
void Init_Serial_UCA0(_Bool lowBaud);
void Init_Serial_UCA1(_Bool lowBaud);

#endif