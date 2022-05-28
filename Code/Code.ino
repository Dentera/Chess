#include "LedControl.h"
LedControl matrix = LedControl(12, 11, 10); 
 
unsigned long delaytime = 250;

int row_1_p = 3;
int col_1_p = 2;

int row_p = 3;
int col_p = 2;
 
void setup() 
{  
  matrix.shutdown(0, false);
  matrix.setIntensity(0, 8);
  matrix.clearDisplay(0);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}
 
void loop() 
{
  matrix.setLed(0, row_1_p, col_1_p, true);
  matrix.setLed(0, row_p, col_p, true);
  if (digitalRead(2) == HIGH)
  {
    if (col_p < 7)
    { 
    matrix.setLed(0, row_p, col_p, false);
    col_p = col_p + 1;
    matrix.setLed(0, row_p, col_p, true);
    delay(400);
    }
  }
  if (digitalRead(3) == HIGH)
  {
    if (col_p > 0)
    {      
      matrix.setLed(0, row_p, col_p, false);
      col_p = col_p - 1;
      matrix.setLed(0, row_p, col_p, true);
      delay(400);      
    }
  }





  if (row_p == row_1_p and col_p == col_1_p)
  {
    matrix.setLed(0,row_p, col_p, false);
    delay(150);
    matrix.setLed(0,row_p, col_p, true);
    delay(150);
  }
}
