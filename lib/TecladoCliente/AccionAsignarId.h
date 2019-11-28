#ifndef ACCION_ASIGNAR_ID_H
#define ACCION_ASIGNAR_ID_H

#include "AccionSwitch.h"
#include "TecladoCliente.h"
#include "Mensajero.h"
#include "ManejadorFlash.h"

class AccionAsignarId : public AccionSwitch
{
public:
    AccionAsignarId(TecladoCliente *tecladoCliente, ManejadorFlash *manejadorFlash, Mensajero *mensajero, byte id);
    void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);

private:
    TecladoCliente *tecladoCliente;
    ManejadorFlash *manejadorFlash;
    Mensajero *mensajero;
    byte id;
};

#endif