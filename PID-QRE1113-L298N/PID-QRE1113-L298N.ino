#include "Pinagem.h"
#include "QRE1113.h"
#include "Motores.h"
#include "Configuracoes.h"
#include "PID.h"

void setup() {
  Serial.begin(115200);
  configurarPinos();
  configurarModuloQRE();
}

void loop() {
  // valorSensoresQRE();
  seguirLinha();
  delay(DELAY_LOOP_MS);
}
