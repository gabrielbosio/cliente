#include <Arduino.h>
#include "AccionConfigId.h"

AccionConfigId::AccionConfigId(TecladoCliente *tecladoCliente) : tecladoCliente(tecladoCliente) {}

void AccionConfigId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
  if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
    Serial.println("Asignando ID...");
    tecladoCliente->configurar(ID, ID, ID, ID);
  }
}