#include <Arduino.h>
#include "AccionMostrarId.h"

AccionMostrarId::AccionMostrarId(int id, Display* display) : id(id), display(display) {}

void AccionMostrarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        display->asignarNumero(id);
        display->asignarEstado(MOSTRANDO_NUMERO);
    }
}