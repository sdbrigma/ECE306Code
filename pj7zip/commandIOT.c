//******************************************************************************
//
//  Description: This file turns on the right forward port
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//******************************************************************************

//------------------------------------------------------------------------------

//Points to Header files for Preprocessing
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Command_IOT(void){
//******************************************************************************
//
//  Description: This function implements the IOT operating system after
//  configuration
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runRight
//
// Local: tmp
//
// Return: VOID
//
//****************************************************************************** 
  int L,R,T = TRUE;
  int i = INITIAL;
  Display_Format();
  display_2 = "SYS. READY";
  Display_Process();
  Five_msec_Delay(BIGGER_DELAY);
  for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
  Time_Sequence = INITIAL;
  
  while(ALWAYS) {
   // Command has been issued
    if (IOT_RX[Pos0] == '*') {
      Five_msec_Delay(TRUE);
      // HARD CODED SECURITY PIN
      if ((IOT_RX[Pos1] == '2') && (IOT_RX[Pos2] == '5') && (IOT_RX[Pos3] == '4') && (IOT_RX[Pos4] == '0')) {
        Five_msec_Delay(LIL_DELAY); 
        UCA1IE &= ~UCRXIE;
        // FORWARD COMMAND
        if(IOT_RX[Pos5] == 'F') {
          L = IOT_RX[Pos6] - NUMBER_OP;
          R = IOT_RX[Pos7] - NUMBER_OP;
          T = IOT_RX[Pos8] - NUMBER_OP;
          IOT_driveForward(L, R, T);
        }
        else if(IOT_RX[Pos5] == 'B') {
          L = IOT_RX[Pos6] - NUMBER_OP;
          R = IOT_RX[Pos7] - NUMBER_OP;
          T = IOT_RX[Pos8] - NUMBER_OP;
          IOT_driveReverse(L, R, T);
        }
        else if(IOT_RX[Pos5] == 'L') {
          T = IOT_RX[Pos8] - NUMBER_OP;
          IOT_Clockwise(T);
        }
        else if(IOT_RX[Pos5] == 'R') {
          T = IOT_RX[Pos8] - NUMBER_OP;
          IOT_Counterclockwise(T);
        }
        UCA1IE |= UCRXIE;
        for(i=INITIAL; i < SMALL_RING_SIZE; i++) IOT_RX[i] = INITIAL;
      }
    }
    
    if (!(P4IN & SW2)) {
      Five_msec_Delay(LIL_SW_DELAY); 
      break;
    }
    if(Time_Sequence > CASE250){                  // Fail-safe for clock
      PING();
      Time_Sequence = INITIAL;
    }
  }
}

void IOT_driveForward(unsigned int leftDrive, unsigned int rightDrive, unsigned int runTime){
//******************************************************************************
//
//  Description: This function implements the IOT forward drive
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runRight
//
// Local: tmp
//
// Return: VOID
//
//******************************************************************************
  
  display_1 = "----------";
  posL1 = LINE_POS_L0;
  display_2 = " Forward  ";
  posL2 = LINE_POS_L0;
  display_3 = "----------";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
  runTime *= ONE_SEC_COUNT;
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  while(A0_time_count <= runTime) {
    Left_Forward_On(leftDrive);
    Left_Forward_Off();
    Right_Forward_On(rightDrive);
    Right_Forward_Off();
  }
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  
  display_2 = "SYS. READY";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
}

void IOT_driveReverse(unsigned int leftDrive, unsigned int rightDrive, unsigned int runTime){
//******************************************************************************
//
//  Description: This function implements the IOT forward drive
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runRight
//
// Local: tmp
//
// Return: VOID
//
//******************************************************************************
  
  display_1 = "----------";
  posL1 = LINE_POS_L0;
  display_2 = " Reverse  ";
  posL2 = LINE_POS_L0;
  display_3 = "----------";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
  runTime *= ONE_SEC_COUNT;
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  while(A0_time_count <= runTime) {
    Left_Reverse_On(leftDrive);
    Left_Reverse_Off();
    Right_Reverse_On(rightDrive);
    Right_Reverse_Off();
  }
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  
  display_2 = "SYS. READY";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
}

void IOT_Clockwise(unsigned int runTime){
//******************************************************************************
//
//  Description: This function implements the IOT forward drive
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runRight
//
// Local: tmp
//
// Return: VOID
//
//******************************************************************************
  
  display_1 = "----------";
  posL1 = LINE_POS_L0;
  display_2 = "Clockwise ";
  posL2 = LINE_POS_L0;
  display_3 = "----------";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
  runTime *= ONE_SEC_COUNT;
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  while(A0_time_count <= runTime) {
    Left_Forward_On(TRUE);
    Left_Forward_Off();
    Right_Reverse_On(TRUE);
    Right_Reverse_Off();
  }
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  
  display_2 = "SYS. READY";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
}

void IOT_Counterclockwise(unsigned int runTime){
//******************************************************************************
//
//  Description: This function implements the IOT forward drive
//
//  Steffon Brigman
//  Sept 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (6.30.3)
//
// Globals: Time_Sequence
//
// Passed: runRight
//
// Local: tmp
//
// Return: VOID
//
//******************************************************************************
  
  display_1 = " Counter  ";
  posL1 = LINE_POS_L0;
  display_2 = "Clockwise ";
  posL2 = LINE_POS_L0;
  display_3 = "----------";
  posL3 = LINE_POS_L0;
  display_4 = "          ";
  posL4 = LINE_POS_L0;
  big = TRUE;
  lcd_BIG_mid();
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
  
  runTime *= ONE_SEC_COUNT;
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  while(A0_time_count <= runTime) {
    Left_Reverse_On(TRUE);
    Left_Reverse_Off();
    Right_Forward_On(TRUE);
    Right_Forward_Off();
  }
  Right_Forward_Off();
  Left_Forward_Off();
  Right_Reverse_Off();
  Left_Reverse_Off();
  Time_Sequence = INITIAL;
  A0_time_count = INITIAL;
  
  display_1 = "----------";
  display_2 = "SYS. READY";
  Display_Process();
  Five_msec_Delay(BIG_DELAY);
}