#include <SparkFunLSM6DS3.h>
#include <Arduino.h>
#include "LSM6DS3.h"

// Dependência: https://github.com/sparkfun/SparkFun_LSM6DS3_Arduino_Library

LSM6DS3 myIMU(I2C_MODE, 0x6B);
bool sensorInicializado = false;

void inicializarLSM6DS3() {
  Serial.println("Inicializando LSM6DS3...");

  if (myIMU.begin() != 0) {
    Serial.println("ERRO: Sensor não encontrado! Verifique as conexões.");
    Serial.println("VCC = 3.3V");
    Serial.println("GND = GND");
    Serial.println("SDA = Valor definido em SDA_PIN");
    Serial.println("SCL = Valor definido em SCL_PIN");
    Serial.println("O endereço I2C pode ser 0x6A ou 0x6B, tente trocar também.");
    sensorInicializado = false;
  } else {
    Serial.println("LSM6DS3 inicializado com sucesso!");
    sensorInicializado = true;
  }
}

void lerSensorLSM6DS3() {
  // Só tenta ler se o sensor foi inicializado corretamente
  if (!sensorInicializado) {
    return;
  }

  // A leitura dos eixos do acelerômetro é feita em mg (mili-g) e a do giroscópio em mdps (miligraus por segundo).
  float acelX = myIMU.readFloatAccelX();
  float acelY = myIMU.readFloatAccelY();
  float acelZ = myIMU.readFloatAccelZ();

  float giroX = myIMU.readFloatGyroX();
  float giroY = myIMU.readFloatGyroY();
  float giroZ = myIMU.readFloatGyroZ();

  Serial.printf("Acelerômetro (mg): Eixo X: %.2f, Eixo Y: %.2f, Eixo Z: %.2f\n", acelX, acelY, acelZ);
  Serial.printf("Giroscópio (mdps): Eixo X: %.2f, Eixo Y: %.2f, Eixo Z: %.2f\n", giroX, giroY, giroZ);
  Serial.println();
}