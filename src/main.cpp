#include "TecladoCliente.h"
#include "DisplayHelper.h"
#include <Arduino.h>

// Pin definition
// Buttons
#define PIN_SWITCH1 5
#define PIN_SWITCH2 18
#define PIN_SWITCH3 22
#define PIN_SWITCH4 23
// 7 segments
#define SEGMENT_A 13
#define SEGMENT_B 12
#define SEGMENT_C 14
#define SEGMENT_D 27
#define SEGMENT_E 26
#define SEGMENT_F 25
#define SEGMENT_G 33
#define MUX_SEGMENT_ZERO 32
#define MUX_SEGMENT_ONE 19


DisplayHelper *displayHelper;
TecladoCliente *tecladoCliente;
TaskHandle_t Task1;

int count = 1;

// Used to move display behaviour has paralel task into the secondary core
void Task1code(void *pvParameters)
{
  for (;;)
  {
    displayHelper->display_number(count);
  }
}

void setup()
{
  Serial.begin(115200);
  displayHelper = new DisplayHelper(SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_D, SEGMENT_E,
                                    SEGMENT_F, SEGMENT_G, MUX_SEGMENT_ZERO, MUX_SEGMENT_ONE);
  tecladoCliente = new TecladoCliente(PIN_SWITCH1, PIN_SWITCH2, PIN_SWITCH3, PIN_SWITCH4);
  
  // TODO - Check how we can move this to the DisplayHelper library
  xTaskCreatePinnedToCore(
      Task1code, /* Task function. */
      "Task1",   /* name of task. */
      10000,     /* Stack size of task */
      NULL,      /* parameter of the task */
      1,         /* priority of the task */
      &Task1,    /* Task handle to keep track of created task */
      1);        /* pin task to core 0 */
  }

  void loop()
  {
    tecladoCliente->actualizar();
    count  = (count + 1)%100;
    delay(100);
  }