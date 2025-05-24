#include "QRE1113.h"
#include "Pinagem.h"
#include "Motores.h"

void setup() {
  Serial.begin(115200);
  configurarPinos();
  configurarModuloQRE();
}

void loop() {
  mostrarValorSensoresQRE();

  /*
  short codigoDeDirecao = 3;
  short porcentagemVelocidade = 100;
  direcao(codigoDeDirecao);
  controleDeVelocidade(codigoDeDirecao, porcentagemVelocidade);
  */
}
