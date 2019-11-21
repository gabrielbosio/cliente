#ifndef ACCION_LLAMAR_MOZO_H
#define ACCION_LLAMAR_MOZO_H

#include "AccionSwitch.h"

class AccionLlamarMozo: public AccionSwitch {
    public:
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
};

#endif