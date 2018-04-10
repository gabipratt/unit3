#include "Arduino.h"
#define PING_PIN 4 //Use digital pin 4  for the range finder
#define MAX_DEPTH_SIGHT 100 // the distance in cm it can "see"
#define DANGER_DISTANCE 10 // the danger distance in cm it can "see"

//D4 is connected to STG
//5V is connected to VCC
//GND is connected to GND
//NC is not used

class PersonalSpace {

    long cm;

  public:

    PersonalSpace() {}

    void measure_distance() {
      //Set Ping Pin to OUTPUT mode
      pinMode(PING_PIN, OUTPUT);
      //Send a HIGH signal for 5 microseconds
      digitalWrite(PING_PIN, HIGH);
      delayMicroseconds(5);
      digitalWrite(PING_PIN, LOW);

      //Now read back the distance as a time value (microseconds) using the same pin
      pinMode(PING_PIN, INPUT);
      long duration = pulseIn(PING_PIN, HIGH);

      //Convert the time into a distance
      cm  = microsecondsToCentimeters(duration);
    }

    bool isInRange() {
      return cm < MAX_DEPTH_SIGHT;
    }

    bool isInDangerDistance() {
      return cm < DANGER_DISTANCE;
    }

    int getProximityPercentage()
    {
      return map(cm,DANGER_DISTANCE,MAX_DEPTH_SIGHT,100,0);
      //Defines the sight range untill the DANGER range from 0 to 100%
    }

    long getTheDistance()
    {
      return cm;
    }

    long microsecondsToCentimeters(long microseconds)
    {
      //The speed of sound is 340 m/s or 29 microseconds per centimeter
      //The ping travels twice the distance, there and back and so divide by 58
      return microseconds / 58;
    }
};
