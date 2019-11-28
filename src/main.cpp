#include "ControladorAlertas.h"
#include "Display.h"
#include "MatrizLeds.h"
#include "Mensajero.h"
#include "TecladoCliente.h"
#include "ManejadorFlash.h"
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

ControladorAlertas* controladorAlertas;
Display* display;
Mensajero* mensajero;
TecladoCliente* tecladoCliente;
MatrizLeds* matrizLeds;
Tester* tester;
TaskHandle_t tareaDisplay;
ManejadorFlash* manejadorFlash;

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
    xTaskCreatePinnedToCore(loopSegundoCore, "loopSegundoCore", 8192, NULL, 1, &tareaDisplay, 1);
    
    controladorAlertas = new ControladorAlertas();
    matrizLeds = new MatrizLeds(CS_PIN_LEDMATRIX);
    manejadorFlash = new ManejadorFlash();
    byte id = manejadorFlash->leerID();
    Serial.print("ID Cliente: ");
    Serial.println(id);
    delay(1000);
    mensajero = new Mensajero(id, controladorAlertas, display, matrizLeds);
    Serial.println("mensajero creado");
    tecladoCliente = new TecladoCliente(PIN_SWITCH_1, PIN_SWITCH_2, PIN_SWITCH_3, PIN_SWITCH_4,
                                        controladorAlertas, display, matrizLeds, mensajero, manejadorFlash);
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