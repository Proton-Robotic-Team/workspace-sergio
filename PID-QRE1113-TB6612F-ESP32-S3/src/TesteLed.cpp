#include <Arduino.h>
#include "TesteLed.h"

#define RGB_PWR 17

void configurarLed() {
  pinMode(RGB_PWR, OUTPUT);
  digitalWrite(RGB_PWR, HIGH);
}

void ledRGB() {
  // Vermelho
  rgbLedWrite(RGB_BUILTIN, 255, 0, 0);
  delay(500);

  // Verde
  rgbLedWrite(RGB_BUILTIN, 0, 255, 0);
  delay(500);

  // Azul
  rgbLedWrite(RGB_BUILTIN, 0, 0, 255);
  delay(500);

  // Amarelo
  rgbLedWrite(RGB_BUILTIN, 255, 255, 0);
  delay(500);

  // Branco
  rgbLedWrite(RGB_BUILTIN, 255, 255, 255);
  delay(500);

  // Desligado
  rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
  delay(500);
}
