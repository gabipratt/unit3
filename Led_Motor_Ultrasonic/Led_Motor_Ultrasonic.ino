// Include Libraries
#include "Arduino.h"
#include "DCMDriverL298.h"
#include "NewPing.h"
#include "LED.h"
#include "Switchable.h"


// Pin Definitions
#define DCMOTORDRIVERL298_PIN_ENA	2
#define DCMOTORDRIVERL298_PIN_INT1	9
#define DCMOTORDRIVERL298_PIN_INT2	11
#define DCMOTORDRIVERL298_PIN_ENB	3
#define DCMOTORDRIVERL298_PIN_INT3	12
#define DCMOTORDRIVERL298_PIN_INT4	13
#define HCSR04_PIN_TRIG	15
#define HCSR04_PIN_ECHO	14
#define LEDBlue1_PIN_VIN	4
#define LEDBlue2_PIN_VIN	5
#define LEDBlue3_PIN_VIN	6
#define LEDBlue4_PIN_VIN	7
#define LEDBlue5_PIN_VIN	8
#define LEDBlue6_PIN_VIN	10



// Global variables and defines

// object initialization
DCMDriverL298 dcMotorDriverL298(DCMOTORDRIVERL298_PIN_ENA,DCMOTORDRIVERL298_PIN_INT1,DCMOTORDRIVERL298_PIN_INT2,DCMOTORDRIVERL298_PIN_ENB,DCMOTORDRIVERL298_PIN_INT3,DCMOTORDRIVERL298_PIN_INT4);
NewPing hcsr04(HCSR04_PIN_TRIG,HCSR04_PIN_ECHO);
LED ledB1(LEDBlue1_PIN_VIN);
LED ledB2(LEDBlue2_PIN_VIN);
LED ledB3(LEDBlue3_PIN_VIN);
LED ledB4(LEDBlue4_PIN_VIN);
LED ledB5(LEDBlue5_PIN_VIN);
LED ledB6(LEDBlue6_PIN_VIN);



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // L298N Motor Driver Board Module - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298.setMotorA(200,1);
    dcMotorDriverL298.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    delay(2000);

    }
    else if(menuOption == '2') {
    // Ultrasonic Sensor - HC-SR04 - Test Code
    // Read distance measurment from UltraSonic sensor           
    int hcsr04Dist = hcsr04.ping_cm();
    delay(10);
    Serial.print(F("Distance: ")); Serial.print(hcsr04Dist); Serial.println(F("[cm]"));

    }
    else if(menuOption == '3') {
    // LED - Basic Blue 5mm #1 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB1.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB1.off();                        // 3. turns off
    }
    else if(menuOption == '4') {
    // LED - Basic Blue 5mm #2 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB2.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB2.off();                        // 3. turns off
    }
    else if(menuOption == '5') {
    // LED - Basic Blue 5mm #3 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB3.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB3.off();                        // 3. turns off
    }
    else if(menuOption == '6') {
    // LED - Basic Blue 5mm #4 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB4.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB4.off();                        // 3. turns off
    }
    else if(menuOption == '7') {
    // LED - Basic Blue 5mm #5 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB5.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB5.off();                        // 3. turns off
    }
    else if(menuOption == '8') {
    // LED - Basic Blue 5mm #6 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB6.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB6.off();                        // 3. turns off
    }
    
    
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) L298N Motor Driver Board Module"));
    Serial.println(F("(2) Ultrasonic Sensor - HC-SR04"));
    Serial.println(F("(3) LED - Basic Blue 5mm #1"));
    Serial.println(F("(4) LED - Basic Blue 5mm #2"));
    Serial.println(F("(5) LED - Basic Blue 5mm #3"));
    Serial.println(F("(6) LED - Basic Blue 5mm #4"));
    Serial.println(F("(7) LED - Basic Blue 5mm #5"));
    Serial.println(F("(8) LED - Basic Blue 5mm #6"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {
            if(c == '1') 
    			Serial.println(F("Now Testing L298N Motor Driver Board Module"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Ultrasonic Sensor - HC-SR04"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm #1"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm #2"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm #3"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm #4"));
    		else if(c == '7') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm #5"));
    		else if(c == '8') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm #6"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
            }
        }
    }


