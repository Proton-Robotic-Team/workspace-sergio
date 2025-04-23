#include <Arduino.h>
#include "Sensores.h"

short valorD1 = 0;
short valorD2 = 0;
short valorD3 = 0;
short valorD4 = 0;
short valorD5 = 0;
short valorD6 = 0;
short valorD7 = 0;
short valorD8 = 0;

void lerSensores() {
  valorD1 = analogRead(PIN_D1);
  valorD2 = analogRead(PIN_D2);
  valorD3 = analogRead(PIN_D3);
  valorD4 = analogRead(PIN_D4);
  valorD5 = analogRead(PIN_D5);
  valorD6 = analogRead(PIN_D6);
  valorD7 = analogRead(PIN_D7);
  valorD8 = analogRead(PIN_D8);
}

void printarValorDosSensores(bool debugAtivo) {
  if (debugAtivo) {
    Serial.println("Valor do sensor D1: " + String(valorD1));
    Serial.println("Valor do sensor D2: " + String(valorD2));
    Serial.println("Valor do sensor D3: " + String(valorD3));
    Serial.println("Valor do sensor D4: " + String(valorD4));
    Serial.println("Valor do sensor D5: " + String(valorD5));
    Serial.println("Valor do sensor D6: " + String(valorD6));
    Serial.println("Valor do sensor D7: " + String(valorD7));
    Serial.println("Valor do sensor D8: " + String(valorD8));
    Serial.println();
  }
}
