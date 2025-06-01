#include <Arduino.h>
#include "Menus.h"
#include "Display.h"
#include "Configuracoes.h"
#include "Pinagem.h"

void menuTempoDePercurso() {
  if (inicioDoPercurso == 0L) {
    inicioDoPercurso = millis();
  }

  if (pararCarro) {
    if (!tempoDePercursoContabilizado) {
      tempoTotalDePercurso = millis() - inicioDoPercurso;
      tempoDePercursoContabilizado = true;
    }
    double tempoTotalDePercursoEmSegundos = tempoTotalDePercurso / 1000.0;
    char tempo[20];
    snprintf(tempo, sizeof(tempo), "%.3fs", tempoTotalDePercursoEmSegundos);
    display("Tempo", tempo, false, false);
  }
}

void menuConfigurarCarro() {

  bool botaoEsquerdaPressionado = (digitalRead(PIN_MENU_ESQUERDA) == LOW);
  bool botaoDireitaPressionado = (digitalRead(PIN_MENU_DIREITA) == LOW);
  bool botaoIncrementoPressionado = (digitalRead(PIN_MENU_INCREMENTO) == LOW);
  bool botaoDecrementoPressionado = (digitalRead(PIN_MENU_DECREMENTO) == LOW);

  static unsigned long ultimaTroca = 0;
  const unsigned long intervaloDebounce = 200;

  if (millis() - ultimaTroca < intervaloDebounce) {
    return;
  }

  if (botaoDireitaPressionado && menuAtual < 3) {
    menuAtual++;
    ultimaTroca = millis();
  } else if (botaoEsquerdaPressionado && menuAtual > 1) {
    menuAtual--;
    ultimaTroca = millis();
  }

  if (menuAtual == 1) {
    char valorKP[6];
    snprintf(valorKP, sizeof(valorKP), "%.3f", KP);
    display("P", valorKP, false, true);
  } else if (menuAtual == 2) {
    char valorKI[6];
    snprintf(valorKI, sizeof(valorKI), "%.3f", KI);
    display("I", valorKI, true, true);
  } else if (menuAtual == 3) {
    char valorKD[6];
    snprintf(valorKD, sizeof(valorKD), "%.3f", KD);
    display("D", valorKD, true, false);
  }

  if (menuAtual == 1 && botaoIncrementoPressionado) {
    KP += 0.01;
    ultimaTroca = millis();
  } else if (menuAtual == 2 && botaoIncrementoPressionado) {
    KI += 0.001;
    ultimaTroca = millis();
  } else if (menuAtual == 3 && botaoIncrementoPressionado) {
    KD += 0.1;
    ultimaTroca = millis();
  }

  if (menuAtual == 1 && botaoDecrementoPressionado && KP > 0.0f) {
    KP -= 0.010f;
    KP = max(KP, 0.0f);
    ultimaTroca = millis();
  } else if (menuAtual == 2 && botaoDecrementoPressionado && KI > 0.0f) {
    KI -= 0.001f;
    KI = max(KI, 0.0f);
    ultimaTroca = millis();
  } else if (menuAtual == 3 && botaoDecrementoPressionado && KD > 0.0f) {
    KD -= 0.100f;
    KD = max(KD, 0.0f);
    ultimaTroca = millis();
  }

  salvarConfiguracoes();
}
