#ifndef ACCION_CONFIG_ID_H
#define ACCION_CONFIG_ID_H

#include "AccionSwitch.h"
#include "TecladoCliente.h"

class AccionConfigId : public AccionSwitch
{
public:
    AccionConfigId(TecladoCliente *tecladoCliente);
    void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);

private:
    TecladoCliente *tecladoCliente;
};

#endif