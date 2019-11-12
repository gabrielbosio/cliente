#include <Arduino.h>
#include "AccionMostrarId.h"

AccionMostrarId::AccionMostrarId(int id) : id(id) {}

void AccionMostrarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
  if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
    Serial.print("ID ");
    Serial.println(id);
  }
}