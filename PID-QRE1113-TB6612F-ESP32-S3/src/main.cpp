#include <Arduino.h>
#include "Motores.h"
#include "TesteDisplay.h"
#include "ServidorWeb.h"

// Não esqueça de upar os arquivos do servidor web
// 1 - Abra o menu de opções do PlatformIO
// 2 - Platform > Build Filesystem Image
// 3 - Platform > Upload Filesystem Image

short valorPWM = 255;

void setup() {
  Serial.begin(115200);
  configMotores();
  configDisplayTeste();
  configurarServidorWeb();
}

void loop() {
  controleMotores(1, valorPWM, valorPWM);
  // printarRPM();
  servidorAtivo();
}
