#include <Arduino.h>

#include "Display.h"

Display::Display(int a, int b, int c, int d, int e, int f, int g, int mux0, int mux1) :
    segmentoA(a), segmentoB(b), segmentoC(c), segmentoD(d), segmentoE(e), segmentoF(f),
    segmentoG(g), mux0(mux0), mux1(mux1) {

    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);

    pinMode(mux0, OUTPUT);
    pinMode(mux1, OUTPUT);
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
        default:
            Serial.println("Estado Display Erroneo");
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
    digitalWrite(segmentoA, numero[0]);
    digitalWrite(segmentoB, numero[1]);
    digitalWrite(segmentoC, numero[2]);
    digitalWrite(segmentoD, numero[3]);
    digitalWrite(segmentoE, numero[4]);
    digitalWrite(segmentoF, numero[5]);
    digitalWrite(segmentoG, numero[6]);
    
    if (mux == 0) {
        digitalWrite(mux0, 1);
        digitalWrite(mux1, 0);
    } else if (mux == 1) {
        digitalWrite(mux0, 0);
        digitalWrite(mux1, 1);
    }
}