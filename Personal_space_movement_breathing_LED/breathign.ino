
int breatheMin = 25;
int breatheMax = 180;

float breatheOutPercentage = 0.65f;

Servo myservoR;  // create servo object to control a servo
Servo myservoL;

void setupBreathing() {
  myservoR.attach(5);  // attaches the servo on pin 9 to the servo object 
  myservoL.attach(10); // attaching second servo to pin 2
}

void updateBreathing() {
  int clippedMS = millis() % breatheCycleMilliseconds;
  float breatheCyclePercentage = clippedMS / (float)breatheCycleMilliseconds; // a number between 0 and 1 depending on where we are in the breathing cycle

  float value = 0;
  if (breatheCyclePercentage < breatheOutPercentage) {
    value = mapF(breatheCyclePercentage, 0, breatheOutPercentage, breatheMin, breatheMax);
  } else {
    value = mapF(breatheCyclePercentage, breatheOutPercentage, 1.0, breatheMax, breatheMin);
  }
  myservoR.write((int)value);
  myservoL.write((int)value);
}

float mapF(float v, float v0, float v1, float o0, float o1) {
  return o0 + (o1-o0)*(v-v0)/(v1-v0);
}

