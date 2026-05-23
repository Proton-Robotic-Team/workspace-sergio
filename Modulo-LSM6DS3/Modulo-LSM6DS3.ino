#include <Wire.h>
#include <SparkFunLSM6DS3.h>

// Dependência: https://github.com/sparkfun/SparkFun_LSM6DS3_Arduino_Library

const uint8_t SDA_PIN = 4;
const uint8_t SCL_PIN = 5;

LSM6DS3 myIMU(I2C_MODE, 0x6B);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.setPins(SDA_PIN, SCL_PIN);
  Wire.begin();

  if (myIMU.begin() != 0) {
    Serial.println("ERRO: Sensor não encontrado! Verifique as conexões.");
    Serial.println("VCC = 3.3V");
    Serial.println("GND = GND");
    Serial.println("SDA = Valor definido em SDA_PIN");
    Serial.println("SCL = Valor definido em SCL_PIN");
    Serial.println("O endereço I2C pode ser 0x6A ou 0x6B, tente trocar também.");
    while (1)
      ;
  }
  delay(100);
}

void loop() {
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

  delay(200);
}
