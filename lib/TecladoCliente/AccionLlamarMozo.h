#ifndef ACCION_LLAMAR_MOZO_H
#define ACCION_LLAMAR_MOZO_H

#include "AccionSwitch.h"
#include "Mensajero.h"

class AccionLlamarMozo: public AccionSwitch {
    public:
        AccionLlamarMozo(Mensajero* mensajero);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        Mensajero* mensajero;
};

#endif