#include "Pinagem.h"
#include "QRE1113.h"
#include "Motores.h"
#include "Configuracoes.h"
#include "PID.h"
#include "Display.h"
#include "Menus.h"
#include "ServidorWeb.h"

// Não esqueça de upar os arquivos do servidor web
// 1 - Abra o menu de opções do PlatformIO
// 2 - Platform > Build Filesystem Image
// 3 - Platform > Upload Filesystem Image

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
    configurarServidorWeb();
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
    valorSensoresQRE();
    seguirLinha();
    // menuTempoDePercurso();
    // controleMotores(1, 255, 255);
    // printarRPM();
    servidorAtivo();
  }

  delay(DELAY_LOOP_MS);
}
