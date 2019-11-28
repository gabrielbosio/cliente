#ifndef TESTER_H
#define TESTER_H

#include "Display.h"
#include "MatrizLeds.h"

class Tester
{
public:
    Tester(Display *display, MatrizLeds *matrizLeds);
    void ejecutar();

private:
    Display *display;
    MatrizLeds *matrizLeds;
};

#endif