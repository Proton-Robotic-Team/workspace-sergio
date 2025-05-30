#ifndef PINAGEM_H
#define PINAGEM_H

const uint8_t PIN_LED_ESP32 = 2;

const uint8_t PIN_D1 = 36;  // Antes 34
const uint8_t PIN_D2 = 39;  // Antes 35
const uint8_t PIN_D3 = 34;  // Antes 32
const uint8_t PIN_D4 = 35;  // Antes 33
const uint8_t PIN_D5 = 32;  // Antes 25
const uint8_t PIN_D6 = 33;  // Antes 26
const uint8_t PIN_D7 = 25;  // Antes 27
const uint8_t PIN_D8 = 26;  // Antes 13

const uint8_t PIN_ENA_L298N = 27;  // Antes 23
const uint8_t PIN_ENB_L298N = 13;  // Antes 22
const uint8_t PIN_IN1_L298N = 18;  // Antes 21
const uint8_t PIN_IN2_L298N = 17;  // Antes 19
const uint8_t PIN_IN3_L298N = 16;  // Antes 18
const uint8_t PIN_IN4_L298N = 4;   // Antes 4

inline void configurarPinos() {
  pinMode(PIN_LED_ESP32, OUTPUT);
  pinMode(PIN_ENA_L298N, OUTPUT);
  pinMode(PIN_IN1_L298N, OUTPUT);
  pinMode(PIN_IN2_L298N, OUTPUT);
  pinMode(PIN_IN3_L298N, OUTPUT);
  pinMode(PIN_IN4_L298N, OUTPUT);
  pinMode(PIN_ENB_L298N, OUTPUT)
}

#endif
