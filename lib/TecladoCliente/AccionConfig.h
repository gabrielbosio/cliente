#ifndef ACCION_CONFIG_H
#define ACCION_CONFIG_H

#include "AccionSwitch.h"
#include "TecladoCliente.h"

class AccionConfig: public AccionSwitch {
    public:
        AccionConfig(TecladoCliente *tecladoCliente);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        TecladoCliente *tecladoCliente;
};

#endif