#include "PersonalSpace.cpp"
#define READ_DELAY 100 //Delay between readings in milliseconds

#define CHB_DIR 13
#define CHB_PWM 11
#define CHB_BRK 8
#define CHB_SNS A1

#define CHA_DIR 12
#define CHA_PWM 3
#define CHA_BRK 9
#define CHA_SNS A0


PersonalSpace personalSpace;

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
   init_motor();
}

void loop()
{

  personalSpace.measure_distance();

  // this ensures that the robot only reacts within the sight range
  if (personalSpace.isInRange()) {

    if (personalSpace.isInDangerDistance()) {
      // here you will trigger the shutdown system
      Serial.println("DANGER!");
      analogWrite(CHB_PWM, random(0,255));
      analogWrite(CHA_PWM, random(0,255));
    }
    else {
      Serial.print("Proximity percantage = ");
      float perc = personalSpace.getProximityPercentage();
      Serial.println(perc);
      analogWrite(CHB_PWM, map(perc,0,100,0,255));
      analogWrite(CHA_PWM, map(perc,0,100,0,255));
      //This shows the range in percentage from 0 to 100% within the range untill the DANGER range
    }


  } else {
    Serial.println("Can't see anyone");
    //Range above the defined sight range
     analogWrite(CHB_PWM, 0);
      analogWrite(CHA_PWM, 0);
  }

  //Delay before the next reading
  delay(READ_DELAY);
}

