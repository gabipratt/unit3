#include "PersonalSpace.cpp"
#define READ_DELAY 100 //Delay between readings in milliseconds


PersonalSpace personalSpace;

void setup()
{
  //Start the serial connection
  Serial.begin(9600);
}

void loop()
{

  personalSpace.measure_distance();

  // this ensures that the robot only reacts within the sight range
  if (personalSpace.isInRange()) {

    if (personalSpace.isInDangerDistance()) {
      // here you will trigger the shutdown system
      Serial.println("DANGER!");
    }
    else {
      Serial.print("Proximity percantage = ");
      Serial.println(personalSpace.getProximityPercentage());
      //This shows the range in percentage from 0 to 100% within the range untill the DANGER range
    }


  } else {
    Serial.println("Can't see anyone");
    //Range above the defined sight range
  }

  //Delay before the next reading
  delay(READ_DELAY);
}

