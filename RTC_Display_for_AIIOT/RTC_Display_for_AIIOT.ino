#include "RTClib.h"
#include <TM1637Display.h>
RTC_DS1307 rtc;

const int CLK = 14; //Set the CLK pin connection to the display
const int DIO = 12; //Set the DIO pin connection to the display
TM1637Display display(CLK, DIO); //set up the 4-Digit Display.
int hour;
void setup()
{
 display.setBrightness(0x0a); 
 Serial.begin(9600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    //Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  //rtc.adjust(DateTime(2023, 12, 29, 18, 1, 0));
}
//set the diplay to maximum brightness
void loop()
{
  //Iterate numCounter
 
   DateTime now = rtc.now();
    hour=now.hour();
    Serial.println(hour);
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
 display.showNumberDec((hour*100)+now.minute()); //Display the numCounter value;
delay(1000);
 }

