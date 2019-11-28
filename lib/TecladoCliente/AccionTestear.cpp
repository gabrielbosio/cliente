#include <Arduino.h>
#include "AccionTestear.h"

AccionTestear::AccionTestear(TecladoCliente *tecladoCliente,
                             ManejadorFlash *manejadorFlash,
                             Mensajero *mensajero,
                             bool *comienzaTest) : tecladoCliente(tecladoCliente),
                                                   manejadorFlash(manejadorFlash),
                                                   mensajero(mensajero),
                                                   comienzaTest(comienzaTest) {}

void AccionTestear::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch)
{
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW)
    {
        *comienzaTest = true;
        manejadorFlash->reiniciarConfiguracion();
        mensajero->asignarId(0);
        tecladoCliente->configurar(NADA, NADA, NADA, NADA);
    }
}