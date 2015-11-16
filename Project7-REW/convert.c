//***********************************************************************
//      Title: convert.c 
//      Description: This file handles type conversions 
//      Rachel Williams
//      November 2015
//      Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//***********************************************************************
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

//***********************************************************************
//      Function name: ADC_Convert 
//      Description: Converts 10-bit analog input to hex representation 
//      Global variables: enabled_LD, enabled_RD, temp_num, temp
//      Local variables: diff, temp
//      Return: NONE
//***********************************************************************
void ADC_Convert(void){
  int diff = ORIGINAL;
  int temp = ORIGINAL;   
  
  if(enabled_RD){
    temp_num = ADC_Right_Detector; // reading hexadecimal values fr: detector
    temp = ADC_Right_Detector;       
  }
  if(enabled_LD){
    temp_num = ADC_Left_Detector; // reading hexadecimal values fr: detector
    temp = ADC_Left_Detector;
  }
  if(enabled_thumb){
    temp_num =  ADC_Thumb;        // reading hexadecimal values fr: th. wheel
    temp = ADC_Thumb; 
  }
  
  // LSB bit of 10bit signal
  temp_num = temp_num & BIT_LSB; 
  if(temp_num <= NUM_MIN){
     temp_num += NUM_BASE; 
  }else {
     diff = temp_num-NUM_MIN;
     temp_num = ORIGINAL; 
     temp_num = LET_MIN + diff;
  }
  if(enabled_RD){
     display_1[POSIT_6]=temp_num;
  }
  if(enabled_LD){
     display_2[POSIT_6]=temp_num;
  }
  if(enabled_thumb){
     display_3[POSIT_6]=temp_num;
  }
      
  // Next bit of 10bit signal 
  temp_num = temp; 
  temp_num = temp_num & BIT_MID; 
  temp_num>>=POSIT_4; //right shifted to next bit 
  if(temp_num <= NUM_MIN){
     temp_num += NUM_BASE; 
  }else {
     diff = temp_num-NUM_MIN;
     temp_num = ORIGINAL; 
     temp_num = LET_MIN + diff; 
   }
   if(enabled_RD){
     display_1[POSIT_5]=temp_num;
   }
   if(enabled_LD){
     display_2[POSIT_5]=temp_num;
   }
  if(enabled_thumb){
    display_3[POSIT_5]=temp_num;
  }
      
   // MSB bit of 10bit signal 
   temp_num = temp; 
   temp_num = temp_num & BIT_MSB; 
   temp_num>>=POSIT_8; 
   if(temp_num <= NUM_MIN){
     temp_num += NUM_BASE;
   } else {
     diff = temp_num-NUM_MIN;
     temp_num = ORIGINAL; 
     temp_num = LET_MIN + diff; 
   }
   if(enabled_RD){
     display_1[POSIT_4]= temp_num;
   }
   if(enabled_LD){
     display_2[POSIT_4]=temp_num;
   }
   if(enabled_thumb){
    display_3[POSIT_4]=temp_num;
  }  
}

//***********************************************************************
//      Function name: Convert_H2I
//      Description: This file handles hex to int/int to hex conversion
//      Global variables: diff, enabled_TX 
//      Local variables: temp
//      Return: VOID
//***********************************************************************
void Convert_H2I(void){ 
  diff = ORIGINAL;
  
   // resetting after button press 
    if (!(P4IN & SW1)){
      UCA1TXBUF = TILDE;
      Five_Msec_Delay(POSIT_5);
      UCA1TXBUF = NUM_BASE;
      temp1 = UCA1RXBUF;
    } else{
      temp1 = UCA1RXBUF; 
    }
    
  // checks if tilde is sent: resets all  // sends tilde+number 
   if(temp1 == TILDE){
     display_1[POSIT_0] = NUM_BASE;
     display_1[POSIT_1] = NUM_BASE;
     display_1[POSIT_2] = NUM_BASE;
     display_1[POSIT_3] = NUM_BASE;
     display_1[POSIT_4] = NUM_BASE;
     display_1[POSIT_5] = NUM_BASE;
     display_1[POSIT_6] = NUM_BASE;
     display_1[POSIT_7] = NUM_BASE;
     display_1[POSIT_8] = NUM_BASE;
     display_1[POSIT_9] = NUM_BASE;
     Display_Process(); 
     Five_Msec_Delay(POSIT_5);
     temp1 = UCA1RXBUF; 
     
     if (temp1 == NUM_8) {
       diff++;
       temp1 = diff + NUM_BASE;
       UCA1TXBUF = temp1;
     }
     else {
       UCA1TXBUF = TILDE;
       Five_Msec_Delay(POSIT_5);
       UCA1TXBUF = temp1;
     }
     
     UCA1TXBUF = NUM_BASE;
     tens_num = NUM_BASE;
     hundreds_num = NUM_BASE; 
  }else if(temp1 > NUM_9){// if other characters are sent: ignored 
    temp1 = NUM_BASE;
    display_1[POSIT_0] = NUM_BASE;
    display_1[POSIT_1] = NUM_BASE;
    display_1[POSIT_2] = NUM_BASE;
    display_1[POSIT_3] = NUM_BASE;
    display_1[POSIT_4] = NUM_BASE;
    display_1[POSIT_5] = NUM_BASE;
    display_1[POSIT_6] = NUM_BASE;
    display_1[POSIT_7] = hundreds_num;
    display_1[POSIT_8] = tens_num;
    display_1[POSIT_9] = temp1;
    display_2 = "          ";
    display_3 = "          ";
    display_4 = "          ";
    Display_Process();  
    return; 
  } else{ // handling conversion
    // taking hex representation, subtracting 0x0030: now an integer 
    diff = temp1 - NUM_BASE; 

    if(!tens){
        tens = POSIT_1; 
        diff = ORIGINAL;
        tens_num = NUM_BASE; 
        hundreds_num = NUM_BASE;
    }
    // add 1 to integer  
    if(diff == POSIT_9){
      diff = ORIGINAL;
      tens_num++;
    }else if(tens_num == NUM_9){
      tens_num = NUM_BASE;
      hundreds = POSIT_1;
      diff = ORIGINAL;
      hundreds_num++;  
    }else{
      diff++; 
    }
   
    // taking int representation, adding 0x0030: now a hex value 
    temp1 = diff + NUM_BASE;
    
   // displaying digits      
    display_1[POSIT_0] = NUM_BASE;
    display_1[POSIT_1] = NUM_BASE;
    display_1[POSIT_2] = NUM_BASE;
    display_1[POSIT_3] = NUM_BASE;
    display_1[POSIT_4] = NUM_BASE;
    display_1[POSIT_5] = NUM_BASE;
    display_1[POSIT_6] = NUM_BASE;
    display_1[POSIT_7] = hundreds_num;
    display_1[POSIT_8] = tens_num;
    display_1[POSIT_9] = temp1;
    display_2 = "          ";
    display_3 = "          ";
    display_4 = "          ";
    Display_Process(); 
    
    // transmit/send the updated value 
    UCA1TXBUF = temp1; 
    
    // re-initialize to zero until next interrupt call 
    enabled_RX = POSIT_0; 
    hundreds = POSIT_0; 
    Five_Msec_Delay(POSIT_10);
  }
}