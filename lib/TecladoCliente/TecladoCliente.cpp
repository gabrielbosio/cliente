#include <Arduino.h>
#include "TecladoCliente.h"
#include "AccionAck.h"
#include "AccionAsignarId.h"
#include "AccionConfig.h"
#include "AccionConfigId.h"
#include "AccionLlamarMozo.h"
#include "AccionMostrarId.h"
#include "AccionNula.h"
#include "AccionTiempoEspera.h"
#include "AccionTestear.h"

TecladoCliente::TecladoCliente(int pinSwitch1, int pinSwitch2, int pinSwitch3, int pinSwitch4,
                               Display *display) :
    display(display), id(0),
    pinSwitch1(pinSwitch1), pinSwitch2(pinSwitch2), pinSwitch3(pinSwitch3), pinSwitch4(pinSwitch4),
    accionSwitch1(NULL), accionSwitch2(NULL), accionSwitch3(NULL), accionSwitch4(NULL) {

    pinMode(pinSwitch1, INPUT);
    pinMode(pinSwitch2, INPUT);
    pinMode(pinSwitch3, INPUT);
    pinMode(pinSwitch4, INPUT);

    estadoAnteriorPinSwitch1 = LOW;
    estadoAnteriorPinSwitch2 = LOW;
    estadoAnteriorPinSwitch3 = LOW;
    estadoAnteriorPinSwitch4 = LOW;

    estadoActualPinSwitch1 = LOW;
    estadoActualPinSwitch2 = LOW;
    estadoActualPinSwitch3 = LOW;
    estadoActualPinSwitch4 = LOW;

    reiniciar();
}

void TecladoCliente::reiniciar() {
    configurar(NORMAL, NORMAL, NORMAL, NORMAL);
}

void TecladoCliente::configurar(int configSwitch1, int configSwitch2, int configSwitch3,
                                int configSwitch4) {

    configurarSwitch1(configSwitch1);
    configurarSwitch2(configSwitch2);
    configurarSwitch3(configSwitch3);
    configurarSwitch4(configSwitch4);
}

void TecladoCliente::actualizar() {
    estadoActualPinSwitch1 = digitalRead(pinSwitch1);
    estadoActualPinSwitch2 = digitalRead(pinSwitch2);
    estadoActualPinSwitch3 = digitalRead(pinSwitch3);
    estadoActualPinSwitch4 = digitalRead(pinSwitch4);

    accionSwitch1->ejecutar(estadoActualPinSwitch1, estadoAnteriorPinSwitch1);
    accionSwitch2->ejecutar(estadoActualPinSwitch2, estadoAnteriorPinSwitch2);
    accionSwitch3->ejecutar(estadoActualPinSwitch3, estadoAnteriorPinSwitch3);
    accionSwitch4->ejecutar(estadoActualPinSwitch4, estadoAnteriorPinSwitch4);
    
    estadoAnteriorPinSwitch1 = estadoActualPinSwitch1;
    estadoAnteriorPinSwitch2 = estadoActualPinSwitch2;
    estadoAnteriorPinSwitch3 = estadoActualPinSwitch3;
    estadoAnteriorPinSwitch4 = estadoActualPinSwitch4;
}

void TecladoCliente::asignarId(int id) {
    this->id = id;
}

void TecladoCliente::configurarSwitch1(int configSwitch) {
    delete accionSwitch1;

    switch (configSwitch) {
        case NORMAL:
            accionSwitch1 = new AccionLlamarMozo();
            break;
        case CONFIG:
            accionSwitch1 = new AccionMostrarId(id, display);
            break;
        case ID:
            accionSwitch1 = new AccionAsignarId(this, 1);
            break;
        case NADA:
            accionSwitch1 = new AccionNula();
            break;
    }
}

void TecladoCliente::configurarSwitch2(int configSwitch) {
    delete accionSwitch2;

    switch (configSwitch) {
        case NORMAL:
            accionSwitch2 = new AccionAck();
            break;
        case CONFIG:
            accionSwitch2 = new AccionConfigId(this);
            break;
        case ID:
            accionSwitch2 = new AccionAsignarId(this, 2);
            break;
        case NADA:
            accionSwitch2 = new AccionNula();
            break;
    }
}

void TecladoCliente::configurarSwitch3(int configSwitch) {
    delete accionSwitch3;

    switch (configSwitch) {
        case NORMAL:
            accionSwitch3 = new AccionTiempoEspera();
            break;
        case CONFIG:
            accionSwitch3 = new AccionTestear(this);
            break;
        case ID:
            accionSwitch3 = new AccionAsignarId(this, 3);
            break;
        case NADA:
            accionSwitch3 = new AccionNula();
            break;
    }
}

void TecladoCliente::configurarSwitch4(int configSwitch) {
    delete accionSwitch4;

    switch (configSwitch) {
        case NORMAL:
            accionSwitch4 = new AccionConfig(this);
            break;
        case ID:
            accionSwitch4 = new AccionAsignarId(this, 4);
            break;
        case NADA:
            accionSwitch4 = new AccionNula();
            break;
    }
}

int TecladoCliente::get_id()
{
    return id;
}