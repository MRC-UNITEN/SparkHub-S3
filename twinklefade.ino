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
  // 1. Fade everything slightly every frame (creates a "tail" effect)
  fadeToBlackBy(leds, NUM_LEDS, 20); //fadeToBlackBy(<led array>, <no_of_leds>, <reducing effect>)

  // 2. Pick a random LED and turn it white
  if(random8() < 50) { // Only do this about 20% of the time
    int i = random8(NUM_LEDS);
    leds[i] = CRGB::White;
  }

  FastLED.show();
  delay(50);
}