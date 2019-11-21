#ifndef ACCION_ACK_H
#define ACCION_ACK_H

#include "AccionSwitch.h"

class AccionAck: public AccionSwitch {
    public:
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
};

#endif