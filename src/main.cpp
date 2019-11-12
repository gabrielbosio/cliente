#include "TecladoCliente.h"
#include <Arduino.h>

#define PIN_SWITCH1 15
#define PIN_SWITCH2 4
#define PIN_SWITCH3 18
#define PIN_SWITCH4 19

TecladoCliente *tecladoCliente;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_SWITCH1, INPUT);
  tecladoCliente = new TecladoCliente(PIN_SWITCH1, PIN_SWITCH2, PIN_SWITCH3, PIN_SWITCH4);
}

void loop() {
  tecladoCliente->actualizar();

  delay(100);
}