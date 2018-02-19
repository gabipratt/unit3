#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(11, 10); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value); 

int sensorpin = A0;            // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
 Serial.begin(9600);               // starts the serial monitor
 mySoftwareSerial.begin(9600);
 Serial.begin(115200);

 Serial.println();
 Serial.println(F("DFRobot DFPlayer Mini Demo"));
 Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
 
 if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
   Serial.println(F("Unable to begin:"));
   Serial.println(F("1.Please recheck the connection!"));
   Serial.println(F("2.Please insert the SD card!"));
   while(true);
}
 Serial.println(F("DFPlayer Mini online."));
}
 void read_value () {

  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  Serial.println(val);            // prints the value of the sensor to the serial monitor
  delay(400);                    // wait for this much time before printing next value 
 }
 
void loop()
{
  if (read_value > 600)
  {
    myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    myDFPlayer.play(1);  //Play the first mp3
  }
    else 
  myDFPlayer.stop();
}


