#include <FastLED.h>
#define NUM_LEDS 30
#define DATA_PIN 2
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define BRIGHTNESS 100
#define VOLTS 5
#define MAX_AMPS 500

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
FastLED.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER> (leds, NUM_LEDS);
FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
FastLED.setBrightness(BRIGHTNESS);
FastLED.clear();
FastLED.show();
}
CRGB COLORS[] = {CRGB::Aqua, CRGB::Purple, CRGB::LimeGreen, CRGB::DarkRed, CRGB::OrangeRed, CRGB::HotPink, CRGB::Yellow, CRGB::White};
int COLOR_NUM = 7;
void loop() {
  COLOR_NUM++;
  if (COLOR_NUM >= 8) {
    COLOR_NUM = 0;
  }
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUM_LEDS-1; i++) {
    leds[i] = COLORS[COLOR_NUM];
    FastLED.show();
    delay(50);
  }
  for (int i = 100; i >= 0; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(20);
  }
  delay(500);
  FastLED.clear();
  FastLED.setBrightness(100);
    COLOR_NUM++;
  if (COLOR_NUM >= 8) {
    COLOR_NUM = 0;
  }
  for (int i = NUM_LEDS-1; i > 0; i--) {
    leds[i] = COLORS[COLOR_NUM];
    FastLED.show();
    delay(50);
  }
    for (int i = 100; i >= 0; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(20);
  }
  delay(500);
  FastLED.clear();
  FastLED.setBrightness(100);
}
