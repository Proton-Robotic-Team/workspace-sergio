#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H

#include <Arduino.h>

// Motores
const uint16_t FREQUENCIA_HZ = 20000;
const uint8_t RESOLUCAO = 8;

// Valores padrão para o PWM
extern uint8_t DUTY_CYCLE_MIN;
extern uint8_t DUTY_CYCLE_MED;
extern uint8_t DUTY_CYCLE_MAX;

// Variáveis do PID
extern float KP;
extern float KI;
extern float KD;

// Para contador de tempo de percurso
extern long inicioDoPercurso;
extern long tempoTotalDePercurso;
extern bool tempoDePercursoContabilizado;

// Outros
const uint8_t DELAY_LOOP_MS = 15;
const bool DEBUG_ATIVADO = false;
extern bool pararCarro;
extern bool modoDeConfiguracao;
extern short menuAtual;

void configuracoesSalvas();
void salvarConfiguracoes();

#endif
