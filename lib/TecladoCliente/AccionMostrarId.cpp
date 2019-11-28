#include <Arduino.h>
#include "AccionMostrarId.h"

AccionMostrarId::AccionMostrarId(Display *display, Mensajero *mensajero) : display(display), mensajero(mensajero) {}

void AccionMostrarId::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch)
{
    if (estadoActualPinSwitch == HIGH && estadoAnteriorPinSwitch == LOW)
    {
        display->asignarNumero(mensajero->id());
        display->asignarEstado(MOSTRANDO_NUMERO);
    }
}