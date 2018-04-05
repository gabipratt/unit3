int myPins[] = {10, 7, 6, 5, 2};
int pattern[][5] = {
  { 1, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 1 },
};
int pattern1[][8] = {
  { 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
};
int patternSpeed = 100; // milliseconds



void setup () {
  for (int i = 0; i < 5; i = i + 1) {
    int pin = myPins[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}


void loop () {
  int timeIndex = millis() / patternSpeed;
  int patternLength = sizeof(pattern1[0]);
  timeIndex = timeIndex % patternLength; // this gives you always numbers between 0 and patternlength

  for (int i = 0; i < 5; i = i + 1) {
    int pin = myPins[i];
    //int[] patternForPin = pattern[i];
    int pinValue = pattern1[i][timeIndex];
    if (pinValue == 1)
      digitalWrite(pin, HIGH);
      else
      digitalWrite(pin, LOW);
  }

}

