// Function prototypes main
void main(void);
void Init_Conditions(void);
void Switches_Process(void);
void Init_Timers(void);
void Init_LEDs(void);

// Function prototypes clocks
void Init_Clocks(void);
void five_msec_sleep(unsigned int fivemsec);

// Function prototypes systems
void enable_interrupts(void);

// Function prototypes
__interrupt void Timer2_B0_ISR(void);
 __interrupt void TIMER2_B1_ISR(void);
void Init_Timer_B2(void);
void measure_delay(void);
void usleep10(unsigned int usec);

// Timers for Project 4
void Init_Timer_A0(void);
__interrupt void Timer2_A0_ISR(void);
void Five_msec_Delay(unsigned int delay);

// Functions for HW8
void Init_Serial_UCA1(void);
__interrupt void USCI_A1_ISR(void);

void setLCD(const char display1[], int pos1, const char display2[], int pos2, 
            const char display3[], int pos3, const char display4[], int pos4);
void clearLCD(void);
void displayLine1(const char display1[], int pos1);
void displayLine2(const char display2[], int pos2);
void displayLine3(const char display3[], int pos3);
void displayLine4(const char display4[], int pos4);

// Function prototypes ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_PortJ(void);

// ADC10_B Setup
void Init_ADC(void);
void ADC_read(int detect_mode);
void ADC_Process(void);

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

// Motors
void Init_Motors(void);
void motor_straight(void);
void motor_reverse(unsigned int time);
void circle(void);
void triangle(void);
void figure_eight(void);
void left_off(void);
void right_off(void);
void l_reverse_off(void);
void r_reverse_off(void);
void right_on(void);
void left_on(void);
void r_reverse_on(void);
void l_reverse_on(void);
void twerk(void);

// Project 5 funciton
void line_dance(void);
void calibrate_detector(void);
void emitter_on(void);
void emitter_off(void);

// Homework 9 functions
void getResistorMenu(unsigned int adc_value);
void getShapesMenu(unsigned int adc_value);
void getSongMenu(unsigned int adc_value);
