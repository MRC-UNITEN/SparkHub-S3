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
  // 1. Every loop, fade all LEDs slightly (e.g., by 64 out of 255)
  // This creates the "tail" or motion blur.
  fadeToBlackBy(leds, NUM_LEDS, 100);

  // 2. Move a single "head" light across the strip
  static int pos = 0;
  leds[pos] = CRGB::Cyan;
  
  pos = (pos + 1) % NUM_LEDS; // Move to next LED, reset to 0 at the end

  FastLED.show();
  delay(100);
}