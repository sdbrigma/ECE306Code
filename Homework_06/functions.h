// Function prototypes main
void main(void);
void Init_Conditions(void);
void Switches_Process(void);
void Init_Timers(void);
void Init_LEDs(void);

// Function prototypes clocks
void Init_Clocks(void);
void five_msec_sleep(unsigned int fivemsec);
void Five_msec_Delay(unsigned int delay); // New delay function for HW6

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

// Interrupt for SW1 and SW2
__interrupt void switch_interrupt(void);


// Function prototypes ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_PortJ(void);

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
void motor_reverse(volatile unsigned int time);
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

