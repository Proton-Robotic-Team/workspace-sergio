#include <Arduino.h>
#include "PID.h"
#include "Motores.h"
#include "QRE1113.h"
#include "Configuracoes.h"

int erroAnterior = 0;
int integral = 0;

int calcularPID() {

  uint16_t posicaoAtual = posicaoFaixaBranca();

  int centroDoSensor = 3500;

  int erro = posicaoAtual - centroDoSensor;

  int P = erro * KP;

  integral += erro;
  int I = KI * integral;

  int D = KD * (erro - erroAnterior);
  erroAnterior = erro;

  int saidaPID = P + I + D;

  saidaPID = constrain(saidaPID, -255, 255);

  return saidaPID;
}

void seguirLinha() {
  int correcao = calcularPID();

  correcao = constrain(correcao, -150, 150);

  int velocidadeBase = DUTY_CYCLE_MED;
  int velocidadeDireita = velocidadeBase - correcao;
  int velocidadeEsquerda = velocidadeBase + correcao;

  velocidadeDireita = constrain(velocidadeDireita, DUTY_CYCLE_MIN, DUTY_CYCLE_MAX);
  velocidadeEsquerda = constrain(velocidadeEsquerda, DUTY_CYCLE_MIN, DUTY_CYCLE_MAX);

  controleMotores(1, velocidadeDireita, velocidadeEsquerda);

  if (DEBUG_ATIVADO) {
    Serial.print("PID: ");
    Serial.print(correcao);
    Serial.print(" | PWM da Direita: ");
    Serial.print(velocidadeDireita);
    Serial.print(" | PWM da Esquerda: ");
    Serial.println(velocidadeEsquerda);
  }
}
