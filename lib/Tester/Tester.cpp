#include "Tester.h"

Tester::Tester(Display* display, MatrizLeds* matrizLeds) :
    display(display), matrizLeds(matrizLeds) {}

void Tester::ejecutar() {
    Serial.println("Comienza test");
    display->asignarNumero(88);
    display->asignarEstado(MOSTRANDO_NUMERO);
    delay(1000);
    Serial.println("Termina test");
    display->asignarEstado(STAND_BY);
}