#include "TecladoCliente.h"
#include "Display.h"
#include "MatrizLeds.h"
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


Display *display;
TecladoCliente *tecladoCliente;
MatrizLeds *matrizLeds;
// TaskHandle_t DisplayTask;

// Used to move display behaviour has paralel task into the secondary core
// void display_id_number(void *pvParameters)
// {
//   for (;;)
//   {
//     // display->display_loading();
//     // display->display_stand_by();
//     display->display_number(tecladoCliente->get_id());
//   }
// }

// void create_task() {
//   vTaskDelete(DisplayTask);
//   // TODO - Check how we can move this to the Display library
//   xTaskCreatePinnedToCore(
//       display_id_number,    /* Task function. */
//       "display_id_number",      /* name of task. */
//       10000,        /* Stack size of task */
//       NULL,         /* parameter of the task */
//       1,            /* priority of the task */
//       &DisplayTask, /* Task handle to keep track of created task */
//       1);           /* pin task to core 0 */
// }

void setup()
{
  Serial.begin(115200);
  display = new Display(SEGMENTO_A, SEGMENTO_B, SEGMENTO_C, SEGMENTO_D, SEGMENTO_E,
                                    SEGMENTO_F, SEGMENTO_G, MUX_SEGMENTO_0, MUX_SEGMENTO_1);
  tecladoCliente = new TecladoCliente(PIN_SWITCH_1, PIN_SWITCH_2, PIN_SWITCH_3, PIN_SWITCH_4,
                                      display);
  matrizLeds = new MatrizLeds(CS_PIN_LEDMATRIX);
  // create_task();
}

void loop()
{
  tecladoCliente->actualizar();
  delay(100);
}