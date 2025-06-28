#include <Arduino.h>
#include "Motores.h"

short valorPWM = 255;

void setup() {
  Serial.begin(115200);
  configMotores();
}

void loop() {
  controleMotores(1, valorPWM, valorPWM);
  printarRPM();
}
