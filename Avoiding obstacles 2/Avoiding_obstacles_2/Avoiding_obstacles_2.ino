#define CHB_DIR 13 
#define CHB_PWM 11
#define CHB_BRK 8
#define CHB_SNS A1

#define CHA_DIR 12
#define CHA_PWM 3
#define CHA_BRK 9
#define CHA_SNS A0


#define TRIG_PIN A4
#define ECHO_PIN A5
int motorB_speed = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(CHA_DIR, OUTPUT);
  pinMode(CHA_BRK, OUTPUT);
  digitalWrite(CHA_DIR, LOW);
  digitalWrite(CHA_BRK, LOW);
  pinMode(CHB_DIR, OUTPUT);
  pinMode(CHB_BRK, OUTPUT);
  digitalWrite(CHB_DIR, LOW);
  digitalWrite(CHB_BRK, LOW);
}

void loop() {
int distanceR = 0;
int distanceL =  0;
delay(40);
 
 if(distance<=15)
{
 moveStop();
 delay(100);
 moveBackward();
 delay(300);
 moveStop();
 delay(200);
 distanceR = lookRight();
 delay(200);
 distanceL = lookLeft();
 delay(200);

 if(distanceR>=distanceL)
 {
   turnRight();
   moveStop();
 }else
 {
   turnLeft();
   moveStop();
 }
}else
{
 moveForward();
}
distance = readPing();
}

int lookRight()
{
   myservo.write(50);
   delay(500);
   int distance = readPing();
   delay(100);
   myservo.write(115);
   return distance;
}

int lookLeft()
{
   myservo.write(170);
   delay(500);
   int distance = readPing();
   delay(100);
   myservo.write(115);
   return distance;
   delay(100);
}

int readPing() {
 delay(70);
 int cm = sonar.ping_cm();
 if(cm==0)
 {
   cm = 250;
 }
 return cm;
}

void moveStop() {
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 }
 
void moveForward() {

if(!goesForward)
 {
   goesForward=true;
   motor1.run(FORWARD);      
   motor2.run(FORWARD);      
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
   motor1.setSpeed(speedSet);
   motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
   delay(5);
  }
 }
}

void moveBackward() {
   goesForward=false;
   motor1.run(BACKWARD);      
   motor2.run(BACKWARD);  
 for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
 {
   motor1.setSpeed(speedSet);
   motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
   delay(5);
 }
}  

void turnRight() {
 motor1.run(FORWARD);
 motor2.run(BACKWARD);    
 delay(300);
 motor1.run(FORWARD);      
 motor2.run(FORWARD);      
}

void turnLeft() {
 motor1.run(BACKWARD);    
 motor2.run(FORWARD);    
 delay(300);
 motor1.run(FORWARD);    
 motor2.run(FORWARD);
}
//int lightRight = analogRead(LGT_SNS_RGT)/4; 
 //int lightLeft = analogRead(LGT_SNS_LFT)/4;

  
 //Serial.print("left sensor: ");
// Serial.println(lightLeft);
//Serial.print("right sensor: ");
//Serial.println(lightRight);
  
//put your main code here, to run repeatedly:
// analogWrite(CHB_PWM, lightLeft); //conect sensor value to direction
// analogWrite(CHA_PWM, lightRight);
 
 
}
