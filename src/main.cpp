#include <Arduino.h>
#include "LedMatrix.h"

#define CS_PIN 5

LedMatrix *ledMatrix;

void setup()
{
  ledMatrix = new LedMatrix(CS_PIN);
}

void loop()
{
  ledMatrix->apagar();
  delay(1000);
  ledMatrix->encender();
  delay(1000);
}