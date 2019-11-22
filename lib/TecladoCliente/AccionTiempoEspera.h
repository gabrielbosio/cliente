#ifndef ACCION_TIEMPO_ESPERA_H
#define ACCION_TIEMPO_ESPERA_H

#include "AccionSwitch.h"
#include "Mensajero.h"

class AccionTiempoEspera: public AccionSwitch {
    public:
        AccionTiempoEspera(Mensajero* mensajero);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        Mensajero* mensajero;
};

#endif