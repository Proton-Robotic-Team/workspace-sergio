#include "QRE1113.h"
#include "Pinagem.h"
#include "Motores.h"

void setup() {
  configurarPinos();
  configurarModuloQRE();
}

void loop() {
  mostrarValorSensoresQRE();

  // Testes iniciais dos motores
  /*
  short codigoDeDirecao = 1;
  short porcentagemVelocidade = 100;
  direcao(codigoDeDirecao);
  controleDeVelocidade(codigoDeDirecao, porcentagemVelocidade);
  */
}
