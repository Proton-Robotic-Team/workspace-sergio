#include <Arduino.h>
#include "Motores.h"
#include "TesteDisplay.h"

short valorPWM = 255;

void setup() {
  Serial.begin(115200);
  configMotores();
  configDisplayTeste();
}

void loop() {
  controleMotores(1, valorPWM, valorPWM);
  printarRPM();
}
