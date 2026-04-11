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
  CRGB colorA = CRGB::Red;
  CRGB colorB = CRGB::Blue;

  // We will blend from A to B in 256 tiny steps
  for(int i = 0; i < 256; i++) {
    // blend(color1, color2, amount_of_color2)
    CRGB mixedColor = blend(colorA, colorB, i);
    
    fill_solid(leds, NUM_LEDS, mixedColor);
    FastLED.show();
    delay(10);
  }

  // Then blend back!
  for(int i = 255; i >= 0; i--) {
    CRGB mixedColor = blend(colorA, colorB, i);
    fill_solid(leds, NUM_LEDS, mixedColor);
    FastLED.show();
    delay(10);
  }
}