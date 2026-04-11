#include <FastLED.h> // Importing our FastLED "dictionary"

// 1. Defining our variables and hardware setup
#define NUM_LEDS 10      // We have 10 LEDs on our strip
#define DATA_PIN 8       // The Arduino pin sending instructions to the LEDs
#define MAX_VOLTS 5      // 5 Volts is standard for USB
#define MAX_AMPS 500     // 500 milliamps is a safe limit for a laptop USB port
#define BRIGHTNESS 50    // Set your global brightness (0-255)

// 2. Creating the LED array (our street of houses)
CRGB leds[NUM_LEDS]; 

void setup() {
  // 3. Telling FastLED what kind of strip we have and where it is
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  // 4. Setting our safety limits
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // 5. Turn the very first LED Red
  leds[0] = CRGB::Red; 
  
  // 6. Push the data to the strip so we can see it
  FastLED.show(); 
}