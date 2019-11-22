#ifndef ACCION_MOSTRAR_ID_H
#define ACCION_MOSTRAR_ID_H

#include "Display.h"
#include "Mensajero.h"
#include "AccionSwitch.h"

class AccionMostrarId: public AccionSwitch {
    public:
        AccionMostrarId(Display* display, Mensajero* mensajero);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        Display* display;
        Mensajero* mensajero;
};

#endif