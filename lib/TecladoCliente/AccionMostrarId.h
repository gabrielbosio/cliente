#ifndef ACCION_MOSTRAR_ID_H
#define ACCION_MOSTRAR_ID_H

#include "AccionSwitch.h"

class AccionMostrarId: public AccionSwitch {
  public:
    AccionMostrarId(int id, DisplayHelper *display);
    void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch);
  private:
    int id;
    DisplayHelper *display;
};

#endif