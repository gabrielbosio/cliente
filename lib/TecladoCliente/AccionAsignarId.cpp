#include <Arduino.h>
#include "AccionAsignarId.h"

AccionAsignarId::AccionAsignarId(TecladoCliente *tecladoCliente, int id) :
    tecladoCliente(tecladoCliente), id(id) {}

void AccionAsignarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        Serial.print("ID = ");
        Serial.println(id);
        tecladoCliente->asignarId(id);
        tecladoCliente->reiniciar();
    }
}