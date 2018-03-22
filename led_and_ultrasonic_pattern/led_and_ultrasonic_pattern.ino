#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin



//const int freq = 500;
//const int dur = 20;
//const int buzzer = 3;
const int red3 = 3;
const int red2 = 4;
const int red1 = 5;
const int yellow3 = 6;
const int yellow2 = 9;
const int yellow1 = 10;
//const int green3 = 11; 
//const int green2 = 12;
//const int green1 = 13;



int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance


void setup() {
// pinMode(buzzer, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
// pinMode(green1, OUTPUT);
// pinMode(green2, OUTPUT);
// pinMode(green3, OUTPUT);
 pinMode(yellow1, OUTPUT);
 pinMode(yellow2, OUTPUT);
 pinMode(yellow3, OUTPUT);
 pinMode(red1, OUTPUT);
 pinMode(red2, OUTPUT);
 pinMode(red3, OUTPUT);
 
 
// digitalWrite(green1, HIGH);
// digitalWrite(green2, HIGH);
// digitalWrite(green3, HIGH);
 digitalWrite(yellow1, HIGH);
 digitalWrite(yellow2, HIGH);
 digitalWrite(yellow3, HIGH);
 digitalWrite(red1, HIGH);
 digitalWrite(red2, HIGH);
 digitalWrite(red3, HIGH);
 
 delay(300);
// digitalWrite(green1, LOW);
// digitalWrite(green2, LOW);
// digitalWrite(green3, LOW);
 digitalWrite(yellow1, LOW);
 digitalWrite(yellow2, LOW);
 digitalWrite(yellow3, LOW);
 digitalWrite(red1, LOW);
 digitalWrite(red2, LOW);
 digitalWrite(red3, LOW);
 
 //tone(buzzer, freq, duration);
 
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 


 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 
 if (distance < 7){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, HIGH);
   digitalWrite(yellow2, HIGH);
   digitalWrite(yellow3, HIGH);
   digitalWrite(red1, HIGH);
   digitalWrite(red2, HIGH);
   digitalWrite(red3, HIGH);
   
   
   
 } else if (distance < 15){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, HIGH);
   digitalWrite(yellow2, HIGH);
   digitalWrite(yellow3, HIGH);
   digitalWrite(red1, HIGH);
   digitalWrite(red2, HIGH);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 20){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, HIGH);
   digitalWrite(yellow2, HIGH);
   digitalWrite(yellow3, HIGH);
   digitalWrite(red1, HIGH);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 25){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, HIGH);
   digitalWrite(yellow2, HIGH);
   digitalWrite(yellow3, HIGH);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 30){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, HIGH);
   digitalWrite(yellow2, HIGH);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 35){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, HIGH);
   digitalWrite(yellow2, LOW);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 40){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, HIGH);
   digitalWrite(yellow1, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 45){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, HIGH);
//   digitalWrite(green3, LOW);
   digitalWrite(yellow1, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 50){
//   digitalWrite(green1, HIGH);
//   digitalWrite(green2, LOW);
//   digitalWrite(green3, LOW);
   digitalWrite(yellow1, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
   
   
 } else if (distance < 55){
//   digitalWrite(green1, LOW);
//   digitalWrite(green2, LOW);
//   digitalWrite(green3, LOW);
   digitalWrite(yellow1, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);

 } else if (distance > 55){
//   digitalWrite(green1, LOW);
//   digitalWrite(green2, LOW);
//   digitalWrite(green3, LOW);
   digitalWrite(yellow1, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(yellow3, LOW);
   digitalWrite(red1, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(red3, LOW);
 } 
 
//if(distance < 7){
//   tone(buzzer, freq, dur);
//   delay(5);
// } else if (distance < 15){
//   tone(buzzer, freq, dur);
//   delay(10);
// } else if (distance < 20){
//   tone(buzzer, freq, dur);
//   delay(15);
// } else if (distance < 25){
//   tone(buzzer, freq, dur);
//   delay(20);
// } else if (distance < 30){
//   tone(buzzer, freq, dur);
//   delay(25);
// } else if (distance < 35){
//   tone(buzzer, freq, dur);
//   delay(30);
// } else if (distance < 40){
//   tone(buzzer, freq, dur);
//   delay(35);
// } else if (distance < 45){
//   tone(buzzer, freq, dur);
//   delay(40);
// } else if (distance < 50){
//   tone(buzzer, freq, dur);
//   delay(45);
// } else if (distance < 55){
//   tone(buzzer, freq, dur);
//   delay(50);
// } 


 
 //Delay 50ms before next reading.
 //delay(50);
}
