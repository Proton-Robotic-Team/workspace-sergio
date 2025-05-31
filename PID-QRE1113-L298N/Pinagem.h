#ifndef PINAGEM_H
#define PINAGEM_H

const uint8_t PIN_LED_ESP32 = 2;

const uint8_t PIN_D1 = 36;
const uint8_t PIN_D2 = 39;
const uint8_t PIN_D3 = 34;
const uint8_t PIN_D4 = 35;
const uint8_t PIN_D5 = 32;
const uint8_t PIN_D6 = 33;
const uint8_t PIN_D7 = 25;
const uint8_t PIN_D8 = 26;

const uint8_t PIN_ENA_L298N = 27;
const uint8_t PIN_ENB_L298N = 13;
const uint8_t PIN_IN1_L298N = 18;
const uint8_t PIN_IN2_L298N = 17;
const uint8_t PIN_IN3_L298N = 16;
const uint8_t PIN_IN4_L298N = 4;

const uint8_t PIN_CONFIG_MODE = 23;
const uint8_t PIN_MENU_DIREITA = 14;
const uint8_t PIN_MENU_ESQUERDA = 15;
const uint8_t PIN_MENU_INCREMENTO = 5;
const uint8_t PIN_MENU_DECREMENTO = 3;

inline void configurarPinosModoNormal() {
  pinMode(PIN_LED_ESP32, OUTPUT);
  pinMode(PIN_ENA_L298N, OUTPUT);
  pinMode(PIN_IN1_L298N, OUTPUT);
  pinMode(PIN_IN2_L298N, OUTPUT);
  pinMode(PIN_IN3_L298N, OUTPUT);
  pinMode(PIN_IN4_L298N, OUTPUT);
  pinMode(PIN_ENB_L298N, OUTPUT);
}

inline void configurarPinosModoConfig() {
  pinMode(PIN_MENU_DIREITA, INPUT_PULLUP);
  pinMode(PIN_MENU_ESQUERDA, INPUT_PULLUP);
  pinMode(PIN_MENU_INCREMENTO, INPUT_PULLUP);
  pinMode(PIN_MENU_DECREMENTO, INPUT_PULLUP);
}

#endif
