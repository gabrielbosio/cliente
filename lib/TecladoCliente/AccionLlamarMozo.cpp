#include <Arduino.h>
#include "AccionLlamarMozo.h"

AccionLlamarMozo::AccionLlamarMozo(Mensajero *mensajero) : mensajero(mensajero) {}

void AccionLlamarMozo::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch)
{
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW)
    {
        Serial.println("MOZO");
        mensajero->notificarPedidoMozo();
    }
}