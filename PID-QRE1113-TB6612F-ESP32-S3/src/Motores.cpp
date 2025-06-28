#include <Arduino.h>
#include "Motores.h"

// Motor da esquerda
const uint8_t PIN_DRV_PWMA = 11;
const uint8_t PIN_DRV_AIN1 = 13;
const uint8_t PIN_DRV_AIN2 = 14;
const uint8_t PIN_ENCODER_C1_E = 39;
const uint8_t PIN_ENCODER_C2_E = 40;

// Motor da direita
const uint8_t PIN_DRV_PWMB = 12;
const uint8_t PIN_DRV_BIN1 = 15;
const uint8_t PIN_DRV_BIN2 = 16;
const uint8_t PIN_ENCODER_C1_D = 6;
const uint8_t PIN_ENCODER_C2_D = 7;

const uint8_t PIN_DRV_STBY = 17;

const uint16_t FREQUENCIA_HZ = 20000;
const uint8_t RESOLUCAO = 8;

long valorEncoderMotorDireito = 0;
long valorEncoderMotorEsquerdo = 0;
double rpmMotorDireito = 0.0;
double rpmMotorEsquerdo = 0.0;
unsigned long ultimoTempo = 0;
const double PULSOS_POR_VOLTA = 200.0;

void atualizarEncoderMotorDireito() {
  if (digitalRead(PIN_ENCODER_C1_D) > digitalRead(PIN_ENCODER_C2_D)) {
    valorEncoderMotorDireito++;
  } else {
    valorEncoderMotorDireito--;
  }
}

void atualizarEncoderMotorEsquerdo() {
  if (digitalRead(PIN_ENCODER_C1_E) > digitalRead(PIN_ENCODER_C2_E)) {
    valorEncoderMotorEsquerdo++;
  } else {
    valorEncoderMotorEsquerdo--;
  }
}

void calcularRPM() {
  unsigned long tempoAtual = millis();
  unsigned long deltaTempo = tempoAtual - ultimoTempo;
  double minutos = deltaTempo / 60000.0;

  if (deltaTempo == 0) {
    rpmMotorDireito = 0.0;
    rpmMotorEsquerdo = 0.0;
  }

  double rotacoesDireita = abs(valorEncoderMotorDireito) / PULSOS_POR_VOLTA;
  double rotacoesEsquerda = abs(valorEncoderMotorEsquerdo) / PULSOS_POR_VOLTA;

  double rpmDireita = rotacoesDireita / minutos;
  double rpmEsquerda = rotacoesEsquerda / minutos;

  valorEncoderMotorDireito = 0;
  valorEncoderMotorEsquerdo = 0;

  ultimoTempo = tempoAtual;

  rpmMotorDireito = rpmDireita;
  rpmMotorEsquerdo = rpmEsquerda;
}

void printarRPM() {

  short INTERVALO_DE_EXIBICAO_MS = 200;

  static unsigned long ultimoPrint = 0;

  if (millis() - ultimoPrint >= INTERVALO_DE_EXIBICAO_MS) {
    calcularRPM();
    Serial.print("RPM Motor Direito: ");
    Serial.print(rpmMotorDireito);
    Serial.print(" | RPM Motor Esuerdo: ");
    Serial.println(rpmMotorEsquerdo);
    ultimoPrint = millis();
  }
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

  pinMode(PIN_ENCODER_C1_D, INPUT);
  pinMode(PIN_ENCODER_C2_D, INPUT);
  pinMode(PIN_ENCODER_C1_E, INPUT);
  pinMode(PIN_ENCODER_C2_E, INPUT);

  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_C1_D), atualizarEncoderMotorDireito, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_C1_E), atualizarEncoderMotorEsquerdo, RISING);
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
