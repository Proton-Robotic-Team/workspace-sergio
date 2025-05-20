const int PIN_D0_F249 = 4;

volatile unsigned long qtdPulsos = 0;
unsigned long ultimaAmostragem = 0;
volatile float rpm = 0;
const int QTD_FUROS_DISCO_ENCODER = 20;

void IRAM_ATTR pulseInterrupt() {
  qtdPulsos++;
}

void calculaRPM() {
  if (millis() - ultimaAmostragem >= 1000) {
    detachInterrupt(digitalPinToInterrupt(PIN_D0_F249));

    rpm = (float)qtdPulsos / (float)QTD_FUROS_DISCO_ENCODER * 60.0;
    qtdPulsos = 0;
    ultimaAmostragem = millis();

    attachInterrupt(digitalPinToInterrupt(PIN_D0_F249), pulseInterrupt, RISING);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_D0_F249, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_D0_F249), pulseInterrupt, RISING);
}

void loop() {
  calculaRPM();

  Serial.print("Pulsos: ");
  Serial.print(qtdPulsos);
  Serial.print(" | RPM: ");
  Serial.println(rpm);
}
