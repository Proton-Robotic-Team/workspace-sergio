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

  if (botaoDireitaPressionado && menuAtual < 6) {
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
    display("D", valorKD, true, true);
  } else if (menuAtual == 4) {
    char valorDCMIN[4];
    snprintf(valorDCMIN, sizeof(valorDCMIN), "%d", DUTY_CYCLE_MIN);
    display("DC_MIN", valorDCMIN, true, true);
  } else if (menuAtual == 5) {
    char valorDCMED[4];
    snprintf(valorDCMED, sizeof(valorDCMED), "%d", DUTY_CYCLE_MED);
    display("DC_MED", valorDCMED, true, true);
  } else if (menuAtual == 6) {
    char valorDCMAX[4];
    snprintf(valorDCMAX, sizeof(valorDCMAX), "%d", DUTY_CYCLE_MAX);
    display("DC_MAX", valorDCMAX, true, false);
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
  } else if (menuAtual == 4 && botaoIncrementoPressionado && DUTY_CYCLE_MIN < 255) {
    DUTY_CYCLE_MIN += 1;
    ultimaTroca = millis();
  } else if (menuAtual == 5 && botaoIncrementoPressionado && DUTY_CYCLE_MED < 255) {
    DUTY_CYCLE_MED += 1;
    ultimaTroca = millis();
  } else if (menuAtual == 6 && botaoIncrementoPressionado && DUTY_CYCLE_MAX < 255) {
    DUTY_CYCLE_MAX += 1;
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
  } else if (menuAtual == 4 && botaoDecrementoPressionado && DUTY_CYCLE_MIN > 0) {
    DUTY_CYCLE_MIN -= 1;
    ultimaTroca = millis();
  } else if (menuAtual == 5 && botaoDecrementoPressionado && DUTY_CYCLE_MED > 0) {
    DUTY_CYCLE_MED -= 1;
    ultimaTroca = millis();
  } else if (menuAtual == 6 && botaoDecrementoPressionado && DUTY_CYCLE_MAX > 0) {
    DUTY_CYCLE_MAX -= 1;
    ultimaTroca = millis();
  }

  salvarConfiguracoes();
}
