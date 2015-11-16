#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
//******************************************************************************
//
//  Description: This file contains code for the second option, "Shapes" , in the top menu
//   
//
//  Steffon Brigman
//  Noember 2015
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************

void getShapesMenu(unsigned int adc_value){
/*******************************************************************************
*        Author: Steffon Brigman
*        Date:   November 2015
*        Description: This fucntion displays options under "Shapes" in the top menu
*        Built with IAR Embedded Workbench Version: V7.0.5/W32 (6.10.5)
*
*        Funcction name: getShapesMenu
*        Passed : No variables passed 
*        Returned: no values returned 
*        Locals: adc_value
*        Globlas: big
*******************************************************************************/
  char value = adc_value >> SHIFT6; // shift 10 bit value by 6 bits
  big = ALWAYS;
  lcd_BIG_mid();
  if(value <= MENU1){
    setLCD("----------",LINE_POS_L0,"Circle",LINE_POS_L2,"Square",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU2){
    setLCD("Circle",LINE_POS_L0,"Square",LINE_POS_L2,"Triangle",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU3){
    setLCD("Square",LINE_POS_L0,"Triangle",LINE_POS_L2,"Octagon",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU4){
    setLCD("Triangle",LINE_POS_L0,"Octagon",LINE_POS_L2,"Hexagon",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU5){
    setLCD("Octagon",LINE_POS_L0,"Pentagon",LINE_POS_L2,"Hexagon",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU6){
    setLCD("Pentagon",LINE_POS_L0,"Hexagon",LINE_POS_L2,"Cube",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU7){
    setLCD("Hexagon",LINE_POS_L0,"Cube",LINE_POS_L2,"Oval",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU8){
    setLCD("Cube",LINE_POS_L0,"Oval",LINE_POS_L2,"Sphere",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU9){
    setLCD("Oval",LINE_POS_L0,"Sphere",LINE_POS_L2,"Cylinder",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else{
    setLCD("Sphere",LINE_POS_L0,"Cylinder",LINE_POS_L2,"----------",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
}