#include <Arduino.h>
#include "AccionTestear.h"

AccionTestear::AccionTestear(TecladoCliente *tecladoCliente) : tecladoCliente(tecladoCliente){}

void AccionTestear::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        tecladoCliente->configurar(NADA, NADA, NADA, NADA);
        Serial.println("Comienza test.");
        digitalWrite(2, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        delay(1000);
        Serial.println("Finaliza test.");
        tecladoCliente->reiniciar();
    }
}