#include <Arduino.h>
#include "AccionTiempoEspera.h"

AccionTiempoEspera::AccionTiempoEspera(Display* display) : display(display) {}

void AccionTiempoEspera::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        display->asignarEstado(CARGANDO);
    }
}