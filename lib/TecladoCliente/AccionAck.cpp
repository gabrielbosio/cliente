#include <Arduino.h>
#include "AccionAck.h"

AccionAck::AccionAck(Mensajero* mensajero) : mensajero(mensajero) {}

void AccionAck::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        mensajero->notificarAck();
    }
}