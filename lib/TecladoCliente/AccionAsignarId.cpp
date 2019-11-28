#include <Arduino.h>
#include "AccionAsignarId.h"

AccionAsignarId::AccionAsignarId(TecladoCliente *tecladoCliente, ManejadorFlash *manejadorFlash, Mensajero *mensajero, byte id) : tecladoCliente(tecladoCliente), manejadorFlash(manejadorFlash), mensajero(mensajero), id(id) {}

void AccionAsignarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch)
{
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW)
    {
        Serial.print("ID = ");
        Serial.println(id);
        mensajero->asignarId(id);
        mensajero->notificarRegistro();
        manejadorFlash->grabarID(id);
        tecladoCliente->reiniciar();
    }
}