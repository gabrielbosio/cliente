#include <Arduino.h>
#include "DisplayHelper.h"
#include "AccionMostrarId.h"

AccionMostrarId::AccionMostrarId(int id, DisplayHelper *display) :
  id(id), display(display) {}

void AccionMostrarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
  if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
    display->display_number(id);
  }
}