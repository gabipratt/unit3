
int breatheMin = 25;
int breatheMax = 180;

float breatheOutPercentage = 0.65f;

Servo myservo;  // create servo object to control a servo

void setupBreathing() {
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object 
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
  myservo.write((int)value);
}

float mapF(float v, float v0, float v1, float o0, float o1) {
  return o0 + (o1-o0)*(v-v0)/(v1-v0);
}

