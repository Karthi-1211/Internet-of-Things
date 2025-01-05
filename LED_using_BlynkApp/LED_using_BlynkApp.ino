/*New blynk app project
   Home Page
*/

#define BLYNK_TEMPLATE_ID "TMPL3AeBTHGpl"
#define BLYNK_TEMPLATE_NAME "LED Using Blynk"
#define BLYNK_AUTH_TOKEN "iWrXr6A_v2LNv9k2hSfr4Ly5vzjD_cfc"//Enter your blynk auth token


//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Balu";//Enter your WIFI name
char pass[] = "$AbK_001";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}