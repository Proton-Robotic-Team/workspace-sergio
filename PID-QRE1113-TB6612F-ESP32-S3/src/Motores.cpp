#include <Arduino.h>
#include "Motores.h"

// Motor da esquerda
const uint8_t PIN_DRV_PWMA = 11;
const uint8_t PIN_DRV_AIN1 = 13;
const uint8_t PIN_DRV_AIN2 = 14;

// Motor da direita
const uint8_t PIN_DRV_PWMB = 12;
const uint8_t PIN_DRV_BIN1 = 15;
const uint8_t PIN_DRV_BIN2 = 16;

const uint8_t PIN_DRV_STBY = 17;

const uint8_t PIN_ENCODER_C1 = 4;
const uint8_t PIN_ENCODER_C2 = 5;

const uint16_t FREQUENCIA_HZ = 20000;
const uint8_t RESOLUCAO = 8;

long valorEncoder = 0;
unsigned long ultimoTempo = 0;
const double PULSOS_POR_VOLTA = 200.0;

void atualizarValorEncoder() {
  if (digitalRead(PIN_ENCODER_C1) > digitalRead(PIN_ENCODER_C2)) {
    valorEncoder++;
  } else {
    valorEncoder--;
  }
}

double valorRPM() {
  unsigned long tempoAtual = millis();
  unsigned long deltaTempo = tempoAtual - ultimoTempo;

  if (deltaTempo == 0) return 0.0;

  double rotacoes = abs(valorEncoder) / PULSOS_POR_VOLTA;
  double minutos = deltaTempo / 60000.0;
  double rpm = rotacoes / minutos;

  valorEncoder = 0;
  ultimoTempo = tempoAtual;

  return rpm;
}

void configMotores() {
  pinMode(PIN_DRV_PWMA, OUTPUT);
  pinMode(PIN_DRV_PWMB, OUTPUT);
  pinMode(PIN_DRV_AIN1, OUTPUT);
  pinMode(PIN_DRV_AIN2, OUTPUT);
  pinMode(PIN_DRV_BIN1, OUTPUT);
  pinMode(PIN_DRV_BIN2, OUTPUT);
  pinMode(PIN_DRV_STBY, OUTPUT);

  ledcAttach(PIN_DRV_PWMA, FREQUENCIA_HZ, RESOLUCAO);
  ledcAttach(PIN_DRV_PWMB, FREQUENCIA_HZ, RESOLUCAO);

  pinMode(PIN_ENCODER_C1, INPUT);
  pinMode(PIN_ENCODER_C2, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_C1), atualizarValorEncoder, RISING);
}

void controleMotores(uint8_t codigoDeDirecao, uint8_t velocidadeDireita, uint8_t velocidadeEsquerda) {

  digitalWrite(PIN_DRV_STBY, HIGH);

  if (codigoDeDirecao == 1) {
    // Para frente
    digitalWrite(PIN_DRV_AIN1, HIGH);
    digitalWrite(PIN_DRV_AIN2, LOW);
    digitalWrite(PIN_DRV_BIN1, HIGH);
    digitalWrite(PIN_DRV_BIN2, LOW);
  } else if (codigoDeDirecao == 2) {
    // Para trás
    digitalWrite(PIN_DRV_AIN1, LOW);
    digitalWrite(PIN_DRV_AIN2, HIGH);
    digitalWrite(PIN_DRV_BIN1, LOW);
    digitalWrite(PIN_DRV_BIN2, HIGH);
  } else if (codigoDeDirecao == 3) {
    // Para a direita
    digitalWrite(PIN_DRV_AIN1, HIGH);
    digitalWrite(PIN_DRV_AIN2, LOW);
    digitalWrite(PIN_DRV_BIN1, LOW);
    digitalWrite(PIN_DRV_BIN2, HIGH);
  } else if (codigoDeDirecao == 4) {
    // Para a esquerda
    digitalWrite(PIN_DRV_AIN1, LOW);
    digitalWrite(PIN_DRV_AIN2, HIGH);
    digitalWrite(PIN_DRV_BIN1, HIGH);
    digitalWrite(PIN_DRV_BIN2, LOW);
  } else {
    // Parado
    digitalWrite(PIN_DRV_AIN1, HIGH);
    digitalWrite(PIN_DRV_BIN1, HIGH);
    digitalWrite(PIN_DRV_AIN2, HIGH);
    digitalWrite(PIN_DRV_BIN2, HIGH);
  }

  ledcWrite(PIN_DRV_PWMA, velocidadeEsquerda);
  ledcWrite(PIN_DRV_PWMB, velocidadeDireita);
}
