#include "Arduino.h"
#ifndef DISPLAY_H
#define DISPLAY_H

#define STAND_BY 0
#define CARGANDO 1
#define MOSTRANDO_NUMERO 2

class Display {
    public:
        Display(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1);
        void actualizar();
        void asignarNumero(int numero);
        void asignarEstado(int estado);
        void mostrarStandBy();
        void mostrarCargando();
        void mostrar(int* numero, int mux);
        void realizarTareaMostrarNumero(int numero);

    private:
        // Para no borrar la tarea la primera vez, porque no hay tarea en ese caso
        bool seLlamoAlDisplay = false;
};

#endif
