#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 50

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // The For Loop: Start at 0, go up to 9, stepping by 1 each time
  for(int i = 0; i < NUM_LEDS; i++) {
    
    leds[i] = CRGB::Blue;  // Turn the current LED Blue
    FastLED.show();        // Update the strip
    delay(800);            // Wait a fraction of a second
    leds[i] = CRGB::Black; // Turn the LED off (Black means off in light!)
    // The loop now repeats and moves to the next LED!
  }
}