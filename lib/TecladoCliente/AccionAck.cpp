#include <Arduino.h>
#include "AccionAck.h"

AccionAck::AccionAck(ControladorAlertas *controladorAlertas, Mensajero *mensajero,
                     MatrizLeds *matrizLeds) : controladorAlertas(controladorAlertas), mensajero(mensajero), matrizLeds(matrizLeds) {}

void AccionAck::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch)
{
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW)
    {
        Serial.println("ACK");
        mensajero->notificarAck();
        matrizLeds->apagar();
        controladorAlertas->apagar();
    }
}