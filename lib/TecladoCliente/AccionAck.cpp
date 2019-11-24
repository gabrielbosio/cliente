#include <Arduino.h>
#include "AccionAck.h"

AccionAck::AccionAck(Mensajero* mensajero, MatrizLeds* matrizLeds) :
    mensajero(mensajero), matrizLeds(matrizLeds) {}

void AccionAck::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        mensajero->notificarAck();
        matrizLeds->apagar();
    }
}