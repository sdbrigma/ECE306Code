//******************************************************************************
//
//  Description: This file is used to implement a circle shape during runtime
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

void Circle_Drive(void){
//******************************************************************************
//
//  Description: This file is used to implement a circle shape during runtime
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4, Time_Sequence,
//
//
// Passed: 
//
// Local:
//
// Return: VOID
//
//****************************************************************************** 
  
	// Display GUI
      display_1 = "A Circle";
      posL1 = LINE_POS_L1;
      display_2 = "Is Being";
      posL2 = LINE_POS_L1;
      display_3 = "Made!";
      posL3 = LINE_POS_L3;
      display_4 =  "Circle: 1";
      posL4 = LINE_POS_L0;
      Display_Process();
      
	// Initialize
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;

      
    // Forward  
      
  while(A0_time_count <= C_TWO_SEC_COUNT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(CIRCLE_LEFT);
      Right_Forward_Off();

    }
  
      // Pause
      display_4 =  "  WAIT...";
      Display_Process();
      Right_Forward_Off();
      Left_Forward_Off();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;
      
  while(A0_time_count <= C_ONE_SEC_COUNT) {                            
      
      Right_Forward_Off();
      Left_Forward_Off();
      Right_Reverse_Off();
      Left_Reverse_Off();
    }  
  

      // Circle 2  
      display_4 =  "Circle: 2";
      Display_Process();
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL;    
  
  while(A0_time_count <= C_TWO_SEC_COUNT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(CIRCLE_LEFT);
      Right_Forward_Off();

    }

  
	// Finalize Function
      Time_Sequence = INITIAL;
      A0_time_count = INITIAL; 
      Right_Forward_Off();
      Left_Forward_Off();
      
      display_1 = "Circle";
      posL1 = LINE_POS_L2;
      display_2 = "Complete!";
      posL2 = LINE_POS_L1;
      display_3 = "Push";
      posL3 = LINE_POS_L3;
      display_4 =  "Select";
      posL4 = LINE_POS_L2;
      Display_Process();
      
}