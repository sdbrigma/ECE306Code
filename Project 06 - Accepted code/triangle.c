//******************************************************************************
//
//  Description: This file is used to implement a triangle shape during runtime
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

void Triangle_Drive(void){
//******************************************************************************
//
//  Description: This file is used to implement a triangle shape during runtime
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
// Local: i
//
// Return: VOID
//
//****************************************************************************** 
  
	// Display GUI
	  display_1 = "Triangle";
      posL1 = LINE_POS_L1;
      display_2 = "Is Being";
      posL2 = LINE_POS_L1;
      display_3 = "Made!";
      posL3 = LINE_POS_L3;
      display_4 =  "3Angle: 1";
      posL4 = LINE_POS_L0;
      
	// Initialize
      Time_Sequence = INITIAL;
      Right_Forward_Off();
      Left_Forward_Off();
      int i = INITIAL;
      Display_Process();

    // First Triangle  
  while(i < TRI_STRGHT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
      
  while(i < TRI_TURN1) {                         
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;    
  
  while(i < TRI_STRGHT) {     
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
  
  while(i < TRI_TURN2) {       
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;    
  
  while(i < TRI_STRGHT) {       
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
  
   while(i < TRI_TURN2) {          
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_Off();
      i++;

    }

  i = INITIAL; 

  
	// Pause
      display_4 =  "  WAIT...";
      Display_Process();
      Right_Forward_Off();
      Left_Forward_Off();
      i = INITIAL;
      Five_msec_Delay(BIG_DELAY);
      Time_Sequence = INITIAL;
      display_4 =  "3Angle: 2";
      Display_Process();

	  
	// Second Triangle
  while(i < TRI_STRGHT) {                            
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
      
  while(i < TRI_TURN3) {                           
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;    
  
  while(i < TRI_STRGHT) {                          
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
  
  while(i < TRI_TURN2) {                         
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;    
  
  while(i < TRI_STRGHT) {                           
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_On(MOTOR_ENABLE);
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
  
   while(i < TRI_TURN2) {                         
      
      Left_Forward_On(MOTOR_ENABLE);
      Left_Forward_Off();
      Right_Forward_Off();
      i++;

    }

  i = INITIAL;
  

	// Finalize function
      Time_Sequence = INITIAL;
      Right_Forward_Off();
      Left_Forward_Off();
      
      display_1 = "Triangle";
      posL1 = LINE_POS_L2;
      display_2 = "Complete!";
      posL2 = LINE_POS_L1;
      display_3 = "Push";
      posL3 = LINE_POS_L3;
      display_4 =  "Select";
      posL4 = LINE_POS_L2;
  
}