#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H

#include <Arduino.h>

// Motores
const uint16_t FREQUENCIA_HZ = 20000;
const uint8_t RESOLUCAO = 8;

// Valores padrão para o PWM
const uint8_t DUTY_CYCLE_MIN = 190;  // 180, 180, 200 (valores testados anteriormente)
const uint8_t DUTY_CYCLE_MED = 220;  // 180, 215, 220 (valores testados anteriormente)
const uint8_t DUTY_CYCLE_MAX = 255;  // 230, 255, 255 (valores testados anteriormente)

// Variáveis do PID
const float KP = 0.02;  // 0.02
const float KI = 0.0;   // 0.0
const float KD = 0.1;   //0.1

// Outros
const uint8_t DELAY_LOOP_MS = 15;
const bool DEBUG_ATIVADO = false;
extern bool pararCarro;

#endif
