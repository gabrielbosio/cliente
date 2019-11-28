#include <Arduino.h>
#include "AccionTiempoEspera.h"

AccionTiempoEspera::AccionTiempoEspera(Mensajero *mensajero) : mensajero(mensajero) {}

void AccionTiempoEspera::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch)
{
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW)
    {
        mensajero->notificarConsultaEspera();
    }
}