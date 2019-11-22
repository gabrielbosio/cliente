#ifndef ACCION_ACK_H
#define ACCION_ACK_H

#include "AccionSwitch.h"
#include "Mensajero.h"

class AccionAck: public AccionSwitch {
    public:
        AccionAck(Mensajero* mensajero);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        Mensajero* mensajero;
};

#endif