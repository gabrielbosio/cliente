#include <Arduino.h>
#include "AccionTiempoEspera.h"

void AccionTiempoEspera::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        Serial.println("TIEMPO DE ESPERA");
    }
}