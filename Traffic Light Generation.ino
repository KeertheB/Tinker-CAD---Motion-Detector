#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 12

Adafruit_NeoPixel strip(12, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // GREEN light (LEDs 0–3)
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
  }
  strip.show();
  delay(5000);
  // YELLOW light (LEDs 4–7)
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 0));
  }
  strip.show();
  delay(2000);

  // RED light (LEDs 8–11)
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
  }
  strip.show();
  delay(5000);

  // Turn off all LEDs
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(1000);
}