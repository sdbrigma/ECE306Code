/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   October 2015
*        Description: This file contains code to read data from the thumb wheel.
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        File name: int_hex.c
*        Passed : No variables passed 
*        Locals: No locals variables
*        Returned: no values returned 
*        Globlas: Listed in the globals section
*******************************************************************************/

// Includes
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

char int_hex_conversion(char received_char){ // receiving characters are chars
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   November 2015
*        Description: This function converts integers into chars to display on LCD
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: int_hex_conversion
*        Passed : number
*        Locals: 
*        Returned: converted_char
*        Globlas: All listed in the globals section
*******************************************************************************/
    int converted_number = received_char - ADC_conv2;
    return converted_number;
}

char hex_int_conversion(int number){ // receiving characters are chars
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   November 2015
*        Description: This function converts integers into chars to display on LCD
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: int_hex_conversion
*        Passed : number
*        Locals: 
*        Returned: converted_char
*        Globlas: All listed in the globals section
*******************************************************************************/
    char converted_number = number;
    return converted_number;
}

void count(unsigned int counter){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   November 2015
*        Description: This function converts integers into chars to display on LCD
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Function name: int_hex_conversion
*        Passed : number
*        Locals: 
*        Returned: converted_char
*        Globlas: All listed in the globals section
*******************************************************************************/
  if(counter == 0x00FE){
    counter = ZERO;
  }
  else {counter++;}
  Five_msec_Delay(30);
  counter = counter - ADC_conv2;
  
  char nibble1 = (counter & NIBBLE1);
  unsigned int test1 = nibble1;
  
  char nibble2 = (counter & NIBBLE2);
  unsigned int test2 = nibble2;
  
  char nibble3 = (counter & NIBBLE3);
  unsigned int test3 = nibble3;
  
  if(test1 >= 10) {
    nibble1 = test1 - 10;
    if(test2 >= 10){
      nibble2 = test2 - 10;
      if(test3 >= 10) {nibble3 = test3 - 10;}
    }
  }
  
  if(test2 >= 10) {nibble2 = test2 - 10;}
  
  if(test3 >= 10) {nibble3 = test3 - 10;}
  
  nibble1 = nibble1 + ADC_conv2;
  
  nibble2 >>= 4;
  nibble2 = nibble2 + ADC_conv2;
  
  nibble3 >>= 4;
  nibble3 = nibble3 + ADC_conv2;
  
  
  display_1[line1] = nibble1;
  display_1[line2] = nibble2;
  display_1[line3] = nibble3;
  posL1 = ZERO;
  display_2 = "          ";
  posL2 = ZERO;
  display_3 = "          ";
  posL3 = ZERO;
  display_4 = "          ";
  posL4 = ZERO;
  Display_Process();
  UCA1TXBUF = counter + ADC_conv2;
}