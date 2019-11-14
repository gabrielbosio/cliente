#ifndef TECLADO_CLIENTE_H
#define TECLADO_CLIENTE_H

#include "AccionSwitch.h"

#define NADA 1
#define NORMAL 2
#define CONFIG 3
#define ID 4

class TecladoCliente {
  public:
    TecladoCliente(int pinSwitch1, int pinSwitch2, int pinSwitch3, int pinSwitch4);
    void reiniciar();
    void configurar(int configwitch1, int configwitch2, int configwitch3, int configwitch4);
    void actualizar();
    void asignarId(int id);
    int get_id();
  private:
    int id;

    int pinSwitch1;
    int pinSwitch2;
    int pinSwitch3;
    int pinSwitch4;

    int estadoAnteriorPinSwitch1;
    int estadoAnteriorPinSwitch2;
    int estadoAnteriorPinSwitch3;
    int estadoAnteriorPinSwitch4;

    int estadoActualPinSwitch1;
    int estadoActualPinSwitch2;
    int estadoActualPinSwitch3;
    int estadoActualPinSwitch4;

    void configurarSwitch1(int config);
    void configurarSwitch2(int config);
    void configurarSwitch3(int config);
    void configurarSwitch4(int config);

    AccionSwitch* accionSwitch1;
    AccionSwitch* accionSwitch2;
    AccionSwitch* accionSwitch3;
    AccionSwitch* accionSwitch4;
};

#endif