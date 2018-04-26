#include <Servo.h>
#include "PersonalSpace.cpp"
#define READ_DELAY 10 //Delay between readings in milliseconds (used to be 100)

//int myPins[] = { 7, 6,};
//int pattern1[][2] = {
// { 1, 1 },
// { 1, 0},
// { 0,1},
//};
//int pattern2[][2] = {
//{ 1,0 },
//{ 0, 1 },
//{ 0, 0 },
//};

int breatheCycleMilliseconds = 4000;
PersonalSpace personalSpace;

#define CHB_DIR 13
#define CHB_PWM 11
#define CHB_BRK 8
#define CHB_SNS A1

#define CHA_DIR 12
#define CHA_PWM 3
#define CHA_BRK 9
#define CHA_SNS A0

//PersonalSpace personalSpace;
//Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//int pos = 0;    // variable to store the servo position


void init_motor() {
  // initialize the PWM pins
  pinMode(CHB_PWM, OUTPUT);
  digitalWrite(CHB_PWM, LOW);
  // initialize the PWM pins
  pinMode(CHA_PWM, OUTPUT);
  digitalWrite(CHA_PWM, LOW);

  pinMode(CHA_DIR, OUTPUT);
  pinMode(CHA_BRK, OUTPUT);
  digitalWrite(CHA_DIR, LOW);
  digitalWrite(CHA_BRK, LOW);
  pinMode(CHB_DIR, OUTPUT);
  pinMode(CHB_BRK, OUTPUT);
  digitalWrite(CHB_DIR, LOW);
  digitalWrite(CHB_BRK, LOW);

  Serial.println( "initializing motor" );       


                                                                                                          
}
void setup()
{
  //Start the serial connection
   Serial.begin(9600);
   //myservo.attach(5);  // attaches the servo on pin 5 to the servo object
   setupBreathing();
   ledSetup ();
   init_motor();
}

void loop()
{

  personalSpace.measure_distance();
  patternUpdate();
  // this ensures that the robot only reacts within the sight range
  if (personalSpace.isInRange()) {

    if (personalSpace.isInDangerDistance()) {
      // here you will trigger the shutdown system
      Serial.println("DANGER!");
      analogWrite(CHB_PWM, random(0,255));
      analogWrite(CHA_PWM, random(0,255));
      breatheCycleMilliseconds = 700;

      //servo movement
//for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  //}
 // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(15);                       // waits 15ms for the servo to reach the position



      
   // }
    }    else {
      Serial.print("Proximity percantage = ");
      float perc = personalSpace.getProximityPercentage();
     //steering
      Serial.println(perc);
      analogWrite(CHB_PWM, map(perc,0,100,0,255));
      analogWrite(CHA_PWM, map(perc,0,100,0,255));
      
      breatheCycleMilliseconds = 4000;
      //This shows the range in percentage from 0 to 100% within the range untill the DANGER range
    }


  } else {
    Serial.println("Can't see anyone");
    //Range above the defined sight range
     analogWrite(CHB_PWM, 0);
     analogWrite(CHA_PWM, 0);
     breatheCycleMilliseconds = 4000;
  }
  updateBreathing();
  //Delay before the next reading
  //delay(READ_DELAY);
}

