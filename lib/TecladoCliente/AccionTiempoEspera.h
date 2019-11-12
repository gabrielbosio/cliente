#ifndef ACCION_TIEMPO_ESPERA_H
#define ACCION_TIEMPO_ESPERA_H

#include "AccionSwitch.h"

class AccionTiempoEspera: public AccionSwitch {
  public:
    void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
};

#endif