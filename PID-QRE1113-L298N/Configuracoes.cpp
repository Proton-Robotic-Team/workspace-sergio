#include <Arduino.h>
#include <Preferences.h>
#include "Configuracoes.h"
#include "Pinagem.h"

Preferences preferences;

bool pararCarro = false;
bool modoDeConfiguracao = false;

long inicioDoPercurso = 0L;
long tempoTotalDePercurso = 0L;
bool tempoDePercursoContabilizado = false;

uint8_t DUTY_CYCLE_MIN;
uint8_t DUTY_CYCLE_MED;
uint8_t DUTY_CYCLE_MAX;

float KP;
float KI;
float KD;

short menuAtual = 1;

void configuracoesSalvas() {
  preferences.begin("configuracao", false);
  KP = preferences.getFloat("kp", 0.02);
  KI = preferences.getFloat("ki", 0.000);
  KD = preferences.getFloat("kd", 0.1);
  DUTY_CYCLE_MIN = preferences.getInt("dc_min", 190);
  DUTY_CYCLE_MED = preferences.getInt("dc_med", 220);
  DUTY_CYCLE_MAX = preferences.getInt("dc_max", 255);
}

void salvarConfiguracoes() {
  preferences.putFloat("kp", KP);
  preferences.putFloat("ki", KI);
  preferences.putFloat("kd", KD);
  preferences.putInt("dc_min", DUTY_CYCLE_MIN);
  preferences.putInt("dc_med", DUTY_CYCLE_MED);
  preferences.putInt("dc_max", DUTY_CYCLE_MAX);
}
