#include "Pinagem.h"
#include "QRE1113.h"
#include "Motores.h"
#include "Configuracoes.h"
#include "PID.h"
#include "Display.h"

long inicio = 0L;
long tempoDePercurso = 0L;
bool tempoContabilizado = false;

void setup() {
  Serial.begin(115200);
  configurarPinos();
  configurarModuloQRE();
  iniciarDisplay();
}

void loop() {
  valorSensoresQRE();
  seguirLinha();

  if (inicio == 0L) {
    inicio = millis();
  }

  if (pararCarro) {
    if (!tempoContabilizado) {
      tempoDePercurso = millis() - inicio;
      tempoContabilizado = true;
    }
    double numero = tempoDePercurso / 1000.0;
    char valor[20];
    snprintf(valor, sizeof(valor), "%.3fs", numero);
    display("Tempo", valor, false, false);
  }

  delay(DELAY_LOOP_MS);
}
