#include <Arduino.h>
#include "AccionAck.h"

void AccionAck::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        Serial.println("ACK");
    }
}