
#include <FastLED.h>

#define NUM_LEDS 6
#define LED_PIN 2

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led, NUM_LEDS);
  for (int i=0; i<NUM_LEDS; i++) {
    led[i]=CRGB(0,0,255);
  }
FastLED.show(); 
}
void setBlue(int val){
  for (int i=0; i<NUM_LEDS;i++){
    led[i]=CRGB(0,0,val);
  }
  
  FastLED.show();
}
void loop() {
for(int i=255; i>0;i--){
  setBlue(i);
  delay(10);
}
for(int i=0;i<256;i++){
  setBlue(i);
  delay(10);
  
}
}
