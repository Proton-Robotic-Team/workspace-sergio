#include "Pinagem.h"
#include "QRE1113.h"
#include "Motores.h"
#include "Configuracoes.h"
#include "PID.h"
#include "Display.h"
#include "Menus.h"

void setup() {
  Serial.begin(115200);

  pinMode(PIN_CONFIG_MODE, INPUT_PULLUP);
  modoDeConfiguracao = digitalRead(PIN_CONFIG_MODE) == LOW;

  if (modoDeConfiguracao) {
    configurarPinosModoConfig();
  } else {
    configurarPinosModoNormal();
    configurarModuloQRE();
  }

  iniciarDisplay();
}

void loop() {

  if (modoDeConfiguracao) {
    menuConfigurarCarro();
  } else {
    valorSensoresQRE();
    seguirLinha();
    menuTempoDePercurso();
  }

  delay(DELAY_LOOP_MS);
}
