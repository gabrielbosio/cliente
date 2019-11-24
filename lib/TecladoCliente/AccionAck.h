#ifndef ACCION_ACK_H
#define ACCION_ACK_H

#include "AccionSwitch.h"
#include "ControladorAlertas.h"
#include "MatrizLeds.h"
#include "Mensajero.h"

class AccionAck: public AccionSwitch {
    public:
        AccionAck(ControladorAlertas* controladorAlertas, Mensajero* mensajero,
                  MatrizLeds* matrizLeds);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        ControladorAlertas* controladorAlertas;
        Mensajero* mensajero;
        MatrizLeds* matrizLeds;
};

#endif