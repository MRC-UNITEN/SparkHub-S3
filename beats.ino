#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 200 // We set max brightness high to see the pulse

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // beatsin8(BeatsPerMinute, LowestValue, HighestValue)
  // This creates a number that swings between 10 and 255
  uint8_t pulse = beatsin8(30, 10, 255); 
  
  // Apply that "pulse" number to the brightness
  FastLED.setBrightness(pulse);
  
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
}