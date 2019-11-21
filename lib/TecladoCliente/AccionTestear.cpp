#include <Arduino.h>
#include "AccionTestear.h"

AccionTestear::AccionTestear(TecladoCliente* tecladoCliente, Display* display) :
    tecladoCliente(tecladoCliente), display(display) {}

void AccionTestear::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        /* Si se configura a NADA, se pierde este objeto. Por ahi, conviene crear un Tester
           que no se cree en TecladoCliente y llamarlo de aca. */
        // tecladoCliente->configurar(NADA, NADA, NADA, NADA);
        Serial.println("Comienza test.");
        display->mostrarNumero(88);
        delay(1000);
        // volver display a stand by
        Serial.println("Finaliza test.");
        tecladoCliente->reiniciar();
    }
}