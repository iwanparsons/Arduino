#include <Adafruit_NeoPixel.h>
#define PIN 5
#define NUMPIXELS 144

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

#define DELAWVAL 10  // Tine (in milliseconds) to pause between pixels
#define BRIGHTNESS 25 
void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(BRIGHTNESS);
}
void loop() {
    pixels.clear(); // Set all pixel colors to "off"
    whiteOverRainbow();
}

void whiteOverRainbow() {
  int loops = 3;
  int loopNum = 0;
  uint32_t lastTime = millis();
  uint32_t firstPixelHue = 0;

  for (;;) {
    for (int i = 0; i < pixels.numPixels(); i++) {
      int pixelHue = firstPixelHue = (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    firstPixelHue + -40;
  }
}
