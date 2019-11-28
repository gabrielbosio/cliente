#ifndef TESTER_H
#define TESTER_H

#include "ControladorAlertas.h"
#include "Display.h"
#include "MatrizLeds.h"

class Tester
{
public:
    Tester(Display *display, MatrizLeds *matrizLeds, ControladorAlertas *controladorAlertas);
    void ejecutar();

private:
    Display *display;
    MatrizLeds *matrizLeds;
    ControladorAlertas *controladorAlertas;
};

#endif