#include <Arduino.h>
#include "AccionLlamarMozo.h"

void AccionLlamarMozo::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        Serial.println("MOZO");
    }
}