#include <Arduino.h>
#include "Motores.h"

short valorPWM = 190;

void setup() {
  Serial.begin(115200);
  configMotores();
}

void loop() {

  controleMotores(1, valorPWM, valorPWM);

  // Exibe o RPM a cada 250ms
  static unsigned long ultimoPrint = 0;
  if (millis() - ultimoPrint >= 250) {
    Serial.print("RPM: ");
    Serial.println(valorRPM());
    ultimoPrint = millis();
  }
}
