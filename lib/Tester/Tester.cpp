#include "Tester.h"

Tester::Tester(Display *display, MatrizLeds *matrizLeds,
               ControladorAlertas *controladorAlertas) : display(display),
               matrizLeds(matrizLeds), controladorAlertas(controladorAlertas) {}

void Tester::ejecutar()
{
    Serial.println("Comienza test");
    this->display->asignarNumero(88);
    this->display->asignarEstado(MOSTRANDO_NUMERO);
    delay(2000);
    this->display->asignarEstado(STAND_BY);
    this->matrizLeds->encender();
    delay(2000);
    this->controladorAlertas->encender(2000);
    Serial.println("Termina test");
    this->matrizLeds->apagar();
}