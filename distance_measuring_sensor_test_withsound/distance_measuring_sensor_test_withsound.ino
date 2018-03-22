#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

//const int freq = 500;
//const int dur = 20;
//const int buzzer = 3;
int sensorpin = A0;            // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
 int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
  //pinMode(buzzer, OUTPUT);
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

void loop() {
  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  Serial.println(val);            // prints the value of the sensor to the serial monitor
  delay(400);                    // wait for this much time before printing next value 
 if ( val > 300){ // how close to the sensor it gets triggered
   myDFPlayer.volume(30);
   myDFPlayer.play(2);
   delay (2000); //how long will the sound play
 
 }
 else if (val < 200){
   myDFPlayer.volume(30);
   myDFPlayer.play(1);
   delay (2000); //how long will the sound play
 }

else {
  myDFPlayer.stop();
}
}


