#include "Tester.h"

Tester::Tester(Display* display, MatrizLeds* matrizLeds) :
    display(display), matrizLeds(matrizLeds) {}

void Tester::ejecutar() {
    Serial.println("Comienza test");
    display->asignarNumero(88);
    display->asignarEstado(MOSTRANDO_NUMERO);
    delay(2000);
    display->asignarEstado(STAND_BY);
    matrizLeds->encender();
    delay(2000);
    Serial.println("Termina test");
    matrizLeds->apagar();
}