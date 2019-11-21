#ifndef ACCION_MOSTRAR_ID_H
#define ACCION_MOSTRAR_ID_H

#include "Display.h"
#include "AccionSwitch.h"

class AccionMostrarId: public AccionSwitch {
    public:
        AccionMostrarId(int id, Display* display);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        int id;
        Display* display;
};

#endif