#ifndef ACCION_ASIGNAR_ID_H
#define ACCION_ASIGNAR_ID_H

#include "AccionSwitch.h"
#include "TecladoCliente.h"

class AccionAsignarId: public AccionSwitch {
    public:
        AccionAsignarId(TecladoCliente* tecladoCliente, int id);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        TecladoCliente* tecladoCliente;
        int id;
};

#endif