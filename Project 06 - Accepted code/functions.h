//******************************************************************************
//
//  Description: This file contains function prototypes
//
//
//  Christopher Woedy
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
void Init_LEDs(void);

// Function prototypes clocks
void Init_Clocks(void);
void five_msec_sleep(unsigned int fivemsec);
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
void Circle_Drive(void);
void Figure8_Drive(void);
void Triangle_Drive(void);
void P_Four_Drive(void);
void P_Five_Drive(void);
void Project_6(void);
void Homework_7(void);
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
void Detect(void);
void Calibrate(void);

// USCI
__interrupt void USC1_A1_ISR(void);
void Init_Serial_UCA1(_Bool lowBaud);
#endif