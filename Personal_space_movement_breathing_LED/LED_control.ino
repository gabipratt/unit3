int LED_PINS [] = {7, 6};


int pattern1[][2] = {
 { 1, 1 },
 { 1, 0},
 { 0,1},
};
int pattern2[][2] = {
{ 1,0 },
{ 0, 1 },
{ 0, 0 },
};

int patternSpeed = 100; // milliseconds

void ledSetup () {
  for (int i = 0; i < 5; i = i + 1) {
    int pin = LED_PINS[i];
    pinMode(pin, OUTPUT);
    //digitalWrite(pin, HIGH);
  }
}


void patternUpdate () {
  int timeIndex = millis() / patternSpeed;
  int patternLength = sizeof(pattern1[0]);
  timeIndex = timeIndex % patternLength; // this gives you always numbers between 0 and patternlength

  for (int i = 0; i < 5; i = i + 1) {
    int pin = LED_PINS[i];
    //int[] patternForPin = pattern[i];
    int pinValue = pattern1[i][timeIndex];
    if (pinValue == 1)
      digitalWrite(pin, HIGH);
      else
      digitalWrite(pin, LOW);
  }

}
