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

float KP;
float KI;
float KD;

short menuAtual = 1;

void configuracoesSalvas() {
  preferences.begin("configuracao", false);
  KP = preferences.getFloat("kp", 0.02);
  KI = preferences.getFloat("ki", 0.000);
  KD = preferences.getFloat("kd", 0.1);
}

void salvarConfiguracoes() {
  preferences.putFloat("kp", KP);
  preferences.putFloat("ki", KI);
  preferences.putFloat("kd", KD);
}
