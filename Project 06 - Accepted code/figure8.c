//******************************************************************************
//
//  Description: This file is used to implement a figure 8 shape during runtime
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

void Figure8_Drive(void){
//******************************************************************************
//
//  Description: This file is used to implement a figure 8 shape during runtime
//
//
//  Christopher Woedy
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: display_1, display_2, display_3, display_4, LCD_HOME_L1, LCD_HOME_L2,
// LCD_HOME_L3, LCD_HOME_L4, posL1, posL2, posL3, posL4, Time_Sequence,
// circle_timer,
//
// Passed: 
//
// Local: i
//
// Return: VOID
//
//****************************************************************************** 
	
	// Display UI
      display_1 = "A Fig. 8";
      posL1 = LINE_POS_L1;
      display_2 = "Is Being";
      posL2 = LINE_POS_L1;
      display_3 = "Made!";
      posL3 = LINE_POS_L3;
      display_4 =  "Fig 8.: 1";
      posL4 = LINE_POS_L0;
      
	// Initialize
      Time_Sequence = INITIAL;
      Left_Forward_Off();
      Right_Forward_Off();
      int i = INITIAL;
      Display_Process();

// First Figure 8
 while(i < FIG8_STEP1) {                            
      
      Left_Forward_On(CIRCLE_LEFT);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

 i = INITIAL;
      
  while(i < FIG8_STEP2) {                            
      
      Right_Forward_On(CIRCLE_RIGHT);
      Right_Forward_Off();
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      i++;
      
    }
  
  i = INITIAL;

  while(i < FIG8_STEP3) {                            
      
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      i++;
      
    }
  
  i = INITIAL;
  
	// Pause
      display_4 =  "  WAIT...";
      Display_Process();
      Left_Forward_Off();
      Right_Forward_Off();
      Five_msec_Delay(BIG_DELAY);
      Time_Sequence = INITIAL;
      display_4 =  "Fig 8.: 2";
      Display_Process();

	  
	// Second Figure 8
 while(i < FIG8_STEP4) {                            
      
      Left_Forward_On(CIRCLE_LEFT);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

 i = INITIAL;
      
  while(i < FIG8_STEP5) {                            
      
      Right_Forward_On(CIRCLE_RIGHT);
      Right_Forward_Off();
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      i++;
      
    }

  i = INITIAL;

  while(i < FIG8_STEP6) {                            
      
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      i++;
      
    }
  
  i = INITIAL;
  
	// Finalize function
      Right_Forward_Off();
      Left_Forward_Off();
      Time_Sequence = INITIAL;
      
      display_1 = "Fig. 8";
      posL1 = LINE_POS_L2;
      display_2 = "Complete!";
      posL2 = LINE_POS_L1;
      display_3 = "Push";
      posL3 = LINE_POS_L3;
      display_4 =  "Select";
      posL4 = LINE_POS_L2;
  
}