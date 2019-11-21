#include "Tester.h"

Tester::Tester(Display* display, MatrizLeds* matrizLeds) :
    display(display), matrizLeds(matrizLeds) {}

void Tester::ejecutar() {
    Serial.println("Comienza test");
    display->mostrarNumero(88);
    delay(1000);
    Serial.println("Termina test");
}