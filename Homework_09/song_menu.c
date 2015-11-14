#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void getShapesMenu(unsigned int adc_value){
  const char HW9_String[] = "We're the Red and White from State And we know we are the best. 
                             A hand behind our back, We can take on all the rest. Come over the hill, 
                             Carolina. Devils and Deacs stand in line. The Red and White from N.C. State.
                             Go State!";
  unsigned int test = adc_value % 2;
  big = ALWAYS;
  lcd_BIG_mid();
  if(value <= MENU1){
    setLCD("----------",LINE_POS_L0,"We're the ",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU2){
    setLCD("----------",LINE_POS_L0,"Square",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU3){
    setLCD("----------",LINE_POS_L0,"Triangle",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU4){
    setLCD("----------",LINE_POS_L0,"Octagon",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU5){
    setLCD("----------",LINE_POS_L0,"Pentagon",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU6){
    setLCD("----------",LINE_POS_L0,"Hexagon",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU7){
    setLCD("----------",LINE_POS_L0,"Cube",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU8){
    setLCD("----------",LINE_POS_L0,"Oval",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else if(value == MENU9){
    setLCD("----------",LINE_POS_L0,"Sphere",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
  else{
    setLCD("----------",LINE_POS_L0,"Cylinder",LINE_POS_L2," ",LINE_POS_L1,"----------",LINE_POS_L0);
    ADC_Process();
  }
}