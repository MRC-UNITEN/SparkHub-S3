#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 100 

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  FastLED.clear();
  
  // We only loop through HALF the strip (0 to 4)
  for(int i = 0; i < NUM_LEDS / 2; i++) {
    CRGB color = CHSV(i * 50, 255, 255);
    
    leds[i] = color;                   // Set the "real" LED
    leds[(NUM_LEDS - 1) - i] = color;  // Set the "mirror" LED on the other side
    
    FastLED.show();
    delay(200);
  }
}