#include <Arduino.h>
#include "Motores.h"
#include "Pinagem.h"

void controleMotores(uint8_t codigoDeDirecao, uint8_t velocidadeDireita, uint8_t velocidadeEsquerda) {
  if (codigoDeDirecao == 1) {
    // Para frente
    digitalWrite(PIN_IN1_L298N, HIGH);
    digitalWrite(PIN_IN2_L298N, LOW);
    digitalWrite(PIN_IN3_L298N, LOW);
    digitalWrite(PIN_IN4_L298N, HIGH);
  } else if (codigoDeDirecao == 2) {
    // Para trás
    digitalWrite(PIN_IN1_L298N, LOW);
    digitalWrite(PIN_IN2_L298N, HIGH);
    digitalWrite(PIN_IN3_L298N, HIGH);
    digitalWrite(PIN_IN4_L298N, LOW);
  } else if (codigoDeDirecao == 3) {
    // Para a direita
    digitalWrite(PIN_IN1_L298N, HIGH);
    digitalWrite(PIN_IN2_L298N, LOW);
    digitalWrite(PIN_IN3_L298N, HIGH);
    digitalWrite(PIN_IN4_L298N, LOW);
  } else if (codigoDeDirecao == 4) {
    // Para a esquerda
    digitalWrite(PIN_IN1_L298N, LOW);
    digitalWrite(PIN_IN2_L298N, HIGH);
    digitalWrite(PIN_IN3_L298N, LOW);
    digitalWrite(PIN_IN4_L298N, HIGH);
  } else {
    // Parado
    digitalWrite(PIN_IN1_L298N, LOW);
    digitalWrite(PIN_IN2_L298N, LOW);
    digitalWrite(PIN_IN3_L298N, LOW);
    digitalWrite(PIN_IN4_L298N, LOW);
  }

  ledcWrite(PIN_ENA_L298N, velocidadeEsquerda);
  ledcWrite(PIN_ENB_L298N, velocidadeDireita);
}
