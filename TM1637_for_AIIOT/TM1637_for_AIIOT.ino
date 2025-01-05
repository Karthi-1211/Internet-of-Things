#include <TM1637Display.h>
const int CLK = D1; //Set the CLK pin connection to the display
const int DIO = D0; //Set the DIO pin connection to the display
int numCounter = 0;
TM1637Display display(CLK, DIO); //set up the 4-Digit Display.

void setup()
{
 display.setBrightness(0x0a); //set the diplay to maximum brightness
 
  pinMode(D4,OUTPUT);
}
void loop()
{
  //int x=analogRead(A0);
 // Serial.println();
  int num=0;
  for(num=0;num<100;num++)
  {
    display.showNumberDec(num);
  }
  
 //Display the numCounter value;
  delay(100);
}
