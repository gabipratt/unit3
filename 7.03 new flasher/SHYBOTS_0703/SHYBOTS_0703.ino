#include "corestats.h"
#include "flasher.h"                        
#define CLAUS
#include "personality.h"

#define CHB_DIR 13
#define CHB_PWM 11
#define CHB_BRK 8
#define CHB_SNS A1

#define CHA_DIR 12
#define CHA_PWM 3
#define CHA_BRK 9
#define CHA_SNS A0

#define LDR_Right A3
#define LDR_Left  A2

// mapping ranges light sensors (thresholds)
#define LGT_THR_LFT_MIN 180 // lowerbund of the LEFT eye
#define LGT_THR_LFT_MAX 988
#define LGT_THR_RGT_MIN 240 // right
#define LGT_THR_RGT_MAX 990

#define LDR_READ_EVERY_MS 200 //5 Times per second

#define VIBRATION_PIN 2
//#define LED_PIN 4
//#define LED_PIN2 5          

const int ledPin = 5;
Flasher led(ledPin, 800, 2000);              // We added this today from Led_Flasher
int threshold = 500;

int motorB_speed = 0;

int BEHAVIOUR_NORMAL = 0;
int BEHAVIOUR_PARANOID = 1;
int behaviourMode = BEHAVIOUR_NORMAL;

boolean lightWasShined = false;
int paranoidCounter = 0;               // Count the light flashes

//RunningAverage avgL( (1000 / LDR_READ_EVERY_MS) * 10 );
//RunningAverage avgR( (1000 / LDR_READ_EVERY_MS) * 10 );

AdaptiveNormalizer mavgL(0,1);
AdaptiveNormalizer mavgR(0,1);

int leftEye, rightEye;

//SoftwareSerial mySoftwareSerial(6, 10); // RX, TX // for the mp3  module
//SoftwareSerial mySoftwareSerial(0, 1); // RX, TX // for the mp3  module
//DFRobotDFPlayerMini myDFPlayer;
//void printDetail(uint8_t type, int value);

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

void setup() {
  // put your setup code here, to run once:
//  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

pinMode(A0, INPUT);                          //included this from flasher LED code
  
  init_motor();
  //init_audio();

  pinMode(VIBRATION_PIN, OUTPUT);
//  pinMode (LED_PIN, OUTPUT);
}

void debug_text() {
  Serial.print("left sensor: ");
  Serial.println(leftEye);
  Serial.print("right sensor: ");
  Serial.println(rightEye);
}

void debug_graph() {
//  Serial.print(leftEye);
//  Serial.print(",");
//  Serial.print(rightEye);
//  Serial.print(",");
  Serial.print( mavgL.get() );
  Serial.print(",");
  Serial.println( mavgR.get() );
}

void read_eyes() {

  rightEye = readEye(LDR_Right);
  mavgR.put( rightEye );

  leftEye = readEye(LDR_Left);
  mavgL.put( leftEye );
}
//void blinking_light () {
//  digitalWrite (LED_PIN,HIGH);
//  delay (2000);
//  digitalWrite (LED_PIN,LOW);
//  delay (2000);
 // digitalWrite (LED_PIN2, HIGH);
 // delay (500);
  //digitalWrite (LED_PIN2, LOW);
 // delay (2000);
 // Flasher led for milliseconds 
//  }
  

void steer_with_light() {
  // put your main code here, to run repeatedly:
  analogWrite(CHB_PWM, mappedMotorValue(leftEye, true)); //conect sensor value to direction
  analogWrite(CHA_PWM, mappedMotorValue(rightEye, false));
}

void loop() {
  debug_graph();


  read_eyes();
 
 
 // read analog sensor for interaction
  int reading = 0;
  for(int i = 0; i < 4; i++) {
    reading += analogRead(A0);
  }
  reading == reading >> 2;

  // flash if threshold is overflown, stop otherwise
  if(reading > threshold) {
    led.flash();
  } else {
    led.stop();
  }

  led.update(); // update the flasher
  led.debug();
  
  Serial.print(threshold);
  Serial.print(", ");
  Serial.println(reading);
  
  delay(10);

  // normal behaviour:
  if (behaviourMode == BEHAVIOUR_NORMAL) {
    steer_with_light();
    if (mavgR.get() > (0.4*SENSITIVITY) || mavgL.get() > (0.4*SENSITIVITY) ) { // when the room is really dark it should be around 400. Maximun is 1000.
      shake(true);
    }
    else if (mavgR.get() < (0*SENSITIVITY) || mavgL.get() < (0*SENSITIVITY)) { // if there is no light stops vibrating
      shake(false);
//      blinking_light ();
    }

    // check for paranoid light:
    if (mavgR.get() > (8*SENSITIVITY) || mavgL.get() > (8*SENSITIVITY)) {       //change from 12 to 8 @7.52
      
      if (lightWasShined==false) {
        
        paranoidCounter++;
        Serial.print("HELP ");
        Serial.println(paranoidCounter);
        
        if (paranoidCounter==3) {
          behaviourMode = BEHAVIOUR_PARANOID;
          paranoidCounter = 0;
        }
      }
      lightWasShined = true;
    } else {
      lightWasShined = false;
    }
    
  }

  // PARANOID
  else if (behaviourMode == BEHAVIOUR_PARANOID) { 
    shake(true);
    if (random(2)<1) {
      analogWrite(CHB_PWM, 255); //conect sensor value to direction
      analogWrite(CHA_PWM, 0);
    } else {
      analogWrite(CHB_PWM, 0); //conect sensor value to direction
      analogWrite(CHA_PWM, 255);
    }
    delay(2000);
    behaviourMode = BEHAVIOUR_NORMAL;
  }
  
  delay(50);

}
double readEye(int eye) {
  double reading = .0;
  // read 4 times to get a stable reading
  for (int i = 0; i < 4; i++) {
    reading += analogRead(eye);
    delay(5);
  }

  return (reading / 4.0);
}


void shake(bool _shakeOn) {
  digitalWrite (VIBRATION_PIN, _shakeOn); // if the light is turned on, it activates the vibrating module
  //  delay (1000);
  //  digitalWrite (5, LOW);
  //  delay (1000);
}

int mappedMotorValue(int reading, bool isLeft) {
  int mappedValue;
  if (isLeft) {
    mappedValue = map(reading, LGT_THR_LFT_MIN, LGT_THR_LFT_MAX, 0, 1023);
  } else {
    mappedValue = map(reading, LGT_THR_RGT_MIN, LGT_THR_RGT_MAX, 0, 1023);
  }
  mappedValue = mappedValue / 4;
  if (mappedValue < 0) return 0;
  // --------------------------
  if (mappedValue > 255) return 255;
  return mappedValue;
}

