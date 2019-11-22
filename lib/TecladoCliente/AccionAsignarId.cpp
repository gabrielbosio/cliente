#include <Arduino.h>
#include "AccionAsignarId.h"

AccionAsignarId::AccionAsignarId(TecladoCliente* tecladoCliente, Mensajero* mensajero, int id) :
    tecladoCliente(tecladoCliente), mensajero(mensajero), id(id) {}

void AccionAsignarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        Serial.print("ID = ");
        Serial.println(id);
        mensajero->asignarId(id);
        tecladoCliente->reiniciar();
    }
}