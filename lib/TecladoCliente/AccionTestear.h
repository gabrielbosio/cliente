#ifndef ACCION_TESTEAR_h
#define ACCION_TESTEAR_h

#include "AccionSwitch.h"
#include "TecladoCliente.h"

class AccionTestear: public AccionSwitch {
    public:
        AccionTestear(TecladoCliente *tecladoCliente);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        TecladoCliente *tecladoCliente;
};

#endif