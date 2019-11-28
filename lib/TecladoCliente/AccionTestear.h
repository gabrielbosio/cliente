#ifndef ACCION_TESTEAR_h
#define ACCION_TESTEAR_h

#include "AccionSwitch.h"
#include "ManejadorFlash.h"
#include "Mensajero.h"
#include "TecladoCliente.h"

class AccionTestear: public AccionSwitch {
    public:
        AccionTestear(TecladoCliente* tecladoCliente, ManejadorFlash* manejadorFlash, Mensajero* mensajero, bool* comienzaTest);
        void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
    private:
        TecladoCliente* tecladoCliente;
        ManejadorFlash* manejadorFlash;
        Mensajero* mensajero;
        bool* comienzaTest;
};

#endif