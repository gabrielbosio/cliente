#include <Arduino.h>
#include "AccionTestear.h"

AccionTestear::AccionTestear(TecladoCliente* tecladoCliente, bool* comienzaTest) :
    tecladoCliente(tecladoCliente), comienzaTest(comienzaTest) {}

void AccionTestear::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW) {
        *comienzaTest = true;    
        tecladoCliente->configurar(NADA, NADA, NADA, NADA);
    }
}