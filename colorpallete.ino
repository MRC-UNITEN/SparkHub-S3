#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 650

CRGB leds[NUM_LEDS];

// We choose a palette - think of this as a "Color Theme"
CRGBPalette16 currentPalette = ForestColors_p;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; // This makes the colors "scroll"

  for(int i = 0; i < NUM_LEDS; i++) {
    // ColorFromPalette(palette, index, brightness, blending)
    leds[i] = ColorFromPalette(currentPalette, startIndex + (i * 10), 255, LINEARBLEND);
  }
  
  FastLED.show();
  delay(20);
}