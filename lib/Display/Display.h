#include "Arduino.h"
#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
    public:
        Display(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1);
        void mostrarNumero(int numero);
        void mostrarStandBy();
        void mostrarCargando();
        void mostrar(int *numero, int mux);
        void realizarTareaMostrarNumero(int numero);

    private:
        TaskHandle_t tareaDisplay;

        // Para no borrar la tarea la primera vez, porque no hay tarea en ese caso
        bool seLlamoAlDisplay = false;
};

#endif
