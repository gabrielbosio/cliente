#ifndef TECLADO_CLIENTE_H
#define TECLADO_CLIENTE_H

#include "ControladorAlertas.h"
#include "Display.h"
#include "MatrizLeds.h"
#include "Mensajero.h"
#include "AccionSwitch.h"
#include "ManejadorFlash.h"

#define NADA 1
#define NORMAL 2
#define CONFIG 3
#define ID 4

class TecladoCliente
{
public:
    TecladoCliente(int pinSwitch1, int pinSwitch2, int pinSwitch3, int pinSwitch4,
                   ControladorAlertas *controladorAlertas, Display *display,
                   MatrizLeds *matrizLeds, Mensajero *mensajero, ManejadorFlash *manejadorFlash);
    void reiniciar();
    void configurar(int configwitch1, int configwitch2, int configwitch3, int configwitch4);
    bool actualizar();

private:
    ControladorAlertas *controladorAlertas;
    Display *display;
    MatrizLeds *matrizLeds;
    Mensajero *mensajero;
    ManejadorFlash *manejadorFlash;
    bool comienzaTest = false;
    byte id = 0;

    int pinSwitch1;
    int pinSwitch2;
    int pinSwitch3;
    int pinSwitch4;

    int estadoAnteriorPinSwitch1 = LOW;
    int estadoAnteriorPinSwitch2 = LOW;
    int estadoAnteriorPinSwitch3 = LOW;
    int estadoAnteriorPinSwitch4 = LOW;

    int estadoActualPinSwitch1 = LOW;
    int estadoActualPinSwitch2 = LOW;
    int estadoActualPinSwitch3 = LOW;
    int estadoActualPinSwitch4 = LOW;

    void configurarSwitch1(int config);
    void configurarSwitch2(int config);
    void configurarSwitch3(int config);
    void configurarSwitch4(int config);

    AccionSwitch *accionSwitch1 = NULL;
    AccionSwitch *accionSwitch2 = NULL;
    AccionSwitch *accionSwitch3 = NULL;
    AccionSwitch *accionSwitch4 = NULL;
};

#endif