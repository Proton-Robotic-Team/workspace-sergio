#include "Pinagem.h"
#include "QRE1113.h"
#include "Motores.h"
#include "Configuracoes.h"
#include "PID.h"
#include "Display.h"
#include "Menus.h"

void setup() {

  pinMode(PIN_CONFIG_MODE, INPUT_PULLUP);
  modoDeConfiguracao = digitalRead(PIN_CONFIG_MODE) == LOW;
  configuracoesSalvas();
  iniciarDisplay();

  if (modoDeConfiguracao) {
    configurarPinosModoConfig();
  } else {
    Serial.begin(115200);
    configurarPinosModoNormal();
    display("Calibrando");
    configurarModuloQRE();
    display("Iniciando");
    delayAntesDoStart();
    limparDisplay();
  }
}

void loop() {

  if (modoDeConfiguracao) {
    menuConfigurarCarro();
  } else {
    //valorSensoresQRE();
    seguirLinha();
    menuTempoDePercurso();
  }

  delay(DELAY_LOOP_MS);
}
