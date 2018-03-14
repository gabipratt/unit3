class Flasher
{
  int ledPin;      // the number of the LED pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time

  // These maintain the current state
  int ledState;                 // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated

  bool flashing;
  unsigned long flashingStarted;
  unsigned long flashingTime;

  float level;
  
  public:

  Flasher(int pin, long on, long off)
  {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);     
      
    OnTime = on;
    OffTime = off;
    
    ledState = LOW; 
    previousMillis = 0;
  }

  void flash(int howlong = 1000) {
    if (!flashing) {
      flashing = true;
      flashingStarted = millis();
      flashingTime = howlong;
    }
  }

/*
  void stop() {
      //flashing = false;
      digitalWrite(ledPin, LOW);
  }
*/

  void reset() {
    flashing = false;
    flashingStarted = millis();
  }

  void debug(){
    Serial.print(level);
    Serial.print(", ");
  }
  /*

  float smooth() {
    return (exp(sin(millis()/(float(OnTime+OffTime))*PI)) - 0.36787944) * 108.0;
  }

  float onoff() {
      float val = .0;
      unsigned long currentMillis = millis();

      if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
      {
        ledState = LOW;  // Turn it off
        previousMillis = currentMillis;  // Remember the time
        val = .0;
      }
      else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
      {
        ledState = HIGH;  // turn it on
        previousMillis = currentMillis;   // Remember the time
        val = 255.0;
      }
      return val;
  }
  */
  
  void update()
  {
    // check to see if it's time to change the state of the LED
    //level = smooth();

    if(flashing && (millis()-flashingStarted)<flashingTime) {
        digitalWrite(ledPin, HIGH);//level);
    }

    else if(flashing && (millis() - flashingStarted) >= flashingTime ) {
        //stop();
        digitalWrite(ledPin, LOW);
        if ((millis()-flashingStarted)>=flashingTime*2) {
          reset();  
        }
    }

    
    
  } // update ()

}; // class
