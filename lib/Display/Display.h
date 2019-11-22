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
    private:
        // Para no borrar la tarea la primera vez, porque no hay tarea en ese caso
        bool seLlamoAlDisplay = false;
        int estado = STAND_BY;
        int numero = 0;

        int segmentoA = 18;
        int segmentoB = 19;
        int segmentoC = 21;
        int segmentoD = 16;
        int segmentoE = 17;
        int segmentoF = 22;
        int segmentoG = 23;
        int mux0 = 2;
        int mux1 = 4;
        
        // Numeros y animaciones
        int cero[7] = {1, 1, 1, 1, 1, 1, 0};
        int uno[7] = {0, 1, 1, 0, 0, 0, 0};
        int dos[7] = {1, 1, 0, 1, 1, 0, 1};
        int tres[7] = {1, 1, 1, 1, 0, 0, 1};
        int cuatro[7] = {0, 1, 1, 0, 0, 1, 1};
        int cinco[7] = {1, 0, 1, 1, 0, 1, 1};
        int seis[7] = {1, 0, 1, 1, 1, 1, 1};
        int siete[7] = {1, 1, 1, 0, 0, 0, 0};
        int ocho[7] = {1, 1, 1, 1, 1, 1, 1};
        int nueve[7] = {1, 1, 1, 0, 0, 1, 1};
        int* numeros[10] = {cero, uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve};
        int standBy[7] = {0, 0, 0, 0, 0, 0, 1};
        int cargandoFrame1[7] = {1, 1, 0, 0, 0, 0, 0};
        int cargandoFrame2[7] = {0, 1, 1, 0, 0, 0, 0};
        int cargandoFrame3[7] = {0, 0, 1, 1, 0, 0, 0};
        int cargandoFrame4[7] = {0, 0, 0, 1, 1, 0, 0};
        int cargandoFrame5[7] = {0, 0, 0, 0, 1, 1, 0};
        int cargandoFrame6[7] = {1, 0, 0, 0, 0, 1, 0};
        int* animacionCargando[6] = {cargandoFrame1, cargandoFrame2, cargandoFrame3, cargandoFrame4, cargandoFrame5, cargandoFrame6};
        int posicionAnimacionCargando = 0;
        int longitudAnimacionCargando = 0;

        void mostrarStandBy();
        void mostrarCargando();
        void realizarTareaMostrarNumero(int numero);
        void mostrar(int* numero, int mux);
};

#endif
