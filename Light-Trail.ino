#include <Adafruit_NeoPixel.h>

#define LED_PIN 6      // Define the pin where the data line is connected
#define NUM_LEDS 120   // Total number of LEDs per line

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip1.show();  // Initialize all pixels to 'off'

  strip2.begin();
  strip2.show();  // Initialize all pixels to 'off'
}

void loop() {
  // Move a red light from left to right on strip1
  for (int i = 0; i < NUM_LEDS; i++) {
    strip1.setPixelColor(i, strip1.Color(255, 0, 0));
    strip1.show();
    delay(50);
    strip1.setPixelColor(i, strip1.Color(64, 0, 0)); // Trail at 25% brightness
    if (i > 2) {
      strip1.setPixelColor(i - 3, strip1.Color(0, 0, 0)); // Remove trailing light
    }
  }

  // Move a blue light from right to left on strip2
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    strip2.setPixelColor(i, strip2.Color(0, 0, 255));
    strip2.show();
    delay(50);
    strip2.setPixelColor(i, strip2.Color(0, 0, 64)); // Trail at 25% brightness
    if (i < NUM_LEDS - 2) {
      strip2.setPixelColor(i + 3, strip2.Color(0, 0, 0)); // Remove trailing light
    }
  }
}
