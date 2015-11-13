//******************************************************************************
//
//  Description: This file contains the ADC detection routine module
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void P_Five_Drive(void){
//******************************************************************************
//
//  Description: This file contains the ADC detection routine module
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: 
//
// Passed:
//
// Local: reverseTime
//
// Return: VOID
//
//****************************************************************************** 
  
      // Initialize
      unsigned int reverseTime = INITIAL;
      unsigned int forwardTime = INITIAL;
    
      adc_RD_Enable = FALSE;
      adc_LD_Enable = FALSE; 
      thumbEnable = FALSE;
      tempEnable = FALSE;
      batEnable  = FALSE; 
      
	// Display GUI
      lcd_BIG_mid();
  
      display_1 = "----------";
      posL1 = LINE_POS_L0;
      display_2 = "FORWARD";
      posL2 = LINE_POS_L2;
      display_3 = "----------";
      posL3 = LINE_POS_L0;
      display_4 =  "";
      posL4 = LINE_POS_L0;
      
      Display_Process();
      
      int i= TEN_ITERATIONS;
      while(i) {
      ADC10_Process();
        i--;
      }
      
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
      
      // Forward  
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
      
  while(ALWAYS) {                            
      
       ADC10_Process(); ADC10_Process(); ADC10_Process(); ADC10_Process(); ADC10_Process();
      // Stop if blackline is detected
      if ((ADC_Left_Detector >= (blackLineLeft - TOLERANCE))
          && (ADC_Right_Detector >= (blackLineRight - TOLERANCE))) break;
    
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();

    }
  
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
  
     // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

      while(A0_time_count <= HALF_SEC_COUNT) {                            

       }
  
    // Reverse  
      display_2 =  "REVERSE";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
      
  while(ALWAYS) {                            
      
       ADC10_Process(); ADC10_Process(); ADC10_Process(); ADC10_Process(); ADC10_Process();
      reverseTime++;
      // Stop if blackline is detected
      if ((ADC_Left_Detector >= (blackLineLeft - TOLERANCE))
          && (ADC_Right_Detector >= (blackLineRight - TOLERANCE))
            && (A0_time_count >= ONE_SEC_COUNT)) break;
    
      Left_Reverse_On(MOTOR_ENABLE);
      Left_Reverse_Off();
      Right_Reverse_On(MOTOR_ENABLE);
      Right_Reverse_Off();

    }
  
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
  
     // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

      while(A0_time_count <= HALF_SEC_COUNT) {                            

       }
      reverseTime >>= TRUE;
      
      // Forward  
      display_2 =  "FORWARD";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(forwardTime <= reverseTime) {                            
      ADC10_Process();
      forwardTime++;
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
    }
    
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
  
     // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

      while(A0_time_count <= HALF_SEC_COUNT) {                            

       }
      
      // Clockwise  
      display_2 =  "CLOCKWISE";
      posL2 = LINE_POS_L1;
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(A0_time_count <= TWO_SEC_COUNT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Reverse_On(MOTOR_ENABLE);
      Right_Reverse_Off();

    }
    
     Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
  
     // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

      while(A0_time_count <= HALF_SEC_COUNT) {                            

       }
      
      // Counter-clockwise  
      display_1 =  "COUNTER";
      posL1 = LINE_POS_L2;
      display_2 =  "CLOCKWISE";
      posL2 = LINE_POS_L1;
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(A0_time_count <= THREE_HALF_SEC_COUNT) {                            
      
      Left_Reverse_On(MOTOR_ENABLE);
      Left_Reverse_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();

    }

      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
    
      // Pause
      display_1 =  "----------";
      posL1 = LINE_POS_L0;
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

  while(A0_time_count <= HALF_SEC_COUNT) {                            
     
    }
    
	// Finalize Function
      Time_Sequence = INITIAL;
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
      
      display_1 = "P. Five";
      posL1 = LINE_POS_L2;
      display_2 = "Complete!";
      posL2 = LINE_POS_L1;
      display_3 = "Push";
      posL3 = LINE_POS_L3;
      display_4 =  "Select";
      posL4 = LINE_POS_L2;

      lcd_4line();      
      Display_Process();
  
}