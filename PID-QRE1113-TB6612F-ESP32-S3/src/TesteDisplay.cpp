#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "TesteDisplay.h"

const uint8_t SDA_PIN = 4;
const uint8_t SCL_PIN = 5;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void configDisplayTeste() {
  Wire.begin(SDA_PIN, SCL_PIN);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Falha no display!");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Display OK!");
  display.display();
}
