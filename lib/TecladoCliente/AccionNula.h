#ifndef ACCION_NULA_h
#define ACCION_NULA_h

#include "AccionSwitch.h"
#include "TecladoCliente.h"

class AccionNula : public AccionSwitch
{
public:
    AccionNula();
    void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
};

#endif