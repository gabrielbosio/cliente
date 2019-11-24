#ifndef ACCION_ACK_H
#define ACCION_ACK_H

#include "AccionSwitch.h"
#include "MatrizLeds.h"
#include "Mensajero.h"

class AccionAck: public AccionSwitch {
    public:
        AccionAck(Mensajero* mensajero, MatrizLeds* matrizLeds);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        Mensajero* mensajero;
        MatrizLeds* matrizLeds;
};

#endif