#include "Sensores.h"

bool debugAtivo = true;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // O delay foi adicionado apenas para facilitar a visualização dos dados
  // no terminal durante o desenvolvimento.
  delay(100);
  lerSensores();
  printarValorDosSensores(debugAtivo);
}
