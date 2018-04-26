// not used:   0 1 6 7 10
// used pins:  2(vib) 3(motor) 4(led) 5(led) 8(m)? 9(m)? 11(m) 12(m) 13(m)

#define CHB_DIR 13
#define CHB_PWM 11
#define CHB_BRK 8
#define CHB_SNS A1

#define SWITCH1 10
#define SWITCH2 7

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

#define LDR_READ_EVERY_MS 200 //5 times per second

#define VIBRATION_PIN 2
#define LED_PIN 4
#define LED_PIN2 5
#define LED_PIN3 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH1, INPUT);
  pinMode(SWITCH2, INPUT);
  pinMode(VIBRATION_PIN, OUTPUT);
  pinMode(CHA_DIR, OUTPUT);
  pinMode(CHA_PWM, OUTPUT);
  pinMode(CHB_DIR, OUTPUT);
  pinMode(CHB_PWM, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("--------------------------------");
  Serial.print("LDR_RIGHT: ");
  Serial.println(analogRead(LDR_Right));
  Serial.print("LDR_LEFT: ");
  Serial.println(analogRead(LDR_Left));
  Serial.print("SWITCH1: ");
  Serial.println(digitalRead(SWITCH1));
  Serial.print("SWITCH2: ");
  Serial.println(digitalRead(SWITCH2));

  boolean vib = (millis() % 2000) < 500;
  digitalWrite(VIBRATION_PIN, vib ? HIGH : LOW);
  Serial.print("Vibration: ");
  Serial.println(vib ? "ON" : "OFF");

  boolean wheel1 = (millis() % 10000) < 5000;
  boolean forward = (millis() % 5000) < 2500;
  if (wheel1) {
    Serial.print("WHEEL A: ");
    analogWrite(CHA_PWM, 255);
    analogWrite(CHB_PWM, 0);
    Serial.println(forward ? "FORWARD" : "BACKWARD");
    digitalWrite(CHA_DIR, forward ? HIGH : LOW);
  } else {
    Serial.print("WHEEL B: ");
    analogWrite(CHA_PWM, 0);
    analogWrite(CHB_PWM, 255);
    Serial.println(forward ? "FORWARD" : "BACKWARD");
    digitalWrite(CHB_DIR, forward ? HIGH : LOW);
  }

  int ledNr = (millis() % 1500) / 500;
  Serial.print("LED ON: ");
  Serial.println(ledNr);
  digitalWrite(LED_PIN, ledNr==0?HIGH:LOW);
  digitalWrite(LED_PIN2, ledNr==1?HIGH:LOW);
  digitalWrite(LED_PIN3, ledNr==2?HIGH:LOW);

  delay(300);
}
