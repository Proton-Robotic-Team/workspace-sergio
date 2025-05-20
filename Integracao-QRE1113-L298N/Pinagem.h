#ifndef PINAGEM_H
#define PINAGEM_H

// const uint8_t PIN_IR = ?;
const uint8_t PIN_LED_ESP32 = 2;

const uint8_t PIN_D1 = 34;
const uint8_t PIN_D2 = 35;
const uint8_t PIN_D3 = 32;
const uint8_t PIN_D4 = 33;
const uint8_t PIN_D5 = 25;
const uint8_t PIN_D6 = 26;
const uint8_t PIN_D7 = 27;
const uint8_t PIN_D8 = 13;

const uint8_t PIN_ENA_L298N = 23;
const uint8_t PIN_ENB_L298N = 22;
const uint8_t PIN_IN1_L298N = 21;
const uint8_t PIN_IN2_L298N = 19;
const uint8_t PIN_IN3_L298N = 18;
const uint8_t PIN_IN4_L298N = 4;

inline void configurarPinos() {
  pinMode(PIN_LED_ESP32, OUTPUT);
  pinMode(PIN_ENA_L298N, OUTPUT);
  pinMode(PIN_IN1_L298N, OUTPUT);
  pinMode(PIN_IN2_L298N, OUTPUT);
  pinMode(PIN_IN3_L298N, OUTPUT);
  pinMode(PIN_IN4_L298N, OUTPUT);
  pinMode(PIN_ENB_L298N, OUTPUT);
}

#endif
