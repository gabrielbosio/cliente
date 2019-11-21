#ifndef ACCION_TIEMPO_ESPERA_H
#define ACCION_TIEMPO_ESPERA_H

#include "AccionSwitch.h"
#include "Display.h"

class AccionTiempoEspera: public AccionSwitch {
    public:
        AccionTiempoEspera(Display* display);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        Display* display;
};

#endif