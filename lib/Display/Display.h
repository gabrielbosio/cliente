#include "Arduino.h"
#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
private:

    bool seLlamoAlDisplay;
    TaskHandle_t tareaDisplay;

public:
    // Display receive from a to g segments pin numero and mux 0 - 1 for control mostrars
    Display(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1);
    void mostrarNumero(int numero);
    void mostrarStandBy();
    void mostrarCargando();
    void mostrar(int *numero, int mux);
    void realizarTareaMostrarNumero(int numero);
};

#endif
