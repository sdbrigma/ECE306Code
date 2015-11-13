//******************************************************************************
//
//  Description: This file is used to implement the test code for project 4
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

void P_Four_Drive(void){
//******************************************************************************
//
//  Description: This file is used to implement the test code for project 4
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: display_1, display_2, display_3, display_4, posL1, posL2, posL3, 
// posL4, Time_Sequence, A0_time_count
//
// Passed: 
//
// Local: i
//
// Return: VOID
//
//****************************************************************************** 
  
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
      
      // Initialize
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
      
      // Forward  
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
      
  while(A0_time_count <= ONE_SEC_COUNT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();

    }
  
      // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

  while(A0_time_count <= HALF_SEC_COUNT) {                            
      
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
    }
  
  // Reverse  
      display_2 =  "REVERSE";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
      
  while(A0_time_count <= TWO_SEC_COUNT) {                            
      
      Left_Reverse_On(MOTOR_ENABLE);
      Left_Reverse_Off();
      Right_Reverse_On(MOTOR_ENABLE);
      Right_Reverse_Off();

    }
  
      // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(A0_time_count <= HALF_SEC_COUNT) {                            
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
      Time_Sequence = INITIAL;
    }

    // Forward  
      display_2 =  "FORWARD";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(A0_time_count <= ONE_SEC_COUNT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();

    }

      // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

  while(A0_time_count <= HALF_SEC_COUNT) {                            
      
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
    }

      // Clockwise  
      display_2 =  "CLOCKWISE";
      posL2 = LINE_POS_L1;
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(A0_time_count <= ONE_SEC_COUNT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Reverse_On(MOTOR_ENABLE);
      Right_Reverse_Off();

    }

      // Pause
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

  while(A0_time_count <= HALF_SEC_COUNT) {                            
      
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
    }
  
  
      // Counter-clockwise  
      display_1 =  "COUNTER";
      posL1 = LINE_POS_L2;
      display_2 =  "CLOCKWISE";
      posL2 = LINE_POS_L1;
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
  
    while(A0_time_count <= ONE_SEC_COUNT) {                            
      
      Left_Reverse_On(MOTOR_ENABLE);
      Left_Reverse_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();

    }

      // Pause
      display_1 =  "----------";
      posL1 = LINE_POS_L0;
      display_2 =  "WAIT...";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

  while(A0_time_count <= HALF_SEC_COUNT) {                            
      
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
    }
    
	// Finalize Function
      Time_Sequence = INITIAL;
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
      
      display_1 = "P. Four";
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