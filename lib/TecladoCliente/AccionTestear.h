#ifndef ACCION_TESTEAR_h
#define ACCION_TESTEAR_h

#include "AccionSwitch.h"
#include "TecladoCliente.h"

class AccionTestear: public AccionSwitch {
    public:
        AccionTestear(TecladoCliente* tecladoCliente, bool* comienzaTest);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        TecladoCliente* tecladoCliente;
        bool* comienzaTest;
};

#endif