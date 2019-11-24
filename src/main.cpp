#include "Display.h"
#include "MatrizLeds.h"
#include "Mensajero.h"
#include "TecladoCliente.h"
#include "Tester.h"
#include <Arduino.h>

// Definicion de pines
// Botones
#define PIN_SWITCH_1 35
#define PIN_SWITCH_2 34
#define PIN_SWITCH_3 39
#define PIN_SWITCH_4 36
// Display 7 segmentos
#define SEGMENTO_A 13
#define SEGMENTO_B 12
#define SEGMENTO_C 14
#define SEGMENTO_D 27
#define SEGMENTO_E 26
#define SEGMENTO_F 25
#define SEGMENTO_G 33
#define MUX_SEGMENTO_0 4
#define MUX_SEGMENTO_1 32
// Matriz de leds
#define CS_PIN_LEDMATRIX 5

Display* display;
Mensajero* mensajero;
TecladoCliente* tecladoCliente;
MatrizLeds* matrizLeds;
Tester* tester;
TaskHandle_t tareaDisplay;

// Tarea a ejecutar en paralelo
void loopSegundoCore(void* p) {
    while (true) {
        display->actualizar();
    }
}

void setup() {
    Serial.begin(115200);
    
    display = new Display(SEGMENTO_A, SEGMENTO_B, SEGMENTO_C, SEGMENTO_D, SEGMENTO_E, SEGMENTO_F,
                          SEGMENTO_G, MUX_SEGMENTO_0, MUX_SEGMENTO_1);
    xTaskCreatePinnedToCore(loopSegundoCore, "loopSegundoCore", 4096, NULL, 1, &tareaDisplay, 1);
    
    matrizLeds = new MatrizLeds(CS_PIN_LEDMATRIX);
    mensajero = new Mensajero(0, display, matrizLeds);
    tecladoCliente = new TecladoCliente(PIN_SWITCH_1, PIN_SWITCH_2, PIN_SWITCH_3, PIN_SWITCH_4,
                                        display, matrizLeds, mensajero);
    tester = new Tester(display, matrizLeds);
}

void loop() {
    bool comienzaTest = tecladoCliente->actualizar();

    if (comienzaTest) {
        tester->ejecutar();
        tecladoCliente->reiniciar();
    }

    delay(100);
}