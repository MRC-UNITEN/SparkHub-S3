#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];

// We need a variable to track where our rainbow starts moving
uint8_t startIndex = 0; //unsigned-integer 8bit

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Effect 1: Fill the whole strip green instantly
  fill_solid(leds, NUM_LEDS, CRGB::Green); //fill_solid(<leds_array>, <no_of_leds>, <color>)
  FastLED.show();
  delay(3000);

  // Effect 2: Instantly turn off all LEDs
  FastLED.clear(); //All leds will be off
  FastLED.show();
  delay(500);

  // Effect 3: A moving rainbow! Let's let it run 50 times quickly
  for(int i = 0; i < 100; i++) {
    // leds array, number of leds, starting color, how fast colors change
    fill_rainbow(leds, NUM_LEDS, startIndex, 10); // fill_rainbow(<leds_array>, <no_of_leds>, <start color(0~255)>, <increment on next led color(0~255))
    FastLED.show();
    
    startIndex = startIndex + 5; // Shift the rainbow forward
    delay(80);                   // Speed of the animation
  }

  FastLED.clear(); 
  FastLED.show();
  delay(2000);

  // Effect 4: Static fill rainbow
  fill_rainbow(leds, NUM_LEDS, 0, 25); 
  FastLED.show();
  delay(5000);
}