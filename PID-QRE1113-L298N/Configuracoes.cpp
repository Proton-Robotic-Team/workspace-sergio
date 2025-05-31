#include <Arduino.h>
#include "Configuracoes.h"
#include "Pinagem.h"

bool pararCarro = false;
bool modoDeConfiguracao = false;

long inicioDoPercurso = 0L;
long tempoTotalDePercurso = 0L;
bool tempoDePercursoContabilizado = false;

float KP = 0.02;
float KI = 0.000;
float KD = 0.1;

short menuAtual = 1;
