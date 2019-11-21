#include <Arduino.h>

#include "Display.h"

int SEGMENTO_A = 18;
int SEGMENTO_B = 19;
int SEGMENTO_C = 21;
int SEGMENTO_D = 16;
int SEGMENTO_E = 17;
int SEGMENTO_F = 22;
int SEGMENTO_G = 23;

int MUX_0 = 2;
int MUX_1 = 4;

int estado = STAND_BY;
int numero = 0;

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

Display::Display(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1) {
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);

    pinMode(mux_0, OUTPUT);
    pinMode(mux_1, OUTPUT);

    SEGMENTO_A = a;
    SEGMENTO_B = b;
    SEGMENTO_C = c;
    SEGMENTO_D = d;
    SEGMENTO_E = e;
    SEGMENTO_F = f;
    SEGMENTO_G = g;

    MUX_0 = mux_0;
    MUX_1 = mux_1;
}

void Display::actualizar() {
    switch (estado) {
        case STAND_BY:
            mostrarStandBy();
            break;
        
        case CARGANDO:
            mostrarCargando();
            break;

        case MOSTRANDO_NUMERO:
            realizarTareaMostrarNumero(numero);
            break;
    }
}

void Display::asignarNumero(int n) {
    numero = n;
}

void Display::asignarEstado(int e) {
    estado = e;
}

// Loop de tarea ejecutada en paralelo
void Display::realizarTareaMostrarNumero(int numero) {
    int primerDigito = floor(numero / 10);
    int segundoDigito = numero % 10;
    mostrar(numeros[primerDigito], 0);
    delay(5);
    mostrar(numeros[segundoDigito], 1);
    delay(5);
}

// Muestra dos lineas en el medio del display, indicando stand by
void Display::mostrarStandBy() {
    mostrar(standBy, 0);
    delay(5);
    mostrar(standBy, 1);
    delay(5);
}

// Muestra una animacion de carga
void Display::mostrarCargando() {

    if (longitudAnimacionCargando%10 == 0) {
        posicionAnimacionCargando++;
        if (posicionAnimacionCargando == 6) {
            posicionAnimacionCargando = 0;
        }
    }

    longitudAnimacionCargando++;
    mostrar(animacionCargando[posicionAnimacionCargando], 0);
    delay(5);
    mostrar(animacionCargando[posicionAnimacionCargando], 1);
    delay(5);
}

// Muestra, multiplexando, un digito en el display
void Display::mostrar(int* numero, int mux) {
    digitalWrite(SEGMENTO_A, numero[0]);
    digitalWrite(SEGMENTO_B, numero[1]);
    digitalWrite(SEGMENTO_C, numero[2]);
    digitalWrite(SEGMENTO_D, numero[3]);
    digitalWrite(SEGMENTO_E, numero[4]);
    digitalWrite(SEGMENTO_F, numero[5]);
    digitalWrite(SEGMENTO_G, numero[6]);
    
    if (mux == 0) {
        digitalWrite(MUX_0, 1);
        digitalWrite(MUX_1, 0);
    } else if (mux == 1) {
        digitalWrite(MUX_0, 0);
        digitalWrite(MUX_1, 1);
    }
}